#include <iostream>
#include <coroutine>

template <typename T>
struct Tarea {
    // Usamos el manejador base de la librería estándar:
    struct promise_type;
    using Manejador = std::coroutine_handle<promise_type>;

    // Definimos el tipo promise_type que necesita el compilador:
    struct promise_type {
        // El último valor generado en la corrutina:
        T valor;

        // Método para instanciar una corrutina:
        Tarea get_return_object () {
            return Tarea(Manejador::from_promise(*this));
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
        void unhandled_exception () {}

        // Método para cuando se sale de la corrutina con co_return:
        template <std::convertible_to<T> From>
        void return_value (From && from) {
            valor = std::forward<From>(from);
        }
    };

    // Definimos el tipo awaitable para poder usar co_await:
    struct Esperador {
        Manejador & manejador;

        // Método para indicar que se tiene que pausar la ejecución
        // al estar devolviendo false como resultado:
        bool await_ready() noexcept {
            return false;
        }

        // Método que recibe una corrutina externa y que después,
        // de realizar las operaciones que sean necesarias, volverá
        // a activar la ejecución de dicha corrutina:
        void await_suspend(std::coroutine_handle<> externo) noexcept {
            externo.resume();
        }

        // Método que se invoca cuando se va a reactivar la ejecución
        // de la corrutina que se ha puesto en espera con co_await:
        T await_resume() noexcept {
            manejador.resume();
            return manejador.promise().valor;
        }
    };

    // Sobrecarga el operador co_await para supender
    Esperador operator co_await () noexcept {
        // Como el operador co_await está siendo usado con una tarea
        // vamos a configurar el "esperador" con una referencia al
        // manejador del tipo promesa de la corrutina:
        return Esperador{manejador_};
    }

    // Devuelve el resultado generado por la tarea:
    T resultado () {
        manejador_();
        return std::move(manejador_.promise().valor);
    }

    // Construye una tarea con un manejador recibido:
    Tarea (Manejador h) : manejador_(h) {}

    // Destruye la tarea eliminando los recursos del manejador:
    ~Tarea () {
        manejador_.destroy();
    }

private:
    Manejador manejador_;
};

Tarea<std::uint64_t> factorial (unsigned x) {
    if (x > 1) {
        auto y = co_await factorial(x - 1);
        co_return x * y;
    } else {
        co_return 1;
    }
}

int main () {
    auto tarea = factorial(10);
    std::cout << tarea.resultado() << '\n';
}
