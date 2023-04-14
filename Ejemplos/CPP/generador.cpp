#include <iostream>
#include <coroutine>

template <typename T>
struct Generador {
    // Usamos el manejador base de la librería estándar:
    struct promise_type;
    using Manejador = std::coroutine_handle<promise_type>;

    // Definimos el tipo promise_type que necesita el compilador:
    struct promise_type {
        // El último valor generado en la corrutina:
        T valor;

        // La última excepción lanzada en la corrutina:
        std::exception_ptr error;

        // Método para instanciar una corrutina:
        Generador get_return_object () {
            return Generador(Manejador::from_promise(*this));
        }

        // Método para cuando se va pausar la corrutina con co_await:
        std::suspend_always initial_suspend () {
            return {};
        }

        // Método para cuando se va pausar por última vez la corrutina:
        std::suspend_always final_suspend () noexcept {
            return {};
        }

        // Método para cuando se produce una excepción en la corrutina:
        void unhandled_exception () {
            error = std::current_exception();
        }

        // Método para cuando se sale de la corrutina con co_return:
        void return_void () {}

        // Método para cuando se devuelve un valor en la corrutina con co_yield:
        template <std::convertible_to<T> From>
        std::suspend_always yield_value (From && from) {
            valor = std::forward<From>(from);
            return {};
        }
    };

    // Genera el siguiente elemento de la secuencia:
    bool siguiente () {
        // Genera el siguiente elemento de la corrutina:
        manejador_();
        // Comprueba si se ha generado alguna excepción:
        if (manejador_.promise().error) {
            std::rethrow_exception(manejador_.promise().error);
        }
        // Comprueba si se ha terminado de ejecutar la corrutina:
        return !manejador_.done();
    }

    // Devuelve el último elemento generado en la secuencia:
    T actual () {
        return std::move(manejador_.promise().valor);
    }

    // Construye un generador con un manejador recibido:
    Generador (Manejador h) : manejador_(h) {}

    // Destruye el generador eliminando los recursos del manejador:
    ~Generador () {
        manejador_.destroy();
    }

private:
    Manejador manejador_;
};

Generador<std::uint64_t> fibonacci (unsigned n) {
    if (n > 94) {
        throw std::runtime_error("Secuencia demasiado grande.");
    } if (n == 0) {
        co_return;
    } else {
        std::uint64_t a = 0, b = 1, aux;
        for (unsigned i = 0; i < n; ++i) {
            co_yield a;
            aux = a + b;
            a = b;
            b = aux;
        }
    }
}

int main () {
    try {
        auto gen = fibonacci(20);
        while (gen.siguiente()) {
            std::cout << gen.actual() << ' ';
        }
        std::cout << '\n';
    } catch (const std::exception & ex) {
        std::cerr << "Error: " << ex.what() << '\n';
    } catch (...) {
        std::cerr << "Error desconocido...\n";
    }
}
