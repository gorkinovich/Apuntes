
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

$$\mathit{tipo}\ \mathit{nombre} \texttt{[} \textcolor{red}{[} \mathit{tam_1} \textcolor{red}{]} \texttt{]} \textcolor{red}{[} \texttt{[} \mathit{tam_2} \texttt{]} \textcolor{red}{\dots} \texttt{[} \mathit{tam_n} \texttt{]} \textcolor{red}{]}\ \textcolor{red}{[} \texttt{=}\ \texttt{\char123}\ \mathit{expresiones}\ \texttt{\char125} \textcolor{red}{]} \textcolor{red}{[} \texttt{,} \textcolor{red}{\dots}\ \textcolor{red}{]} \texttt{;}$$

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

$$\mathit{tipo}\ \mathit{nombre} \texttt{(} \textcolor{red}{[} \mathit{par\acute{a}metros} \textcolor{red}{]} \texttt{)}\ \textcolor{red}{[} \mathit{modificadores} \textcolor{red}{]}\ \textcolor{red}{[} \texttt{->}\ \mathit{tipo} \textcolor{red}{]}\ \texttt{\char123}\ \mathit{expresiones}\ \texttt{\char125}$$

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

$$\texttt{[} \mathit{capturas} \texttt{]}\ \texttt{(} \textcolor{red}{[} \mathit{par\acute{a}metros} \textcolor{red}{]} \texttt{)}\ \textcolor{red}{[} \mathit{modificadores} \textcolor{red}{]}\ \textcolor{red}{[} \texttt{->}\ \mathit{tipo} \textcolor{red}{]}\ \texttt{\char123}\ \mathit{expresiones}\ \texttt{\char125}$$

En cuanto a los *parámetros* se usa las mismas reglas que las funciones normales para su definición. Pero antes, tenemos las *capturas*, que es una lista de variables sobre las que vamos a hacer el cierre (*closure*), para poder usarlas en el cuerpo de la lambda. Hay que tener en cuenta que las lambdas se traducen en objetos de la clase [`std::function`](https://en.cppreference.com/w/cpp/utility/functional/function), por lo que se pueden devolver como resultados de una función y por ello hay que gestionar cómo se cierran las variables. Para ello esta lista de cero o más variables, separadas por comas, podrán declararse con la siguiente sintaxis:

$$\textcolor{red}{\char123} \texttt{\char38}\ \textcolor{red}{|}\ \texttt{=}\ \textcolor{red}{|}\ \textcolor{red}{[} \texttt{*} \textcolor{red}{]} \texttt{this}\ \textcolor{red}{|}\ \textcolor{red}{[} \texttt{\char38} \textcolor{red}{]} \mathit{nombre}\ \textcolor{red}{[} \mathit{inicializaci\acute{o}n} \textcolor{red}{|} \texttt{...} \textcolor{red}{]}\ \textcolor{red}{|}\ \textcolor{red}{[} \texttt{\char38} \textcolor{red}{]} \texttt{...} \mathit{nombre}\ \mathit{inicializaci\acute{o}n} \textcolor{red}{\char125}$$

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
\texttt{class}\ \mathit{nombre}\ \textcolor{red}{[} \texttt{final} \textcolor{red}{]}\ \textcolor{red}{[} \texttt{:}\ \mathit{padres} \textcolor{red}{]}\ \texttt{\char123}
\\[0.5em] \textcolor{red}{[} \texttt{public:}
\\[0.5em] \qquad \mathit{definiciones\ p\acute{u}blicas} \textcolor{red}{]}
\\[0.5em] \textcolor{red}{[} \texttt{protected:}
\\[0.5em] \qquad \mathit{definiciones\ protegidas} \textcolor{red}{]}
\\[0.5em] \textcolor{red}{[} \texttt{private:}
\\[0.5em] \qquad \mathit{definiciones\ privadas} \textcolor{red}{]}
\\[0.5em] \texttt{\char125} \texttt{;}
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

$$\textcolor{red}{[} \texttt{const} \textcolor{red}{]}\ \textcolor{red}{[} \texttt{\char38} \textcolor{red}{|} \texttt{\char38\char38} \textcolor{red}{]}\ \textcolor{red}{[} \texttt{noexcept} \textcolor{red}{[} \texttt{(} \mathit{booleano} \texttt{)} \textcolor{red}{]} \textcolor{red}{]}\ \textcolor{red}{[} \texttt{->}\ \mathit{tipo} \textcolor{red}{]}\ \textcolor{red}{\char123} \texttt{;}\ \textcolor{red}{|}\ \texttt{\char123}\ \mathit{expresiones}\ \texttt{\char125} \textcolor{red}{\char125}$$

Si no implementamos el cuerpo de la función dentro de la clase, hay que hacerlo fuera con la siguiente sintaxis:

$$\textcolor{red}{[} \texttt{inline} \textcolor{red}{]}\ \textcolor{red}{[} \texttt{constexpr} \textcolor{red}{|} \texttt{consteval} \textcolor{red}{]}\ \mathit{tipo}\ \mathit{clase} \texttt{::} \mathit{nombre} \texttt{(} \textcolor{red}{[} \mathit{par\acute{a}metros} \textcolor{red}{]} \texttt{)}$$

$$\textcolor{red}{[} \texttt{volatile} \textcolor{red}{]}\ \textcolor{red}{[} \texttt{const} \textcolor{red}{]}\ \textcolor{red}{[} \texttt{\char38} \textcolor{red}{|} \texttt{\char38\char38} \textcolor{red}{]}\ \textcolor{red}{[} \texttt{noexcept} \textcolor{red}{[} \texttt{(} \mathit{booleano} \texttt{)} \textcolor{red}{]} \textcolor{red}{]}\ \textcolor{red}{[} \texttt{->}\ \mathit{tipo} \textcolor{red}{]}\ \texttt{\char123}\ \mathit{expresiones}\ \texttt{\char125}$$

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

$$\textcolor{red}{\char123} \textcolor{red}{[} \texttt{= default} \textcolor{red}{|} \texttt{= delete} \textcolor{red}{]} \texttt{;}\ \textcolor{red}{|}\ \textcolor{red}{[} \texttt{:}\ \mathit{inicializadores} \textcolor{red}{]}\ \texttt{\char123}\ \mathit{expresiones}\ \texttt{\char125} \textcolor{red}{\char125}$$

Si no implementamos el cuerpo dentro de la clase, hay que hacerlo fuera con la siguiente sintaxis:

$$\textcolor{red}{[} \texttt{inline} \textcolor{red}{]}\ \textcolor{red}{[} \texttt{constexpr} \textcolor{red}{|} \texttt{consteval} \textcolor{red}{]}\ \mathit{clase} \texttt{::} \mathit{clase} \texttt{(} \textcolor{red}{[} \mathit{par\acute{a}metros} \textcolor{red}{]} \texttt{)}$$

$$\textcolor{red}{[} \texttt{noexcept} \textcolor{red}{[} \texttt{(} \mathit{booleano} \texttt{)} \textcolor{red}{]} \textcolor{red}{]}\ \textcolor{red}{[} \texttt{:}\ \mathit{inicializadores} \textcolor{red}{]}\ \texttt{\char123}\ \mathit{expresiones}\ \texttt{\char125}$$

Un constructor puede tener una lista de parámetros, como las funciones normales. El constructor con cero parámetros se denomina [constructor por defecto](https://en.cppreference.com/w/cpp/language/default_constructor). También tenemos el caso especial del [constructor copia](https://en.cppreference.com/w/cpp/language/copy_constructor) (`clase(const clase & obj)`), así como el [constructor de movimiento](https://en.cppreference.com/w/cpp/language/move_constructor) (`clase(clase && obj)`). El primero hace una copia de `obj` para crear la nueva instancia, mientras que el segundo se queda con todos los recursos (punteros y referencias) para construir la nueva instancia.

> Para forzar la invocación del constructor de movimiento, se puede utilizar la función [`std::move`](https://en.cppreference.com/w/cpp/utility/move).

 Además de los modificadores previamente vistos, con [`explicit`](https://en.cppreference.com/w/cpp/language/explicit) se añade como requisito que el tipo de los argumentos ha de corresponder con el tipo de los parámetros. Esto evita que se haga una conversión implícita para hacer encajar el valor en el tipo del parámetro. Luego tenemos `=default`, que sólo se puede aplicar al constructor por defecto, el de copia y el de movimiento, que indica de forma explícita al compilador que genere la versión por defecto automáticamente. Mientras que `=delete`, que se puede aplicar a todo tipo de constructor, indica al compilador que no se va a generar ningún código para dicho constructor.

Los inicializadores son una lista con la forma `nombre(expresión)` o `nombre{expresión}`, donde el nombre puede ser una variable interna o un tipo padre de la clase, que inicializa lo valores de la instancia que se está construyendo. Dependiendo de la expresión asignada, se usará un constructor u otro para inicializar cada elemento, por ello se usaba la notación con paréntesis, pero con C++11 se incorporó el uso de llaves para hacer lo mismo y unificar diferentes tipos de inicialización de objetos.

A continuación, la sintaxis de los destructores es:

$$\textcolor{red}{[} \texttt{virtual} \textcolor{red}{]}\ \textcolor{red}{[} \texttt{constexpr} \textcolor{red}{|} \texttt{consteval} \textcolor{red}{]}\ \texttt{\textasciitilde} \mathit{clase} \texttt{(} \texttt{)}\ \textcolor{red}{[} \texttt{noexcept} \textcolor{red}{[} \texttt{(} \mathit{booleano} \texttt{)} \textcolor{red}{]} \textcolor{red}{]}$$

$$\textcolor{red}{\char123} \textcolor{red}{[} \texttt{= default} \textcolor{red}{|} \texttt{= delete} \textcolor{red}{]} \texttt{;}\ \textcolor{red}{|}\ \texttt{\char123}\ \mathit{expresiones}\ \texttt{\char125} \textcolor{red}{\char125}$$

Si no implementamos el cuerpo dentro de la clase, hay que hacerlo fuera con la siguiente sintaxis:

$$\textcolor{red}{[} \texttt{inline} \textcolor{red}{]}\ \textcolor{red}{[} \texttt{constexpr} \textcolor{red}{|} \texttt{consteval} \textcolor{red}{]}\ \mathit{clase} \texttt{::} \texttt{\textasciitilde} \mathit{clase} \texttt{(} \texttt{)}$$

$$\textcolor{red}{[} \texttt{noexcept} \textcolor{red}{[} \texttt{(} \mathit{booleano} \texttt{)} \textcolor{red}{]} \textcolor{red}{]}\ \texttt{\char123}\ \mathit{expresiones}\ \texttt{\char125}$$

Por último, la sintaxis del operador de [copia](https://en.cppreference.com/w/cpp/language/copy_assignment)/[movimiento](https://en.cppreference.com/w/cpp/language/move_assignment) es:

$$\textcolor{red}{[} \texttt{virtual} \textcolor{red}{]}\ \textcolor{red}{[} \texttt{constexpr} \textcolor{red}{|} \texttt{consteval} \textcolor{red}{]}\ \mathit{clase}\ \texttt{\char38}\ \texttt{operator =} \texttt{(} \mathit{par\acute{a}metro} \texttt{)}$$

$$\textcolor{red}{[} \texttt{noexcept} \textcolor{red}{[} \texttt{(} \mathit{booleano} \texttt{)} \textcolor{red}{]} \textcolor{red}{]}\ \textcolor{red}{\char123} \textcolor{red}{[} \texttt{= default} \textcolor{red}{|} \texttt{= delete} \textcolor{red}{]} \texttt{;}\ \textcolor{red}{|}\ \texttt{\char123}\ \mathit{expresiones}\ \texttt{\char125} \textcolor{red}{\char125}$$

Si no implementamos el cuerpo dentro de la clase, hay que hacerlo fuera con la siguiente sintaxis:

$$\textcolor{red}{[} \texttt{inline} \textcolor{red}{]}\ \textcolor{red}{[} \texttt{constexpr} \textcolor{red}{|} \texttt{consteval} \textcolor{red}{]}\ \mathit{clase}\ \texttt{\char38}\ \mathit{clase} \texttt{::} \texttt{operator =} \texttt{(} \mathit{par\acute{a}metro} \texttt{)}$$

$$\textcolor{red}{[} \texttt{noexcept} \textcolor{red}{[} \texttt{(} \mathit{booleano} \texttt{)} \textcolor{red}{]} \textcolor{red}{]}\ \texttt{\char123}\ \mathit{expresiones}\ \texttt{\char125}$$

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

$$\textcolor{red}{[} \texttt{noexcept} \textcolor{red}{[} \texttt{(} \mathit{booleano} \texttt{)} \textcolor{red}{]} \textcolor{red}{]}\ \textcolor{red}{[} \texttt{->}\ \mathit{tipo} \textcolor{red}{]}\ \textcolor{red}{\char123} \texttt{;}\ \textcolor{red}{|}\ \texttt{\char123}\ \mathit{expresiones}\ \texttt{\char125} \textcolor{red}{\char125}$$

Si no implementamos el cuerpo de la función estática dentro de la clase, hay que hacerlo fuera con la siguiente sintaxis:

$$\textcolor{red}{[} \texttt{inline} \textcolor{red}{]}\ \textcolor{red}{[} \texttt{constexpr} \textcolor{red}{|} \texttt{consteval} \textcolor{red}{]}\ \mathit{tipo}\ \mathit{clase} \texttt{::} \mathit{nombre} \texttt{(} \textcolor{red}{[} \mathit{par\acute{a}metros} \textcolor{red}{]} \texttt{)}$$

$$\textcolor{red}{[} \texttt{noexcept} \textcolor{red}{[} \texttt{(} \mathit{booleano} \texttt{)} \textcolor{red}{]} \textcolor{red}{]}\ \textcolor{red}{[} \texttt{->}\ \mathit{tipo} \textcolor{red}{]}\ \texttt{\char123}\ \mathit{expresiones}\ \texttt{\char125}$$

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
\texttt{struct}\ \mathit{nombre}\ \textcolor{red}{[} \texttt{final} \textcolor{red}{]}\ \textcolor{red}{[} \texttt{:}\ \mathit{padres} \textcolor{red}{]}\ \texttt{\char123}
\\[0.5em] \textcolor{red}{[} \texttt{public:}
\\[0.5em] \qquad \mathit{definiciones\ p\acute{u}blicas} \textcolor{red}{]}
\\[0.5em] \textcolor{red}{[} \texttt{protected:}
\\[0.5em] \qquad \mathit{definiciones\ protegidas} \textcolor{red}{]}
\\[0.5em] \textcolor{red}{[} \texttt{private:}
\\[0.5em] \qquad \mathit{definiciones\ privadas} \textcolor{red}{]}
\\[0.5em] \texttt{\char125} \texttt{;}
\end{array}$$

Su existencia en el lenguaje se debe a una herencia del lenguaje C, pero en C++ actualmente funcionan exactamente como un tipo definido con `class`, con la diferencia de que por defecto la visibilidad es pública, si no se indica ningún bloque de visibilidad.

## Uniones

Las uniones son un tipo de dato especial, que permite definir una abstracción que contenga diferentes tipos de información en el mismo espacio de memoria a lo largo del tiempo. Su sintaxis básica es la siguiente:

$$\begin{array}{l}
\texttt{union}\ \mathit{nombre}\ \texttt{\char123}
\\[0.5em] \qquad \mathit{definiciones}
\\[0.5em] \texttt{\char125} \texttt{;}
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

$$\texttt{enum}\ \textcolor{red}{[} \texttt{class} \textcolor{red}{|} \texttt{struct} \textcolor{red}{]}\ \mathit{nombre}\ \textcolor{red}{[} \texttt{:}\ \mathit{tipo} \textcolor{red}{]}\ \texttt{\char123} \mathit{nombre_1}\ \textcolor{red}{[} \texttt{=}\ \mathit{valor_1} \textcolor{red}{]} \textcolor{red}{[} \texttt{,}\ \textcolor{red}{\dots} \texttt{,}\ \mathit{nombre_n}\ \textcolor{red}{[} \texttt{=}\ \mathit{valor_n} \textcolor{red}{]} \textcolor{red}{]} \texttt{\char125} \texttt{;}$$

Los valores deben ser expresiones constantes, incluyendo expresiones `constexpr`. Se puede indicar un tipo básico numérico, para definir cuál es el tamaño de los valores en memoria. Luego las palabras claves `class` y `struct` sirven para crear un tipo enumerado estricto, de ese modo una variable de ese tipo sólo puede recibir valores definidos en él, teniendo que usar la sintaxis `tipo::nombre`. Sin no se usa este mecanismo, basta con usar el nombre sin cualificar.

En ocasiones puede ser necesario declarar la existencia de un tipo enumerado sin incluir su definición, usando la siguiente sintaxis:

$$\texttt{enum}\ \mathit{nombre}\ \texttt{:}\ \mathit{tipo} \texttt{;}$$

$$\texttt{enum}\ \textcolor{red}{\char123} \texttt{class} \textcolor{red}{|} \texttt{struct} \textcolor{red}{\char125}\ \mathit{nombre}\ \textcolor{red}{[} \texttt{:}\ \mathit{tipo} \textcolor{red}{]} \texttt{;}$$

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
| `a@b` | `R A::operator @(B b)` | `R operator @(A a, B b)` | `+`, `-`, `*`, `/`, `%`, `&`, `|`, `^`, `<<`, `>>`, `,` |
| `a@b` | `bool A::operator @(const & B b)` | `bool operator @(const & A a, const & B b)` | `==`, `!=`, `<`, `>`, `<=`, `>=` |
| `a@b` | `auto A::operator @(const & B b)` | `auto operator @(const & A a, const & B b)` | `<=>` |
| `@a` | `bool A::operator @()` | `bool operator @(A a)` | `!` |
| `a@b` | `bool A::operator @(B b)` | `bool operator @(A a, B b)` | `&&`, `||` |
| `a@b` | `R & A::operator @(B b)` | - | `=` |
| `a@b` | `R & A::operator @(B b)` | `R & operator @(A & a, B b)` | `+=`, `-=`, `*=`, `/=`, `%=`, `&=`, `|=`, `^=`, `>>=`, `<<=` |
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

$$\mathit{tipo}\ \texttt{operator}\ \texttt{""}\ \mathit{sufijo} \texttt{(} \mathit{parametros} \texttt{)}\ \texttt{\char123}\ \mathit{expresi\acute{o}nes}\ \texttt{\char125}$$

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

int main () {
    std::cout << inc(1) << "\n";
}
```

Pero con C++20 se incluye la posibilidad de definir [módulos](https://en.cppreference.com/w/cpp/language/modules), para facilitar la definición de unidades de compilación y su acceso. Para ello tenemos las expresiones `export` e `import`, la primera para exportar definiciones y la segunda para importar módulos o cabeceras.

Para crear un módulo primero hay que definirlo y a continuación definir qué se va a exportar con el módulo. La sintaxis para definirlo es la siguiente:

$$\texttt{export}\ \texttt{module}\ \mathit{identificador} \texttt{;}$$

El identificador es una serie de nombres separados por `:`, para construir un nombre cualificado para el módulo. La sintaxis para exportar definiciones en el módulo es la siguiente:

$$\texttt{export}\ \textcolor{red}{\char123}\ \mathit{definici\acute{o}n}\ \textcolor{red}{|}\ \texttt{\char123}\ \mathit{definiciones}\ \texttt{\char125}\ \textcolor{red}{\char125}$$

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

Las [plantillas](https://en.cppreference.com/w/cpp/language/templates) es la herramienta del lenguaje para poder hacer código genérico independiente de los tipos. La sintáxis básica para definir una plantilla es:

$$\texttt{template} \texttt{<} \mathit{par\acute{a}metros} \texttt{>}\ \textcolor{red}{[} \mathit{requisitos} \textcolor{red}{]}\ \mathit{definici\acute{o}n}$$

Como *definiciones* podemos tener tipos, funciones y variables. Los *requisitos* tienen que ver con los conceptos que veremos en una subsección más adelante. Los parámetros tenemos tres categorías: variables, variables de tipo y plantillas de variables de tipo.

La sintaxis para definir variables como parámetros de una plantilla es:

$$\textcolor{red}{\char123}\ \mathit{tipo}\ \textcolor{red}{[} \mathit{nombre}\ \textcolor{red}{[} \texttt{=}\ \mathit{valor} \textcolor{red}{]} \textcolor{red}{]}\ \textcolor{red}{|}\ \mathit{tipo}\ \texttt{...}\ \textcolor{red}{[} \mathit{nombre} \textcolor{red}{]}\ \textcolor{red}{|}\ \texttt{auto}\ \textcolor{red}{[} \mathit{modificadores} \textcolor{red}{]}\ \mathit{nombre}\ \textcolor{red}{\char125}$$

La primera forma es un tipo normal, con un nombre y un posible valor por defecto. La segunda forma es una variable que representa una lista de parámetros variable. La tercera forma usa `auto` y se puede combinar con `*` y `&`, como modificadores, para deducir en tiempo de compilación el tipo de la variable de la plantilla.

La sintaxis para definir variables de tipo como parámetros de una plantilla es:

$$\textcolor{red}{\char123} \texttt{typename} \textcolor{red}{|} \texttt{class} \textcolor{red}{|} \mathit{restricci\acute{o}n} \textcolor{red}{\char125}\ \textcolor{red}{[} \mathit{nombre}\ \textcolor{red}{[} \texttt{=}\ \mathit{tipo} \textcolor{red}{]} \textcolor{red}{|} \texttt{...}\ \textcolor{red}{[} \mathit{nombre} \textcolor{red}{]} \textcolor{red}{]}$$

Después de indicar si es una variable de tipo general, con `typename` o `class`, que son sinónimos, o si es una restricción definida con conceptos, podremos darle un nombre y un valor por defecto al parámetro. Pero también podemos convertir ese parámetro en una lista de parámetros variable.

La sintaxis para definir plantillas de variables de tipo como parámetros de una plantilla es:

$$\texttt{template} \texttt{<} \mathit{par\acute{a}metros} \texttt{>}\ \textcolor{red}{\char123} \texttt{typename} \textcolor{red}{|} \texttt{class} \textcolor{red}{\char125}\ \textcolor{red}{[} \mathit{nombre}\ \textcolor{red}{[} \texttt{=}\ \mathit{tipo} \textcolor{red}{]} \textcolor{red}{|} \texttt{...}\ \textcolor{red}{[} \mathit{nombre} \textcolor{red}{]} \textcolor{red}{]}$$

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

$$\textcolor{red}{[} \texttt{extern} \textcolor{red}{]}\ \texttt{template}\ \textcolor{red}{\char123} \texttt{class} \textcolor{red}{|} \texttt{struct} \textcolor{red}{|} \texttt{union} \textcolor{red}{\char125}\ \mathit{nombre}\ \texttt{<} \mathit{argumentos} \texttt{>} \texttt{;}$$

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

### Conceptos

Los [conceptos](https://en.cppreference.com/w/cpp/language/constraints) son una forma de poder definir requisitos para las plantillas, de modo que definimos un concepto como una restricción que se han de cumplir, para que se pueda instanciar correctamente la plantilla. La sintaxis para definir un concepto es la siguiente:

$$\texttt{template} \texttt{<} \mathit{par\acute{a}metros} \texttt{>}\ \texttt{concept}\ \mathit{nombre}\ \texttt{=}\ \mathit{restrici\acute{o}n} \texttt{;}$$

En este caso la *restricción* puede ser una composición de los siguientes elementos: otros conceptos (no puede ser una relación recursiva), conjunciones con `&&`, disyunciones con `||`, negaciones con `!` y expresiones `requires`. En el fondo estamos manejado predicados lógicos para formar una fórmula que de como resultado `true`.

La expresión [`requires`](https://en.cppreference.com/w/cpp/language/requires), dentro de la definición de una restricción, sigue la siguiente sintaxis:

$$\texttt{requires}\ \textcolor{red}{[} \texttt{(} \mathit{par\acute{a}metros} \texttt{)} \textcolor{red}{]}\ \texttt{\char123}\ \mathit{requisitos}\ \texttt{\char125}$$

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

### Alias

Se puede crear un [alias](https://en.cppreference.com/w/cpp/language/type_alias) de una plantilla con la siguiente sintaxis:

$$\texttt{template} \texttt{<} \mathit{par\acute{a}metros} \texttt{>}\ \texttt{using}\ \mathit{nombre}\ \texttt{=}\ \mathit{declaraci\acute{o}n} \texttt{;}$$

Basta con indicar la declaración del tipo cuyo alias queremos crear, en lugar de la definición completa. Es decir, basta con la firma o cabecera del tipo.

### Lambdas

Se pueden tener plantillas de [lambdas](https://en.cppreference.com/w/cpp/language/lambda) con la siguiente sintaxis:

$$\texttt{[} \mathit{capturas} \texttt{]}\ \textcolor{red}{[} \texttt{<} \mathit{tipos} \texttt{>}\ \textcolor{red}{[} \mathit{requisitos} \textcolor{red}{]} \textcolor{red}{]}\ \texttt{(} \textcolor{red}{[} \mathit{par\acute{a}metros} \textcolor{red}{]} \texttt{)}\ \textcolor{red}{[} \mathit{modificadores} \textcolor{red}{]}\ \textcolor{red}{[} \texttt{->}\ \mathit{tipo} \textcolor{red}{]}\ \textcolor{red}{[} \mathit{requisitos} \textcolor{red}{]}\ \texttt{\char123}\ \mathit{expresiones}\ \texttt{\char125}$$

El prácticamente la misma sintaxis y elementos que las lambdas normales, pero aquí podemos poner variables de tipo entre `<` y `>`, así como indicar los requisitos que ha de cumplir la función mediante conceptos.

## Corrutinas

Las [corrutinas](https://en.cppreference.com/w/cpp/language/coroutines) son funciones que permiten la ejecución de código asíncrono, sin detener por completo la ejecución de la función que las invoca. Para trabajar con corrutinas es necesario incluir la librería [`coroutine`](https://en.cppreference.com/w/cpp/header/coroutine) y utilizar los siguientes operadores:

| Operador | Descripción |
|:--------:|:------------|
| `co_await` | Suspende la ejecución de la rutina hasta que vuelve a ser activada. |
| `co_yield` | Suspende la ejecución de la rutina para devolver un valor. |
| `co_return` | Completa la ejecución de la rutina devolviendo un valor. |

..

```cpp
// Fichero: corrutina.cpp
#include<coroutine>
#include<iostream>

int main () {
}
```

..

```cpp
// Fichero: generador.cpp
#include<coroutine>
#include<iostream>

int main () {
}
```

## Biblioteca estándar

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

int main () {
}
```

