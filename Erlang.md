
# Erlang

[Erlang](https://www.erlang.org/) es un lenguaje de programación diseñado para desarrollar sistemas de comunicación grandes en tiempo real con alta disponibilidad, que sean escalables y tolerantes a fallos. Es un lenguaje de [programación funcional](https://es.wikipedia.org/wiki/Programaci%C3%B3n_funcional), cuya característica principal es disponer de [concurrencia](https://es.wikipedia.org/wiki/Concurrencia_%28inform%C3%A1tica%29). Otras propiedades del lenguaje son la [inmutabilidad](https://es.wikipedia.org/wiki/Objeto_inmutable) de los datos, el [encaje de patrones](https://es.wikipedia.org/wiki/B%C3%BAsqueda_de_patrones), la evaluación impaciente, el [tipado dinámico](https://es.wikipedia.org/wiki/Sistema_de_tipos), la [computación distribuida](https://es.wikipedia.org/wiki/Computaci%C3%B3n_distribuida) o el [cambio en caliente](https://es.wikipedia.org/wiki/Cambio_en_caliente), entre muchas otras.

Recomiendo leer el libro [Learn You Some Erlang](https://learnyousomeerlang.com/), que recoge con bastante acierto las principales herramientas de las que dispone el lenguaje. El IDE que recomiendo es el [IntelliJ IDEA](https://www.jetbrains.com/es-es/idea/), que tiene la versión *Community* que es gratuita y permite instalar un plugin para trabajar con Erlang. Por último, estos apuntes han sido probados en la versión 23 de Erlang/OTP, aunque deberían funcionar la mayoría de los ejemplos con las versiones posteriores.

## Primeros pasos

Los programas en Erlang se dividen en **módulos**, ficheros con la extensión `.erl`, que contienen conjuntos de **funciones**. También existen ficheros de **cabecera**, con la extensión `.hrl`, para incluir **macros** en diferentes módulos.

Una vez codificados los **módulos** del programa, estos son **compilados** a ficheros `.beam` para convertir el código fuente del programa al **byte code** que será **ejecutado** por la **máquina virtual** de Erlang.

Para compilar y ejecutar programas necesitamos entrar en la **terminal** de Erlang, con los comandos [`erl`](https://www.erlang.org/doc/man/erl.html) y [`werl`](https://www.erlang.org/doc/man/werl.html). El primero ejecuta Erlang desde la consola del sistema y el segundo lo hace desde una ventana de la interfaz gráfica del sistema operativo.

Dentro de la terminal existe una lista de comandos del [sistema](https://www.erlang.org/doc/man/c.html) y de la [terminal](https://www.erlang.org/doc/man/shell.html) para poder trabajar. Aquí destacamos una lista de los más fundamentales para el día a día:

| Comando | Descripción | Parámetros |
|:-------:|-------------|:----------:|
| `c(M)` | Compilar un módulo | `M`: Nombre del módulo |
| `l(M)` | Cargar un módulo | `M`: Nombre del módulo |
| `cd(D)` | Cambia de directorio | `D`: Ruta del directorio |
| `pwd()` | Muestra el directorio actual |  |
| `f()` | Libera las variables asignadas |  |
| `q()` | Cierra la terminal |  |
| `help()` | Muestra la ayuda de la terminal |  |

Podemos también **compilar** un módulo con el comando [`erlc`](https://www.erlang.org/doc/man/erlc.html), de cara a automatizar la compilación de un proyecto mediante scripts.

Como ejemplo inicial vamos a realizar el clásico hola mundo:

```Erlang
% hello.erl
-module(hello).
-export([world/0]).
world() -> io:format("Hello, world!~n").
```

Los **comentarios** en Erlang se escriben usando `%`, como muestra la primera línea del ejemplo. Un **módulo** está compuesto por una serie de **definiciones** que terminan con un **punto**. Las definiciones pueden ser **atributos** o **funciones**. Los atributos describen propiedades del módulo, que pueden ser consultadas por la máquina virtual. En el ejemplo tenemos dos: el nombre del módulo con `-module` y las funciones públicas del mismo con `-export`. Estos dos atributos son los mínimos que necesitamos para construir un módulo y hay que tener en cuenta que el nombre del módulo y del fichero tienen que ser el mismo. Después de los atributos viene la función `world` que no tiene parámetros e invoca la función `format` del módulo `io`, que muestra una cadena de texto en la consola del sistema.

Con esto tenemos entonces nuestro fichero `hello.erl`, que contiene el módulo `hello`. Para compilarlo podemos utilizar `erlc` de la siguiente manera:

```
erlc hello.erl
```

Esto compila el módulo `hello` y genera un fichero `hello.beam` dentro del mismo directorio que contiene a `hello.erl`. Si queremos compilar el módulo desde la terminal de Erlang, tenemos que ejecutar el comando `erl` y dentro de la terminal usar los comandos:

```Erlang
c(hello).
l(hello).
```

El primero compila el módulo `hello` y el segundo carga el módulo en la máquina virtual, siempre y cuando se haya generado el fichero `.beam` correspondiente. Si estamos muy seguros, de que se va a compilar sin problemas, podemos también usar:

```Erlang
c(hello), l(hello).
```

Una vez está cargado el módulo en la máquina virtual, ejecutamos el programa con:

```Erlang
hello:world().
```

Para ejecutarlo desde la consola del sistema directamente, como si fuera un programa normal, usaríamos `erl` de la siguiente manera:

```
erl -eval hello:world(). -s init stop -noshell
```

Esto arranca la máquina virtual sin usar la terminal, para evaluar la expresión `hello:world().` mediante la opción `-eval` y después ejecuta la función `init:stop()`, que finaliza la ejecución del entorno de ejecución.

Esta forma de trabajar hace que los ficheros `.beam` terminen en el mismo directorio que nuestro código, por lo que sería buena idea tener un directorio de salida para la compilación. Para ello tenemos que utilizar la opción `-o` con `erlc` y `-pa` con `erl`:

```
erlc -o Release Source/hello.erl
erl.exe -pa Release -eval hello:world(). -s init stop -noshell
```

Este escenario presupone que tenemos un directorio `Release` para el resultado de la compilación y `Source` para el código fuente del programa. Entonces, tras compilar `hello.erl`, se genera `hello.beam` en el directorio `Release` y es ejecutado con gracias a que hemos indicado a la máquina virtual un directorio adicional en el que buscar ficheros `.beam`.

En Erlang podemos tener secuencias de expresiones separadas por **comas**, que terminarán en un **punto** para cerrar la definición dentro del módulo. Por ejemplo, la siguiente función:

```Erlang
hi_bye() ->
   io:format("Hello~n"),
   io:format("Goodbye~n").
```

También dentro de la terminal se puede introducir una secuencia de expresiones, como hemos visto antes para compilar y cargar un módulo. Tomando el último ejemplo:

```
1> io:format("Hello~n"), io:format("Goodbye~n").
Hello
Goodbye
ok
```

Para este ejemplo mostramos la salida por pantalla de la terminal, viendo que nos muestra el texto que queremos enviar a la salida de la consola, y podemos observar que termina con un `ok`, que es el valor que devuelve la función `io:format` al terminar.

> La notación que utiliza la biblioteca estándar de Erlang/OTP para los nombres de módulos y funciones es de tipo [snake case](https://en.wikipedia.org/wiki/Snake_case), es decir, que las palabras se separan con un guion bajo para que sea el nombre más legible.

## Constantes

### Números

La sintaxis para definir **números enteros** es la siguiente:

$$\textcolor{red}{[}\texttt{+}\textcolor{red}{|}\texttt{-}\textcolor{red}{]} \textcolor{red}{[}\mathit{base}\texttt{\char35}\textcolor{red}{]} \mathit{d\acute{\imath}gitos}$$

La base puede ser un valor dentro del intervalo $[2,36]$ y por defecto es `10`. Por ejemplo: `4`, `8`, `15`, `2#10000`, `8#27`, `16#2A`.

También podemos definir **números reales** o de **coma flotante**:

$$\textcolor{red}{[}\texttt{+}\textcolor{red}{|}\texttt{-}\textcolor{red}{]} \mathit{d\acute{\imath}gitos}\textcolor{red}{[}\texttt{.}\mathit{d\acute{\imath}gitos}\textcolor{red}{]} \textcolor{red}{[}\texttt{E}\textcolor{red}{[}\texttt{+}\textcolor{red}{|}\texttt{-}\textcolor{red}{]} \mathit{d\acute{\imath}gitos}\textcolor{red}{]}$$

Por ejemplo: `0.64341054629`, `2.718281828459045`, `3.141592653589793`.

Enteros y reales tienen una representación interna en Erlang distinta, por ello a la hora de realizar una operación matemática, si fuera necesario, la máquina virtual transforma un valor entero en uno real automáticamente.

> La sintaxis de Erlang permite usar el símbolo `_` como separador visual entre los dígitos de un número, de modo que se puede usar como separador de millares. Por ejemplo: `1_234` o `1_2_3`. Al ser un elemento meramente estético, son eliminados a la hora de evaluar la expresión numérica.

### Átomos

Los átomos son **valores** literales representados por un **nombre**. Para definirlos hay dos maneras. La primera es aquellas cadenas compuestas por letras, números, el guion bajo (`_`) y la arroba (`@`), que empiezan por una letra minúscula. La segunda es aquellas cadenas delimitadas por comillas simples (`'`), que contienen cualquier cadena de texto. Por motivos obvios, la segunda forma no puede contener una comilla simple, salvo que vaya precedida que la barra invertida, es decir: `\'`. Por ejemplo: `plastic_love`, `'Mariya Takeuchi'`.

Como curiosidad, para representar valores **booleanos** se utilizan los átomos `true` y `false`.

> Existen algunas palabras claves reservadas del lenguaje que no pueden ser utilizadas como átomos: `after`, `and`, `andalso`, `band`, `begin`, `bnot`, `bor`, `bsl`, `bsr`, `bxor`, `case`, `catch`, `cond`, `div`, `end`, `fun`, `if`, `let`, `not`, `of`, `or`, `orelse`, `query`, `receive`, `rem`, `try`, `when`, `xor`.

### Texto

Se puede utilizar caracteres y cadenas de texto en Erlang como valores literales. Para los **caracteres** hay que utilizar el símbolo `$` seguido de la letra en cuestión. Para las **cadenas** hay que delimitarlas con las comillas dobles (`"`). Por ejemplo: `$ñ`, `"La letra eñe."`.

Realmente, como pasa en tantos otros lenguajes, la representación de cada letra es un valor numérico y por extensión el de una cadena es una lista de números. Es decir, que esta sintaxis es azúcar sintáctico, pero no por ello deja de ser útil su uso.

> Se puede dividir la definición de una cadena en varios segmentos si es necesario, sin que ello altere el resultado final. Por lo tanto, es lo mismo la cadena `"abcdefgh"` que la cadena `"abcd" "efgh"`.

## Variables inmutables

Las variables son **valores asociados** a un **nombre identificador**. Para definir un nombre de variable, se necesita una cadena compuesta por una serie de letras, números, guiones bajos (`_`) y/o arrobas (`@`), que empieza por una letra mayúscula o un guion bajo. A diferencia de los átomos, que son valores por sí mismos, las variables necesitan ser inicializadas. Una de las formas posibles es utilizar el operador igual (`=`) de la siguiente manera:

```Erlang
Year = 1984,
Name = george_orwell.
```

Otra de las formas, para asignar valores a una variable, es invocar una función con una serie de valores utilizados como argumentos de la aplicación de dicha función. Al invocarla, los valores de los argumentos son asignados a las variables que conforman los parámetros de la función.

Hay que tener en cuenta, que una vez que se asigna un valor a cualquier variable, no se puede volver a asignar otro valor nuevo a la misma, ya que estas son **inmutables**. De modo que lo siguiente daría un fallo en ejecución:

```Erlang
N = 1,
N = 2.
```

Es común en lenguajes funcionales que el operador igual no es un operador de asignación, sino de igualdad matemática. Al evaluar el primer uso, `N = 1`, al no estar inicializada la variable `N` se asume que su valor ha de ser `1`. Pero al evaluar el segundo uso, `N = 2`, la variable ya está inicializada y es falsa la igualdad, por lo tanto nuestro programa fallará.

Manejar variables inmutables puede parecer al principio un escollo insalvable, pero ya iremos viendo cómo superar esta aparente dificultad, con el uso de funciones recursivas.

> El guion bajo a solas (`_`) es una variable especial que se utiliza en el lenguaje para cuando no nos interesa el valor que tiene asignado. Internamente, al compilarlo, genera una variable fresca para evitar la colisión de nombres entre las diferentes apariciones de esta variable comodín.

## Estructuras de datos

### Tuplas

Las tuplas son estructuras de datos que agrupan información de forma ordenada con un tamaño fijo. Siguen la siguiente sintaxis:

$$\texttt{\char123} \textcolor{red}{[} \mathit{expresi\acute{o}n_1} \textcolor{red}{[} \texttt{,} \dots \textcolor{red}{[} \texttt{,} \mathit{expresi\acute{o}n_n} \textcolor{red}{]} \textcolor{red}{]} \textcolor{red}{]} \texttt{\char125}$$

Por ejemplo: `{}`, `{0, a}`, `{{data, 3.14}, Foo, {}, 8}`.

### Listas

Las listas son estructuras de datos que agrupan información de forma ordenada con un tamaño variable. Su sintaxis es la siguiente:

$$\texttt{[} \textcolor{red}{[} \mathit{expresi\acute{o}n_1}  \texttt{|} \mathit{expresi\acute{o}n_2} \textcolor{red}{]} \texttt{]}$$

Este es el constructor de listas, que podemos hacer una lista vacía con `[]`, o podemos hacer una lista no vacía donde la primera expresión es el valor en la **cabecera** de dicha lista y la segunda la **continuación**. Por ejemplo: `[1, [2 | []]]`, que es la lista con los valores `1` y `2` en orden. La continuación, también denominada **cola** de la lista, puede ser cualquier valor posible, por lo que podemos tener una lista tal que: `[z | 80]`.

> Que la cola pueda ser cualquier valor puede provocar que la terminación de la lista no sea una lista vacía, en cuyo caso se le denomina como **lista impropia**, frente a las **listas propias**. Esta distinción es importante a la hora de analizar el tipo de una expresión, pues hay funciones que sólo funcionan con listas propias, por lo que fallarían al recibir una impropia ya que nunca llegarían a la condición final de parar con la lista vacía.

A diferencia de los lenguajes fuertemente tipados, como es el caso de [Haskell](https://www.haskell.org/), las listas en Erlang pueden ser heterogéneas en relación a los tipos de los valores que contiene, gracias a su naturaleza de lenguaje con tipado dinámico.

Como definir listas más complejas, con el constructor de listas, puede llegar a ser costoso y confuso, existe una sintaxis alternativa para definir listas:

$$\texttt{[} \textcolor{red}{[} \mathit{expresi\acute{o}n_1} \textcolor{red}{[} \texttt{,} \dots \textcolor{red}{[} \texttt{,} \mathit{expresi\acute{o}n_n} \textcolor{red}{]} \textcolor{red}{]} \textcolor{red}{]} \texttt{]}$$

De este modo, la lista `[1, [2 | []]]` se puede definir como `[1, 2]`, siendo más legible para el programador. Internamente, para la máquina virtual, son la misma cosa porque esta forma de sintaxis es azúcar sintáctico.

Dentro de la biblioteca estándar existe el módulo [`lists`](https://www.erlang.org/doc/man/lists.html), con una buena colección de funciones que permiten consultar y transformar listas, algunas de ellas bastante avanzadas.


### Mapas

Los mapas son estructuras de datos que relacionan una clave con un valor. Aunque también se le conoce como diccionarios en otros lenguajes, la [biblioteca estándar](https://www.erlang.org/doc/man/stdlib_app) de Erlang tiene otro tipo de estructura nativa que se llama diccionario (módulo `dict`), por lo que usaremos el término mapa para evitar confusiones innecesarias. Los mapas se añadieron como sustitución de los diccionarios implementados, para corregir algunas carencias que tenía el lenguaje.

La sintaxis para crear un mapa es la siguiente:

$$\texttt{\char35\char123} \textcolor{red}{[} \mathit{clave_1}\ \texttt{=>}\ \mathit{valor_1} \textcolor{red}{[} \texttt{,} \dots \textcolor{red}{[} \texttt{,} \mathit{clave_n}\ \texttt{=>}\ \mathit{valor_n} \textcolor{red}{]} \textcolor{red}{]} \textcolor{red}{]} \texttt{\char125}$$

Tanto las claves, como los valores, pueden ser de cualquier tipo. Para actualizar un mapa previo, usaremos esta sintaxis:

$$\mathit{mapa}\texttt{\char35\char123} \mathit{clave}\ \texttt{=>}\ \mathit{valor} \texttt{\char125}$$

De este modo se devuelve un nuevo mapa, donde se asigna un valor a la clave indicada, existiera esta previamente o no. Existe otra variante para actualizar un mapa previo con:

$$\mathit{mapa}\texttt{\char35\char123} \mathit{clave}\ \texttt{:=}\ \mathit{valor} \texttt{\char125}$$

Con esta versión, si la clave no existe previamente, no se actualizará el contenido del nuevo mapa creado y será simplemente una copia idéntica del mapa que hemos intentado modificar.

El módulo [`maps`](https://www.erlang.org/doc/man/maps.html) contiene una serie de funciones que permite trabajar con mapas, para poder consultar su contenido o realizar transformaciones avanzadas.

### Bloques binarios

Debido a que Erlang fue diseñado para construir sistemas de telecomunicaciones, existía la necesidad de tener las herramientas para poder procesar protocolos e información a nivel de bytes e incluso de bits. Para ello se tiene en Erlang la siguiente sintaxis:

$$\texttt{<<} \textcolor{red}{[} \mathit{segmento_1} \textcolor{red}{[} \texttt{,} \dots \textcolor{red}{[} \texttt{,} \mathit{segmento_n} \textcolor{red}{]} \textcolor{red}{]} \textcolor{red}{]} \texttt{>>}$$

Los *segmentos* tienen la siguiente sintaxis:

$$\mathit{dato} \textcolor{red}{[} \texttt{:} \mathit{tamaño} \textcolor{red}{]} \textcolor{red}{[} \texttt{/} \mathit{descriptores} \textcolor{red}{]}$$

Los *descriptores* es una lista de propiedades que definen al *dato* y que se separan con guiones (`-`). Los *descriptores* disponibles son:

| Categoría | Valores | Defecto | Descripción |
|:---------:|:-------:|:-------:|:------------|
| Tipo | `integer`, `float`, `binary`, `bytes`, `bitstring`, `bits`, `utf8`, `utf16`, `utf32` | `integer` | Tipo del dato del segmento. El valor `bytes` equivale a `binary` y el valor `bits` a `bitstring`. |
| Signo | `signed`, `unsigned` | `unsigned` | Esta propiedad sólo importa cuando el tipo es `integer`, para indicar si tiene signo o no su formato. |
| Orden | `big`, `little`, `native` | `big` | Indica cómo están [orientados los bytes](https://es.wikipedia.org/wiki/Endianness), si se trata de una arquitectura *big-endian* o *little-endian*. Esta propiedad solamente es relevante para los tipos `integer`, `float`, `utf16` y `utf32`. |
| Unidad | `unit:Literal` (Literal = `1`.\.`256`) | `1` (`integer`, `float`,`bitstring`)<br/>`8` (`binary`) | Indica el número de bits que se va a usar como unidad al definir el *tamaño* del segmento. Con los tipos `utf8`, `utf16` y `utf32` no se indica unidad alguna. |

El *dato* dependerá del tipo indicado en el *descriptor* y podremos usar números, cadenas de texto o bloques binarios, siempre y cuando se indique el tipo adecuado, de lo contrario obtendremos un error.

El *tamaño*, dentro del *segmento*, indica en número de unidades el espacio que ocupa. Por ejemplo, si se trata de un *dato* de tipo `integer` y el tamaño es `16`, como por defecto la unidad de 1 bit, el tamaño final del segmento son 16 bits. Si no se indica el *tamaño*, por defecto será de `8` unidades cuando sea un `integer`, de `64` unidades para `float`, y en el caso de `binary` y `bitstring` se tomará el resto del bloque como tamaño.

> La única diferencia relevante entre el tipo `binary` y `bitstring`, es que el primero por defecto maneja unidades de 8 bits, mientras que el segundo maneja unidades de 1 bit, por ello con `binary` es requisito que la información que se vaya a definir o encajar sea múltiplo de 8.

Veamos algunos ejemplos:

```
1> <<_,A/binary>> = <<1, 2, 257:16>>.
<<1,2,1,1>>
2> A.
<<2,1,1>>
3> <<_,B/bitstring>> = <<1, 2, 257:12>>.
<<1,2,16,1:4>>
4> B.
<<2,16,1:4>>
5> <<C,D>> = <<256:16/big>>, {C,D}.
{1,0}
6> <<E,F>> = <<256:16/little>>, {E,F}.
{0,1}
7> <<1024:32, 3.14/float, <<"abc">>/bytes>>.
<<0,0,4,0,64,9,30,184,81,235,133,31,97,98,99>>
8> io:format("~w~n", [<<"Año"/utf8>>]).
<<65,195,177,111>>
9> io:format("~w~n", [<<"Año"/utf16>>]).
<<0,65,0,241,0,111>>
10> io:format("~w~n", [<<"Año"/utf32>>]).
<<0,0,0,65,0,0,0,241,0,0,0,111>>
```

## Operadores

### Comparaciones

| Operador | Descripción |
|:--------:|:-----------:|
| `==`  | Igualdad |
| `/=`  | Desigualdad |
| `=<`  | Menor o igual que |
| `<`   | Menor que |
| `>=`  | Mayor o igual que |
| `>`   | Mayor que |
| `=:=` | Igualdad estricta |
| `=/=` | Desigualdad estricta |

El resultado de las operaciones de comparación son los valores booleanos `true` y `false`, que pertenecen al conjunto de los átomos. La única particularidad, frente a otros lenguajes, es la distinción entre las versiones de la igualdad y la desigualdad. La igualdad estándar, como la desigualdad estándar, realizan una conversión de tipos cuando se comparan enteros y reales entre sí, de modo que el número entero será convertido a formato de coma flotante. En las versiones estrictas de estos dos operadores no se realiza la conversión, por lo que nunca un entero será igual a un real dentro del lenguaje Erlang. Por ejemplo:

```Erlang
1 ==  1.0, % true
1 =:= 1.0. % false
```

Según la documentación de Erlang, la relación entre los diferentes tipos del lenguaje es la siguiente:

```
number < atom < reference < fun < port < pid
       < tuple < map < nil < list < bit string
```

Si bien no es necesario conocer esta relación para programar, es importante que un lenguaje esté bien definido y mantenga un orden fijo para la coherencia de las operaciones.

### Aritméticos

| Operador | Descripción | Tipo |
|:--------:|:-----------:|:----:|
| `+` | Positivo | Número |
| `-` | Negativo | Número |
| `+` | Suma | Número |
| `-` | Resta | Número |
| `*` | Multiplicación | Número |
| `/` | División | Número |
| `div` | División entera | Entero |
| `rem` | Resto de la división | Entero |

Estos operadores funcionan con números y devuelven números como resultado. Salvo en el caso del resto y la división entera, que sólo admiten números enteros, el resto de operadores devolverá como resultado un número entero, salvo que alguno de los operandos sea de coma flotante y por lo tanto se devolverá como resultado un número real.

### Lógica booleana

| Operador | Descripción |
|:--------:|:-----------:|
| `not` | [Negación](https://es.wikipedia.org/wiki/Negaci%C3%B3n_l%C3%B3gica) |
| `and` | [Conjunción](https://es.wikipedia.org/wiki/Conjunci%C3%B3n_l%C3%B3gica) |
| `or`  | [Disyunción](https://es.wikipedia.org/wiki/Disyunci%C3%B3n_l%C3%B3gica) |
| `xor` | [Disyunción exclusiva](https://es.wikipedia.org/wiki/Disyunci%C3%B3n_exclusiva) |

El resultado de estos operadores son valores booleanos, que son los átomos `true` y `false`. También hay que tener en cuenta que sólo admiten como operandos valores booleanos. Para poder entender mejor estas operaciones, veamos sus [tablas de la verdad](https://es.wikipedia.org/wiki/Tabla_de_verdad):

| `A` | `B` | `not A` | `not B` | `A and B` | `A or B` | `A xor B` |
|:---:|:---:|:-------:|:-------:|:---------:|:--------:|:---------:|
| `true`  | `true`  | `false` | `false` | `true`  | `true`  | `false` |
| `false` | `true`  | `true`  | `false` | `false` | `true`  | `true`  |
| `true`  | `false` | `false` | `true`  | `false` | `true`  | `true`  |
| `false` | `false` | `true`  | `true`  | `false` | `false` | `false` |

Estos operadores evalúan toda la expresión, aunque se alcance el resultado final tras terminar de evaluar el operando izquierdo. Por ello el lenguaje dispone de `orelse` y `andalso`, que son versiones de la conjunción y la disyunción con **cortocircuito**. Es decir, si el operando izquierdo en la conjunción es `false`, se devolverá `false` sin evaluar el operando derecho. De modo similar, si el operando izquierdo en la disyunción es `true`, se devolverá `true` sin evaluar el operando derecho.

### Lógica a nivel de bit

| Operador | Descripción |
|:--------:|:-----------:|
| `bnot` | Negación |
| `band` | Conjunción |
| `bor`  | Disyunción |
| `bxor` | Disyunción exclusiva |
| `bsl`  | Desplazamiento de bits a la izquierda |
| `bsr`  | Desplazamiento de bits a la derecha |

Todos estos operadores trabajan con números enteros exclusivamente. Los cuatro primeros operadores funcionan igual que los operadores lógicos booleanos, la diferencia es que, en lugar de usar `true` y `false`, usan los valores binarios `1` y `0` respectivamente. En cuanto a los operadores de desplazamiento de bits, el operando izquierdo es desplazado tantas posiciones como indique el operando derecho:

```
1> 1024 bsr 5.
32
2> 2 bsl 10.
2048
```

> La representación de los enteros en Erlang no se limita a un tamaño fijo como en otros lenguajes. Para enteros pequeños se utilizan 28 bits en arquitecturas de 32 bits y 60 bits en las de 64 bits. Pero para enteros largos se reservan bloques de memoria divisibles por el ancho de palabra de la arquitectura donde se esté ejecutando. De esta manera se pueden representar números enteros extraordinariamente largos, al punto que la expresión `1 bsl (1 bsl 24)` es ejecutable en arquitecturas de 64 bits.

### Listas

| Operador | Descripción |
|:--------:|:-----------:|
| `++` | Concatenación |
| `--` | Eliminación |

Estos dos operadores sólo permiten listas como operandos y devuelven listas. Con `++` se obtiene una nueva lista que concatena dos listas. Con `--` se obtiene una nueva lista en la que se ha ido eliminando los elementos de la lista en el operando derecho. Por ejemplo:

```
1> [1,2,3] ++ [4,5].
[1,2,3,4,5]
2> [1,2,3,2,1,2] -- [2,1,4,2].
[3,1,2]
```

Como se puede ver, para la eliminación, no salta ningún error si el elemento que se busca eliminar no existe. Con este operador tenemos una forma básica de filtrar valores.

### Otros operadores

| Operador | Descripción |
|:--------:|:-----------:|
| `:` | Acceso a módulos |
| `#` | Modificación de estructuras |
| `=` | Encaje de patrones |
| `!` | Envío de mensajes |
| `catch` | Captura de excepciones |

Estos operadores se pueden ver en más detalle en otras secciones, para explicar mejor los conceptos que manejan.

### Precedencia y asociatividad

La precedencia de los operadores es la siguiente:

| Operadores | Asociatividad |
|:----------:|:-------------:|
| `:` |  |
| `#` |  |
| Unarios: `+`, `-`, `bnot`, `not` |  |
| `/`, `*`, `div`, `rem`, `band`, `and` | Izquierda |
| `+`, `-`, `bor`, `bxor`, `bsl`, `bsr`, `or`, `xor` | Izquierda |
| `++`, `--` | Derecha |
| `==`, `/=`, `=<`, `<`, `>=`, `>`, `=:=`, `=/=` |  |
| `andalso` |  |
| `orelse` |  |
| `=`, `!` | Derecha |
| `catch` |  |

> La [asociatividad](https://es.wikipedia.org/wiki/Orden_de_evaluaci%C3%B3n) de un operador indica cómo se va evaluando las expresiones, si es de izquierda a derecha o al revés. Los operadores aritméticos se evalúan de izquierda a derecha, por lo que primero se resuelven aquellas operaciones que están a la izquierda de otra operación con el mismo nivel de prioridad.

Si necesitamos indicar de forma explícita la precedencia de una operación sobre otra, podemos usar el operador de paréntesis `(` `)` de forma idéntica al uso que le damos al operar en matemáticas.

## Encaje de patrones

Una de las propiedades del lenguaje Erlang es el encaje de patrones, este se realiza en múltiples circunstancias, la más obvia de ellas es usando el operador `=`, que vimos en la sección sobre las variables. El encaje de patrones sirve para dos cometidos:

1. Descomponer y seleccionar datos en una expresión.
2. Comprobar el valor de una expresión.

Veamos el siguiente ejemplo para entenderlo mejor:

```Erlang
A = 5,
B = {A, A * 2},
{_, C} = B,
10 = C.
```

La primera expresión asigna el valor `5` a la variable `A`. La segunda expresión asigna a la variable `B` una tupla de dos componentes, la primera con el valor de `A` y la segunda con el valor de `A` multiplicado por `2`. En la tercera expresión, se realiza un ajuste de patrón, para asignar en la variable `C` el valor de la segunda componente de la tupla que está asignada a `B`. Como la primera componente no nos interesa, usamos la variable comodín `_` para descartar dicha información. Por último, comprobamos que el contenido de `C` es el valor `10` usando la expresión `10 = C` en el ejemplo, aunque también podríamos haber usado `C = 10` porque actúan de forma idéntica las dos.

Este mismo comportamiento, que ocurre con el operador `=`, veremos que también se aplica con las cláusulas al llamar una función o al utilizar las expresiones `case`, `receive` y `try`.

### Cláusulas, patrones y guardas

Las **cláusulas** en Erlang son una construcción que permite ajustar un valor a un **patrón** determinado, siempre que se cumplan una serie de condiciones que denominaremos **guardas**. De modo que su sintaxis sería algo tal que:

$$\mathit{patr\acute{o}n}\ \textcolor{red}{[} \texttt{when}\ \mathit{guardas} \textcolor{red}{]}\ \texttt{->}\ \mathit{expresiones}$$

Para la declaración de funciones, la sintaxis varía ligeramente porque el ajuste se realiza sobre cero o más parámetros, recibidos en la invocación de dicha función.

Para ser más precisos, un **patrón** es una expresión que define una estructura de datos y que contiene variables y valores literales. Si las variables están ya ligadas a un valor, se comprobará que se ajusten los valores con lo que se intenta encajar, si no están ligadas se asignará el valor que se está encajando. Por ejemplo, cuando se utiliza el operador `=`, el lado izquierdo ha de ser un patrón, mientras que el derecho es la expresión que nos da el valor que se va a intentar encajar.

En cuanto a las **guardas**, estas son expresiones booleanas. Si no se indica ninguna guarda, por defecto se utiliza el valor `true` internamente. Una condición que debe cumplir las guardas, es que no debe tener ningún efecto colateral al evaluarse. Para ello, están limitados los elementos que pueden formar parte de una guarda a los siguientes:

- Variables
- Constantes
- Constructores de átomos, números, listas, tuplas, registros, bloques binarios y mapas.
- Expresiones para actualizar mapas.
- Expresiones con registros como: `Expresión#Nombre.Campo` y `#Nombre.Campo`.
- Operaciones de comparación, aritméticas, lógicas booleanas y a nivel de bit, así como los operadores lógicos `andalso` y `orelse`.
- Las siguientes funciones nativas del lenguaje:
	- Comprobación de tipos: `is_atom/1`, `is_binary/1`, `is_bitstring/1`, `is_boolean/1`, `is_float/1`, `is_function/1`, `is_function/2`, `is_integer/1`, `is_list/1`, `is_map/1`, `is_number/1`, `is_pid/1`, `is_port/1`, `is_record/2`, `is_record/3`, `is_reference/1`, `is_tuple/1`.
	- Operaciones varias: `abs/1`, `bit_size/1`, `byte_size/1`, `element/2`, `float/1`, `hd/1`, `is_map_key/2`, `length/1`, `map_get/2`, `map_size/1`, `node/0`, `node/1`, `round/1`, `self/0`, `size/1`, `tl/1`, `trunc/1`, `tuple_size/1`.

En la sección sobre las funciones, se habla en más detalle sobre las [funciones nativas del lenguaje](https://www.erlang.org/doc/man/erlang.html) que hay en Erlang. Volviendo a las guardas, podemos tener una secuencia de ellas utilizando una de estas dos formas:

$$\mathit{guarda_1} \texttt{,} \dots \texttt{,} \mathit{guarda_n}$$

$$\mathit{guarda_1} \texttt{;} \dots \texttt{;} \mathit{guarda_n}$$

Usando la coma (`,`) es requisito que todas las guardas den como resultado `true`, mientras que con el punto y coma (`;`) sólo es necesario que una de las guardas sea cierta. Esta sintaxis vendría a ser un equivalente de usar `andalso` para el caso de la coma y `orelse` para el caso del punto y coma, la principal diferencia es que usando operadores no se capturan las excepciones cuando se producen, es decir, `hd(1) orelse true` fallaría, pero `hd(1); true` tendría éxito.

### Encaje con mapas

Podemos usar la siguiente sintaxis como patrón de encaje con mapas:

$$\texttt{\char35\char123} \textcolor{red}{[} \mathit{clave_1}\ \texttt{:=}\ \mathit{patr\acute{o}n_1} \textcolor{red}{[} \texttt{,} \dots \textcolor{red}{[} \texttt{,} \mathit{clave_n}\ \texttt{:=}\ \mathit{patr\acute{o}n_n} \textcolor{red}{]} \textcolor{red}{]} \textcolor{red}{]} \texttt{\char125}$$

Como requisito, para que funcione correctamente, las claves tienen que cumplir los mismos requisitos que cumplen las guardas de las cláusulas, lo cual implica que todas las variables internas han de estar previamente ligadas. Si las claves son encontradas, los valores de estas son ajustados a los patrones definidos.

En caso de no encontrar alguna de las claves indicadas, se lanzará una excepción de tipo `badmatch` si el encaje se realiza mediante el operador `=`. Si el encaje se está realizando en el patrón de una cláusula, en caso de fallar el ajuste se pasará a la siguiente cláusula.

## Secuencias intensionales

Además de poder crear listas mediante literales y con el uso de operadores, podemos utilizar las listas intensionales para crear nuevas listas a partir de otra, realizando filtrados y transformaciones. Para ello existe la siguiente sintaxis:

$$\texttt{[} \mathit{expresi\acute{o}n}\  \texttt{||}\ \textcolor{red}{[} \mathit{generador_1} \textcolor{red}{[} \texttt{,} \dots \textcolor{red}{[} \texttt{,} \mathit{generador_n} \textcolor{red}{]} \textcolor{red}{]} \textcolor{red}{]} \texttt{]}$$

Donde la expresión generadora puede ser una de las siguientes:

$$\textcolor{red}{\char123} \mathit{patr\acute{o}n}\ \texttt{<-}\ \mathit{lista}\ \textcolor{red}{|}\ \mathit{patr\acute{o}n}\ \texttt{<=}\ \mathit{binario}
\ \textcolor{red}{|}\ \mathit{guarda} \textcolor{red}{\char125}$$

El primer tipo de generador ajusta un patrón con cada elemento de la lista. El segundo hace lo mismo que el primero pero con cada elemento dentro de un bloque binario. Finalmente, podemos usar guardas como predicados para filtrar los elementos de la lista de entrada, de modo que se usarán aquellos elementos que den como resultado `true` con el predicado, y aquellos que den `false` serán descartados. Por ejemplo:

```
1> L=[3,e,4.5,f,{1,2},7].
[3,e,4.5,f,{1,2},7]
2> [X || X <- L, is_integer(X)].
[3,7]
```

La lista intensional `[X || X <- L, is_integer(X)]` nos devuelve sólo los números enteros de `L`. Obviamente `4.5`, aunque es un número, no es un entero y por ello queda descartado.

De forma análoga a las listas, con los bloques binarios podemos también crear bloques binarios intensionales con la siguiente sintaxis:

$$\texttt{<<} \mathit{expresi\acute{o}n}\  \texttt{||}\ \textcolor{red}{[} \mathit{generador_1} \textcolor{red}{[} \texttt{,} \dots \textcolor{red}{[} \texttt{,} \mathit{generador_n} \textcolor{red}{]} \textcolor{red}{]} \textcolor{red}{]} \texttt{>>}$$

Los generadores que se usan son los mismos que usamos con las listas.

## Funciones

Las funciones son bloques de código que realizan diferentes tareas. Para realizar programas y algoritmos necesitamos descomponer el problema en diferentes funciones.

### Invocar funciones

Para poder **ejecutar una función** tenemos que invocarla usando la siguiente sintaxis:

$$\textcolor{red}{[} \mathit{m\acute{o}dulo} \textcolor{red}{]} \texttt{:} \mathit{funci\acute{o}n} \texttt{(} \textcolor{red}{[} \mathit{par\acute{a}metro_1} \textcolor{red}{[} \texttt{,} \dots \textcolor{red}{[} \texttt{,} \mathit{par\acute{a}metro_n} \textcolor{red}{]} \textcolor{red}{]} \textcolor{red}{]} \texttt{)}$$

Indicando el módulo podemos llamar a funciones que están en otros módulos. Si se omite el módulo, se asume que estamos usando funciones del módulo actual.

### Funciones como valores

Hay que tener en cuenta que las **funciones son valores** para el lenguaje, por lo que podemos usarlas como parámetros de otras funciones y devolverlas. Por lo tanto, Erlang es un lenguaje con [funciones de orden superior](https://es.wikipedia.org/wiki/Funci%C3%B3n_de_orden_superior). Entonces, si queremos referenciar a una función con nombre como un valor, usaremos la siguiente sintaxis:

$$\texttt{fun}\ \textcolor{red}{[} \mathit{m\acute{o}dulo} \textcolor{red}{]} \texttt{:} \mathit{funci\acute{o}n} \texttt{/} \mathit{aridad}$$

De este modo, con `fun hello:world/0` tendríamos el valor que representa a la función `world` dentro del módulo `hello`. Si no indicamos el módulo, se asume que se trata del módulo actual que estemos codificando. Una vez está una variable ligada a una función, podemos usar la variable para invocar la función, pasando entre paréntesis los parámetros que necesita. Por ejemplo:

```
1> l(hello).
{module,hello}
2> Hi = fun hello:world/0.
fun hello:world/0
3> Hi().
Hello, world!
```

### Definir funciones

Para poder **definir funciones** se utiliza la siguiente sintaxis:

$$\mathit{nombre} \texttt{(} \mathit{patrones_1} \texttt{)}\ \textcolor{red}{[} \texttt{when}\ \mathit{guardas_1} \textcolor{red}{]}\ \texttt{->}\ \mathit{expresiones_1}\texttt{;}$$

$$\vdots$$

$$\mathit{nombre} \texttt{(} \mathit{patrones_n} \texttt{)}\ \textcolor{red}{[} \texttt{when}\ \mathit{guardas_n} \textcolor{red}{]}\ \texttt{->}\ \mathit{expresiones_n}\texttt{.}$$

Como podemos ver, lo que tenemos aquí es una **secuencia de cláusulas** que componen la función. Los **patrones** y **expresiones** son secuencias separadas por comas de patrones y expresiones respectivamente. Cada patrón representa los **argumentos** de la función y las expresiones son el **cuerpo** de la función, es decir:

$$\textcolor{red}{[} \mathit{patr\acute{o}n_1} \textcolor{red}{[} \texttt{,} \dots \textcolor{red}{[} \texttt{,} \mathit{patr\acute{o}n_n} \textcolor{red}{]} \textcolor{red}{]} \textcolor{red}{]}$$

$$\mathit{expresi\acute{o}n_1} \textcolor{red}{[} \texttt{,} \dots \textcolor{red}{[} \texttt{,} \mathit{expresi\acute{o}n_m} \textcolor{red}{]} \textcolor{red}{]}$$

La diferencia es que, mientras que podemos tener una función sin argumentos, el cuerpo de la función requiere al menos una expresión. El caso de que no se indique la guarda para la cláusula funcional, se asume por defecto como guarda el valor `true`. Por ejemplo:

```Erlang
fact(N) when N > 0 ->
    N * fact(N - 1);
fact(0) ->
    1.
```

La función `fact` calcula el factorial, para ello tiene la cláusula recursiva primero y segundo el caso base. Hay que entender que el **orden** de las **cláusulas** es importante, porque para evaluar cual hay que seleccionar se hace en orden de definición, escogiendo la primera que permita ajustar los parámetros de entrada con sus patrones y su guarda sea cierta. Por ejemplo:

```Erlang
foo(X) when X >= 0 -> up;
foo(X) when X =< 0 -> down.

bar(X) when X =< 0 -> down;
bar(X) when X >= 0 -> up.

test() -> foo(0) =:= bar(0).
```

El resultado de `test()` es el valor `false`, ya que aplicar el valor `0` a `foo` y `bar` da resultados distintos aunque el código parezca el mismo. Esto es porque hay superposición de casos entre las cláusulas y se escogerá la primera que se pueda usar con éxito. Por ello, cuando usemos la variable comodín `_`, como patrón de ajuste, es importante usarla en una cláusula que no bloquee el acceso a las siguientes salvo que haya una muy buena razón.

### Funciones lambda

También se pueden definir funciones anónimas, también conocidas como [funciones lambda](https://es.wikipedia.org/wiki/Expresi%C3%B3n_lambda). Para ello se utiliza la siguiente sintaxis:

$$\texttt{fun} \qquad\qquad\qquad\qquad\qquad\qquad\qquad\qquad\qquad\qquad\qquad\qquad\qquad$$

$$\textcolor{red}{[} \mathit{Variable} \textcolor{red}{]} \texttt{(} \mathit{patrones_1} \texttt{)}\ \textcolor{red}{[} \texttt{when}\ \mathit{guardas_1} \textcolor{red}{]}\ \texttt{->}\ \mathit{expresiones_1}\texttt{;}$$

$$\vdots$$

$$\textcolor{red}{[} \mathit{Variable} \textcolor{red}{]} \texttt{(} \mathit{patrones_n} \texttt{)}\ \textcolor{red}{[} \texttt{when}\ \mathit{guardas_n} \textcolor{red}{]}\ \texttt{->}\ \mathit{expresiones_n}$$

$$\texttt{end} \qquad\qquad\qquad\qquad\qquad\qquad\qquad\qquad\qquad\qquad\qquad\qquad\qquad$$

La sintaxis es muy similar a la declaración de funciones normales, pero las lambdas no tienen nombre propio, por ello para poder realizar lambdas recursivas se puede utilizar una variable para invocar a la función anónima desde dentro. Por ejemplo:

```Erlang
foo()  ->
    fun Fact(N) when N > 0 ->
		    N * Fact(N - 1);
		Fact(0) ->
		    1
	end.
```

La función `foo` nos devuelve una función que contiene la función factorial.

### Recursión de cola

Otro aspecto importante al diseñar funciones, es la **recursión de cola**.  En programación funcional la recursión es esencial, porque la iteración se realiza mediante la recursión.

Si el resultado de la llamada recursiva se tiene que utilizar para realizar más cálculos, se tiene que almacenar en la pila de llamadas la información que contiene la llamada actual, para que no se pierda al evaluar las siguientes iteraciones recursivas. Aunque dispongamos de muchos recursos en cuanto a memoria, en determinadas circunstancias se puede provocar un desbordamiento de pila por realizarse una cantidad grande de llamadas a función anidadas.

La recursión de cola se produce cuando la expresión final a devolver es la llamada recursiva a la función, por lo que todos los parámetros de la llamada se evalúan antes de la llamada y no hace falta guardar en la pila ninguna información. La ventaja es que este tipo de recursión no puede desbordar la pila y nos sirve, por ejemplo, para hacer bucles infinitos cuando necesitamos un servidor que recibe y envía mensajes. Para entenderlo mejor, vamos a ver el ejemplo del factorial con recursión de cola:

```Erlang
fact(N) ->
    ifact(N,1).

ifact(N, R) when N > 0 ->
    ifact(N - 1, R * N);
ifact(0, R) ->
    R.
```

## Control de la ejecución

La primera expresión de control es el `case` que tiene la siguiente sintaxis:

$$\texttt{fun}\ \mathit{expresi\acute{o}n}\ \texttt{of} \qquad\qquad\qquad\qquad\qquad\qquad\qquad\qquad$$

$$\mathit{patr\acute{o}n_1}\ \textcolor{red}{[} \texttt{when}\ \mathit{guardas_1} \textcolor{red}{]}\ \texttt{->}\ \mathit{expresiones_1}\texttt{;}$$

$$\vdots$$

$$\mathit{patr\acute{o}n_n}\ \textcolor{red}{[} \texttt{when}\ \mathit{guardas_n} \textcolor{red}{]}\ \texttt{->}\ \mathit{expresiones_n}$$

$$\texttt{end} \qquad\qquad\qquad\qquad\qquad\qquad\qquad\qquad\qquad\qquad\quad$$

..

## Procesos y comunicación

..

## Errores y excepciones

..

## Módulos

Los [módulos](https://www.erlang.org/doc/reference_manual/modules.html) en Erlang son la unidad en la que se organiza el código de nuestros proyectos. Todo **módulo** se compone en una secuencia de **atributos** y declaración de **funciones**, terminadas con punto cada una de ellas.

 Aunque Erlang es un lenguaje donde las variables obtienen su tipo de forma dinámica, el lenguaje nos permite definir tipos para documentar los módulos usando la [especificación de tipos](https://www.erlang.org/doc/reference_manual/typespec.html). Que un lenguaje no requiera indicar el tipo de sus variables, no quiere decir que este lenguaje no tenga un sistema de tipos, por ello también es importante conocer cuáles son los tipos con los que trabaja el lenguaje.

### Atributos de un módulo

Todo atributo en Erlang tiene la siguiente sintaxis:

$$\texttt{-} \mathit{etiqueta} \texttt{(} \mathit{valor_1} \textcolor{red}{[} \texttt{,}\ \mathit{valor_2} \textcolor{red}{]} \texttt{)}$$

Donde la *etiqueta* es un átomo y los *valores* son expresiones literales. Esta es la lista de atributos básicos que se puede definir para un módulo:

| Etiqueta | Parámetros y Tipos | Descripción |
|:--------:|:-------------------|:------------|
| `module` | Nombre: `atom()` | Declara cuál es el nombre del módulo. Por requisitos técnicos, el nombre del fichero y del módulo han de ser el mismo, exceptuando por la extensión `.erl`. |
| `export` | Funciones: `[atom()/integer()]` | Declara cuáles son las funciones públicas del módulo, aquellas que pueden ser accesibles desde otros módulos. El parámetro *funciones* es una lista con los identificadores de las funciones, que tienen la sintaxis `Nombre/Aridad`. |
| `import` | Nombre: `atom()`<br/>Funciones: `[atom()/integer()]` | Importa una lista de funciones dentro del módulo actual, para no necesitar usar el operador `:` al invocar dichas funciones, usando únicamente el nombre de las mismas. |
| `compile` | Opciones: `option()` o `[option()]` | Añade opciones de compilación extras al compilar el módulo. El parámetro *opciones* puede ser una sola opción o una lista de ellas, las cuales están descritas en la documentación del módulo [`compile`](https://www.erlang.org/doc/man/compile.html).  |
| `vsn` | Versión: `any()` | Declara la versión del módulo. La versión es cualquier literal y se puede obtener con la función `version/1` del módulo [`beam_lib`](https://www.erlang.org/doc/reference_manual/typespec.html). |
| `on_load` | Función: `atom()/integer()` | Indica qué función, dentro del módulo, ha de ser invocada al cargarse. |
| `behaviour` | Nombre: `atom()` | Indica que el módulo implementa los *callbacks* que definen a un comportamiento. |

> Cuando en Erlang se usa la forma `Nombre/Aridad`, el compilador lo traduce a la expresión `{Nombre,Aridad}`.

### Las funciones: `module_info`

Todo módulo contiene dos funciones generadas por el compilador que son `module_info/0` y `module_info/1`, que devuelven información relativa al módulo en cuestión. El resultado de `module_info/0` devuelve una lista de tuplas `{Clave,Valor}`, mientras que `module_info/1` recibe como parámetro la *clave* y te devuelve el *valor* asociado. Estas son las *claves* disponibles:

| Clave | Tipo | Descripción |
|:-----:|:-----:|:------------|
| `module` | `atom()` | Devuelve el nombre del módulo. |
| `attributes` | `[atom(),any()]` | Devuelve los atributos del módulo mediante una lista de tuplas `{Etiqueta, Valores}`. |
| `compile` | `[option()]` | Devuelve una lista con las opciones usadas para compilar el módulo. |
| `exports` | `[{atom(),integer()}]` | Devuelve una lista con las funciones públicas del módulo. |
| `functions` | `[{atom(),integer()}]` | Devuelve una lista con todas las funciones del módulo. |
| `md5` | `binary()` | Devuelve un bloque binario que representa la [suma de verificación](https://es.wikipedia.org/wiki/Suma_de_verificaci%C3%B3n) [MD5](https://es.wikipedia.org/wiki/MD5) del módulo. |
| `native` | `boolean()` | Devuelve si el módulo contiene [funciones nativas](https://www.erlang.org/doc/tutorial/nif.html). |
| `nifs` | `[{atom(),integer()}]` | Devuelve una lista con todas las [funciones nativas](https://www.erlang.org/doc/tutorial/nif.html) del módulo. |

### Preprocesador

El [preprocesador](https://www.erlang.org/doc/reference_manual/macros.html) en Erlang nos permite realizar operaciones de sustitución durante la compilación de un módulo.

..

## Registros

Los [registros](https://www.erlang.org/doc/reference_manual/records.html) es un mecanismo que Erlang tiene para definir estructuras de datos cuyas componentes tienen nombre. Para simplificarlo, sería equivalente a una tupla donde cada componente de la misma tiene un nombre propio con el que acceder a ella.

..

## Comportamientos

Lo *comportamientos* en Erlang es un tipo de interfaz que un módulo puede implementar. Esta interfaz tienen que tener una serie de funciones determinadas, para que el módulo, que define la interfaz de comportamiento, pueda operar con el módulo que la implementa. Estas funciones que ha de tener un módulo para implementar un *comportamiento* se llaman *callbacks*. Declaramos la implementación de un *comportamiento* con el siguiente atributo:

$$\texttt{-behaviour(} \mathit{nombre} \texttt{)}$$

El nombre es un átomo con el nombre del módulo que define el *comportamiento* en cuestión, ya sea uno definido por el usuario o uno de los siguientes de la biblioteca estándar de OTP: `gen_server`, `gen_statem`, `gen_event`, `supervisor`. Erlang también permite usar `behavior` como etiqueta del atributo.

Para crear una interfaz de comportamiento propia, dentro de nuestro módulo tendremos que indicar una lista de atributos que definan los *callbacks* a implementar, usando una sintaxis similar a la [especificación de tipos](https://www.erlang.org/doc/reference_manual/typespec.html):

$$\texttt{-callback}\ \mathit{nombre} \texttt{(} \textcolor{red}{[} \mathit{var_1}\ \textcolor{red}{[} \mathtt{::}\ \mathit{tipo_1} \textcolor{red}{]} \textcolor{red}{[} \texttt{,} \dots \textcolor{red}{[} \texttt{,} \mathit{var_n}\ \textcolor{red}{[} \mathtt{::}\ \mathit{tipo_n} \textcolor{red}{]} \textcolor{red}{]} \textcolor{red}{]} \textcolor{red}{]} \texttt{)}\ \texttt{->}\ \mathit{tipo}$$

Además tenemos el atributo de módulo `optional_callbacks`, que tiene como valor una lista de los *callbacks* (`Nombre/Aridad`) que son opcionales para implementar la interfaz de comportamiento.

Por ejemplo, creamos la siguiente interfaz de comportamiento:

```Erlang
-module(foobeh).

% Otros atributos

-callback ping() -> boolean().
-callback pong() -> boolean().

% Otras funciones
```

Para implementarla tendremos que:

```Erlang
-module(foo).
-behaviour(foobeh).
-export([ping/0, pong/0]).

% Otros atributos

ping() -> true.
pong() -> false.

% Otras funciones
```

### El comportamiento: `gen_server`

..

### El comportamiento: `gen_statem`

..

### El comportamiento: `gen_event`

..

### El comportamiento: `supervisor`

..

```Erlang
.
```

