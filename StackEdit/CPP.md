# C++

[C++](https://isocpp.org/) es un lenguaje de propósito general creado por Bjarne Stroustrup en los años 80. Es un lenguaje multiparadigma de tipado estático, que compila a código máquina, por lo que sus ejecutables no son portables pero su código si puede serlo. Estos son algunos enlaces de interés:

+ [C++ Core Guidelines](http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines): Guías básicas sobre cómo programar bien en C++.
+ [CppReference](https://www.cppreference.com/): Referencia general del lenguaje y la biblioteca estándar.
+ [Microsoft Learn](https://learn.microsoft.com/es-es/cpp/): Documentación sobre su implementación del lenguaje.
+ [Visual Studio](https://visualstudio.microsoft.com/): Entorno de desarrollo para programar.
+ [Wikipedia Inglesa](https://en.wikipedia.org/wiki/C++): Artículo general sobre el lenguaje.

Para este documento vamos a utilizar la versión 20 del estándar, cuya implementación ya está suficientemente extendida entre los principales compiladores del mercado.

## Hola mundo

El código que se compila va en ficheros `.cpp`, por ejemplo:

```cpp
// Fichero: hola.cpp
#include<iostream>

void main () {
    std::cout << "Hola mundo\n";
}
```

Para poner comentarios de una sola línea usamos `//`, si se quiere usar varias líneas se hace con `/*` `*/`. La directiva `#include` indica al preprocesador del compilador que incluya el contenido de otro fichero en esa posición. En el caso del ejemplo incluye la cabecera [`iostream`](https://en.cppreference.com/w/cpp/header/iostream), que contiene definiciones para trabajar con flujos de entrada y salida. Las cabeceras son ficheros, que normalmente tienen la extensión `.hpp` o `.h`, que contienen definiciones cuyo código está en otro fichero `.cpp` o en una biblioteca ya compilada (`.dll`, `.lib`, `.so`). Después tenemos la función `main`, que es la entrada al programa y en ella mandamos a la terminal una cadena de texto usando el objeto `std::cout`. Existen otras variantes de la función `main`:

```cpp
// Fichero: hola.cpp
#include<iostream>

int main (int argc, char ** argv) {
	std::cout << "Argumentos: " << argc << "\n";
	for (int i = 0; i < argc; i++) {
		std::cout << i << ": " << argv[i] << "\n";
	}
    return 0;
}
```

En este caso la función `main` devuelve un valor entero, donde `0` indica que no ha habido ningún error, y recibe una serie de argumentos, donde `argc` es el número de argumentos recibido y `argv` los argumentos como cadenas de texto. Las cadenas de texto estándar de C, son segmentos de memoria que terminan con el valor `0` (no confundirlo con el carácter cero). En el ejemplo mostramos el número de argumentos y con la sentencia `for` vamos mostrando cada argumento por pantalla. Otra variantes de `main` es `int main ()`, que devuelve un valor entero, pero no recibe argumentos.

> Existen diferentes compiladores, como el de [MSVC](https://learn.microsoft.com/cpp/build/reference/c-cpp-building-reference) o el [GCC](https://gcc.gnu.org/), que tienen una cantidad considerable de opciones que no vamos a documentar aquí. Lo más fácil es utilizar un IDE, que se encargue de gestionar la compilación.

## Literales

### Números enteros

La sintaxis para definir números enteros es la siguiente:

$$\textcolor{red}{[} \mathit{prefijo} \textcolor{red}{]} \mathit{d\acute{\imath}gitos} \textcolor{red}{[} \mathit{sufijo} \textcolor{red}{]}$$

Los prefijos validos son:

| Prefijos | Tipo | Dígitos |
|:--------:|:----:|:-------:|
| - | Decimal | `0`-`9` |
| `0b`, `0B` | Binario | `0`-`1` |
| `0x`, `0X` | Hexadecimal | `0`-`9`, `A`-`F`, `a`-`f` |
| `0` | Octal | `0`-`7` |

Los sufijos validos son:

| Prefijos | Tipo | Descripción |
|:--------:|:----:|:------------|
| - | `int` | Entero con signo. |
| `u`, `U` | `usigned` | Entero sin signo. |
| `l`, `L` | `long` | Entero largo con signo. |
| `ul`, `lu`, `uL`, `Lu`,<br/>`Ul`, `lU`, `UL`, `LU` | `usigned long` | Entero largo sin signo. |
| `ll`, `LL` | `long long` | Entero muy largo con signo. |
| `ull`, `llu`, `uLL`, `LLu`,<br/>`Ull`, `llU`, `ULL`, `LLU` | `usigned long long` | Entero muy largo sin signo. |

Estos son los tipos que representan números enteros, con sus tamaño en bits (donde **W** es Windows, **U** es Unix/Linux y **x** es ambos):

| Tipo | Variantes | W16 | x32 | W64 | U64 |
|:----:|:---------:|:---:|:---:|:---:|:---:|
| `signed char` | - | 8 | 8 | 8 | 8 |
| `unsigned char` | - | 8 | 8 | 8 | 8 |
| `short` | `short int`, `signed short`, `signed short int` | 16 | 16 | 16 | 16 |
| `unsigned short` | `unsigned short int` | 16 | 16 | 16 | 16 |
| `int` | `signed`, `signed int` | 16 | 32 | 32 | 32 |
| `unsigned` | `unsigned int` | 16 | 32 | 32 | 32 |
| `long` | `long int`, `signed long`, `signed long int` | 32 | 32 | 32 | 64 |
| `unsigned long` | `unsigned long int` | 32 | 32 | 32 | 64 |
| `long long` | `long long int`, `signed long long`, `signed long long int` | 64 | 64 | 64 | 64 |
| `unsigned long long` | `unsigned long long int` | 64 | 64 | 64 | 64 |

Los rangos de valores para cada tamaño son:

| Tamaño | Rango |
|:------:|:-----:|
| 8-bits con signo | `-128` .\. `127` |
| 8-bits sin signo | `0` .\. `255` |
| 16-bits con signo | `-32768` .\. `32767` |
| 16-bits sin signo | `0` .\. `65535` |
| 32-bits con signo | `-2147483648` .\. `2147483647` |
| 32-bits sin signo | `0` .\. `4294967295` |
| 64-bits con signo | `-9223372036854775808` .\. `9223372036854775807` |
| 64-bits sin signo | `0` .\. `18446744073709551615` |

Se puede convertir sin pérdida cuando se asigna un entero de un tipo a uno más grande. Al revés pueden haber pérdidas de información, así como al intentar asignar un valor sin signo a uno con signo y viceversa.

En la cabecera [`cstdint`](https://en.cppreference.com/w/cpp/header/cstdint) se incorporan una serie de alias para los tipos enteros, así como algunas macros que definen los límites numéricos de cada tamaño. Con `int8_t`, `int16_t`, `int32_t` e `int64_t`, podemos definir variables enteras con signo de un tamaño fijo, sin preocuparnos de la plataforma. Con `uint8_t`, `uint16_t`, `uint32_t` y `uint64_t`, podemos hacer lo mismo pero para enteros sin signo. También con la cabecera [`limits`](https://en.cppreference.com/w/cpp/header/limits) tenemos herramientas para comprobar propiedades sobre cualquier tipo tipo numérico.

> Desde el estándar 14 se puede utilizar la comilla simple (`'`) para separar grupos de dígitos, como una especie de separador de millares arbitrario. A la hora de compilar el carácter es ignorado, por lo que es meramente estético.

### Números reales

..

### Caracteres

..

### Cadenas de texto

..

### Booleanos

Lo valores booleanos están representados por el tipo `bool`. Estos se utilizan para dar valor a condiciones que pueden ser ciertas o falsas. Su sintaxis es la siguiente:

$$\textcolor{red}{\char123} \texttt{true} \textcolor{red}{|} \texttt{false} \textcolor{red}{\char125}$$

> Por compatibilidad con el lenguaje C, el valor `true` equivale al entero `1` y `false` al `0`. Por ello hay que entender la siguiente regla: una condición será falsa si su valor es cero y cierta con cualquier otro valor.

### Puntero nulo

Un puntero es un tipo de valor que nos indica una dirección de memoria donde está el valor con el que vamos a trabajar. En el caso de no apuntar valor alguno, utilizaremos el literal `nullptr`.

> Internamente equivale al valor cero y sustituye a la histórica macro `NULL`, para ayudar al compilador con las conversiones. El tipo `std::nullptr_t` representa los punteros nulos en el estándar y tiene el mismo tamaño que el tipo `void *`.

## Variables

..

### Arrays

..

### Punteros

..

### Referencias

..

### Constantes

..

## Operadores

..

### Booleanos

..

### Aritméticos

..

### Punteros

..

### Asignación

..

### Precedencia

..

## Sentencias

..

## Funciones

..

## Lambdas

..

## Clases

..

## Estructuras

..

## Enumeraciones

..

## Uniones

..

## Plantillas

..

## Módulos

..

## Biblioteca estándar

..

### Cadenas

..

### Contenedores

..

### Iteradores

..

### Rangos

..

### Algoritmos

..

### Números

..

### Utilidades

..

### Entrada/Salida

..

### Concurrencia

..


```cpp
// Fichero: .cpp
```

