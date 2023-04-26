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

int main () {
    std::cout << "Hola mundo\n";
}
```

Para poner comentarios de una sola línea usamos `//`, si se quiere usar varias líneas se hace con `/*` `*/`. La directiva `#include` indica al preprocesador del compilador que incluya el contenido de otro fichero en esa posición. En el caso del ejemplo incluye la cabecera [`iostream`](https://en.cppreference.com/w/cpp/header/iostream), que contiene definiciones para trabajar con flujos de entrada y salida. Las cabeceras son ficheros, que normalmente tienen la extensión `.hpp` o `.h`, que contienen definiciones cuyo código está en otro fichero `.cpp` o en una biblioteca ya compilada (`.dll`, `.lib`, `.so`). Después tenemos la función `main`, que es la entrada al programa y en ella mandamos a la terminal una cadena de texto usando el objeto `std::cout`.

> La función `main` es la única que permite omitir devolver un valor con `return`. Si se omite esta operación, por defecto el compilador hará que el programa devuelva el valor `0`.

Existen otra variante de la función `main`:

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

En este caso la función `main` devuelve un valor entero, donde `0` indica que no ha habido ningún error, y recibe una serie de argumentos, donde `argc` es el número de argumentos recibido y `argv` los argumentos como cadenas de texto. Las cadenas de texto estándar de C, son segmentos de memoria que terminan con el valor `0` (no confundirlo con el carácter cero). En el ejemplo mostramos el número de argumentos y con la sentencia `for` vamos mostrando cada argumento por pantalla.

> Existen diferentes compiladores, como el de [MSVC](https://learn.microsoft.com/cpp/build/reference/c-cpp-building-reference) o el [GCC](https://gcc.gnu.org/), que tienen una cantidad considerable de opciones que no vamos a documentar aquí. Lo más fácil es utilizar un IDE, que se encargue de gestionar la compilación.

## Nombres y espacios

Para poder usar aquello que vamos a definir, necesitamos de nombres identificadores. Un identificador se compone de una sucesión de letras (mayúsculas y minúsculas), dígitos (`0`-`9`) y/o el guion bajo (`_`), que no debe comenzar por dígito. No se podrán usar las [palabras reservadas](https://en.cppreference.com/w/cpp/keyword) del lenguaje como identificadores.

> Es muy importante tener en cuenta en C++, que no podremos usar ningún elemento que no haya sido definido o declarado previamente a su uso. Esto implica ciertas incomodidades que no tienen muchos lenguajes modernos, por ello C y C++ suelen tener código cuyo propósito es declarar la existencia de una definición que se encuentra en otra unidad de compilación o más adelante dentro de la misma unidad.

Además, el lenguaje nos permite crear espacios de nombres, donde agrupar conjuntos de definiciones. Por ejemplo, `std` es el espacio de nombres donde se encuentran las definiciones de la biblioteca estándar. Para acceder al contenido de uno se usa el operador `::`, por ejemplo, `std::cout` es el nombre cualificado para acceder a la definición `cout` dentro de `std`. La forma `::miembro` hace referencia a miembros que están en el espacio de nombres global a todos.

La sintaxis básica para definir un espacio de nombres es la siguiente:

$$\textcolor{red}{[} \texttt{inline} \textcolor{red}{]}\ \texttt{namespace}\ \textcolor{red}{[} \mathit{nombre} \textcolor{red}{]}\ \texttt{\\{}\ \mathit{definiciones}\ \texttt{\\}}$$

La palabra clave `inline` incluye las definiciones dentro del espacio de nombres que contenga al espacio definido. Si no se incluye un nombre identificador, el ámbito de sus miembros se circunscribe a la unidad de compilación.

Alternativamente, podemos definir espacios de nombre de la siguiente manera para no tener que anidarlos manualmente:

$$\texttt{namespace}\ \mathit{nombre_1} \textcolor{red}{[} \texttt{::}\ \textcolor{red}{\cdots}\ \texttt{::}\ \textcolor{red}{[} \texttt{inline} \textcolor{red}{]}\ \mathit{nombre_n} \textcolor{red}{]}\ \texttt{\\{}\ \mathit{definiciones}\ \texttt{\\}}$$

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

$$\mathit{d\acute{\imath}gitos} \textcolor{red}{[} \texttt{.} \mathit{d\acute{\imath}gitos} \textcolor{red}{]} \textcolor{red}{[} \textcolor{red}{\\{} \texttt{e} \textcolor{red}{|} \texttt{E} \textcolor{red}{\\}} \textcolor{red}{[} \texttt{+} \textcolor{red}{|} \texttt{-} \textcolor{red}{]} \mathit{d\acute{\imath}gitos} \textcolor{red}{]} \textcolor{red}{[} \mathit{sufijo} \textcolor{red}{]}$$

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

$$\textcolor{red}{[} \mathit{prefijo} \textcolor{red}{]} \texttt{'} \textcolor{red}{\\{} \mathit{letra} \textcolor{red}{|} \mathit{secuencia\ de\ escape} \textcolor{red}{\\}} \texttt{'}$$

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

$$\textcolor{red}{\\{} \texttt{true} \textcolor{red}{|} \texttt{false} \textcolor{red}{\\}}$$

> Por compatibilidad con el lenguaje C, el valor `true` equivale al entero `1` y `false` al `0`. Por ello hay que entender la siguiente regla: una condición será falsa si su valor es cero y cierta con cualquier otro valor.

### Puntero nulo

Un puntero es un tipo de valor que nos indica una dirección de memoria donde está el valor con el que vamos a trabajar. En el caso de no apuntar valor alguno, utilizaremos el literal `nullptr`.

> Internamente equivale al valor cero y sustituye a la histórica macro `NULL`, para ayudar al compilador con las conversiones. El tipo `std::nullptr_t` representa los punteros nulos en el estándar y tiene el mismo tamaño que el tipo `void *`.

## Variables

Una variable es un valor con nombre que puede variar durante la ejecución del programa. La sintaxis básica para definir variables es la siguiente:

$$\mathit{tipo}\ \mathit{nombre}\ \textcolor{red}{[} \texttt{=}\ \mathit{expresi\acute{o}n} \textcolor{red}{]} \textcolor{red}{[} \texttt{,} \textcolor{red}{\dots}\ \textcolor{red}{]} \texttt{;}$$

Con la palabra clave `auto` se indica al compilador que infiera el tipo para la variable en base a la expresión que inicializa su valor:

$$\texttt{auto}\ \mathit{nombre}\ \texttt{=}\ \mathit{expresi\acute{o}n} \textcolor{red}{[} \texttt{,} \textcolor{red}{\dots}\ \textcolor{red}{]} \texttt{;}$$

Cada *nombre* representa una dirección en la memoria, donde se almacena el valor resultante de evaluar la *expresión* que se le asigne a la variable, ya sea en la inicialización o con el operador asignación (`=`). El tipo le indica al compilador el tamaño que ocupan los valores con los que vamos a trabajar, para acceder a su estructura interna de forma correcta. Por ejemplo:

```cpp
// Fichero: variables.cpp
#include<iostream>

int main () {
    int a = 1, b = 2;
    auto c = 3.14;
    std::cout << a << ", " << b << ", " << c << "\n"; // 1, 2, 3.14
    b = 4;
    std::cout << a << ", " << b << ", " << c << "\n"; // 1, 4, 3.14
}
```

### Arrays

Los arrays son bloques de memoria que contienen un número fijo de elementos, a los que se acceden de forma indexada. La sintaxis básica para definir arrays es la siguiente:

$$\mathit{tipo}\ \mathit{nombre} \texttt{[} \textcolor{red}{[} \mathit{tam_1} \textcolor{red}{]} \texttt{]} \textcolor{red}{[} \texttt{[} \mathit{tam_2} \texttt{]} \textcolor{red}{\dots} \texttt{[} \mathit{tam_n} \texttt{]} \textcolor{red}{]}\ \textcolor{red}{[} \texttt{=}\ \texttt{\\{}\ \mathit{expresiones}\ \texttt{\\}} \textcolor{red}{]} \textcolor{red}{[} \texttt{,} \textcolor{red}{\dots}\ \textcolor{red}{]} \texttt{;}$$

Entre corchetes indicamos el *tamaño* de cada dimensión del array, pudiendo inicializar el contenido con una serie de *valores*. Se puede omitir el tamaño de la primera dimensión si se inicializa la variable. Por ejemplo:

```cpp
// Fichero: arrays.cpp
#include<iostream>

int main () {
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

int main () {
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

int main () {
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

int main () {
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

int main () {
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

$$\texttt{const}\ \mathit{tipo}\ \mathit{nombre}\ \texttt{=}\ \mathit{expresi\acute{o}n} \textcolor{red}{[} \texttt{,} \textcolor{red}{\dots}\ \textcolor{red}{]} \texttt{;}$$

Para el compilador una constante es una variable capada, que no puede ser reasignada. Se puede utilizar `auto` para inferir el *tipo* en tiempo de compilación. Por ejemplo:

```cpp
// Fichero: constantes.cpp
#include<iostream>

int main () {
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
| 13 | `x \| y` | Disyunción binaria | Izquierda |
| 14 | `x && y` | Conjunción booleana | Izquierda |
| 15 | `x \|\| y` | Disyunción booleana | Izquierda |
| 16 | `x ? y : z`<br/>`throw x`<br/>`co_yield x`<br/>`x = y`<br/>`x += y`, `x -= y`, `x *= y`, `x /= y`, `x %= y`, `x &= y`, `x \|= y`, `x ^= y`, `x <<= y`, `x >>= y` | Condicional<br/>Lanzar excepción<br/>Lanzar valor<br/>Asignación<br/>Asignación compuesta | Derecha |
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
| `X \|\| Y` | [Disyunción](https://es.wikipedia.org/wiki/Disyunci%C3%B3n_l%C3%B3gica) de `X` con `Y`. |

Estos operadores nos permiten componer condiciones más complejas. Para entenderlos mejor aquí tenemos sus [tablas de la verdad](https://es.wikipedia.org/wiki/Tabla_de_verdad):

|   `X`   |   `Y`   |  `!X`   |  `!Y`   | `X && Y`  | `X \|\| Y` |
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

int main () {
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
| `X \| Y` | [Disyunción](https://es.wikipedia.org/wiki/Disyunci%C3%B3n_l%C3%B3gica) de los bits de `X` con `Y`. |
| `X ^ Y` | [Disyunción exclusiva](https://es.wikipedia.org/wiki/Disyunci%C3%B3n_exclusiva) de los bits de `X` con `Y`. |
| `X << Y` | Desplazamiento a la izquierda `Y` bits de `X`. |
| `X >> Y` | Desplazamiento a la derecha `Y` bits de `X`. |

De modo similar a los operadores lógicos, están son sus [tablas de la verdad](https://es.wikipedia.org/wiki/Tabla_de_verdad):

| `X` | `Y` | `~X` | `~Y` | `X & Y` | `X \| Y` | `X ^ Y` |
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
| `X \|= Y` | Equivale a `X = X \| Y`. |
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

int main () {
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

int main () {
    std::string nombre;
    std::cout << "Nombre: ";
    if (std::cin >> nombre; !nombre.empty()) {
        std::cout << "Hola, " << nombre << ".\n";
    }
}
```

La sentencia de control `switch` permite evaluar una expresión y ejecutar un bloque dependiendo del valor obtenido. Su sintaxis es:

$$\begin{array}{l}
\texttt{switch}\ \texttt{(} \mathit{expresi\acute{o}n} \texttt{)}\ \texttt{\\{}
\\\\[0.5em] \qquad \textcolor{red}{[} \texttt{case}\ \mathit{literal_1} \texttt{:}\ \mathit{expresiones_1} \textcolor{red}{]}
\\\\[0.5em] \qquad\qquad \textcolor{red}{\vdots}
\\\\[0.5em] \qquad \textcolor{red}{[} \texttt{case}\ \mathit{literal_n} \texttt{:}\ \mathit{expresiones_n} \textcolor{red}{]}
\\\\[0.5em] \qquad \textcolor{red}{[} \texttt{default:}\ \mathit{expresiones} \textcolor{red}{]}
\\\\[0.5em] \texttt{\\}}
\end{array}$$

Dependiendo del valor de la *expresión*, se va buscando en orden una cláusula `case` donde encaje su valor. La primera que encaje será el punto de entrada de la ejecución, ejecutando sus expresiones hasta encontrar la sentencia `break` al final de dicho bloque, pues de lo contrario saltaría a ejecutar el cuerpo de la siguiente cláusula. Si no se encaja con ninguna cláusula, se ejecutará la cláusula `default` de estar definida. Por ejemplo:

```cpp
// Fichero: switch.cpp
#include<iostream>

int main () {
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

int main () {
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

int main () {
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
\texttt{try}\ \texttt{\\{}\ \mathit{expresiones_0}\ \texttt{\\}}
\\\\[0.5em] \textcolor{red}{[} \texttt{catch}\ \texttt{(} \mathit{tipo_1}\ \textcolor{red}{[} \mathit{nombre_1} \textcolor{red}{]} \texttt{)}\ \texttt{\\{}\ \mathit{expresiones_1}\ \texttt{\\}} \textcolor{red}{]}
\\\\[0.5em] \qquad\qquad \textcolor{red}{\vdots}
\\\\[0.5em] \textcolor{red}{[} \texttt{catch}\ \texttt{(} \mathit{tipo_n}\ \textcolor{red}{[} \mathit{nombre_n} \textcolor{red}{]} \texttt{)}\ \texttt{\\{}\ \mathit{expresiones_n}\ \texttt{\\}} \textcolor{red}{]}
\\\\[0.5em] \textcolor{red}{[} \texttt{catch}\ \texttt{(...)}\ \texttt{\\{}\ \mathit{expresiones_c}\ \texttt{\\}} \textcolor{red}{]}
\end{array}$$

Hay que tener en cuenta que `try` debe ir acompañado al menos de un `catch`. En caso de lanzarse una excepción, se comprobará en el orden que están definidas las cláusulas `catch`, para ejecutar el bloque de expresiones que primero encaje con el error recibido. Esto significa que el orden importa, por lo que si la primera es un `catch (...)`, todas las que vengan después quedarán tapadas por esta primera, ya que es el modelo más genérico para capturar excepciones. Dentro de un `catch` se puede usar `throw;`, que relanza la última excepción capturada.

En este ejemplo podemos ver un manejo básico de las excepciones:

```cpp
// Fichero: excepciones.cpp
#include<iostream>

int main () {
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

$$\mathit{tipo}\ \mathit{nombre} \texttt{(} \textcolor{red}{[} \mathit{par\acute{a}metros} \textcolor{red}{]} \texttt{)}\ \textcolor{red}{[} \mathit{modificadores} \textcolor{red}{]}\ \textcolor{red}{[} \texttt{->}\ \mathit{tipo} \textcolor{red}{]}\ \texttt{\\{}\ \mathit{expresiones}\ \texttt{\\}}$$

Una función tiene un tipo de retorno, pero si no devuelve nada usará `void` como tipo del resultado. También se permite usar `auto` como tipo de retorno, para inferir el tipo en tiempo de compilación. Luego se puede tener entre cero y N parámetros, cuya sintaxis es:

$$\textcolor{red}{[} \texttt{const} \textcolor{red}{]}\ \mathit{tipo}\ \textcolor{red}{[} \mathit{nombre}\ \textcolor{red}{[} \texttt{=}\ \mathit{valor} \textcolor{red}{]} \textcolor{red}{]} \textcolor{red}{[} \texttt{,} \textcolor{red}{\dots}\ \textcolor{red}{]}$$

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

int main () {
    std::cout << sum(4, 1, 2, 3, 4) << "\n"; // 10
}
```

## Lambdas

Las [expresiones lambda](https://en.cppreference.com/w/cpp/language/lambda) es una forma de definir una función sin nombre. Son bien conocidas en el mundo de la programación funcional. Se utilizan mucho para procesar datos en contenedores de la biblioteca estándar, de los que veremos ejemplos más adelante.

La sintaxis básica para definir una lambda es la siguiente:

$$\texttt{[} \mathit{capturas} \texttt{]}\ \texttt{(} \textcolor{red}{[} \mathit{par\acute{a}metros} \textcolor{red}{]} \texttt{)}\ \textcolor{red}{[} \mathit{modificadores} \textcolor{red}{]}\ \textcolor{red}{[} \texttt{->}\ \mathit{tipo} \textcolor{red}{]}\ \texttt{\\{}\ \mathit{expresiones}\ \texttt{\\}}$$

En cuanto a los *parámetros* se usa las mismas reglas que las funciones normales para su definición. Pero antes, tenemos las *capturas*, que es una lista de variables sobre las que vamos a hacer el cierre (*closure*), para poder usarlas en el cuerpo de la lambda. Hay que tener en cuenta que las lambdas se traducen en objetos de la clase [`std::function`](https://en.cppreference.com/w/cpp/utility/functional/function), por lo que se pueden devolver como resultados de una función y por ello hay que gestionar cómo se cierran las variables. Para ello esta lista de cero o más variables, separadas por comas, podrán declararse con la siguiente sintaxis:

$$\textcolor{red}{\\{} \texttt{\\&}\ \textcolor{red}{|}\ \texttt{=}\ \textcolor{red}{|}\ \textcolor{red}{[} \texttt{*} \textcolor{red}{]} \texttt{this}\ \textcolor{red}{|}\ \textcolor{red}{[} \texttt{\\&} \textcolor{red}{]} \mathit{nombre}\ \textcolor{red}{[} \mathit{inicializaci\acute{o}n} \textcolor{red}{|} \texttt{...} \textcolor{red}{]}\ \textcolor{red}{|}\ \textcolor{red}{[} \texttt{\\&} \textcolor{red}{]} \texttt{...} \mathit{nombre}\ \mathit{inicializaci\acute{o}n} \textcolor{red}{\\}}$$

Con `&` se capturan por referencia todas las variables utilizadas en el cuerpo de la lambda que estén en el ámbito de la misma, mientras que con `=` se capturan por copia. Con `this` se capturan por referencia los miembros del objeto del que es miembro la función donde se ha declarado la expresión lambda, pero con `*this` se capturan por copia. Luego podemos indicar el *nombre* de las variables que queremos capturar, ya sea por copia o por referencia con `&`. La elipsis `...` se utiliza para el [pack de expansión](https://en.cppreference.com/w/cpp/language/parameter_pack) de variables en plantillas, que explicaremos más adelante.

Hay que tener en cuenta, que con el cierre de las variables lo que se está haciendo es crear una nueva variable con el mismo nombre, que será una propiedad del objeto función que se está construyendo. Por eso podemos modificar la [inicialización](https://en.cppreference.com/w/cpp/language/initialization) de dichas propiedades con las siguientes formas:

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

## Clases

Las clases son la forma de definir tipos por parte del usuario, para expresar abstracciones y estructuras de datos más complejas de las ofrecidas por el lenguaje. Su sintaxis básica es la siguiente:

$$\begin{array}{l}
\texttt{class}\ \mathit{nombre}\ \textcolor{red}{[} \texttt{final} \textcolor{red}{]}\ \textcolor{red}{[} \texttt{:}\ \mathit{padres} \textcolor{red}{]}\ \texttt{\\{}
\\\\[0.5em] \textcolor{red}{[} \texttt{public:}
\\\\[0.5em] \qquad \mathit{definiciones\ p\acute{u}blicas} \textcolor{red}{]}
\\\\[0.5em] \textcolor{red}{[} \texttt{protected:}
\\\\[0.5em] \qquad \mathit{definiciones\ protegidas} \textcolor{red}{]}
\\\\[0.5em] \textcolor{red}{[} \texttt{private:}
\\\\[0.5em] \qquad \mathit{definiciones\ privadas} \textcolor{red}{]}
\\\\[0.5em] \texttt{\\}} \texttt{;}
\end{array}$$

El orden de las secciones puede variar e incluso podemos tener varias secciones con el mismo tipo de visibilidad si fuera necesario. En caso de definir miembros fuera de una sección, se asume `private` como visibilidad por defecto. Dependiendo de la visibilidad, los miembros de la clase serán accesibles o no desde fuera:

| Visibilidad | `public` | `protected` | `private` |
|:------------|:--------:|:-----------:|:---------:|
| Dentro de la clase actual | Sí | Sí | Sí |
| Dentro de las clases hijas | Sí | Sí | No |
| Fuera de las anteriores | Sí | No | No |

El lenguaje C++ permite herencia múltiple entre tipos. Cuando una clase hereda de otra, puede incorporar definiciones a las que puede acceder y sobrescribir si fuera necesario. Con el modificador `final` se impide que la clase pueda ser heredadas por otras clases. Para heredar de otras clases tenemos la lista de padres, que tiene la siguiente sintaxis:

$$\textcolor{red}{[} \texttt{virtual} \textcolor{red}{]}\ \textcolor{red}{[} \texttt{public} \textcolor{red}{|} \texttt{protected} \textcolor{red}{|} \texttt{private} \textcolor{red}{]}\ \mathit{nombre}\ \textcolor{red}{[} \texttt{,}\ \textcolor{red}{\dots}\ \textcolor{red}{]}$$

Si no se indica la visibilidad del padre heredado, se asume por defecto que será `private`, modificando así la visibilidad de los miembros heredados para restringirlos todavía más. En cuanto al modificador `virtual`, marca la clase heredada como una clase base virtual, para evitar problemas con la herencia múltiple, cuando una clase superior es heredada múltiples veces por una descendiente. `virtual` puede usarse también después de los modificadores de visibilidad. Por ejemplo:

```cpp
// Fichero: multiple.cpp
#include<iostream>

class A {
public:
    void hola () {
        std::cout << "Hola\n";
    }
};

class B : virtual public A {};
class C : virtual public A {};
class D : public B, public C {};

int main () {
    D objeto;
    objeto.hola();
}
```

### Atributos

Los atributos de una clase son las variables definidas para almacenar la información. Para definir uno se usa la siguiente sintaxis:

$$\textcolor{red}{[} \texttt{mutable} \textcolor{red}{]}\ \textcolor{red}{[} \texttt{volatile} \textcolor{red}{]}\ \textcolor{red}{[} \texttt{const} \textcolor{red}{]}\ \mathit{tipo}\ \mathit{nombre}\ \textcolor{red}{[} \texttt{=}\ \mathit{inicializaci\acute{o}n} \textcolor{red}{]} \texttt{;}$$

Los modificadores aceptados para los atributos son:

| Modificador | Descripción |
|:-----------:|:------------|
| `mutable` | Permite que una variable no estática sea modificable al usarse desde una función constante. |
| `volatile` | Avisa la compilador que la variable se usa de forma volátil en código concurrente, para optimizar su uso. |
| `const` | La variable es una constante y no se puede modificar su valor. |

> El modificador `mutable` no se puede usar con un tipo constante (`const T`), pero sí con un puntero a un tipo constante (`const T *` o `const T &`).

Para [inicializar](https://en.cppreference.com/w/cpp/language/initialization) una variable, tenemos las siguientes formas:

| Forma | Descripción |
|:-----:|:------------|
| `= expresión` | Se inicializa con el valor de la expresión, que también puede ser una lista de expresiones entre llaves. |
| `(expresiones)` | Lista de valores entre paréntesis. |
| `{expresiones}` | Lista de valores entre llaves. |
| `{miembros}` | Lista de valores asignados a los miembros del tipo, con la forma `.miembro = expresión`. Los miembros que se declaren en la lista, tienen que estar en el orden en el que han sido definidos en el tipo o no compilará el código. |

### Métodos

Los métodos de una clase son las funciones definidas para ejecutar las operaciones que implementa. Para definir uno se usa la siguiente sintaxis:

$$\textcolor{red}{[} \texttt{constexpr} \textcolor{red}{|} \texttt{consteval} \textcolor{red}{]}\ \mathit{tipo}\ \mathit{nombre} \texttt{(} \textcolor{red}{[} \mathit{par\acute{a}metros} \textcolor{red}{]} \texttt{)}\ \textcolor{red}{[} \texttt{volatile} \textcolor{red}{]}$$

$$\textcolor{red}{[} \texttt{const} \textcolor{red}{]}\ \textcolor{red}{[} \texttt{\\&} \textcolor{red}{|} \texttt{\\&\\&} \textcolor{red}{]}\ \textcolor{red}{[} \texttt{noexcept} \textcolor{red}{[} \texttt{(} \mathit{booleano} \texttt{)} \textcolor{red}{]} \textcolor{red}{]}\ \textcolor{red}{[} \texttt{->}\ \mathit{tipo} \textcolor{red}{]}\ \textcolor{red}{\\{} \texttt{;}\ \textcolor{red}{|}\ \texttt{\\{}\ \mathit{expresiones}\ \texttt{\\}} \textcolor{red}{\\}}$$

Si no implementamos el cuerpo de la función dentro de la clase, hay que hacerlo fuera con la siguiente sintaxis:

$$\textcolor{red}{[} \texttt{inline} \textcolor{red}{]}\ \textcolor{red}{[} \texttt{constexpr} \textcolor{red}{|} \texttt{consteval} \textcolor{red}{]}\ \mathit{tipo}\ \mathit{clase} \texttt{::} \mathit{nombre} \texttt{(} \textcolor{red}{[} \mathit{par\acute{a}metros} \textcolor{red}{]} \texttt{)}$$

$$\textcolor{red}{[} \texttt{volatile} \textcolor{red}{]}\ \textcolor{red}{[} \texttt{const} \textcolor{red}{]}\ \textcolor{red}{[} \texttt{\\&} \textcolor{red}{|} \texttt{\\&\\&} \textcolor{red}{]}\ \textcolor{red}{[} \texttt{noexcept} \textcolor{red}{[} \texttt{(} \mathit{booleano} \texttt{)} \textcolor{red}{]} \textcolor{red}{]}\ \textcolor{red}{[} \texttt{->}\ \mathit{tipo} \textcolor{red}{]}\ \texttt{\\{}\ \mathit{expresiones}\ \texttt{\\}}$$

Hay que tener en cuenta que la firma, declarada dentro de la clase, tiene que ser exactamente la misma definida fuera. Igual que pasaba con las funciones que no pertenecen a una clase, tenemos el modificador `noexcept` para indicar si el método lanza excepciones o no. Luego `-> tipo` indica cual es el tipo a devolver al usar `auto` como tipo de retorno en la firma de la función. En cuanto al resto de modificadores:

| Modificador | Descripción |
|:-----------:|:------------|
| `constexpr` | Pide al compilador que el miembro sea constante o ejecutable por el compilador. |
| `consteval` | Define y fuerza que la función sea ejecutable por el compilador. |
| `volatile` | La función puede ser usada por objetos volátiles y los parámetros de la función también serán tratados como variables volátiles. |
| `const` | La función es sólo de lectura, no puede modificar el contenido del objeto, salvo que el atributo esté definido como mutable. |
| `&` | La función es invocada cuando el objeto que la invoca es un valor normal (*LVALUE*). |
| `&&` | La función es invocada cuando el objeto que la invoca es un valor que ha sido movido (*RVALUE*). |
| `inline` | Se recomienda al compilador que inserte el código del cuerpo de la función en aquellos sitios donde es invocada. Cuando el cuerpo se define dentro de la clase, se asume este modificador como implícito. |

Veamos un ejemplo con un par de métodos:

```cpp
// Fichero: metodos.cpp
#include<iostream>

class Foo {
public:
    const int a = 1;
    mutable int b = 2;
    int c = 3;

    int foo (int) const;

    void bar () {
        std::cout << a << ", " << b << ", "
            << ++c << "; " << foo(c) << "\n";
    }
};

int Foo::foo(int a) const {
    a *= this->a + (b++);
    return a + a;
}

int main () {
    Foo obj;
    obj.bar(); // 1, 2, 4; 24
    obj.bar(); // 1, 3, 5; 40
}
```

La expresión `this`, usada en el ejemplo, es un puntero a la propia instancia que está llamando al método. Su uso puede ser útil para resolver conflictos, cuando un parámetro de una función tiene el mismo nombre que un miembro de la clase.

### Métodos virtuales

Cuando heredamos de una clase podemos querer que se sobrescriban algunos métodos, para cambiar el comportamiento de una determinada operación, aprovechando así los mecanismos de herencia y polimorfismo conjuntamente. Para ello tenemos que usar el modificador `virtual`, al inicio de la firma de la función, en aquellas funciones que podrían ser rescritas en las clases hijas.

> Definir qué métodos son virtuales es necesario para que el compilador las añada a la tabla de funciones virtuales (*vtable*) de la clase, que luego será apuntada por un puntero oculto (*vptr*) en las clases base, para saber cuáles son los métodos que tiene que llamar para la instancia actual.

Con el modificador `= 0`, que va al final de la firma de la función, podemos indicar que es un método virtual abstracto. Esto quiere decir que el método no tiene implementación para esa clase, por lo que las clases hijas tendrán que encargarse para poder ser instanciadas.

Para rescribir un método virtual, a partir de C++11, se utilizan los modificadores `override` y `final`, que son situados al final de la firma de la función. Aunque el lenguaje permite combinaciones extrañas, lo aconsejable es usar cada uno suelto. Usaremos `override` cuando simplemente queremos sobrescribir un método virtual en una clase hija. Pero usaremos `final` si queremos sobrescribirlo e impedir que las clases hijas puedan sobrescribirlo.

> Antes de C++11, para sobrescribir una función virtual se usaba el modificador `virtual`. Todavía se puede seguir usando el método en C++20, pero se recomienda usar `override` y `final` en su lugar.

Para comprender mejor lo anterior veamos un ejemplo:

```cpp
// Fichero: herencia.cpp
#include <iostream>

class A {
public:
    virtual void foo () = 0;
    virtual void bar () {
        std::cout << "A::bar()\n";
    }
};

class B : public A {
public:
    void foo () final {
        std::cout << "B::foo()\n";
    }
    void bar () override = 0;
};

class C : public B {
public:
    void bar () override {
        std::cout << "C::bar()\n";
    }
};

class D : public A {
public:
    void foo () override {
        std::cout << "D::foo()\n";
    }
};

int main () {
    A * c = new C();
    c->foo(); // B::foo()
    c->bar(); // C::bar()

    A * d = new D();
    d->foo(); // D::foo()
    d->bar(); // A::bar()

    delete c;
    delete d;
}
```

Las clase `A` tiene dos métodos virtuales, uno de ellos abstracto, por lo que es una clase abstracta y no puede ser instanciada. Después la clase `B` hereda de `A` y sobrescribe el método abstracto `foo`, pero sobrescribe `bar` para que sea abstracto, convirtiendo la clase también en abstracta. Entonces la clase `C` hereda de `B`, sobrescribiendo `bar` para poder instanciarla. Por último tenemos la clase `D` que hereda de `A` y sobrescribe `foo` para poder instanciarla.

### Métodos especiales

Existe una serie de métodos especiales en los tipos, que definen cómo se construye una instancia, cómo se destruye o cómo se copia. La sintaxis de los constructores es:

$$\textcolor{red}{[} \texttt{explicit} \textcolor{red}{]}\ \textcolor{red}{[} \texttt{constexpr} \textcolor{red}{|} \texttt{consteval} \textcolor{red}{]}\ \mathit{clase} \texttt{(} \textcolor{red}{[} \mathit{par\acute{a}metros} \textcolor{red}{]} \texttt{)}\ \textcolor{red}{[} \texttt{noexcept} \textcolor{red}{[} \texttt{(} \mathit{booleano} \texttt{)} \textcolor{red}{]} \textcolor{red}{]}$$

$$\textcolor{red}{\\{} \textcolor{red}{[} \texttt{= default} \textcolor{red}{|} \texttt{= delete} \textcolor{red}{]} \texttt{;}\ \textcolor{red}{|}\ \textcolor{red}{[} \texttt{:}\ \mathit{inicializadores} \textcolor{red}{]}\ \texttt{\\{}\ \mathit{expresiones}\ \texttt{\\}} \textcolor{red}{\\}}$$

Si no implementamos el cuerpo dentro de la clase, hay que hacerlo fuera con la siguiente sintaxis:

$$\textcolor{red}{[} \texttt{inline} \textcolor{red}{]}\ \textcolor{red}{[} \texttt{constexpr} \textcolor{red}{|} \texttt{consteval} \textcolor{red}{]}\ \mathit{clase} \texttt{::} \mathit{clase} \texttt{(} \textcolor{red}{[} \mathit{par\acute{a}metros} \textcolor{red}{]} \texttt{)}$$

$$\textcolor{red}{[} \texttt{noexcept} \textcolor{red}{[} \texttt{(} \mathit{booleano} \texttt{)} \textcolor{red}{]} \textcolor{red}{]}\ \textcolor{red}{[} \texttt{:}\ \mathit{inicializadores} \textcolor{red}{]}\ \texttt{\\{}\ \mathit{expresiones}\ \texttt{\\}}$$

Un constructor puede tener una lista de parámetros, como las funciones normales. El constructor con cero parámetros se denomina [constructor por defecto](https://en.cppreference.com/w/cpp/language/default_constructor). También tenemos el caso especial del [constructor copia](https://en.cppreference.com/w/cpp/language/copy_constructor) (`clase(const clase & obj)`), así como el [constructor de movimiento](https://en.cppreference.com/w/cpp/language/move_constructor) (`clase(clase && obj)`). El primero hace una copia de `obj` para crear la nueva instancia, mientras que el segundo se queda con todos los recursos (punteros y referencias) para construir la nueva instancia.

> Para forzar la invocación del constructor de movimiento, se puede utilizar la función [`std::move`](https://en.cppreference.com/w/cpp/utility/move).

 Además de los modificadores previamente vistos, con [`explicit`](https://en.cppreference.com/w/cpp/language/explicit) se añade como requisito que el tipo de los argumentos ha de corresponder con el tipo de los parámetros. Esto evita que se haga una conversión implícita para hacer encajar el valor en el tipo del parámetro. Luego tenemos `=default`, que sólo se puede aplicar al constructor por defecto, el de copia y el de movimiento, que indica de forma explícita al compilador que genere la versión por defecto automáticamente. Mientras que `=delete`, que se puede aplicar a todo tipo de constructor, indica al compilador que no se va a generar ningún código para dicho constructor.

Los inicializadores son una lista con la forma `nombre(expresión)` o `nombre{expresión}`, donde el nombre puede ser una variable interna o un tipo padre de la clase, que inicializa lo valores de la instancia que se está construyendo. Dependiendo de la expresión asignada, se usará un constructor u otro para inicializar cada elemento, por ello se usaba la notación con paréntesis, pero con C++11 se incorporó el uso de llaves para hacer lo mismo y unificar diferentes tipos de inicialización de objetos.

A continuación, la sintaxis de los destructores es:

$$\textcolor{red}{[} \texttt{virtual} \textcolor{red}{]}\ \textcolor{red}{[} \texttt{constexpr} \textcolor{red}{|} \texttt{consteval} \textcolor{red}{]}\ \texttt{\\~{}}\ \mathit{clase} \texttt{(} \texttt{)}\ \textcolor{red}{[} \texttt{noexcept} \textcolor{red}{[} \texttt{(} \mathit{booleano} \texttt{)} \textcolor{red}{]} \textcolor{red}{]}$$

$$\textcolor{red}{\\{} \textcolor{red}{[} \texttt{= default} \textcolor{red}{|} \texttt{= delete} \textcolor{red}{]} \texttt{;}\ \textcolor{red}{|}\ \texttt{\\{}\ \mathit{expresiones}\ \texttt{\\}} \textcolor{red}{\\}}$$

Si no implementamos el cuerpo dentro de la clase, hay que hacerlo fuera con la siguiente sintaxis:

$$\textcolor{red}{[} \texttt{inline} \textcolor{red}{]}\ \textcolor{red}{[} \texttt{constexpr} \textcolor{red}{|} \texttt{consteval} \textcolor{red}{]}\ \mathit{clase} \texttt{::} \texttt{\\~{}}\ \mathit{clase} \texttt{(} \texttt{)}$$

$$\textcolor{red}{[} \texttt{noexcept} \textcolor{red}{[} \texttt{(} \mathit{booleano} \texttt{)} \textcolor{red}{]} \textcolor{red}{]}\ \texttt{\\{}\ \mathit{expresiones}\ \texttt{\\}}$$

Por último, la sintaxis del operador de [copia](https://en.cppreference.com/w/cpp/language/copy_assignment)/[movimiento](https://en.cppreference.com/w/cpp/language/move_assignment) es:

$$\textcolor{red}{[} \texttt{virtual} \textcolor{red}{]}\ \textcolor{red}{[} \texttt{constexpr} \textcolor{red}{|} \texttt{consteval} \textcolor{red}{]}\ \mathit{clase}\ \texttt{\\&}\ \texttt{operator =} \texttt{(} \mathit{par\acute{a}metro} \texttt{)}$$

$$\textcolor{red}{[} \texttt{noexcept} \textcolor{red}{[} \texttt{(} \mathit{booleano} \texttt{)} \textcolor{red}{]} \textcolor{red}{]}\ \textcolor{red}{\\{} \textcolor{red}{[} \texttt{= default} \textcolor{red}{|} \texttt{= delete} \textcolor{red}{]} \texttt{;}\ \textcolor{red}{|}\ \texttt{\\{}\ \mathit{expresiones}\ \texttt{\\}} \textcolor{red}{\\}}$$

Si no implementamos el cuerpo dentro de la clase, hay que hacerlo fuera con la siguiente sintaxis:

$$\textcolor{red}{[} \texttt{inline} \textcolor{red}{]}\ \textcolor{red}{[} \texttt{constexpr} \textcolor{red}{|} \texttt{consteval} \textcolor{red}{]}\ \mathit{clase}\ \texttt{\\&}\ \mathit{clase} \texttt{::} \texttt{operator =} \texttt{(} \mathit{par\acute{a}metro} \texttt{)}$$

$$\textcolor{red}{[} \texttt{noexcept} \textcolor{red}{[} \texttt{(} \mathit{booleano} \texttt{)} \textcolor{red}{]} \textcolor{red}{]}\ \texttt{\\{}\ \mathit{expresiones}\ \texttt{\\}}$$

Donde el parámetro puede ser `clase obj`, `const clase & obj` o `clase && obj`, siendo este último para hacer el operador de movimiento.

> Para hacer un operador de copia se suele usar como tipo `const clase &`, pero en ocasiones hay desarrolladores que utilizan el patrón *copia-e-intercambio* y por ello usan como tipo `clase`. Este patrón hace un intercambio entre el objeto de origen y el de destino.

Por último veamos un ejemplo de lo anterior:

```cpp
// Fichero: especial.cpp
#include <iostream>

class Foo {
public:
    Foo() {
        std::cout << "Foo()\n";
    }

    explicit Foo(int v) {
        std::cout << "Foo(int) -> " << v << "\n";
    }

    Foo(const Foo & obj) {
        std::cout << "Foo(const Foo &)\n";
    }

    Foo(Foo && obj) {
        std::cout << "Foo(Foo &&)\n";
    }

    virtual ~Foo() {
        std::cout << "~Foo()\n";
    }

    Foo & operator =(const Foo & obj) {
        std::cout << "operator =(const Foo &)\n";
        return *this;
    }

    Foo & operator =(Foo && obj) {
        std::cout << "operator =(Foo &&)\n";
        return *this;
    }
};

int main () {
    Foo a, b(42), c(a), d(std::move(c));
    b = d;
    a = std::move(b);
}
```

### Miembros estáticos

Los miembros estáticos no forman parte de los objetos instanciados de una clase, sino a la clase misma. Para acceder a ellos se usa la forma `clase::miembro`, en lugar de acceder con los operadores `.` o `->`.

Para declarar una variable estática se utiliza la siguiente sintaxis:

$$\texttt{static}\ \textcolor{red}{[} \texttt{volatile} \textcolor{red}{]}\ \textcolor{red}{[} \texttt{const} \textcolor{red}{]}\ \mathit{tipo}\ \mathit{nombre} \texttt{;}$$

Para inicializar la variable estática, se debe hacer fuera de la clase con la siguiente sintaxis:

$$\textcolor{red}{[} \texttt{volatile} \textcolor{red}{]}\ \textcolor{red}{[} \texttt{const} \textcolor{red}{]}\ \mathit{tipo}\ \mathit{clase} \texttt{::} \mathit{nombre}\ \texttt{=}\ \mathit{inicializaci\acute{o}n} \texttt{;}$$

Para declarar o definir una función estática se utiliza la siguiente sintaxis:

$$\texttt{static}\ \textcolor{red}{[} \texttt{constexpr} \textcolor{red}{|} \texttt{consteval} \textcolor{red}{]}\ \mathit{tipo}\ \mathit{nombre} \texttt{(} \textcolor{red}{[} \mathit{par\acute{a}metros} \textcolor{red}{]} \texttt{)}$$

$$\textcolor{red}{[} \texttt{noexcept} \textcolor{red}{[} \texttt{(} \mathit{booleano} \texttt{)} \textcolor{red}{]} \textcolor{red}{]}\ \textcolor{red}{[} \texttt{->}\ \mathit{tipo} \textcolor{red}{]}\ \textcolor{red}{\\{} \texttt{;}\ \textcolor{red}{|}\ \texttt{\\{}\ \mathit{expresiones}\ \texttt{\\}} \textcolor{red}{\\}}$$

Si no implementamos el cuerpo de la función estática dentro de la clase, hay que hacerlo fuera con la siguiente sintaxis:

$$\textcolor{red}{[} \texttt{inline} \textcolor{red}{]}\ \textcolor{red}{[} \texttt{constexpr} \textcolor{red}{|} \texttt{consteval} \textcolor{red}{]}\ \mathit{tipo}\ \mathit{clase} \texttt{::} \mathit{nombre} \texttt{(} \textcolor{red}{[} \mathit{par\acute{a}metros} \textcolor{red}{]} \texttt{)}$$

$$\textcolor{red}{[} \texttt{noexcept} \textcolor{red}{[} \texttt{(} \mathit{booleano} \texttt{)} \textcolor{red}{]} \textcolor{red}{]}\ \textcolor{red}{[} \texttt{->}\ \mathit{tipo} \textcolor{red}{]}\ \texttt{\\{}\ \mathit{expresiones}\ \texttt{\\}}$$

Salvo por el modificador `static`, el resto de modificadores son iguales que en los métodos de una clase. Veamos un ejemplo para hacernos una idea de todo lo anterior:

```cpp
// Fichero: estatico.cpp
#include<iostream>

class Foo {
public:
    static int a;
    static int foo (int);
};

int Foo::a = 0;

int Foo::foo(int b) {
    a += b;
    return a;
}

int main () {
    Foo::a = 10;
    std::cout << Foo::a      << "\n"; // 10
    std::cout << Foo::foo(1) << "\n"; // 11
}
```

### Estructuras

Las estructuras es una forma alternativa para definir tipos por parte del usuario. Su sintaxis básica es la siguiente:

$$\begin{array}{l}
\texttt{struct}\ \mathit{nombre}\ \textcolor{red}{[} \texttt{final} \textcolor{red}{]}\ \textcolor{red}{[} \texttt{:}\ \mathit{padres} \textcolor{red}{]}\ \texttt{\\{}
\\\\[0.5em] \textcolor{red}{[} \texttt{public:}
\\\\[0.5em] \qquad \mathit{definiciones\ p\acute{u}blicas} \textcolor{red}{]}
\\\\[0.5em] \textcolor{red}{[} \texttt{protected:}
\\\\[0.5em] \qquad \mathit{definiciones\ protegidas} \textcolor{red}{]}
\\\\[0.5em] \textcolor{red}{[} \texttt{private:}
\\\\[0.5em] \qquad \mathit{definiciones\ privadas} \textcolor{red}{]}
\\\\[0.5em] \texttt{\\}} \texttt{;}
\end{array}$$

Su existencia en el lenguaje se debe a una herencia del lenguaje C, pero en C++ actualmente funcionan exactamente como un tipo definido con `class`, con la diferencia de que por defecto la visibilidad es pública, si no se indica ningún bloque de visibilidad.

## Uniones

Las uniones son un tipo de dato especial, que permite definir una abstracción que contenga diferentes tipos de información en el mismo espacio de memoria a lo largo del tiempo. Su sintaxis básica es la siguiente:

$$\begin{array}{l}
\texttt{union}\ \mathit{nombre}\ \texttt{\\{}
\\\\[0.5em] \qquad \mathit{definiciones}
\\\\[0.5em] \texttt{\\}} \texttt{;}
\end{array}$$

En cuanto a definiciones se permiten variables, funciones y tipos. Puede tener constructores y destructores, pero no puede tener métodos virtuales. También están limitados los tipos que se pueden usar para las variables, estos no pueden tener métodos especiales.

La utilidad de las uniones viene de los tiempos de C, cuando era necesario tener diferentes estructuras de datos almacenables desde un solo tipo, algo así como una jerarquía de clases solapadas en una sola clase. En memoria se reserva el espacio para el tipo mayor de toda la unión y se almacena la información dentro de dicho espacio, para interpretarla en base a la variable que se haga referencia a la hora de recuperar la información. Por ejemplo:

```cpp
// Fichero: union.cpp
#include<iostream>

union Foo {
    char a;
    short b;
    int c;
};

int main () {
    Foo v;
    v.c = 0x12345678;
    std::cout << std::hex << v.c << "\n"; // 12345678
    std::cout << std::hex << v.b << "\n"; // 5678
    std::cout << std::hex << (int)v.a << "\n"; // 78
}
```

## Enumeraciones

Las enumeraciones son tipos de datos que asocian valores con nombres identificadores, creando constantes de forma ordenada y agrupada. Su sintaxis básica es la siguiente:

$$\texttt{enum}\ \textcolor{red}{[} \texttt{class} \textcolor{red}{|} \texttt{struct} \textcolor{red}{]}\ \mathit{nombre}\ \textcolor{red}{[} \texttt{:}\ \mathit{tipo} \textcolor{red}{]}\ \texttt{\\{} \mathit{nombre_1}\ \textcolor{red}{[} \texttt{=}\ \mathit{valor_1} \textcolor{red}{]} \textcolor{red}{[} \texttt{,}\ \textcolor{red}{\dots} \texttt{,}\ \mathit{nombre_n}\ \textcolor{red}{[} \texttt{=}\ \mathit{valor_n} \textcolor{red}{]} \textcolor{red}{]} \texttt{\\}} \texttt{;}$$

Los valores deben ser expresiones constantes, incluyendo expresiones `constexpr`. Se puede indicar un tipo básico numérico, para definir cuál es el tamaño de los valores en memoria. Luego las palabras claves `class` y `struct` sirven para crear un tipo enumerado estricto, de ese modo una variable de ese tipo sólo puede recibir valores definidos en él, teniendo que usar la sintaxis `tipo::nombre`. Sin no se usa este mecanismo, basta con usar el nombre sin cualificar.

En ocasiones puede ser necesario declarar la existencia de un tipo enumerado sin incluir su definición, usando la siguiente sintaxis:

$$\texttt{enum}\ \mathit{nombre}\ \texttt{:}\ \mathit{tipo} \texttt{;}$$

$$\texttt{enum}\ \textcolor{red}{\\{} \texttt{class} \textcolor{red}{|} \texttt{struct} \textcolor{red}{\\}}\ \mathit{nombre}\ \textcolor{red}{[} \texttt{:}\ \mathit{tipo} \textcolor{red}{]} \texttt{;}$$

En caso de querer usar en un ámbito general, de tipo o de función, una enumeración estricta sin los nombres cualificados, se puede utilizar la siguiente sintaxis:

$$\texttt{using}\ \texttt{enum}\ \mathit{nombre} \texttt{;}$$

Esto incluye en el ámbito los nombres, para poder usarlos sin indicar el tipo. Por ejemplo:

```cpp
// Fichero: enums.cpp
#include<iostream>

enum Bar { A = 10, B, C };
enum class Foo : int { A, B, C };

int main () {
    Bar b = A;
    std::cout << b << "\n";
    {
        std::cout << A << "\n";
        std::cout << B << "\n";
        std::cout << C << "\n";
    }
    Foo f = Foo::A;
    std::cout << (int) f << "\n";
    {
        using enum Foo;
        std::cout << (int) A << "\n";
        std::cout << (int) B << "\n";
        std::cout << (int) C << "\n";
    }
}
```

## Elementos avanzados

### Alias de tipos

Existen dos formas de crear alias de tipos. Por un lado la heredada de C con [`typedef`](https://en.cppreference.com/w/cpp/language/typedef), que sigue la siguiente sintaxis:

$$\texttt{typedef}\ \mathit{tipo}\ \mathit{nombre} \texttt{;}$$

Y por el otro la incorporada en C++11 con [`using`](https://en.cppreference.com/w/cpp/language/type_alias), que sigue la siguiente sintaxis:

$$\texttt{using}\ \mathit{nombre}\ \texttt{=}\ \mathit{tipo} \texttt{;}$$

### Amigos de un tipo

La palabra clave [`friend`](https://en.cppreference.com/w/cpp/language/friend) permite indicar al compilador que una definición externa, a un tipo, puede acceder al contenido privado del mismo. Podemos declarar como amigos de un tipo a funciones y tipos.

```cpp
// Fichero: amigos.cpp
#include<iostream>

class Bar {
private:
    int dato = 0;
public:
    void mostrar() {
        std::cout << dato << "\n";
    }

    friend class Foo;
};

class Foo {
public:
    void cambiar (Bar & obj, int valor) {
        obj.dato = valor;
    }
};

int main () {
    Foo a;
    Bar b;
    b.mostrar(); // 0
    a.cambiar(b, 1);
    b.mostrar(); // 1
}
```

### Sobrecargar de operadores

Usando la palabra clave `operator` seguido de un operador, o un tipo, se puede usar funciones para [sobrecargar operadores](https://en.cppreference.com/w/cpp/language/operators) del lenguaje. Las formas aceptadas son:

| Forma | Firma Método | Firma Función | Operadores |
|:-----:|:------------:|:-------------:|:-----------|
| `@a` | `R A::operator @()` | `R operator @(A a)` | `+`, `-`, `~` |
| `@a` | `R & A::operator @()` | `R & operator @(A & a)` | `++`, `--` |
| `a@` | `R A::operator @(int)` | `R operator @(A & a, int)` | `++`, `--` |
| `a@b` | `R A::operator @(B b)` | `R operator @(A a, B b)` | `+`, `-`, `*`, `/`, `%`, `&`, `\|`, `^`, `<<`, `>>`, `,` |
| `a@b` | `bool A::operator @(const & B b)` | `bool operator @(const & A a, const & B b)` | `==`, `!=`, `<`, `>`, `<=`, `>=` |
| `a@b` | `auto A::operator @(const & B b)` | `auto operator @(const & A a, const & B b)` | `<=>` |
| `@a` | `bool A::operator @()` | `bool operator @(A a)` | `!` |
| `a@b` | `bool A::operator @(B b)` | `bool operator @(A a, B b)` | `&&`, `\|\|` |
| `a@b` | `R & A::operator @(B b)` | - | `=` |
| `a@b` | `R & A::operator @(B b)` | `R & operator @(A & a, B b)` | `+=`, `-=`, `*=`, `/=`, `%=`, `&=`, `\|=`, `^=`, `>>=`, `<<=` |
| `a(b, ..., z)` | `R A::operator ()(B b, ..., Z z)` | - | `()` |
| `a[b]` | `R & A::operator [](B b)` | - | `[]` |
| `a->b` | `R * A::operator ->()` | - | `->` |
| `a->*b` | `R & A::operator ->*(B b)` | `R & operator ->*(A a, B b)` | `->*` |
| `*a` | `R & A::operator *()` | `R & operator *(A a)` | `*` |
| `&a` | `R * A::operator &()` | `R * operator &(A a)` | `&` |
| `(T)a` | `T A::operator T()` | - | `(T)`, `static_cast<T>()` |
| `new T` | `void * A::operator new(size_t n)` | `void * operator new(size_t n)` | `new` |
| `new T[n]` | `void * A::operator new[](size_t m)` | `void * operator new[](size_t m)` | `new[]` |
| `delete a` | `void A::operator delete(void * a)` | `void operator delete(void * a)` | `delete` |
| `delete[] a` | `void A::operator delete[](void * a)` | `void operator delete[](void * a)` | `delete[]` |
| `co_await a` | `auto A::operator co_await()` | `auto operator co_await(A a)` | `co_await` |

Dependiendo de si es un método de una clase o una función suelta, se podrán utilizar unos modificadores u otros. En cuanto a los tipos de los parámetros y del resultado, hay cierta flexibilidad para usar referencias y punteros, incluso se puede alterar el comportamiento esperado para un operador, como ocurre con `<<` a la hora de canalizar flujos de salida de datos, en lugar de desplazar bits. Por ejemplo:

```cpp
// Fichero: sobrecarga.cpp
#include<iostream>

struct Foo {
    int X, Y;
};

std::ostream & operator <<(std::ostream & out, const Foo & obj) {
    out << "(" << obj.X << "," << obj.Y << ")";
    return out;
}

inline Foo operator +(const Foo & left, const Foo & right) {
    return Foo{
        .X = left.X + right.X,
        .Y = left.Y + right.Y
    };
}

int main () {
    Foo v{2, 3}, w{4, 5};
    std::cout << v << " + " << w << " = "
              << (v + w) << "\n";
}
```

### Sobrecargar de literales

Con C++11 se incorporó la posibilidad de definir [literales de usuario](https://en.cppreference.com/w/cpp/language/user_literal), permitiendo así reinterpretar los literales del lenguaje en base a un sufijo designado. Para ello hay que usar la sintaxis:

$$\mathit{tipo}\ \texttt{operator}\ \texttt{""}\ \mathit{sufijo} \texttt{(} \mathit{parametros} \texttt{)}\ \texttt{\\{}\ \mathit{expresi\acute{o}nes}\ \texttt{\\}}$$

En base a un *tipo* de retorno escogido, usaremos como sufijo una secuencia de letras que comience por guion bajo (`_`), ya que las secuencias que comienzan sin guion bajo se reservan para la biblioteca estándar. En cuanto a los *parámetros*, están permitidas las siguientes firmas: 
+ `(const char *)`
+ `(unsigned long long int)`
+ `(long double)`
+ `(char)`
+ `(wchar_t)`
+ `(char8_t)`
+ `(char16_t)`
+ `(char32_t)`
+ `(const char *, std::size_t)`
+ `(const wchar_t *, std::size_t)`
+ `(const char8_t *, std::size_t)`
+ `(const char16_t *, std::size_t)`
+ `(const char32_t *, std::size_t)`

Por ejemplo:

```cpp
// Fichero: literales.cpp
#include <string>
#include <iostream>

struct Foo {
    int X, Y;
};

std::ostream & operator <<(std::ostream & out, const Foo & obj) {
    out << "(" << obj.X << "," << obj.Y << ")";
    return out;
}

Foo operator ""_f(const char * v, size_t) {
    std::string texto{v};
    auto coma = texto.find(',');
    return Foo{
        .X = std::stoi(texto.substr(0, coma)),
        .Y = std::stoi(texto.substr(coma + 1))
    };
}

int main () {
    std::cout << "2,3"_f << "\n";
}
```

### Insertando funciones

La palabra clave [`inline`](https://en.cppreference.com/w/cpp/language/inline), permite indicar al compilador que debe intentar insertar el cuerpo de la misma en aquellos puntos donde es invocada. Es una recomendación para el compilador, que se usa como optimización en cuanto a la ejecución, pero como contrapartida aumenta el tamaño del programa compilado.

Esta palabra se usa como un modificador que va al inicio de la definición de una función, es decir, antes del tipo de retorno de la función. También se puede utilizar para funciones especiales como el constructor, el destructor o la sobrecarga de operadores. Por ejemplo:

```cpp
// Fichero: inline.cpp
#include<iostream>

inline void foo (int a, int b) {
    std::cout << a << " + " << b << " = " << a + b << "\n";
}

int main () {
    foo(2 , 3);
}
```

> Las funciones cuyo cuerpo es definido dentro de la declaración de un `class`, `struct` o `union`, son tratadas como funciones `inline` por defecto, así como las funciones con `delete`. También se asume implícitamente como `inline` aquellas funciones con `constexpr`.

### Ejecución al compilar

La palabra clave [`constexpr`](https://en.cppreference.com/w/cpp/language/constexpr) es un modificador para recomendar al compilador que ejecute la expresión siguiente en tiempo de compilación. Hay una serie de restricciones en el estándar para que efectivamente se pueda ejecutar la expresión con el compilador, pero en términos generales podemos usar literales o variables inicializadas con literales.

Se puede definir funciones como `constexpr`, pero tiene todavía más limitaciones que los otros tipos de expresiones. Por ejemplo, no puede ser una función virtual, ni una corrutina, entre muchas otras limitaciones. En caso de necesitar forzar al compilador a ejecutarlo, usaremos la palabra clave [`consteval`](https://en.cppreference.com/w/cpp/language/consteval), que hará fallar la compilación si no puede ejecutar. Hay que tener en cuenta que `consteval` puede llegar a ser más estricto que `constexpr`.

También, podemos ejecutar sentencias [condicionales](https://en.cppreference.com/w/cpp/language/if) con `if constexpr (condición)`, haciendo que se compile sólo uno de los dos bloques de la sentencia, dependiendo de si es cierta o falsa la condición. Con C++23 se incorpora `consteval` a las sentencias condicionales.

Por último, tenemos la función especial [`static_assert`](https://en.cppreference.com/w/cpp/language/static_assert), que puede recibir hasta dos argumentos, el primero una expresión booleana y el segundo una cadena de texto literal. El compilador ejecuta la expresión booleana, para asegurarse de que se cumple la condición indicada; en caso contrario falla la compilación y nos muestra el mensaje de la cadena.

## Preprocesador

El [preprocesado](https://en.cppreference.com/w/cpp/preprocessor) es la etapa inicial de la compilación, que realiza sustituciones de texto.

### Macros

La directiva más básica es definir [macros](https://en.cppreference.com/w/cpp/preprocessor/replace), que consiste en un identificador que se va a sustituir por un texto determinado. Para ello se usa la siguiente sintaxis:

$$\texttt{\\#define}\ \mathit{nombre}\ \textcolor{red}{[} \mathit{texto} \textcolor{red}{]}$$

El texto es opcional, porque podemos simplemente definir una macro para hacer comprobaciones condicionales, que se verán en la siguiente sección. Si queremos eliminar una macro usaremos la directiva:

$$\texttt{\\#undef}\ \mathit{nombre}$$

Aunque no es recomendable, se pueden definir macros con parámetros con la directiva:

$$\texttt{\\#define}\ \mathit{nombre} \texttt{(} \textcolor{red}{\\{} \mathit{par\acute{a}metros} \textcolor{red}{[} \texttt{,}\ \texttt{...} \textcolor{red}{]} \textcolor{red}{|} \texttt{...} \textcolor{red}{\\}} \texttt{)}\ \textcolor{red}{[} \mathit{texto} \textcolor{red}{]}$$

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

int main () {
    std::cout << inc(1) << "\n";
}
```

Pero con C++20 se incluye la posibilidad de definir [módulos](https://en.cppreference.com/w/cpp/language/modules), para facilitar la definición de unidades de compilación y su acceso. Para ello tenemos las expresiones `export` e `import`, la primera para exportar definiciones y la segunda para importar módulos o cabeceras.

Para crear un módulo primero hay que definirlo y a continuación definir qué se va a exportar con el módulo. La sintaxis para definirlo es la siguiente:

$$\texttt{export}\ \texttt{module}\ \mathit{identificador} \texttt{;}$$

El identificador es una serie de nombres separados por `:`, para construir un nombre cualificado para el módulo. La sintaxis para exportar definiciones en el módulo es la siguiente:

$$\texttt{export}\ \textcolor{red}{\\{}\ \mathit{definici\acute{o}n}\ \textcolor{red}{|}\ \texttt{\\{}\ \mathit{definiciones}\ \texttt{\\}}\ \textcolor{red}{\\}}$$

En caso de necesitar usar directivas del preprocesador, antes de declarar el módulo, hay que utilizar el módulo global con `module;`, para utilizar las directivas y después ya declarar el módulo. Otro aspecto de la definición de módulos es `module : private;`, que inicia la sección privada que no va a formar parte de la construcción del módulo por parte del compilador. Hay que entender que la parte pública del módulo sería una suerte de cabecera de la unidad de compilación, por lo que modificar cualquier cosa en ella, exportada o no, provoca que se recompilen todas las unidades de compilación que utilicen el módulo. Esto no ocurre con la parte privada del módulo.

Para importar módulos utilizamos la siguiente sintaxis:

$$\textcolor{red}{[} \texttt{export} \textcolor{red}{]}\ \texttt{import}\ \mathit{identificador} \texttt{;}$$

El identificador puede ser un nombre cualificado de módulo, así como una cabecera usando `<fichero>` o `"fichero"`. Si se utiliza la palabra clave `export`, al importar el módulo actual se importará también el módulo importado con `export import`.

Para entenderlo mejor, veamos el anterior ejemplo como un módulo:

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

int main () {
    std::cout << inc(1) << "\n";
}
```

## Plantillas

Las [plantillas](https://en.cppreference.com/w/cpp/language/templates) es la herramienta del lenguaje para poder hacer código genérico independiente de los tipos. La sintaxis básica para definir una plantilla es:

$$\texttt{template} \texttt{<} \mathit{par\acute{a}metros} \texttt{>}\ \textcolor{red}{[} \mathit{requisitos} \textcolor{red}{]}\ \mathit{definici\acute{o}n}$$

Como *definiciones* podemos tener tipos, funciones y variables. Los *requisitos* tienen que ver con los conceptos que veremos en una subsección más adelante. Los parámetros tenemos tres categorías: variables, variables de tipo y plantillas de variables de tipo.

La sintaxis para definir variables como parámetros de una plantilla es:

$$\textcolor{red}{\\{}\ \mathit{tipo}\ \textcolor{red}{[} \mathit{nombre}\ \textcolor{red}{[} \texttt{=}\ \mathit{valor} \textcolor{red}{]} \textcolor{red}{]}\ \textcolor{red}{|}\ \mathit{tipo}\ \texttt{...}\ \textcolor{red}{[} \mathit{nombre} \textcolor{red}{]}\ \textcolor{red}{|}\ \texttt{auto}\ \textcolor{red}{[} \mathit{modificadores} \textcolor{red}{]}\ \mathit{nombre}\ \textcolor{red}{\\}}$$

La primera forma es un tipo normal, con un nombre y un posible valor por defecto. La segunda forma es una variable que representa una lista de parámetros variable. La tercera forma usa `auto` y se puede combinar con `*` y `&`, como modificadores, para deducir en tiempo de compilación el tipo de la variable de la plantilla.

La sintaxis para definir variables de tipo como parámetros de una plantilla es:

$$\textcolor{red}{\\{} \texttt{typename} \textcolor{red}{|} \texttt{class} \textcolor{red}{|} \mathit{restricci\acute{o}n} \textcolor{red}{\\}}\ \textcolor{red}{[} \mathit{nombre}\ \textcolor{red}{[} \texttt{=}\ \mathit{tipo} \textcolor{red}{]} \textcolor{red}{|} \texttt{...}\ \textcolor{red}{[} \mathit{nombre} \textcolor{red}{]} \textcolor{red}{]}$$

Después de indicar si es una variable de tipo general, con `typename` o `class`, que son sinónimos, o si es una restricción definida con conceptos, podremos darle un nombre y un valor por defecto al parámetro. Pero también podemos convertir ese parámetro en una lista de parámetros variable.

La sintaxis para definir plantillas de variables de tipo como parámetros de una plantilla es:

$$\texttt{template} \texttt{<} \mathit{par\acute{a}metros} \texttt{>}\ \textcolor{red}{\\{} \texttt{typename} \textcolor{red}{|} \texttt{class} \textcolor{red}{\\}}\ \textcolor{red}{[} \mathit{nombre}\ \textcolor{red}{[} \texttt{=}\ \mathit{tipo} \textcolor{red}{]} \textcolor{red}{|} \texttt{...}\ \textcolor{red}{[} \mathit{nombre} \textcolor{red}{]} \textcolor{red}{]}$$

Es similar a las variables de tipo, con el añadido de estar parametrizado como una plantilla. Esto tiene su utilidad si queremos que uno de los parámetros sea una plantilla con una forma concreta, en lugar de cualquier tipo posible que representaría `typename`.

Veamos un simple ejemplo para entenderlo mejor:

```cpp
// Fichero: plantillas.cpp
#include<iostream>

template<typename T1, typename T2>
struct Tupla {
    T1 primero;
    T2 segundo;
};

template<typename T1, typename T2>
void mostrar (const Tupla<T1, T2> & valor) {
    std::cout << "{ " << valor.primero
              << ", " << valor.segundo
              << " }\n";
}

int main () {
    auto v1 = Tupla{1, true};
    auto v2 = Tupla{3.14, "PI"};
    mostrar(v1); // { 1, 1 }
    mostrar(v2); // { 3.14, PI }
}
```

En el ejemplo hemos usado el compilador para que [deduzca los tipos](https://en.cppreference.com/w/cpp/language/template_argument_deduction) que se están usando a la hora de instanciar las plantillas `Tupla` y `mostrar`, pero podríamos haber usado la forma explícita también:

```cpp
    auto v1 = Tupla<int, bool>{1, true};
    auto v2 = Tupla<double, const char *>{3.14, "PI"};
    mostrar<int, bool>(v1);
    mostrar<double, const char *>(v2);
```

Claramente ganamos legibilidad cuando el compilador deduce por nosotros los tipos de las instancias de las plantillas que usemos. Pero no siempre será posible, por lo que hay que tener en cuenta cómo se pueden instanciar de forma explícita.

También podemos forzar que se genere una instancia concreta de una plantilla, sobre todo cuando queremos crear una librería externa. En el caso de [tipos](https://en.cppreference.com/w/cpp/language/class_template) se usa la siguiente sintaxis:

$$\textcolor{red}{[} \texttt{extern} \textcolor{red}{]}\ \texttt{template}\ \textcolor{red}{\\{} \texttt{class} \textcolor{red}{|} \texttt{struct} \textcolor{red}{|} \texttt{union} \textcolor{red}{\\}}\ \mathit{nombre}\ \texttt{<} \mathit{argumentos} \texttt{>} \texttt{;}$$

Sin `extern` se define la instanciación y se genera el código, con `extern` se declara la instanciación pero se asume que su código ha sido generado en otra unidad de compilación. En el caso de las [funciones](https://en.cppreference.com/w/cpp/language/function_template) la sintaxis es:

$$\textcolor{red}{[} \texttt{extern} \textcolor{red}{]}\ \texttt{template}\ \mathit{tipo}\ \mathit{nombre}\ \texttt{<} \mathit{argumentos} \texttt{>}\ \texttt{(} \mathit{par\acute{a}metros} \texttt{)} \texttt{;}$$

Igual que pasa con los tipos podemos definir o declarar una instanciación. El resto es casi igual a declarar la firma de una función.

### Especialización

Podemos especializar una plantilla, es decir, crear un subtipo de la misma, indicando una parte o la totalidad de los tipos que conforman los parámetros de una. En estas plantillas especializadas podemos sobrecargar la definición previa de la plantilla, redefiniendo todo su contenido si fuera necesario. Este mecanismo permite la metaprogramación, al ejecutarse expresiones en tiempo de compilación.

Para especializar [parcial](https://en.cppreference.com/w/cpp/language/partial_specialization) o [totalmente](https://en.cppreference.com/w/cpp/language/template_specialization) una plantilla, hay que pasar los argumentos entre `<` y `>` a la derecha del nombre de la plantilla, por ejemplo:

```cpp
// Fichero: especializar.cpp
#include<iostream>

template<typename T>
void mostrar_valor (T valor) {
    std::cout << valor;
}

template<>
void mostrar_valor<bool> (bool valor) {
    std::cout << (valor ? "true" : "false");
}

template<>
void mostrar_valor<const char *> (const char * valor) {
    std::cout << '"' << valor << '"';
}

template<typename T1, typename T2>
struct Tupla {
    T1 primero;
    T2 segundo;

    void mostrar () {
        std::cout << "{ ";
        mostrar_valor(primero);
        std::cout << ", ";
        mostrar_valor(segundo);
        std::cout << " }\n";
    }
};

int main () {
    auto v1 = Tupla{1, true};
    auto v2 = Tupla{3.14, "PI"};
    v1.mostrar(); // { 1, true }
    v2.mostrar(); // { 3.14, "PI" }
}
```

En este ejemplo tenemos una función para mostrar valores, que hemos sobrecargado para booleanos y cadenas, especializando la plantilla `mostrar_valor`. Otro ejemplo sería calcular con metaprogramación la secuencia de Fibonacci:

```cpp
// Fichero: metafibonacci.cpp
#include <cstdint>
#include <iostream>

constexpr uint8_t MAX_VALUE = 46;

template<uint8_t n>
class MetaFibonacci {
private:
    template<uint8_t i, uint64_t v0, uint64_t v1>
    class fibonacci {
    public:
        enum {
            Result = fibonacci<i - 1, v1, v0 + v1>::Result
        };
    };
    template<uint64_t v0, uint64_t v1>
    class fibonacci<0, v0, v1> {
    public:
        enum {
            Result = v0
        };
    };
public:
    enum {
        Result = fibonacci<n, 0, 1>::Result
    };
};

template<unsigned char n>
inline void print_numbers() {
    print_numbers<n - 1>();
    std::cout << ", ";
    std::cout << MetaFibonacci<n>::Result;
}

template<>
inline void print_numbers<0>() {
    std::cout << MetaFibonacci<0>::Result;
}

int main () {
    std::cout << "Fibonacci: ";
    print_numbers<MAX_VALUE>();
    std::cout << "\n";
}
```

Aquí tenemos la plantilla `fibonacci`, dentro de `MetaFibonacci`, que tiene tres parámetros. A continuación tiene una especialización parcial, donde solo tiene dos parámetros y el primer argumento es el valor cero.

### Parámetros variables

Podemos tener plantillas con un número de parámetros variable utilizando la notación [`...`](https://en.cppreference.com/w/cpp/language/parameter_pack), que hemos visto en la sintaxis de los parámetros de las plantillas. La notación `tipo... nombre` define una lista variable de variables, mientras que `nombre...` expande esa lista de diferentes formas. Lo mismo se aplica a variables de tipo.

Si queremos saber cuál es el número de elementos de una lista variable, tenemos el operador [`sizeof...(nombre)`](https://en.cppreference.com/w/cpp/language/sizeof...), donde nombre es una variable de datos o de tipos. Por ejemplo:

```cpp
// Fichero: expansion.cpp
#include <iostream>

// Versión estándar de mostrar:
void mostrar () {}

template<typename T, typename... TS>
void mostrar (T value, TS... args) {
    std::cout << value;
    mostrar(args...);
}

// Versión alternativa de mostrar:
template<typename T, typename... TS>
void mostrarsi (T value, TS... args) {
    std::cout << value;
    if constexpr (sizeof...(TS) > 0) {
        mostrar(args...);
    }
}

int main () {
    mostrar(1, ", ", 2, ", ", 3, ", ", 4, "\n");
    mostrarsi(1.2, ", ", 3.4, "\n");
}
```

Podemos hacer una [reducción](https://en.cppreference.com/w/cpp/language/fold) aplicando alguno de los siguientes operadores binarios: `+`, `-`, `*`, `/`, `%`, `^`, `&`, `|`, `=`, `<`, `>`, `<<`, `>>`, `+=`, `-=`, `*=`, `/=`, `%=`, `^=`, `&=`, `|=`, `<<=`, `>>=`, `==`, `!=`, `<=`, `>=`, `&&`, `||`, `,`, `.*`, `->*`. Para ello es necesario utilizar alguna de las siguientes cuatro formas:

+ `(nombre @ ...)`
+ `(... @ nombre)`
+ `(nombre @ ... @ inicial)`
+ `(inicial @ ... @ nombre)`

Donde `@` es un operador binario de la lista anterior, `nombre` es el nombre de la variable de datos o de tipos, e `inicial` es una expresión que representa el valor inicial para la reducción. Por ejemplo:

```cpp
// Fichero: reducir.cpp
#include<iostream>

template<typename... TS>
auto sumar (TS... args) {
    return (0 + ... + args);
}

int main () {
    std::cout << sumar(1, 2, 3, 4) << "\n";
}
```

> La función [`std::forward`](https://en.cppreference.com/w/cpp/utility/forward) permite mover el contenido de una variable. Por ejemplo, si tenemos un parámetro definido como `T && ... args` y queremos que se mueva su contenido un constructor de forma eficiente, usaremos la forma `tipo(std::forward<T>(args)...)`. Se puede usar con otras funciones, para obligar a que se mueva el contenido de la variable usada como argumento, al parámetro de dicha función que mueve valores.

### Alias

Se puede crear un [alias](https://en.cppreference.com/w/cpp/language/type_alias) de una plantilla con la siguiente sintaxis:

$$\texttt{template} \texttt{<} \mathit{par\acute{a}metros} \texttt{>}\ \texttt{using}\ \mathit{nombre}\ \texttt{=}\ \mathit{declaraci\acute{o}n} \texttt{;}$$

Basta con indicar la declaración del tipo cuyo alias queremos crear, en lugar de la definición completa. Es decir, basta con la firma o cabecera del tipo.

### Lambdas

Se pueden tener plantillas de [lambdas](https://en.cppreference.com/w/cpp/language/lambda) con la siguiente sintaxis:

$$\texttt{[} \mathit{capturas} \texttt{]}\ \textcolor{red}{[} \texttt{<} \mathit{tipos} \texttt{>}\ \textcolor{red}{[} \mathit{requisitos} \textcolor{red}{]} \textcolor{red}{]}\ \texttt{(} \textcolor{red}{[} \mathit{par\acute{a}metros} \textcolor{red}{]} \texttt{)}\ \textcolor{red}{[} \mathit{modificadores} \textcolor{red}{]}\ \textcolor{red}{[} \texttt{->}\ \mathit{tipo} \textcolor{red}{]}\ \textcolor{red}{[} \mathit{requisitos} \textcolor{red}{]}\ \texttt{\\{}\ \mathit{expresiones}\ \texttt{\\}}$$

El prácticamente la misma sintaxis y elementos que las lambdas normales, pero aquí podemos poner variables de tipo entre `<` y `>`, así como indicar los requisitos que ha de cumplir la función mediante conceptos.

### Conceptos

Los [conceptos](https://en.cppreference.com/w/cpp/language/constraints) son una forma de poder definir requisitos para las plantillas, de modo que definimos un concepto como una restricción que se han de cumplir, para que se pueda instanciar correctamente la plantilla. La sintaxis para definir un concepto es la siguiente:

$$\texttt{template} \texttt{<} \mathit{par\acute{a}metros} \texttt{>}\ \texttt{concept}\ \mathit{nombre}\ \texttt{=}\ \mathit{restrici\acute{o}n} \texttt{;}$$

En este caso la *restricción* puede ser una composición de los siguientes elementos: otros conceptos (no puede ser una relación recursiva), conjunciones con `&&`, disyunciones con `||`, negaciones con `!` y expresiones `requires`. En el fondo estamos manejado predicados lógicos para formar una fórmula que de como resultado `true`.

La expresión [`requires`](https://en.cppreference.com/w/cpp/language/requires), dentro de la definición de una restricción, sigue la siguiente sintaxis:

$$\texttt{requires}\ \textcolor{red}{[} \texttt{(} \mathit{par\acute{a}metros} \texttt{)} \textcolor{red}{]}\ \texttt{\\{}\ \mathit{requisitos}\ \texttt{\\}}$$

Los *parámetros* tienen la forma `tipo nombre`, para usar dichos nombres dentro de los requisitos, para las comprobaciones realizadas en tiempo de compilación. Mientras que los *requisitos* los hay de cuatro categorías:

| Categoría | Descripción |
|:---------:|:------------|
| Simple | Expresiones del lenguaje que no empiezan por `requires`, que el compilador comprueba si es válida sin evaluarla. Por ejemplo: `template<typename T> concept C = requires (T a, T b) { a + b; }` |
| Tipos | Expresiones que comienzan por `typename`, para comprobar que existe el tipo indicado. Por ejemplo: `template<typename T> concept C = requires { typename T::Inner; }` |
| Compuestas | Que tienen la forma `{expresión} noexcept -> tipo`, donde `noexcept` es opcional, *expresión* es una expresión simple, y *tipo* es el tipo en el que ha de encajar la *expresión* (permite usar `decltype((expresión))`). |
| Anidadas | Son expresiones que empiezan con `requires`. |

Además de lo anterior, el uso de los conceptos definidos puede darse en dos casos. El primero es usar un concepto como una restricción para una variable de tipo definida en los parámetros, y el segundo es usarlo en los requisitos de la plantilla. Para usar la cláusula de requisitos se usa la siguiente sintaxis:

$$\texttt{requires}\ \mathit{restrici\acute{o}n}$$

Donde la restricción es una composición de conceptos, que ejercen como predicados, conjunciones con `&&`, disyunciones con `||` y negaciones con `!`. Por ejemplo:

```cpp
// Fichero: conceptos.cpp
#include <vector>
#include <iostream>

template<typename P, typename T>
concept Predicado = requires (P p, T x) {
    {p(x)} -> std::same_as<bool>;
};

template<typename T, typename P>
void mostrar (const T & datos, P predicado)
	requires Predicado<P, typename T::value_type> {
	for (auto item : datos) {
		if (predicado(item)) {
			std::cout << item << " ";
		}
	}
	std::cout << "\n";
}

int main () {
	std::vector datos = {1, 2, 3, 4, 5, 6, 7, 8};
	mostrar(datos, [](int x) { return x % 2 == 0; });
}
```

## Corrutinas

Las [corrutinas](https://en.cppreference.com/w/cpp/language/coroutines) son funciones que permiten la ejecución de código asíncrono, sin detener por completo la ejecución de la función que las invoca. Para trabajar con corrutinas es necesario incluir la librería [`coroutine`](https://en.cppreference.com/w/cpp/header/coroutine) y utilizar los siguientes operadores:

| Operador | Descripción |
|:--------:|:------------|
| `co_await` | Suspende la ejecución de la rutina hasta que vuelve a ser activada. |
| `co_yield` | Suspende la ejecución de la rutina para devolver un valor. |
| `co_return` | Completa la ejecución de la rutina devolviendo un valor. |

Para que el compilador permita el uso de corrutinas, es necesario crear un tipo auxiliar que defina en su interior otro tipo llamado `promise_type`, que tendrá una serie de operaciones definidas que dictarán el comportamiento de la corrutina definida:

| Método | Descripción |
|:------:|:------------|
| `get_return_object` | Este método es invocado cuando se tiene que instanciar una corrutina. |
| `initial_suspend` | Este método es invocado cuando se va pausar la corrutina con `co_await`. |
| `final_suspend` | Este método es invocado cuando se va pausar por última vez la corrutina en su finalización. |
| `unhandled_exception` | Este método es invocado cuando se produce una excepción en la corrutina. |
| `return_value` | Este método es invocado cuando se sale de la corrutina con `co_return` devolviendo un valor. |
| `return_void` | Este método es invocado cuando se sale de la corrutina con `co_return` sin devolver un valor. |
| `await_transform` | Este método es invocado cuando se obtiene el valor que está esperando `co_await` en la corrutina y se quiere transformar el objeto recibido de tipo *awaitable*. |
| `yield_value` | Este método es invocado cuando se devuelve un valor en la corrutina con `co_yield`. |

En el caso de `initial_suspend`, `final_suspend`, `await_transform` y `yield_value`, el tipo de retorno será una instancia de un tipo *awaitable*, como por ejemplo, [`std::suspend_always`](https://en.cppreference.com/w/cpp/coroutine/suspend_always) o [`std::suspend_never`](https://en.cppreference.com/w/cpp/coroutine/suspend_never). El primero indica que la ejecución en efecto se ha de poner en pausa, mientras que el segundo indica lo contrario. Ambos casos no generan un valor de retorno con el operador, sino que se ha de gestionar aparte dicha obtención del valor generado. Por ejemplo:

```cpp
// Fichero: corrutina.cpp
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
```

En este ejemplo calculamos el factorial con una corrutina. Por un lado está la clase `Tarea`, que contiene a `promise_type` y un tipo *awaitable* llamado `Esperador`, que es lo que necesita `co_await` para trabajar. Lo ideal es hacer una clase genérica para gestionar tareas de todo tipo, ya que la complejidad que subyace a las corrutinas es considerable.

Otro tipo de corrutinas son las que generan valores con `co_yield`, para crear una secuencia de valores que se van calculando de forma perezosa. Por ejemplo:

```cpp
// Fichero: generador.cpp
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
```

## Biblioteca estándar

### Cadenas

Para trabajar con cadenas tenemos, en el módulo [`string`](https://en.cppreference.com/w/cpp/header/string), la clase genérica [`std::basic_string`](https://en.cppreference.com/w/cpp/string/basic_string). Este tipo trabaja con cadenas mutables y tenemos las siguientes especializaciones:

| Tipo | Definición | Codificación |
|:----:|:----------:|:-------------|
| `std::string` | `std::basic_string<char>` | ASCI |
| `std::wstring` | `std::basic_string<wchar_t>` | Unicode |
| `std::u8string` | `std::basic_string<char8_t>` | UTF-8 |
| `std::u16string` | `std::basic_string<char16_t>` | UTF-16 |
| `std::u32string` | `std::basic_string<char32_t>` | UTF-32 |

En el módulo [`string_view`](https://en.cppreference.com/w/cpp/header/string_view), tenemos la clase genérica [`std::basic_string_view`](https://en.cppreference.com/w/cpp/string/basic_string_view), que nos permite tener una vista inmutable a una cadena o un fragmento de la misma. Para ello tenemos las siguientes especializaciones:

| Tipo | Definición | Codificación |
|:----:|:----------:|:-------------|
| `std::string_view` | `std::basic_string_view<char>` | ASCI |
| `std::wstring_view` | `std::basic_string_view<wchar_t>` | Unicode |
| `std::u8string_view` | `std::basic_string_view<char8_t>` | UTF-8 |
| `std::u16string_view` | `std::basic_string_view<char16_t>` | UTF-16 |
| `std::u32string_view` | `std::basic_string_view<char32_t>` | UTF-32 |

Los miembros principales que disponemos para trabajar con cadenas son:

| Categoría | Tipos | Miembro | Descripción |
|:---------:|:-----:|:-------:|:------------|
| General | `basic_string`<br/>`basic_string_view` | `operator=` | Operador de asignación. |
| General | `basic_string` | `assign` | Asigna caracteres a una cadena. |
| Iterador | `basic_string`<br/>`basic_string_view` | `begin`<br/>`cbegin` | Iterador que apunta al inicio del recorrido. |
| Iterador | `basic_string`<br/>`basic_string_view` | `end`<br/>`cend` | Iterador que apunta al final del recorrido. |
| Iterador | `basic_string`<br/>`basic_string_view` | `rbegin`<br/>`crbegin` | Iterador que apunta al inicio del recorrido inverso. |
| Iterador | `basic_string`<br/>`basic_string_view` | `rend`<br/>`crend` | Iterador que apunta al final del recorrido inverso. |
| Acceso | `basic_string`<br/>`basic_string_view` | `at` | Accede a un carácter cualquiera, con comprobación de límites. |
| Acceso | `basic_string`<br/>`basic_string_view` | `operator[]` | Accede a un carácter cualquiera. |
| Acceso | `basic_string`<br/>`basic_string_view` | `front` | Accede al primer carácter. |
| Acceso | `basic_string`<br/>`basic_string_view` | `back` | Accede al último carácter. |
| Acceso | `basic_string`<br/>`basic_string_view` | `data` | Accede al puntero al primer carácter. |
| Acceso | `basic_string` | `c_str` | Devuelve una versión inmutable de la cadena en estilo C. |
| Acceso | `basic_string` | `operator basic_string_view` | Devuelve una vista inmutable de la cadena. |
| Capacidad | `basic_string`<br/>`basic_string_view` | `empty` | Comprueba si la cadena está vacía. |
| Capacidad | `basic_string`<br/>`basic_string_view` | `size`<br/>`length` | Devuelve el número de caracteres. |
| Capacidad | `basic_string`<br/>`basic_string_view` | `max_size` | Devuelve el tamaño máximo para cualquier cadena. |
| Capacidad | `basic_string` | `capacity` | Devuelve el número máximo de caracteres actualmente reservado. |
| Capacidad | `basic_string` | `reserve` | Reserva espacio en la memoria. |
| Capacidad | `basic_string` | `shrink_to_fit` | Reduce el espacio reservado al tamaño actual de la cadena. |
| Operaciones | `basic_string` | `append` | Añade caracteres al final. |
| Operaciones | `basic_string` | `operator+=` | Añade caracteres al final. |
| Operaciones | `basic_string` | `clear` | Borra el contenido de la cadena. |
| Operaciones | `basic_string` | `insert` | Inserta caracteres. |
| Operaciones | `basic_string` | `erase` | Borra caracteres. |
| Operaciones | `basic_string` | `push_back` | Añade un carácter al final. |
| Operaciones | `basic_string` | `pop_back` | Elimina un carácter al final. |
| Operaciones | `basic_string`<br/>`basic_string_view` | `compare` | Compara dos cadenas. |
| Operaciones | `basic_string`<br/>`basic_string_view` | `starts_with` | Comprueba si la cadena empieza con un valor dado. |
| Operaciones | `basic_string`<br/>`basic_string_view` | `ends_with` | Comprueba si la cadena termina con un valor dado. |
| Operaciones | `basic_string`<br/>`basic_string_view` | `substr` | Devuelve un fragmento de la cadena. |
| Operaciones | `basic_string`<br/>`basic_string_view` | `copy` | Copia caracteres. |
| Operaciones | `basic_string` | `replace` | Sustituye una sección de la cadena. |
| Operaciones | `basic_string` | `resize` | Modifica el espacio reservado en la memoria para la cadena. |
| Operaciones | `basic_string` | `swap` | Intercambia el contenido de dos cadenas. |
| Búsqueda | `basic_string`<br/>`basic_string_view` | `find` | Busca la primera ocurrencia de un valor dado. |
| Búsqueda | `basic_string`<br/>`basic_string_view` | `rfind` | Busca la última ocurrencia de un valor dado. |
| Búsqueda | `basic_string`<br/>`basic_string_view` | `find_first_of` | Busca la primera ocurrencia de un carácter dado. |
| Búsqueda | `basic_string`<br/>`basic_string_view` | `find_first_not_of` | Busca la primera ocurrencia que no sea el carácter dado. |
| Búsqueda | `basic_string`<br/>`basic_string_view` | `find_last_of` | Busca la última ocurrencia de un carácter dado. |
| Búsqueda | `basic_string`<br/>`basic_string_view` | `find_last_not_of` | Busca la última ocurrencia que no sea el carácter dado. |
| Constantes | `basic_string`<br/> `basic_string_view` | `npos` | Valor especial para definir que no se ha encontrado un valor, entre otros usos. |

Además tenemos las siguientes funciones dentro del espacio de nombres `std`:

| Categoría | Tipos | Función | Descripción |
|:---------:|:-----:|:-------:|:------------|
| General | `basic_string` | `operator+` | Concatena dos cadenas. |
| General | `basic_string`<br/>`basic_string_view` | `operator==`<br/>`operator!=`<br/>`operator<`<br/>`operator>`<br/>`operator<=`<br/>`operator>=`<br/>`operator<=>` | Compara dos cadenas. |
| General | `basic_string` | `erase`<br/>`erase_if` | Elimina caracteres dentro de la cadena. |
| General | `basic_string` | `swap` | Intercambia el contenido de dos cadenas. |
| E/S | `basic_string` | `operator>>` | Entrada de cadenas por consola. |
| E/S | `basic_string`<br/>`basic_string_view` | `operator<<` | Salida de cadenas por consola. |
| E/S | `basic_string` | `getline` | Lee una línea de la consola para almacenarla en una cadena. |
| Conversiones | `basic_string` | `stoi`<br/>`stol`<br/>`stoll` | Convierte una cadena a un entero con signo. |
| Conversiones | `basic_string` | `stoul`<br/>`stoull` | Convierte una cadena a un entero sin signo. |
| Conversiones | `basic_string` | `stof`<br/>`stod`<br/>`stold` | Convierte una cadena a un número de coma flotante. |
| Conversiones | `basic_string` | `to_string`<br/>`to_wstring` | Convierte números a una cadena. |
| Literales | `basic_string` | `operator""s` | Convierte un literal a cadena. |
| Literales | `basic_string_view` | `operator""sv` | Convierte un literal a una vista. |
| Útiles | `basic_string`<br/>`basic_string_view` | `hash<T>` | Devuelve el código hash para un valor. |

Además de lo anterior tenemos una serie de [funciones](https://en.cppreference.com/w/cpp/string/byte) heredadas de la biblioteca estándar C, para comprobar y transformar, tanto caracteres como cadenas de estilo C.

Para manejar [expresiones regulares](https://en.cppreference.com/w/cpp/regex), en el módulo [`regex`](https://en.cppreference.com/w/cpp/header/regex), tenemos la clase genérica [`std::basic_regex`](https://en.cppreference.com/w/cpp/string/basic_regex), que tiene como especializaciones a `std::regex`, para cadenas ASCII, y a `std::wregex`, para cadenas Unicode.

### Contenedores

Estos son los contenedores principales de la biblioteca estándar:

| Tipo | Módulo | Descripción |
|:----:|:------:|:------------|
| [`std::array<T,N>`](https://en.cppreference.com/w/cpp/container/array) | [`array`](https://en.cppreference.com/w/cpp/header/array) | Array de tamaño fijo. |
| [`std::vector<T>`](https://en.cppreference.com/w/cpp/container/vector) | [`vector`](https://en.cppreference.com/w/cpp/header/vector) | Array de tamaño dinámico. |
| [`std::deque<T>`](https://en.cppreference.com/w/cpp/container/deque) | [`deque`](https://en.cppreference.com/w/cpp/header/deque) | Cola doblemente encabezada. |
| [`std::list<T>`](https://en.cppreference.com/w/cpp/container/list) | [`list`](https://en.cppreference.com/w/cpp/header/list) | Lista doblemente enlazada. |
| [`std::forward_list<T>`](https://en.cppreference.com/w/cpp/container/forward_list) | [`forward_list`](https://en.cppreference.com/w/cpp/header/forward_list) | Lista simplemente enlazada. |
| [`std::map<K,T>`](https://en.cppreference.com/w/cpp/container/map) | [`map`](https://en.cppreference.com/w/cpp/header/map) | Diccionario clave-valor, sin repetición de claves. |
| [`std::multimap<K,T>`](https://en.cppreference.com/w/cpp/container/multimap) | [`map`](https://en.cppreference.com/w/cpp/header/map) | Diccionario clave-valor, con repetición de claves. |
| [`std::unordered_map<K,T>`](https://en.cppreference.com/w/cpp/container/unordered_map) | [`unordered_map`](https://en.cppreference.com/w/cpp/header/unordered_map) | Diccionario clave-valor, sin repetición de claves y organizadas mediante valores hash. |
| [`std::unordered_multimap<K,T>`](https://en.cppreference.com/w/cpp/container/unordered_multimap) | [`unordered_map`](https://en.cppreference.com/w/cpp/header/unordered_map) | Diccionario clave-valor, con repetición de claves y organizadas mediante valores hash. |
| [`std::set<T>`](https://en.cppreference.com/w/cpp/container/set) | [`set`](https://en.cppreference.com/w/cpp/header/set) | Conjunto de valores sin repetición. |
| [`std::multiset<T>`](https://en.cppreference.com/w/cpp/container/multiset) | [`set`](https://en.cppreference.com/w/cpp/header/set) | Conjunto de valores con repetición. |
| [`std::unordered_set<T>`](https://en.cppreference.com/w/cpp/container/unordered_set) | [`unordered_set`](https://en.cppreference.com/w/cpp/header/unordered_set) | Conjunto de valores sin repetición y organizados mediante valores hash. |
| [`std::unordered_multiset<T>`](https://en.cppreference.com/w/cpp/container/unordered_multiset) | [`unordered_set`](https://en.cppreference.com/w/cpp/header/unordered_set) | Conjunto de valores con repetición y organizados mediante valores hash. |
| [`std::stack<T>`](https://en.cppreference.com/w/cpp/container/stack) | [`stack`](https://en.cppreference.com/w/cpp/header/stack) | Pila de elementos (LIFO). |
| [`std::queue<T>`](https://en.cppreference.com/w/cpp/container/queue) | [`queue`](https://en.cppreference.com/w/cpp/header/queue) | Cola de elementos (FIFO). |
| [`std::priority_queue<T>`](https://en.cppreference.com/w/cpp/container/priority_queue) | [`queue`](https://en.cppreference.com/w/cpp/header/queue) | Cola de elementos con prioridades. |
| [`std::span<T>`](https://en.cppreference.com/w/cpp/container/span) | [`span`](https://en.cppreference.com/w/cpp/header/span) | Vista mutable de un contenedor. |

Donde `T` es el tipo de los elementos del contenedor, `N` es un entero con el tamaño del contenedor y `K` es el tipo de las claves del contenedor. Entonces, los miembros principales que disponemos para trabajar con contenedores son:

| Categoría | Tipos | Miembro | Descripción |
|:---------:|:-----:|:-------:|:------------|
| General | `array`, `vector`, `deque`, `list`, `forward_list`, `map`, `multimap`, `unordered_map`, `unordered_multimap`, `set`, `multiset`, `unordered_set`, `unordered_multiset`, `stack`, `queue`, `priority_queue`, `span` | `operator=` | Operador de asignación. |
| General | `vector`, `deque`, `list`, `forward_list` | `assign` | Asigna elementos a un contenedor. |
| Iterador | `array`, `vector`, `deque`, `list`, `forward_list`, `map`, `multimap`, `unordered_map`, `unordered_multimap`, `set`, `multiset`, `unordered_set`, `unordered_multiset`, `span` | `begin`<br/>`cbegin` | Iterador que apunta al inicio del recorrido. |
| Iterador | `array`, `vector`, `deque`, `list`, `forward_list`, `map`, `multimap`, `unordered_map`, `unordered_multimap`, `set`, `multiset`, `unordered_set`, `unordered_multiset`, `span` | `end`<br/>`cend` | Iterador que apunta al final del recorrido. |
| Iterador | `array`, `vector`, `deque`, `list`, `map`, `multimap`, `set`, `multiset`, `span` | `rbegin`<br/>`crbegin` | Iterador que apunta al inicio del recorrido inverso. |
| Iterador | `array`, `vector`, `deque`, `list`, `map`, `multimap`, `set`, `multiset`, `span` | `rend`<br/>`crend` | Iterador que apunta al final del recorrido inverso. |
| Iterador | `forward_list` | `before_begin`<br/>`cbefore_begin` | Iterador que apunta al elemento anterior al inicio del recorrido. |
| Acceso | `array`, `vector`, `deque`, `map`, `unordered_map` | `at` | Accede a un elemento cualquiera, con comprobación de límites. |
| Acceso | `array`, `vector`, `deque`, `map`, `unordered_map`, `span` | `operator[]` | Accede a un elemento cualquiera. |
| Acceso | `array`, `vector`, `deque`, `list`, `forward_list`, `queue`, `span` | `front` | Accede al primer elemento. |
| Acceso | `array`, `vector`, `deque`, `list`, `queue`, `span` | `back` | Accede al último elemento. |
| Acceso  | `stack`, `priority_queue` | `top` | Accede al elemento en la cima. |
| Acceso | `array`, `vector`, `span` | `data` | Accede al puntero al primer elemento. |
| Capacidad | `array`, `vector`, `deque`, `list`, `forward_list`, `map`, `multimap`, `unordered_map`, `unordered_multimap`, `set`, `multiset`, `unordered_set`, `unordered_multiset`, `stack`, `queue`, `priority_queue`, `span` | `empty` | Comprueba si el contenedor está vacío. |
| Capacidad | `array`, `vector`, `deque`, `list`, `map`, `multimap`, `unordered_map`, `unordered_multimap`, `set`, `multiset`, `unordered_set`, `unordered_multiset`, `stack`, `queue`, `priority_queue`, `span` | `size` | Devuelve el número de elementos. |
| Capacidad | `array`, `vector`, `deque`, `list`, `forward_list`, `map`, `multimap`, `unordered_map`, `unordered_multimap`, `set`, `multiset`, `unordered_set`, `unordered_multiset` | `max_size` | Devuelve el tamaño máximo para cualquier contenedor. |
| Capacidad | `vector` | `capacity` | Devuelve el número máximo de elementos actualmente reservado. |
| Capacidad | `vector`, `unordered_map`, `unordered_multimap`, `unordered_set`, `unordered_multiset` | `reserve` | Reserva espacio en la memoria. |
| Capacidad | `vector`, `deque` | `shrink_to_fit` | Reduce el espacio reservado al tamaño actual del contenedor. |
| Capacidad | `span` | `size_bytes` | Devuelve el tamaño de la secuencia en bytes. |
| Operaciones | `vector`, `deque`, `list`, `forward_list`, `map`, `multimap`, `unordered_map`, `unordered_multimap`, `set`, `multiset`, `unordered_set`, `unordered_multiset` | `clear` | Borra el contenido del contenedor. |
| Operaciones | `vector`, `deque`, `list`, `map`, `multimap`, `unordered_map`, `unordered_multimap`, `set`, `multiset`, `unordered_set`, `unordered_multiset` | `insert` | Inserta elementos. |
| Operaciones | `vector`, `deque`, `list`, `map`, `multimap`, `unordered_map`, `unordered_multimap`, `set`, `multiset`, `unordered_set`, `unordered_multiset` | `erase` | Borra elementos. |
| Operaciones | `stack`, `queue`, `priority_queue` | `push` | Añade un elemento al contenedor. |
| Operaciones | `stack`, `queue`, `priority_queue` | `pop` |  Elimina un elemento del contenedor. |
| Operaciones | `vector`, `deque`, `list` | `push_back` | Añade un elemento al final. |
| Operaciones | `vector`, `deque`, `list` | `pop_back` | Elimina un elemento al final. |
| Operaciones | `deque`, `list`, `forward_list` | `push_front` | Añade un elemento al inicio. |
| Operaciones | `deque`, `list`, `forward_list` | `pop_front` | Elimina un elemento al inicio. |
| Operaciones | `vector`, `deque`, `list`, `map`, `multimap`, `unordered_map`, `unordered_multimap`, `set`, `multiset`, `unordered_set`, `unordered_multiset`, `stack`, `queue`, `priority_queue` | `emplace` | Añade elementos en una posición dada. |
| Operaciones | `vector`, `deque`, `list` | `emplace_back` | Añade elementos al final del contenedor. |
| Operaciones | `deque`, `list`, `forward_list` | `emplace_front` | Añade elementos al inicio del contenedor. |
| Operaciones | `forward_list` | `insert_after` | Inserta elementos después de una posición dada. |
| Operaciones | `forward_list` | `erase_after` | Borra elementos después de una posición dada. |
| Operaciones | `forward_list` | `emplace_after` | Añade elementos después de una posición dada. |
| Operaciones | `map`, `unordered_map` | `insert_or_assign` | Inserta un elemento o actualiza el valor si la clave ya existe. |
| Operaciones | `map`, `multimap`, `unordered_map`, `unordered_multimap`, `set`, `multiset`, `unordered_set`, `unordered_multiset` | `emplace_hint` | Añade elementos en una posición dada. |
| Operaciones | `map`, `unordered_map` | `try_emplace` | Añade elementos en una posición dada si la clave no existe. |
| Operaciones | `array` | `fill` | Rellena el contenedor con un valor dado. |
| Operaciones | `vector`, `deque`, `list`, `forward_list` | `resize` | Modifica el espacio reservado en la memoria para el contenedor. |
| Operaciones | `array`, `vector`, `deque`, `list`, `forward_list`, `map`, `multimap`, `unordered_map`, `unordered_multimap`, `set`, `multiset`, `unordered_set`, `unordered_multiset`, `stack`, `queue`, `priority_queue` | `swap` | Intercambia el contenido de dos contenedores. |
| Operaciones | `list`, `forward_list`, `map`, `multimap`, `unordered_map`, `unordered_multimap`, `set`, `multiset`, `unordered_set`, `unordered_multiset` | `merge` | Fusiona dos contenedores ordenados previamente. |
| Operaciones | `list` | `splice` | Mueve elementos desde otro contenedor. |
| Operaciones | `forward_list` | `splice_after` | Mueve elementos desde otro contenedor. |
| Operaciones | `list`, `forward_list` | `remove`<br/>`remove_if` | Elimina elementos dentro del contenedor. |
| Operaciones | `list`, `forward_list` | `reverse` | Invierte el orden de los elementos del contendor. |
| Operaciones | `list`, `forward_list` | `unique` | Elimina duplicados consecutivos del contenedor. |
| Operaciones | `list`, `forward_list` | `sort` | Ordena los elementos del contenedor. |
| Operaciones | `map`, `multimap`, `unordered_map`, `unordered_multimap`, `set`, `multiset`, `unordered_set`, `unordered_multiset` | `extract` | Extrae elementos de otro contenedor. |
| Búsqueda | `map`, `multimap`, `unordered_map`, `unordered_multimap`, `set`, `multiset`, `unordered_set`, `unordered_multiset` | `count` | Cuenta el número de apariciones de un elemento dentro del contenedor. |
| Búsqueda | `map`, `multimap`, `unordered_map`, `unordered_multimap`, `set`, `multiset`, `unordered_set`, `unordered_multiset` | `find` | Busca un elemento dentro del contenedor. |
| Búsqueda | `map`, `multimap`, `unordered_map`, `unordered_multimap`, `set`, `multiset`, `unordered_set`, `unordered_multiset` | `contains` | Comprueba si existe un elemento dentro del contenedor. |
| Búsqueda | `map`, `multimap`, `unordered_map`, `unordered_multimap`, `set`, `multiset`, `unordered_set`, `unordered_multiset` | `equal_range` | Devuelve un rango de elementos que encaje con una clave. |
| Búsqueda | `map`, `multimap`, `set`, `multiset` | `lower_bound` | Devuelve un iterador al primer elemento mayor o igual que una clave. |
| Búsqueda | `map`, `multimap`, `set`, `multiset` | `upper_bound` | Devuelve un iterador al primer elemento mayor que una clave. |
| Selección | `span` | `first` | Obtiene una selección de los primeros N elementos. |
| Selección | `span` | `last` | Obtiene una selección de los últimos N elementos. |
| Selección | `span` | `subspan` | Obtiene una selección de N elementos. |

> El tipo `span` no dispone de los métodos `cbegin`, `cend`, `crbegin` y `crend`, para crear iteradores constantes.

Además tenemos las siguientes funciones dentro del espacio de nombres `std`:

| Categoría | Tipos | Función | Descripción |
|:---------:|:-----:|:-------:|:------------|
| General | `array`, `vector`, `deque`, `list`, `forward_list`, `map`, `multimap`, `unordered_map`, `unordered_multimap`, `set`, `multiset`, `unordered_set`, `unordered_multiset`, `stack`, `queue` | `operator==`<br/>`operator!=` | Compara dos contenedores. |
| General | `array`, `vector`, `deque`, `list`, `forward_list`, `map`, `multimap`, `set`, `multiset`, `stack`, `queue` | `operator<`<br/>`operator>`<br/>`operator<=`<br/>`operator>=`<br/>`operator<=>` | Compara dos contenedores. |
| General | `vector`, `deque`, `list`, `forward_list`, `multiset` | `erase` | Elimina elementos dentro del contenedor. |
| General | `vector`, `deque`, `list`, `forward_list`, `map`, `multimap`, `unordered_map`, `unordered_multimap`, `set`, `multiset`, `unordered_set`, `unordered_multiset` | `erase_if` | Elimina elementos dentro del contenedor. |
| General | `array`, `vector`, `deque`, `list`, `forward_list`, `map`, `multimap`, `unordered_map`, `unordered_multimap`, `set`, `multiset`, `unordered_set`, `unordered_multiset`, `stack`, `queue`, `priority_queue` | `swap` | Intercambia el contenido de dos contenedores. |
| General | `array` | `get<N>` | Accede a un elemento de un contenedor de tamaño fijo. |
| Útiles | `array` | `tuple_element<T>` | Devuelve el tipo de los elementos del contenedor. |
| Útiles | `array` | `tuple_size<T>` | Devuelve el tamaño del contenedor. |

### Iteradores y rangos

Estos son algunos de los tipos y funciones de la biblioteca estándar, en el módulo [`iterator`](https://en.cppreference.com/w/cpp/header/iterator), para manejar [iteradores](https://en.cppreference.com/w/cpp/iterator):

| Tipo | Elemento | Descripción |
|:----:|:--------:|:------------|
| Función | `std::ranges::iter_move` | Mueve el contenido de un iterador a otro. |
| Función | `std::ranges::iter_swap` | Intercambia el contenido entre dos iteradores. |
| Clase | `std::reverse_iterator<T>` | Recorre una secuencia en orden inverso. |
| Función | `std::make_reverse_iterator<T>` | Crea un `reverse_iterator` infiriendo el tipo con el argumento. |
| Clase | `std::move_iterator<T>` | Recorre una secuencia moviendo su contenido. |
| Función | `std::make_move_iterator<T>` | Crea un `move_iterator` infiriendo el tipo con el argumento. |
| Clase | `std::back_insert_iterator<T>` | Iterador para insertar al final de un contenedor. |
| Función | `std::back_inserter<T>` | Crea un `back_insert_iterator` infiriendo el tipo con el argumento. |
| Clase | `std::front_insert_iterator<T>` | Iterador para insertar al inicio de un contenedor. |
| Función | `std::front_inserter<T>` | Crea un `front_insert_iterator` infiriendo el tipo con el argumento. |
| Clase | `std::insert_iterator<T>` | Iterador para insertar en un contenedor. |
| Función | `std::inserter<T>` | Crea un `insert_iterator` infiriendo el tipo con el argumento. |
| Función | `std::advance<T,U>` | Avanza un iterador N posiciones. |
| Función | `std::distance<T>` | Devuelve la distancia entre el inicio y el final del recorrido. |
| Función | `std::next<T>` | Avanza un iterador una posición. |
| Función | `std::prev<T>` | Retrocede un iterador una posición. |
| Función | `std::begin<T>`<br/>`std::cbegin<T>` | Iterador que apunta al inicio del recorrido. |
| Función | `std::end<T>`<br/>`std::cend<T>` | Iterador que apunta al final del recorrido. |
| Función | `std::rbegin<T>`<br/>`std::crbegin<T>` | Iterador que apunta al inicio del recorrido inverso. |
| Función | `std::rend<T>`<br/>`std::crend<T>` | Iterador que apunta al final del recorrido inverso. |
| Función | `std::size<T>`<br/>`std::ssize<T>` | Devuelve el número de elementos de la secuencia. |
| Función | `std::empty<T>` | Comprueba si la secuencia está vacía. |
| Función | `std::data<T>` | Accede al puntero al primer elemento de la secuencia. |

Con C++20 se incorporó el concepto de los [rangos](https://en.cppreference.com/w/cpp/ranges), como un mecanismo más genérico para definir secuencias iterables. Para ello tenemos los espacios de nombres `std::ranges` y `std::views`. Estos son algunos de los tipos y funciones de la biblioteca estándar, en el módulo [`iterator`](https://en.cppreference.com/w/cpp/header/iterator) y [`ranges`](https://en.cppreference.com/w/cpp/header/ranges), para manejar rangos:

| Categoría | Elemento | Descripción |
|:---------:|:--------:|:------------|
| Operaciones | `std::ranges::advance` | Avanza un iterador N posiciones. |
| Operaciones | `std::ranges::distance` | Devuelve la distancia entre el inicio y el final del recorrido. |
| Operaciones | `std::ranges::next` | Avanza un iterador una posición. |
| Operaciones | `std::ranges::prev` | Retrocede un iterador una posición. |
| Acceso | `std::ranges::begin`<br/>`std::ranges::cbegin` | Iterador que apunta al inicio del recorrido. |
| Acceso | `std::ranges::end`<br/>`std::ranges::cend` | Iterador que apunta al final del recorrido. |
| Acceso | `std::ranges::rbegin`<br/>`std::ranges::crbegin` | Iterador que apunta al inicio del recorrido inverso. |
| Acceso | `std::ranges::rend`<br/>`std::ranges::crend` | Iterador que apunta al final del recorrido inverso. |
| Acceso | `std::ranges::size`<br/>`std::ranges::ssize` | Devuelve el número de elementos de la secuencia. |
| Acceso | `std::ranges::empty` | Comprueba si la secuencia está vacía. |
| Acceso | `std::ranges::data`<br/>`std::ranges::cdata` | Accede al puntero al primer elemento de la secuencia. |
| Vistas | `std::ranges::view_interface` | Clase que representa una vista a una secuencia. |
| Vistas | `std::ranges::subrange` | Clase que representa una vista a una secuencia, mediante un rango compuesto por un par iterador-limite. |
| Factoría | `std::ranges::empty_view`<br/>`std::views::empty` | Una vista sin elementos. |
| Factoría | `std::ranges::single_view`<br/>`std::views::single` | Una vista con un solo elemento. |
| Factoría | `std::ranges::iota_view`<br/>`std::views::iota` | Una vista compuesta por un valor inicial que se va incrementando con cada paso. |
| Factoría | `std::ranges::basic_istream_view`<br/>`std::views::istream` | Una vista que está asociada a un flujo de entrada al que aplica el operador `>>` a cada paso. |
| Adaptador | `std::views::all_t`<br/>`std::views::all` | Una vista que incluye todos los elementos de un rango. |
| Adaptador | `std::ranges::ref_view` | Una vista de los elementos de otro rango. |
| Adaptador | `std::ranges::owning_view` | Una vista con la propiedad única de los elementos de un rango. |
| Adaptador | `std::ranges::filter_view`<br/>`std::views::filter` | Una vista con los elementos de una secuencia que satisfacen un predicado. |
| Adaptador | `std::ranges::transform_view`<br/>`std::views::transform` | Una vista que aplica una función de transformación a los elementos de una secuencia. |
| Adaptador | `std::ranges::take_view`<br/>`std::views::take` | Una vista que toma los N primeros elementos de otra secuencia. |
| Adaptador | `std::ranges::take_while_view`<br/>`std::views::take_while` | Una vista que toma los N primeros elementos de otra secuencia mientras se cumpla un predicado. |
| Adaptador | `std::ranges::drop_view`<br/>`std::views::drop` | Una vista que descarta los N primeros elementos de otra secuencia. |
| Adaptador | `std::ranges::drop_while_view`<br/>`std::views::drop_while` | Una vista que descarta los N primeros elementos de otra secuencia mientras se cumpla un predicado. |
| Adaptador | `std::ranges::join_view`<br/>`std::views::join` | Una vista que aplana una vista de secuencias. |
| Adaptador | `std::ranges::split_view`<br/>`std::views::split` | Una vista obtenida de dividir otra vista usando un delimitador. |
| Adaptador | `std::ranges::lazy_split_view`<br/>`std::views::lazy_split` | Una vista obtenida de dividir otra vista usando un delimitador. |
| Adaptador | `std::views::counted` | Crea un rango con un iterador y un tamaño. |
| Adaptador | `std::ranges::common_view`<br/>`std::views::common` | Convierte una vista en un objeto de tipo `common_range`. |
| Adaptador | `std::ranges::reverse_view`<br/>`std::views::reverse` | Una vista que recorre otra secuencia en sentido inverso. |
| Adaptador | `std::ranges::elements_view`<br/>`std::views::elements` | Una vista que selecciona un campo determinado de las tuplas de una secuencia. |
| Adaptador | `std::ranges::keys_view`<br/>`std::views::keys` | Una vista que selecciona el primer campo de una tupla clave-valor. |
| Adaptador | `std::ranges::values_view`<br/>`std::views::values` | Una vista que selecciona el segundo campo de una tupla clave-valor. |

> Los adaptadores se pueden combinar utilizando el operador `|`. Por ejemplo, si `v` es una secuencia de números, `v | std::views::take(3) | std::views::reverse` devolverá una vista que recorrerá al revés los primeros tres elementos de la secuencia.

### Algoritmos

La biblioteca estándar dispone de una serie de [algoritmos](https://en.cppreference.com/w/cpp/algorithm) genéricos, en el módulo [`algorithm`](https://en.cppreference.com/w/cpp/header/algorithm), para trabajar con contenedores, iteradores y rangos. El primera tabla son funciones que no modifican la secuencia:

| Función | Función (Rangos) | Descripción |
|:-------:|:----------------:|:------------|
| `std::all_of` | `std::ranges::all_of` | Comprueba si se cumple un predicado para todos los elementos de una secuencia. |
| `std::any_of` | `std::ranges::any_of` | Comprueba si se cumple un predicado para algún elemento de una secuencia. |
| `std::none_of` | `std::ranges::none_of` | Comprueba si se cumple un predicado para ningún elemento de una secuencia. |
| `std::for_each` | `std::ranges::for_each` | Aplica una función a cada elemento de una secuencia. |
| `std::for_each_n` | `std::ranges::for_each_n` | Aplica una función a los N primeros elementos de una secuencia. |
| `std::count`<br/>`std::count_if` | `std::ranges::count`<br/>`std::ranges::count_if` | Obtiene el número de elementos de una secuencia que cumple un criterio específico. |
| `std::mismatch` | `std::ranges::mismatch` | Encuentra la primera posición donde dos secuencias difieren. |
| `std::find`<br/>`std::find_if`<br/>`std::find_if_not` | `std::ranges::find`<br/>`std::ranges::find_if`<br/>`std::ranges::find_if_not` | Busca el primer elemento de una secuencia que cumpla un criterio específico. |
| `std::find_end` | `std::ranges::find_end` | Busca en una secuencia de elementos la última posición de una determinada secuencia dada. |
| `std::find_first_of` | `std::ranges::find_first_of` | Busca un elemento cualquier dentro de un conjunto dado. |
| `std::adjacent_find` | `std::ranges::adjacent_find` | Busca los dos primeros elementos adyacentes que son iguales o que cumplen un predicado dado. |
| `std::search` | `std::ranges::search` | Busca una secuencia de elementos. |
| `std::search_n` | `std::ranges::search_n` | Busca un número consecutivo de copias de un elemento en una secuencia. |

La segunda tabla son funciones que modifican la secuencia:

| Función | Función (Rangos) | Descripción |
|:-------:|:----------------:|:------------|
| `std::copy`<br/>`std::copy_if` | `std::ranges::copy`<br/>`std::ranges::copy_if` | Copia una secuencia de elementos a una nueva localización. |
| `std::copy_n` | `std::ranges::copy_n` | Copia un número de elementos a una nueva localización. |
| `std::copy_backward` | `std::ranges::copy_backward` | Copia una secuencia de elementos en sentido inverso a una nueva localización. |
| `std::move` | `std::ranges::move` | Mueve una secuencia de elementos a una nueva localización. |
| `std::move_backward` | `std::ranges::move_backward` | Mueve una secuencia de elementos en sentido inverso a una nueva localización. |
| `std::fill` | `std::ranges::fill` | Copia y asigna un valor a los elementos de una secuencia. |
| `std::fill_n` | `std::ranges::fill_n` | Copia y asigna un valor a un número de elementos en una secuencia. |
| `std::transform` | `std::ranges::transform` | Aplica una función a una secuencia de elementos y almacena el resultado en una nueva localización. |
| `std::generate` | `std::ranges::generate` | Asigna el resultado de llamar sucesivas veces a una función a los elementos de una secuencia. |
| `std::generate_n` | `std::ranges::generate_n` | Asigna el resultado de llamar sucesivas veces a una función a un número de elementos en una secuencia. |
| `std::remove`<br/>`std::remove_if` | `std::ranges::remove`<br/>`std::ranges::remove_if` | Elimina elementos de una secuencia que cumplan un criterio específico. |
| `std::remove_copy`<br/>`std::remove_copy_if` | `std::ranges::remove_copy`<br/>`std::ranges::remove_copy_if` | Copia los elementos de una secuencia, omitiendo aquellos que cumplan un criterio específico. |
| `std::replace`<br/>`std::replace_if` | `std::ranges::replace`<br/>`std::ranges::replace_if` | Sustituye con un valor dado aquellos elementos de una secuencia que cumplan un criterio específico. |
| `std::replace_copy`<br/>`std::replace_copy_if` | `std::ranges::replace_copy`<br/>`std::ranges::replace_copy_if` | Copia los elementos de una secuencia, sustituyendo con un valor dado aquellos que cumplan un criterio específico. |
| `std::swap` | - | Intercambia los valores de dos objetos. |
| `std::swap_ranges` | `std::ranges::swap_ranges` | Intercambia los valores de dos secuencias. |
| `std::iter_swap` | - | Intercambia los valores apuntados por dos iteradores. |
| `std::reverse` | `std::ranges::reverse` | Invierte el orden de una secuencia de elementos. |
| `std::reverse_copy` | `std::ranges::reverse_copy` | Crea una copia con el orden invertido de una secuencia de elementos. |
| `std::rotate` | `std::ranges::rotate` | Rota el orden de una secuencia de elementos. |
| `std::rotate_copy` | `std::ranges::rotate_copy` | Crea una copia con el orden de los elementos de una secuencia rotados. |
| `std::shift_left`<br/>`std::shift_right` | - | Rota el valor de los elementos de una secuencia. |
| `std::shuffle` | `std::ranges::shuffle` | Reordena aleatoriamente los elementos de una secuencia. |
| `std::sample` | `std::ranges::sample` | Selecciona N elementos aleatoriamente de una secuencia. |
| `std::unique` | `std::ranges::unique` | Elimina los duplicados consecutivos en una secuencia de elementos. |
| `std::unique_copy` | `std::ranges::unique_copy` | Crea una copia de una secuencia de elementos donde se elimina los duplicados consecutivos. |

La tercera tabla son funciones que particionan una secuencia:

| Función | Función (Rangos) | Descripción |
|:-------:|:----------------:|:------------|
| `std::is_partitioned` | `std::ranges::is_partitioned` | Comprueba si una secuencia está particionada en base a un predicado dado. |
| `std::partition` | `std::ranges::partition` | Divide una secuencia en dos grupos de elementos. |
| `std::partition_copy` | `std::ranges::partition_copy` | Copia la división de una secuencia en dos grupos de elementos. |
| `std::stable_partition` | `std::ranges::stable_partition` | Divide una secuencia en dos grupos de elementos, manteniendo el orden relativo de los mismos entre sí. |
| `std::partition_point` | `std::ranges::partition_point` | Localiza el punto de partición en una secuencia particionada. |

La cuarta tabla son funciones que ordenan una secuencia:

| Función | Función (Rangos) | Descripción |
|:-------:|:----------------:|:------------|
| `std::is_sorted` | `std::ranges::is_sorted` | Comprueba si una secuencia está ordenada en sentido ascendente. |
| `std::is_sorted_until` | `std::ranges::is_sorted_until` | Busca la mayor subsecuencia ordenada en una secuencia de elementos. |
| `std::sort` | `std::ranges::sort` | Ordena en sentido ascendente una secuencia de elementos. |
| `std::partial_sort` | `std::ranges::partial_sort` | Ordena los N primeros elementos de una secuencia. |
| `std::partial_sort_copy` | `std::ranges::partial_sort_copy` | Copia la ordenación de los N primeros elementos de una secuencia. |
| `std::stable_sort` | `std::ranges::stable_sort` | Ordena una secuencia de elementos, manteniendo el orden previo entre valores iguales. |
| `std::nth_element` | `std::ranges::nth_element` | Ordena de forma parcial una secuencia, asegurando que está particionada por un elemento dado. |

La quinta tabla son funciones que trabajan con una secuencia ordenada:

| Categoría | Función | Función (Rangos) | Descripción |
|:---------:|:-------:|:----------------:|:------------|
| Búsqueda | `std::lower_bound` | `std::ranges::lower_bound` | Devuelve un iterador al primer elemento no menor que un valor dado. |
| Búsqueda | `std::upper_bound` | `std::ranges::upper_bound` | Devuelve un iterador al primer elemento mayor que un valor dado. |
| Búsqueda | `std::binary_search` | `std::ranges::binary_search` | Comprueba si un elemento existe en una secuencia parcialmente ordenada. |
| Búsqueda | `std::equal_range` | `std::ranges::equal_range` | Devuelve una secuencia de elementos que encaja con una clave específica. |
| Mezcla | `std::merge` | `std::ranges::merge` | Fusiona dos secuencias de elementos ordenados. |
| Mezcla | `std::inplace_merge` | `std::ranges::inplace_merge` | Fusiona dos secuencias de elementos ordenados dentro de una misma secuencia. |
| Conjunto | `std::includes` | `std::ranges::includes` | Comprueba si una secuencia es subconjunto de otra. |
| Conjunto | `std::set_difference` | `std::ranges::set_difference` | Calcula la diferencia entre dos conjuntos. |
| Conjunto | `std::set_intersection` | `std::ranges::set_intersection` | Calcula la intersección entre dos conjuntos. |
| Conjunto | `std::set_symmetric_difference` | `std::ranges::set_symmetric_difference` | Calcula la diferencia simétrica entre dos conjuntos. |
| Conjunto | `std::set_union` | `std::ranges::set_union` | Calcula la unión entre dos conjuntos. |

La sexta tabla son funciones que trabajan con un montículo:

| Función | Función (Rangos) | Descripción |
|:-------:|:----------------:|:------------|
| `std::is_heap` | `std::ranges::is_heap` | Comprueba si una secuencia es un montículo de máximos. |
| `std::is_heap_until` | `std::ranges::is_heap_until` | Busca la mayor subsecuencia ordenada como un montículo en una secuencia de elementos. |
| `std::make_heap` | `std::ranges::make_heap` | Crea un montículo de máximos con una secuencia de elementos. |
| `std::push_heap` | `std::ranges::push_heap` | Añade un elemento a un montículo de máximos. |
| `std::pop_heap` | `std::ranges::pop_heap` | Saca un elemento de un montículo de máximos. |
| `std::sort_heap` | `std::ranges::sort_heap` | Ordena un montículo de máximos como una secuencia de elementos en sentido ascendente. |

La séptima tabla son funciones para encontrar el mínimo o el máximo en una secuencia:

| Función | Función (Rangos) | Descripción |
|:-------:|:----------------:|:------------|
| `std::max` | `std::ranges::max` | Obtiene mayor elemento entre los valores dados. |
| `std::max_element` | `std::ranges::max_element` | Obtiene el elemento máximo de una secuencia. |
| `std::min` | `std::ranges::min` | Obtiene menor elemento entre los valores dados. |
| `std::min_element` | `std::ranges::min_element` | Obtiene el elemento mínimo de una secuencia. |
| `std::minmax` | `std::ranges::minmax` | Obtiene el mayor y el menor elemento entre los valores dados. |
| `std::minmax_element` | `std::ranges::minmax_element` | Obtiene el elemento máximo y mínimo de una secuencia. |
| `std::clamp` | `std::ranges::clamp` | Restringe un valor entre un par de valores límites dados. |

La octava tabla son funciones que comparan secuencias:

| Función | Función (Rangos) | Descripción |
|:-------:|:----------------:|:------------|
| `std::equal` | `std::ranges::equal` | Comprueba si una secuencia es igual a otra. |
| `std::lexicographical_compare` | `std::ranges::lexicographical_compare` | Comprueba si una secuencia es menor lexicográficamente que otra. |
| `std::lexicographical_compare_three_way` | - | Comprueba una secuencia con otra con el operador de comparación `<=>`. |

La novena tabla son funciones que permutan una secuencia:

| Función | Función (Rangos) | Descripción |
|:-------:|:----------------:|:------------|
| `std::is_permutation` | `std::ranges::is_permutation` | Comprueba si una secuencia es una permutación de otra. |
| `std::next_permutation` | `std::ranges::next_permutation` | Obtiene la siguiente permutación lexicográfica de una secuencia de elementos. |
| `std::prev_permutation` | `std::ranges::prev_permutation` | Obtiene la anterior permutación lexicográfica de una secuencia de elementos. |

La décima tabla son funciones numéricas sobre una secuencia, del módulo [`numeric`](https://en.cppreference.com/w/cpp/header/numeric):

| Función | Descripción |
|:-------:|:------------|
| `std::iota` | Rellena una secuencia con incrementos sucesivos de un valor inicial. |
| `std::accumulate` | Suma o reduce una secuencia de elementos. |
| `std::inner_product` | Calcula el producto interior de dos secuencias de elementos. |
| `std::adjacent_difference` | Calcula la diferencia entre elementos adyacentes en una secuencia. |
| `std::partial_sum` | Calcula la suma parcial de una secuencia de elementos. |
| `std::reduce` | Reduce una secuencia de elementos sin un orden concreto. |
| `std::exclusive_scan` | Similar a `partial_sum`, excluyendo el último elemento de la secuencia. |
| `std::inclusive_scan` | Similar a `partial_sum`, incluyendo el último elemento de la secuencia. |
| `std::transform_reduce` | Aplica una función a una secuencia y después la reduce. |
| `std::transform_exclusive_scan` | Aplica una función a una secuencia y después la operación `exclusive_scan`. |
| `std::transform_inclusive_scan` | Aplica una función a una secuencia y después la operación `inclusive_scan`. |

> Por defecto los algoritmos son secuenciales en su ejecución, pero se puede como primer parámetro indicar una política de ejecución en algunos de ellos. Las opciones son:
> + `seq`: Ejecución secuencial.
> + `par`: Ejecución paralela si está disponible.
> + `par_unseq`: Ejecución paralela y/o vectorizada si está disponible.
> + `unseq`: Ejecución vectorizada si está disponible.

### Entrada/Salida

Estos son los [tipos principales](https://en.cppreference.com/w/cpp/io) de la biblioteca estándar para manejar la entrada y salida:

| Tipo | Módulo | `char` | `wchar_t` | Descripción |
|:----:|:------:|:------:|:---------:|:------------|
| [`std::ios_base`](https://en.cppreference.com/w/cpp/io/ios_base) | [`ios`](https://en.cppreference.com/w/cpp/header/ios) |  |  | Gestiona los flags para formatear la entrada y salida, así como las excepciones. |
| [`std::basic_ios<T>`](https://en.cppreference.com/w/cpp/io/basic_ios) | [`ios`](https://en.cppreference.com/w/cpp/header/ios) | `std::ios` | `std::wios` | Gestiona flujos de datos arbitrarios. |
| [`std::basic_ostream<T>`](https://en.cppreference.com/w/cpp/io/basic_ostream) | [`ostream`](https://en.cppreference.com/w/cpp/header/ostream) | `std::ostream` | `std::wostream` | Encapsula un dispositivo abstracto para operaciones de salida. |
| [`std::basic_istream<T>`](https://en.cppreference.com/w/cpp/io/basic_istream) | [`istream`](https://en.cppreference.com/w/cpp/header/istream) | `std::istream` | `std::wistream` | Encapsula un dispositivo abstracto para operaciones de entrada. |
| [`std::basic_iostream<T>`](https://en.cppreference.com/w/cpp/io/basic_iostream) | [`istream`](https://en.cppreference.com/w/cpp/header/istream) | `std::iostream` | `std::wiostream` | Encapsula un dispositivo abstracto para operaciones de entrada y salida. |
| [`std::basic_ostringstream<T>`](https://en.cppreference.com/w/cpp/io/basic_ostringstream) | [`sstream`](https://en.cppreference.com/w/cpp/header/sstream) | `std::ostringstream` | `std::wostringstream` | Encapsula un dispositivo de cadenas para operaciones de salida. |
| [`std::basic_istringstream<T>`](https://en.cppreference.com/w/cpp/io/basic_istringstream) | [`sstream`](https://en.cppreference.com/w/cpp/header/sstream) | `std::istringstream` | `std::wistringstream` | Encapsula un dispositivo de cadenas para operaciones de entrada. |
| [`std::basic_stringstream<T>`](https://en.cppreference.com/w/cpp/io/basic_stringstream) | [`sstream`](https://en.cppreference.com/w/cpp/header/sstream) | `std::stringstream` | `std::wstringstream` | Encapsula un dispositivo de cadenas para operaciones de entrada y salida. |
| [`std::basic_ofstream<T>`](https://en.cppreference.com/w/cpp/io/basic_ofstream) | [`fstream`](https://en.cppreference.com/w/cpp/header/fstream) | `std::ofstream` | `std::wofstream` | Encapsula un fichero para operaciones de salida. |
| [`std::basic_ifstream<T>`](https://en.cppreference.com/w/cpp/io/basic_ifstream) | [`fstream`](https://en.cppreference.com/w/cpp/header/fstream) | `std::ifstream` | `std::wifstream` | Encapsula un fichero para operaciones de entrada. |
| [`std::basic_fstream<T>`](https://en.cppreference.com/w/cpp/io/basic_fstream) | [`fstream`](https://en.cppreference.com/w/cpp/header/fstream) | `std::fstream` | `std::wfstream` | Encapsula un fichero para operaciones de entrada y salida. |

Los miembros principales que disponemos para trabajar con `ios_base` son:

| Categoría | Miembro | Descripción |
|:---------:|:-------:|:------------|
| General | `operator=` | Operador de asignación. |
| Formato | `flags` | Modifica los flags de formato. |
| Formato | `setf` | Activa flags de formato. |
| Formato | `unsetf` | Desactiva flags de formato. |
| Formato | `precision` | Configura la precisión de la parte decimal en números reales. |
| Formato | `width` | Configura el ancho de columna. |
| Localización | `imbue` | Cambia la configuración para la localización. |
| Localización | `getloc` | Obtiene la configuración para la localización. |

También como parte de `ios_base` tenemos los siguientes tipos y valores definidos, a los que se puede acceder usando `std::ios` o `std::wios`:

| Tipo | Descripción | Valores |
|:----:|:------------|:--------|
| [`openmode`](https://en.cppreference.com/w/cpp/io/ios_base/openmode) | Modo de apertura del flujo. | `app`: Se sitúa al final del flujo después de cada escritura.<br/>`binary`: Abre el flujo en modo binario.<br/>`in`: Abre el flujo para lectura.<br/>`out`: Abre el flujo para escritura.<br/>`trunc`: Borra el contenido del flujo al abrirlo.<br/>`ate`: Se sitúa al final del flujo después de abrirlo. |
| [`fmtflags`](https://en.cppreference.com/w/cpp/io/ios_base/fmtflags) | Flags de formato. | `dec`: Usa la notación decimal para números enteros.<br/>`oct`: Usa la notación octal para números enteros.<br/>`hex`: Usa la notación hexadecimal para números enteros.<br/>`basefield`: `dec \| oct \| hex`.<br/>`left`: Ajuste a la izquierda.<br/>`right`: Ajuste a la derecha.<br/>`internal`: Ajuste interno.<br/>`adjustfield`: `left \| right \| internal`.<br/>`scientific`: Muestra tipos de coma flotante con notación científica.<br/>`fixed`: Muestra tipos de coma flotante con notación fija.<br/>`floatfield`: `scientific \| fixed`.<br/>`boolalpha`: Muestra los valores booleanos de forma alfabética.<br/>`showbase`: Muestra un prefijo para indicar la base de un número entero.<br/>`showpoint`: Muestra siempre el separador decimal con números reales.<br/>`showpos`: Muestra el signo `+` para números positivos.<br/>`skipws`: Descarta los espacios en blanco iniciales con operaciones de entrada.<br/>`unitbuf`: Procesa el buffer de salida con cada operación de salida.<br/>`uppercase`: Salida en mayúsculas. |
| [`iostate`](https://en.cppreference.com/w/cpp/io/ios_base/iostate) | Estado del flujo. | `goodbit`: Sin errores.<br/>`badbit`: Error de flujo irrecuperable.<br/>`failbit`: Operación de E/S fallida.<br/>`eofbit`: La entrada ha alcanzado el final de fichero. |
| [`seekdir`](https://en.cppreference.com/w/cpp/io/ios_base/seekdir) | Posición de partida para desplazarse. | `beg`: Inicio del flujo.<br/>`end`: Final del flujo.<br/>`cur`: Posición actual del flujo. |

Los miembros principales que disponemos para trabajar con `basic_ios` son:

| Categoría | Miembro | Descripción |
|:---------:|:-------:|:------------|
| General | `operator=` | Operador de asignación. |
| Estado | `good` | Comprueba que no ha ocurrido ningún error de E/S. |
| Estado | `eof` | Comprueba si se ha llegado al final de fichero. |
| Estado | `fail` | Comprueba que si ha ocurrido algún error de E/S. |
| Estado | `bad` | Comprueba que si ha ocurrido algún error irrecuperable de E/S. |
| Estado | `operator!` | Comprueba que si ha ocurrido algún error de E/S. |
| Estado | `operator bool` | Comprueba que no ha ocurrido ningún error de E/S. |
| Estado | `rdstate` | Devuelve los flags de estado del flujo. |
| Estado | `setstate` | Modifica los flags de estado del flujo. |
| Estado | `clear` | Borra los flags de estado del flujo. |
| Formato | `copyfmt` | Copia la información de formato. |
| Formato | `fill` | Configura el carácter de relleno. |
| Varios | `exceptions` | Gestiona la máscara de excepciones. |
| Varios | `imbue` | Cambia la configuración para la localización. |
| Varios | `rdbuf` | Gestiona el buffer asociado al flujo. |
| Varios | `tie` | Gestiona el flujo enlazado. |
| Varios | `narrow` | Convierte un carácter a su equivalente estándar. |
| Varios | `widen` | Convierte un carácter a su equivalente local. |

Los miembros principales que disponemos para trabajar con `basic_ostream` son:

| Categoría | Miembro | Descripción |
|:---------:|:-------:|:------------|
| General | `operator=` | Operador de asignación. |
| Salida | `operator<<` | Envía información con formato a la salida. |
| Salida | `put` | Envía un carácter a la salida. |
| Salida | `write` | Envía una cadena de texto a la salida. |
| Posición | `tellp` | Devuelve la posición actual en el flujo. |
| Posición | `seekp` | Modifica la posición actual en el flujo. |
| Varios | `flush` | Sincroniza el flujo con el dispositivo subyacente. |
| Varios | `swap` | Intercambio de flujos entre objetos. |

Los miembros principales que disponemos para trabajar con `basic_istream` son:

| Categoría | Miembro | Descripción |
|:---------:|:-------:|:------------|
| General | `operator=` | Operador de asignación. |
| Salida  | `operator>>` | Obtiene información con formato de la entrada. |
| Salida  | `get` | Obtiene un carácter de la entrada. |
| Salida  | `peek` | Obtiene un carácter de la entrada sin eliminarlo del buffer. |
| Salida  | `unget` | Recupera de vuelta el último carácter extraído del buffer de entrada, para volver a añadirlo al inicio del mismo. |
| Salida  | `putback` | Añade un carácter al inicio del buffer de entrada. |
| Salida  | `getline` | Obtiene una línea de texto de la entrada. |
| Salida  | `ignore` | Descarta caracteres de la entrada hasta encontrar el valor dado como argumento. |
| Salida  | `read` | Obtiene un bloque de tamaño fijo de texto de la entrada. |
| Salida  | `readsome` | Obtiene un bloque de texto con lo que hay en el buffer de entrada. |
| Salida  | `gcount` | Obtiene el número de caracteres obtenido por la última operación de lectura sin formato. |
| Posición | `tellp` | Devuelve la posición actual en el flujo. |
| Posición | `seekp` | Modifica la posición actual en el flujo. |
| Varios | `sync` | Sincroniza el flujo con el dispositivo subyacente. |
| Varios | `swap` | Intercambio de flujos entre objetos. |

Los miembros principales que disponemos para trabajar con `basic_fstream` son:

| Categoría | Miembro | Descripción |
|:---------:|:-------:|:------------|
| General | `operator=` | Operador de asignación. |
| General | `swap` | Intercambio de flujos entre objetos. |
| Operaciones | `is_open` | Comprueba si el flujo tiene un fichero abierto. |
| Operaciones | `open` | Abre un fichero y lo asocia al flujo. |
| Operaciones | `close` | Cierra el fichero asociado al flujo. |

Los miembros principales que disponemos para trabajar con `basic_stringstream` son:

| Categoría | Miembro | Descripción |
|:---------:|:-------:|:------------|
| General | `operator=` | Operador de asignación. |
| General | `swap` | Intercambio de flujos entre objetos. |
| Operaciones | `str` | Modifica u obtiene la cadena actual del flujo. |
| Operaciones | `view` | Obtiene una vista a la cadena actual del flujo. |

Para trabajar con la consola tenemos, en el módulo [`iostream`](https://en.cppreference.com/w/cpp/header/iostream), los objetos [`std::cout`](https://en.cppreference.com/w/cpp/io/cout) para la salida estándar, [`std::cin`](https://en.cppreference.com/w/cpp/io/cin) para la entrada estándar, [`std::cerr`](https://en.cppreference.com/w/cpp/io/cerr) para la salida de errores estándar. Estos objetos trabajan con ASCII, usando el tipo `char`, pero para Unicode tenemos `std::wcout`, `std::wcin` y `std::wcerr`, usando el tipo `wchar_t`.

Para enviar un mensaje a la pantalla se utiliza el operador `<<` con `std::cout` o `std::cerr`, ya que son de tipo `std::ostream`. Mientras que para obtener un valor se usa `>>` con `std::cin`, ya que es de tipo `std:istream`.

Para una correcta localización, a la hora de mostrar texto por la consola, podemos usar la función [`setlocale`](https://en.cppreference.com/w/cpp/locale/setlocale) de C, pero en C++ existe el tipo [`std::locale`](https://en.cppreference.com/w/cpp/locale/locale), en el módulo [`locale`](https://en.cppreference.com/w/cpp/header/locale). Por ejemplo:

```cpp
#include<iostream>

int main () {
    std::locale::global(std::locale("es_ES"));
    std::cout << "¡Hola España!\n";
    std::locale::global(std::locale("C"));
    std::cout << "¡Adios España!\n";
}
```

Con la función estática `global`, podemos pasarle una configuración determinada para la localización, que para ello construimos un objeto `std::locale` indicando con una cadena el lenguaje o configuración a usar. Por temas históricos, la configuración `C` es la utilizada por defecto en C, pero si queremos usar texto en español podemos usar valores como `es_ES`, `es` o `spanish`, entre otras.

> Por defecto, la biblioteca estándar de C++, tiene activada la compatibilidad con la E/S de C. Si no se necesita las funciones del estándar de C para la E/S, se puede desactivar la compatibilidad con la función [`sync_with_stdio`](https://en.cppreference.com/w/cpp/io/ios_base/sync_with_stdio) con la sentencia `std::ios_base::sync_with_stdio(false);`.

Además tenemos las siguientes [funciones](https://en.cppreference.com/w/cpp/io/manip) dentro del espacio de nombres `std`, que se pueden usar con los operadores de entrada `>>` y salida `<<`, para dar formato a dichas operaciones:

| Módulo | Función | Descripción |
|:------:|:-------:|:------------|
| [`ios`](https://en.cppreference.com/w/cpp/header/ios) | `boolalpha`<br/>`noboolalpha` | Activa o desactiva la representación alfabética de los booleanos. |
| [`ios`](https://en.cppreference.com/w/cpp/header/ios) | `showbase`<br/>`noshowbase` | Activa o desactiva el uso del prefijo que indica la base numérica. |
| [`ios`](https://en.cppreference.com/w/cpp/header/ios) | `showpoint`<br/>`noshowpoint` | Activa o desactiva si se debe mostrar siempre el punto decimal en números reales. |
| [`ios`](https://en.cppreference.com/w/cpp/header/ios) | `showpos`<br/>`noshowpos` | Activa o desactiva si se debe mostrar siempre el signo positivo en números. |
| [`ios`](https://en.cppreference.com/w/cpp/header/ios) | `skipws`<br/>`noskipws` | Activa o desactiva si se deben descartar lo espacios en blanco iniciales con la entrada. |
| [`ios`](https://en.cppreference.com/w/cpp/header/ios) | `uppercase`<br/>`nouppercase` | Activa o desactiva si el texto ha de estar sólo en mayúsculas. |
| [`ios`](https://en.cppreference.com/w/cpp/header/ios) | `unitbuf`<br/>`nounitbuf` | Activa o desactiva si se debe procesar el buffer de salida con cada operación de salida. |
| [`ios`](https://en.cppreference.com/w/cpp/header/ios) | `internal`<br/>`left`<br/>`right` | Configura la alineación del texto en la columna actual. |
| [`ios`](https://en.cppreference.com/w/cpp/header/ios) | `dec`<br/>`hex`<br/>`oct` | Configura la base numérica a usar para los enteros. |
| [`ios`](https://en.cppreference.com/w/cpp/header/ios) | `fixed`<br/>`scientific`<br/>`hexfloat`<br/>`defaultfloat` | Configura el formato usado para los números reales. |
| [`istream`](https://en.cppreference.com/w/cpp/header/istream) | `ws` | Descarta los espacios en blanco iniciales de la entrada. |
| [`ostream`](https://en.cppreference.com/w/cpp/header/ostream) | `ends` | Inserta el carácter nulo (`'\0'`) en un flujo de salida. |
| [`ostream`](https://en.cppreference.com/w/cpp/header/ostream) | `flush` | Limpia el buffer de salida procesando su contenido. |
| [`ostream`](https://en.cppreference.com/w/cpp/header/ostream) | `endl` | Inserta un salto de línea (`'\n'`) y limpia el buffer de salida procesando su contenido. |
| [`ostream`](https://en.cppreference.com/w/cpp/header/ostream) | `emit_on_flush`<br/>`noemit_on_flush` | Controla cuándo se emite un `basic_syncbuf` al limpiar el buffer. |
| [`ostream`](https://en.cppreference.com/w/cpp/header/ostream) | `flush_emit` | Limpia el buffer y emite su contenido si está usando un `basic_syncbuf`. |
| [`iomanip`](https://en.cppreference.com/w/cpp/header/iomanip) | `resetiosflags` | Limpia los `ios_base` flags indicados. |
| [`iomanip`](https://en.cppreference.com/w/cpp/header/iomanip) | `setiosflags` | Activa los `ios_base` flags indicados. |
| [`iomanip`](https://en.cppreference.com/w/cpp/header/iomanip) | `setbase` | Modifica los `ios_base` flags indicados. |
| [`iomanip`](https://en.cppreference.com/w/cpp/header/iomanip) | `setfill` | Modifica el carácter de relleno. |
| [`iomanip`](https://en.cppreference.com/w/cpp/header/iomanip) | `setprecision` | Modifica la precisión de la parte decimal de los números reales. |
| [`iomanip`](https://en.cppreference.com/w/cpp/header/iomanip) | `setw` | Modifica el ancho de columna para las operaciones de E/S. |
| [`iomanip`](https://en.cppreference.com/w/cpp/header/iomanip) | `get_money` | Obtiene un valor de tipo monetario. |
| [`iomanip`](https://en.cppreference.com/w/cpp/header/iomanip) | `put_money` | Envía un valor de tipo monetario. |
| [`iomanip`](https://en.cppreference.com/w/cpp/header/iomanip) | `get_time` | Obtiene un valor de tipo fecha o tiempo. |
| [`iomanip`](https://en.cppreference.com/w/cpp/header/iomanip) | `put_time` | Envía un valor de tipo fecha o tiempo. |
| [`iomanip`](https://en.cppreference.com/w/cpp/header/iomanip) | `quoted` | Inserta y extrae cadenas con comillas con espacios embebidos. |

### Sistema de ficheros

Estos son los tipos principales de la biblioteca estándar, dentro del módulo [`filesystem`](https://en.cppreference.com/w/cpp/header/filesystem), para gestionar el sistema de ficheros:

| Tipo | Descripción |
|:----:|:------------|
| [`std::path`](https://en.cppreference.com/w/cpp/filesystem/path) | Clase para representar rutas en el sistema de ficheros. |
| [`std::filesystem_error`](https://en.cppreference.com/w/cpp/filesystem/filesystem_error) | Clase para representar errores en el sistema de ficheros. |
| [`std::directory_entry`](https://en.cppreference.com/w/cpp/filesystem/directory_entry) | Clase para representar un elemento en un directorio. |
| [`std::directory_iterator`](https://en.cppreference.com/w/cpp/filesystem/directory_iterator) | Clase para iterar sobre el contenido de un directorio. |
| [`std::recursive_directory_iterator`](https://en.cppreference.com/w/cpp/filesystem/recursive_directory_iterator) | Clase para iterar sobre el contenido de un directorio y sus subdirectorios. |
| [`std::file_status`](https://en.cppreference.com/w/cpp/filesystem/file_status) | Clase para representar el tipo y los permisos de un fichero. |
| [`std::space_info`](https://en.cppreference.com/w/cpp/filesystem/space_info) | Clase para obtener información sobre el espacio disponible en un sistema de ficheros. |
| [`std::file_type`](https://en.cppreference.com/w/cpp/filesystem/file_type) | Enumeración para . |
| [`std::perms`](https://en.cppreference.com/w/cpp/filesystem/perms) | Enumeración para . |
| [`std::perm_options`](https://en.cppreference.com/w/cpp/filesystem/perm_options) | Enumeración para . |
| [`std::copy_options`](https://en.cppreference.com/w/cpp/filesystem/copy_options) | Enumeración para . |
| [`std::directory_options`](https://en.cppreference.com/w/cpp/filesystem/directory_options) | Enumeración para . |
| [`std::file_time_type`](https://en.cppreference.com/w/cpp/filesystem/file_time_type) | Tipo para representar marcas de tiempo para ficheros. |

Además, tenemos las siguientes [funciones](https://en.cppreference.com/w/cpp/filesystem) dentro del espacio de nombres `std`, para realizar operaciones sobre el sistema de ficheros:

| Función | Descripción |
|:-------:|:------------|
| `absolute` | Crea una ruta absoluta. |
| `canonical`<br/>`weakly_canonical` | Crea una ruta canónica. |
| `relative`<br/>`proximate` | Crea una ruta relativa. |
| `copy` | Copia ficheros o directorios. |
| `copy_file` | Copia el contenido de ficheros. |
| `copy_symlink` | Copia un enlaces simbólicos. |
| `create_directory`<br/>`create_directories` | Crea directorios nuevos. |
| `create_hard_link` | Crea enlaces duros. |
| `create_symlink`<br/>`create_directory_symlink` | Crea enlaces simbólicos. |
| `current_path` | Obtiene o modifica el directorio de trabajo actual. |
| `exists` | Comprueba si una ruta existe o no. |
| `equivalent` | Comprueba si dos rutas hacen referencia al mismo elemento. |
| `file_size` | Obtiene el tamaño de un fichero. |
| `hard_link_count` | Obtiene el número de enlaces duros asociados a un fichero. |
| `last_write_time` | Obtiene o modifica la marca de tiempo de la última modificación. |
| `permissions` | Modifica los permisos de acceso a un fichero. |
| `read_symlink` | Obtiene el destino de un enlace simbólico. |
| `remove`<br/>`remove_all` | El primero elimina un fichero o directorio vacío. El segundo además elimina el contenido de un directorio recursivamente. |
| `rename` | Mueve o renombra un fichero o directorio. |
| `resize_file` | Cambia el tamaño de un fichero, ya sea truncando el contenido o rellenando con ceros. |
| `space` | Obtiene el espacio libre disponible en el sistema de ficheros. |
| `status`<br/>`symlink_status` | Determina los atributos de un fichero. |
| `temp_directory_path` | Obtiene un directorio para ficheros temporales. |

A las anteriores, también se le suman las siguientes funciones para comprobar propiedades de los ficheros:

| Función | Descripción |
|:-------:|:------------|
| `is_block_file` | Comprueba si la ruta es un dispositivo de bloque. |
| `is_character_file` | Comprueba si la ruta es un dispositivo de caracteres. |
| `is_directory` | Comprueba si la ruta es un directorio. |
| `is_empty` | Comprueba si la ruta es un fichero o directorio vacío. |
| `is_fifo` | Comprueba si la ruta es una tubería con nombre. |
| `is_other` | Comprueba si la ruta es otro tipo de fichero. |
| `is_regular_file` | Comprueba si la ruta es un fichero normal. |
| `is_socket` | Comprueba si la ruta es un socket IPC con nombre. |
| `is_symlink` | Comprueba si la ruta es un enlace simbólico. |
| `status_known` | Comprueba si el estado para un fichero es conocido. |

### Memoria

Existen muchos tipos y funciones para la [gestión dinámica de la memoria](https://en.cppreference.com/w/cpp/memory) en la biblioteca estándar, pero nos vamos a centrar en los punteros inteligentes. Hay dos tipos genéricos para crear punteros inteligentes y uno auxiliar:

| Tipo | Descripción |
|:----:|:------------|
| [`std::unique_ptr<T>`](https://en.cppreference.com/w/cpp/memory/unique_ptr) | Puntero con semánticas de propiedad única. |
| [`std::shared_ptr<T>`](https://en.cppreference.com/w/cpp/memory/shared_ptr) | Puntero con semánticas de propiedad compartida. |
| [`std::weak_ptr<T>`](https://en.cppreference.com/w/cpp/memory/weak_ptr) | Referencia débil a un objeto gestionado por `shared_ptr`. |

Un `unique_ptr` no comparte la propiedad del puntero, por lo que no se puede copiar su contenido, mientras que un `shared_ptr` sí se puede compartir, porque lleva la cuenta del número de referencias que hay al objeto apuntado. Es el caso de `shared_ptr` el que se asemejaría más a los punteros inteligentes de C# o Python, pero aquí no hay recolector de basura, por lo que cuando se llega a cero en el contador de referencias, se elimina de la memoria el objeto apuntado.

Para facilitar la construcción de instancias, usando punteros inteligentes, se utilizan las funciones [`std::make_unique<T>`](https://en.cppreference.com/w/cpp/memory/unique_ptr/make_unique) y [`std::make_shared<T>`](https://en.cppreference.com/w/cpp/memory/shared_ptr/make_shared), que por debajo implementan la reserva de memoria con el operador `new`, invocando un constructor del tipo `T` en base a los argumentos pasados.

También son muy importantes, para la gestión de memoria, las funciones [`std::move`](https://en.cppreference.com/w/cpp/utility/move) y [`std::forward`](https://en.cppreference.com/w/cpp/utility/forward). La primera cambia la semántica del argumento de copiar a mover su valor. La segunda, dependiendo del tipo, elige entre dar al argumento la semántica de copiar o mover, para tener referencias a objetos que no queremos que su contenido se mueva.

### Utilidades

Dentro de la biblioteca estándar tenemos los siguientes tipos como [utilidades](https://en.cppreference.com/w/cpp/utility) varias:

| Módulo | Tipo | Descripción |
|:------:|:----:|:------------|
| [`functional`](https://en.cppreference.com/w/cpp/header/functional) | [`std::hash<T>`](https://en.cppreference.com/w/cpp/utility/hash) | Calcula un valor hash para un objeto de un tipo `T`. |
| [`bitset`](https://en.cppreference.com/w/cpp/header/bitset) | [`std::bitset<N>`](https://en.cppreference.com/w/cpp/utility/bitset) | Representa una secuencia de tamaño fijo de `N` bits. |
| [`utility`](https://en.cppreference.com/w/cpp/header/utility) | [`std::pair<T1,T2>`](https://en.cppreference.com/w/cpp/utility/pair) | Representa una tupla de dos componentes. |
| [`tuple`](https://en.cppreference.com/w/cpp/header/tuple) | [`std::tuple<...>`](https://en.cppreference.com/w/cpp/utility/tuple) | Representa una tupla de N componentes. |
| [`variant`](https://en.cppreference.com/w/cpp/header/variant) | [`std::variant<...>`](https://en.cppreference.com/w/cpp/utility/variant) | Representa una unión de tipos, para almacenar un objeto de alguno de dichos tipos. Se utiliza como sustituto de los tipos `union`. |
| [`optional`](https://en.cppreference.com/w/cpp/header/optional) | [`std::optional<T>`](https://en.cppreference.com/w/cpp/utility/optional) | Representa un valor opcional, que puede contener o no la instancia actual. Es un concepto prestado de la programación funcional y las [mónadas](https://es.wikipedia.org/wiki/M%C3%B3nada_(programaci%C3%B3n_funcional)). |
| [`any`](https://en.cppreference.com/w/cpp/header/any) | [`std::any`](https://en.cppreference.com/w/cpp/utility/any) | Representa una unión de cualquier tipo, para almacenar cualquier tipo de objeto. |
| [`typeinfo`](https://en.cppreference.com/w/cpp/header/typeinfo) | [`std::type_info`](https://en.cppreference.com/w/cpp/types/type_info) | Contiene información sobre la implementación de un tipo. El operador `typeid(T)` devuelve este tipo de objetos si está activado el RTTI al compilar. |

Para trabajar con el [tiempo](https://en.cppreference.com/w/cpp/chrono), en el módulo [`chrono`](https://en.cppreference.com/w/cpp/header/chrono), tenemos los siguientes tipos:

| Tipo | Descripción |
|:----:|:------------|
| [`std::system_clock`](https://en.cppreference.com/w/cpp/chrono/system_clock) | Reloj en tiempo real del sistema (*wall clock*). |
| [`std::steady_clock`](https://en.cppreference.com/w/cpp/chrono/steady_clock) | Reloj monótono que nunca va a ser ajustado. |
| [`std::high_resolution_clock`](https://en.cppreference.com/w/cpp/chrono/high_resolution_clock) | Reloj con la mayor precisión disponible. |
| [`std::is_clock`<br/>`std::is_clock_v`](https://en.cppreference.com/w/cpp/chrono/is_clock) | Comprueba si un tipo es un reloj. |
| [`std::utc_clock`](https://en.cppreference.com/w/cpp/chrono/utc_clock) | Reloj de tipo UTC (*Coordinated Universal Time*). |
| [`std::tai_clock`](https://en.cppreference.com/w/cpp/chrono/tai_clock) | Reloj de tipo TAI (*International Atomic Time*). |
| [`std::gps_clock`](https://en.cppreference.com/w/cpp/chrono/gps_clock) | Reloj para GPS. |
| [`std::file_clock`](https://en.cppreference.com/w/cpp/chrono/file_clock) | Reloj usado para marcas de tiempo de ficheros. |
| [`std::local_t`](https://en.cppreference.com/w/cpp/chrono/local_t) | Pseudo-reloj que representa la hora local. |
| [`std::time_point`](https://en.cppreference.com/w/cpp/chrono/time_point) | Representa una marca en el tiempo. |
| [`std::clock_cast`](https://en.cppreference.com/w/cpp/chrono/clock_cast) | Convierte marcas de tiempo de un reloj a otro. |

En el módulo [`functional`](https://en.cppreference.com/w/cpp/header/functional), tenemos herramientas para trabajar con [funciones](https://en.cppreference.com/w/cpp/utility/functional). El tipo principal es [`std::function`](https://en.cppreference.com/w/cpp/utility/functional/function), que representa una función del programa como valor, permitiendo que las funciones sean ciudadanos de primera clase como en los lenguajes de programación funcional. También hay tipos que encapsulan operadores matemáticos como funciones, para poder usarlos en algoritmos de la biblioteca estándar en lugar de crear una lambda para ello.

En el módulo [`format`](https://en.cppreference.com/w/cpp/header/format), tenemos herramientas para dar [formato a cadenas](https://en.cppreference.com/w/cpp/utility/format). La función principal es [`std::format`](https://en.cppreference.com/w/cpp/utility/format/format), pero no usa el formato de cadenas de C, en su lugar usa la sintaxis:

$$\texttt{\\{} \textcolor{red}{[} \mathit{\acute{\imath}ndice} \textcolor{red}{]} \textcolor{red}{[} \texttt{:} \mathit{formato} \textcolor{red}{]} \texttt{\\}}$$

El *formato* depende de las especializaciones que tengamos del tipo genérico [`std::formatter`](https://en.cppreference.com/w/cpp/utility/format/formatter). Este mecanismo para dar formato a cadenas, es una alternativa a tipos como `stringstream`.

Por último, en el módulo [`type_traits`](https://en.cppreference.com/w/cpp/header/type_traits), podemos encontrar un buen repertorio de tipos y funciones para trabajar con [metaprogramación](https://en.cppreference.com/w/cpp/meta). Mediante plantillas podemos ejecutar operaciones varias en tiempo de compilación, usando el paradigma de la programación funcional con una sintaxis no del todo amable.

### Números

Dentro de la biblioteca estándar tenemos diferentes herramientas [matemáticas](https://en.cppreference.com/w/cpp/numeric). La primera de ellas son las [funciones comunes](https://en.cppreference.com/w/cpp/numeric/math), que están en su mayoría en el módulo [`cmath`](https://en.cppreference.com/w/cpp/header/cmath):

| Categoría | Miembro | Descripción |
|:---------:|:-------:|:------------|
| Básicas | `abs`<br/>`fabs` | Valor absoluto. |
| Básicas | `fmod` | Resto de una división. |
| Básicas | `remainder` | Resto con signo de una división. |
| Básicas | `remquo` | Resto con signo de una división y los tres últimos bits del resultado de la división. |
| Básicas | `fma` | `fma(x,y,z)` equivale a `x * y + z`. |
| Básicas | `fmax` | El mayor de dos números. |
| Básicas | `fmin` | El menor de dos números. |
| Básicas | `fdim` | Diferencia positiva de dos números: `fmax(0,x-y)`. |
| Básicas | `nan` | Devuelve el valor *NaN*. |
| Interpolación | `lerp` | Calcula la función de interpolación lineal. |
| Exponencial | `exp` | Calcula el valor de *e^x^*. |
| Exponencial | `exp2` | Calcula el valor de *2^x^*. |
| Exponencial | `expm1` | Calcula el valor de *e^x^-1*. |
| Exponencial | `log` | Calcula el valor de *ln x*. |
| Exponencial | `log10` | Calcula el valor de *log~10~ x*. |
| Exponencial | `log2` | Calcula el valor de *log~2~ x*. |
| Exponencial | `log1p` | Calcula el valor de *ln(1+x)*. |
| Potencias | `pow` | Calcula el valor de *x^y^*. |
| Potencias | `sqrt` | Calcula la raíz cuadrada de *x*. |
| Potencias | `cbrt` | Calcula la raíz cúbica de *x*. |
| Potencias | `hypot` | Calcula la hipotenusa. |
| Trigonometría | `sin` | Calcula el seno en radianes. |
| Trigonometría | `cos` | Calcula el coseno en radianes. |
| Trigonometría | `tan` | Calcula la tangente en radianes. |
| Trigonometría | `asin` | Calcula el arcoseno en radianes. |
| Trigonometría | `acos` | Calcula el arcocoseno en radianes. |
| Trigonometría | `atan` | Calcula la arcotangente en radianes. |
| Trigonometría | `atan2` | Calcula la arcotangente de *y/x* en radianes. |
| Hiperbólicas | `sinh` | Calcula el seno hiperbólico en radianes. |
| Hiperbólicas | `cosh` | Calcula el coseno hiperbólico en radianes. |
| Hiperbólicas | `tanh` | Calcula la tangente hiperbólica en radianes. |
| Hiperbólicas | `asinh` | Calcula el arcoseno hiperbólico en radianes. |
| Hiperbólicas | `acosh` | Calcula el arcocoseno hiperbólico en radianes. |
| Hiperbólicas | `atanh` | Calcula la arcotangente hiperbólica en radianes. |
| Precisión | `erf` | Función de error. |
| Precisión | `erfc` | Función complementaria de error. |
| Precisión | `tgamma` | Función gamma. |
| Precisión | `lgamma` | Logaritmo natural de la función gamma. |
| Redondeo | `ceil` | El siguiente entero mayor o igual. |
| Redondeo | `floor` | El siguiente entero menor o igual. |
| Redondeo | `trunc` | El siguiente entero menor o igual en magnitud. |
| Redondeo | `round`<br/>`lround`<br/>`llround` | El entero más cercano. |
| Redondeo | `nearbyint` | El entero más cercano usando el modo actual de redondeo. |
| Redondeo | `rint`<br/>`lrint`<br/>`llrint` | El entero más cercano usando el modo actual de redondeo con excepciones si el resultado difiere. |
| Manipulación | `frexp` | Descompone un número entre su significado y su potencia de `2`. |
| Manipulación | `ldexp` | Multiplica un número por `2` elevado a la potencia. |
| Manipulación | `modf` | Descompone un número en su parte entera y la decimal. |
| Manipulación | `scalbn`<br/>`scalbln` | Multiplica un número por `FLT_RADIX` elevado a la potencia. |
| Manipulación | `ilogb` | Extrae el exponente de un número. |
| Manipulación | `logb` | Extrae el exponente de un número. |
| Manipulación | `nextafter`<br/>`nexttoward` | Siguiente valor de coma flotante representable. |
| Manipulación | `copysign` | Copia el signo de un valor de coma flotante. |
| Clasificación | `fpclassify` | Obtiene la categoría de un valor de coma flotante. |
| Clasificación | `isfinite` | Comprueba si el valor es finito. |
| Clasificación | `isinf` | Comprueba si el valor es infinito. |
| Clasificación | `isnan` | Comprueba si el valor no es valido. |
| Clasificación | `isnormal` | Comprueba si el valor es normal. |
| Clasificación | `signbit` | Comprueba si el valor es negativo. |
| Clasificación | `isgreater` | Comprueba si el primer valor es mayor que el segundo. |
| Clasificación | `isgreaterequal` | Comprueba si el primer valor es mayor o igual que el segundo. |
| Clasificación | `isless` | Comprueba si el primer valor es menor que el segundo. |
| Clasificación | `islessequal` | Comprueba si el primer valor es menor o igual que el segundo. |
| Clasificación | `islessgreater` | Comprueba si el primer valor es menor o mayor que el segundo. |
| Clasificación | `isunordered` | Comprueba si dos valores no son ordenables. |

Las anteriores funciones funcionan con el tipo `double`, pero tienen versiones terminadas en `f` para `float` y en `l` para `long double`. Además, dentro de `cmath` hay constantes como `INFINITY` o `NAN`, para representar el infinito o un número inválido con los números reales, que son macros heredadas del lenguaje C.

En el módulo [`numeric`](https://en.cppreference.com/w/cpp/header/numeric) tenemos las siguientes funciones adicionales:

| Función | Descripción |
|:-------:|:------------|
| `std::gcd` | Calcula el máximo común divisor de dos números. |
| `std::lcm` | Calcula el mínimo común múltiplo de dos números. |
| `std::midpoint` | Calcula el punto medio entre dos números. |
| `std::lerp` | Calcula la función de interpolación lineal. |
| `std::iota` | Rellena una secuencia con incrementos sucesivos de un valor inicial. |
| `std::accumulate` | Suma o reduce una secuencia de elementos. |
| `std::inner_product` | Calcula el producto interior de dos secuencias de elementos. |
| `std::adjacent_difference` | Calcula la diferencia entre elementos adyacentes en una secuencia. |
| `std::partial_sum` | Calcula la suma parcial de una secuencia de elementos. |
| `std::reduce` | Reduce una secuencia de elementos sin un orden concreto. |
| `std::exclusive_scan` | Similar a `partial_sum`, excluyendo el último elemento de la secuencia. |
| `std::inclusive_scan` | Similar a `partial_sum`, incluyendo el último elemento de la secuencia. |
| `std::transform_reduce` | Aplica una función a una secuencia y después la reduce. |
| `std::transform_exclusive_scan` | Aplica una función a una secuencia y después la operación `exclusive_scan`. |
| `std::transform_inclusive_scan` | Aplica una función a una secuencia y después la operación `inclusive_scan`. |

Por último, tenemos los siguientes módulos matemáticos:

| Módulo | Descripción |
|:------:|:------------|
| [`bit`](https://en.cppreference.com/w/cpp/header/bit) | Recoge una serie de funciones para trabajar a nivel de bits con valores y secuencias. |
| [`complex`](https://en.cppreference.com/w/cpp/header/complex) | Tiene la clase [`std::complex<T>`](https://en.cppreference.com/w/cpp/numeric/complex) que representa los números complejos. |
| [`limits`](https://en.cppreference.com/w/cpp/header/limits) | Tiene la clase [`std::numeric_limits<T>`](https://en.cppreference.com/w/cpp/types/numeric_limits) que da información sobre los tipos numéricos del lenguaje. |
| [`numbers`](https://en.cppreference.com/w/cpp/header/numbers) | Recoge un conjunto de [constantes](https://en.cppreference.com/w/cpp/numeric/constants), como el número `e` o `pi`. |
| [`random`](https://en.cppreference.com/w/cpp/header/random) | Recoge una serie de tipos para generar [números aleatorios](https://en.cppreference.com/w/cpp/numeric/random). Por un lado, tenemos distribuciones como [`std::uniform_int_distribution<T>`](https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution), para producir números enteros aleatorios de forma uniforme, y [`std::uniform_real_distribution<T>`](https://en.cppreference.com/w/cpp/numeric/random/uniform_real_distribution), para hacer lo mismo con números reales, entre otras. Por otro lado, las distribuciones requieren de generadores como `std::default_random_engine`, entre otros.  |
| [`valarray`](https://en.cppreference.com/w/cpp/header/valarray) | Tiene la clase [`std::valarray<T>`](https://en.cppreference.com/w/cpp/numeric/valarray) que representa un array especializado en números para optimizar operaciones matemáticas. |

### Concurrencia

La biblioteca estándar incorpora soporte para la [concurrencia](https://en.cppreference.com/w/cpp/thread). Estos son los principales tipos disponibles:

| Módulo | Tipo | Descripción |
|:------:|:----:|:------------|
| [`thread`](https://en.cppreference.com/w/cpp/header/thread) | [`std::thread`](https://en.cppreference.com/w/cpp/thread/thread) | Gestiona un hilo separado de ejecución. |
| [`thread`](https://en.cppreference.com/w/cpp/header/thread) | [`std::jthread`](https://en.cppreference.com/w/cpp/thread/jthread) | Gestiona un hilo separado de ejecución, con soporte para que se vuelva a unir al hilo principal por sí solo y para que pueda ser cancelado. |
| [`atomic`](https://en.cppreference.com/w/cpp/header/atomic) | [`std::atomic<T>`](https://en.cppreference.com/w/cpp/atomic/atomic) | Gestiona que las operaciones que se hagan sobre un objeto sean atómicas. |
| [`atomic`](https://en.cppreference.com/w/cpp/header/atomic) | [`std::atomic_ref<T>`](https://en.cppreference.com/w/cpp/atomic/atomic_ref) | Gestiona que las operaciones que se hagan sobre una referencia a un objeto sean atómicas. |
| [`atomic`](https://en.cppreference.com/w/cpp/header/atomic) | [`std::atomic_flag`](https://en.cppreference.com/w/cpp/atomic/atomic_flag) | Gestiona que las operaciones que se hagan sobre un booleano sean atómicas. Además, estas operaciones están libres de bloqueos. |
| [`mutex`](https://en.cppreference.com/w/cpp/header/mutex) | [`std::mutex`](https://en.cppreference.com/w/cpp/thread/mutex) | Representa una primitiva para sincronizar el acceso ordenado, a datos compartidos por múltiples hilos, mediante el bloqueo de la ejecución. |
| [`mutex`](https://en.cppreference.com/w/cpp/header/mutex) | [`std::timed_mutex`](https://en.cppreference.com/w/cpp/thread/timed_mutex) | Similar a `mutex`, pero los bloqueos tienen un tiempo de espera máximo. |
| [`mutex`](https://en.cppreference.com/w/cpp/header/mutex) | [`std::recursive_mutex`](https://en.cppreference.com/w/cpp/thread/recursive_mutex) | Similar a `mutex`, pero el se pueden acumular bloqueos de forma recursiva por el mismo hilo. |
| [`mutex`](https://en.cppreference.com/w/cpp/header/mutex) | [`std::recursive_timed_mutex`](https://en.cppreference.com/w/cpp/thread/recursive_timed_mutex) | Similar a `mutex`, pero el se pueden acumular bloqueos de forma recursiva por el mismo hilo con un tiempo de espera máximo. |
| [`shared_mutex`](https://en.cppreference.com/w/cpp/header/shared_mutex) | [`std::shared_mutex`](https://en.cppreference.com/w/cpp/thread/shared_mutex) | Similar a `mutex`, pero puede permitir acceso compartido a varios hilos. |
| [`shared_mutex`](https://en.cppreference.com/w/cpp/header/shared_mutex) | [`std::shared_timed_mutex`](https://en.cppreference.com/w/cpp/thread/shared_timed_mutex) | Similar a `shared_mutex`, pero los bloqueos tienen un tiempo de espera máximo. |
| [`mutex`](https://en.cppreference.com/w/cpp/header/mutex) | [`std::lock_guard<M>`](https://en.cppreference.com/w/cpp/thread/lock_guard) | Gestiona el bloqueo de un *mutex* y liberándolo cuando se sale del ámbito donde el candado ha sido declarado. |
| [`mutex`](https://en.cppreference.com/w/cpp/header/mutex) | [`std::scoped_lock<...>`](https://en.cppreference.com/w/cpp/thread/scoped_lock) | Similar a `lock_guard`, pero permite gestionar varios *mutex* a la vez. |
| [`mutex`](https://en.cppreference.com/w/cpp/header/mutex) | [`std::unique_lock<M>`](https://en.cppreference.com/w/cpp/thread/unique_lock) | Gestiona cómo se mueve la propiedad de un *mutex*. |
| [`shared_mutex`](https://en.cppreference.com/w/cpp/header/shared_mutex) | [`std::shared_lock<M>`](https://en.cppreference.com/w/cpp/thread/shared_lock) | Gestiona cómo se mueve la propiedad de un *shared mutex*. |
| [`mutex`](https://en.cppreference.com/w/cpp/header/mutex) | [`std::lock<...>`](https://en.cppreference.com/w/cpp/thread/lock) | Función para bloquear un grupo de *mutex*, si alguno estuviera bloqueado se bloquea la ejecución del hilo actual. |
| [`mutex`](https://en.cppreference.com/w/cpp/header/mutex) | [`std::try_lock<...>`](https://en.cppreference.com/w/cpp/thread/try_lock) | Función para bloquear un grupo de *mutex*, si alguno estuviera bloqueado devuelve un índice para indicar cuál ha sido, si no devuelve el valor `-1`. |
| [`future`](https://en.cppreference.com/w/cpp/header/future) | [`std::future<T>`](https://en.cppreference.com/w/cpp/thread/future) | Espera por un valor que es asignado de forma asíncrona. |
| [`future`](https://en.cppreference.com/w/cpp/header/future) | [`std::shared_future<T>`](https://en.cppreference.com/w/cpp/thread/shared_future) | Espera por un valor, posiblemente referenciado por otros objetos de tipo `future`, que es asignado de forma asíncrona. |
| [`future`](https://en.cppreference.com/w/cpp/header/future) | [`std::promise<T>`](https://en.cppreference.com/w/cpp/thread/promise) | Almacena un valor para recuperarlo de forma asíncrona. |
| [`future`](https://en.cppreference.com/w/cpp/header/future) | [`std::packaged_task<...>`](https://en.cppreference.com/w/cpp/thread/packaged_task) | Encapsula una función para almacenar su valor de retorno para recuperarlo de forma asíncrona. |
| [`future`](https://en.cppreference.com/w/cpp/header/future) | [`std::async<...>`](https://en.cppreference.com/w/cpp/thread/async) | Ejecuta una función de forma asíncrona, potencialmente en un nuevo hilo, y devuelve un objeto de tipo `future` con el que se obtendrá el resultado. |

