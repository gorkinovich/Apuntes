# C++

[C++](https://isocpp.org/) es un lenguaje de propósito general creado por Bjarne Stroustrup en los años 80. Es un lenguaje multiparadigma de tipado estático, que compila a código máquina, por lo que sus ejecutables no son portables pero su código si puede serlo. Estos son algunos enlaces de interés:

+ [C++ Core Guidelines](http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines): Guías básicas sobre cómo programar bien en C++.
+ [CppReference](https://www.cppreference.com/): Referencia general del lenguaje y la biblioteca estándar.
+ [Microsoft Learn](https://learn.microsoft.com/es-es/cpp/): Documentación sobre su implementación del lenguaje.
+ [Visual Studio](https://visualstudio.microsoft.com/): Entorno de desarrollo para programar.
+ [Wikipedia Inglesa](https://en.wikipedia.org/wiki/C++): Artículo general sobre el lenguaje.

Para este documento vamos a utilizar la versión C++20 del estándar, cuya implementación ya está suficientemente extendida entre los principales compiladores del mercado.

## Hola mundo

El código que se compila va en ficheros `.cpp`, también conocidos como unidades de compilación, por ejemplo:

```cpp
// Fichero: hola.cpp
#include<iostream>

void main () {
    std::cout << "Hola mundo\n";
}
```

Para poner comentarios de una sola línea usamos `//`, si se quiere usar varias líneas se hace con `/*` `*/`. La directiva `#include` indica al preprocesador del compilador que incluya el contenido de otro fichero en esa posición. En el caso del ejemplo incluye la cabecera [`iostream`](https://en.cppreference.com/w/cpp/header/iostream), que contiene definiciones para trabajar con flujos de entrada y salida. Las cabeceras son ficheros, que normalmente tienen la extensión `.hpp` o `.h`, que contienen definiciones cuyo código está en otro fichero `.cpp` o en una biblioteca ya compilada (`.dll`, `.lib`, `.so`). Después tenemos la función `main`, que es la entrada al programa y en ella mandamos a la terminal una cadena de texto usando el objeto `std::cout`. Existen otras variantes de la función `main`:

```cpp
// Fichero: holarg.cpp
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

## Nombres y espacios

Para poder usar aquello que vamos a definir, necesitamos de nombres identificadores. Un identificador se compone de una sucesión de letras (mayúsculas y minúsculas), dígitos (`0`-`9`) y/o el guion bajo (`_`), que no debe comenzar por dígito. No se podrán usar las [palabras reservadas](https://en.cppreference.com/w/cpp/keyword) del lenguaje como identificadores.

Además, el lenguaje nos permite crear espacios de nombres, donde agrupar conjuntos de definiciones. Por ejemplo, `std` es el espacio de nombres donde se encuentran las definiciones de la biblioteca estándar. Para acceder al contenido de uno se usa el operador `::`, por ejemplo, `std::cout` es el nombre cualificado para acceder a la definición `cout` dentro de `std`.

La sintaxis básica para definir un espacio de nombres es la siguiente:

$$\textcolor{red}{[} \texttt{inline} \textcolor{red}{]}\ \texttt{namespace}\ \textcolor{red}{[} \mathit{nombre} \textcolor{red}{]}\ \texttt{\char123}\ \mathit{definiciones}\ \texttt{\char125}$$

La palabra clave `inline` incluye las definiciones dentro del espacio de nombres que contenga al espacio definido. Si no se incluye un nombre identificador, el ámbito de sus miembros se circunscribe a la unidad de compilación.

Alternativamente, podemos definir espacios de nombre de la siguiente manera para no tener que anidarlos manualmente:

$$\texttt{namespace}\ \mathit{nombre_1} \textcolor{red}{[} \texttt{::}\ \textcolor{red}{\cdots}\ \texttt{::}\ \textcolor{red}{[} \texttt{inline} \textcolor{red}{]}\ \mathit{nombre_n} \textcolor{red}{]}\ \texttt{\char123}\ \mathit{definiciones}\ \texttt{\char125}$$

Existe la posibilidad de utilizar los miembros de un espacio de nombres, en una unidad de compilación, sin tener que utilizar su nombre cualificado. Para ello se utiliza la sintaxis:

$$\texttt{using}\ \texttt{namespace}\ \mathit{nombre_1} \textcolor{red}{[} \texttt{::} \textcolor{red}{\cdots} \texttt{::} \mathit{nombre_n} \textcolor{red}{]} \texttt{;}$$

Si sólo queremos incorporar un miembro determinado usaremos la siguiente sintaxis:

$$\texttt{using}\ \mathit{nombre_1} \textcolor{red}{[} \texttt{::} \textcolor{red}{\cdots} \texttt{::} \mathit{nombre_n} \textcolor{red}{]} \texttt{::} \mathit{miembro} \texttt{;}$$

Si queremos crear un alias para un espacio de nombres tenemos la siguiente sintaxis:

$$\texttt{namespace}\ \mathit{nombre}\ \texttt{=}\ \mathit{nombre_1} \textcolor{red}{[} \texttt{::} \textcolor{red}{\cdots} \texttt{::} \mathit{nombre_n} \textcolor{red}{]} \texttt{;}$$

## Literales y tipos básicos

### Números enteros

La sintaxis para definir números enteros es la siguiente:

$$\textcolor{red}{[} \mathit{prefijo} \textcolor{red}{]} \mathit{d\acute{\imath}gitos} \textcolor{red}{[} \mathit{sufijo} \textcolor{red}{]}$$

> Desde C++14 se puede utilizar la comilla simple (`'`) para separar grupos de dígitos, como una especie de separador de millares arbitrario. A la hora de compilar el carácter es ignorado, por lo que es meramente estético.

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

> Desde C++17 se puede usar el prefijo `0x` o `0X` para usar dígitos hexadecimales al definir un número real. Sin embargo, para indicar el exponente se utiliza `p` o `P`, en lugar de `e` y `E`. Por ejemplo, `0x1EFp2`.

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

## Variables

Una variable es un valor con nombre que puede variar durante la ejecución del programa. La sintaxis básica para definir variables es la siguiente:

$$\mathit{tipo}\ \mathit{nombre}\ \textcolor{red}{[} \texttt{=}\ \mathit{expresi\acute{o}n} \textcolor{red}{]} \textcolor{red}{[} \texttt{,} \textcolor{red}{\dots} \textcolor{red}{]} \texttt{;}$$

Con la palabra clave `auto` se indica al compilador que infiera el tipo para la variable en base a la expresión que inicializa su valor:

$$\texttt{auto}\ \mathit{nombre}\ \texttt{=}\ \mathit{expresi\acute{o}n} \textcolor{red}{[} \texttt{,} \textcolor{red}{\dots} \textcolor{red}{]} \texttt{;}$$

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

$$\texttt{const}\ \mathit{tipo}\ \mathit{nombre}\ \texttt{=}\ \mathit{expresi\acute{o}n} \textcolor{red}{[} \texttt{,} \textcolor{red}{\dots} \textcolor{red}{]} \texttt{;}$$

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

Esta es la precedencia de mayor a menor de los operadores del lenguaje:

| Nivel | Operadores | Descripción | Asociatividad |
|:------|:----------:|:-----------:|:-------------:|
| 1 | `x::y` | Resolución de ámbito | Izquierda |
| 2 | `x++`, `x--`<br/>`T(x)`, `T{x}`<br/>`x(y)`<br/>`x[y]`<br/>`x.y`, `x->y` | Incremento/decremento postfijo<br/>Casting funcional<br/>Llamada a función<br/>Acceso indexado<br/>Acceso a miembro | Izquierda |
| 3 | `++x`, `--x`<br/>`+x`, `-x`<br/>`!x`, `~x`<br/>`(T)x`<br/>`*x`<br/>`&x`<br/>`sizeof(x)`<br/>`co_await x`<br/>`new`, `new[]`<br/>`delete`, `delete[]` | Incremento/decremento prefijo<br/>Signo positivo/negativo<br/>Negación lógica/binaria<br/>Casting clásico<br/>Contenido apuntado<br/>Dirección de<br/>Tamaño de<br/>Espera de corrutina<br/>Reservar memoria<br/>Eliminar memoria | Derecha |
| 4 | `x.*y`, `x->*y` | Puntero a miembro | Izquierda |
| 5 | `x * y`, `x / y`, `x % y` | Multiplicación, división y resto | Izquierda |
| 6 | `x + y`, `x – y` | Suma y resta | Izquierda |
| 7 | `x << y`, `x >> y` | Desplazamiento a la izquierda/derecha | Izquierda |
| 8 | `x <=> y` | Comparación por diferencia | Izquierda |
| 9 | `x < y`, `x <= y`, `x > y`, `x >= y` | Menor, menor o igual, mayor y mayor o igual | Izquierda |
| 10 | `x == y`, `x != y` | Igual y distinto | Izquierda |
| 11 | `x & y` | Conjunción binaria | Izquierda |
| 12 | `x ^ y` | Disyunción exclusiva binaria | Izquierda |
| 13 | `x | y` | Disyunción binaria | Izquierda |
| 14 | `x && y` | Conjunción booleana | Izquierda |
| 15 | `x || y` | Disyunción booleana | Izquierda |
| 16 | `x ? y : z`<br/>`throw x`<br/>`co_yield x`<br/>`x = y`<br/>`x += y`, `x -= y`, `x *= y`, `x /= y`, `x %= y`, `x &= y`, `x |= y`, `x ^= y`, `x <<= y`, `x >>= y` | Condicional<br/>Lanzar excepción<br/>Lanzar valor<br/>Asignación<br/>Asignación compuesta | Derecha |
| 17 | `x, y` | Coma | Izquierda |

Donde `x`, `y` y `z` son expresiones, y `T` es un tipo.

### Booleanos

El primer bloque de operadores booleanos son los de comparación:

| Operación | Descripción |
|:---------:|:-----------:|
| `X == Y` | `X` es igual a `Y`. |
| `X != Y` | `X` no es igual a `Y`. |
| `X <= Y` | `X` es menor o igual que `Y`. |
| `X < Y` | `X` es menor que `Y`. |
| `X >= Y` | `X` es mayor o igual que `Y`. |
| `X > Y` | `X` es mayor que `Y`. |
| `X <=> Y` | Resultado de `X - Y`. |

El primer bloque de operadores booleanos son los lógicos:

| Operación | Descripción |
|:---------:|:-----------:|
| `!X` | [Negación](https://es.wikipedia.org/wiki/Negaci%C3%B3n_l%C3%B3gica) de `X`. |
| `X && Y` | [Conjunción](https://es.wikipedia.org/wiki/Conjunci%C3%B3n_l%C3%B3gica) de `X` con `Y`. |
| `X || Y` | [Disyunción](https://es.wikipedia.org/wiki/Disyunci%C3%B3n_l%C3%B3gica) de `X` con `Y`. |

Estos operadores nos permiten componer condiciones más complejas. Para entenderlos mejor aquí tenemos sus [tablas de la verdad](https://es.wikipedia.org/wiki/Tabla_de_verdad):

|   `X`   |   `Y`   |  `!X`   |  `!Y`   | `X && Y`  | `X || Y` |
|:-------:|:-------:|:-------:|:-------:|:---------:|:--------:|
| `true`  | `true`  | `false` | `false` |  `true`   | `true`   |
| `false` | `true`  | `true`  | `false` |  `false`  | `true`   |
| `true`  | `false` | `false` | `true`  |  `false`  | `true`   |
| `false` | `false` | `true`  | `true`  |  `false`  | `false`  |

Los operadores de conjunción y disyunción funcionan por [cortocircuito](https://es.wikipedia.org/wiki/Evaluaci%C3%B3n_de_cortocircuito), por lo que si el operando izquierdo es suficiente para determinar el resultado, no se evaluará el operando derecho. Es decir, si `X` es `false` en una conjunción, el resultado será `false`, pero si es `true` en una disyunción, el resultado será `true`.

Por último, existe el operador condicional ternario `C ? T : F`, donde se evalúa la condición `C` y si esta es cierta, se devuelve el valor de la expresión `T`, si es falsa se devuelve el valor de `F`.

### Aritméticos

El primer bloque de operadores numéricos es el de los aritméticos:

| Operación | Descripción |
|:---------:|:-----------:|
| `+X` | Signo positivo. |
| `-X` | Signo negativo. |
| `X + Y` | Suma: `X` más `Y`. |
| `X - Y` | Resta: `X` menos `Y`. |
| `X * Y` | Multiplicación: `X` por `Y`. |
| `X / Y` | División: `X` entre `Y`. |
| `X % Y` | Resto de dividir `X` entre `Y`. |
| `++X`, `X++` | Incremento prefijo y postfijo. |
| `--X`, `X--` | Decremento prefijo y postfijo. |

La diferencia entre el incremento, o decremento, prefijo y postfijo radica en que la versión postfija devuelve el valor de `X` previo al cambio. Con la versión prefija se realiza el cambio y entonces se devuelve el valor de `X`:

```cpp
// Fichero: incremento.cpp
#include<iostream>

void main () {
	int x = 1;
	std::cout << ++x << "\n"; // 2
	std::cout << x++ << "\n"; // 2
	std::cout << x   << "\n"; // 3
}
```

El segundo bloque son los operadores a nivel de bits:

| Operación | Descripción |
|:---------:|:-----------:|
| `~X` | [Negación](https://es.wikipedia.org/wiki/Negaci%C3%B3n_l%C3%B3gica) de los bits de `X`. |
| `X & Y` | [Conjunción](https://es.wikipedia.org/wiki/Conjunci%C3%B3n_l%C3%B3gica) de los bits de `X` con `Y`. |
| `X | Y` | [Disyunción](https://es.wikipedia.org/wiki/Disyunci%C3%B3n_l%C3%B3gica) de los bits de `X` con `Y`. |
| `X ^ Y` | [Disyunción exclusiva](https://es.wikipedia.org/wiki/Disyunci%C3%B3n_exclusiva) de los bits de `X` con `Y`. |
| `X << Y` | Desplazamiento a la izquierda `Y` bits de `X`. |
| `X >> Y` | Desplazamiento a la derecha `Y` bits de `X`. |

De modo similar a los operadores lógicos, están son sus [tablas de la verdad](https://es.wikipedia.org/wiki/Tabla_de_verdad):

| `X` | `Y` | `~X` | `~Y` | `X & Y` | `X | Y` | `X ^ Y` |
|:---:|:---:|:----:|:----:|:-------:|:-------:|:-------:|
| `1` | `1` |  `0` |  `0` |   `1`   |   `1`   |   `0`   |
| `0` | `1` |  `1` |  `0` |   `0`   |   `1`   |   `1`   |
| `1` | `0` |  `0` |  `1` |   `0`   |   `1`   |   `1`   |
| `0` | `0` |  `1` |  `1` |   `0`   |   `0`   |   `0`   |

### Asignación

Estos son los operadores de asignación disponibles:

| Operación | Descripción |
|:---------:|:-----------:|
| `X = Y` | Asigna `Y` a `X`. |
| `X += Y` | Equivale a `X = X + Y`. |
| `X -= Y` | Equivale a `X = X - Y`. |
| `X *= Y` | Equivale a `X = X * Y`. |
| `X /= Y` | Equivale a `X = X / Y`. |
| `X %= Y` | Equivale a `X = X % Y`. |
| `X &= Y` | Equivale a `X = X & Y`. |
| `X |= Y` | Equivale a `X = X | Y`. |
| `X ^= Y` | Equivale a `X = X ^ Y`. |
| `X <<= Y` | Equivale a `X = X << Y`. |
| `X >>= Y` | Equivale a `X = X >> Y`. |

### Acceso

Estos son los operadores para acceder a miembros:

| Operación | Descripción |
|:---------:|:-----------:|
| `X::Y` | Acceso al miembro `Y` del espacio de nombres `X`. |
| `X.Y` | Acceso al miembro `Y` de `X`. |
| `X[Y]` | Acceso al elemento `Y` en `X`. |

### Punteros

El primer bloque son operadores básicos para manipular punteros:

| Operación | Descripción |
|:---------:|:-----------:|
| `X->Y` | Acceso al miembro `Y` del puntero `X`. |
| `&X` | Dirección de `X` en la memoria. |
| `*X` | Contenido apuntado por `X` en la memoria. |
| `X.*Y` | Acceso al contenido apuntado por el miembro `Y` de `X`. |
| `X->*Y` | Acceso al contenido apuntado por el miembro `Y` del puntero `X`. |

El segundo bloque son los operadores para manipular la memoria:

| Operación | Descripción |
|:---------:|:-----------:|
| `new T` | Reserva memoria para almacenar un valor del tipo `T`. |
| `new T(Args)` | Reserva memoria para almacenar un valor del tipo `T`, pasándole una serie de argumentos para construirlo. |
| `new T[]` | Reserva memoria para almacenar un array del tipo `T`. |
| `delete X` | Libera el espacio reservado para el valor apuntado por `X`. |
| `delete[] X` | Libera el espacio reservado para el array apuntado por `X`. |

### Conversiones

El siguiente bloque son operadores para convertir tipos:

| Operación | Descripción |
|:---------:|:-----------:|
| `(T)X` | *Casting* para convertir el resultado de `X` al tipo `T`. |
| `T(X)`<br/>`T{X}` | *Casting* funcional para convertir el resultado de `X` al tipo `T`. |

Estos operadores normalmente se utilizan con punteros y referencias, pero también se pueden usar con tipos básicos para forzar conversiones que requieran ser explícitas. Para hacer punteros genéricos en C, se solía utilizar el tipo `void *`, para después hacer un *casting* al tipo oportuno. Con C++ lo recomendable es usar jerarquías de tipos, para aprovechar el polimorfismo y usar algunos de los *casting* funcionales que ofrece el lenguaje:

| Casting | Descripción |
|:-------:|:------------|
| `static_cast<T>(X)` | Convierte el resultado de `X` al tipo `T` sin ninguna comprobación en tiempo de ejecución. Sin embargo, el compilador realiza algunas comprobaciones para evitar algunos errores de ejecución. |
| `dynamic_cast<T>(X)` | Convierte el resultado de `X` al tipo `T` con una comprobación en tiempo de ejecución, si esta falla se devuelve `nullptr` cuando el tipo es un puntero, o se lanza la excepción [`std::bad_cast`](https://en.cppreference.com/w/cpp/types/bad_cast) en el resto de casos. Sólo se puede usar con tipos dentro de una misma jerarquía. Para convertir una clase base a una hija, la base ha de tener algún método virtual. |
| `reinterpret_cast<T>(X)` | Convierte el resultado de `X` al tipo `T` sin ninguna comprobación en tiempo de ejecución. Es esencialmente un *casting* al estilo C para punteros. |
| `const_cast<T>(X)` | Convierte el resultado de `X` al tipo `T` para eliminar el modificador `const` o añadirlo. |

### Especiales

Estos son operadores que no entran en las demás categorías antes expuestas:

| Operación | Descripción |
|:---------:|:-----------:|
| `X, Y` | Ejecuta la expresión `X` y después la expresión `Y`. |
| `F(Args)` | Invocación de la función `F` con una serie de argumentos. |
| `sizeof(X)` | Da el tamaño que ocupa en memoria la expresión `X`. |
| `throw x` | Lanza el valor de `X` como una excepción. |
| `co_await X` | Espera asíncrona para el resultado de la corrutina `X`. |
| `co_yield X` | Lanza el valor `X` en una corrutina generadora. |

## Sentencias

### Condicionales

La primera sentencia de control es el `if`-`else`, cuya sintaxis es la siguiente:

$$\texttt{if}\ \texttt{(} \mathit{condici\acute{o}n} \texttt{)}\ \mathit{bloque_{true}}\ \textcolor{red}{[} \texttt{else}\ \mathit{bloque_{false}} \textcolor{red}{]}$$

Un bloque puede ser una sentencia terminada con punto y coma (`expresión;`) o un bloque de sentencias delimitado por llaves (`{ expresiones }`). Si la condición se evalúa a `true`, se ejecutará el primer bloque, si no se ejecutará el segundo si está definido. Por ejemplo:

```cpp
// Fichero: ifelse.cpp
#include<iostream>

void main () {
	int a, b;
	std::cout << "A = ";
	std::cin  >> a;
	std::cout << "B = ";
	std::cin  >> b;

	if (a == b) {
		std::cout << "A y B son iguales.\n";
	} else if (a < b) {
		std::cout << "A es menor que B.\n";
	} else {
		std::cout << "A es mayor que B.\n";
	}
}
```

> En el ejemplo vemos el objeto `std::cin`, que nos permite introducir por consola un valor y almacenarlo en una variable. Téngase en cuenta que este objeto no reserva automáticamente memoria, por lo que para introducir una cadena de texto se requiere tener reservado previamente el espacio necesario o utilizar tipos como `std::string`.

Desde C++17 se puede introducir antes de la condición, separado con un punto y coma, una expresión de inicialización. Por ejemplo:

```cpp
// Fichero: ifinit.cpp
#include <string>
#include <iostream>

void main () {
	std::string nombre;
	std::cout << "Nombre: ";
	if (std::cin >> nombre; !nombre.empty()) {
		std::cout << "Hola, " << nombre << ".\n";
	}
}
```

La sentencia de control `switch` permite evaluar una expresión y ejecutar un bloque dependiendo del valor obtenido. Su sintaxis es:

$$\begin{array}{l}
\texttt{switch}\ \texttt{(} \mathit{expresi\acute{o}n} \texttt{)}\ \texttt{\char123}
\\[0.5em] \qquad \textcolor{red}{[} \texttt{case}\ \mathit{literal_1} \texttt{:}\ \mathit{expresiones_1} \textcolor{red}{]}
\\[0.5em] \qquad\qquad \textcolor{red}{\vdots}
\\[0.5em] \qquad \textcolor{red}{[} \texttt{case}\ \mathit{literal_n} \texttt{:}\ \mathit{expresiones_n} \textcolor{red}{]}
\\[0.5em] \qquad \textcolor{red}{[} \texttt{default:}\ \mathit{expresiones} \textcolor{red}{]}
\\[0.5em] \texttt{\char125}
\end{array}$$

Dependiendo del valor de la *expresión*, se va buscando en orden una cláusula `case` donde encaje su valor. La primera que encaje será el punto de entrada de la ejecución, ejecutando sus expresiones hasta encontrar la sentencia `break` al final de dicho bloque, pues de lo contrario saltaría a ejecutar el cuerpo de la siguiente cláusula. Si no se encaja con ninguna cláusula, se ejecutará la cláusula `default` de estar definida. Por ejemplo:

```cpp
// Fichero: switch.cpp
#include<iostream>

void main () {
	int a;
	std::cout << "> ";
	std::cin  >> a;

	switch (a) {
	case 5:  std::cout << "Cinco.\n";
	case 4:  std::cout << "Cuatro.\n";
	case 3:  std::cout << "Tres.\n";
	case 2:  std::cout << "Dos.\n";
	case 1:  std::cout << "Uno.\n";
	case 0:  std::cout << "Cero.\n";
			 break;
	default: std::cout << "Indefinido.\n";
	}
}
```

### Bucles

La sentencia de control `while` permite ejecutar un bloque de código mientras se cumpla una condición. Su sintaxis es:

$$\texttt{while}\ \texttt{(} \mathit{condici\acute{o}n} \texttt{)}\ \mathit{bloque}$$

Con la sentencia `do`-`while` podremos hacer lo mismo que con la anterior, con la diferencia de que siempre se ejecutará al menos una vez el bloque de código. Su sintaxis es:

$$\texttt{do}\ \mathit{bloque}\ \texttt{while}\ \texttt{(} \mathit{condici\acute{o}n} \texttt{)} \texttt{;}$$

Si queremos ejecutar el código un número determinado de veces, con la sentencia `for` podremos hacerlo con la siguiente sintaxis:

$$\texttt{for}\ \texttt{(} \textcolor{red}{[} \mathit{inicio} \textcolor{red}{]} \texttt{;}\ \textcolor{red}{[} \mathit{condici\acute{o}n} \textcolor{red}{]} \texttt{;}\ \textcolor{red}{[} \mathit{incremento} \textcolor{red}{]} \texttt{)}\ \mathit{bloque}$$

Donde *inicio* son las expresiones, separadas por comas, que se ejecutan antes de entrar en el bucle. Normalmente se utiliza el inicio para declarar las variables contadoras del bucle. Con *condición*, en cada iteración del bucle, se controla al inicio de cada vuelta si se ha de ejecutar o no. Y con *incremento* tenemos las expresiones que se ejecutan al final de cada iteración, que habitualmente se usan para incrementar los contadores.

Existe una variante del bucle `for` que nos permite recorrer los elementos de un contenedor de datos, tales como los arrays por ejemplo. Su sintaxis es:

$$\texttt{for}\ \texttt{(} \mathit{tipo}\ \mathit{nombre}\ \texttt{:}\ \mathit{contenedor} \texttt{)}\ \mathit{bloque}$$

De forma similar a lo que vimos con el `if`, desde C++20 se puede introducir, separado con un punto y coma, una expresión de inicialización en los bucles `for` para contenedores.

Con este ejemplo podremos ver en acción los diferentes tipos de bucles:

```cpp
// Fichero: bucles.cpp
#include <string>
#include <iostream>

void main () {
	const int SIZE = 4;
	int nums[SIZE] = { 1, 2, 3, 4 };
	std::string respuesta;
	do {
		int i = 0;
		std::cout << "While: ";
		while (i < SIZE) {
			std::cout << nums[i] << " ";
			++i;
		}
		std::cout << "\n";

		std::cout << "For: ";
		for (int j = 0; j < SIZE; j++) {
			std::cout << nums[j] << " ";
		}
		std::cout << "\n";

		std::cout << "For each: ";
		for (auto n : nums) {
			std::cout << n << " ";
		}
		std::cout << "\n";

		std::cout << "¿Salir? (S/N) ";
		std::cin >> respuesta;
	} while (respuesta != "s" && respuesta != "S");
}
```

### Saltos y retornos

La primera sentencia de salto es `return`, que se utiliza para salir de una función, devolviendo un valor de forma opcional. Su sintaxis es:

$$\texttt{return}\ \textcolor{red}{[} \mathit{expresi\acute{o}n} \textcolor{red}{]} \texttt{;}$$

Después están `break` y `continue`. La primera se utiliza en bucles, o sentencias `switch`, para salir fuera de dicha sentencia que la contiene. La segunda se utiliza en bucles y, en lugar de salir de este, lo que provoca es un salto a la siguiente iteración del bucle. Su sintaxis es:

$$\texttt{break} \texttt{;}$$

$$\texttt{continue} \texttt{;}$$

Para entenderlo mejor, veamos el siguiente ejemplo:

```cpp
// Fichero: saltos.cpp
#include<iostream>

void main () {
	int xs[] = {
		1, 2, 3, 4, 5, 6, 7, 0, 8, 9
	};

	for (auto x : xs) {
		if (x == 0) break;
		if (x % 2 == 0) continue;
		std::cout << x << " ";
	}
	std::cout << "\n";
	// 1 3 5 7
}
```

Por último está el demonio de la programación estructurada, la sentencia maldita, la portadora de grandes tormentos de ofuscación, la que no debería ser nombrada. La sentencia `goto` se utiliza para hacer un salto incondicional a otra parte del código, que se identifica con una etiqueta. La sintaxis de esta herejía es:

$$\mathit{etiqueta} \texttt{:}$$

$$\texttt{goto}\ \mathit{etiqueta} \texttt{;}$$

El uso de `goto` no se recomienda en absoluto, ya que puede derivar en muy malas prácticas de programación. Su uso debe estar muy justificado y es preferible utilizar otras opciones antes.

### Excepciones

Las excepciones es un mecanismo del lenguaje para gestionar los errores en nuestros programas. Cuando algo falle de forma inesperada, podemos lanzar una excepción con la siguiente sintaxis:

$$\texttt{throw}\ \textcolor{red}{[} \mathit{excepci\acute{o}n} \textcolor{red}{]} \texttt{;}$$

Donde *excepción* debe ser una expresión que devuelva un valor. La biblioteca estándar dispone de la clase base [`std::exception`](https://en.cppreference.com/w/cpp/error/exception) para representar excepciones, pero el lenguaje permite lanzar todo tipo de valores.

Una vez lanzada la excepción, por nosotros o por el sistema, tendremos que capturarla con la sentencia `try`-`catch`, cuya sintaxis es:

$$\begin{array}{l}
\texttt{try}\ \texttt{\char123}\ \mathit{expresiones_0}\ \texttt{\char125}
\\[0.5em] \textcolor{red}{[} \texttt{catch}\ \texttt{(} \mathit{tipo_1}\ \textcolor{red}{[} \mathit{nombre_1} \textcolor{red}{]} \texttt{)}\ \texttt{\char123}\ \mathit{expresiones_1}\ \texttt{\char125} \textcolor{red}{]}
\\[0.5em] \qquad\qquad \textcolor{red}{\vdots}
\\[0.5em] \textcolor{red}{[} \texttt{catch}\ \texttt{(} \mathit{tipo_n}\ \textcolor{red}{[} \mathit{nombre_n} \textcolor{red}{]} \texttt{)}\ \texttt{\char123}\ \mathit{expresiones_n}\ \texttt{\char125} \textcolor{red}{]}
\\[0.5em] \textcolor{red}{[} \texttt{catch}\ \texttt{(...)}\ \texttt{\char123}\ \mathit{expresiones_c}\ \texttt{\char125} \textcolor{red}{]}
\end{array}$$

Hay que tener en cuenta que `try` debe ir acompañado al menos de un `catch`. En caso de lanzarse una excepción, se comprobará en el orden que están definidas las cláusulas `catch`, para ejecutar el bloque de expresiones que primero encaje con el error recibido. Esto significa que el orden importa, por lo que si la primera es un `catch (...)`, todas las que vengan después quedarán tapadas por esta primera, ya que es el modelo más genérico para capturar excepciones. Dentro de un `catch` se puede usar `throw;`, que relanza la última excepción capturada.

En este ejemplo podemos ver un manejo básico de las excepciones:

```cpp
// Fichero: excepciones.cpp
#include<iostream>

void main () {
	try {
		throw 42;
		std::cout << "Todo fue bien\n";
	} catch (...) {
		std::cout << "Error inesperado\n";
	}
}
```

## Funciones

Una [función](https://en.cppreference.com/w/cpp/language/function) es un bloque de código con nombre, que podemos parametrizar, para obtener diferentes resultados. Para definir una se utiliza la siguiente sintaxis:

$$\mathit{tipo}\ \mathit{nombre} \texttt{(} \textcolor{red}{[} \mathit{par\acute{a}metros} \textcolor{red}{]} \texttt{)}\ \textcolor{red}{[} \mathit{modificadores} \textcolor{red}{]}\ \textcolor{red}{[} \texttt{->}\ \mathit{tipo} \textcolor{red}{]}\ \texttt{\char123}\ \mathit{expresiones}\ \texttt{\char125}$$

Una función tiene un tipo de retorno, pero si no devuelve nada usará `void` como tipo del resultado. También se permite usar `auto` como tipo de retorno, para inferir el tipo en tiempo de compilación. Luego se puede tener entre cero y N parámetros, cuya sintaxis es:

$$\textcolor{red}{[} \texttt{const} \textcolor{red}{]}\ \mathit{tipo}\ \textcolor{red}{[} \mathit{nombre}\ \textcolor{red}{[} \texttt{=}\ \mathit{valor} \textcolor{red}{]} \textcolor{red}{]} \textcolor{red}{[} \texttt{,} \textcolor{red}{\dots} \textcolor{red}{]}$$

Se puede, por herencia de C, usar `void` para indicar que no tiene parámetros, pero lo normal es no poner nada entre los paréntesis. También podemos usar `auto` como tipo de un parámetro, para inferir su tipo con el compilador. El lenguaje permite definir valores por defecto para los parámetros, pero sólo si el parámetro tiene un nombre y los parámetros a continuación también tienen valores por defecto.

> C++ es un lenguaje que permite polimorfismo, por lo que podemos tener dos funciones definidas con el mismo nombre, siempre que varíen los parámetros de su definición. Por lo que podemos tener `void foo ()`, `void foo (int)` y `char foo (bool)` al mismo tiempo sin problemas. A la hora de invocar la función, dependiendo del tipo del argumento se elegirá una función u otra.

La firma de una función corresponde a toda la definición previa al cuerpo de la misma, definido con `{ expresiones }`. Si necesitamos utilizar la función en un lugar del proyecto donde no está definida, podremos declararla usando la firma de la función, sin el cuerpo, terminando la sentencia con un punto y coma. Por ejemplo:

```cpp
// Declaración:
int suma (int, int);

// Definición:
int suma (int a, int b) {
    return a + b;
}
```

En cuanto a los *modificadores* disponibles, para funciones que no son miembros de un tipo, son los que indican si la función está libre de excepciones o no:

| Modificador | Descripción |
|:-----------:|:------------|
| `noexcept`<br/>`noexcept(true)` | La función no lanza excepciones. |
| `noexcept(false)` | La función lanza excepciones. |
| `throw()`<br/>`throw(tipos)` | La función lanza excepciones.<br/> (**Nota:** deprecado en C++17 y eliminado en C++20.) |

> Disponemos del operador `noexcept(X)` para saber si la expresión `X` no lanza excepciones, devolviendo como resultado un booleano.

Con el sufijo `-> tipo` indicamos el tipo de retorno de la función y requiere el uso de `auto`. Se utiliza esta herramienta para dar información al compilador de lo que tiene que inferir. Lo habitual es usar este mecanismo en conjunción con plantillas y el operador [`decltype(X)`](https://en.cppreference.com/w/cpp/language/decltype), que infiere el tipo para una entidad o expresión.

Existe el prefijo [`inline`](https://en.cppreference.com/w/cpp/language/inline), que permite indicar al compilador que debe insertar el código de la función en los puntos del programa donde es invocada. El compilador no siempre podrá insertar el código, por lo que es una recomendación que el programador da para la optimización del programa.

La elipsis `...` sirve para crear funciones con un número variable de argumentos en su llamada. Se añade al final de la lista de parámetros, pudiendo separarlo opcionalmente con una coma por compatibilidad con C. Su uso no impide usar valores por defecto para los parámetros anteriores. Para poder usar este tipo de parámetros, es necesario utilizar la cabecera [`cstdarg`](https://en.cppreference.com/w/cpp/header/cstdarg), que dispone de los siguientes elementos:

| Elemento | Descripción |
|:--------:|:------------|
| `std::va_list` | Estructura para almacenar los argumentos variables. |
| `va_start(L, N)` | Carga en la lista `L` un número `N` de argumentos. |
| `va_copy(LD, LS)` | Copia en la lista `LD` el contenido de `LS`. |
| `va_arg(L, T)` | Devuelve el siguiente argumento en la lista `L`, indicando su tipo con `T`. |
| `va_end(L)` | Elimina la lista `L` de argumentos. |

Por ejemplo:

```cpp
// Fichero: varargs.cpp
#include <cstdarg>
#include <iostream>

int sum (int n, ...) {
	int r = 0;
	std::va_list args;
	va_start(args, n);
	for (int i = 0; i < n; i++) {
		r += va_arg(args, int);
	}
	va_end(args);
	return r;
}

void main () {
	std::cout << sum(4, 1, 2, 3, 4) << "\n"; // 10
}
```

## Lambdas

Las [expresiones lambda](https://en.cppreference.com/w/cpp/language/lambda) es una forma de definir una función sin nombre. Son bien conocidas en el mundo de la programación funcional. Se utilizan mucho para procesar datos en contenedores de la biblioteca estándar, de los que veremos ejemplos más adelante.

La sintaxis básica para definir una lambda es la siguiente:

$$\texttt{[} \mathit{capturas} \texttt{]}\ \texttt{(} \textcolor{red}{[} \mathit{par\acute{a}metros} \textcolor{red}{]} \texttt{)}\ \textcolor{red}{[} \mathit{modificadores} \textcolor{red}{]}\ \textcolor{red}{[} \texttt{->}\ \mathit{tipo} \textcolor{red}{]}\ \texttt{\char123}\ \mathit{expresiones}\ \texttt{\char125}$$

En cuanto a los *parámetros* se usa las mismas reglas que las funciones normales para su definición. Pero antes, tenemos las *capturas*, que es una lista de variables sobre las que vamos a hacer el cierre (*closure*), para poder usarlas en el cuerpo de la lambda. Hay que tener en cuenta que las lambdas se traducen en objetos de la clase [`std::function`](https://en.cppreference.com/w/cpp/utility/functional/function), por lo que se pueden devolver como resultados de una función y por ello hay que gestionar cómo se cierran las variables. Para ello esta lista de cero o más variables, separadas por comas, podrán declararse con la siguiente sintaxis:

$$\textcolor{red}{\char123} \texttt{\char38}\ \textcolor{red}{|}\ \texttt{=}\ \textcolor{red}{|}\ \textcolor{red}{[} \texttt{*} \textcolor{red}{]} \texttt{this}\ \textcolor{red}{|}\ \textcolor{red}{[} \texttt{\char38} \textcolor{red}{]} \mathit{nombre}\ \textcolor{red}{[} \mathit{inicializaci\acute{o}n} \textcolor{red}{|} \texttt{...} \textcolor{red}{]}\ \textcolor{red}{|}\ \textcolor{red}{[} \texttt{\char38} \textcolor{red}{]} \texttt{...} \mathit{nombre}\ \mathit{inicializaci\acute{o}n} \textcolor{red}{\char125}$$

Con `&` se capturan por referencia todas las variables utilizadas en el cuerpo de la lambda que estén en el ámbito de la misma, mientras que con `=` se capturan por copia. Con `this` se capturan por referencia los miembros del objeto del que es miembro la función donde se ha declarado la expresión lambda, pero con `*this` se capturan por copia. Luego podemos indicar el *nombre* de las variables que queremos capturar, ya sea por copia o por referencia con `&`. La elipsis `...` se utiliza para el [pack de expansión](https://en.cppreference.com/w/cpp/language/parameter_pack) de variables en plantillas, que explicaremos más adelante.

Hay que tener en cuenta, que con el cierre de las variables lo que se está haciendo es crear una nueva variable con el mismo nombre, que será una propiedad del objeto función que se está construyendo. Por eso podemos modificar la inicialización de dichas propiedades con las siguientes formas:

| Forma | Descripción |
|:-----:|:------------|
| `= expresión` | Se inicializa con el valor de la expresión, que también puede ser una lista de expresiones entre llaves. |
| `(expresiones)` | Lista de valores entre paréntesis. |
| `{expresiones}` | Lista de valores entre llaves. |
| `{miembros}` | Lista de valores asignados a los miembros del tipo, con la forma `.miembro = expresión`. Los miembros que se declaren en la lista, tienen que estar en el orden en el que han sido definidos en el tipo o no compilará el código. |

En cuanto a los *modificadores* disponibles, tenemos un grupo opcional que especifica el comportamiento general de la lambda:

| Modificador | Descripción |
|:-----------:|:------------|
| `mutable` | Permite al cuerpo de la función a modificar las variables capturadas por copia e invocar sus métodos no constantes, ya que por defecto la copia se asume como `const`. |
| `constexpr` | Define la lambda como una función `constexpr`. |
| `consteval` | Define la lambda como una función `consteval`. No se pueden utilizar `consteval` y `constexpr` al mismo tiempo. |

Después viene, de forma también opcional, el modificador de comportamiento de excepciones:

| Modificador | Descripción |
|:-----------:|:------------|
| `noexcept`<br/>`noexcept(true)` | La función no lanza excepciones. |
| `noexcept(false)` | La función lanza excepciones. |
| `throw()`<br/>`throw(tipos)` | La función lanza excepciones.<br/> (**Nota:** deprecado en C++17 y eliminado en C++20.) |

A continuación está `-> tipo`, para indicar el tipo de retorno de la función lambda, por si queremos hacerlo explícito en lugar de dejar al compilador inferirlo en base a las expresiones `return` del cuerpo de la misma.

## Tipos avanzados

### Clases

..

### Estructuras

..

### Enumeraciones

..

### Uniones

..

## Plantillas

..

### Lambdas genéricas

..

$$\texttt{[} \mathit{capturas} \texttt{]}\ \textcolor{red}{[} \texttt{<} \mathit{tipos} \texttt{>}\ \textcolor{red}{[} \mathit{requisitos} \textcolor{red}{]} \textcolor{red}{]}\ \texttt{(} \textcolor{red}{[} \mathit{par\acute{a}metros} \textcolor{red}{]} \texttt{)}\ \textcolor{red}{[} \mathit{modificadores} \textcolor{red}{]}\ \textcolor{red}{[} \texttt{->}\ \mathit{tipo}\ \textcolor{red}{[} \mathit{requisitos} \textcolor{red}{]} \textcolor{red}{]}\ \texttt{\char123}\ \mathit{expresiones}\ \texttt{\char125}$$

..

## Definiciones avanzadas

### Usando `constexpr`

..

### Usando `consteval`

..

### Usando `inline`

..

## Preprocesador

El [preprocesado](https://en.cppreference.com/w/cpp/preprocessor) es la etapa inicial de la compilación, que realiza sustituciones de texto.

### Macros

La directiva más básica es definir [macros](https://en.cppreference.com/w/cpp/preprocessor/replace), que consiste en un identificador que se va a sustituir por un texto determinado. Para ello se usa la siguiente sintaxis:

$$\texttt{\char35define}\ \mathit{nombre}\ \textcolor{red}{[} \mathit{texto} \textcolor{red}{]}$$

El texto es opcional, porque podemos simplemente definir una macro para hacer comprobaciones condicionales, que se verán en la siguiente sección. Si queremos eliminar una macro usaremos la directiva:

$$\texttt{\char35undef}\ \mathit{nombre}$$

Aunque no es recomendable, se pueden definir macros con parámetros con la directiva:

$$\texttt{\char35define}\ \mathit{nombre} \texttt{(} \textcolor{red}{\char123} \mathit{par\acute{a}metros} \textcolor{red}{[} \texttt{,}\ \texttt{...} \textcolor{red}{]} \textcolor{red}{|} \texttt{...} \textcolor{red}{\char125} \texttt{)}\ \textcolor{red}{[} \mathit{texto} \textcolor{red}{]}$$

Los parámetros es una lista separada por comas de nombres. La elipsis `...` se utiliza para crear macros que tengan un número arbitrario de argumentos en sus usos. Para este último caso se utiliza las macros:
+ `__VA_OPT__(texto)`: Que añade el texto indicado si la lista de argumentos arbitrario no está vacía.
+ `__VA_ARGS__`: Añade los argumentos arbitrarios separados por comas.

Finalmente, tenemos un par de operadores para los parámetros de las macros. Usando el operador `#` con un parámetro, este se convertirá en un literal de cadena de texto. Con el operador `##` tomará el parámetro y lo concatenará al texto al que esté a su izquierda.

### Condicionales

Estas son las directivas [condicionales](https://en.cppreference.com/w/cpp/preprocessor/conditional) del preprocesador:

| Directiva | Descripción |
|:---------:|:------------|
| `#ifdef nombre` | Si está definida la macro `nombre` se procesa el bloque siguiente. |
| `#ifndef nombre` | Si no está definida la macro `nombre` se procesa el bloque siguiente. |
| `#if expresión` | Si es cierta la `expresión` se procesa el bloque siguiente. |
| `#elif expresión` | Si no son ciertas las condiciones anteriores, pero sí lo es la `expresión` se procesa el bloque siguiente. |
| `#else` | Si no son ciertas las condiciones anteriores se procesa el bloque siguiente. |
| `#endif` | Cierra el bloque de directivas condicionales. |

### Ficheros

Para [incluir ficheros](https://en.cppreference.com/w/cpp/preprocessor/include) dentro de otro, tenemos las siguientes directivas:

| Directiva | Descripción |
|:---------:|:------------|
| `#include <fichero>` | Incluye un fichero que buscará en las rutas de librerías indicadas al compilar. |
| `#include "fichero"` | Incluye un fichero que buscará en el directorio actual. |

El fichero puede ser una ruta, cuando se use la forma con comillas.

## Módulos

Para organizar un proyecto, se divide en unidades de compilación el código, que son ficheros `.cpp`. El método clásico, si queremos acceder a las definiciones de dichas unidades, consiste en definir una cabecera `.h` o `.hpp`, que contenga definiciones y firmas de funciones. Por ejemplo:

```cpp
// Fichero: tools.hpp
#ifndef __TOOLS_H__
#define __TOOLS_H__

int inc (int);

#endif
```

```cpp
// Fichero: tools.cpp
#include "tools.hpp"

int inc (int x) {
    return x + 1;
}
```

```cpp
// Fichero: main.cpp
#include<iostream>
#include<tools.hpp>

void main () {
    std::cout << inc(1) << "\n";
}
```

Pero con C++20 se incluye la posibilidad de definir [módulos](https://en.cppreference.com/w/cpp/language/modules), para facilitar la definición de unidades de compilación y su acceso. Para ello tenemos las expresiones `export` e `import`, la primera para exportar definiciones y la segunda para importar módulos o cabeceras.

..

Por ejemplo, aplicado al anterior ejemplo:

```cpp
// Fichero: tools.cpp
export module tools;
export int inc (int);
module : private;

int inc (int x) {
    return x + 1;
}
```

```cpp
// Fichero: main.cpp
import <iostream>;
import tools;

void main () {
    std::cout << inc(1) << "\n";
}
```

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

