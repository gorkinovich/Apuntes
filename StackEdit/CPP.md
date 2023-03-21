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

## Literales y tipos básicos

### Números enteros

La sintaxis para definir números enteros es la siguiente:

$$\textcolor{red}{[} \mathit{prefijo} \textcolor{red}{]} \mathit{d\acute{\imath}gitos} \textcolor{red}{[} \mathit{sufijo} \textcolor{red}{]}$$

> Desde el estándar 14 se puede utilizar la comilla simple (`'`) para separar grupos de dígitos, como una especie de separador de millares arbitrario. A la hora de compilar el carácter es ignorado, por lo que es meramente estético.

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

### Números reales

La sintaxis para definir números reales es la siguiente:

$$\mathit{d\acute{\imath}gitos} \textcolor{red}{[} \texttt{.} \mathit{d\acute{\imath}gitos} \textcolor{red}{]} \textcolor{red}{[} \textcolor{red}{\char123} \texttt{e} \textcolor{red}{|} \texttt{E} \textcolor{red}{\char125} \textcolor{red}{[} \texttt{+} \textcolor{red}{|} \texttt{-} \textcolor{red}{]} \mathit{d\acute{\imath}gitos} \textcolor{red}{]} \textcolor{red}{[} \mathit{sufijo} \textcolor{red}{]}$$

> Desde el estándar 17 se puede usar el prefijo `0x` o `0X` para usar dígitos hexadecimales al definir un número real. Sin embargo, para indicar el exponente se utiliza `p` o `P`, en lugar de `e` y `E`. Por ejemplo, `0x1EFp2`.

Los sufijos validos son:

| Prefijos | Tipo | Tamaño | Descripción |
|:--------:|:----:|:------:|:------------|
| - | `double` | 64 | Real doble. |
| `f`, `f` | `float` | 32 | Real simple. |
| `l`, `L` | `long double` | 128 | Real doble largo. |

> El tipo `long double` ocupa 128 bits en arquitecturas de 64 bits, siguiendo el estándar [IEEE 754](https://en.wikipedia.org/wiki/IEEE_754), pero tradicionalmente en las de 32 bits este tipo ocupaba 80 bits, siguiendo el formato de [precisión extendida](https://en.wikipedia.org/wiki/Extended_precision).

### Caracteres

La sintaxis para definir caracteres es la siguiente:

$$\textcolor{red}{[} \mathit{prefijo} \textcolor{red}{]} \texttt{'} \textcolor{red}{\char123} \mathit{letra} \textcolor{red}{|} \mathit{secuencia\ de\ escape} \textcolor{red}{\char125} \texttt{'}$$

Las [secuencias de escape](https://en.cppreference.com/w/cpp/language/escape) disponibles son:

| Secuencia | Significado | Secuencia | Significado |
|:---------:|:------------|:---------:|:------------|
| `\'` | Comilla simple. | `\"` | Comilla doble. |
| `\?` | Interrogación. | `\\` | Barra invertida. |
| `\a` | Alarma. | `\b` | Retroceso. |
| `\f` | Alimentación. | `\n` | Nueva línea. |
| `\r` | Retroceso de línea. | `\t` | Tabulación horizontal. |
| `\v` | Tabulación vertical. | `\0` | Carácter nulo. |
| `\###` | Carácter octal. | `\x##`<br/>`\x####` | Carácter hexadecimal. |
| `\u####` | Carácter Unicode (UTF-16). | `\U########` | Carácter Unicode (UTF-32). |

Los prefijos validos son:

| Prefijos | Tipo | Descripción |
|:--------:|:----:|:------------|
| - | `char` | Carácter normal. |
| `u8` | `char8_t` | Carácter UTF-8. |
| `u` | `char16_t` | Carácter UTF-16. |
| `U` | `char32_t` | Carácter UTF-32. |
| `L` | `wchar_t` | Carácter Unicode (UTF-16 en Windows y UTF-32 en Unix/Linux). |

### Cadenas de texto

La sintaxis para definir cadenas de texto es la siguiente:

$$\textcolor{red}{[} \mathit{prefijo} \textcolor{red}{]} \texttt{"} \mathit{caracteres} \texttt{"}$$

Los prefijos validos son:

| Prefijos | Elementos | Descripción |
|:--------:|:---------:|:------------|
| - | `char` | Carácter normal. |
| `u8` | `char8_t` | Carácter UTF-8. |
| `u` | `char16_t` | Carácter UTF-16. |
| `U` | `char32_t` | Carácter UTF-32. |
| `L` | `wchar_t` | Carácter Unicode (UTF-16 en Windows y UTF-32 en Unix/Linux). |

> Las cadenas de texto como tal no existe como tipos básicos del lenguaje, es necesario usar arrays (`char []`) y punteros (`char *`) para almacenar una cadena de texto. Dicho lo cual, la biblioteca estándar tiene el tipo [`std::string`](https://en.cppreference.com/w/cpp/string/basic_string) para almacenar cadenas y trabajar con ellas de forma cómoda.

### Booleanos

Lo valores booleanos están representados por el tipo `bool`. Estos se utilizan para dar valor a condiciones que pueden ser ciertas o falsas. Su sintaxis es la siguiente:

$$\textcolor{red}{\char123} \texttt{true} \textcolor{red}{|} \texttt{false} \textcolor{red}{\char125}$$

> Por compatibilidad con el lenguaje C, el valor `true` equivale al entero `1` y `false` al `0`. Por ello hay que entender la siguiente regla: una condición será falsa si su valor es cero y cierta con cualquier otro valor.

### Puntero nulo

Un puntero es un tipo de valor que nos indica una dirección de memoria donde está el valor con el que vamos a trabajar. En el caso de no apuntar valor alguno, utilizaremos el literal `nullptr`.

> Internamente equivale al valor cero y sustituye a la histórica macro `NULL`, para ayudar al compilador con las conversiones. El tipo `std::nullptr_t` representa los punteros nulos en el estándar y tiene el mismo tamaño que el tipo `void *`.

## Variables y valores

Las variables, como todas las definiciones, requieren de un nombre identificador para poder trabajar con ellas. Un identificador se compone de una sucesión de letras (mayúsculas y minúsculas), dígitos (`0`-`9`) y/o el guion bajo (`_`), que no debe comenzar por dígito. No se podrán usar las [palabras reservadas](https://en.cppreference.com/w/cpp/keyword) del lenguaje como identificadores.

La sintaxis básica para definir variables es la siguiente:

$$\mathit{tipo}\ \mathit{nombre_1}\ \textcolor{red}{[} \texttt{=}\ \mathit{expresi\acute{o}n_1} \textcolor{red}{]} \textcolor{red}{[} \texttt{,} \textcolor{red}{\dots} \texttt{,}\ \mathit{nombre_n}\ \textcolor{red}{[} \texttt{=}\ \mathit{expresi\acute{o}n_n} \textcolor{red}{]} \textcolor{red}{]} \texttt{;}$$

Con la palabra clave `auto` se indica al compilador que infiera el tipo para la variable en base a la expresión que inicializa su valor:

$$\texttt{auto}\ \mathit{nombre_1}\ \texttt{=}\ \mathit{expresi\acute{o}n_1} \textcolor{red}{[} \texttt{,} \textcolor{red}{\dots} \texttt{,}\ \mathit{nombre_n}\ \texttt{=}\ \mathit{expresi\acute{o}n_n} \textcolor{red}{]} \texttt{;}$$

Cada *nombre* representa una dirección en la memoria, donde se almacena el valor resultante de evaluar la *expresión* que se le asigne a la variable, ya sea en la inicialización o con el operador asignación (`=`). El tipo le indica al compilador el tamaño que ocupan los valores con los que vamos a trabajar, para acceder a su estructura interna de forma correcta. Por ejemplo:

```cpp
// Fichero: variables.cpp
#include<iostream>

void main () {
	int a = 1, b = 2;
	auto c = 3.14;
	std::cout << a << ", " << b << ", " << c << "\n"; // 1, 2, 3.14
	b = 4;
	std::cout << a << ", " << b << ", " << c << "\n"; // 1, 4, 3.14
}
```

### Arrays

Los arrays son bloques de memoria que contienen un número fijo de elementos, a los que se acceden de forma indexada. La sintaxis básica para definir arrays es la siguiente:

$$\mathit{tipo}\ \mathit{nombre} \texttt{[} \textcolor{red}{[} \mathit{tam_1} \textcolor{red}{]} \texttt{]} \textcolor{red}{[} \texttt{[} \mathit{tam_2} \texttt{]} \textcolor{red}{\dots} \texttt{[} \mathit{tam_n} \texttt{]} \textcolor{red}{]}\ \textcolor{red}{[} \texttt{=}\ \texttt{\char123}\ \mathit{expresiones}\ \texttt{\char125} \textcolor{red}{]} \textcolor{red}{[} \texttt{,} \textcolor{red}{\dots}\ \textcolor{red}{]} \texttt{;}$$

Entre corchetes indicamos el *tamaño* de cada dimensión del array, pudiendo inicializar el contenido con una serie de *valores*. Se puede omitir el tamaño de la primera dimensión si se inicializa la variable. Por ejemplo:

```cpp
// Fichero: arrays.cpp
#include<iostream>

void main () {
	int a[2];
	a[0] = 1;
	a[1] = 2;
	std::cout << a[0] << ", " << a[1] << "\n"; // 1, 2

	char b[] = "Hola"; // char b[5]
	std::cout << b << "\n"; // Hola

	int c[][2] = { {1, 2}, {3, 4} }; // int c[2][2]
	std::cout << c[0][0] << ", " << c[0][1] << "\n"; // 1, 2
	std::cout << c[1][0] << ", " << c[1][1] << "\n"; // 3, 4

	char d[][20] = { "inicio", "final" }; // char d[2][20]
	std::cout << d[0] << "\n"; // inicio
	std::cout << d[1] << "\n"; // final
}
```

Hay que tener en cuenta que la primera posición en un array es el índice cero, la segunda el índice uno y así sucesivamente. Los arrays conforman un bloque contiguo en la memoria del programa, donde se almacenan los valores, calculando su posición en la memoria mediante los índices utilizados. Al inicializar un array no es requisito inicializar todos los valores del segmento de memoria, pero sí es requisito que no excedan en número de elementos.

### Punteros

Al usar el `*`, a continuación de un tipo, modificamos su significado para convertir dicha variable en un puntero. Un puntero es un tipo de variable que apunta a otro lugar de la memoria y por lo tanto lo que almacena es una dirección de memoria. Con el operador `&` podemos obtener la dirección de memoria de cualquier variable, mientras que con el operador `*` accedemos al contenido apuntado. Por ejemplo:

```cpp
// Fichero: punteros.cpp
#include<iostream>

void main () {
	int a = 24;
	std::cout << a << "\n"; // 24

	int * b = &a;
	*b = 42;
	std::cout << a << "\n"; // 42
}
```

Con un puntero se puede acceder a un array de valores, de hecho un tipo común de las cadenas de texto es `char *`. Para recorrer los elementos de un array apuntado por un vector se puede utilizar el operador de indexación `[]`, o se puede usar la aritmética de punteros, que no es muy recomendable. Se puede definir punteros de punteros, por si necesitamos hacer una tabla de elementos. Por ejemplo:

```cpp
// Fichero: parrays.cpp
#include<iostream>

void main () {
	char c[] = "cadena";
	char * d = c;

	std::cout << d[2] << "\n"; // d
	std::cout << *(d+2) << "\n"; // d
}
```

La utilidad fundamental de los punteros es que con el operador `new` podemos reservar memoria del sistema, para almacenar un nuevo valor, y con `delete` borrar dicha memoria reservada. Por ejemplo:

```cpp
// Fichero: memoria.cpp
#include<iostream>

void main () {
	int * a = new int { 8 };
	std::cout << *a << "\n"; // 8
	delete a;

	int * b = new int[5] { 5, 4, 3, 2, 1 };
	std::cout << b[2] << "\n"; // 3
	delete[] b;

	int ** c = new int*[2] {
		new int[3] { 1, 2, 3 },
		new int[4] { 4, 5, 6, 7 }
	};
	std::cout << c[0][2] << "\n"; // 3
	std::cout << c[1][3] << "\n"; // 7
	delete[] c[0];
	delete[] c[1];
	delete[] c;
}
```

Con `new` se reserva un elemento, mientras que con `new[]` se reservan un número arbitrario de elementos. Por ello hay que utilizar `delete[]` cuando se haya usado `new[]`, para garantizar la correcta eliminación del bloque de memoria reservado. Otro aspecto relevante del ejemplo, es que con `{}` podemos opcionalmente indicar los valores con los que inicializar el bloque reservado de memoria.

> Los punteros son una característica de bajo nivel, que requiere ser metódico y cuidadoso, para evitar que los programas tengan [fugas de memoria](https://es.wikipedia.org/wiki/Fuga_de_memoria) y terminen fallando. Por ello no son muy populares entre el programador común, haciendo que muchos lenguajes dispongan de abstracciones como los [punteros inteligentes](https://es.wikipedia.org/wiki/Puntero_inteligente) y la gestión de memoria automática con [recolectores de basura](https://es.wikipedia.org/wiki/Recolector_de_basura). Sin embargo, la librería estándar de C++ incorpora punteros inteligentes como [`std::shared_ptr`](https://en.cppreference.com/w/cpp/memory/shared_ptr) y [`std::unique_ptr`](https://en.cppreference.com/w/cpp/memory/unique_ptr), que veremos más adelante.

### Referencias

Debido al poco cariño que la gente le tiene a los punteros, se introdujo en C++ el modificador `&` para convertir una variable en una referencia a otra variable. Esencialmente es un puntero con ciertas limitaciones y ventajas. Por ejemplo:

```cpp
// Fichero: referencias.cpp
#include<iostream>

void main () {
	int a { 8 };
	int b[] { 5, 4, 3, 2, 1 };
	int c[][3] { { 1, 2, 3 }, { 4, 5, 6 } };

	auto & ra = a; // int & ra = a;
	auto & rb = b; // int (& rb)[5] = b;
	auto & rc = c; // int (& rc)[2][3] = c;

	std::cout << ra << "\n"; // 8
	std::cout << rb[2] << "\n"; // 3
	std::cout << rc[0][0] << "\n"; // 1
	std::cout << rc[1][1] << "\n"; // 5
}
```

La principal ventaja es que su uso es más sencillo, porque no requiere del operador `*` para acceder al contenido al que hace referencia. Como desventajas, la primera es que no se puede declarar una referencia sin inicializar su valor. Otra desventaja es que no se le puede asignar directamente el resultado de reservar memoria con `new`, porque no están las referencias pensadas para estas tareas. Si usamos el operador `&` con una variable referencia, nos dará la dirección de memoria de la variable que referencia.

### Constantes

Una constante es un valor que no va a cambiar durante la ejecución del programa. La sintaxis básica para definir constantes es la siguiente:

$$\texttt{const}\ \mathit{tipo}\ \mathit{nombre_1}\ \texttt{=}\ \mathit{expresi\acute{o}n_1} \textcolor{red}{[} \texttt{,} \textcolor{red}{\dots} \texttt{,}\ \mathit{nombre_n}\ \texttt{=}\ \mathit{expresi\acute{o}n_n} \textcolor{red}{]} \texttt{;}$$

Para el compilador una constante es una variable capada, que no puede ser reasignada. Se puede utilizar `auto` para inferir el *tipo* en tiempo de compilación. Por ejemplo:

```cpp
// Fichero: constantes.cpp
#include<iostream>

void main () {
	const auto a = 123; // const int a
	std::cout << a << "\n"; // 123

	const auto b = "hola"; // const char * const b
	std::cout << b << "\n"; // hola
	// Ilegal: b[0] = 'H';
	// Ilegal: b = "Hola";

	const char * c = "hola";
	std::cout << c << "\n"; // hola
	// Ilegal: c[0] = 'H';
	c = "Hola";
	std::cout << c << "\n"; // Hola

	char cadena[] = "hola";
	char * const d = cadena;
	std::cout << d << "\n"; // hola
	d[0] = 'H';
	// Ilegal: d = "Hola";
	std::cout << d << "\n"; // Hola
}
```

Con tipos normales o referencias, una constante no puede cambiar el contenido del valor asignado. Pero con punteros, dependiendo de la posición donde se use `const`, si se puede llegar a cambiar el contenido de un valor asignado. Por ejemplo, `const char *` significa que no se puede modificar el contenido apuntado por la variable, pero sí se puede cambiar a dónde apunta la variable. Mientras que `char * const` lo que impide es cambiar el valor al que apunta la variable. Es un matiz importante a tener en cuenta, aunque no es habitual tener que lidiar con el segundo caso, pero sí con el primero.

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
#include<iostream>

void main () {
}
```

