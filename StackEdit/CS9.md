# C# 9.0

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

Este tipo de comentario termina  con el salto de línea, por lo que todo el texto que venga detrás de `//` será ignorado por el compilador. Si necesitáramos que el comentario ocupe varias líneas, tenemos la siguiente manera:

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

$$\texttt{namespace}\ \mathit{nombre_1} \textcolor{red}{[} \texttt{.} \textcolor{red}{\dots} \texttt{.} \mathit{nombre_n} \textcolor{red}{]}\ \texttt{\char123}\ \mathit{definiciones}\ \texttt{\char125}$$

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

$$\textcolor{red}{\char123} \texttt{true} \textcolor{red}{|} \texttt{false} \textcolor{red}{\char125}$$

El siguiente grupo son los números enteros, cuya sintaxis es:

$$\textcolor{red}{[} \mathit{prefijo} \textcolor{red}{]}  \mathit{d\acute{\imath}gitos} \textcolor{red}{[} \mathit{sufijo} \textcolor{red}{]}$$

Los prefijos validos son:

| Prefijos | Tipo | Dígitos |
|:--------:|:----:|:-------:|
| - | Decimal | `0`-`9` |
| `0b`, `OB` | Binario | `0`-`1` |
| `0x`, `OX` | Hexadecimal | `0`-`9`, `A`-`F`, `a`-`f` |

Los sufijos validos son:

| Prefijos | Tipo | Descripción |
|:--------:|:----:|:------------|
| - | `int` | Entero con signo (32 bits). |
| `u`, `U` | `uint` | Entero sin signo (32 bits). |
| `l`, `L` | `long` | Entero largo con signo (64 bits). |
| `ul`, `lu`, `uL`, `lU`,<br/>`Ul`, `Lu`, `UL`, `LU` | `ulong` | Entero largo sin signo (64 bits). |

Además, se puede usar `_` como separador entre dígitos, para agrupar los números de la forma que necesitemos. Por ejemplo, `1_234` o `0x1234_5678`.

El siguiente grupo son los números reales, cuya sintaxis es:

$$\mathit{d\acute{\imath}gitos} \textcolor{red}{[} \texttt{.} \mathit{d\acute{\imath}gitos} \textcolor{red}{]} \textcolor{red}{[} \textcolor{red}{\char123} \texttt{e} \textcolor{red}{|} \texttt{E} \textcolor{red}{\char125} \textcolor{red}{[} \texttt{+} \textcolor{red}{|} \texttt{-} \textcolor{red}{]} \mathit{d\acute{\imath}gitos} \textcolor{red}{]} \textcolor{red}{[} \mathit{sufijo} \textcolor{red}{]}$$

Los sufijos validos son:

| Prefijos | Tipo | Descripción |
|:--------:|:----:|:------------|
| - | `double` | Precisión doble (64 bits). |
| `f`, `F` | `float` | Precisión simple (32 bits). |
| `d`, `D` | `double` | Precisión doble (64 bits). |
| `m`, `M` | `decimal` | Precisión extra larga (128 bits). |

El siguiente grupo es para representar texto, ya sean caracteres sueltos o cadenas de ellos. Para representar un carácter suelto se utiliza:

$$\texttt{'} \textcolor{red}{\char123} \mathit{letra} \textcolor{red}{|} \mathit{secuencia\ de\ escape} \textcolor{red}{\char125} \texttt{'}$$

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

Con el prefijo `@` la cadena será "cruda" y no tendrá en cuenta ninguna secuencia de escape. Se utilizan para poder poner rutas de Windows sin tener que usar `\\` continuamente. La única salvedad con este tipo de cadenas es que con `""` se puede representar las comillas dobles.

## Constantes

Una constante es un valor fijo con nombre. Se pueden declarar de la siguiente manera:

$$\texttt{const}\ \mathit{tipo}\ \mathit{nombre_1}\ \texttt{=}\ \mathit{literal_1} \textcolor{red}{[} \texttt{,} \textcolor{red}{\dots} \texttt{,}\ \mathit{nombre_n}\ \texttt{=}\ \mathit{literal_n} \textcolor{red}{]} \texttt{;}$$

Su valor no se puede modificar durante la ejecución, de ahí que sean constantes. Los tipos válidos para declarar constantes es reducido, ya que se requiere que se inicialice con una expresión literal. Esta limitación se debe a que la constante se toma, durante la compilación, para sustituir sus apariciones por su valor asignado.

## Variables

Una variable es un valor con nombre que puede variar durante la ejecución del programa. La sintaxis estándar para definir variables es la siguiente:

$$\mathit{tipo}\ \mathit{nombre_1}\ \textcolor{red}{[} \texttt{=}\ \mathit{expresi\acute{o}n_1} \textcolor{red}{]} \textcolor{red}{[} \texttt{,} \textcolor{red}{\dots} \texttt{,}\ \mathit{nombre_n}\ \textcolor{red}{[} \texttt{=}\ \mathit{expresi\acute{o}n_n} \textcolor{red}{]} \textcolor{red}{]} \texttt{;}$$

Con la palabra clave `var` se indica al compilador que infiera el tipo para la variable en base a la expresión que inicializa su valor:

$$\texttt{var}\ \mathit{nombre_1}\ \texttt{=}\ \mathit{expresi\acute{o}n_1} \textcolor{red}{[} \texttt{,} \textcolor{red}{\dots} \texttt{,}\ \mathit{nombre_n}\ \texttt{=}\ \mathit{expresi\acute{o}n_n} \textcolor{red}{]} \texttt{;}$$

Con la palabra clave `dynamic` se marca el tipo de la variable como dinámico y las comprobaciones de tipo se resuelven en tiempo de ejecución, en lugar de hacerlo durante la compilación. Esto hace que sea más flexible, pero también puede provocar más errores durante la ejecución. Su sintaxis es:

$$\texttt{dynamic}\ \mathit{nombre_1}\ \textcolor{red}{[} \texttt{=}\ \mathit{expresi\acute{o}n_1} \textcolor{red}{]} \textcolor{red}{[} \texttt{,} \textcolor{red}{\dots} \texttt{,}\ \mathit{nombre_n}\ \textcolor{red}{[} \texttt{=}\ \mathit{expresi\acute{o}n_n} \textcolor{red}{]} \textcolor{red}{]} \texttt{;}$$

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
|  `MinusOne` | Representación del valor `-1`. |
|  `One` | Representación del valor `1`. |
|  `Zero` | Representación del valor `0`. |

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

En esta sección veremos por encima los operadores disponibles en el lenguaje. En algunos casos particulares se verán con más detalles en secciones posteriores.

### Booleanos

El primer bloque de operadores booleanos son los de comparación:

| Operación | Descripción |
|:---------:|:-----------:|
| `X == Y`  | `X` es igual a `Y`. |
| `X != Y`  | `X` no es igual a `Y`. |
| `X <= Y`  | `X` es menor o igual que `Y`. |
| `X < Y`   | `X` es menor que `Y`. |
| `X >= Y`  | `X` es mayor o igual que `Y`. |
| `X > Y`   | `X` es mayor que `Y`. |
| `X is T`   | `X` es de tipo `T`. |

El primer bloque de operadores booleanos son los lógicos:

| Operación | Descripción |
|:---------:|:-----------:|
| `!X` | [Negación](https://es.wikipedia.org/wiki/Negaci%C3%B3n_l%C3%B3gica) de `X`. |
| `X && Y` | [Conjunción](https://es.wikipedia.org/wiki/Conjunci%C3%B3n_l%C3%B3gica) de `X` con `Y`. |
| `X || Y`  | [Disyunción](https://es.wikipedia.org/wiki/Disyunci%C3%B3n_l%C3%B3gica) de `X` con `Y`. |

Estos operadores nos permiten componer condiciones más complejas. Para entenderlos mejor aquí tenemos sus [tablas de la verdad](https://es.wikipedia.org/wiki/Tabla_de_verdad):

|   `X`   |   `Y`   |  `!X`   |  `!Y`   | `X && Y`  | `X || Y` |
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
} catch (OverflowException e) {
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
| `default` | Devuelve el valor por defecto para un tipo. |
| `delegate` | Permite definir funciones anónimas. |
| `nameof` | Devuelve como una cadena de texto el nombre de un elemento (variable, tipo o miembro). Se resuelve en tiempo de compilación. |
| `new` | Reserva espacio en la memoria para un objeto, ya sea un tipo por valor (en la pila) o un tipo por referencia (en el montículo). |
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
| `X |= Y` | Equivale a `X = X | Y`. |
| `X ^= Y` | Equivale a `X = X ^ Y`. |
| `X <<= Y` | Equivale a `X = X << Y`. |
| `X >>= Y` | Equivale a `X = X >> Y`. |
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
| Disyunción | `x | y` | Izquierda |
| Conjunción condicional | `x && y` | Izquierda |
| Disyunción condicional | `x || y` | Izquierda |
| Nulidad | `x ?? y` | Derecha |
| Condicional | `c ? t : f` | Derecha |
| Asignación y lambas | `x = y`, `x += y`, `x -= y`, `x *= y`, `x /= y`, `x %= y`, `x &= y`, `x |= y`, `x ^= y`, `x <<= y`, `x >>= y`, `x ??= y`, `=>` | Derecha |

## Funciones

Una función es un bloque de código con nombre, que podemos parametrizar, para obtener diferentes resultados. Para definir una se utiliza la siguiente sintaxis:

$$\textcolor{red}{\char123} \mathit{tipo} \textcolor{red}{|} \texttt{dynamic} \textcolor{red}{|} \texttt{void} \textcolor{red}{\char125}\ \mathit{nombre} \texttt{(} \textcolor{red}{[} \mathit{par\acute{a}metros} \textcolor{red}{]} \texttt{)}\ \texttt{\char123}\ \mathit{expresiones}\ \texttt{\char125}$$

$$\textcolor{red}{\char123} \mathit{tipo} \textcolor{red}{|} \texttt{dynamic} \textcolor{red}{|} \texttt{void} \textcolor{red}{\char125}\ \mathit{nombre} \texttt{(} \textcolor{red}{[} \mathit{par\acute{a}metros} \textcolor{red}{]} \texttt{)}\ \texttt{=>}\ \mathit{expresi\acute{o}n} \texttt{;}$$

Una función tiene un tipo de retorno, pero si no devuelve nada usará `void` como tipo del resultado. También se permite usar `dynamic` como tipo de retorno, con las implicaciones que ello tiene para la ejecución. Luego se puede tener entre cero y N parámetros, cuya sintaxis es:

$$\textcolor{red}{[} \texttt{ref} \textcolor{red}{|} \texttt{out} \textcolor{red}{|} \texttt{in} \textcolor{red}{]}\ \textcolor{red}{\char123} \mathit{tipo} \textcolor{red}{|} \texttt{dynamic} \textcolor{red}{\char125}\ \mathit{nombre_1}\ \textcolor{red}{[} \texttt{=}\ \mathit{expresi\acute{o}n_1} \textcolor{red}{]} \texttt{,}$$

$$\textcolor{red}{\dots} \texttt{,}\ \texttt{params}\ \mathit{tipo}\texttt{[]}\ \mathit{nombre_n}$$

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

### Clases

La sintaxis para definir una clase es la siguiente:

$$\textcolor{red}{[} \mathit{modificadores} \textcolor{red}{]}\ \texttt{class}\ \mathit{nombre}\ \textcolor{red}{[} \texttt{:} \mathit{padre\ e\ interfaces} \textcolor{red}{]}\ \texttt{\char123}\ \mathit{definiciones}\ \texttt{\char125}$$

Los modificadores de visibilidad disponibles para las clases son `public` e `internal`. También tenemos como modificadores de comportamiento los siguientes:

| Modificador | Descripción |
|:-----------:|:------------|
| `static` | Clase estática, todos sus miembros serán estáticos. |
| `abstract` | Clase abstracta, alguno de sus métodos es abstracto, es decir, no está definido y lo tendrán que definir sus clases hijas. |
| `sealed` | Clase sellada, ninguna otra clase podrá heredar de ella. |
| `unsafe` | Clase con código inseguro, para poder usar punteros. |
| `partial` | Clase parcial, que sus elementos están definidos en uno o varios ficheros de código fuente. Este modificador se suele utilizar para herramientas que generan código automático. |

Algunos modificadores no se pueden combinar entre sí, ya que provocaría una situación contradictoria. Por ejemplo, no una clase no puede ser estática y abstracta a la vez.

La [herencia](https://es.wikipedia.org/wiki/Herencia_%28inform%C3%A1tica%29) en C# sólo nos permite heredar de un único padre, que por defecto será `object`. Lo que sí podemos es heredar de múltiples interfaces, que veremos más adelante.

### Campos

Los campos son variables que pertenecen a una clase. Para definir un campo se utiliza la siguiente sintaxis:

$$\textcolor{red}{[} \mathit{modificadores} \textcolor{red}{]}\ \textcolor{red}{\char123} \mathit{tipo} \textcolor{red}{|} \texttt{dynamic} \textcolor{red}{\char125}\ \mathit{nombre}\ \textcolor{red}{[} \texttt{=}\ \mathit{expresi\acute{o}n} \textcolor{red}{]} \textcolor{red}{[} \texttt{,} \textcolor{red}{\dots}\ \textcolor{red}{]} \texttt{;}$$

Además de los modificadores de visibilidad, los de comportamiento disponibles son los siguientes:

| Modificador | Descripción |
|:-----------:|:------------|
| `static` | La variable será un campo estático. |
| `readonly` | La variable es sólo de lectura una vez es inicializada, ya sea en su definición o en el constructor. |

También se puede declarar constantes como campos con `const`, en cuyo caso es obligatorio inicializar su valor, y los únicos modificadores disponibles son los de visibilidad.

### Métodos

Los métodos son funciones que pertenecen a una clase. Para definir un método se utiliza la siguiente sintaxis:

$$\textcolor{red}{[} \mathit{modificadores} \textcolor{red}{]}\ \textcolor{red}{\char123} \mathit{tipo} \textcolor{red}{|} \texttt{dynamic} \textcolor{red}{|} \texttt{void} \textcolor{red}{\char125}\ \mathit{nombre} \texttt{(} \textcolor{red}{[} \mathit{par\acute{a}metros} \textcolor{red}{]} \texttt{)}$$

$$\textcolor{red}{\char123} \texttt{\char123}\ \mathit{expresiones}\ \texttt{\char125} \textcolor{red}{|} \texttt{=>}\ \mathit{expresi\acute{o}n} \texttt{;} \textcolor{red}{|} \texttt{;} \textcolor{red}{\char125}$$

..

### Propiedades

..

### Interfaces

..

### Estructuras

..

### Registros

..

### Enumeraciones

..

## Control de la ejecución

..

### Condicionales

..

### Bucles

..

### Excepciones

..

## Funciones anónimas

..

## LINQ

..

## E/S por consola

..

## Formato de cadenas

.. `String.Format` `{index[,alineamiento][:formato]}` `{{` `}}` ..

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

..

```csharp
using static System.Console;

void foo (string format, object value) {
    try {
        WriteLine(format, value);
    } catch (Exception) {
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

..

| Código | Descripción | Ejemplo | Valor | Resultado |
|:------:|:-----------:|:-------:|:-----:|:---------:|
| `0` | Ceros | `{0:0.000}`<br/>`{0:000.0}` | `23.45` | `23,450`<br/>`023,5` |
| `#` | Dígitos | `{0:#.###}`<br/>`{0:###.#}` | `23.45` | `23,45`<br/>`23,5` |
| `.` | Decimales | `{0:#.00}` | `42` | `42,00` |
| `,` | Millares | `{0:#.###}` | `1234` | `1.234` |
| `%` | Porcentaje | `{0:0.##%}`<br/>`{0:0.## %}` | `0.12345` | `12,35%`<br/>`12,35 %` |

.. `DateTime` `DateTimeOffset` ..

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

..

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

.. `TimeSpan` ..

| Código | Descripción | Ejemplo |
|:------:|:-----------:|:-------:|
| `c` | Formato constante. | `1.02:03:04` |
| `g` | Formato general corto. | `1:2:03:04` |
| `G` | Formato general largo. | `1:02:03:04,0000000` |

..

| Código | Descripción | Código | Descripción |
|:------:|:-----------:|:------:|:-----------:|
| `d`, `%d` | Días | `dd`-`dddddddddd` | Días con ceros a la izquierda |
| `h`, `%h` | Horas | `hh` | Horas con ceros a la izquierda |
| `s`, `%s` | Segundos | `ss` | Segundos con ceros a la izquierda |
| `f`, `%f` | Décimas de segundo | `ff`-`fffffff` | De 10^-2^ a 10^-7^ de segundo |
| `F`, `%F` | Décimas de segundo o nada si es cero | `FF`-`FFFFFFF` | De 10^-2^ a 10^-7^ de segundo  o nada si es cero |
| `'...'` | Texto literal | `\` | Carácter de escape |
| Otros | Texto literal |

.. `Enum.ToString` ..

| Código | Descripción |
|:------:|:-----------:|
| `g`, `G` | Representación como texto. |
| `f`, `F` | Representación de *flags* como texto. |
| `d`, `D` | Representación como número decimal. |
| `x`, `X` | Representación como número hexadecimal. |

..

## La biblioteca estándar

..


