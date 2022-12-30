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

## Arrays

Los arrays es un tipo de dato estructurado que permite declarar N elementos con un orden fijo, que se pueden acceder de forma directa mediante un índice numérico. Su sintaxis es:

$$\mathit{tipo} \texttt{[} \textcolor{red}{[} \texttt{,} \textcolor{red}{\dots} \texttt{,} \textcolor{red}{]} \texttt{]} \textcolor{red}{[} \texttt{[} \textcolor{red}{[} \texttt{,} \textcolor{red}{\dots} \texttt{,} \textcolor{red}{]} \texttt{]} \textcolor{red}{\dots} \texttt{[} \textcolor{red}{[} \texttt{,} \textcolor{red}{\dots} \texttt{,} \textcolor{red}{]} \texttt{]} \textcolor{red}{]}\ \mathit{nombre_1}\ \textcolor{red}{[} \texttt{=}\ \mathit{inicializaci\acute{o}n_1} \textcolor{red}{]}$$

$$\textcolor{red}{[} \texttt{,} \textcolor{red}{\dots} \texttt{,}\ \mathit{nombre_n}\ \textcolor{red}{[} \texttt{=}\ \mathit{inicializaci\acute{o}n_n} \textcolor{red}{]} \textcolor{red}{]} \texttt{;}$$

La *inicialización* es una expresión que devuelve la instancia del array creado, ya sea el resultado de un `new`. En este último caso la sintaxis es:

$$\texttt{new}\ \textcolor{red}{[} \mathit{tipo} \textcolor{red}{]} \texttt{[} \textcolor{red}{[} \mathit{tamaño_1} \textcolor{red}{[} \texttt{,} \textcolor{red}{\dots} \texttt{,}\ \mathit{tamaño_n} \textcolor{red}{]} \textcolor{red}{]} \texttt{]} \textcolor{red}{[} \texttt{[]} \textcolor{red}{\dots} \texttt{[]} \textcolor{red}{]} \textcolor{red}{[} \texttt{\char123}\ \mathit{valores}\ \texttt{\char125} \textcolor{red}{]}$$

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

## Funciones

Una función es un bloque de código con nombre, que podemos parametrizar, para obtener diferentes resultados. Para definir una se utiliza la siguiente sintaxis:

$$\textcolor{red}{\char123} \mathit{tipo} \textcolor{red}{|} \texttt{void} \textcolor{red}{\char125}\ \mathit{nombre} \texttt{(} \textcolor{red}{[} \mathit{par\acute{a}metros} \textcolor{red}{]} \texttt{)}\ \textcolor{red}{\char123} \texttt{\char123}\ \mathit{expresiones}\ \texttt{\char125} \textcolor{red}{|} \texttt{=>}\ \mathit{expresi\acute{o}n} \texttt{;} \textcolor{red}{\char125}$$

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

La sintaxis para definir una clase es la siguiente:

$$\textcolor{red}{[} \mathit{modificadores} \textcolor{red}{]}\ \texttt{class}\ \mathit{nombre}\ \textcolor{red}{[} \texttt{:} \mathit{padre\ e\ interfaces} \textcolor{red}{]}\ \texttt{\char123}\ \mathit{definiciones}\ \texttt{\char125}$$

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

$$\textcolor{red}{[} \mathit{modificadores} \textcolor{red}{]}\ \mathit{tipo}\ \mathit{nombre}\ \textcolor{red}{[} \texttt{=}\ \mathit{expresi\acute{o}n} \textcolor{red}{]} \textcolor{red}{[} \texttt{,} \textcolor{red}{\dots}\ \textcolor{red}{]} \texttt{;}$$

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

$$\textcolor{red}{[} \mathit{modificadores} \textcolor{red}{]}\ \textcolor{red}{\char123} \mathit{tipo} \textcolor{red}{|} \texttt{void} \textcolor{red}{\char125}\ \mathit{nombre} \texttt{(} \textcolor{red}{[} \mathit{par\acute{a}metros} \textcolor{red}{]} \texttt{)}$$

$$\textcolor{red}{\char123} \texttt{\char123}\ \mathit{expresiones}\ \texttt{\char125} \textcolor{red}{|} \texttt{=>}\ \mathit{expresi\acute{o}n} \texttt{;} \textcolor{red}{|} \texttt{;} \textcolor{red}{\char125}$$

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

### Métodos especiales

El primer método especial es el constructor de la clase, que es la función que se invoca cuando usamos el operador `new` crear una nueva instancia de la clase. Su sintaxis es:

$$\textcolor{red}{[} \mathit{modificadores} \textcolor{red}{]}\ \mathit{nombre} \texttt{(} \textcolor{red}{[} \mathit{par\acute{a}metros} \textcolor{red}{]} \texttt{)} \textcolor{red}{[} \texttt{:} \textcolor{red}{\char123} \texttt{base} \textcolor{red}{|} \texttt{this} \textcolor{red}{\char125} \texttt{(} \textcolor{red}{[} \mathit{par\acute{a}metros} \textcolor{red}{]} \texttt{)} \textcolor{red}{]}$$

$$\textcolor{red}{\char123} \texttt{\char123}\ \mathit{expresiones}\ \texttt{\char125} \textcolor{red}{|} \texttt{=>}\ \mathit{expresi\acute{o}n} \texttt{;} \textcolor{red}{\char125}$$

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

El segundo método especial es el destructor de la clase, que es la función que se invoca cuando el objeto va a ser eliminado de la memoria por el recolector de basura. Su sintaxis es:

$$\texttt{\textasciitilde} \mathit{nombre} \texttt{(} \texttt{)} \textcolor{red}{\char123} \texttt{\char123}\ \mathit{expresiones}\ \texttt{\char125} \textcolor{red}{|} \texttt{=>}\ \mathit{expresi\acute{o}n} \texttt{;} \textcolor{red}{\char125}$$

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

$$\texttt{public}\ \texttt{void}\ \texttt{Deconstruct} \texttt{(} \texttt{out}\ \mathit{tipo}\ \mathit{nombre} \texttt{,} \textcolor{red}{\dots} \texttt{)}\ \texttt{\char123}\ \mathit{expresiones}\ \texttt{\char125}$$

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

$$\textcolor{red}{[} \mathit{modificadores} \textcolor{red}{]}\ \mathit{tipo}\ \mathit{nombre}\ \texttt{\char123}\ \mathit{accesores}\ \texttt{\char125}\ \textcolor{red}{[} \texttt{=}\ \mathit{expresi\acute{o}n} \texttt{;} \textcolor{red}{]}$$

La sintaxis de los *accesores* es la siguiente:

$$\textcolor{red}{[} \mathit{visibilidad} \textcolor{red}{]}\ \textcolor{red}{\char123} \texttt{get} \textcolor{red}{|} \texttt{set} \textcolor{red}{|} \texttt{init} \textcolor{red}{\char125}\ \textcolor{red}{\char123} \texttt{\char123}\ \mathit{expresiones}\ \texttt{\char125} \textcolor{red}{|} \texttt{=>}\ \mathit{expresi\acute{o}n} \texttt{;} \textcolor{red}{|} \texttt{;} \textcolor{red}{\char125}$$

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

$$\textcolor{red}{[} \mathit{modificadores} \textcolor{red}{]}\ \mathit{tipo}\ \mathit{nombre} \texttt{[} \mathit{tipo_1}\ \mathit{nombre_1} \texttt{,} \textcolor{red}{\dots} \texttt{]}\ \texttt{\char123}\ \mathit{accesores}\ \texttt{\char125}$$

La sintaxis de los *accesores* es la siguiente:

$$\textcolor{red}{[} \mathit{visibilidad} \textcolor{red}{]}\ \textcolor{red}{\char123} \texttt{get} \textcolor{red}{|} \texttt{set} \textcolor{red}{\char125}\ \textcolor{red}{\char123} \texttt{\char123}\ \mathit{expresiones}\ \texttt{\char125} \textcolor{red}{|} \texttt{=>}\ \mathit{expresi\acute{o}n} \texttt{;} \textcolor{red}{|} \texttt{;} \textcolor{red}{\char125}$$

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
| `+`, `-`, `*`, `/`, `%`, `&`, `|`, `^`, `<<`, `>>` | Binaria |  |
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

..TODO..

### Estructuras

..TODO..

### Registros

..TODO..

### Enumeraciones

..TODO..

## Control de la ejecución

..TODO..

### Condicionales

..TODO..

### Bucles

..TODO..

### Excepciones

..TODO..

## Genéricos

..TODO..

## Funciones anónimas

..TODO..

## E/S por consola

..TODO..

## Formato de cadenas

El formato de cadenas, realizado por funciones como [`String.Format`](https://learn.microsoft.com/dotnet/api/system.string.format) o [`Console.WriteLine`](https://learn.microsoft.com/dotnet/api/system.console.writeline), consiste en cadenas de texto que tienen una serie de códigos especiales, delimitados entre llaves, que siguen la siguiente sintaxis:

$$\texttt{\char123} \mathit{\acute{\imath}ndice} \textcolor{red}{[} \texttt{,} \mathit{alineamiento} \textcolor{red}{]} \textcolor{red}{[} \texttt{:} \mathit{formato} \textcolor{red}{]} \texttt{\char125}$$

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
| `F`, `%F` | Décimas de segundo o nada si es cero | `FF`-`FFFFFFF` | De 10^-2^ a 10^-7^ de segundo  o nada si es cero |
| `'...'` | Texto literal | `\` | Carácter de escape |
| Otros | Texto literal |

Por último, para la función [`Enum.ToString`](https://learn.microsoft.com/dotnet/api/system.enum.tostring) tenemos estos códigos, para dar formato a valores enumerados:

| Código | Descripción |
|:------:|:-----------:|
| `g`, `G` | Representación como texto. |
| `f`, `F` | Representación de *flags* como texto. |
| `d`, `D` | Representación como número decimal. |
| `x`, `X` | Representación como número hexadecimal. |

## LINQ

..TODO..

## Concurrencia y paralelismo

..TODO..

