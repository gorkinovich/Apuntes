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

## Nombres

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

$$\texttt{namespace}\ 
\mathit{nombre_1} \textcolor{red}{[} \texttt{.} \textcolor{red}{\dots} \texttt{.} \mathit{nombre_n} \textcolor{red}{]}\ \texttt{\char123}\ \mathit{definiciones}\ \texttt{\char125}$$

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

Se pueden declarar constantes de la siguiente manera:

$$\texttt{const}\ \mathit{tipo}\ \mathit{nombre_1}\ \texttt{=}\ \mathit{literal_1} \textcolor{red}{[} \texttt{,} \textcolor{red}{\dots} \texttt{,}\ \mathit{nombre_n}\ \texttt{=}\ \mathit{literal_n} \textcolor{red}{]} \texttt{;}$$

Su valor no se puede modificar durante la ejecución, de ahí que sean constantes. Los tipos válidos para declarar constantes es reducido, ya que se requiere que se inicialice con una expresión literal. Esta limitación se debe a que la constante se toma, durante la compilación, para sustituir sus apariciones por su valor asignado.

## Variables

La sintaxis estándar para definir variables es la siguiente:

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
using System;

var número = 1.0 / 0.0;                               // Infinito
Console.WriteLine(número == double.PositiveInfinity); // True

número /= double.PositiveInfinity;       // NaN
Console.WriteLine(número == float.NaN);  // False
Console.WriteLine(double.IsNaN(número)); // True
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
using System;

byte a = 128;
int b = a * 2;
Console.WriteLine($"{a}, {b}"); // 128, 256

a = (byte)b;
Console.WriteLine($"{a}, {b}"); // 0, 256
```

## Operadores

..

## Control de la ejecución

..

### Condicionales

..

### Bucles

..

### Excepciones

..

## Tipos de usuario

..

### Clases

..

### Campos

..

### Métodos

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


## LINQ

..

## La biblioteca estándar

..

### E/S por consola

..


