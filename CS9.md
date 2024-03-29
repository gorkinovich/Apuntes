﻿# C# 9.0 (.NET 5.0)

[C#](https://en.wikipedia.org/wiki/C_Sharp_(programming_language)) es un lenguaje de programación multiparadigma desarrollado por Microsoft. Este lenguaje se sustenta sobre la plataforma [.NET](https://dotnet.microsoft.com/), siendo necesaria como mínimo la versión 5.0 para desarrollar con la versión 9.0 del lenguaje. El IDE principal que tenemos disponible es el [Visual Studio](https://visualstudio.microsoft.com/), siendo su versión *Community* gratuita. También existe [Visual Studio Code](https://code.visualstudio.com/), que es una versión gratuita y más liviana, que permite configurarlo para todo tipo de lenguajes de programación. Estos son algunos enlaces de interés:

+ [Documentación del lenguaje](https://learn.microsoft.com/dotnet/csharp/)
+ [Biblioteca estándar de .NET](https://learn.microsoft.com/dotnet/api/)

## Primeros pasos

Los ficheros con código fuente tienen la extensión `.cs`. Por ejemplo:

```csharp
// Fichero: hola.cs
System.Console.WriteLine("¡Hola mundo!");
```

Podemos usar el comando [`csc`](https://learn.microsoft.com/dotnet/csharp/language-reference/compiler-options/) para compilar el programa de la siguiente manera:

```
csc hola.cs
```

Esto nos genera un ejecutable `hola.exe`, para la consola del sistema operativo. Al ejecutarlo nos mostrará por la terminal el mensaje `¡Hola mundo!`.

> Existen ficheros con extensión `.csx`, que también contienen código en C# para ser ejecutado como un script por el comando `csi`.

Para crear proyectos, compilarlos y ejecutarlos, lo recomendable es usar el comando [`dotnet`](https://learn.microsoft.com/dotnet/core/tools/dotnet). Por ejemplo:

```
dotnet new console -o ejemplo
cd ejemplo
dotnet run
```

Con la opción [`new`](https://learn.microsoft.com/dotnet/core/tools/dotnet-new) se crea un proyecto nuevo, que genera un fichero de configuración `.csproj`, que el comando `dotnet` utilizará para saber qué opciones ha de utilizar para la compilación. En el ejemplo utilizamos la [plantilla](https://learn.microsoft.com/dotnet/core/tools/dotnet-new-sdk-templates) `console`. Con la opción [`run`](https://learn.microsoft.com/dotnet/core/tools/dotnet-run) se ejecuta la aplicación, compilándola previamente si fuera necesario. Por último, con la opción [`build`](https://learn.microsoft.com/dotnet/core/tools/dotnet-build) se compila el proyecto entero y sus dependencias.

Si usamos un IDE como Visual Studio, no tendremos que preocuparnos de aprender las opciones del comando `dotnet`, porque lo hará el propio entorno de desarrollo por nosotros pulsando el botón de compilar. Además tendremos ventajas como el depurador integrado, para inspeccionar la ejecución cuando falle y saber cuál es el error que hemos cometido en nuestro código.

## Conceptos fundamentales

C# es un lenguaje **orientado a objetos**, por lo que todo tipo de datos tiene su **definición** que es su **clase** y las **instancias** de las clases se las denomina **objetos**. Al describir una clase hay que definir los elementos que la componen, que podrán ser para instancias o estáticos. Los **elementos para instancias** son los datos que pertenecen a cada objeto y las funciones que se pueden aplicar a dichas instancias. Mientras que los **elementos estáticos** son datos y funciones globales al ámbito de la clase y que se almacenan de forma aparte a las instancias.

Se utiliza el punto y coma (`;`) para separar **sentencias** en el código, conformando una secuencia de expresiones. Las secuencias se pueden agrupar en un **bloque de código**, delimitado por llaves (`{` y `}`), creando un ámbito con ello. Los bloques no necesitan terminar con un punto y coma después de la llave. Sin embargo, una cosa son las llaves usadas para definir un bloque y otra las usadas para inicializar estructuras de datos, ya que en este caso sí se termina la definición con un punto y coma.

El **ámbito** de una declaración vendrá delimitado por el bloque que lo contiene. Un ámbito puede acceder directamente a aquellas definiciones de los bloques que lo contiene, pero no al revés. Dependiendo del tipo de declaración, se podrá acceder a definiciones internas a un ámbito usando los nombres cualificados, relativos o completos, con los que dicho elemento esté registrado. Esto último se puede observar con los espacios de nombres, por ejemplo, `Console` es una clase que está dentro de `System` y para acceder a ella hace falta usar el nombre cualificado `System.Console`.

Otro aspecto fundamental del lenguaje es la gestión de la **memoria**, siendo C# un lenguaje manejado. Esto quiere decir que la gestión de la memoria es automática, gracias a que las instancias de los objetos tienen un contador de **referencias** y que además existe un **recolector de basura** que se encarga de liberar el espacio que ocupan cuando dicho contador ha llegado a cero. Además, hay dos **tipos de memoria** utilizada por el lenguaje: la **pila** y el **montículo** (*heap*). El primero es usado para **tipos por valor** y el segundo para **tipos por referencia**.

El **montículo** es donde se reserva memoria de forma dinámica para almacenar los objetos. Para acceder a ellos se utilizan referencias, es decir, la variable que manejamos no es el valor final, sino una dirección de memoria que nos dice dónde está el valor final. Esto también se lo conoce como puntero, pero a diferencia de otros lenguajes como C, el proceso de trabajar con referencias es transparente al usuario y no hace falta trabajar a bajo nivel.

La **pila** es un segmento de memoria asociado a la ejecución del programa, que almacena datos con semántica por valor en lugar de por referencia, como es el caso de los tipos básicos o de las direcciones de memoria que se usan para acceder a los objetos en el montículo. La pila está muy relacionada con el ámbito de ejecución en el que se esté, cuando se sale de dicho ámbito, la información que se había añadido a la pila se pierde. Es importante tener esto en cuenta, para ser consciente del ciclo de vida de los valores que están almacenados en la pila.

## Comentarios y documentación

En C# hay varios tipos de comentarios. El primer tipo son los comentarios de línea:

```csharp
// Comentario de una sola línea...
```

Este tipo de comentario termina con el salto de línea, por lo que todo el texto que venga detrás de `//` será ignorado por el compilador. Si necesitáramos que el comentario ocupe varias líneas, tenemos la siguiente manera:

```csharp
/* Comentario que
puedo escribir en
varias líneas... */
```

Otro tipo de comentarios disponibles, son unas pequeñas variaciones de los dos anteriores, para poder añadir la documentación del código. Esta [documentación](https://learn.microsoft.com/dotnet/csharp/language-reference/language-specification/documentation-comments), que se puede aplicar a diferentes elementos del código, sirve para que un IDE pueda analizarla y mostrarla como ayuda al programador, mientras escribe código sobre la marcha. La primera forma de documentar es con:

```csharp
/// <summary>
/// Ejemplo de documentación del código...
/// </summary>
```

Al escribir `///`, en Visual Studio, nos generará automáticamente las etiquetas XML para la documentación que necesite el elemento que estamos documentando. Sin embargo, no tendremos esa misma ventaja al utilizar esta segunda forma:

```csharp
/** <summary>
    Ejemplo de documentación del código...
    </summary> */
```

## Nombres identificadores

En un programa es necesario poner nombres a los elementos con los que trabajamos. Para ello, un identificador se compone de una sucesión de letras (mayúsculas y minúsculas), dígitos (`0`-`9`) y/o el guion bajo (`_`), que no debe comenzar por dígito. No se podrán usar las [palabras reservadas](https://learn.microsoft.com/dotnet/csharp/language-reference/keywords/) del lenguaje como identificadores, salvo que se utilice como prefijo el símbolo `@` (por ejemplo, `@class`).

> La [guía de estilo](https://learn.microsoft.com/dotnet/csharp/fundamentals/coding-style/identifier-names) de C# es compleja y extensa, pero a grandes rasgos se utiliza [*PascalCase*](https://en.wikipedia.org/wiki/Pascal_case) para espacios de nombres, tipos de datos y miembros públicos en los tipos, para lo demás se usa [`camelCase`](https://en.wikipedia.org/wiki/Camel_case). Otra regla es que los nombres de las interfaces empiezan por `I`.

## Entrada al programa

Todo programa tiene una función principal de entrada, pero en las últimas versiones de C# se permite tener un fichero con un bloque de expresiones que irían en la función de entrada, sin tener que definirla. Por ejemplo:

```csharp
using System;
Console.WriteLine("¡Hola mundo!");
```

Esto se traduce a algo parecido a lo siguiente:

```csharp
using System;

class Programa {
    static void Main() {
        Console.WriteLine("¡Hola mundo!");
    }
}
```

Donde tenemos una clase `Programa` que tiene una función `Main` que es estática. El compilador buscará esta función en el proyecto, para generar el programa, por lo que sólo podemos tener una función `Main` definida en todo el proyecto.

Si necesitamos acceder a los argumentos usados para ejecutar el programa, tendremos esta otra variante de la función `Main`:

```csharp
using System;

class Programa {
    static int Main(string[] args) {
        Console.WriteLine("¡Hola mundo con argumentos!");
        foreach (var arg in args) {
            Console.WriteLine(arg);
        }
        return 0;
    }
}
```

En el modo *top-level* del primer ejemplo, si queremos acceder a los argumentos del programa, tendremos a nuestra disposición una variable predefinida llamada `args`, que también será un array de cadenas de texto.

## Espacios de nombres

Los espacios de nombres (*namespaces*) nos sirven para organizar grupos de definiciones bajo un nombre identificador. Estos nombres pueden estar compuestos por varios nombres separados por puntos, ya que un espacio se puede anidar en el interior de otro. La sintaxis para crear un espacio de nombres es la siguiente:

$$\texttt{namespace}\ \mathit{nombre_1} \textcolor{red}{[} \texttt{.} \textcolor{red}{\dots} \texttt{.} \mathit{nombre_n} \textcolor{red}{]}\ \texttt{\\{}\ \mathit{definiciones}\ \texttt{\\}}$$

Incluso dentro de un mismo fichero se puede declarar dos veces el mismo espacio de nombres, siempre que no se pisen las definiciones. Esto también se puede aplicar entre distintos ficheros de código. Se le llama nombre cualificado cuando se usa el nombre completo de un elemento definido, es decir su espacio de nombres completo más el nombre del elemento, todo ello separado por puntos. Por ejemplo, `System.Collections.IEnumerator`, donde su espacio es `System.Collections` y el elemento es `IEnumerator`. Si queremos usar el nombre de la definición sin el nombre cualificado, podemos usar la sentencia `using` con la siguiente sintaxis:

$$\texttt{using}\ \textcolor{red}{[} \texttt{static} \textcolor{red}{]}\ \mathit{nombre_1} \textcolor{red}{[} \texttt{.} \textcolor{red}{\dots} \texttt{.} \mathit{nombre_n} \textcolor{red}{]}\texttt{;}$$

Con esta sentencia se añade a la tabla de búsqueda del compilador, para ese ámbito donde ha sido utilizada, un elemento donde buscar definiciones al usar un nombre. El modificador `static` nos permite incorporar las definiciones estáticas de un tipo, en lugar de incorporar las definiciones de un espacio de nombres. Por ejemplo:

```csharp
using System;             // Definiciones del espacio de nombres.
using static System.Math; // Elementos estáticos del tipo.

var resultado = Pow(2, 3);
Console.WriteLine($"2 ** 3 = {resultado}");
```

En lugar de:

```csharp
var resultado = System.Math.Pow(2, 3);
System.Console.WriteLine($"2 ** 3 = {resultado}");
```

Otra utilidad de la sentencia `using` es crear alias para definiciones o espacios de nombres, con la siguiente sintaxis:

$$\texttt{using}\ \mathit{nombre}\ \texttt{=}\ \mathit{nombre_1} \textcolor{red}{[} \texttt{.} \textcolor{red}{\dots} \texttt{.} \mathit{nombre_n} \textcolor{red}{]}\texttt{;}$$

Por ejemplo:

```csharp
using S = System;
using C = System.Console;
C.WriteLine(S.Int32.MaxValue);
```

Aunque el uso de alias puede acabar llevando a crear código ofuscado, dependiendo del uso que se le de. Normalmente se recurre a crear alias cuando necesitamos usar tipos que se llaman igual en distintos espacios de nombres y para evitar la colisión de nombres les ponemos un alias a cada uno.

Dentro de un espacio de nombres se puede acceder directamente a los elementos del espacio que lo contiene. Si el espacio `A` contiene a `B` y `C`, para que los elementos de `B` accedan a `C`, tendrán que usar un nombre cualificado relativo al espacio `A`, es decir, `C.Elemento`. Hay que tener en cuenta que las definiciones en un ámbito pueden ocultar a las definiciones exteriores si tienen el mismo nombre, en cuyo caso habría que usar el nombre cualificado para acceder a la definición ocultada. También existe un cualificador para acceder al espacio global con `global::Elemento`, por ejemplo, `global::System.Math`.

## Literales

El primer grupo de literales es el valor nulo, que representa la semántica vacía en cuanto a los valores del lenguaje. Es decir, una expresión nula no tiene valor. Su sintaxis es la siguiente:

$$\texttt{null}$$

> Técnicamente hablando, el valor nulo se utiliza para indicar que una variable, con una referencia a un objeto, no está apuntando a ninguna instancia del tipo que tiene y por lo tanto no tiene valor.

El siguiente grupo son los [booleanos](https://es.wikipedia.org/wiki/Booleano). Estos se utilizan para dar valor a condiciones que pueden ser ciertas o falsas. Su sintaxis es la siguiente:

$$\textcolor{red}{\\{} \texttt{true} \textcolor{red}{|} \texttt{false} \textcolor{red}{\\}}$$

El siguiente grupo son los números enteros, cuya sintaxis es:

$$\textcolor{red}{[} \mathit{prefijo} \textcolor{red}{]} \mathit{d\acute{\imath}gitos} \textcolor{red}{[} \mathit{sufijo} \textcolor{red}{]}$$

Los prefijos validos son:

| Prefijos | Tipo | Dígitos |
|:--------:|:----:|:-------:|
| - | Decimal | `0`-`9` |
| `0b`, `0B` | Binario | `0`-`1` |
| `0x`, `0X` | Hexadecimal | `0`-`9`, `A`-`F`, `a`-`f` |

Los sufijos validos son:

| Prefijos | Tipo | Descripción |
|:--------:|:----:|:------------|
| - | `int` | Entero con signo (32 bits). |
| `u`, `U` | `uint` | Entero sin signo (32 bits). |
| `l`, `L` | `long` | Entero largo con signo (64 bits). |
| `ul`, `lu`, `uL`, `lU`,<br/>`Ul`, `Lu`, `UL`, `LU` | `ulong` | Entero largo sin signo (64 bits). |

Además, se puede usar `_` como separador entre dígitos, para agrupar los números de la forma que necesitemos. Por ejemplo, `1_234` o `0x1234_5678`.

El siguiente grupo son los números reales, cuya sintaxis es:

$$\mathit{d\acute{\imath}gitos} \textcolor{red}{[} \texttt{.} \mathit{d\acute{\imath}gitos} \textcolor{red}{]} \textcolor{red}{[} \textcolor{red}{\\{} \texttt{e} \textcolor{red}{|} \texttt{E} \textcolor{red}{\\}} \textcolor{red}{[} \texttt{+} \textcolor{red}{|} \texttt{-} \textcolor{red}{]} \mathit{d\acute{\imath}gitos} \textcolor{red}{]} \textcolor{red}{[} \mathit{sufijo} \textcolor{red}{]}$$

Los sufijos validos son:

| Prefijos | Tipo | Descripción |
|:--------:|:----:|:------------|
| - | `double` | Precisión doble (64 bits). |
| `f`, `F` | `float` | Precisión simple (32 bits). |
| `d`, `D` | `double` | Precisión doble (64 bits). |
| `m`, `M` | `decimal` | Precisión extra larga (128 bits). |

El siguiente grupo es para representar texto, ya sean caracteres sueltos o cadenas de ellos. Para representar un carácter suelto se utiliza:

$$\texttt{'} \textcolor{red}{\\{} \mathit{letra} \textcolor{red}{|} \mathit{secuencia\ de\ escape} \textcolor{red}{\\}} \texttt{'}$$

Las secuencias de escape disponibles son:

| Secuencia | Significado | Secuencia | Significado |
|:---------:|:------------|:---------:|:------------|
| `\'` | Comilla simple. | `\n` | Nueva línea. |
| `\"` | Comilla doble. | `\r` | Retroceso de línea. |
| `\\` | Barra invertida. | `\t` | Tabulación horizontal. |
| `\0` | Carácter nulo. | `\v` | Tabulación vertical. |
| `\a` | Alarma. | `\xHHHH` | Carácter hexadecimal. |
| `\b` | Retroceso. | `\uHHHH` | Carácter Unicode (UTF-16). |
| `\f` | Alimentación. | `\UHHHHHHHH` | Carácter Unicode (UTF-32). |

Para representar una cadena de texto se utiliza:

$$\textcolor{red}{[} \texttt{@} \textcolor{red}{]} \texttt{"} \mathit{caracteres} \texttt{"}$$

Con el prefijo `@` la cadena será "cruda" y no tendrá en cuenta ninguna secuencia de escape. Se utilizan para poder poner rutas de Windows sin tener que usar `\\` continuamente. La única salvedad con este tipo de cadenas es que con `""` se puede representar las comillas dobles. También se puede utilizar este tipo de cadenas para crear cadenas multilínea, a diferencia de las cadenas normales.

## Constantes

Una constante es un valor fijo con nombre. Se pueden declarar de la siguiente manera:

$$\texttt{const}\ \mathit{tipo}\ \mathit{nombre_1}\ \texttt{=}\ \mathit{literal_1} \textcolor{red}{[} \texttt{,} \textcolor{red}{\dots} \texttt{,}\ \mathit{nombre_n}\ \texttt{=}\ \mathit{literal_n} \textcolor{red}{]} \texttt{;}$$

Su valor no se puede modificar durante la ejecución, de ahí que sean constantes. Los tipos válidos para declarar constantes es reducido, ya que se requiere que se inicialice con una expresión literal. Esta limitación se debe a que la constante se toma, durante la compilación, para sustituir sus apariciones por su valor asignado.

## Variables

Una variable es un valor con nombre que puede variar durante la ejecución del programa. La sintaxis estándar para definir variables es la siguiente:

$$\mathit{tipo}\ \mathit{nombre_1}\ \textcolor{red}{[} \texttt{=}\ \mathit{expresi\acute{o}n_1} \textcolor{red}{]} \textcolor{red}{[} \texttt{,} \textcolor{red}{\dots} \texttt{,}\ \mathit{nombre_n}\ \textcolor{red}{[} \texttt{=}\ \mathit{expresi\acute{o}n_n} \textcolor{red}{]} \textcolor{red}{]} \texttt{;}$$

Podemos usar la palabra clave `dynamic` como *tipo* al declarar una variable, o cualquier elemento que tenga tipo. Al hacer esto, se marca el tipo de dicho elemento como dinámico, sea una variable, el tipo de una función, etcétera.

> El tipado dinámico realiza la comprobación de tipos en tiempo de ejecución, en lugar de hacerlo durante la compilación, como ocurre con el tipado estático. Esto permite una mayor flexibilidad en el código, pero también puede ser una mayor fuente de errores durante la ejecución, por un mal uso de los tipos instanciados. Se incorporó esta característica a .NET para poder dar soporte a lenguajes como Python en la plataforma.

Con la palabra clave `var` se indica al compilador que infiera el tipo para la variable en base a la expresión que inicializa su valor:

$$\texttt{var}\ \mathit{nombre_1}\ \texttt{=}\ \mathit{expresi\acute{o}n_1} \textcolor{red}{[} \texttt{,} \textcolor{red}{\dots} \texttt{,}\ \mathit{nombre_n}\ \texttt{=}\ \mathit{expresi\acute{o}n_n} \textcolor{red}{]} \texttt{;}$$

## Tipos básicos

Los tipos básicos son aquellos que tienen palabras reservadas en el lenguaje para referirse a ellos. En su mayoría son tipos por valor, por lo que se almacenan en la pila de programa.

### Booleanos

El tipo `bool` representa a los valores booleanos y es un sinónimo del tipo [`System.Boolean`](https://learn.microsoft.com/dotnet/api/system.boolean). Es un tipo bastante sencillo, del que si acaso podemos destacar las funciones estáticas `Parse` y `TryParse`, para convertir una cadena en un booleano. En cuanto a las instancias, existe el método `ToString` para convertir el booleano a cadena.

### Texto

El tipo `char` representa caracteres de texto en Unicode (UTF-16). Es sinónimo del tipo [`System.Char`](https://learn.microsoft.com/dotnet/api/system.char) y ocupa 16-bits.

El tipo `string` representa una cadena de texto en Unicode y es sinónimo del tipo [`System.String`](https://learn.microsoft.com/dotnet/api/system.string). Este tipo no es por valor, sino por referencia. Además, sus valores son inmutables, por lo que no se puede modificar el contenido de una cadena. Las operaciones para manipularlas lo que hacen es crear una nueva cadena con el resultado de la operación, sin modificar la original.

### Números

El primer grupo de ellos son los [números enteros](https://learn.microsoft.com/dotnet/csharp/language-reference/builtin-types/integral-numeric-types):

| Tipo | Tipo .NET | Tamaño | Rango |
|:----:|:---------:|:------:|:-----:|
| `sbyte` | [`System.SByte`](https://learn.microsoft.com/dotnet/api/system.sbyte) | 8-bit con signo | `-128` .\. `127` |
| `byte` | [`System.Byte`](https://learn.microsoft.com/dotnet/api/system.byte) | 8-bit sin signo | `0` .\. `255` |
| `short` | [`System.Int16`](https://learn.microsoft.com/dotnet/api/system.int16) | 16-bit con signo | `-32768` .\. `32767` |
| `ushort` | [`System.UInt16`](https://learn.microsoft.com/dotnet/api/system.uint16) | 16-bit sin signo | `0` .\. `65535` |
| `int` | [`System.Int32`](https://learn.microsoft.com/dotnet/api/system.int32) | 32-bit con signo | `-2147483648` .\. `2147483647` |
| `uint` | [`System.UInt32`](https://learn.microsoft.com/dotnet/api/system.uint32) | 32-bit sin signo | `0` .\. `4294967295` |
| `long` | [`System.Int64`](https://learn.microsoft.com/dotnet/api/system.int64) | 64-bit con signo | `-9223372036854775808` .\. `9223372036854775807` |
| `ulong` | [`System.UInt64`](https://learn.microsoft.com/dotnet/api/system.uint64) | 64-bit sin signo | `0` .\. `18446744073709551615` |
| `nint` | [`System.IntPtr`](https://learn.microsoft.com/dotnet/api/system.intptr) | 32-bit o 64-bit con signo | (Depende de la plataforma) |
| `nuint` | [`System.UIntPtr`](https://learn.microsoft.com/dotnet/api/system.uintptr) | 32-bit o 64-bit sin signo | (Depende de la plataforma) |

Todos estos tipos tienen las constantes `MinValue` y `MaxValue`, que representan el valor mínimo y máximo del tipo. Son muchas las funciones estáticas que tienen cada tipo, como las que convierten una cadena a número y viceversa.

> El caso de `nint` y `nuint` es especial porque son tipos para representar números enteros de forma nativa a la plataforma, para aplicar ciertas optimizaciones durante la compilación, así como interoperabilidad con código nativo. Esto no quiere decir que sea siempre más eficiente su uso en los programas, ya que esa eficiencia se da en circunstancias muy específicas.

El segundo grupo de ellos son los [números reales](https://learn.microsoft.com/dotnet/csharp/language-reference/builtin-types/floating-point-numeric-types):

| Tipo | Tipo .NET | Tamaño | Rango | Precisión |
|:----:|:---------:|:------:|:-----:|:---------:|
| `float` | [`System.Single`](https://learn.microsoft.com/dotnet/api/system.single) | 4 bytes | De ±1,5 x 10^−45^ hasta ±3,4 x 10^38^ | ~6-9 dígitos |
| `double` | [`System.Double`](https://learn.microsoft.com/dotnet/api/system.double) | 8 bytes | De ±5,0 x 10^−324^ hasta ±1,7 x 10^308^ | ~15-17 dígitos |
| `decimal` | [`System.Decimal`](https://learn.microsoft.com/dotnet/api/system.decimal) | 16 bytes | De ±1,0 x 10^−28^ hasta ±7,9228 x 10^28^ | 28-29 dígitos |

Al igual que con los enteros, `float` y `double` también tienen las constantes `MinValue` y `MaxValue`. Pero además, tienen las siguientes constantes:

| Constante | Descripción |
|:---------:|:------------|
| `NaN` | Representación de valores que no son un número. |
| `Epsilon` | Representa el menor positivo posible por encima de cero. |
| `NegativeZero` | Representación del cero negativo. |
| `NegativeInfinity` | Representación lógica del infinito negativo. |
| `PositiveInfinity` | Representación lógica del infinito. |
| `E` | [Número *e*](https://es.wikipedia.org/wiki/N%C3%BAmero_e). |
| `Pi` | [Número π](https://es.wikipedia.org/wiki/N%C3%BAmero_%CF%80). |
| `Tau` | [Número tau](https://es.wikipedia.org/wiki/Tau_%282%CF%80%29) (valor en radianes de 360º). |

También tienen las funciones para convertir de cadena a número y viceversa, a lo que hay que sumar, entre muchas otras, funciones estáticas para comprobar si un número cumple una condición. Por ejemplo, `IsNaN` comprueba si el valor es en efecto `NaN`, porque en este caso concreto cualquier comparación con esta constante dará falso como resultado:

```csharp
using static System.Console;

var número = 1.0 / 0.0;                       // Infinito
WriteLine(número == double.PositiveInfinity); // True

número /= double.PositiveInfinity; // NaN
WriteLine(número == double.NaN);   // False
WriteLine(double.IsNaN(número));   // True
```

El tipo `decimal` también comparte con los enteros las constantes `MinValue` y `MaxValue`, así como la conversión de número a cadena y viceversa. A ello se le suma las constantes:

| Constante | Descripción |
|:---------:|:------------|
| `MinusOne` | Representación del valor `-1`. |
| `One` | Representación del valor `1`. |
| `Zero` | Representación del valor `0`. |

También en el caso de `decimal` tiene una cuantiosa variedad de funciones estáticas para realizar operaciones varias, como ocurre con el resto de tipos numéricos.

### Conversiones implícitas

Estas son las conversiones implícitas que permite el lenguaje:

| Origen | Destino |
|:------:|:--------|
| `sbyte` | `short`, `int`, `long`, `float`, `double`, `decimal` o `nint`. |
| `byte` | `short`, `ushort`, `int`, `uint`, `long`, `ulong`, `float`, `double`, `decimal`, `nint` o `nuint`. |
| `short` | `int`, `long`, `float`, `double`, `decimal` o `nint`. |
| `ushort` | `int`, `uint`, `long`, `ulong`, `float`, `double`, `decimal`, `nint` o `nuint`. |
| `int` | `long`, `float`, `double`, `decimal` o `nint`. |
| `uint` | `long`, `ulong`, `float`, `double`, `decimal` o `nuint`. |
| `long` | `float`, `double` o `decimal`. |
| `ulong` | `float`, `double` o `decimal`. |
| `float` | `double`. |
| `nint` | `long`, `float`, `double` o `decimal`. |
| `nuint` | `ulong`, `float`, `double` o `decimal`. |

Para hacer la conversión inversa habrá que realizar un *casting* para evitar que el compilador nos de un error, ya que en esos casos la probabilidad de pérdida de información es muy alta. Por ejemplo:

```csharp
using static System.Console;

byte a = 128;
int b = a * 2;
WriteLine($"{a}, {b}"); // 128, 256

a = (byte)b;
WriteLine($"{a}, {b}"); // 0, 256
```

## Operadores

En esta sección veremos por encima los [operadores](https://learn.microsoft.com/dotnet/csharp/language-reference/operators/) disponibles en el lenguaje. En algunos casos particulares se verán con más detalles en secciones posteriores.

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
| `X is T` | `X` es de tipo `T`. |

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

### Numéricos

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

```csharp
using static System.Console;

int x = 1;
WriteLine(++x); // 2
WriteLine(x++); // 2
WriteLine(x);   // 3
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
| `X >>> Y` | **C# 11:** Desplazamiento sin signo a la derecha `Y` bits de `X`. Siempre se añaden ceros por la izquierda con el desplazamiento, mientras que con `>>` se añaden unos si el primer bit es un `1`. |

De modo similar a los operadores lógicos, están son sus [tablas de la verdad](https://es.wikipedia.org/wiki/Tabla_de_verdad):

| `X` | `Y` | `~X` | `~Y` | `X & Y` | `X \| Y` | `X ^ Y` |
|:---:|:---:|:----:|:----:|:-------:|:-------:|:-------:|
| `1` | `1` |  `0` |  `0` |   `1`   |   `1`   |   `0`   |
| `0` | `1` |  `1` |  `0` |   `0`   |   `1`   |   `1`   |
| `1` | `0` |  `0` |  `1` |   `0`   |   `1`   |   `1`   |
| `0` | `0` |  `1` |  `1` |   `0`   |   `0`   |   `0`   |

Los operadores aritméticos sólo se aplican a los tipos básicos `int`, `uint`, `long`, `ulong`, `float`, `double` y `decimal`. Mientras que los operadores a nivel de bit sólo se aplican a los tipos básicos `int`, `uint`, `long` y `ulong`. El resto de tipos básicos numéricos enteros, serán convertidos a `int`, por ejemplo:

```csharp
using static System.Console;

byte a = 128;
WriteLine((a).GetType());     // System.Byte
WriteLine((a + 2).GetType()); // System.Int32
```

La opción de compilación `CheckForOverflowUnderflow`, activa o desactiva si se debe vigilar el desbordamiento, por arriba o por abajo, de una operación aritmética. Cuando está activada, si al realizar una operación se supera el límite del rango de valores del tipo utilizado, se lanzará una excepción `OverflowException`. Con los operadores `checked` y `unchecked` podemos activar o desactivar este comportamiento. Por ejemplo:

```csharp
using static System.Console;

var a = double.MaxValue;
try {
    checked {
        WriteLine(unchecked((int) a));
        WriteLine((int) a);
    }
} catch (System.OverflowException e) {
    WriteLine(e.Message);
}
```

El primer *casting* no dará error, pero el segundo sí y saltará al bloque del `catch`. La sintaxis de estos operadores permite una expresión entre paréntesis (`checked(expresión)`) o un bloque entre llaves (`checked { expresiones }`).

### Tipos y objetos

El siguiente bloque son operadores básicos para manipular objetos:

| Operación | Descripción |
|:---------:|:-----------:|
| `X.Y` | Acceso al miembro `Y` de `X`. |
| `X[Y]` | Acceso al elemento `Y` en `X`. |
| `X()` | Invocación de la función `X`. |
| `(T)X` | *Casting* para convertir el resultado de `X` al tipo `T`. |
| `X as T` | Convierte el tipo del resultado de `X` a `T`. Si no se puede devuelve `null`, por ello sólo se puede aplicar a tipo por referencia. |

Este bloque son operadores relacionados con la comprobación de referencias nulas:

| Operación | Descripción |
|:---------:|:-----------:|
| `X?.Y` | Acceso condicional a un miembro cuando `X` no es `null`. |
| `X?[Y]` | Acceso condicional a un elemento cuando `X` no es `null`. |
| `X ?? Y` | Devuelve `X` si no es `null`, en caso contrario devuelve `Y`. |
| `X!` | Permite saltarse las restricciones del modo *nullable*. Es un modo para tipos por referencia, que obliga al compilador dar un aviso si cree que hay una posibilidad de que ocurra una `NullReferenceException`, al intentar acceder al contenido de `X`. |

Estos operadores permiten un acceso avanzado a elementos de un contenedor:

| Operación | Descripción |
|:---------:|:-----------:|
| `^X` | Índices negativos, para acceder a los elementos desde el final del contenedor. El valor de la expresión `X` ha de ser un número entero. Por ejemplo, `^1` sería el último elemento. |
| `X..Y` | Rango de índices, para acceder a los elementos de `X` hasta `Y-1`. El valor de las expresiones `X` e `Y` han de ser números enteros o índices negativos. |

### Punteros

El lenguaje C# permite acceso a la memoria a bajo nivel mediante punteros, para poder trabajar con código nativo. Sin embargo, no es recomendable su uso, salvo que se necesite comunicarse el programa con bibliotecas escritas en código nativo. El código que utiliza punteros debe delimitarse por un bloque `unsafe` y activar la opción de compilación para ello. Estos son los operadores disponibles para punteros:

| Operación | Descripción |
|:---------:|:-----------:|
| `X->Y` | Acceso al miembro `Y` de `X`. |
| `&X` | Dirección de `X` en la memoria. |
| `*X` | Contenido apuntado por `X` en la memoria. |

### Especiales

Estos son operadores especiales del lenguaje:

| Operación | Descripción |
|:---------:|:-----------:|
| `await` | Espera asíncrona para el resultado de una tarea. |
| `default` | Devuelve el valor por defecto para un tipo. Cuando el compilador es capaz de inferir el tipo de la expresión, se puede usar `default` en lugar de `default(Tipo)`. |
| `delegate` | Permite definir funciones anónimas. |
| `nameof` | Devuelve como una cadena de texto el nombre de un elemento (variable, tipo o miembro). Se resuelve en tiempo de compilación. |
| `new` | Reserva espacio en la memoria para un objeto, ya sea un tipo por valor (en la pila) o un tipo por referencia (en el montículo). Cuando el compilador es capaz de inferir el tipo de la expresión, se puede usar `new` en lugar de `new Tipo`. |
| `sizeof` | Da el tamaño que ocupa en memoria un tipo por valor. Está limitado a código `unsafe`, salvo para tipos básicos, por ejemplo `sizeof(int)`. |
| `switch` | Ramificación por encaje de patrones. |
| `stackalloc` | Modificador para reservar memoria en la pila de programa. |
| `typeof` | Devuelve el tipo de un parámetro de tipo en genéricos. |
| `with` | Modificación de objetos inmutables. |
| `=>` | Operador para definir lambdas. |

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
| `X >>>= Y` | **C# 11:** Equivale a `X = X >>> Y`. |
| `X ??= Y` | Equivale a `X = X ?? Y`. |

### Precedencia

Esta es la precedencia de mayor a menor de los operadores del lenguaje:

| Categoría | Operaciones | Asociatividad |
|:----------|:-----------:|:-------------:|
| Primarios | `x.y`, `f(x)`, `a[i]`, `x?.y`, `x?[y]`, `x++`, `x--`, `x!`, `new`, `typeof`, `checked`, `unchecked`, `default`, `nameof`, `delegate`, `sizeof`, `stackalloc`, `x->y` | Izquierda |
| Unarios | `+x`, `-x`, `!x`, `~x`, `++x`, `--x`, `^x`, `(T)x`, `await`, `&x`, `*x`, `true`, `false` | Izquierda |
| Rangos | `x..y` | Izquierda |
| Sentencias | `switch`, `with` | Izquierda |
| Multiplicación | `x * y`, `x / y`, `x % y` | Izquierda |
| Adición | `x + y`, `x – y` | Izquierda |
| Desplazamiento | `x << y`, `x >> y` | Izquierda |
| Relacionales | `x < y`, `x > y`, `x <= y`, `x >= y`, `x is T`, `x as T` | Izquierda |
| Igualdad | `x == y`, `x != y` | Izquierda |
| Conjunción | `x & y` | Izquierda |
| Disyunción exclusiva | `x ^ y` | Izquierda |
| Disyunción | `x \| y` | Izquierda |
| Conjunción condicional | `x && y` | Izquierda |
| Disyunción condicional | `x \|\| y` | Izquierda |
| Nulidad | `x ?? y` | Derecha |
| Condicional | `c ? t : f` | Derecha |
| Asignación y lambas | `x = y`, `x += y`, `x -= y`, `x *= y`, `x /= y`, `x %= y`, `x &= y`, `x \|= y`, `x ^= y`, `x <<= y`, `x >>= y`, `x ??= y`, `=>` | Derecha |

## Arrays

Los [arrays](https://learn.microsoft.com/dotnet/csharp/programming-guide/arrays/) es un tipo de dato estructurado que permite declarar N elementos con un orden fijo, que se pueden acceder de forma directa mediante un índice numérico. Su sintaxis es:

$$\mathit{tipo} \texttt{[} \textcolor{red}{[} \texttt{,} \textcolor{red}{\dots} \texttt{,} \textcolor{red}{]} \texttt{]} \textcolor{red}{[} \texttt{[} \textcolor{red}{[} \texttt{,} \textcolor{red}{\dots} \texttt{,} \textcolor{red}{]} \texttt{]} \textcolor{red}{\dots} \texttt{[} \textcolor{red}{[} \texttt{,} \textcolor{red}{\dots} \texttt{,} \textcolor{red}{]} \texttt{]} \textcolor{red}{]}\ \mathit{nombre_1}\ \textcolor{red}{[} \texttt{=}\ \mathit{inicializaci\acute{o}n_1} \textcolor{red}{]}$$

$$\textcolor{red}{[} \texttt{,} \textcolor{red}{\dots} \texttt{,}\ \mathit{nombre_n}\ \textcolor{red}{[} \texttt{=}\ \mathit{inicializaci\acute{o}n_n} \textcolor{red}{]} \textcolor{red}{]} \texttt{;}$$

La *inicialización* es una expresión que devuelve la instancia del array creado, ya sea el resultado de un `new`. En este último caso la sintaxis es:

$$\texttt{new}\ \textcolor{red}{[} \mathit{tipo} \textcolor{red}{]} \texttt{[} \textcolor{red}{[} \mathit{tamaño_1} \textcolor{red}{[} \texttt{,} \textcolor{red}{\dots} \texttt{,}\ \mathit{tamaño_n} \textcolor{red}{]} \textcolor{red}{]} \texttt{]} \textcolor{red}{[} \texttt{[]} \textcolor{red}{\dots} \texttt{[]} \textcolor{red}{]} \textcolor{red}{[} \texttt{\\{}\ \mathit{valores}\ \texttt{\\}} \textcolor{red}{]}$$

Se puede usar este tipo de expresiones `new` para asignar un valor a una variable array o un parámetro de una función, no está limitado a la declaración de variables únicamente, sino que es un tipo de expresión por sí misma. Se puede prescindir del tipo y del tamaño si se indican los valores que componen a la instancia. También. Por ejemplo, veamos ejemplos de arrays unidimensionales:

```csharp
int[] a = new int[2]; // = { 0, 0 };
int[] b = new int[2] { 1, 2 };
int[] c = new int[] { 1, 2 };
int[] d = new[] { 1, 2 };
int[] e = { 1, 2 };

foo(new int[3] { 3, 2, 1 });
foo(new int[] { 3, 2, 1 });
foo(new[] { 3, 2, 1 });

int foo (int[] victim) => victim.Length;
```

Para acceder al contenido se usa el operador `[]`, indicando un valor entero positivo. Pero también podemos usar el operador `^` para indicar índices negativos que para indexar desde el final hasta el principio, así como el operador `..` para obtener un fragmento del array:

```csharp
using static System.Console;

int[] datos = { 1, 2, 3, 4, 5 };
WriteLine(datos[0]);  // 1
WriteLine(datos[^1]); // 5
var subdatos = datos[2..4];
WriteLine(subdatos[0]);  // 3
WriteLine(subdatos[^1]); // 4
```

Para poder hacer arrays de varias dimensiones, el tipo debe incorporar entre los `[]` las comas que hagan falta, para alcanzar las dimensiones necesarias. Luego en el `new` también habrán de ser indicados los tamaños, separados por comas, aunque se pueden omitir si se definen los valores de la instancia, siendo igualmente necesarias las comas. Por ejemplo:

```csharp
int[,] a = new int[2,2]; // = { { 0, 0 }, { 0, 0 } };
int[,] b = new int[2,2] { { 1, 2 }, { 3, 4 } };
int[,] c = new int[,] { { 1, 2 }, { 3, 4 } };
int[,] d = new[,] { { 1, 2 }, { 3, 4 } };
int[,] e = { { 1, 2 }, { 3, 4 } };
```

Esto crea un array "compacto", ya que toda la memoria que emplea está en un único segmento continuo, excluyendo las referencias a los objetos del tipo de los elementos. Existe otra forma de hacer arrays con varias dimensiones, que consiste en arrays "fragmentados":

```csharp
int[][] a = new int[2][]; // = { null, null };
int[][] b = new int[2][] { new[] { 1, 2 }, new[] { 3, 4, 5 } };
int[][] c = new int[][] { new[] { 0, 1, 2 }, new[] { 3, 4 } };
int[][] d = new[] { new int[] { 1, 2 }, new int[3] { 3, 4, 5 } };
int[][] e = { new int[2] { 1, 2 }, new int[] { 3, 4, 5 } };
```

De esta manera lo que estamos creando es un array de objetos arrays. Por lo tanto, la memoria de cada celda de la matriz no es continua, sino que está dividida en segmentos esparcidos por la memoria. Una ventaja que trae esta forma, es que podemos tener elementos de diferentes tamaños, cosa que con la forma compacta no se podría.

> Además de los arrays, C# tiene diferentes tipos contenedores de datos, que se pueden encontrar en el espacio de nombres [`System.Collections.Generic`](https://learn.microsoft.com/dotnet/api/system.collections.generic) y en [`System.Collections`](https://learn.microsoft.com/dotnet/api/system.collections). Igual que hemos visto con los arrays, estos tipos de datos se pueden inicializar su contenido:
> 
> ```csharp
> // Forma estándar para tipos con método Add():
> var lista = new List<int> { 1, 2, 3 };
> var dic1 = new Dictionary<int, string> {
>     { 1, "uno" }, { 2, "dos" }, { 3, "tres" }
> };
> // Forma alternativa para tipos con indexadores:
> var dic2 = new Dictionary<int, string> {
>     [1] = "uno", [2] = "dos", [3] = "tres"
> };
> ```

## Funciones

Una función es un bloque de código con nombre, que podemos parametrizar, para obtener diferentes resultados. Para definir una se utiliza la siguiente sintaxis:

$$\textcolor{red}{\\{} \mathit{tipo} \textcolor{red}{|} \texttt{void} \textcolor{red}{\\}}\ \mathit{nombre} \texttt{(} \textcolor{red}{[} \mathit{par\acute{a}metros} \textcolor{red}{]} \texttt{)}\ \textcolor{red}{\\{} \texttt{\\{}\ \mathit{expresiones}\ \texttt{\\}} \textcolor{red}{|} \texttt{=>}\ \mathit{expresi\acute{o}n} \texttt{;} \textcolor{red}{\\}}$$

Una función tiene un tipo de retorno, pero si no devuelve nada usará `void` como tipo del resultado. También se permite usar `dynamic` como tipo de retorno, con las implicaciones que ello tiene para la ejecución. Luego se puede tener entre cero y N parámetros, cuya sintaxis es:

$$\textcolor{red}{[} \texttt{ref} \textcolor{red}{|} \texttt{out} \textcolor{red}{|} \texttt{in} \textcolor{red}{]}\ \mathit{tipo_1}\ \mathit{nombre_1}\ \textcolor{red}{[} \texttt{=}\ \mathit{valor_1} \textcolor{red}{]} \texttt{,} \textcolor{red}{\dots} \texttt{,}\ \texttt{params}\ \mathit{tipo_n}\texttt{[]}\ \mathit{nombre_n}$$

Cada parámetro tiene que tener un tipo concreto o dinámico. También pueden tener una serie de modificadores de comportamiento, que también serán necesarios usarlos al llamar a la función, de modo que:

| Llamada | Descripción |
|:-------:|:------------|
| `f(x)` | `x` se pasa por valor. |
| `f(ref x)` | `x` se pasa por referencia. |
| `f(out x)` | `x` recibe por referencia un resultado. |
| `f(in x)` | `x` se pasa por referencia en modo sólo lectura. |

Por la naturaleza de estos modificadores, es necesario usar una variable como argumento en la llamada. El motivo de obligar a pasar algo como referencia, se debe a que los tipos por valor se pasan siempre por copia y sus modificaciones se pierden al salir del método. Del mismo modo, si queremos reasignar una variable de un tipo por referencia, dentro del método, tendríamos el mismo problema:

```csharp
using static System.Console;

void bar (string a) => a += " bar";
void foo (ref string a) => a += " foo";

string a = "a";
WriteLine(a); // a
bar(a);
WriteLine(a); // a
foo(ref a);
WriteLine(a); // a foo
```

El modificador `out` se utiliza para devolver valores, sin necesidad de que se inicialice la variable usada como argumento previamente. Es decir, con `ref` e `in`, si usamos una variable sin inicializar como argumento, el compilador nos alertará de ello. Además, con `out` podemos declarar las variables en la propia invocación de la función:

```csharp
using static System.Console;

void foo (string v, out int x, out int y) {
    x = v.Length / 10;
    y = v.Length % 10;
}

var s = "En un lugar de la Mancha...";
foo(s, out int _, out int n);
WriteLine(n);
```

Nótese que con `_` se pueden descartar valores que no nos interesen recoger.

Los parámetros, de forma opcional, pueden tener un valor por defecto, que tiene que ser una constante o un constructor de un tipo por valor. Los parámetros con los modificadores `ref` y `out` no podrán tener un valor por defecto. Cuando un parámetro tiene un valor por defecto, se lo denomina parámetro opcional y no pueden definirse delante de los parámetros no opcionales.

```csharp
using static System.Console;

void foo (int x, int y = 10) => WriteLine(x * y);

foo(5);    // 50
foo(5, 2); // 10
```

También de forma opcional, al final del todo, se puede declarar con `params` un parámetro de tipo array que permite invocaciones con un número arbitrario de argumentos:

```csharp
using static System.Console;

void foo (string name = "none", params int[] args) {
    Write(name + ": ");
    foreach (var item in args) {
        Write(item.ToString() + " ");
    }
    WriteLine();
}

foo();                // none:
foo("some", 1, 2, 3); // some: 1 2 3
```

A la hora de invocar una una función, se puede utilizar el nombre de los parámetros en la llamada. Esta herramienta puede ayudar en casos donde se tienen muchos parámetros opcionales:

```csharp
using static System.Console;

int foo (int n = 0, int a = 1, int b = 1, int c = 0) {
    return a * n * n + b * n + c;
}

WriteLine(foo(2));                   // 6
WriteLine(foo(n: 2, b: 2));          // 8
WriteLine(foo(c: 10, n: 2));         // 16
WriteLine(foo(n: 1, 2, c: 3, b: 4)); // 9
```

Se pueden mezclar argumentos con nombre y posicionales, siempre que se respeten las posiciones para los parámetros con nombres, que estén anteriores a los otros parámetros indicados posicionalmente. Es decir, en la última llamada no podemos hacer `foo(c: 3, 2, n: 1, b: 4)`, aunque se esté presuntamente respetando la posición del parámetro `a`, porque el compilador realmente ignora los nombres de todos los argumentos que haya previos a un argumento posicional.

La sentencia `return` se utiliza para devolver un valor del tipo de retorno indicado. En el caso del último ejemplo se devolvía un número entero. En funciones con `void` como retorno, se pude utilizar `return;` para salir en cualquier punto de la ejecución de una función.

Si es necesario, se pueden anidar funciones dentro de otras funciones:

```csharp
using static System.Console;

int fact (int n) {
    static int f (int v, int r) =>
        (v <= 1) ? r : f(v - 1, r * v);
    return f(n, 1);
}

WriteLine(fact(3)); // 6
WriteLine(fact(4)); // 24
WriteLine(fact(5)); // 120
```

Las funciones de una sola expresión con `=>` no requieren de la sentencia `return` para devolver un valor, se deduce del tipo de retorno que lo harán. Además, el modificador `static` sirve para evitar que `f` pudiera acceder a variables que están fuera de su ámbito, algo que puede ser útil para que nos avise el compilador por si nos equivocamos sin querer.

Por último, la firma de una función consiste en la cabecera de su declaración, es decir, el tipo de retorno, el nombre, el número de parámetros y sus tipos. Esto es importante porque existen mecanismos que dependen de la firma de una función, sin definir su cuerpo, para trabajar.

## Sentencias de control

Esta sección cubre las sentencias de control básicas del lenguaje. El resto de sentencias más avanzadas serán analizadas en otras secciones más específicas.

### Condicionales

La primera sentencia de control es el `if`-`else`, cuya sintaxis es la siguiente:

$$\texttt{if}\ \texttt{(} \mathit{condici\acute{o}n} \texttt{)}\ \mathit{bloque_{true}}\ \textcolor{red}{[} \texttt{else}\ \mathit{bloque_{false}} \textcolor{red}{]}$$

Recordemos que un bloque puede ser una sentencia terminada con punto y coma (`expresión;`) o un bloque de sentencias delimitado por llaves (`{ expresiones }`). Si la condición, que ha de ser una expresión booleana, se evalúa a `true`, se ejecutará el primer bloque, si no se ejecutará el segundo si está definido.

```csharp
using static System.Console;

Write("A = ");
int a = int.Parse(ReadLine());
Write("B = ");
int b = int.Parse(ReadLine());

if (a == b) {
    WriteLine("A y B son iguales.");
} else if (a < b) {
    WriteLine("A es menor que B.");
} else {
    WriteLine("A es mayor que B.");
}
```

### Patrones

La sentencia de control `switch` permite evaluar una expresión y ejecutar un bloque haciendo un ajuste de patrones con las diferentes cláusulas definidas. Su sintaxis es:

$$\begin{array}{l}
\texttt{switch}\ \texttt{(} \mathit{expresi\acute{o}n} \texttt{)}\ \texttt{\\{}
\\\\[0.5em] \qquad \textcolor{red}{[} \texttt{case}\ \mathit{patr\acute{o}n_1}\ \textcolor{red}{[} \texttt{when}\ \mathit{condici\acute{o}n_1} \textcolor{red}{]} \texttt{:}\ \mathit{expresiones_1} \textcolor{red}{]}
\\\\[0.5em] \qquad\qquad \textcolor{red}{\vdots}
\\\\[0.5em] \qquad \textcolor{red}{[} \texttt{case}\ \mathit{patr\acute{o}n_n}\ \textcolor{red}{[} \texttt{when}\ \mathit{condici\acute{o}n_n} \textcolor{red}{]} \texttt{:}\ \mathit{expresiones_n} \textcolor{red}{]}
\\\\[0.5em] \qquad \textcolor{red}{[} \texttt{default:}\ \mathit{expresiones} \textcolor{red}{]}
\\\\[0.5em] \texttt{\\}}
\end{array}$$

Dependiendo del valor de la *expresión*, se va buscando en orden una cláusula `case` que encaje su patrón con el valor y su condición asociada. La primera que encaje será el punto de entrada de la ejecución, ejecutando sus expresiones hasta encontrar la sentencia `break` al final de dicho bloque, pues de lo contrario el compilador dará error. Si no se encaja con ninguna cláusula, se ejecutará la cláusula `default` de estar definida.

> Si en lugar de salir del `switch` con un `break`, queremos saltar a otra cláusula, se puede usar la sentencia `goto` para lograrlo. Las dos variantes disponibles son `goto default` y `goto case valor`. No se permite usar con `goto case` nada que no sea un valor constante. También se puede evitar terminar con `break` si se utiliza una sentencia de salto (`return`, `throw`, `continue`, `goto etiqueta`).

También tenemos disponible la expresión `switch`, cuya sintaxis es:

$$\mathit{expresi\acute{o}n}\ \texttt{switch}\ \texttt{\\{}\ \mathit{patr\acute{o}n_1}\ \texttt{=>}\ \mathit{expresi\acute{o}n_1} \textcolor{red}{[} \texttt{,} \textcolor{red}{\dots} \texttt{,}\ \mathit{patr\acute{o}n_n}\ \texttt{=>}\ \mathit{expresi\acute{o}n_n} \textcolor{red}{]}\ \texttt{\\}}$$

Es algo más limitada que la sentencia `switch` en cuanto al cuerpo de las cláusulas, pero permite todas las categorías de patrones que hay. Por ejemplo, para crear la cláusula por defecto usaríamos `_ => expresión`, mientras que `case _:` interpreta el guion bajo como una variable y no como un patrón.

El patrón más básico que existe es usar valores constantes, ya sean constantes definidas, valores enumerados o literales (números, letras, cadenas, `true`, `false` o `null`). Luego tenemos [patrones](https://learn.microsoft.com/dotnet/csharp/language-reference/operators/patterns) más avanzados como:

| Categoría | Ejemplo | Descripción |
|:---------:|:-------:|:------------|
| Tipos | `System.Byte`<br/>`int _` | Comprueba si el valor pertenece al tipo. |
| Declaración | `char X`<br/>`var Y` | Comprueba si el valor pertenece al tipo, declarando la variable `X` en el ámbito en caso afirmativo. |
| Relacionales | `> 0`<br/>`<= 10` | Comprueba el valor en relación a otro valor constante usando los operadores `<`, `>`, `<=` y `>=`. |
| Lógicos | `not null`<br/>`int and > 0` | Permiten crear patrones más complejos con los operadores lógicos `not`, `and` y `or`, siendo este su orden de prioridad en la evaluación. Estos operadores sólo se usan en patrones. |
| Miembros | `{ Year: 2002, Month: 12 }` | Comprueba si miembros del valor encajan con los patrones indicados. |
| Posicional | `(true, _)`<br/>`(> 10, not null)` | Comprueba si el valor encaja con un tipo tupla (ya sea por valor directo o por usar el método `Deconstruct`) y si los valores de los componentes de esta encajan con los patrones indicados. |
| Descarte | `_` | Se descarta el valor en la posición indicada. |
| Paréntesis | `not (1 or 2)` | Permite cambiar el orden de evaluación del patrón. |

En principio, el sistema es suficientemente flexible como para combinar las diferentes categorías de patrones entre sí. La excepción a esto último son declaración de variables, que sí permite combinarlo con patrones de miembros, posicionales y de descarte, pero no con los demás.

> En **C# 10** se permite más flexibilidad con los patrones de miembros, como se puede observar en el siguiente ejemplo:
> 
> ```csharp
> bool TestCS9 (Bar value) =>
>     value is { A: { N: > 1 }, B: { M: <= 1 } }
>           or { A: { M: < 1 }, B: { N: >= 1 } };
>
> bool TestCS10 (Bar value) =>
>     value is { A.N: > 1, B.M: <= 1 }
>           or { A.M: < 1, B.N: >= 1 };
>
> record Foo(int N, int M);
> record Bar(Foo A, Foo B);
> ```
> 
> Luego en **C# 11** se han añadido patrones para arrays y listas, pudiendo indicar con `[]` los patrones de la secuencia separados por comas, por ejemplo. `[> 1, var s, _, ..]`. El patrón `..` sirve para indicar un número arbitrario (cero o muchos) de elementos en la secuencia, por ejemplo, `[_, _, ..]` es un patrón que encaja con secuencias que tengan como mínimo dos elementos.

Por último tenemos el operador `is`, que nos permite comprobar si una expresión cumple un patrón. Su sintaxis es:

$$\mathit{expresi\acute{o}n}\ \texttt{is}\ \mathit{patr\acute{o}n}$$

Este primer ejemplo muestra el uso de las expresiones `is` y `switch`:

```csharp
string Foo (object v) {
    if (v is System.DateTime { Month: var m })
        return m switch {
            >= 3 and <= 5 => "primavera",
            >= 6 and <= 8 => "verano",
            >= 9 and <= 11 => "otoño",
            12 or 1 or 2 => "invierno",
            _ => "error"
        };
    else
        return "error";
}
```

Y con este segundo ejemplo vemos la sentencia `swicth`, usando diferentes ejemplos de patrones:

```csharp
void Bar (object v) {
    switch (v) {
        case 0:
            WriteLine("Cero");
            break;
        case 1:
        case 2:
            WriteLine("Uno o dos");
            break;
        case (string { Length: < 1 }, var y):
            WriteLine($"('', {y})");
            break;
        case var (x, y) when x != y:
            WriteLine($"({x}, {y})");
            break;
        case "hola":
            WriteLine("adios");
            break;
        case not null:
            WriteLine("No es null");
            break;
        default:
            WriteLine("Indefinido");
            break;
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

El último tipo de bucle disponible es `foreach`, que nos permite recorrer los elementos de un contenedor de datos, tales como los arrays por ejemplo. Su sintaxis es:

$$\texttt{foreach}\ \texttt{(} \mathit{tipo}\ \mathit{nombre}\ \texttt{in}\ \mathit{contenedor} \texttt{)}\ \mathit{bloque}$$

Con este ejemplo podremos ver en acción los diferentes tipos de bucles:

```csharp
using static System.Console;

var nums = new[] { 1, 2, 3, 4 };
string respuesta;
do {
    var i = 0;
    Write("While: ");
    while (i < nums.Length) {
        Write($"{nums[i]} ");
        ++i;
    }
    WriteLine();

    Write("For: ");
    for (int j = 0; j < nums.Length; j++) {
        Write($"{nums[j]} ");
    }
    WriteLine();

    Write("Foreach: ");
    foreach (var n in nums) {
        Write($"{n} ");

    }
    WriteLine();

    WriteLine("¿Salir? (S/N) ");
    respuesta = ReadLine().ToLower();
} while (respuesta != "s");
```

### Saltos y retornos

La primera sentencia de salto es `return`, que se utiliza para salir de una función, devolviendo un valor de forma opcional. Su sintaxis es:

$$\texttt{return}\ \textcolor{red}{[} \mathit{expresi\acute{o}n} \textcolor{red}{]} \texttt{;}$$

Después están `break` y `continue`. La primera se utiliza en bucles, o sentencias `switch`, para salir fuera de dicha sentencia que la contiene. La segunda se utiliza en bucles y, en lugar de salir de este, lo que provoca es un salto a la siguiente iteración del bucle. Su sintaxis es:

$$\texttt{break} \texttt{;}$$

$$\texttt{continue} \texttt{;}$$

Para entenderlo mejor, veamos el siguiente ejemplo:

```csharp
using static System.Console;

dynamic[] xs = new dynamic[] {
    1, 2, 3, 4, 5, 6, 7, false, 8, 9
};
foreach (var x in xs) {
    if (x is false) break;
    if (x % 2 == 0) continue;
    Write($"{x} ");
}
WriteLine();
// 1 3 5 7
```

Por último está el demonio de la programación estructurada, la sentencia maldita, la portadora de grandes tormentos de ofuscación, la que no debería ser nombrada. La sentencia `goto` se utiliza para hacer un salto incondicional a otra parte del código, que se identifica con una etiqueta. La sintaxis de esta herejía es:

$$\mathit{etiqueta} \texttt{:}$$

$$\texttt{goto}\ \mathit{etiqueta} \texttt{;}$$

El uso de `goto` no se recomienda en absoluto, ya que puede derivar en muy malas prácticas de programación. Su uso debe estar muy justificado y es preferible utilizar otras opciones antes.

### Excepciones

Las excepciones es un mecanismo del lenguaje para gestionar los errores en nuestros programas. Cuando algo falle de forma inesperada, podemos lanzar una excepción con la siguiente sintaxis:

$$\texttt{throw}\ \mathit{excepci\acute{o}n} \texttt{;}$$

Donde *excepción* debe ser un objeto cuyo tipo sea de la clase [`Exception`](https://learn.microsoft.com/dotnet/api/system.exception) o herede de la misma. Esta clase tiene como miembros destacados los siguientes:

| Miembro | Tipo | Descripción |
|:-------:|:----:|:------------|
| `Message` | `string` | Mensaje que describe el error actual. |
| `StackTrace` | `string` | Cadena de texto con la pila de llamadas realizada cuando se produjo el error actual. |
| `InnerException` | `Exception` | Devuelve la excepción causante de la excepción actual. Se utiliza para encadenar excepciones, cuando se captura una y se vuelve a lanzar dentro de otra nueva excepción. |

Una vez lanzada la excepción, por nosotros o por el sistema, tendremos que capturarla con la sentencia `try`-`catch`-`finally`, cuya sintaxis es:

$$\begin{array}{l}
\texttt{try}\ \texttt{\\{}\ \mathit{expresiones_0}\ \texttt{\\}}
\\\\[0.5em] \textcolor{red}{[} \texttt{catch}\ \texttt{(} \mathit{tipo_1}\ \textcolor{red}{[} \mathit{nombre_1} \textcolor{red}{]} \texttt{)}\ \textcolor{red}{[} \texttt{when}\ \texttt{(} \mathit{condici\acute{o}n_1} \texttt{)} \textcolor{red}{]} \texttt{\\{}\ \mathit{expresiones_1}\ \texttt{\\}} \textcolor{red}{]}
\\\\[0.5em] \qquad\qquad \textcolor{red}{\vdots}
\\\\[0.5em] \textcolor{red}{[} \texttt{catch}\ \texttt{(} \mathit{tipo_n}\ \textcolor{red}{[} \mathit{nombre_n} \textcolor{red}{]} \texttt{)}\ \textcolor{red}{[} \texttt{when}\ \texttt{(} \mathit{condici\acute{o}n_n} \texttt{)} \textcolor{red}{]} \texttt{\\{}\ \mathit{expresiones_n}\ \texttt{\\}} \textcolor{red}{]}
\\\\[0.5em] \textcolor{red}{[} \texttt{catch}\ \texttt{\\{}\ \mathit{expresiones_c}\ \texttt{\\}} \textcolor{red}{]}
\\\\[0.5em] \textcolor{red}{[} \texttt{finally}\ \texttt{\\{}\ \mathit{expresiones_f}\ \texttt{\\}} \textcolor{red}{]}
\end{array}$$

Hay que tener en cuenta que `try` debe ir acompañado al menos de un `catch` o un `finally`. En caso de lanzarse una excepción, se comprobará en el orden que están definidas las cláusulas `catch`, para ejecutar el bloque de expresiones que primero encaje con el error recibido, siempre que se cumpla la condición asociada en su `when` de estar definido. Esto significa que el orden importa, por lo que si la primera es un `catch (Exception)`, todas las que vengan después quedarán tapadas por esta primera, ya que es el modelo más genérico para capturar excepciones. La forma `catch {}` equivale a `catch (Exception) {}` y por ello debe ir al final del todo, antes del `finally`. Dentro de un `catch` se puede usar `throw;`, que relanza la última excepción capturada.

La cláusula `finally` es un bloque de código que se ejecutará sin importar si se produce o no una excepción. Es una salvaguarda para poder ejecutar código que necesitemos para limpiar recursos sin liberar, por ejemplo.

En este ejemplo podemos ver un manejo básico de las excepciones:

```csharp
using System;
using static System.Console;

try {
    WriteLine("Hola");
    div(10, 0);
} catch(Exception e) {
    WriteLine(e.Message);
    WriteLine(e.StackTrace);
} finally {
    WriteLine("Adios");
}

int div (int x, int y) {
    if (y == 0) {
        throw new Exception("¡División entre cero!");
    } else {
        return (int) x / y;
    }
}
```

### Recursos

La sentencia `using` tiene la misión de controlar la limpieza de recursos, de aquellos tipos que implementan la interfaz [`System.IDisposable`](https://learn.microsoft.com/dotnet/api/system.idisposable). Su sintaxis es alguna de las siguientes formas:

$$\texttt{using}\ \texttt{(} \mathit{tipo}\ \mathit{nombre}\ \texttt{=}\ \mathit{expresi\acute{o}n} \texttt{,} \textcolor{red}{\dots} \texttt{)}\ \mathit{bloque}$$

$$\texttt{using}\ \mathit{tipo}\ \mathit{nombre}\ \texttt{=}\ \mathit{expresi\acute{o}n} \texttt{,} \textcolor{red}{\dots} \texttt{;}$$

La primera forma delimita el ámbito de la variable creada al bloque indicado, mientras que la segunda delimita el ámbito de la variable al que contiene la sentencia `using`. Se pueden declarar varias variables separadas por comas. Cuando se salga del ámbito, se ejecutará el método `Dispose()` del objeto instanciado, siempre que implemente la interfaz `IDisposable`. Por ejemplo:

```csharp
using System.IO;
using static System.Console;

string data = "uno\ndos\ntres\ncuatro";
using (var reader = new StringReader(data)) {
    string item;
    do {
        item = reader.ReadLine();
        WriteLine(item);
    } while (item != null);
}
```

## Tipos de usuario

El lenguaje C# tiene una jerarquía de tipos con la que tenemos que trabajar si queremos crear tipos de datos propios para nuestros proyectos. Estas son las clases que tienen un significado especial para el lenguaje:

| Clase | Descripción |
|:-----:|:------------|
| [`System.Object`](https://learn.microsoft.com/dotnet/api/system.object) | Clase de la que heredan todas las clases del lenguaje. La palabra reservada `object` es un sinónimo de esta clase. |
| [`System.String`](https://learn.microsoft.com/dotnet/api/system.string) | Clase que representa las cadenas de texto. |
| [`System.ValueType`](https://learn.microsoft.com/dotnet/api/system.valuetype) | Clase base de los tipos por valor. |
| [`System.Enum`](https://learn.microsoft.com/dotnet/api/system.enum) | Clase base de los tipos enumeración. |
| [`System.Array`](https://learn.microsoft.com/dotnet/api/system.array) | Clase base de los tipos array. |
| [`System.Delegate`](https://learn.microsoft.com/dotnet/api/system.delegate) | Clase base de los tipos delegados, que representan funciones anónimas en el lenguaje. |
| [`System.Exception`](https://learn.microsoft.com/dotnet/api/system.exception) | Clase base para los tipos de excepciones. |

Por significado especial entendemos que su semántica varía con respecto otras clases, a la hora de compilar nuestros programas. Por ejemplo, una clase normal, que hereda de `object`, será un tipo por referencia, que se almacenará en la memoria del montículo; pero si hereda de `ValueType` su semántica cambiará y pasará a almacenarse en la pila del programa las instancias de dicho tipo.

### Visibilidad

Los elementos que definamos en nuestro programa, pueden estar contenidos en un espacio de nombre o dentro de un tipo. Esto hace que sea importante tener en cuenta cuál es la visibilidad de dicho elemento con respecto al resto. Por ello existen los siguientes modificadores de visibilidad:

| Modificador | Descripción |
|:-----------:|:------------|
| `public` | El tipo/miembro es visible por todos. |
| `private` | El miembro es visible sólo en el tipo donde está definido. |
| `protected` | El miembro es visible sólo en el tipo donde está definido y en los herederos del tipo. |
| `internal` | El tipo/miembro es visible sólo por otros tipos del mismo ensamblado. |
| `protected internal` | El miembro no es visible para otros tipos, que no heredan del tipo donde está definido, en otros ensamblados. |
| `private protected` | El miembro es visible sólo en el tipo donde está definido y en los herederos del tipo que estén en el mismo ensamblado. |

Téngase en cuenta que sólo se puede elegir un único modificador de visibilidad a la hora de definir un tipo o miembro. A modo de resumen tenemos esta tabla relativa a la ubicación de aquel que invoca:

| Ubicación | `public` | `protected internal` | `protected` | `internal` | `private protected` | `private` |
|:---------:|:--------:|:--------------------:|:-----------:|:----------:|:-------------------:|:---------:|
| Dueño | Sí | Sí | Sí | Sí | Sí | Sí |
| Hijo (mismo ensamblado) | Sí | Sí | Sí | Sí | Sí | No |
| Tipo (mismo ensamblado) | Sí | Sí | No | Sí | No | No |
| Hijo (otro ensamblado) | Sí | Sí | Sí | No | No | No |
| Tipo (otro ensamblado) | Sí | No | No | No | No | No |

Para tipos, definidos en un espacio de nombres, se utilizará `internal` por defecto, si no se indica modificador alguno de visibilidad. Pero para todo elemento, definido dentro de un tipo, se utilizará `private` por defecto, incluso si es un tipo anidado en otro tipo.

### Comportamiento

Además de los modificadores de visibilidad, los elementos que vamos definiendo pueden tener otros modificadores de comportamiento, para activar o no ciertas semánticas. Tenemos como modificadores de comportamiento los siguientes:

| Modificador | Descripción |
|:-----------:|:------------|
| `abstract` | La definición es abstracta, es decir, su implementación corre a cargo de los tipos herederos. |
| `async` | La definición es asíncrona, para poder ejecutarla de forma concurrente, pudiendo hacerlo en paralelo a otras. |
| `extern` | La definición es externa, su implementación está definida de forma nativa. |
| `new` | La definición oculta a otra definición del tipo padre. |
| `override` | La definición sobrescribe otra en un tipo padre. |
| `partial` | La definición es parcial, que se pueden usar diferentes ficheros para desarrollar su implementación. |
| `readonly` | La definición es de sólo de lectura tras inicializarla, ya sea en la propia definición o en el constructor del tipo al que pertenece. |
| `sealed` | La definición es sellada, no se podrá sobrescribir su implementación mediante herencia. |
| `static` | La definición es estática, no pertenecerá a las instancias de un tipo. Si un tipo es estático, todos sus miembros también lo serán. |
| `unsafe` | La definición es insegura, para poder usar punteros. |
| `virtual` | La definición es virtual, es decir, que podrá ser sobrescrita por los tipos herederos. |
| `volatile` | La definición es volátil, es decir, se puede acceder a ella simultáneamente desde diferentes hilos de ejecución. |

No todos los modificadores de comportamiento se pueden emplear para cualquier tipo de definición, por ello veremos en cada elemento cuáles están soportados o no.

### Clases

La sintaxis para definir una [clase](https://learn.microsoft.com/dotnet/csharp/language-reference/keywords/class) es la siguiente:

$$\textcolor{red}{[} \mathit{modificadores} \textcolor{red}{]}\ \texttt{class}\ \mathit{nombre}\ \textcolor{red}{[} \texttt{:} \mathit{padre\ e\ interfaces} \textcolor{red}{]}\ \texttt{\\{}\ \mathit{definiciones}\ \texttt{\\}}$$

Los modificadores de visibilidad disponibles para las clases son `public` e `internal`. También tenemos como modificadores de comportamiento los siguientes:

| Modificador | Descripción |
|:-----------:|:------------|
| `static` | Clase estática, todos sus miembros serán estáticos. |
| `abstract` | Clase abstracta, alguno de sus métodos es abstracto, es decir, no está definido y lo tendrán que definir sus clases hijas. |
| `sealed` | Clase sellada, ninguna otra clase podrá heredar de ella. |
| `partial` | Clase parcial, que sus elementos están definidos en uno o varios ficheros de código fuente. Este modificador se suele utilizar para herramientas que generan código automático. |
| `unsafe` | Clase con código inseguro, para poder usar punteros. |

Algunos modificadores no se pueden combinar entre sí, ya que provocaría una situación contradictoria. Por ejemplo, no una clase no puede ser estática y abstracta a la vez.

La [herencia](https://es.wikipedia.org/wiki/Herencia_%28inform%C3%A1tica%29) en C# sólo nos permite heredar de un único padre, que por defecto será `object`. Lo que sí podemos es heredar de múltiples interfaces, que veremos más adelante.

### Campos

Los campos son variables que pertenecen a una clase. Para definir un campo se utiliza la siguiente sintaxis:

$$\textcolor{red}{[} \mathit{modificadores} \textcolor{red}{]}\ \mathit{tipo}\ \mathit{nombre_1}\ \textcolor{red}{[} \texttt{=}\ \mathit{expresi\acute{o}n_1} \textcolor{red}{]} \textcolor{red}{[} \texttt{,} \textcolor{red}{\dots} \texttt{,}\ \mathit{nombre_n}\ \textcolor{red}{[} \texttt{=}\ \mathit{expresi\acute{o}n_n} \textcolor{red}{]} \textcolor{red}{]} \texttt{;}$$

Además de los modificadores de visibilidad, los de comportamiento disponibles son los siguientes:

| Modificador | Descripción |
|:-----------:|:------------|
| `static` | La variable será un campo estático. |
| `readonly` | La variable es sólo de lectura una vez es inicializada, ya sea en su definición o en el constructor. |
| `new` | La variable oculta a otra variable de la clase padre. |
| `volatile` | La variable es volátil, es decir, se puede acceder a ella simultáneamente desde diferentes hilos de ejecución. |
| `unsafe` | La variable es insegura, para poder usar punteros. |

También se puede declarar constantes como campos con `const`, en cuyo caso es obligatorio inicializar su valor, y los únicos modificadores disponibles son los de visibilidad.

### Métodos

Los métodos son funciones que pertenecen a una clase. Para definir un método se utiliza la siguiente sintaxis:

$$\textcolor{red}{[} \mathit{modificadores} \textcolor{red}{]}\ \textcolor{red}{\\{} \mathit{tipo} \textcolor{red}{|} \texttt{void} \textcolor{red}{\\}}\ \mathit{nombre} \texttt{(} \textcolor{red}{[} \mathit{par\acute{a}metros} \textcolor{red}{]} \texttt{)} \textcolor{red}{\\{} \texttt{\\{}\ \mathit{expresiones}\ \texttt{\\}} \textcolor{red}{|} \texttt{=>}\ \mathit{expresi\acute{o}n} \texttt{;} \textcolor{red}{|} \texttt{;} \textcolor{red}{\\}}$$

Además de los modificadores de visibilidad, los de comportamiento disponibles son los siguientes:

| Modificador | Descripción |
|:-----------:|:------------|
| `static` | La función será un método estático. |
| `partial` | La función es un método parcial, dentro de una clase parcial, por lo tanto puede aparecer la firma de la función en otro fichero del fichero donde esté su implementación. |
| `abstract` | La función será un método abstracto, es decir, que no tiene implementación en esa clase y serán las clases hijas las que implementen el método. Sólo las clases abstractas pueden tener métodos abstractos. |
| `virtual` | La función será un método virtual, es decir, que podrá ser sobrescrito por un método en las clases hijas. |
| `override` | La función será un método que sobrescribe un método abstracto o virtual de la clase padre. |
| `sealed` | La función será un método sellado, es decir, no se podrá seguir sobrescribiendo dicho método en las clases hijas de la actual. Es por ello que, este modificador, se tiene que utilizar junto a `override` para poder usarlo. |
| `new` | La función oculta a otra función de la clase padre. |
| `async` | La función es asíncrona, para poder ejecutarla de forma concurrente, pudiendo hacerlo en paralelo a otras funciones. |
| `extern` | La función es externa, su código está definido de forma nativa. |
| `unsafe` | La función es insegura, para poder usar punteros. |

Dentro de las funciones no estáticas de una clase, se podrá utilizar la palabra reservada `this`, que representa la instancia actual que invoca la función. Puede ser útil para hacer explícito los elementos que pertenecen a la instancia de la clase, o simplemente para resolver conflictos entre nombres, cuando un parámetro tiene el mismo nombre que un campo o propiedad.

También existe la palabra reservada `base`, que representa los elementos de la clase padre, para acceder a ellos en caso de haber quedado ocultos por los elementos de la clase actual.

El lenguaje permite tener varias funciones con el mismo nombre, siempre que su firma sea distinta, es decir, que varíe la cantidad de parámetros y/o el tipo de alguno de sus parámetros:

```csharp
using static System.Console;

WriteLine(Bar.Foo(3));  // 4
WriteLine(Bar.Foo(3f)); // 1,5

public class Bar {
    static public int Foo (int x) => x + 1;
    static public float Foo (float x) => x * 0.5f;
}
```

Al sobrescribir una función, podremos modificar el tipo `X` de retorno siempre que el nuevo tipo `Y` sea [covariante](https://es.wikipedia.org/wiki/Covarianza_y_contravarianza_%28ciencias_de_la_computaci%C3%B3n%29) con respecto a `X`, es decir, que `Y` sea subtipo de `X`. Esto es útil si por ejemplo queremos hacer una función de clonación:

```csharp
using static System.Console;

B v1 = new B { X = 2, Y = 3 };
B v2 = v1.Clone();
WriteLine($"{v2.X}, {v2.Y}");

class A {
    public int X = 1;
    public virtual A Clone () =>
        new A { X = this.X };
}

class B : A {
    public int Y = 1;
    public override B Clone () =>
        new B { X = this.X, Y = this.Y };
}
```

### Métodos especiales

El primer método especial es el constructor de la clase, que es la función que se invoca cuando usamos el operador `new` crear una nueva instancia de la clase. Su sintaxis es:

$$\textcolor{red}{[} \mathit{modificadores} \textcolor{red}{]}\ \mathit{nombre} \texttt{(} \textcolor{red}{[} \mathit{par\acute{a}metros} \textcolor{red}{]} \texttt{)} \textcolor{red}{[} \texttt{:} \textcolor{red}{\\{} \texttt{base} \textcolor{red}{|} \texttt{this} \textcolor{red}{\\}} \texttt{(} \textcolor{red}{[} \mathit{par\acute{a}metros} \textcolor{red}{]} \texttt{)} \textcolor{red}{]}$$

$$\textcolor{red}{\\{} \texttt{\\{}\ \mathit{expresiones}\ \texttt{\\}} \textcolor{red}{|} \texttt{=>}\ \mathit{expresi\acute{o}n} \texttt{;} \textcolor{red}{\\}}$$

Donde *modificadores* son los modificadores de visibilidad del constructor, ya que no hace falta que sea público siempre. El *nombre* tiene que ser el mismo que el nombre del tipo. Puede tener cero o más parámetros de entrada, como las funciones normales. La palabra reservada `base`, en este contexto, se utiliza para invocar a un constructor de la clase padre; mientras que `this` se utiliza para invocar a otro constructor de la misma clase.

> Se puede llegar a usar el modificador `static`, para definir un constructor para la parte estática de la clase, pero es obligatorio que sea también `public` y sólo puede existir un constructor estático, que además no podrá tener parámetros. Tampoco podrá usar `base` y `this`, ya que son "variables" relativas a los objetos instanciados y no a la parte estática de un tipo.
> 
> Otros modificadores de comportamiento admitidos son `unsafe` y `extern`, para cuando se quiere construir un tipo que utiliza código no manejado o nativo.

Veamos algunos ejemplos de construcción de objetos:

```csharp
using static System.Console;

var ps = new Point[] {
    new Point(),          // (0, 0)
    new Point{},          // (0, 0)
    new Point(1),         // (1, 0)
    new Point(1, 2),      // (1, 2)
    new Point(y:2),       // (0, 2)
    new Point{X=3, Y=4},  // (3, 4)
    new Point(5) {Y=6},   // (5, 6)
    new Point(y:5) {X=6}, // (6, 5)
    new Point{X=7},       // (7, 0)
    new Point{Y=8},       // (0, 8)
};

foreach (var p in ps) WriteLine($"{p}");

class Point {
    public int X, Y;
    public Point (int x = 0, int y = 0) {
        X = x;
        Y = y;
    }
    public override string ToString () {
        return $"({X}, {Y})";
    }
}
```

Podemos tener parámetros opcionales y combinarlo con la inicialización de objetos, usando las llaves. La inicialización de objetos será posible, siempre que exista la posibilidad de tener un constructor con cero argumentos, ya sea porque exista uno con cero parámetros o porque tenga todos los parámetros opcionales.

> Si no se define ningún constructor en una clase, se genera con el compilador automáticamente uno por defecto sin parámetros, que inicializa los campos y propiedades a su valores por defecto (`default`), salvo que tengan un valor inicial en su definición.

El segundo método especial es el destructor de la clase, que es la función que se invoca cuando el objeto va a ser eliminado de la memoria por el recolector de basura. Su sintaxis es:

$$\texttt{\\~{}}\ \mathit{nombre} \texttt{(} \texttt{)} \textcolor{red}{\\{} \texttt{\\{}\ \mathit{expresiones}\ \texttt{\\}} \textcolor{red}{|} \texttt{=>}\ \mathit{expresi\acute{o}n} \texttt{;} \textcolor{red}{\\}}$$

No tiene ni modificadores (excepto `unsafe`, para manejar punteros), ni parámetros, ni tampoco se puede invocar. Esto es porque en realidad el compilador transforma esta función al siguiente código:

```csharp
protected override void Finalize() {
    try {
         // Expresiones del destructor...
    } finally {
         base.Finalize();
    }
}
```

El método [`Finalize`](https://learn.microsoft.com/dotnet/api/system.object.finalize) es uno de los métodos de la clase `object`, que se pueden sobrescribir por sus hijas. Este es el método que es invocado por el recolector de basura, antes de eliminarlo de la memoria. Al final, este método se utiliza para controlar la eliminación de recursos abiertos por el objeto, tales como ficheros, por ejemplo. Es decir, si cuando se va a borrar el objeto, se nos ha olvidado cerrar un fichero, con el destructor nos podemos encargar de controlar que se cierre correctamente.

> Debido al no determinismo del recolector de basura, no podremos saber cuándo, ni en qué orden, se invoque a los métodos `Finalize` de los objetos pendientes de ser eliminados. Para poder controlar la limpieza de recursos, podemos utilizar las interfaces [`System.IDisposable`](https://learn.microsoft.com/dotnet/api/system.idisposable) y [`System.IAsyncDisposable`](https://learn.microsoft.com/dotnet/api/system.iasyncdisposable). Además, sentencias como `using`, invocan al método `Dispose` automáticamente, si la interfaz `IDisposable` está implementada. En caso de haberse invocado la limpieza de recursos con `Dispose`, podemos con la función [`GC.SuppressFinalize(object)`](https://learn.microsoft.com/dotnet/api/system.gc.suppressfinalize) eliminar al objeto de la cola encargada de llamar al método `Finalize`, para evitar que se ejecute de nuevo el código de limpieza de recursos.

El siguiente método especial es el deconstructor de la clase, que es la función que se invoca cuando el objeto es asignado a una tupla, para descomponer el valor en diferentes componentes. Su sintaxis es:

$$\texttt{public}\ \texttt{void}\ \texttt{Deconstruct} \texttt{(} \texttt{out}\ \mathit{tipo}\ \mathit{nombre} \texttt{,} \textcolor{red}{\dots} \texttt{)}\ \texttt{\\{}\ \mathit{expresiones}\ \texttt{\\}}$$

Por ejemplo:

```csharp
using static System.Console;

var p = new Point() { X = 1, Y = 2 };
var (a, b) = p;
WriteLine($"{a}, {b}"); // 1, 2

class Point {
    public int X, Y;
    public void Deconstruct (out int x, out int y) {
        x = X;
        y = Y;
    }
}
```

### Propiedades

Las propiedades son funciones que pertenecen a una clase, pero que actúan como si se trataran de variables de la misma. Con las funciones, que componen la propiedad, se puede controlar la lectura y la escritura de otras variables, entre otras opciones. Para definir una propiedad se utiliza la siguiente sintaxis:

$$\textcolor{red}{[} \mathit{modificadores} \textcolor{red}{]}\ \mathit{tipo}\ \mathit{nombre}\ \texttt{\\{}\ \mathit{accesores}\ \texttt{\\}}\ \textcolor{red}{[} \texttt{=}\ \mathit{expresi\acute{o}n} \texttt{;} \textcolor{red}{]}$$

La sintaxis de los *accesores* es la siguiente:

$$\textcolor{red}{[} \mathit{visibilidad} \textcolor{red}{]}\ \textcolor{red}{\\{} \texttt{get} \textcolor{red}{|} \texttt{set} \textcolor{red}{|} \texttt{init} \textcolor{red}{\\}}\ \textcolor{red}{\\{} \texttt{\\{}\ \mathit{expresiones}\ \texttt{\\}} \textcolor{red}{|} \texttt{=>}\ \mathit{expresi\acute{o}n} \texttt{;} \textcolor{red}{|} \texttt{;} \textcolor{red}{\\}}$$

Además de los modificadores de visibilidad, los modificadores de comportamiento disponibles para las propiedades son los siguientes:

| Modificador | Descripción |
|:-----------:|:------------|
| `static` | La propiedad es estática. |
| `abstract` | La propiedad es abstracta, y por lo tanto no tendrá implementación en esa clase. Serán las clases hijas las que implementen la propiedad. Sólo las clases abstractas pueden tener propiedades abstractas. |
| `virtual` | La propiedad es virtual, es decir, que podrá ser sobrescrita por un propiedad en las clases hijas. |
| `override` | La propiedad sobrescribe una propiedad abstracta o virtual de la clase padre. |
| `sealed` | La propiedad está sellada, es decir, no se podrá seguir sobrescribiendo dicha propiedad en las clases hijas de la actual. Es por ello que, este modificador, se tiene que utilizar junto a `override` para poder usarlo. |
| `new` | La propiedad oculta a otra propiedad de la clase padre. |
| `extern` | La propiedad es externa, su código está definido de forma nativa. |
| `unsafe` | La propiedad es insegura, para poder usar punteros. |

Los *accesores* tienen tres tipos posibles: `get` para obtener el valor de la propiedad, `set` para asignarle un valor e `init` para asignarle un valor sólo durante la inicialización. Se puede combinar `get` con `set` o `init`, pero no se puede definir una propiedad con estas dos últimas de forma simultanea. Dentro de los *accesores* de escritura, tenemos la palabra reservada `value`, que representa el valor que se está asignando a la propiedad:

```csharp
class Point {
    private int x, y;
    public int X {
        get { return x; }
        set { x = value; }
    }
    public int Y {
        get => y;
        set => y = value;
    }
    public Point (int x = 0, int y = 0) {
        this.X = x;
        this.Y = y;
    }
}
```

Pero también se pueden definir las propiedades de la siguiente manera:

```csharp
class Point {
    public int X { get; set; }
    public int Y { get; set; }
    public Point (int x = 0, int y = 0) {
        this.X = x;
        this.Y = y;
    }
}
```

De este modo, el compilador genera automáticamente las funciones para `get` y `set`, además de un campo privado para almacenar los valores. De esta manera, podemos expresar lo mismo que en el ejemplo anterior, de forma más sucinta.

Se puede modificar la visibilidad de un *accesor* para hacerlo más restrictivo todavía, pero nunca para hacerlo menos restrictivo:

```csharp
class Point {
    public int X { get; private set; }
    public int Y { get; private set; }
    public Point (int x = 0, int y = 0) {
        this.X = x;
        this.Y = y;
    }
}
```

Con esto podremos modificar `X` e `Y` sólo desde el interior de la clase `Point`. Con `protected` podríamos modificarlo también en clases hijas, etcétera. Pero si el objetivo es crear un tipo de datos inmutable, que no se pueda modificar, podríamos hacer lo siguiente:

```csharp
class Point {
    public int X { get; }
    public int Y { get; }
    public Point (int x = 0, int y = 0) {
        this.X = x;
        this.Y = y;
    }
}
```

Sin embargo, esto no nos permitiría utilizar la inicialización de objetos al crear la instancia con `new Point { X = 1, Y = 2 }`. Para ello tendríamos que utilizar `init` en lugar de `set`.

Por último, podemos crear una propiedad que sólo tenga como *accesor* un `get` usando la siguiente forma simplificada:

```csharp
// Dentro de la clase:
private int data;
public int Data => data;
```

### Indexadores

Los indexadores son muy similares a las propiedades, pero en su caso permite manejar un objeto de una clase como si fuera un array de una o más dimensiones. Para definirlo se utiliza la siguiente sintaxis:

$$\textcolor{red}{[} \mathit{modificadores} \textcolor{red}{]}\ \mathit{tipo}\ \texttt{this} \texttt{[} \mathit{tipo_1}\ \mathit{nombre_1} \texttt{,} \textcolor{red}{\dots} \texttt{]}\ \texttt{\\{}\ \mathit{accesores}\ \texttt{\\}}$$

La sintaxis de los *accesores* es la siguiente:

$$\textcolor{red}{[} \mathit{visibilidad} \textcolor{red}{]}\ \textcolor{red}{\\{} \texttt{get} \textcolor{red}{|} \texttt{set} \textcolor{red}{\\}}\ \textcolor{red}{\\{} \texttt{\\{}\ \mathit{expresiones}\ \texttt{\\}} \textcolor{red}{|} \texttt{=>}\ \mathit{expresi\acute{o}n} \texttt{;} \textcolor{red}{|} \texttt{;} \textcolor{red}{\\}}$$

Además de los modificadores de visibilidad, los modificadores de comportamiento disponibles para los indexadores son los mismos que los de las propiedades, exceptuando `static`, ya que un indexador no puede ser estático. Otra diferencia es que los *accesores* deberán tener un cuerpo definido, salvo que el indexador sea `abstract`. En cuanto a los tipos que podemos usar como índices no hay límites, por lo tanto podremos usar objetos de tipos `Index` y `Range` sin problemas:

```csharp
using static System.Console;

var v = new Vector(10);
v[0] = -1;
v[^1] = 10;
v[1..9] = new int[] { 1, 2, 3, 4, 5, 6, 7, 8 };
for (int i = 0; i < v.Lenght; i++) {
    WriteLine(v[i]);
}

class Vector {
    private int[] data;
    public int Lenght { get => data.Length; }
    public Vector (int size) => data = new int[size];
    public int this[int i] {
        get => data[i];
        set => data[i] = value;
    }
    public int this[System.Index i] {
        get => data[i];
        set => data[i] = value;
    }
    public int[] this[System.Range r] {
        get => data[r];
        set {
            for (int i = r.Start.Value, j = 0; i < r.End.Value; i++, j++) {
                data[i] = value[j];
            }
        }
    }
}
```

En este caso, a diferencia de las propiedades, sí podemos sobrecargar diferentes indexadores al variar los tipos de su firma. Otra posibilidad disponible, igual que con las propiedades, cuando el indexador es sólo de lectura, podemos hacer lo siguiente:

```csharp
// Dentro de la clase:
private int[] data;
public int this[int i] => data[i];
```

### La clase `object`

La clase [`System.Objet`](https://learn.microsoft.com/dotnet/api/system.object) es la raíz de todos los tipos en la jerarquía del lenguaje. Sus principales métodos son:

| Método | Modificadores | Descripción |
|:------:|:-------------:|:------------|
| `bool Equals(Object)` | `public`, `virtual` | Comprueba si el argumento es igual al objeto actual. |
| `bool Equals(Object, Object)` | `public`, `static` | Comprueba si dos objetos son iguales. |
| `void Finalize()` | `protected`, `virtual` | Realiza las operaciones de limpieza previas a ser eliminado el objeto de la memoria. |
| `int GetHashCode()` | `public`, `virtual` | Obtiene el código hash del objeto. |
| `Type GetType()` | `public` | Obtiene el tipo del objeto. |
| `object MemberwiseClone()` | `protected` | Crea una copia superficial. |
| `bool ReferenceEquals(Object, Object)` | `public`, `static` | Comprueba si dos objetos tienen la misma referencia. |
| `string ToString()` | `public`, `virtual` | Devuelve la cadena de texto que representa al objeto. |

Es común sobrescribir los métodos `Equals` y `GetHashCode`, cuando se quiere definir la semántica de igualdad de un tipo, además de sobrecargar los operadores `==` y `!=`. También el método `ToString` es habitual sobrescribirlo, para adaptarlo a la semántica real del tipo. El método `GetType` nos da una instancia de [`System.Type`](https://learn.microsoft.com/dotnet/api/system.type), que nos permite acceder a la información relativa al tipo en tiempo de ejecución, utilizando los mecanismos de la biblioteca [`System.Reflection`](https://learn.microsoft.com/dotnet/api/system.reflection).

### Delegados y lambdas

Los delegados es un mecanismo del lenguaje para crear tipos funcionales que cumplan una firma y poder así hacer referencia a diferentes funciones. Para ello se utiliza la palabra clave `delegate`, pudiendo indicar un modificador de visibilidad. Por ejemplo:

```csharp
using static System.Console;

var foo = new Foo();
Foo.Bar f = foo.Hola;
f("Tatsuro Yamashita");
f = Foo.Adios;
f("Ryūichi Sakamoto");
f = saludos;
f("Mariya Takeuchi");

void saludos (string value) => WriteLine($"Saludos: {value}");

class Foo {
    public delegate void Bar (string value);
    public string Message = "Hola";
    public void Hola (string value) => WriteLine($"{Message}: {value}");
    public static void Adios (string value) => WriteLine($"Adios: {value}");
}
```

Además, `delegate` se puede utilizar como operador para crear funciones anónimas, es decir, que no tienen nombre asociado a ellas:

```csharp
using static System.Console;

System.Action<string, string> f = delegate (string n, string v) {
    WriteLine($"{n}: {v}");
};
f("Miki Matsubara", "Stay with me!");

System.Func<string> g = delegate { return "<3"; };
f = delegate (string _, string v) {
    WriteLine($"City Pop {v}");
};
f("Van Paugam", g());
```

Los tipos genéricos [`Action`](https://learn.microsoft.com/dotnet/api/system.action) y [`Func`](https://learn.microsoft.com/dotnet/api/system.func-1) son delegados de la biblioteca estándar, para poder trabajar con funciones anónimas. Para declarar una función anónima con `delegate`, si no tiene parámetros se puede omitir los paréntesis. También podemos con el guion bajo (`_`) descartar los parámetros que no queramos usar, pudiendo incluso descartarlos todos.

Otra forma de definir una función sin nombre son las expresiones lambda, bien conocidas en el mundo de la programación funcional:

```csharp
using static System.Console;

System.Func<string, string, string> f = (a, b) => a + ": " + b;
System.Action<string> g = v => WriteLine(v);
g(f("Junko Ohashi", "56709"));
g(f("Taeko Ohnuki", "Carnaval"));
```

Las lambdas también pueden definirse su cuerpo con las llaves (`{` `}`):

```csharp
using static System.Console;

System.Func<string, string, string> f = (a, b) => {
    return a + ": " + b;
};
System.Action<string> g = v => { WriteLine(v); };
g(f("Junko Ohashi", "56709"));
g(f("Taeko Ohnuki", "Carnaval"));
```

También se pueden descartar parámetros con el guion bajo:

```csharp
using static System.Console;

System.Func<string, string, string> f = (_, _) => "Anri";
WriteLine(f("Shyness", "Boy"));
```

Se puede añadir el modificador `static` a una lambda, para evitar que se capturen por accidente variables del ámbito en el que está, haciendo que el compilador nos avise del error cometido:

```csharp
int x = 10;
System.Func<int> f = () => x;        // Ok
System.Func<int> g = static () => x; // Error con x
```

Otra curiosidad de los delegados, es que se pueden asignar varias funciones a la vez con el operador `+=` y quitarlas con `-=`:

```csharp
using static System.Console;

System.Action<string, int> f = null;
f += (v, n) => WriteLine($"{n}) Rydeen: {v}");
f += delegate (string v, int n) { WriteLine($"{n}) Tong Poo: {v}"); };
f += foo;
f("YMO", 1);
f -= foo;
f("YMO", 2);

void foo (string v, int n) => WriteLine($"{n}) Technopolis: {v}");
```

### Eventos

Los eventos son a los delegados, lo que las propiedades a los campos de una clase. Su sintaxis es la siguiente:

$$\textcolor{red}{[} \mathit{modificadores} \textcolor{red}{]}\ \texttt{event}\ \mathit{tipo}\ \mathit{nombre}\ \textcolor{red}{\\{} \texttt{;} \textcolor{red}{|} \texttt{\\{}\ \texttt{add}\ \texttt{\\{}\ \mathit{expresiones}\ \texttt{\\}}\ \texttt{remove}\ \texttt{\\{}\ \mathit{expresiones}\ \texttt{\\}}\ \texttt{\\}} \textcolor{red}{\\}}$$

De forma similar a las propiedades, si no se indica su `add` y `remove`, se generarán automáticamente durante la compilación. Estos *accesores*, además de utilizar la palabra clave `value` para hacer referencia al valor que se le está añadiendo o quitando, representan la operación `+=` y `-=` sobre una variable de tipo delegado.

Además de los modificadores de visibilidad, tenemos los siguientes de comportamiento:

| Modificador | Descripción |
|:-----------:|:------------|
| `static` | El evento es estático. |
| `abstract` | El evento es abstracto y su implementación estará en las clases hijas, por lo que no se generarán automáticamente sus *accesores* `add` y `remove`. Sólo las clases abstractas pueden tener eventos abstractos. |
| `virtual` | El evento es virtual, es decir, que podrá ser sobrescrito por un evento en las clases hijas. |
| `override` | El evento sobrescribe un evento abstracto o virtual de la clase padre. |
| `sealed` | El evento está sellado, es decir, no se podrá seguir sobrescribiendo en las clases hijas de la actual. Este modificador se tiene que utilizar junto a `override`. |
| `new` | El evento oculta a otro de la clase padre. |

A continuación un ejemplo completo manejando los eventos:

```csharp
using static System.Console;

var foo = new Foo();
foo.Saluda += () => WriteLine("Bay City");
foo.Saluda += () => WriteLine("Junko Yagami");
foo.Saludame();

var faa = new Faa();
faa.Saluda += () => WriteLine("I'm In Love");
faa.Saluda += () => WriteLine("Tomoko Aran");
faa.Saludame();

class Foo {
    public delegate void Bar ();

    private Bar saluda;

    public event Bar Saluda {
        add {
            WriteLine("Add event...");
            saluda += value;
        }
        remove {
            WriteLine("Remove event...");
            saluda -= value;
        }
    }

    public virtual void Saludame () => this.saluda();
}

class Faa : Foo {
    public new event Bar Saluda;

    public override void Saludame () => this.Saluda();
}
```

Hay que tener en cuenta, que cuando el evento opera sobre una variable delegada, como ocurre con `Foo`, no se puede invocar como una función al evento. Sí se puede invocar como una función en `Faa`, porque luego se va a generar en tiempo de compilación el código completo del evento. Esto no quiere decir que se pueda hacer `faa.Saluda()`, porque la variable delegada generada es privada a la clase `Faa`, por eso sí se puede hacer `this.Saluda()`.

### Métodos extensibles

Los métodos extensibles son funciones que pertenecen a una clase estática, pero que se aplican a otro para extender su funcionalidad sin tener que heredar del mismo. Para definir un método extensible hay que crear una función estática, cuyo primer parámetro siga la sintaxis `this tipo nombre`, por ejemplo:

```csharp
using static System.Console;

WriteLine("123".Repeat()); // 123123
WriteLine(123.Repeat(4));  // 492

static class Foo {
    public static string Repeat (this string value) {
        return value + value;
    }
    public static int Repeat (this int value, int number = 2) {
        return value * number;
    }
}
```

### Sobrecarga de operadores

Se pueden sobrecargar los siguientes operadores del lenguaje:

| Operadores | Aridad | Anotaciones |
|:----------:|:------:|:------------|
| `+`, `-`, `!`, `~`, `++`, `--`, `true`, `false` | Unaria | `true` y `false` deben sobrecargarse de forma conjunta. |
| `+`, `-`, `*`, `/`, `%`, `&`, `\|`, `^`, `<<`, `>>` | Binaria | Los operadores `&&` y `\|\|` se sobrecargan de forma implícita con `&` y `\|` respectivamente. |
| `==`, `!=`, `<`, `>`, `<=`, `>=` | Binaria | `==` con `!=`, `<` con `>` y `<=` con `>=`, deben sobrecargarse de forma conjunta. |

Para [definir la sobrecarga](https://learn.microsoft.com/dotnet/csharp/language-reference/operators/operator-overloading) se ha de crear una función estática, que utilice la palabra clave `operator` seguida del operador, para luego tener los parámetros (uno o dos) a los que se va a aplicar la operación:

```csharp
using static System.Console;

var a = new Foo(); // 0
var b = a + 10;    // 10
var c = 1 + b;     // 11
var d = b + c;     // 21

WriteLine($"{a.Bar}, {b.Bar}, {c.Bar}, {d.Bar}");

class Foo {
    public int Bar = 0;

    public static Foo operator + (Foo left, int right)
        => new Foo { Bar = left.Bar + right };

    public static Foo operator + (int left, Foo right)
        => new Foo { Bar = left + right.Bar };

    public static Foo operator + (Foo left, Foo right)
        => new Foo { Bar = left.Bar + right.Bar };
}
```

Un caso especial y propenso a errores son los operadores de incremento o decremento. Recordemos que la versión postfija devuelve el valor previo al cambio y la prefija se devuelve el valor después del cambio. Sin embargo, sólo hay una opción para sobrecargar estos operadores, sin poder distinguir entre la versión prefija o postfija. Esta es la forma correcta de implementar los operadores:

```csharp
using static System.Console;

var a = new Foo(); // a = 0
var b = ++a;       // a = 1; b = 1
var c = a++;       // a = 2; c = 1

WriteLine($"{a.Bar}, {b.Bar}, {c.Bar}");

class Foo {
    public int Bar = 0;

    public static Foo operator ++ (Foo victim)
        => new Foo { Bar = victim.Bar + 1 };

    public static Foo operator -- (Foo victim)
        => new Foo { Bar = victim.Bar - 1 };
}
```

Esto es debido a que la semántica real del operador es la siguiente:

```csharp
// Versión prefija: b = ++a;
temp = operator ++(a);
a = temp;
b = temp;

// Versión postfija: b = a++;
temp = a;
a = operator ++(a);
b = temp;
```

Donde `temp` sería una variable fresca de tipo `Foo` creada por el compilador. Si los operadores, de incremento y decremento, los implementáramos mutando el contenido del operando, romperíamos la semántica y añadiríamos bugs.

Otra cosa que podemos sobrecargar, son las operaciones de conversión de tipos mediante *casting*, mediante las palabras clave `implicit` y `explicit`. Por ejemplo:

```csharp
using static System.Math;
using static System.Console;

var a = new Foo { Bar = 1.5 };
double b = a;
int c = (int) a;
int d = (int) a.Bar;

WriteLine($"a = {a.Bar}"); // a = 1,5
WriteLine($"b = {b}");     // b = 1,5
WriteLine($"c = {c}");     // c = 2
WriteLine($"d = {d}");     // d = 1

class Foo {
    public double Bar = 0;

    public static implicit operator double (Foo victim)
        => victim.Bar;

    public static explicit operator int (Foo victim)
        => (int) Round(victim.Bar);
}
```

Usamos `implicit` cuando la conversión es implícita y `explicit` cuando queremos que el programador haga explícito que está habiendo una conversión. No se puede tener una sobrecarga implícita y explícita para un mismo tipo, pero sí podemos tener múltiples sobrecargas implícitas, o explícitas, para diferentes tipos.

### Interfaces

Las interfaces es un mecanismo para definir qué operaciones debe tener implementadas una clase que herede de estas. Simplificando mucho, sería como una clase abstracta, donde todos los métodos declarados son abstractos. Su sintaxis es la siguiente:

$$\textcolor{red}{[} \mathit{modificadores} \textcolor{red}{]}\ \texttt{interface}\ \mathit{nombre}\ \textcolor{red}{[} \texttt{:} \mathit{interfaces} \textcolor{red}{]}\ \texttt{\\{}\ \mathit{definiciones}\ \texttt{\\}}$$

Los modificadores aplicables a una interfaz son los de visibilidad. En cuanto a las definiciones, se pueden definir métodos, propiedades, indexadores y eventos, con la principal diferencia de que en las interfaces las definiciones no tienen modificadores, porque se asume que son públicas siempre. Por ejemplo:

```csharp
using static System.Console;

Bar foo = new Foo();
foo.Evento += () => WriteLine("Material Girl");
foo.Mostrar();
foo.Texto = "How Soon Is Now?";
for (int i = 0; i < foo.Texto.Length; i++) {
    Write(foo[i]);
}
WriteLine();

interface Bar {
    void Mostrar ();
    string Texto { get; set; }
    char this[int i] { get; }
    event System.Action Evento;
}

class Foo : Bar {
    public char this[int i] => Texto[i];
    public string Texto { get; set; }
    public event System.Action Evento;
    public void Mostrar () => Evento();

    public Foo () {
        Texto = "Plastic Love";
        Evento += () => WriteLine(Texto);
    }
}
```

Como se pueden heredar varias interfaces, puede ocurrir que haya colisión con las definiciones. En principio no supone un problema, porque ambas interfaces usarán el mismo método en la clase que las implementa:

```csharp
using static System.Console;

var foo = new Foo();
foo.Saluda();
((Hermano) foo).Saluda();
((Primo) foo).Saluda();

interface Hermano { void Saluda (); }
interface Primo { void Saluda (); }

class Foo : Hermano, Primo {
    public void Saluda () => WriteLine("Hola");
}
```

Pero si necesitáramos hacer distinción entre cada interfaz, tendríamos que implementar el método de forma explícita:

```csharp
using static System.Console;

var foo = new Foo();
foo.Saluda();
((Hermano) foo).Saluda();
((Primo) foo).Saluda();

var bar = new Bar();
// bar.Saluda(); <- No compila
((Hermano) bar).Saluda();
((Primo) bar).Saluda();

interface Hermano { void Saluda (); }
interface Primo { void Saluda (); }

class Foo : Hermano, Primo {
    public void Saluda () => WriteLine("Hola");
    void Primo.Saluda () => WriteLine("Hola primo");
}

class Bar : Hermano, Primo {
    void Hermano.Saluda () => WriteLine("Hola hermano");
    void Primo.Saluda () => WriteLine("Hola primo");
}
```

Como se puede observar, implementar un método de forma explícita no permite usar modificadores y dicho método sólo se puede invocar con una expresión que tenga como tipo la interfaz.

Para evitar que se rompa todo un proyecto, al aumentar los miembros de una interfaz, es posible desde la versión 8.0 del lenguaje crear [métodos por defecto](https://learn.microsoft.com/dotnet/csharp/language-reference/proposals/csharp-8.0/default-interface-methods) para una definición:

```csharp
using static System.Console;

Bar foo = new Foo();
foo.Evento += () => WriteLine("Material Girl");
foo.Mostrar();
foo.Texto = "How Soon Is Now?";
for (int i = 0; i < foo.Texto.Length; i++) {
    Write(foo[i]);
}
WriteLine();

interface Bar {
    void Mostrar () => evento();
    
    string Texto {
        get => Mensaje;
        set => Mensaje = value;
    }
    
    char this[int i] { get => Mensaje[i]; }

    event System.Action Evento {
        add => evento += value;
        remove => evento -= value;
    }

    public static string Mensaje { set; get; }
    public static void Saludo () => WriteLine(Mensaje);
    private static System.Action evento = Saludo;
}

class Foo : Bar {
    public Foo () => Bar.Mensaje = "Plastic Love";
}
```

Es el mismo ejemplo del principio, pero usando métodos por defecto. Como se puede observar, podemos crear miembros estáticos dentro de una interfaz, de forma similar a como se hace en las clases. Hay que tener en cuenta, que los métodos por defecto no forman parte de la clase `Foo`, por lo tanto no se podría hacer `foo.Mostrar()` si `foo` fuera del tipo de la clase, en lugar de la interfaz.

Se puede también revertir el efecto de los métodos por defecto, para obligar a las clases a tener que implementar un método, con del modificador `abstract` de la siguiente manera:

```csharp
using static System.Console;

var foo = new Foo();
foo.M();
((A) foo).M();
((B) foo).M();

interface A {
    void M () => WriteLine("A.M");
}

interface B : A {
    abstract void M ();
}

class Foo : B {
    public void M () => WriteLine("Foo.M");
}
```

Existen más detalles derivados de los métodos por defecto, pero lo básico está ya cubierto con los anteriores ejemplos.

> En **C# 11** se pueden declarar miembros estáticos que deban implementar los tipos que extiendan dicha interfaz. Para ello se usa `static abstract` cuando la definición no tiene cuerpo definido, y `static virtual` cuando si tiene un cuerpo definido en la interfaz. También existe `static sealed` para miembros estáticos con cuerpo que no se pueden sobrescribir, aunque en principio con `static` a solas están sellados por defecto.

### Estructuras

Las [estructuras](https://learn.microsoft.com/dotnet/csharp/language-reference/builtin-types/struct) nos permiten crear tipos por valor, mientras que las clases son tipos por referencia. Se definen con la siguiente sintaxis:

$$\textcolor{red}{[} \mathit{modificadores} \textcolor{red}{]}\ \texttt{struct}\ \mathit{nombre}\ \textcolor{red}{[} \texttt{:} \mathit{interfaces} \textcolor{red}{]}\ \texttt{\\{}\ \mathit{definiciones}\ \texttt{\\}}$$

Las estructuras heredan del tipo `System.ValueType` y no pueden heredar de ningún otro tipo, pero sí pueden implementar interfaces. Los modificadores que puede tener son los de visibilidad y `readonly` en cuanto al comportamiento. Este último modificador hace que el tipo sea de sólo lectura una vez inicializado sus campos y propiedades.

En cuanto a las definiciones, varían los modificadores de visibilidad y comportamiento aceptados, ya que no se puede heredar de una estructura. Los modificadores disponibles son: `async`, `extern`, `new`, `override`, `readonly`, `static`, `unsafe` y `volatile`, que se usarán del mismo modo que en una clase. No obstante, podemos aplicar `readonly` a los métodos de la estructura, para forzar a que su código no modifique el contenido del objeto.

Otra diferencia importante es que los campos y propiedades no se puede inicializar con un valor en su definición. Para inicializar una estructura se puede crear un constructor, que no puede ser definido sin parámetros, y que se tendrá que inicializar todos los campos y propiedades de la misma.

El compilador genera internamente un constructor sin parámetros, que toma cada campo de la estructura y lo inicializa a su valor por defecto, el mismo que obtendríamos usando el operador `default`. Sobre el uso de este constructor, se puede inicializar el objeto con la sintaxis de inicialización de objetos. Por ejemplo:

```csharp
using static System.Console;

var a = new Foo();
a.Mostrar(); // 0

var b = new Foo() { Dato = 10 };
b.Mostrar(); // 10

var c = new Bar();
WriteLine($"{c.Dato} {c.Nombre}"); // 0

var d = new Bar() { Nombre = "Bobbin" };
WriteLine($"{d.Dato} {d.Nombre}"); // 0 Bobbin

var e = new Bar(10);
WriteLine($"{e.Dato} {e.Nombre}"); // 10 nada

struct Foo {
    public int Dato;
    public override string ToString() => Dato.ToString();
    public readonly void Mostrar () => WriteLine(Dato);
}

readonly struct Bar {
    public int Dato { get; init; }
    public string Nombre { get; init; }
    public Bar (int dato = -1, string nombre = "nada") {
        Dato = dato;
        Nombre = nombre;
    }
}
```

Tampoco está permitido que una estructura tenga un método destructor. Por lo que se recomienda utilizar la interfaz `System.IDisposable`, para liberar recursos instanciados dentro de la estructura.

> A partir de **C# 10** se permite inicializar campos y propiedades en su declaración. También se permite definir un constructor sin parámetros, que tendrá que ser público. En **C# 11** se quita la limitación de que se tengan que inicializar todos los campos y propiedades en un constructor.

### Registros

Los [registros](https://learn.microsoft.com/dotnet/csharp/language-reference/builtin-types/record) son un tipo por referencia especial pensados para datos inmutables. Su sintaxis es la siguiente:

$$\textcolor{red}{[} \mathit{modificadores} \textcolor{red}{]}\ \texttt{record}\ \mathit{nombre}\ \textcolor{red}{[} \texttt{(} \mathit{campos} \texttt{)} \textcolor{red}{]}\ \textcolor{red}{[} \texttt{:} \mathit{padre\ e\ interfaces} \textcolor{red}{]}\ \textcolor{red}{\\{} \texttt{;} \textcolor{red}{|} \texttt{\\{}\ \mathit{definiciones}\ \texttt{\\}} \textcolor{red}{\\}}$$

A efectos prácticos un registro es una clase, por lo que soporta los mismos tipos de modificadores y definiciones dentro del tipo. Pero un registro sólo puede heredar de otro registro, como primera diferencia. Luego tenemos los *campos*, también llamados parámetros posicionales, que podemos definir entre los paréntesis que acompañan al *nombre* del registro, estos se definen como se definen las variables. Por ejemplo:

```csharp
public record Punto (int X, int Y);
```

Sería similar a la siguiente definición:

```csharp
public record Punto {
    public int X { get; init; } = default;
    public int Y { get; init; } = default;
}
```

Para poder mutar un valor, y asignárselo a otra variable, tenemos el operador `with`:

```csharp
using static System.Console;

Punto p0 = new();
Punto p1 = new(1, 3);
var p2 = new Punto() { Y = 2, Z = 4 };
var p3 = p2 with { X = 4, Z = p1.Y * 2 };

WriteLine(p0); // Punto { X = 0, Y = 0, Z = 0 }
WriteLine(p1); // Punto { X = 1, Y = 3, Z = 0 }
WriteLine(p2); // Punto { X = 0, Y = 2, Z = 4 }
WriteLine(p3); // Punto { X = 4, Y = 2, Z = 6 }

var p4 = new Punto();
WriteLine(p0 == p4); // True
WriteLine(object.ReferenceEquals(p0, p4)); // False

record Punto (int X = 0, int Y = 0, int Z = 0);
```

Como se puede observar en el ejemplo, los registros tienen comprobación de la igualdad por valor y también formato automático de su contenido a cadena. Con los registros y con `with` tenemos una forma concisa de crear y modificar objetos inmutables.

> La inmutabilidad de las propiedades de un registro se limitan al contenido inmediato de los campos del tipo. Esto significa que, si usamos tipos por referencia, no podremos reasignar a la propiedad un nuevo objeto, pero sí podremos modificar el contenido del objeto. Por ejemplo:
> ```csharp
> using static System.Console;
>
> var foo = new Foo(new[] { 1, 2, 3, 4 });
>
> for (int i = 0; i < foo.NS.Length; i++)
>     foo.NS[i] *= 2;
>
> foreach (var item in foo.NS)
>     WriteLine(item); // 2 4 6 8
>
> record Foo (int[] NS );
> ```

Hay que tener en cuenta que, con los parámetros posicionales del registro, se crean automáticamente propiedades con `init`, un constructor cuyos parámetros corresponden con la definición de los parámetros posicionales, y un método `Deconstruct` con parámetros `out` por cada parámetro posicional (se ignorarán los campos y propiedades definidos en el cuerpo del registro). No obstante, podemos redefinir algunos de estos elementos dentro del cuerpo del registro:

```csharp
using static System.Console;

Bar v1 = new Bar(2, 3);
using Bor v2 = new Bor();
WriteLine(v1); // Bar { A = 2, B = 3 }
WriteLine(v2); // Bor { A = 1, B = 1 }

var (x, y) = v1;
WriteLine($"{x}, {y}"); // 2, 3
(x, y) = v2;
WriteLine($"{x}, {y}"); // 2, 2
// Borrar

abstract record Foo : System.IDisposable {
    public void Dispose () => WriteLine("Borrar");
}

record Bar (int A, int B) : Foo;

record Bor (int A, int B) : Foo {
    public Bor (int v = 1) : this(v, v) { }
    public void Deconstruct (out int a, out int b) {
        a = A * 2;
        b = A * 2;
    }
}
```

> A partir de **C# 10** se pueden definir `record struct`, así como `readonly record struct`, para crear registros que sean tipos por valor. Con `record struct` los parámetros posicionales del registro serán mutables. También se puede usar el operador `with` con estructuras para obtener nuevos valores sin destruir el valor de partida.

### Enumeraciones

Las [enumeraciones](https://learn.microsoft.com/dotnet/csharp/language-reference/builtin-types/enum) son tipos cuya semántica está compuesta por una serie de valores con nombre. Su sintaxis es la siguiente:

$$\textcolor{red}{[} \mathit{modificadores} \textcolor{red}{]}\ \texttt{enum}\ \mathit{nombre}\ \textcolor{red}{[} \texttt{:}\ \mathit{tipo} \textcolor{red}{]}\ \texttt{\\{}\ \mathit{nombre_1}\ \textcolor{red}{[} \texttt{=}\ \mathit{valor_1} \textcolor{red}{]} \textcolor{red}{[} \texttt{,} \textcolor{red}{\dots} \texttt{,} \mathit{nombre_n}\ \textcolor{red}{[} \texttt{=}\ \mathit{valor_n} \textcolor{red}{]} \textcolor{red}{]} \texttt{\\}}$$

Los modificadores aplicables a las enumeraciones son los de visibilidad. Por defecto, el *tipo* de una enumeración es `int` y se empieza asignando el valor `0` al primer *nombre* de los valores, e incrementando en `+1` el valor de los siguientes nombres. Los tipos que puede tener una enumeración están restringidos a números enteros:

```csharp
using static System.Console;

var x = Familia.Akane;
WriteLine($"{x - 4}"); // -3
WriteLine($"{x + 4}"); // Genma
WriteLine($"{++x}\n"); // Nabiki

foreach (var item in GetValues<Familia>()) {
    WriteLine($"{item,-8} = {(int) item}");
}

T[] GetValues<T> () => (T[]) System.Enum.GetValues(typeof(T));

public enum Familia {
    Ranma, Akane, Nabiki, Kasumi,
    Soun, Genma, Happosai, Nodoka
}
```

Otra opción disponible es marcar una enumeración con el atributo [`[System.Flags]`](https://learn.microsoft.com/dotnet/api/system.flagsattribute), lo que permite asignar como valores combinaciones que usan los operadores `|`, `&` y `^`:

```csharp
using static System.Console;

var y = Cowboys.Ein;
WriteLine($"{y}");     // Ein
WriteLine($"{y - 8}"); // Edo
WriteLine($"{y + 8}"); // Edo, Ein
WriteLine($"{++y}\n"); // Spike, Ein

y = Cowboys.Bebop;
WriteLine($"{y}");                  // Bebop
WriteLine($"{y | Cowboys.Dragon}"); // Bebop, Dragon
WriteLine($"{y ^ Cowboys.Ein}");    // Spike, Jet, Faye, Edo
WriteLine($"{y & Cowboys.Faye}");   // Faye
WriteLine($"{~y}\n");               // Andy, Dragon

foreach (var item in GetValues<Cowboys>()) {
    WriteLine($"{item,-7} = {(int) item}");
}

T[] GetValues<T> () => (T[]) System.Enum.GetValues(typeof(T));

[System.Flags]
public enum Cowboys : byte {
    Spike   = 0b_0000_0001,
    Jet     = 0b_0000_0010,
    Faye    = 0b_0000_0100,
    Edo     = 0b_0000_1000,
    Ein     = 0b_0001_0000,
    Andy    = 0b_0010_0000,
    Julia   = 0b_0100_0000,
    Vicious = 0b_1000_0000,
    Dragon  = Julia | Vicious,
    Bebop   = Spike | Jet | Faye | Edo | Ein
}
```

En este caso es recomendable asignar los valores manualmente en binario, para que funcionen correctamente los *flags* que queremos asignar.

Como muestran los ejemplos, se pueden hacer operaciones con los valores enumerados, ya que por debajo no dejan de ser números enteros, pero sólo se permiten los operadores `=`, `==`, `!=`, `<`, `>`, `<=`, `>=`, `+`, `-`, `+=`, `-=`, `++` y `sizeof` para las enumeraciones normales, para las de tipo *flags* también se permiten los operadores `^`, `&`, `|` y `~`.

### Tipos anónimos

Los [tipos anónimos](https://learn.microsoft.com/dotnet/csharp/fundamentals/types/anonymous-types) son objetos creados que no pertenecen a un tipo definido previamente. Su sintaxis es:

$$\texttt{new}\ \texttt{\\{}\ \mathit{nombre_1}\ \texttt{=}\ \mathit{expresi\acute{o}n_1} \textcolor{red}{[} \texttt{,} \textcolor{red}{\dots} \texttt{,}\ \mathit{nombre_n}\ \texttt{=}\ \mathit{expresi\acute{o}n_n} \textcolor{red}{]}\ \texttt{\\}}$$

Por ejemplo:
```csharp
using static System.Console;

var p = new { Nombre = "Tendo Akane", Edad = 16 };
WriteLine($"{p.Nombre} ({p.Edad})");
```

### Tuplas

Las [tuplas](https://learn.microsoft.com/dotnet/csharp/language-reference/builtin-types/value-tuples) son estructuras de datos, con un orden y número de componentes fijo. Para construir una tupla se utilizan los paréntesis, separando cada componente con comas:

```csharp
using static System.Console;

(string, int) p1 = ("Saotome Ranma", 16);
WriteLine($"{p1.Item1} ({p1.Item2})");

var (a, b) = p1;
WriteLine($"{a} ({b})");
```

Cuando se construye una tupla, se instancia un objeto de tipo [`System.ValueTuple`](https://learn.microsoft.com/dotnet/api/system.valuetuple), que son tipos por valor. Si queremos crear tuplas que sean tipos por referencia, tenemos el tipo [`System.Tuple`](https://learn.microsoft.com/dotnet/api/system.tuple). Hay que tener en cuenta que `ValueTuple` es mutable, mientras que `Tuple` es inmutable. Cuando se [deconstruye](https://learn.microsoft.com/dotnet/csharp/fundamentals/functional/deconstruct) una tupla, se invoca al método especial `Deconstruct` del tipo para extraer la información.

También se puede poner nombre a los componentes de una tupla con:

```csharp
using static System.Console;

(string nombre, int edad) p2 = ("Tatewaki Kuno", 17);
WriteLine($"{p2.nombre} ({p2.edad})");

var p3 = (Nombre: "Hibiki Ryoga", Edad: 16);
WriteLine($"{p3.Nombre} ({p3.Edad})");
```

Como son tipos por valor, podemos pasar de una tupla sin nombres a una con:

```csharp
using static System.Console;

var p4a = ("Kuonji Ukyo", 16);
WriteLine($"{p4a.Item1} ({p4a.Item2})");

(string Nombre, int Edad) p4b = p4a;
WriteLine($"{p4b.Nombre} ({p4b.Edad})");
```

Las tuplas permiten el uso de los operadores `==` y `!=`, haciendo una comparación por valor, aunque esto no significa que cada componente se realice el mismo tipo de comparación:

```csharp
using static System.Console;

var p5 = ("Tendo Nabiki", 17);
var p6 = ("Tendo Nabiki", 17);
WriteLine(p5 == p6); // True

var p7 = (new { N = "Tendo Kasumi" }, 19);
var p8 = (new { N = "Tendo Kasumi" }, 19);
WriteLine(p7 == p8); // False
```

## E/S por consola

La entrada y salida por consola en C# se realiza con la clase estática [`Console`](https://learn.microsoft.com/dotnet/api/system.console). Es una clase muy completa para poder manejar la terminal, pudiendo cambiar la posición del cursor o los colores, entre otras cosas. Pero en esta sección nos vamos a centrar en las operaciones más básicas:

| Método | Descripción |
|:------:|:------------|
| `Clear` | Borra el contenido de la pantalla. |
| `Read` | Obtiene un carácter del buffer del teclado. |
| `ReadKey` | Obtiene la siguiente tecla pulsada en el teclado. |
| `ReadLine` | Obtiene una línea de texto del buffer del teclado. |
| `Write` | Escribe un valor en el buffer de pantalla. |
| `WriteLine` | Escribe un valor en el buffer de pantalla y añade un salto de línea al final. |
| `GetCursorPosition` | Obtiene una tupla con la posición del cursor. |
| `SetCursorPosition` | Cambia la posición del cursor. |

## Formato de cadenas

El formato de cadenas, realizado por funciones como [`String.Format`](https://learn.microsoft.com/dotnet/api/system.string.format) o [`Console.WriteLine`](https://learn.microsoft.com/dotnet/api/system.console.writeline), consiste en cadenas de texto que tienen una serie de códigos especiales, delimitados entre llaves, que siguen la siguiente sintaxis:

$$\texttt{\\{} \mathit{\acute{\imath}ndice} \textcolor{red}{[} \texttt{,} \mathit{alineamiento} \textcolor{red}{]} \textcolor{red}{[} \texttt{:} \mathit{formato} \textcolor{red}{]} \texttt{\\}}$$

Donde el *índice* es la posición dentro del array de argumentos que acompaña a la cadena de formato, en la llamada a las funciones como `String.Format`, que como es un parámetro con el modificador `params`, se pasan como si fueran argumentos posicionales normales en la llamada. Si necesitáramos poner los caracteres de las llaves, tendríamos que usar la codificación `{{` y `}}` para lograrlo.

También se puede usar el formato de cadenas directamente con lo que se llama [interpolación de cadenas](https://learn.microsoft.com/dotnet/csharp/language-reference/tokens/interpolated). Esta última técnica consiste en una cadena de texto que tiene el símbolo dólar como prefijo, por ejemplo, `$"texto"`. La diferencia es que, en lugar de usar un *índice*, podremos usar directamente expresiones del lenguaje, como variables de programa u operaciones. Además, se pueden combinar con las cadenas "crudas", por ejemplo, `$@"\mi\ruta"`.

El *alineamiento* es un número entero que indica un ancho de columna, alineando a la izquierda el valor si es negativo y a la derecha si es positivo, rellenando con espacios para alcanzar el ancho indicado. En cuanto al *formato* es una serie de códigos, que indica a la función cómo se ha de representar en texto la información. Para valores numéricos tenemos los siguientes códigos:

| Código | Descripción | Tipos | Precisión |
|:------:|:-----------:|:-----:|:---------:|
| `c`, `C` | Divisa | Números | Definida en `NumberFormatInfo` de `System.Globalization`. |
| `d`, `D` | Decimal | Enteros| - |
| `e`, `E` | Científico | Números | De 6 dígitos decimales. |
| `f`, `F` | Punto fijo | Números | Definida en `NumberFormatInfo` de `System.Globalization`. |
| `g`, `G` | General | Números | Dependiente del tipo numérico. |
| `n`, `N` | Número | Números | Definida en `NumberFormatInfo` de `System.Globalization`. |
| `p`, `P` | Porcentaje | Números | Definida en `NumberFormatInfo` de `System.Globalization`. |
| `r`, `R` | Ida y vuelta | Reales | - |
| `x`, `X` | Hexadecimal | Enteros | - |

Estos códigos permiten estar acompañados por un número entero, para indicar la precisión en la representación del dato. Veamos el siguiente ejemplo para observar los resultados de cada código y de la precisión:

```csharp
using static System.Console;

void foo (string format, object value) {
    try {
        WriteLine(format, value);
    } catch (System.Exception) {
        WriteLine($"No \"{format}\" with {value}");
    }
}

int a = 255;
foo("{0:c4} \t {0:C4}", a);   // 255,0000 ?       255,0000 ?
foo("{0:d4} \t\t {0:D4}", a); // 0255             0255
foo("{0:e4} \t {0:E4}", a);   // 2,5500e+002      2,5500E+002
foo("{0:f4} \t {0:F4}", a);   // 255,0000         255,0000
foo("{0:g4} \t\t {0:G4}", a); // 255              255
foo("{0:n4} \t {0:N4}", a);   // 255,0000         255,0000
foo("{0:p4} \t {0:P4}", a);   // 25.500,0000 %    25.500,0000 %
foo("{0:r4} \t {0:R4}", a);   // No "{0:r4}       {0:R4}" with 255
foo("{0:x4} \t\t {0:X4}", a); // 00ff             00FF

float b = 1.23f;
foo("{0:c4} \t {0:C4}", b);   // 1,2300 ?         1,2300 ?
foo("{0:d4} \t {0:D4}", b);   // No "{0:d4}       {0:D4}" with 1,23
foo("{0:e4} \t {0:E4}", b);   // 1,2300e+000      1,2300E+000
foo("{0:f4} \t\t {0:F4}", b); // 1,2300           1,2300
foo("{0:g4} \t\t {0:G4}", b); // 1,23             1,23
foo("{0:n4} \t\t {0:N4}", b); // 1,2300           1,2300
foo("{0:p4} \t {0:P4}", b);   // 123,0000 %       123,0000 %
foo("{0:r4} \t\t {0:R4}", b); // 1,23             1,23
foo("{0:x4} \t {0:X4}", b);   // No "{0:x4}       {0:X4}" with 1,23
```

También podemos crear un formato propio con los siguientes códigos:

| Código | Descripción | Ejemplo | Valor | Resultado |
|:------:|:-----------:|:-------:|:-----:|:---------:|
| `0` | Ceros | `{0:0.000}`<br/>`{0:000.0}` | `23.45` | `23,450`<br/>`023,5` |
| `#` | Dígitos | `{0:#.###}`<br/>`{0:###.#}` | `23.45` | `23,45`<br/>`23,5` |
| `.` | Decimales | `{0:#.00}` | `42` | `42,00` |
| `,` | Millares | `{0:#.###}` | `1234` | `1.234` |
| `%` | Porcentaje | `{0:0.##%}`<br/>`{0:0.## %}` | `0.12345` | `12,35%`<br/>`12,35 %` |

Podemos combinar estos códigos de formato propio entre sí, con gran flexibilidad, como muestran algunos de los ejemplos.

Otros códigos disponibles para dar formato son los de fechas. Estos nos permiten dar formato a valores de las clases [`System.DateTime`](https://learn.microsoft.com/dotnet/api/system.datetime) y [`System.DateTimeOffset`](https://learn.microsoft.com/dotnet/api/system.datetimeoffset), usando los siguientes códigos:

| Código | Descripción | Ejemplo |
|:------:|:-----------:|:-------:|
| `d` | Fecha corta. | `26/12/2022` |
| `D` | Fecha larga. | `lunes, 26 de diciembre de 2022` |
| `f` | Fecha larga con hora corta. | `lunes, 26 de diciembre de 2022 7:53 p.m.` |
| `F` | Fecha larga con hora larga. | `lunes, 26 de diciembre de 2022 7:53:42 p.m.` |
| `g` | Fecha corta con hora corta. | `26/12/2022 7:53 p.m.` |
| `G` | Fecha corta con hora larga. | `26/12/2022 7:53:42 p.m.` |
| `M`, `m` | Día y mes. | `26 de diciembre` |
| `O`, `o` | Ida y vuelta. | `2022-12-26T19:53:42.5655419+01:00` |
| `R`, `r` | RFC1123. | `Mon, 26 Dec 2022 19:53:42 GMT` |
| `s` | Fecha y hora ordenable. | `2022-12-26T19:53:42` |
| `t` | Hora corta. | `7:53 p.m.` |
| `T` | Hora larga. | `7:53:42 p.m.` |
| `u` | Fecha y hora universal ordenable. | `2022-12-26 19:53:42Z` |
| `U` | Fecha y hora universal. | `lunes, 26 de diciembre de 2022 6:53:42 p.m.` |
| `Y`, `y` | Mes y año. | `diciembre de 2022` |

De forma similar a con los números, también podemos crear formatos propios con los siguientes códigos:

| Código | Descripción | Código | Descripción |
|:------:|:-----------:|:------:|:-----------:|
| `d` | Día (`1`-`31`) | `dd` | Día (`01`-`31`) |
| `ddd` | Día nombre corto (`lun`) | `dddd` | Día nombre largo (`lunes`) |
| `f` | Décimas (10^-1^) de segundo | `ff` | Centésimas (10^-2^) de segundo |
| `fff` | Milésimas (10^-3^) de segundo | `ffff` | 10^-4^ de segundo |
| `fffff` | 10^-5^ de segundo | `ffffff` | Millonésima (10^-6^) de segundo |
| `fffffff` | 10^-7^ de segundo | `F` | Décimas (10^-1^) de segundo o nada si es cero |
| `FF` | Centésimas (10^-2^) de segundo o nada si es cero | `FFF` | Milésimas (10^-3^) de segundo o nada si es cero |
| `FFFF` | 10^-4^ de segundo o nada si es cero | `FFFFF` | 10^-5^ de segundo o nada si es cero |
| `FFFFFF` | Millonésima (10^-6^) de segundo o nada si es cero | `FFFFFFF` | 10^-7^ de segundo o nada si es cero |
| `g`, `gg` | Era (`a. C.`, `d. C.`) | `h` | Hora (`1`-`12`) |
| `hh` | Hora (`01`-`12`) | `H` | Hora (`1`-`24`) |
| `HH` | Hora (`01`-`24`) | `K` | Zona horaria (`+01:00`) |
| `m` | Minuto (`1`-`59`) | `mm` | Minuto (`01`-`59`) |
| `M` | Mes (`1`-`12`) | `MM` | Mes (`01`-`12`) |
| `MMM` | Mes nombre corto (`dic`) | `MMMM` | Mes nombre largo (`diciembre`) |
| `s` | Segundo (`1`-`59`) | `ss` | Segundo (`01`-`59`) |
| `t` | AM/PM (`a`, `p`) | `tt` | AM/PM (`a.m.`, `p.m.`) |
| `y` | Año (`1`-`99`) | `yy` | Año (`01`-`99`) |
| `yyy` | Año con mínimo 3 dígitos | `yyyy` | Año con 4 dígitos |
| `yyyyy` | Año con 5 dígitos | `z` | Uso horario |
| `zz` | Uso horario con 2 dígitos | `zzz` | Uso horario con horas y minutos |
| `:` | Separador de tiempo | `/` | Separador de fecha |
| `"..."`<br/>`'...'` | Texto literal | `%` | Usar especificador de formato propio (`%d`) |
| `\` | Carácter de escape | Otros | Texto literal |

Para los valores de la clase [`System.TimeSpan`](https://learn.microsoft.com/dotnet/api/system.timespan) tenemos los siguientes códigos:

| Código | Descripción | Ejemplo |
|:------:|:-----------:|:-------:|
| `c` | Formato constante. | `1.02:03:04` |
| `g` | Formato general corto. | `1:2:03:04` |
| `G` | Formato general largo. | `1:02:03:04,0000000` |

Y estos códigos nos permitirán crear formatos propios:

| Código | Descripción | Código | Descripción |
|:------:|:-----------:|:------:|:-----------:|
| `d`, `%d` | Días | `dd`-`dddddddddd` | Días con ceros a la izquierda |
| `h`, `%h` | Horas | `hh` | Horas con ceros a la izquierda |
| `s`, `%s` | Segundos | `ss` | Segundos con ceros a la izquierda |
| `f`, `%f` | Décimas de segundo | `ff`-`fffffff` | De 10^-2^ a 10^-7^ de segundo |
| `F`, `%F` | Décimas de segundo o nada si es cero | `FF`-`FFFFFFF` | De 10^-2^ a 10^-7^ de segundo o nada si es cero |
| `'...'` | Texto literal | `\` | Carácter de escape |
| Otros | Texto literal |

Por último, para la función [`Enum.ToString`](https://learn.microsoft.com/dotnet/api/system.enum.tostring) tenemos estos códigos, para dar formato a valores enumerados:

| Código | Descripción |
|:------:|:-----------:|
| `g`, `G` | Representación como texto. |
| `f`, `F` | Representación de *flags* como texto. |
| `d`, `D` | Representación como número decimal. |
| `x`, `X` | Representación como número hexadecimal. |

## Conversiones y referencias

Hay dos operadores con los que se puede convertir un expresión de un tipo a otro. El primero es el *casting*, que ya se ha mencionado con anterioridad, cuya forma `(T)X` nos indica que la expresión `X` pasará a ser de tipo `T`. Cuando queremos pasar de un tipo `T` a un tipo `U`, si `T` es descendiente de `U` la conversión será implícita, sin necesidad de hacer un *casting*, pero si `U` es descendiente de `T` sí necesitaremos hacer el casting explícito:

```csharp
string x = "hola";
object y = x;
string z = (string) y;
```

Pero, si tratamos de hacer el *casting* a un tipo incorrecto, se lanzará la excepción `System.InvalidCastException`:

```csharp
string x = "hola";
object y = x;
var z = (System.Delegate) y;
```

Una forma de evitar la excepción, es usando el operador `as`, cuya forma `X as T` nos indica que la expresión `X` pasará a ser de tipo `T` si es posible, si no lo es se devolverá `null`:

```csharp
using static System.Console;

WriteLine(foo("hola")); // HOLA
WriteLine(foo(123));    // <null>

string foo (object v) {
    var x = v as string;
    if (x != null)
        return x.ToUpper();
    else
        return "<null>";
}
```

Aunque también podemos usar el operador  `is` con patrones para hacer lo mismo:

```csharp
using static System.Console;

WriteLine(foo("hola")); // HOLA
WriteLine(foo(123));    // <null>

string foo (object v) {
    if (v is string x)
        return x.ToUpper();
    else
        return "<null>";
}
```

> En la terminología de C#, cuando un tipo por valor es asignado a una variable de tipo `object`, se lo denomina *boxing*. Esto consiste en que se copia el valor de la pila a la memoria del montículo. La operación inversa se la denomina *unboxing*, que ocurre al hacer un *casting* de `object` a tipo por valor, tomando el valor de la memoria del montículo para almacenarlo en la pila.

El caso es que tenemos los operadores para referencias nulas `?` y `??`. El primero permite acceder a un miembro con `?.`, o un elemento con `?[]`, si la expresión a la izquierda no es nula. Si fuera nula se limita a devolver `null` como resultado de la expresión. El segundo evalúa la expresión a la izquierda, para comprobar que su valor no sea nulo y devolverlo como resultado, si fuera nulo devolverá el valor de la expresión a la derecha. Tomando el ejemplo anterior:

```csharp
using static System.Console;

WriteLine(foo("hola")); // HOLA
WriteLine(foo(123));    // <null>

string foo (object v) =>
    (v as string)?.ToUpper() ?? "<null>";
```

Del operador `??` existe la variante `??=`, que asignará al lado izquierdo el valor del lado derecho, si el lado izquierdo es nulo.

### Tipos por valor nulos

 Además de todo lo anterior, el operador `?` tiene [otra utilidad](https://learn.microsoft.com/dotnet/csharp/language-reference/builtin-types/nullable-value-types) importante, para poder simular que se asigna el valor `null` a un tipo por valor. Para ello, al declarar la variable usaremos la forma `T?`, donde `T` es el tipo por valor, para que el compilador lo transforme en el tipo [`System.Nullable<T>`](https://learn.microsoft.com/dotnet/api/system.nullable-1):

```csharp
using static System.Console;

int a = (int)sum(2, 3);
int b = sum(2, "4") ?? 0;
WriteLine($"{a}, {b}"); // 5, 0

int? sum (object x, object y) {
    int? a = x as int?;
    int? b = y as int?;
    return a + b;
}
```

El operador `as` no permite su uso con estructuras, porque no aceptan `null` como valor, pero con `int?` se resuelve ese escollo. Para convertir de `Nullable<T>` a `T`, se puede realizar un *casting*, pero si el valor es nulo se lanza una excepción `System.InvalidOperationException`; mientras que con el operador `??`, en caso de ser nulo el valor, se devuelve el valor derecho como valor por defecto. Otro aspecto relevante es que `Nullable<T>` es gestionado por el compilador para poder hacer operaciones de forma transparente. Para las operaciones aritméticas, si uno de los dos operandos es nulo, se devuelve `null`. Para las operaciones de comparación o lógicas, si uno de los dos operandos es nulo, se devuelve `false`.

Hay dos propiedades importantes en el tipo `Nullable<T>`. La primera es `HasValue`, de tipo `bool`, que devuelve si tiene valor real o no el objeto. El segundo es `Value`, de tipo `T`, que contendrá el valor real del objeto, siempre que `HasValue` sea `true`.

### Tipos por referencia nulos

Existe la opción `Nullable` en el compilador, que en caso de estar activada fuerza al compilador a comprobar que no se esté asignando el valor `null` a ningún tipo por referencia. También se puede activar o desactivar con las directivas:

```csharp
#nullable enable  // Activa el modo no nulo
#nullable disable // Desactiva el modo no nulo
#nullable restore // Restaura la configuración del proyecto
```

Si el compilador detecta que se podría estar asignando un valor nulo, lanzará un aviso al usuario. Si queremos evitar que salte dicho aviso, tenemos el operador `!`:

```csharp
#nullable enable
string  a = default;  // Aviso CS8600
string  b = default!; // Permitido
string? c = default;  // Permitido
```

Con el operador `?`, aplicado a un tipo por referencia, se permite que la variable pueda ser nula sin usar el operador `!`. Sin embargo, los [tipos por referencia nulos](https://learn.microsoft.com/dotnet/csharp/language-reference/builtin-types/nullable-reference-types) no se pueden usar para heredar de ellos, ni para crear objetos con `new`, ni para acceder a miembros estáticos, ni tampoco  en comprobaciones de tipos.

> A partir de **.NET 6**, la opción `Nullable` en nuevos proyectos está activada por defecto.

### Covarianza y contravarianza

Otro asunto importante en las conversiones de tipos es [la covarianza y la contravarianza](https://es.wikipedia.org/wiki/Covarianza_y_contravarianza_%28ciencias_de_la_computaci%C3%B3n%29), que determina las relaciones de subtipado entre tipos:
+ Son **covariantes** en el lenguaje los tipos de retorno de las funciones, así como el tipo de los elementos de un contenedor. Por ejemplo, si `A` es subtipo de `B`, entonces `IEnumerable<A>` es subtipo de `IEnumerable<B>`, por lo que podremos asignar implícitamente a una variable de tipo `IEnumerable<B>` un valor de tipo `IEnumerable<A>`.

+ Son **contravariantes** en el lenguaje los tipos de los parámetros de una función. Por ejemplo, si `A` es subtipo de `B`, entonces `Action<B>` es subtipo de `Action<A>`, por lo que podremos asignar implícitamente a una variable de tipo `Action<A>` un valor de tipo `Action<B>`.

```csharp
using System;
using System.Collections.Generic;
using static System.Console;

WriteLine("Covarianza:");
IEnumerable<Hija> v1 = new[] {
    new Hija(),
    new Hija { X = 2, Y = 3 }
};
IEnumerable<Madre> v2 = v1;
foreach (var item in v2) {
    WriteLine(item);
}

WriteLine("Contravarianza:");
Action<Madre> f1 = x => WriteLine(x);
Action<Hija> f2 = f1;
foreach (var item in v1) {
    f2(item);
}

class Madre {
    public int X = 1;
    public override string ToString () => $"M: {X}";
}

class Hija : Madre {
    public int Y = 2;
    public override string ToString () => $"H: {X}, {Y}";
}
```

Esto se podrá entender algo mejor al implementar tipos genéricos.

### Referencias locales

La palabra clave `ref` tiene algunos usos especiales, para forzar el uso de referencias en lugar de valores. Podemos modificar la declaración de una variable, o el tipo de retorno de una función, con `ref Tipo`:

```csharp
using static System.Console;

var foo = new Foo();
WriteLine(foo); // 1 2 3 4 5

ref int n = ref foo.Bar(2);
n = 9;
WriteLine(foo); // 1 2 9 4 5

class Foo {
    public int[] N = new[] { 1, 2, 3, 4, 5 };
    private int M = 0;

    public ref int Bar (int i) {
        if (0 <= i && i < N.Length)
            return ref N[i];
        else
            return ref M;
    }

    public override string ToString () {
        return string.Join(" ", N);
    }
}
```

Para devolver un valor por referencia, necesitamos usar `return ref` para devolver el valor y usar `ref` como modificador a la invocación de la función. Dicho lo cual, no podremos devolver como referencia variables que estén dentro del ámbito del que se va a salir, porque serán eliminadas y tendríamos una referencia a la nada; o lo que es peor, una referencia a una región de memoria incontrolada, que podría provocar fallos de seguridad grave.

> Técnicamente hablando esto es parecido a tener [punteros](https://learn.microsoft.com/dotnet/csharp/language-reference/unsafe-code), aunque con algunas limitaciones razonables, para que .NET se siga encargando de la gestión de la memoria de forma transparente.

Se puede combinar `ref` con `readonly` de diferentes maneras, para impedir que se modifique la referencia y/o el valor:

| Forma | Referencia | Valor |
|:-----:|:----------:|:-----:|
| `ref Tipo` | Sí | Sí |
| `ref readonly Tipo` | Sí | No |
| `readonly ref Tipo` | No | Sí |
| `readonly ref readonly Tipo` | No | No |

Existe la posibilidad de declarar una estructura como [`ref struct`](https://learn.microsoft.com/dotnet/csharp/language-reference/builtin-types/ref-struct), pero en contra de lo que parecería intuitivo, esto obliga a que los objetos de dicho tipo sólo puedan almacenarse en la pila y no se puedan crear referencias a los mismos. Es una característica especial, que se añadió para crear los tipos [`System.Span<T>`](https://learn.microsoft.com/dotnet/api/system.span-1) y [`System.ReadOnlySpan<T>`](https://learn.microsoft.com/dotnet/api/system.readonlyspan-1).

## Genéricos

Los [parámetros de tipo genéricos](https://learn.microsoft.com/dotnet/csharp/programming-guide/generics/generic-type-parameters) es un mecanismo para poder definir algoritmos genéricos, que se puedan aplicar polimórficamente a diferentes tipos concretos. Se pueden definir código genérico con clases, estructuras, registros, interfaces, métodos y delegados. Para ello hay que definir las variables de tipo entre `<` y `>`, separadas por comas, justo después del nombre identificador del elemento:

```csharp
var v1 = new Foo<string, int> {
    X = "A",
    Y = 2
};
var v2 = new Foo<int, Foo<float, float>> {
    X = 3,
    Y = new Foo<float, float> {
        X = 4f,
        Y = 5f
    }
};

class Foo<T1, T2> {
    public T1 X;
    public T2 Y;
}
```

Cualquier tipo se puede utilizar para instanciar un tipo genérico, incluso otro tipo genérico. Este mecanismo es parecido a las plantillas de C++, pero las plantillas son más flexibles, ya que son como macros muy sofisticadas; mientras que los genéricos son una ayuda al compilador para no perder el polimorfismo, ya que por debajo en la implementación utilizan referencias al tipo `object`.

### Restricciones

Se pueden poner restricciones a las variables de tipo en los genéricos con la palabra clave `where`, usando la siguiente sintaxis:

$$\texttt{where}\ \mathit{variable_1}\ \texttt{:}\ \mathit{restricciones_1}\ \textcolor{red}{[} \textcolor{red}{\dots}\ \texttt{where}\ \mathit{variable_n}\ \texttt{:}\ \mathit{restricciones_n} \textcolor{red}{]}$$

Las restricciones se ponen al final de la firma de la declaración, es decir, justo antes del punto y coma o de la llave que inicia el bloque de definiciones. Cada opción en el conjunto de *restricciones*, asociado a una *variable*, se separa por comas. Las opciones que tenemos como restricciones son las siguientes:

| Restricción | Descripción |
|:-----------:|:------------|
| `struct` | El tipo ha de ser un tipo por valor. Esta restricción implica a `new()`, por lo que no se puede combinar con ella. Tampoco se puede combinar con `unmanaged`. |
| `class` | El tipo ha de ser un tipo por referencia, que incluye clases, interfaces, delegados o arrays. En un contexto *nullable*, será un tipo por referencia no nulo. |
| `class?` | Como `class`, pero el tipo por referencia podrá ser nulo también. |
| `notnull` | El tipo ha de ser un tipo no nulo, ya ser por valor o por referencia. |
| `default` | Se usa para indicar que se va a sobrescribir un método genérico sin restricciones en el tipo padre. |
| `unmanaged` | El tipo ha de ser un tipo no nulo no gestionado, es decir, tipos cuya memoria no está controlada por el recolector de basura (tipos numéricos, booleanos, enumeraciones, punteros y estructuras cuyos campos sólo son de tipo no gestionados). Esta restricción implica a `struct` y no se puede combinar ni con `struct`, ni con `new()`. |
| `new()` | El tipo tiene un constructor público sin parámetros. Si se usa con otras restricciones, esta tendrá que ir la última. No se puede combinar ni con `struct`, ni con `unmanaged`. |
| `Tipo` | El tipo ha de estar en la jerarquía del tipo indicado y no podrá ser nulo en un contexto *nullable*. |
| `Tipo?` | El tipo ha de estar en la jerarquía del tipo indicado y también podrá ser nulo en un contexto *nullable*. |
| `Interfaz` | El tipo ha de implementar la interfaz indicada y no podrá ser nulo en un contexto *nullable*. |
| `Interfaz?` | El tipo ha de implementar la interfaz indicada y también podrá ser nulo en un contexto *nullable*. |
| `T` | El tipo ha de ser subtipo del tipo asignado a otra variable de tipo. |

### Tipos de entrada y de salida

Sabemos que el lenguaje permite la covarianza y la contravarianza. Para lo primero podemos definir variables de tipo con el modificador `out` y para lo segundo tenemos el modificador `in`:

```csharp
using static System.Console;

// Covarianza:
var p1 = new Pila<Bar>();
p1.Meter(new Bar { N = 1, M = 2 });
IFuera<Foo> ff = p1;
WriteLine(ff.Sacar());

// Contravarianza:
var p2 = new Pila<Foo>();
IDentro<Bar> db = p2;
db.Meter(new Bar { N = 3, M = 4 });
WriteLine(p2.Sacar());

record Foo(int N = 0);
record Bar(int N = 0, int M = 0) : Foo(N);

interface IFuera<out T> {
    T Sacar ();
}

interface IDentro<in T> {
    void Meter (T valor);
}

class Pila<T> : IFuera<T>, IDentro<T> {
    private int tam;
    private T[] mem;

    public Pila (int t = 10) {
        tam = 0;
        mem = new T[t];
    }

    public void Meter (T valor) =>
        mem[tam++] = valor;

    public T Sacar () =>
        mem[--tam];
}
```

### Operadores especiales

El operador `typeof(T)` permite obtener un objeto de tipo [`System.Type`](https://learn.microsoft.com/dotnet/api/system.type), que describe al tipo `T` mediante [reflexión](https://learn.microsoft.com/dotnet/csharp/programming-guide/concepts/reflection). Si queremos obtener el tipo de un objeto instanciado, podemos usar el método `GetType()` heredado de `object`. Con el operador `typeof` podemos obtener el tipo de una variable de tipo de un genérico también:

```csharp
using static System.Console;

var v1 = new Foo<int>();
WriteLine(v1.Igual<int>());    // True
WriteLine(v1.Igual<string>()); // False

class Foo<T> {
    public T Info;
    public bool Igual<TOtro> () {
        return typeof(T) == typeof(TOtro);
    }
}
```

Como curiosidad, se puede usar `typeof` para obtener el tipo de un tipo genérico sin variables de tipo asignadas:

```csharp
using static System.Console;

WriteLine(typeof(Foo<>));           // Foo`1[T]
WriteLine(typeof(Foo<int>));        // Foo`1[System.Int32]
WriteLine(typeof(Bar<,>));          // Bar`2[T1,T2]
WriteLine(typeof(Bar<bool, byte>)); // Bar`2[System.Boolean, System.Byte]

class Foo<T> { }
class Bar<T1,T2> { }
```

> El espacio de nombres [`System.Reflection`](https://learn.microsoft.com/dotnet/api/system.reflection) tiene todos los tipos que permiten trabajar con la reflexión en el lenguaje. Es un tema apasionante y extenso, que por desgracia no se va a poder cubrir en estos apuntes. Pero para que nos hagamos una noción de sus posibilidades, además de poder inspeccionar toda la información relativa a los tipos, nos permite modificar en tiempo de ejecución la funcionalidad del programa, por ejemplo, creando nuevos tipos.

El operador `default(T)` devuelve el valor por defecto para un tipo `T`. Se puede usar simplemente `default` cuando el compilador es capaz de inferir el tipo en la expresión, por ejemplo, cuando se declara una variable indicando su tipo. También se pueden usar variables de tipo con el operador:

```csharp
using static System.Console;

var a = default(int);
int b = default;

Mostrar<int>();    // 0
Mostrar<float>();  // 0
Mostrar<bool>();   // False
Mostrar<string>(); // null

void Mostrar<T> () {
    WriteLine(default(T)?.ToString() ?? "null");
}
```

En cuanto a la herencia, podemos heredar de un tipo genérico. También podemos usar el tipo que estamos definiendo como un parámetro o restricción:

```csharp
class Foo<T> { }
class Bar<T> where T : Bar<T> { }

class FooInt : Foo<int> { }
class Uno<T> : Foo<Uno<T>> { }
class Dos<T1, T2> : Foo<T2> { }
class Tres<T1, T2> : Foo<T1> { }
class Cuatro : Foo<Cuatro> { }
```

Otra curiosidad es que podemos tener miembros estáticos en un tipo genérico. Por cada instanciación de tipo, el compilador creará una clase durante la compilación, para trabajar con ellas:

```csharp
using static System.Console;

WriteLine(++Foo<int>.N);    // 1
WriteLine(++Foo<string>.N); // 1
WriteLine(++Foo<object>.N); // 1
WriteLine(++Foo<string>.N); // 2
WriteLine(++Foo<int>.N);    // 2

class Foo<T> {
    public static int N;
}
```

## Secuencias e iteradores

Dentro de la terminología del lenguaje, los enumeradores son objetos que recorren una secuencia de datos. Para ello, un contenedor de datos debe implementar la interfaz [`System.Collections.IEnumerable<T>`](https://learn.microsoft.com/dotnet/api/system.collections.generic.ienumerable-1), que tiene el método [`GetEnumerator()`](https://learn.microsoft.com/dotnet/api/system.collections.generic.ienumerable-1.getenumerator), que nos devuelve un objeto enumerador que implementa la interfaz [`System.Collections.IEnumerator<T>`](https://learn.microsoft.com/dotnet/api/system.collections.generic.ienumerator-1). Los miembros de esta última interfaz son:

| Miembro | Tipo | Descripción |
|:-------:|:----:|:------------|
| `Current` | `T` | Da el elemento en la posición actual del recorrido. |
| `Dispose` | `void ()` | Libera los recursos asociados, para cumplir con la interfaz `IDisposable`. |
| `MoveNext` | `bool ()` | Avanza una posición en el recorrido actual, devolviendo `true` si puede avanzar y `false` si ha llegado al final del recorrido. |
| `Reset` | `void ()` | Sitúa la posición actual en la posición previa al elemento inicial del recorrido. Es decir, después de resetear el objeto, será necesario utilizar `MoveNext()` para acceder al primer elemento. |

> Hay que tener en cuenta, que al crearse el objeto enumerador, la posición a la que apunta es la previa al elemento inicial, como ocurría después de invocar a `Reset()`. Es por ello que el recorrido empieza siempre primero con un `MoveNext()` y después se usa `Current`.

La sentencia `foreach` utiliza los enumeradores para recorrer los contenedores de datos automáticamente, por lo que no será necesario hacerlo de forma manual con `MoveNext()` y `Current`.

En C# también podemos crear lo que denominan [iteradores](https://learn.microsoft.com/dotnet/csharp/iterators), que son como las funciones generadoras de Python, es decir, una función que devuelve una secuencia que depende de la ejecución de la misma. Para ello se usa la sentencia `yield`, cuya sintaxis es:
 
$$\texttt{yield}\ \texttt{return}\ \mathit{expresi\acute{o}n} \texttt{;}$$

$$\texttt{yield}\ \texttt{break} \texttt{;}$$

Con `yield return` se devuelve un valor para la secuencia y con `yield break` termina el recorrido del enumerador. Por ejemplo:

```csharp
using System.Collections.Generic;
using static System.Console;

foreach (var num in Range(1, 10)) {
    Write($"{num} ");
}
WriteLine(); // 1 2 3 4 5 6 7 8 9

IEnumerable<int> Range (int start, int limit) {
    for (int i = start; i < limit; i++) {
        yield return i;
    }
}
```

Para entender mejor `yield break`, veamos este ejemplo:

```csharp
using System.Collections.Generic;
using static System.Console;

foreach (var num in ListaTriangulo(1, 4)) {
    Write($"{num} ");
}
WriteLine(); // 1 1 2 1 2 3

foreach (var num in ListaBreak(1, 4)) {
    Write($"{num} ");
}
WriteLine(); // 1

IEnumerable<int> ListaTriangulo (int start, int limit) {
    for (int i = start; i < limit; i++) {
        for (int j = start; ; j++) {
            yield return j;
            if (j >= i) break;
        }
    }
}

IEnumerable<int> ListaBreak (int start, int limit) {
    for (int i = start; i < limit; i++) {
        for (int j = start; ; j++) {
            yield return j;
            if (j >= i) yield break;
        }
    }
}
```

No se podrá usar `yield` en funciones cuyos parámetros tengan los modificadores `ref`, `in` o `out`, tampoco se puede usar en lambdas, funciones anónimas o en funciones con código `unsafe`.

> Las funciones iteradoras pueden ser asíncronas, que se explican en la sección de concurrencia y paralelismo. 

## LINQ

Dentro de [`System.Linq`](https://learn.microsoft.com/dotnet/api/system.linq) tenemos una serie de tipos que permiten al lenguaje aplicar consultas sobre estructuras de datos enumerables, por ejemplo, `IEnumerable<T>`.

### Operaciones

Hay varias categorías de operaciones, algunas tienen ejecución perezosa:

| Categoría | Pereza | Descripción |
|:---------:|:------:|:------------|
| Filtrado | Sí | Devuelve un subconjunto de elementos que cumplan una condición. |
| Proyección | Sí | Transforma un elemento en otro con una lambda. |
| Unión (*Join*) | Sí | Une los elementos de una secuencia con otra, usando una estrategia *lookup* (agrupando elementos con una misma clave designada). |
| Ordenación | Sí | Ordena los elementos de la secuencia. |
| Agrupamiento | Sí | Agrupa la secuencia en subsecuencias. |
| Conjunto | Sí | Realiza operaciones de conjunto utilizando dos secuencias. |
| Elemento | No | Obtiene un único valor de la secuencia. |
| Reducción | No | Ejecuta una operación sobre la secuencia para reducirla a un único valor. |
| Cuantificación | No | Evalúa una operación sobre la secuencia para devolver `true` o `false`. |
| Conversión: Importar | Sí | Convierte una secuencia no genérica en una genérica. |
| Conversión: Exportar | No | Convierte una secuencia en un array, lista, diccionario o *lookup*, forzando la evaluación completa de la secuencia. |
| Generación | Sí | Genera una secuencia simple. |

Las clases principales que contienen estas operaciones, como métodos extensibles, son [`System.Linq.Enumerable`](https://learn.microsoft.com/dotnet/api/system.linq.enumerable), [`System.Linq.Queryable`](https://learn.microsoft.com/dotnet/api/system.linq.queryable) y [`System.Linq.ParallelQuery`](https://learn.microsoft.com/dotnet/api/system.linq.parallelquery). Mientras que `Enumerable` realiza operaciones sobre [`IEnumerable<T>`](https://learn.microsoft.com/dotnet/api/system.collections.generic.ienumerable-1), la clase `Queryable` aplica sus operaciones sobre la interfaz [`IQueryable<T>`](https://learn.microsoft.com/dotnet/api/system.linq.iqueryable-1). La principal diferencia es que las secuencias de tipo `IEnumerable<T>` trabajan con datos que están instanciados en la memoria, mientras que las de tipo `IQueryable<T>` pueden trabajar contra una base de datos sin cargar todos los datos en memoria previamente. El caso de `ParallelQuery` es para poder ejecutar consultas con ejecución en paralelo de secuencias de tipo `IEnumerable<T>`.

Las operaciones de *filtrado* son:

| Método | Descripción | Ejemplos |
|:------:|:------------|:---------|
| `Where` | Filtra una secuencia en base a un predicado. | `X.Where(x => x % 2 == 0)`<br/>`X.Where((x, i) => x > i)` |
| `Take` | Devuelve una subsecuencia de elementos, tomando los N primeros elementos o un rango de ellos. | `X.Take(5)`<br/>`X.Take(4..8)` |
| `Skip` | Devuelve una subsecuencia de elementos, saltándose los N primeros elementos. | `X.Skip(5)` |
| `TakeWhile` | Devuelve una subsecuencia de elementos, tomando los N primeros elementos que cumplan un predicado. | `X.TakeWhile(x => x % 2 == 0)`<br/>`X.TakeWhile((x, i) => x > i)` |
| `SkipWhile` | Devuelve una subsecuencia de elementos, saltándose los N primeros elementos que cumplan un predicado. | `X.SkipWhile(x => x % 2 == 0)`<br/>`X.SkipWhile((x, i) => x > i)` |
| `TakeLast` | Devuelve una subsecuencia de elementos, tomando los N últimos elementos. | `X.TakeLast(5)` |
| `SkipLast` | Devuelve una subsecuencia de elementos, saltándose los N últimos elementos. | `X.SkipLast(5)` |
| `Distinct` | Devuelve una secuencia eliminando los duplicados. | `X.Distinct()` |
| `DistinctBy` | **C# 10:** Devuelve una secuencia eliminando los duplicados en base a una función selectora. | `X.DistinctBy(x => x.Clave)` |

Las operaciones de *proyección* son:

| Método | Descripción | Ejemplos |
|:------:|:------------|:---------|
| `Select` | Transforma cada elemento de una secuencia en otro objeto. | `X.Select(x => x)`<br/>`X.Select((x, i) => (i, x))` |
| `SelectMany` | Una versión transforma cada elemento de una secuencia en otra secuencia y la aplana en una secuencia única. La otra versión combina el elemento original con cada valor de la secuencia devuelta. | `X.SelectMany(x => x.Y)`<br/>`X.SelectMany((x, i) => x.Y)`<br/>`X.SelectMany(x => x.Y, (x, y) => (x, y))`<br/>`X.SelectMany((x, i) => x.Y, (x, y) => (x, y))` |

Las operaciones de *unión (join)* son:

| Método | Descripción | Ejemplos |
|:------:|:------------|:---------|
| `Join` | Une los elementos de una secuencia con otra (*inner join*) en base a una función selectora, para cada secuencia, y con otra función une cada par de elementos en un único objeto. | `X.GroupJoin(Y, x => x.Clave, y => y.Clave, (x, y) => (x, y))` |
| `GroupJoin` | Ejecuta una *inner join*, como con `Join`, pero en lugar de unir los elementos dos a dos, agrupa los elementos de la segunda secuencia en una subsecuencia. | `X.GroupJoin(Y, x => x.Clave, y => y.Clave, (x, ys) => (x, ys))` |
| `Zip` | Une dos o tres secuencias en un solo objeto, por defecto una tupla. | `X.Zip(Y)`<br/>`X.Zip(Y, Z)`<br/>`X.Zip(Y, (x, y) => (x, y))` |

Las operaciones de *ordenación* son:

| Método | Descripción | Ejemplos |
|:------:|:------------|:---------|
| `OrderBy` | Ordena los elementos de una secuencia en orden ascendiente en base a una función selectora. | `X.OrderBy(x => x.Clave)` |
| `ThenBy` | Añade otro factor de ordenación ascendiente a los elementos de una secuencia en base a una función selectora. | `X.ThenBy(x => x.Clave)` |
| `OrderByDescending` | Ordena los elementos de una secuencia en orden descendiente en base a una función selectora. | `X.OrderByDescending(x => x.Clave)` |
| `ThenByDescending` | Añade otro factor de ordenación descendiente a los elementos de una secuencia en base a una función selectora. | `X.ThenByDescending(x => x.Clave)` |
| `Reverse` | Invierte el orden de los elementos de una secuencia. | `X.Reverse()` |
| `Order` | **C# 11:** Ordena los elementos de una secuencia en orden ascendiente. | `X.Order()` |
| `OrderDescending` | **C# 11:** Ordena los elementos de una secuencia en orden descendiente. | `X.OrderDescending()` |

Las operaciones de *agrupamiento* son:

| Método | Descripción | Ejemplos |
|:------:|:------------|:---------|
| `GroupBy` | Agrupa los elementos de una secuencia en base a una función selectora. También se puede indicar los elementos que agrupar, y la forma de agruparlos, con sus respectivas funciones. | `X.GroupBy(x => x.Clave)`<br/>`X.GroupBy(x => x.Clave, (clave, items) => items)`<br/>`X.GroupBy(x => x.Clave, x => x.Items)`<br/>`X.GroupBy(x => x.Clave, x => x.Items, (clave, items) => items)` |

Las operaciones de *conjunto* son:

| Método | Descripción | Ejemplos |
|:------:|:------------|:---------|
| `Concat` | Devuelve la concatenación de dos secuencias. | `X.Concat(Y)` |
| `Union` | Devuelve la unión entre dos secuencias. | `X.Union(Y)` |
| `Intersect` | Devuelve la intersección entre dos secuencias. | `X.Intersect(Y)` |
| `Except` | Devuelve la diferencia entre dos secuencias. | `X.Except(Y)` |
| `UnionBy` | **C# 10:** Devuelve la unión entre dos secuencias en base a una función selectora. | `X.UnionBy(Y, xy => xy.Clave)` |
| `IntersectBy` | **C# 10:** Devuelve la intersección entre dos secuencias en base a una función selectora. | `X.IntersectBy(Y, xy => xy.Clave)` |
| `ExceptBy` | **C# 10:** Devuelve la diferencia entre dos secuencias en base a una función selectora. | `X.ExceptBy(Y, xy => xy.Clave)` |

Las operaciones de *elemento* son:

| Método | Descripción | Ejemplos |
|:------:|:------------|:---------|
| `First` | Devuelve el primer elemento que hay en la secuencia, o el primero que cumple el predicado. Si no, lanza una excepción. | `X.First()`<br/>`X.First(x => x == 42)` |
| `FirstOrDefault` | Devuelve el primer elemento que hay en la secuencia, o el primero que cumple el predicado. Si no, el valor por defecto. | `X.FirstOrDefault()`<br/>`X.FirstOrDefault(-42)`<br/>`X.FirstOrDefault(x => x == 42)`<br/>`X.FirstOrDefault(x => x == 42, -42)` |
| `Last` | Devuelve el último elemento que hay en la secuencia, o el último que cumple el predicado. Si no, lanza una excepción. | `X.Last()`<br/>`X.Last(x => x == 42)` |
| `LastOrDefault` | Devuelve el último elemento que hay en la secuencia, o el último que cumple el predicado. Si no, el valor por defecto. | `X.LastOrDefault()`<br/>`X.LastOrDefault(-42)`<br/>`X.LastOrDefault(x => x == 42)`<br/>`X.LastOrDefault(x => x == 42, -42)` |
| `Single` | Devuelve el único elemento que hay en la secuencia, o el único que cumple el predicado. Si no, lanza una excepción. | `X.Single()`<br/>`X.Single(x => x == 42)` |
| `SingleOrDefault` | Devuelve el único elemento que hay en la secuencia, o el único que cumple el predicado. Si no, el valor por defecto. | `X.SingleOrDefault()`<br/>`X.SingleOrDefault(-42)`<br/>`X.SingleOrDefault(x => x == 42)`<br/>`X.SingleOrDefault(x => x == 42, -42)` |
| `ElementAt` | Devuelve un elemento de la secuencia en una posición. Si no, lanza una excepción. | `X.ElementAt(1)`<br/>`X.ElementAt(^2)` |
| `ElementAtOrDefault` | Devuelve un elemento de la secuencia en una posición. Si no, el valor por defecto para el tipo de los elementos. | `X.ElementAtOrDefault(1)`<br/>`X.ElementAtOrDefault(^2)` |
| `DefaultIfEmpty` | Devuelve la secuencia si no está vacía. Si no, una secuencia con el valor por defecto como único elemento. | `X.DefaultIfEmpty()`<br/>`X.DefaultIfEmpty(42)` |

Las operaciones de *reducción* son:

| Método | Descripción | Ejemplos |
|:------:|:------------|:---------|
| `Count` | Calcula el número de elementos que hay en una secuencia o cuantos cumplen un predicado. | `X.Count()`<br/>`X.Count(x => x > 0)` |
| `LongCount` | Calcula el número de elementos que hay en una secuencia o cuantos cumplen un predicado. | `X.LongCount()`<br/>`X.LongCount(x => x > 0)` |
| `Min` | Calcula el valor mínimo de una secuencia. | `X.Min()`<br/>`X.Min(x => x.Valor)` |
| `Max` | Calcula el valor máximo de una secuencia. | `X.Max()`<br/>`X.Max(x => x.Valor)` |
| `Sum` | Calcula la suma de una secuencia numérica. | `X.Sum()`<br/>`X.Sum(x => x.Num)` |
| `Average` | Calcula la media de una secuencia numérica. | `X.Average()`<br/>`X.Average(x => x.Num)` |
| `Aggregate` | Reduce una secuencia a un único valor utilizando una función transformadora. | `X.Aggregate(1, (accum, x) => accum * x)`<br/>`X.Aggregate((accum, x) => $"{accum}, {x}")` |
| `MinBy` | **C# 10:** Devuelve el valor mínimo de una secuencia en base a una función selectora. | `X.MinBy(x => x.Clave)` |
| `MaxBy` | **C# 10:** Devuelve el valor máximo de una secuencia en base a una función selectora. | `X.MaxBy(x => x.Clave)` |
| `TryGetNonEnumeratedCount` | **C# 10:** Intenta determinar el número de elementos de la secuencia sin evaluarla entera. Si lo logra devuelve `true` y el tamaño en el parámetro de salida, si no `false`. | `X.TryGetNonEnumeratedCount(out n)` |

Las operaciones de *cuantificación* son:

| Método | Descripción | Ejemplos |
|:------:|:------------|:---------|
| `Contains` | Comprueba si una secuencia contiene un elemento. | `X.Contains(0)` |
| `Any` | Comprueba que la secuencia no esté vacía o que se cumpla un predicado para algún elemento. | `X.Any()`<br/>`X.Any(x => x  > 0)` |
| `All` | Comprueba si una secuencia cumple un predicado para todos sus elementos. Si la secuencia está vacía también devolverá `true`. | `X.All(x => x  > 0)` |
| `SequenceEqual` | Comprueba si una secuencia es igual a otra. | `X.SequenceEqual(Y)` |

Las operaciones de *conversión (importar)* son:

| Método | Descripción | Ejemplos |
|:------:|:------------|:---------|
| `OfType` | Filtra el contenido de un `IEnumerable` para ajustarlo al tipo `IEnumerable<T>`. | `X.OfType<int>()` |
| `Cast` | Aplica un *casting* sobre un `IEnumerable` para devolver un `IEnumerable<T>`. | `X.Cast<string>()` |

Las operaciones de *conversión (exportar)* son:

| Método | Descripción | Ejemplos |
|:------:|:------------|:---------|
| `ToArray` | Convierte la secuencia al tipo `T[]`. | `X.ToArray()` |
| `ToList` | Convierte la secuencia al tipo `List<T>` de `System.Collections.Generic`. | `X.ToList()` |
| `ToDictionary` | Convierte la secuencia al tipo `Dictionary<TKey,TElement>` de `System.Collections.Generic`. | `X.ToDictionary(x => x.Clave)`<br/>`X.ToDictionary(x => x.Clave, x => x.Elemento)` |
| `ToLookup` | Convierte la secuencia al tipo `X.ILookup<TKey,TElement>` de `System.Linq`. | `ToLookup(x => x.Clave)`<br/>`X.ToLookup(x => x.Clave, x => x.Elemento)` |
| `ToHashSet` | Convierte la secuencia al tipo `X.HashSet<T>` de `System.Collections.Generic`. | `X.ToHashSet()` 
| `AsEnumerable` | **Enumerable:** Convierte la secuencia al tipo `IEnumerable<T>`. | `X.AsEnumerable()` |
| `AsQueryable` | **Queryable:** Convierte la secuencia al tipo `IQueryable<T>`. | `X.AsQueryable()` |

Las operaciones de *generación* son:

| Método | Descripción | Parámetros | Ejemplos |
|:------:|:------------|:-----------|:---------|
| `Empty` | Crea una secuencia vacía del tipo indicado. | - | `Enumerable.Empty<float>()` |
| `Range` | Crea una secuencia de números sucesivos. | `start`: Número inicial.<br/>`count`: Número de elementos. | `Enumerable.Range(1, 10)` |
| `Repeat` | Crea una secuencia de elementos repetidos. | `element`: Elemento a repetir.<br/>`count`: Número de repeticiones. | `Enumerable.Repeat('Ñ', 6)` |

Otras operaciones disponibles son:

| Método | Descripción | Ejemplos |
|:------:|:------------|:---------|
| `Append` | Añade un elemento al final de la secuencia, sin modificar la secuencia original. | `X.Append('Z')` |
| `Prepend` | Añade un elemento al inicio de la secuencia, sin modificar la secuencia original. | `X.Prepend('A')` |
| `Chunk` | Divide la secuencia en arrays de un tamaño máximo indicado. | `X.Chunk(5)` |

En los ejemplos de las tablas, `X`, `Y` y `Z`, representan un objeto secuencia. Muchas de estas operaciones devuelven una secuencia, por lo que se pueden encadenar varias operaciones, para realizar transformaciones más complejas:

```csharp
using System.Linq;
using static System.Console;

var foo = Enumerable.Range(1, 10)
                    .SelectMany(x => Enumerable.Range(1, x),
                                (x, y) => x * y)
                    .Where(x => x % 2 == 0)
                    .Distinct()
                    .OrderBy(x => x);
WriteLine(string.Join(", ", foo));
```

> Muchas de las operaciones necesitan que el tipo de los elementos tenga ciertas interfaces de comparación implementadas. Si no fuera el caso, se puede pasar como parámetro un objeto que implemente la interfaz [`IComparer<T>`](https://learn.microsoft.com/dotnet/api/system.collections.generic.icomparer-1) o [`IEqualityComparer<T>`](https://learn.microsoft.com/dotnet/api/system.collections.generic.iequalitycomparer-1).

### Consultas

Otra forma alternativa de usar LINQ es mediante la sintaxis de [consultas](https://learn.microsoft.com/dotnet/csharp/programming-guide/concepts/linq/introduction-to-linq-queries) similares al lenguaje SQL, que utiliza las siguientes palabras clave:

| Operación | Función | Descripción | Sintaxis |
|:---------:|:-------:|:------------|:---------|
| `from` | - | Recorre una secuencia de datos. | `from variable in secuencia` |
| `let` | - | Añade una variable nueva. | `let variable = expresión` |
| `where` | `Where()` | Filtra los elementos. | `where condición` |
| `orderby` | `OrderBy()`<br/>`ThenBy()`<br/>`OrderByDescending()`<br/>`ThenByDescending()` | Ordena los elementos. Se pueden indicar varios niveles de ordenación separados por comas. | `orderby expresión`<br/>`orderby expresión ascending`<br/>`orderby expresión descending` |
| `join` | `Join()` | Une elementos de dos secuencias en base a una clave. | `join variable in secuencia on clave2 equals clave` |
| `join` | `GroupJoin()` | Agrupa una secuencia en base a una clave exterior. | `join variable in secuencia on clave2 equals clave into variable` |
| `select` | `Select()` | Transforma los elementos con una proyección. | `select expresión` |
| `group` | `GroupBy()` | Agrupa elementos en base a una clave. | `group elemento by clave` |
| `into` | - | Asigna el resultado actual de la consulta en una nueva variable. | `into variable` |

La sintaxis de las consultas LINQ está un poco más restringida que mediante el uso de funciones. Se ha de empezar con uno o varios `from`, seguidos de una o varias cláusulas `let`, `join`, `orderby`, `where`, sin importar el orden. En la tercera fase se ha de utilizar una cláusula `select` o `group`, que podrá terminar la consulta o derivar su resultado a un `into` para poder añadir cláusulas de fases anteriores. Por ejemplo:

```csharp
using System.Linq;
using static System.Console;

var bar = from x in Enumerable.Range(1, 10)
          from y in Enumerable.Range(1, x)
          let z = x * y
          where z % 2 == 0
          group z by z into zs
          orderby zs.First()
          select zs.First();
WriteLine(string.Join(", ", bar));
```

## Concurrencia y paralelismo

### Tareas

Con las palabras claves [`async`](https://learn.microsoft.com/dotnet/csharp/language-reference/keywords/async) y [`await`](https://learn.microsoft.com/dotnet/csharp/language-reference/operators/await) se puede incorporar [programación asíncrona](https://learn.microsoft.com/dotnet/csharp/programming-guide/concepts/async/) en los programas. Esto permite que se ejecute código sin bloquear el hilo principal a la espera de los resultados. Para lograr esto tenemos los tipos [`Task`](https://learn.microsoft.com/dotnet/api/system.threading.tasks.task) y [`Task<T>`](https://learn.microsoft.com/dotnet/api/system.threading.tasks.task-1) en el espacio de nombres [`System.Threading.Tasks`](https://learn.microsoft.com/dotnet/api/system.threading.tasks), que encapsulan lo que es una tarea a ejecutar de forma asíncrona.

El modificador `async` se puede aplicar a funciones y a expresiones lambda, para convertir dicha función en código asíncrono. No obstante, para que realmente pueda ser asíncrona, requiere el uso del operador `await` en su interior, que indica al programa que tiene que esperar a que se termine de completar la tarea asíncrona indicada. Por ejemplo:

```csharp
using System.Linq;
using System.Threading.Tasks;
using static System.Console;

WriteLine("(Iniciando tareas)");
var random = new System.Random();
var tareas = Enumerable.Range(0, 5)
                       .Select(i => Tarea(i, random.Next(100, 500)))
                       .ToArray();
WriteLine("(Esperando tareas)");
Task.WaitAll(tareas);
WriteLine("(Tareas terminadas)");

async Task Tarea (int i, int ms) {
    WriteLine($"Tarea {i} iniciada.");
    await Task.Delay(ms);
    WriteLine($"Tarea {i} terminada.");
}
```

Hay algunas limitaciones para que una función sea `async`. Los [tipos de retorno](https://learn.microsoft.com/dotnet/csharp/programming-guide/concepts/async/async-return-types) de la función han de estar comprendidos en: [`Task`](https://learn.microsoft.com/dotnet/api/system.threading.tasks.task), [`Task<T>`](https://learn.microsoft.com/dotnet/api/system.threading.tasks.task-1), [`IAsyncEnumerable<T>`](https://learn.microsoft.com/dotnet/api/system.collections.generic.iasyncenumerable-1), `void` para eventos, y tipos con el método `GetAwaiter()` (por ejemplo, [`ValueTask`](https://learn.microsoft.com/dotnet/api/system.threading.tasks.valuetask) o [`ValueTask<T>`](https://learn.microsoft.com/dotnet/api/system.threading.tasks.valuetask-1)). Tampoco podrá tener parámetros con los modificadores `ref`, `out` e `in`. Si queremos hacer asíncrono el método `Main`, tendrá que tener como tipo de retorno `Task` o `Task<int>`.

En el caso de que la función devuelva un valor con `Task<T>`, el operador `await` se encargará de obtenerlo, consultando la propiedad `Result` del tipo, para asignarlo a una variable. Luego en la clase `Task`, los principales miembros disponibles son:

| Miembro | Descripción |
|:-------:|:------------|
| `Exception` | Excepción lanzada durante la ejecución de la tarea, si esta termina prematuramente. Si no, devuelve `null`. |
| `Id` | El ID de la tarea. |
| `IsCanceled` | Indica si la tarea ha sido cancelada. |
| `IsCompleted` | Indica si la tarea ha sido completada, independientemente de si ha tenido éxito o no. |
| `IsCompletedSuccessfully` | Indica si la tarea ha sido completada con éxito. |
| `IsFaulted` | Indica si la tarea ha terminado por una excepción. |
| `Status` | Devuelve el estado de la tarea con el tipo `TaskStatus`, cuyos valores son: `Canceled`, `Created`, `Faulted`, `RanToCompletion`, `Running`, `WaitingForActivation`, `WaitingForChildrenToComplete`, `WaitingToRun`. |
| `ContinueWith(Task<Task>)`<br/>`ContinueWith<T>(Func<Task,T>)` | Crea una continuación para ser ejecutada asíncronamente cuando la tarea sea completada. |
| `Dispose()` | Libera todos los recursos usados por el objeto que ejecuta la tarea (la instancia de `Task)`. |
| `RunSynchronously()` | Ejecuta la tarea de forma síncrona dentro del planificador actual. |
| `Start()` | Inicia la ejecución de la tarea, siendo gestionada por el planificador actual. |
| `Wait()` | Espera a que se complete la ejecución de la tarea. |
| `WaitAsync(CancellationToken)`<br/>`WaitAsync(TimeSpan)` | Devuelve una tarea que terminará cuando la tarea actual termine o se indique una señal de cancelación o haya transcurrido un tiempo de espera. |

Entre los principales miembros estáticos de la clase `Task` tenemos:

| Miembro | Descripción |
|:-------:|:------------|
| `CurrentId` | El ID de la tarea actual en ejecución. |
| `Delay(int)` | Crea una tarea que se completa tras un tiempo de espera. |
| `FromCanceled(CancellationToken)`<br/>`FromCanceled<T>(CancellationToken)` | Crea una tarea que se completa debido a una señal de cancelación. |
| `FromException(Exception)`<br/>`FromException<T>(Exception)` | Crea una tarea que se completa debido a una excepción lanzada. |
| `FromResult<T>(T) ` | Crea una tarea que se completa con éxito con un resultado determinado. |
| `Run(Action)`<br/>`Run<T>(Func<T>)` | Crea una tarea para añadirla a la cola de ejecuciones y la devuelve. |
| `WaitAll(Task[])` | Espera a que se complete la ejecución de un grupo de tareas. |
| `WaitAny(Task[])` | Espera a que se complete la ejecución de alguna tarea en el grupo indicado. |
| `WhenAll(IEnumerable<Task>)`<br/>`WhenAll<T>(IEnumerable<Task<T>>)` | Crea una tarea que se completa cuando todas las tareas de un grupo se completen. |
| `WhenAny(IEnumerable<Task>)`<br/>`WhenAny<T>(IEnumerable<Task<T>>)` | Crea una tarea que se completa cuando se complete alguna de las tareas en el grupo. |
| `Yield()` | Crea una tarea asíncrona que retorna cuando se utiliza el operador `await`. |

Cuando se quiere usar una operación de espera con tareas, es preferible usar una versión que pueda usar `await`, ya que así la ejecución actual es suspendida hasta obtener el resultado, pudiendo así ejecutar otras cosas mientras. Por ello se recomienda que:

| Caso | Bloqueo | Espera |
|:----:|:-------:|:------:|
| Resultado | `Task.Wait` o `Task.Result` | `await` |
| Esperar a una | `Task.WaitAny` | `await Task.WhenAny` |
| Esperar a todas | `Task.WaitAll` | `await Task.WhenAll` |
| Esperar un tiempo | `Thread.Sleep` | `await Task.Delay` |

También se puede utilizar `await` con las sentencias:

$$\texttt{await}\ \texttt{using}\ \texttt{(} \mathit{tipo}\ \mathit{nombre}\ \texttt{=}\ \mathit{expresi\acute{o}n} \texttt{)}\ \mathit{bloque}$$

$$\texttt{await}\ \texttt{foreach}\ \texttt{(} \mathit{tipo}\ \mathit{nombre}\ \texttt{in}\ \mathit{contenedor} \texttt{)}\ \mathit{bloque}$$

La primera nos permite liberar recursos de forma asíncrona, que deberán implementar la interfaz [`System.IAsyncDisposable`](https://learn.microsoft.com/dotnet/api/system.iasyncdisposable). La segunda nos permite recorrer una secuencia que se genera de forma asíncrona, que deberá implementar la interfaz [`System.Collections.IAsyncEnumerable<T>`](https://learn.microsoft.com/dotnet/api/system.collections.generic.iasyncenumerable-1), que devuelve un objeto de tipo [`System.Collections.IAsyncEnumerator<T>`](https://learn.microsoft.com/dotnet/api/system.collections.generic.iasyncenumerator-1) con `GetAsyncEnumerator()`. Por ejemplo:

```csharp
using System;
using System.IO;
using System.Collections.Generic;

var texto = @"En un lugar de la Mancha, de cuyo nombre no quiero 
              acordarme, no ha mucho tiempo que vivía un hidalgo
              de los de lanza en astillero, adarga antigua, rocín
              flaco y galgo corredor.";

await foreach (var palabra in Palabras(texto)) {
    Console.Write(palabra + " ");
}

async IAsyncEnumerable<string> Palabras (string datos) {
    using var lector = new StringReader(datos);
    string cadena;
    do {
        cadena = await lector.ReadLineAsync();
        if (cadena != null) {
            foreach (var palabra in cadena.Split(' ', StringSplitOptions.RemoveEmptyEntries)) {
                yield return palabra;
            }
        }
    } while (cadena != null);
}
```

Por último, tenemos la clase estática [`Parallel`](https://learn.microsoft.com/dotnet/api/system.threading.tasks.parallel) que permite ejecutar bucles de forma paralela de forma sencilla. Para ello tiene los métodos `For`, `ForEach` y `ForEachAsync`. Por ejemplo:

```csharp
using System.Threading;
using System.Threading.Tasks;
using static System.Console;

var random = new System.Random();
Parallel.For(0, 5, i => {
    WriteLine($"Tarea {i} iniciada.");
    Thread.Sleep(random.Next(100, 500));
    WriteLine($"Tarea {i} terminada.");
});
```

### Hilos

En el hipotético caso de que necesitemos cosas más avanzadas para trabajar, en el espacio de nombres [`System.Threading`](https://learn.microsoft.com/dotnet/api/system.threading) tenemos tipos para crear y manejar hilos en programas. La clase principal es [`Thread`](https://learn.microsoft.com/dotnet/api/system.threading.thread), que encapsula un hilo de ejecución en la aplicación. Por ejemplo:

```csharp
using System.Linq;
using System.Threading;
using static System.Console;

var random = new System.Random();
var tareas = Enumerable.Range(0, 5).Select(Crear).ToArray();

Estado(tareas);
Thread.Sleep(1000);
Estado(tareas);

void Estado (Thread[] tareas) =>
    WriteLine(string.Join(", ", tareas.Select((x, i) => $"{i}={x.IsAlive}")));

Thread Crear (int i) {
    var hilo = new Thread(Tarea);
    hilo.Start((i, random.Next(100, 500)));
    return hilo;
}

void Tarea (object datos) {
    (int i, int ms) = ((int, int)) datos;
    WriteLine($"Tarea {i} iniciada.");
    Thread.Sleep(ms);
    WriteLine($"Tarea {i} terminada.");
}
```

Luego tenemos clases como [`Mutex`](https://learn.microsoft.com/dotnet/api/system.threading.mutex), [`Semaphore`](https://learn.microsoft.com/dotnet/api/system.threading.semaphore) o [`Monitor`](https://learn.microsoft.com/dotnet/api/system.threading.monitor), que permiten incorporar mecanismos de bloqueo para acceder a determinadas partes de código de forma ordenada.

También está la sentencia `lock` para garantizar la exclusión mutua al acceder a un recurso del programa. Su sintaxis es:

$$\texttt{lock}\ \texttt{(} \mathit{variable} \texttt{)}\ \mathit{bloque}$$

Internamente utiliza un `Monitor` para realizar la tarea, por lo que la variable ha de ser un tipo por referencia.

## Biblioteca estándar

Estos son los principales espacios de nombres de la [API de .NET](https://learn.microsoft.com/dotnet/api/):

| Nombre | Descripción |
|:-------|:------------|
| [`System`](https://learn.microsoft.com/dotnet/api/system) | Tipos fundamentales del sistema. |
| [`System.Buffers`](https://learn.microsoft.com/dotnet/api/system.buffers) | Tipos para buffers de memoria. |
| [`System.Collections`](https://learn.microsoft.com/dotnet/api/system.collections) | Tipos para contenedores de objetos, tales como listas, colas, arrays de bits, tablas hash y diccionarios. |
| [`System.Collections.Concurrent`](https://learn.microsoft.com/dotnet/api/system.collections.concurrent) | Tipos para contenedores de objetos que puedan ser usados de forma segura en sistemas con ejecución concurrente y/o paralela. |
| [`System.Collections.Generic`](https://learn.microsoft.com/dotnet/api/system.collections.generic) | Tipos genéricos para contenedores de objetos, tales como listas, colas, pilas, diccionarios y conjuntos. |
| [`System.Collections.Immutable`](https://learn.microsoft.com/dotnet/api/system.collections.immutable) | Tipos para contenedores inmutables de objetos. |
| [`System.Collections.ObjectModel`](https://learn.microsoft.com/dotnet/api/system.collections.objectmodel) | Tipos para contenedores de objetos que sirva de base para modelos de datos en otras bibliotecas. |
| [`System.Collections.Specialized`](https://learn.microsoft.com/dotnet/api/system.collections.specialized) | Tipos para contenedores especializados de objetos. |
| [`System.ComponentModel`](https://learn.microsoft.com/dotnet/api/system.componentmodel) | Tipos que se utilizan para implementar el comportamiento en tiempo de ejecución y en tiempo de diseño de componentes y controles. |
| [`System.Data`](https://learn.microsoft.com/dotnet/api/system.data) | Tipos para manejar datos de múltiples fuentes con la arquitectura ADO.NET. |
| [`System.Data.Common`](https://learn.microsoft.com/dotnet/api/system.data.common) | Tipos para proveedores de datos para .NET. |
| [`System.Data.SqlTypes`](https://learn.microsoft.com/dotnet/api/system.data.sqltypes) | Tipos para datos nativos en SQL Server. |
| [`System.Diagnostics`](https://learn.microsoft.com/dotnet/api/system.diagnostics) | Tipos para interactuar con procesos del sistema, logs de eventos y medidores de rendimiento. |
| [`System.Diagnostics.CodeAnalysis`](https://learn.microsoft.com/dotnet/api/system.diagnostics.codeanalysis) | Tipos para interactuar con herramientas de análisis de código. |
| [`System.Diagnostics.Contracts`](https://learn.microsoft.com/dotnet/api/system.diagnostics.contracts) | Tipos para representar contratos de código, tales como precondiciones, postcondiciones e invariantes. |
| [`System.Diagnostics.Metrics`](https://learn.microsoft.com/dotnet/api/system.diagnostics.metrics) | Tipos para realizar métricas en programas. |
| [`System.Diagnostics.SymbolStore`](https://learn.microsoft.com/dotnet/api/system.diagnostics.symbolstore) | Tipos que permiten leer y escribir información simbólica de depuración. |
| [`System.Diagnostics.Tracing`](https://learn.microsoft.com/dotnet/api/system.diagnostics.tracing) | Tipos para generar eventos de trazado en Windows (EWT). |
| [`System.Dynamic`](https://learn.microsoft.com/dotnet/api/system.dynamic) | Tipos para dar soporte al entorno de ejecución de lenguajes dinámicos. |
| [`System.Formats.Asn1`](https://learn.microsoft.com/dotnet/api/system.formats.asn1) | Tipos para el formato ASN.1 (Abstract Syntax Notation One). |
| [`System.Formats.Tar`](https://learn.microsoft.com/dotnet/api/system.formats.tar) | Tipos para el formato TAR. |
| [`System.Globalization`](https://learn.microsoft.com/dotnet/api/system.globalization) | Tipos para la localización de formatos y lenguaje. |
| [`System.IO`](https://learn.microsoft.com/dotnet/api/system.io) | Tipos para manejar flujos de datos, ficheros y directorios. |
| [`System.IO.Compression`](https://learn.microsoft.com/dotnet/api/system.io.compression) | Tipos para comprimir y descomprimir flujos de datos. |
| [`System.IO.Pipes`](https://learn.microsoft.com/dotnet/api/system.io.pipes) | Tipos para comunicar procesos mediante tuberías. |
| [`System.Linq`](https://learn.microsoft.com/dotnet/api/system.linq) | Tipos para realizar consultas con el lenguaje LINQ. |
| [`System.Linq.Expressions`](https://learn.microsoft.com/dotnet/api/system.linq.expressions) | Tipos para representar expresiones del lenguaje como árboles de expresiones. |
| [`System.Net`](https://learn.microsoft.com/dotnet/api/system.net) | Tipos para manejar diferentes protocolos de red modernos. |
| [`System.Net.Http`](https://learn.microsoft.com/dotnet/api/system.net.http) | Tipos para manejar el protocolo HTTP. |
| [`System.Net.Mail`](https://learn.microsoft.com/dotnet/api/system.net.mail) | Tipos para enviar emails con el protocolo SMTP. |
| [`System.Net.NetworkInformation`](https://learn.microsoft.com/dotnet/api/system.net.networkinformation) | Tipos para obtener información sobre la red. |
| [`System.Net.Security`](https://learn.microsoft.com/dotnet/api/system.net.security) | Tipos para manejar flujos de comunicación seguros. |
| [`System.Net.Sockets`](https://learn.microsoft.com/dotnet/api/system.net.sockets) | Tipos para comunicarse con *sockets*. |
| [`System.Net.WebSockets`](https://learn.microsoft.com/dotnet/api/system.net.websockets) | Tipos para comunicarse con *websockets*. |
| [`System.Numerics`](https://learn.microsoft.com/dotnet/api/system.numerics) | Tipos para complementar los tipos primitivos numéricos del lenguaje. |
| [`System.Reflection`](https://learn.microsoft.com/dotnet/api/system.reflection) | Tipos para inspeccionar y manipular en tiempo de ejecución los tipos del lenguaje. |
| [`System.Reflection.Emit`](https://learn.microsoft.com/dotnet/api/system.reflection.emit) | Tipos para construir código en tiempo de ejecución en formato MSIL para ejecutarlo o guardarlo en disco. Estas herramientas están pensadas para motores de script y compiladores. |
| [`System.Resources`](https://learn.microsoft.com/dotnet/api/system.resources) | Tipos para manejar ficheros de recursos con diferentes idiomas. |
| [`System.Runtime`](https://learn.microsoft.com/dotnet/api/system.runtime) | Tipos para dar soporte al entorno de ejecución. |
| [`System.Runtime.Remoting`](https://learn.microsoft.com/dotnet/api/system.runtime.remoting) | Tipos para crear y configurar aplicaciones distribuidas. |
| [`System.Runtime.Serialization`](https://learn.microsoft.com/dotnet/api/system.runtime.serialization) | Tipos para serializar y deserializar objetos. |
| [`System.Security`](https://learn.microsoft.com/dotnet/api/system.security) | Tipos para dar soporte a la seguridad y permisos de ejecución. |
| [`System.Security.Cryptography`](https://learn.microsoft.com/dotnet/api/system.security.cryptography) | Tipos para manejar operaciones y servicios de criptografía. |
| [`System.Text`](https://learn.microsoft.com/dotnet/api/system.text) | Tipos para codificar y decodificar cadenas de texto. |
| [`System.Text.Encodings.Web`](https://learn.microsoft.com/dotnet/api/system.text.encodings.web) | Tipos para codificar texto a formato HTML, JavaScript y URL. |
| [`System.Text.Json`](https://learn.microsoft.com/dotnet/api/system.text.json) | Tipos para serializar y deserializar en formato JSON. |
| [`System.Text.Json.Nodes`](https://learn.microsoft.com/dotnet/api/system.text.json.nodes) | Tipos para manejar valores JSON en memoria con DOM. |
| [`System.Text.Json.Serialization`](https://learn.microsoft.com/dotnet/api/system.text.json.serialization) | Tipos para serializar y deserializar objetos a formato JSON de forma personalizada para tipos de usuario. |
| [`System.Text.RegularExpressions`](https://learn.microsoft.com/dotnet/api/system.text.regularexpressions) | Tipos para manejar expresiones regulares. |
| [`System.Text.Unicode`](https://learn.microsoft.com/dotnet/api/system.text.unicode) | Tipos para manejar el formato Unicode. |
| [`System.Threading`](https://learn.microsoft.com/dotnet/api/system.threading) | Tipos para dar soporte a la programación multihilo. |
| [`System.Threading.Channels`](https://learn.microsoft.com/dotnet/api/system.threading.channels) | Tipos para manejar canales de comunicación entre hilos. |
| [`System.Threading.Tasks`](https://learn.microsoft.com/dotnet/api/system.threading.tasks) | Tipos para trabajar de forma simple con código concurrente y asíncrono. |
| [`System.Threading.Tasks.Dataflow`](https://learn.microsoft.com/dotnet/api/system.threading.tasks.dataflow) | Tipos para programar en un modelo basado en actores, que soporta paso de mensajes para flujos de datos de grano grueso y canalización de tareas. |
| [`System.Timers`](https://learn.microsoft.com/dotnet/api/system.timers) | Tipos para manejar temporizadores. |
| [`System.Transactions`](https://learn.microsoft.com/dotnet/api/system.transactions) | Tipos para crear aplicaciones y gestores de recursos transaccionales. |
| [`System.Xml`](https://learn.microsoft.com/dotnet/api/system.xml) | Tipos para procesar el formato XML. |
| [`System.Xml.Linq`](https://learn.microsoft.com/dotnet/api/system.xml.linq) | Tipos para utilizar LINQ con el formato XML. |
| [`System.Xml.Schema`](https://learn.microsoft.com/dotnet/api/system.xml.schema) | Tipos para dar soporte al lenguaje XSD (XML Schema Definition). |
| [`System.Xml.Serialization`](https://learn.microsoft.com/dotnet/api/system.xml.serialization) | Tipos para serializar y deserializar en formato XML. |
| [`System.Xml.XPath`](https://learn.microsoft.com/dotnet/api/system.xml.xpath) | Tipos para dar soporte a XQuery 1.0 y XPath 2.0. |
| [`System.Xml.Xsl`](https://learn.microsoft.com/dotnet/api/system.xml.xsl) | Tipos para dar soporte a XSLT (Extensible Stylesheet Transformation). |

También tenemos para la plataforma Windows estos espacios de nombres:

| Nombre | Descripción |
|:-------|:------------|
| [`System.Windows`](https://learn.microsoft.com/dotnet/api/system.windows) | Tipos para dar soporte a WPF (Windows Presentation Foundation). |
| [`System.Windows.Annotations`](https://learn.microsoft.com/dotnet/api/system.windows.annotations) | Tipos para hacer anotaciones a documentos mostrados por controles WPF. |
| [`System.Windows.Automation`](https://learn.microsoft.com/dotnet/api/system.windows.automation) | Tipos para dar soporte a la automatización de aplicaciones WPF. |
| [`System.Windows.Controls`](https://learn.microsoft.com/dotnet/api/system.windows.controls) | Tipos para utilizar controles con los que interactuar  en una aplicación WPF. |
| [`System.Windows.Controls.Ribbon`](https://learn.microsoft.com/dotnet/api/system.windows.controls.ribbon) | Tipos para utilizar el control Microsoft Ribbon para WPF. |
| [`System.Windows.Converters`](https://learn.microsoft.com/dotnet/api/system.windows.converters) | Tipos para convertir tipos durante la serialización en WPF. |
| [`System.Windows.Data`](https://learn.microsoft.com/dotnet/api/system.windows.data) | Tipos para enlazar propiedades de una interfaz con fuentes de datos. |
| [`System.Windows.Documents`](https://learn.microsoft.com/dotnet/api/system.windows.documents) | Tipos para dar soporte a diferentes formatos de documentos como XPS. |
| [`System.Windows.Documents.Serialization`](https://learn.microsoft.com/dotnet/api/system.windows.documents.serialization) | Tipos para dar soporte a la serialización de diferentes formatos de documentos. |
| [`System.Windows.Forms`](https://learn.microsoft.com/dotnet/api/system.windows.forms) | Tipos para usar el modelo antiguo de interfaz gráfica de Windows. Es más sencillo de usar que WPF, pero es menos potente y más limitado. |
| [`System.Windows.Forms.Integration`](https://learn.microsoft.com/dotnet/api/system.windows.forms.integration) | Tipos para dar soporte a la comunicación entre controles de Windows Forms y WPF. |
| [`System.Windows.Ink`](https://learn.microsoft.com/dotnet/api/system.windows.ink) | Tipos para dar soporte a dibujar con tinta en WPF. |
| [`System.Windows.Input`](https://learn.microsoft.com/dotnet/api/system.windows.input) | Tipos para dar soporte a la entrada con dispositivos en WPF (ratón, teclado, lápiz digital, etcétera). |
| [`System.Windows.Markup`](https://learn.microsoft.com/dotnet/api/system.windows.markup) | Tipos para dar soporte al formato XAML. |
| [`System.Windows.Media`](https://learn.microsoft.com/dotnet/api/system.windows.media) | Tipos para dar soporte a contenido multimedia con aplicaciones WPF. |
| [`System.Windows.Media.Animation`](https://learn.microsoft.com/dotnet/api/system.windows.media.animation) | Tipos para dar soporte a animaciones. |
| [`System.Windows.Media.Converters`](https://learn.microsoft.com/dotnet/api/system.windows.media.converters) | Tipos para transformar datos al serializar al formato XAML. |
| [`System.Windows.Media.Effects`](https://learn.microsoft.com/dotnet/api/system.windows.media.effects) | Tipos para aplicar efectos visuales a imágenes. |
| [`System.Windows.Media.Imaging`](https://learn.microsoft.com/dotnet/api/system.windows.media.imaging) | Tipos para codificar y decodificar imágenes. |
| [`System.Windows.Media.Media3D`](https://learn.microsoft.com/dotnet/api/system.windows.media.media3d) | Tipos para dar soporte al renderizado 3D en aplicaciones WPF. |
| [`System.Windows.Media.Media3D.converters`](https://learn.microsoft.com/dotnet/api/system.windows.media.media3d.converters) | Tipos para transformar datos al serializar al formato XAML. |
| [`System.Windows.Media.TextFormatting`](https://learn.microsoft.com/dotnet/api/system.windows.media.textformatting) | Tipos para dar formato visual a bajo nivel a texto enriquecido. |
| [`System.Windows.Navigation`](https://learn.microsoft.com/dotnet/api/system.windows.navigation) | Tipos para dar soporte a la navegación entre ventanas. |
| [`System.Windows.Resources`](https://learn.microsoft.com/dotnet/api/system.windows.resources) | Tipos de bajo nivel para dar soporte al uso de recursos en WPF. |
| [`System.Windows.Shapes`](https://learn.microsoft.com/dotnet/api/system.windows.shapes) | Tipos para definir formas que poder usar con el código o con XAML. |
| [`System.Windows.Shell`](https://learn.microsoft.com/dotnet/api/system.windows.shell) | Tipos para poder usar la barra de tareas de Windows. |
| [`System.Windows.Threading`](https://learn.microsoft.com/dotnet/api/system.windows.threading) | Tipos para dar soporte multihilo a WPF. |

