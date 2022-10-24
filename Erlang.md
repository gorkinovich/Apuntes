

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

$$\texttt{\char123} \textcolor{red}{[} \mathit{expresi\acute{o}n_1} \textcolor{red}{[} \texttt{,} \dots \texttt{,} \mathit{expresi\acute{o}n_n} \textcolor{red}{]} \textcolor{red}{]} \texttt{\char125}$$

Por ejemplo: `{}`, `{0, a}`, `{{data, 3.14}, Foo, {}, 8}`.

### Listas

Las listas son estructuras de datos que agrupan información de forma ordenada con un tamaño variable. Su sintaxis es la siguiente:

$$\texttt{[} \textcolor{red}{[} \mathit{expresi\acute{o}n_1}  \texttt{|} \mathit{expresi\acute{o}n_2} \textcolor{red}{]} \texttt{]}$$

Este es el constructor de listas, que podemos hacer una lista vacía con `[]`, o podemos hacer una lista no vacía donde la primera expresión es el valor en la **cabecera** de dicha lista y la segunda la **continuación**. Por ejemplo: `[1, [2 | []]]`, que es la lista con los valores `1` y `2` en orden. La continuación, también denominada **cola** de la lista, puede ser cualquier valor posible, por lo que podemos tener una lista tal que: `[z | 80]`.

> Que la cola pueda ser cualquier valor puede provocar que la terminación de la lista no sea una lista vacía, en cuyo caso se le denomina como **lista impropia**, frente a las **listas propias**. Esta distinción es importante a la hora de analizar el tipo de una expresión, pues hay funciones que sólo funcionan con listas propias, por lo que fallarían al recibir una impropia ya que nunca llegarían a la condición final de parar con la lista vacía.

A diferencia de los lenguajes fuertemente tipados, como es el caso de [Haskell](https://www.haskell.org/), las listas en Erlang pueden ser heterogéneas en relación a los tipos de los valores que contiene, gracias a su naturaleza de lenguaje con tipado dinámico.

Como definir listas más complejas, con el constructor de listas, puede llegar a ser costoso y confuso, existe una sintaxis alternativa para definir listas:

$$\texttt{[} \textcolor{red}{[} \mathit{expresi\acute{o}n_1} \textcolor{red}{[} \texttt{,} \dots \texttt{,} \mathit{expresi\acute{o}n_n} \textcolor{red}{]} \textcolor{red}{]} \texttt{]}$$

De este modo, la lista `[1, [2 | []]]` se puede definir como `[1, 2]`, siendo más legible para el programador. Internamente, para la máquina virtual, son la misma cosa porque esta forma de sintaxis es azúcar sintáctico.

Dentro de la biblioteca estándar existe el módulo [`lists`](https://www.erlang.org/doc/man/lists.html), con una buena colección de funciones que permiten consultar y transformar listas, algunas de ellas bastante avanzadas.


### Mapas

Los mapas son estructuras de datos que relacionan una clave con un valor. Aunque también se le conoce como diccionarios en otros lenguajes, la [biblioteca estándar](https://www.erlang.org/doc/man/stdlib_app) de Erlang tiene otro tipo de estructura nativa que se llama diccionario (módulo `dict`), por lo que usaremos el término mapa para evitar confusiones innecesarias. Los mapas se añadieron como sustitución de los diccionarios implementados, para corregir algunas carencias que tenía el lenguaje.

La sintaxis para crear un mapa es la siguiente:

$$\texttt{\char35\char123} \textcolor{red}{[} \mathit{clave_1}\ \texttt{=>}\ \mathit{valor_1} \textcolor{red}{[} \texttt{,} \dots \texttt{,} \mathit{clave_n}\ \texttt{=>}\ \mathit{valor_n} \textcolor{red}{]} \textcolor{red}{]} \texttt{\char125}$$

Tanto las claves, como los valores, pueden ser de cualquier tipo. Para actualizar un mapa previo, usaremos esta sintaxis:

$$\mathit{mapa}\texttt{\char35\char123} \mathit{clave}\ \texttt{=>}\ \mathit{valor} \texttt{\char125}$$

De este modo se devuelve un nuevo mapa, donde se asigna un valor a la clave indicada, existiera esta previamente o no. Existe otra variante para actualizar un mapa previo con:

$$\mathit{mapa}\texttt{\char35\char123} \mathit{clave}\ \texttt{:=}\ \mathit{valor} \texttt{\char125}$$

Con esta versión, si la clave no existe previamente, no se actualizará el contenido del nuevo mapa creado y será simplemente una copia idéntica del mapa que hemos intentado modificar.

El módulo [`maps`](https://www.erlang.org/doc/man/maps.html) contiene una serie de funciones que permite trabajar con mapas, para poder consultar su contenido o realizar transformaciones avanzadas.

### Bloques binarios

Debido a que Erlang fue diseñado para construir sistemas de telecomunicaciones, existía la necesidad de tener las herramientas para poder procesar protocolos e información a nivel de bytes e incluso de bits. Para ello se tiene en Erlang la siguiente sintaxis:

$$\texttt{<<} \textcolor{red}{[} \mathit{segmento_1} \textcolor{red}{[} \texttt{,} \dots \texttt{,} \mathit{segmento_n} \textcolor{red}{]} \textcolor{red}{]} \texttt{>>}$$

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

### Registros

Los [registros](https://www.erlang.org/doc/reference_manual/records.html) es un mecanismo que Erlang tiene para definir estructuras de datos cuyas componentes tienen nombre. Para simplificarlo, sería equivalente a una tupla donde cada componente de la misma tiene un nombre propio con el que acceder a ella.

> La ventaja principal, frente a las tuplas, es su mayor flexibilidad a la hora de modificar el tamaño de definiciones previas. Modificar de tamaño una tupla implica tener que revisar todo el código, para actualizar todas las tuplas que deben encajar con la modificada. Sin embargo, con registros se puede aumentar el número de componentes sin romper el código anterior. Además, el uso de registros añade una mayor claridad para entender el acceso a los datos.

Para definir un registro usamos la siguiente sintaxis:

$$\texttt{-record(} \mathit{nombre} \texttt{,} \texttt{\char123} \mathit{campo_1} \textcolor{red}{[} \texttt{=} \mathit{valor_1} \textcolor{red}{]} \textcolor{red}{[} \texttt{,} \dots \texttt{,} \mathit{campo_n} \textcolor{red}{[} \texttt{=} \mathit{valor_n} \textcolor{red}{]} \textcolor{red}{]} \texttt{\char125} \texttt{)}$$

Esto crea un registro con el *nombre* indicado para el módulo donde ha sido definido. De forma opcional se puede indicar valores por defecto de inicialización cuando se crea un valor. La sintaxis para crear un valor es el siguiente:

$$\texttt{\char35} \mathit{nombre} \texttt{\char123} \textcolor{red}{[} \mathit{campo_1} \texttt{=} \mathit{expresi\acute{o}n_1} \textcolor{red}{[} \texttt{,} \dots \texttt{,} \mathit{campo_n} \texttt{=} \mathit{expresi\acute{o}n_n} \textcolor{red}{]} \textcolor{red}{]} \texttt{\char125} \texttt{)}$$

En caso de dejar campos sin definir en el constructor, se les asignará el valor `undefined`. También se puede usar como *campo* la variable comodín `_` para inicializar todos aquellos que no hayan sido explícitamente indicados en el constructor. Para modificar un valor de registro previo se usa la siguiente sintaxis:

$$\mathit{variable} \texttt{\char35} \mathit{nombre} \texttt{\char123} \mathit{campo_1} \texttt{=} \mathit{expresi\acute{o}n_1} \textcolor{red}{[} \texttt{,} \dots \texttt{,} \mathit{campo_n} \texttt{=} \mathit{expresi\acute{o}n_n} \textcolor{red}{]} \texttt{\char125} \texttt{)}$$

Esto devuelve un nuevo calor con la información modificada. Para pode acceder a un campo se usa la sintaxis:

$$\mathit{variable} \texttt{\char35} \mathit{nombre} \texttt{.} \mathit{campo}$$

Esto devuelve el valor asociado al *campo*. Es perfectamente posible anidar registros dentro de otros registros. Para acceder al contenido simplemente hay que usar la sintaxis anterior aplicada al campo en cuestión.

> En versiones anteriores a la `R14`, para acceder al contenido de un registro anidado en otro registro, era necesario usar paréntesis para ayudar al compilador con el análisis. Por suerte, se eliminó esa limitación.

Si necesitamos saber cuál es la posición del campo dentro de la tupla usaremos:

$$\texttt{\char35} \mathit{nombre} \texttt{.} \mathit{campo}$$

Por ejemplo:

```Erlang
-record(state,{first=1, second=2, third=3}).

foo() ->
    S1 = #state{},
    S2 = #state{first="ichi", _=null},
    S3 = S2#state{second="ni", third="san"},
    io:format("S1 = ~p~n", [S1]),
    io:format("S2 = ~p~n", [S2]),
    io:format("S3 = ~p~n", [S3]),
    io:format("first = ~p~n", [#state.first]),
    io:format("second = ~p~n", [#state.second]),
    io:format("third = ~p~n", [#state.third]),
    io:format("S2.first = ~p~n", [S2#state.first]).
```

Obtenemos por consola el siguiente resultado:

```
S1 = {state,1,2,3}
S2 = {state,"ichi",null,null}
S3 = {state,"ichi","ni","san"}
first = 2
second = 3
third = 4
S2.first = "ichi"
```

Como se puede observar, internamente es una tupla la estructura. Es el compilador el que se encarga de analizar el código y traducirlo, sin tener que cambiar la implementación interna de Erlang.

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

$$\texttt{\char35\char123} \textcolor{red}{[} \mathit{clave_1}\ \texttt{:=}\ \mathit{patr\acute{o}n_1} \textcolor{red}{[} \texttt{,} \dots \texttt{,} \mathit{clave_n}\ \texttt{:=}\ \mathit{patr\acute{o}n_n} \textcolor{red}{]} \textcolor{red}{]} \texttt{\char125}$$

Como requisito, para que funcione correctamente, las claves tienen que cumplir los mismos requisitos que cumplen las guardas de las cláusulas, lo cual implica que todas las variables internas han de estar previamente ligadas. Si las claves son encontradas, los valores de estas son ajustados a los patrones definidos.

En caso de no encontrar alguna de las claves indicadas, se lanzará una excepción de tipo `badmatch` si el encaje se realiza mediante el operador `=`. Si el encaje se está realizando en el patrón de una cláusula, en caso de fallar el ajuste se pasará a la siguiente cláusula.

### Encaje con registros

Podemos usar la siguiente sintaxis como patrón de encaje con registros:

$$\texttt{\char35} \mathit{nombre} \texttt{\char123} \textcolor{red}{[} \mathit{campo_1} \texttt{=} \mathit{patr\acute{o}n_1} \textcolor{red}{[} \texttt{,} \dots \texttt{,} \mathit{campo_n} \texttt{=} \mathit{patr\acute{o}n_n} \textcolor{red}{]} \textcolor{red}{]} \texttt{\char125} \texttt{)}$$

Funciona parecido a las tuplas, a la hora de hacer un ajuste de patrones, pero con algo más de flexibilidad en cuanto a la posición de los componentes.

## Secuencias intensionales

Además de poder crear listas mediante literales y con el uso de operadores, podemos utilizar las listas intensionales para crear nuevas listas a partir de otra, realizando filtrados y transformaciones. Para ello existe la siguiente sintaxis:

$$\texttt{[} \mathit{expresi\acute{o}n}\  \texttt{||}\ \mathit{generador_1} \textcolor{red}{[} \texttt{,} \dots \texttt{,} \mathit{generador_n} \textcolor{red}{]} \texttt{]}$$

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

$$\texttt{<<} \mathit{expresi\acute{o}n}\  \texttt{||}\ \mathit{generador_1} \textcolor{red}{[} \texttt{,} \dots \texttt{,} \mathit{generador_n} \textcolor{red}{]} \texttt{>>}$$

Los generadores que se usan son los mismos que usamos con las listas.

## Funciones

Las funciones son bloques de código que realizan diferentes tareas. Para realizar programas y algoritmos necesitamos descomponer el problema en diferentes funciones.

### Invocar funciones

Para poder **ejecutar una función** tenemos que invocarla usando la siguiente sintaxis:

$$\textcolor{red}{[} \mathit{m\acute{o}dulo} \textcolor{red}{]} \texttt{:} \mathit{funci\acute{o}n} \texttt{(} \textcolor{red}{[} \mathit{par\acute{a}metro_1} \textcolor{red}{[} \texttt{,} \dots \texttt{,} \mathit{par\acute{a}metro_n} \textcolor{red}{]} \textcolor{red}{]} \texttt{)}$$

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

$$\textcolor{red}{[} \mathit{patr\acute{o}n_1} \textcolor{red}{[} \texttt{,} \dots \texttt{,} \mathit{patr\acute{o}n_n} \textcolor{red}{]} \textcolor{red}{]}$$

$$\mathit{expresi\acute{o}n_1} \textcolor{red}{[} \texttt{,} \dots \texttt{,} \mathit{expresi\acute{o}n_m} \textcolor{red}{]}$$

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

> Las expresiones lambda crean un ámbito nuevo para las variables, por lo tanto, si definimos una variable `X` como parámetro de entrada y existe la misma variable fuera de la lambda, la variable interna ocultará el acceso a la exterior.

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

$$\texttt{case}\ \mathit{expresi\acute{o}n}\ \texttt{of} \qquad\qquad\qquad\qquad\qquad\qquad\qquad\qquad$$

$$\mathit{patr\acute{o}n_1}\ \textcolor{red}{[} \texttt{when}\ \mathit{guardas_1} \textcolor{red}{]}\ \texttt{->}\ \mathit{expresiones_1}\texttt{;}$$

$$\vdots$$

$$\mathit{patr\acute{o}n_n}\ \textcolor{red}{[} \texttt{when}\ \mathit{guardas_n} \textcolor{red}{]}\ \texttt{->}\ \mathit{expresiones_n}$$

$$\texttt{end} \qquad\qquad\qquad\qquad\qquad\qquad\qquad\qquad\qquad\qquad\qquad$$

Las expresiones `case` sirven para ramificar la ejecución en base al resultado de una *expresión* dada como discriminante. Una vez evaluada la *expresión*, se toma el valor final y se intenta ajustar con las cláusulas definidas. Como pasaba con las funciones, las cláusulas van siendo probadas en el orden en el que están definidas y la primera que logre ajustar el valor, y pasar su guarda, será la que se ejecute finalmente. Por ejemplo:

```Erlang
fact(N) ->
    case N of
        (N) when N > 0 ->
            N * fact(N - 1);
        (0) ->
            1
    end.
```

Aquí vemos la implementación del factorial usando un `case`. Erlang, internamente, convierte las cláusulas funcionales en expresiones `case` al compilar los módulos, pero por comodidad y limpieza es mejor usar cláusulas funcionales.

La expresión `if` tiene la siguiente sintaxis:

$$\texttt{if} \qquad\qquad\qquad\qquad\qquad\qquad\qquad$$

$$\mathit{guardas_1}\ \texttt{->}\ \mathit{expresiones_1}\texttt{;}$$

$$\vdots$$

$$\mathit{guardas_n}\ \texttt{->}\ \mathit{expresiones_n}$$

$$\texttt{end} \qquad\qquad\qquad\qquad\qquad\qquad\qquad$$

Las expresiones `if` también sirven para ramificar la ejecución, pero esta ramificación se hace en base al cumplimiento de una serie de condiciones descritas en las *guardas* de cada rama. Hay que señalar que las *guardas* en la expresión `if` no son tan restrictivas como las guardas originales, en estas sí podemos usar funciones de propias. Esto es posible porque internamente al compilar el módulo se transforma en una expresión `case`.

Podemos tener bloques de expresiones usando la siguiente sintaxis:

$$\texttt{begin} \qquad\qquad\qquad\qquad$$

$$\mathit{expresi\acute{o}n_1}\texttt{,}$$

$$\vdots$$

$$\mathit{expresi\acute{o}n_n}$$

$$\texttt{end} \qquad\qquad\qquad\qquad$$

El resultado de la expresión, igual que ocurre con el cuerpo de una cláusula, es el valor de evaluar la expresión final del bloque. Esto puede ser útil si uno quiere anidar una secuencia de expresiones en una posición de la sintaxis que sólo permite una única expresión (por ejemplo, las componentes de una tupla).

## Errores y excepciones

Erlang dispone de mecanismos para [gestionar errores](https://www.erlang.org/doc/reference_manual/errors.html) durante la ejecución, como ocurre con otros lenguajes modernos. Sin embargo, los creadores del lenguaje recomiendan la filosofía del *"let it crash"*, basada en dejar morir un proceso si falla y crear uno nuevo en su lugar. Dicho lo cual, en algunas ocasiones puede ser útil lanzar y gestionar excepciones.

La sintaxis para capturar excepciones es la siguiente:

$$\texttt{try}\ \mathit{expresiones}\ \textcolor{red}{[} \texttt{of} \qquad\qquad\qquad\qquad\qquad\qquad\qquad\qquad\qquad\qquad$$

$$\mathit{patr\acute{o}n_1}\ \textcolor{red}{[} \texttt{when}\ \mathit{guardas_1} \textcolor{red}{]}\ \texttt{->}\ \mathit{expresiones_1}\texttt{;} \qquad\qquad\qquad$$

$$\vdots$$

$$\mathit{patr\acute{o}n_n}\ \textcolor{red}{[} \texttt{when}\ \mathit{guardas_n} \textcolor{red}{]}\ \texttt{->}\ \mathit{expresiones_n} \textcolor{red}{]} \qquad\qquad\qquad$$

$$\textcolor{red}{[} \texttt{catch} \qquad\qquad\qquad\qquad\qquad\qquad\qquad\qquad\qquad\qquad\qquad\qquad\quad$$

$$\textcolor{red}{[} \mathit{clase_1} \texttt{:} \textcolor{red}{]} \mathit{patr\acute{o}n_1} \textcolor{red}{[} \texttt{:} \mathit{pila_1} \textcolor{red}{]}\ \textcolor{red}{[} \texttt{when}\ \mathit{guardas_1} \textcolor{red}{]}\ \texttt{->}\ \mathit{expresiones_1}\texttt{;}$$

$$\vdots$$

$$\textcolor{red}{[} \mathit{clase_m} \texttt{:} \textcolor{red}{]} \mathit{patr\acute{o}n_m} \textcolor{red}{[} \texttt{:} \mathit{pila_m} \textcolor{red}{]}\ \textcolor{red}{[} \texttt{when}\ \mathit{guardas_m} \textcolor{red}{]}\ \texttt{->}\ \mathit{expresiones_m} \textcolor{red}{]}$$

$$\textcolor{red}{[} \texttt{after} \qquad\qquad\qquad\qquad\qquad\qquad\qquad\qquad\qquad\qquad\qquad\qquad\quad$$

$$\mathit{expresiones_n} \textcolor{red}{]} \qquad\qquad\qquad\qquad\qquad\qquad\qquad\qquad\qquad\quad$$

$$\texttt{end} \qquad\qquad\qquad\qquad\qquad\qquad\qquad\qquad\qquad\qquad\qquad\qquad\qquad$$

Aunque son opcionales, las secciones `of`, `catch` y `after`, es necesario que exista al menos una sección `catch` o `after`. La sección `of` funciona como una expresión `case`. La sección `catch` trata de ajustar las excepciones a unos patrones y ejecutará una serie de expresiones siempre que encaje el valor y la guarda se cumpla. La sección `after` es un bloque de código que se ejecutará independientemente de si se ha producido una excepción o no en tiempo de ejecución. Si la excepción no es gestionada, por ninguna cláusula de la sección `catch`, se lanzará fuera de la expresión `try`.

Para ajustar una excepción, tenemos que hacer el encaje con tres elementos: la *clase*, un *patrón* y  la información de *pila*. En Erlang hay tres *clases* de excepciones:

- `error`: Producidas por las funciones `error/1` o  `error/2`.
- `exit`: Producidas por la función `exit/1`.
- `throw`: Producidas por la función `throw/1`.

Estas son funciones nativas del lenguaje del módulo [`erlang`](https://www.erlang.org/doc/man/erlang.html). El primer argumento en todas es el valor que representa cuál es el motivo de la excepción, este valor es el que tiene que encajar con el *patrón* en la cláusula del `catch`. El valor que tiene que encajar con *pila* en la cláusula es la información de pila para la depuración que acompaña a las excepciones de clase `error`.

La primera sección de la cláusula de captura de excepciones `Clase:Patrón:Pila` tiene partes opcionales. Si no es de clase `error`, podemos prescindir de `:Pila`. Si se omite `Clase:` se asume por defecto el valor `throw` y, por lo tanto, sólo podremos usar `Patrón` para el ajuste.

> También existe la función `erlang:raise/3` para lanzar excepciones, donde el primer parámetro es la clase, el segundo el motivo y el tercero la información de pila para la depuración.

Otro mecanismo para capturar excepciones es:

$$\texttt{catch}\ \mathit{expresi\acute{o}n}$$

Esta expresión es azúcar sintáctico de la anterior y lo que hace es capturar toda excepción y devolverla como un valor, en caso de producirse un fallo. Si no hay error alguno, devuelve el valor al que se evalúa la expresión. Usar `catch` sería lo mismo que usar el siguiente código:

```Erlang
try
    expresión
catch
    throw:Motivo ->
        Motivo;
    exit:Motivo ->
        {'EXIT', Motivo};
    error:Motivo:Pila ->
        {'EXIT', {Motivo, Pila}}
end
```

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

El [preprocesador](https://www.erlang.org/doc/reference_manual/macros.html) en Erlang nos permite realizar operaciones de sustitución durante la compilación de un módulo. Una de las operaciones es el **incluir ficheros** externos dentro del módulo actual, para insertar definiciones que necesitemos. Para ello usaremos:

$$\texttt{-include(}\mathit{fichero}\texttt{)}$$

Habitualmente los ficheros que se insertan son ficheros `.hrl`, que son ficheros de cabecera con macros y definiciones de registros de uso compartido entre varios módulos de nuestro proyecto. Existe una variante que es `-include_lib(fichero)`, que sirve para incluir cabeceras de la biblioteca estándar de Erlang. Por ejemplo:

```Erlang
-include_lib("kernel/include/file.hrl").
```

La otra operación importante del preprocesador son las **macros**, que realizan sustituciones dentro del módulo. Para definir macros la sintaxis es la siguiente:

$$\texttt{-define(} \mathit{ID} \textcolor{red}{[} \texttt{(} \mathit{Var_1} \textcolor{red}{[} \texttt{,} \dots \texttt{,} \mathit{Var_n} \textcolor{red}{]} \texttt{)} \textcolor{red}{]} \texttt{,} \mathit{expresi\acute{o}n} \texttt{)}$$

Lo primero es indicar el *nombre identificador* de la macro, que por convención se suele usar un nombre en mayúsculas. Después, dependiendo de si queremos parametrizar o no la macro, podemos poner una secuencia de *variables* como argumentos de entrada para la marco. Finalmente, tendremos una *expresión* que será usada como resultado final, después de sustituir las variables definidas como parámetros de entrada.

Para invocar una macro se usa la siguiente sintaxis:

$$\texttt{?} \mathit{ID} \textcolor{red}{[} \texttt{(} \mathit{expresi\acute{o}n_1} \textcolor{red}{[} \texttt{,} \dots \texttt{,} \mathit{expresi\acute{o}n_n} \textcolor{red}{]} \texttt{)} \textcolor{red}{]}$$

Por ejemplo:

```Erlang
-define(VERSION, "1.0").
-define(PRINTLN(V), io:format("~s := ~p~n", [??V, V])).

foo() ->
    Victim = ?VERSION,
    ?PRINTLN(Victim).
```

Si invocamos `foo` obtendremos como salida `Victim := "1.0"`. Esto es porque hemos asignado a la variable `Victim` el valor que representa la macro `?VERSION` y luego hemos invocado una macro con parámetros para mostrar una información por pantalla.

Nótese que dentro de la macro `PRINTLN` se utiliza `??V` con la variable de entrada `V` de la macro. Este mecanismo, de poner `??` delante de una variable de entrada, hace que se tome la expresión de entrada usada con la macro y se convierta a una cadena de texto. De ese modo, como la expresión de entrada de `PRINTLN` era la variable `Victim`, el resultado nos muestra eso mismo al aplicar la función `io:format/2`.

> Se puede sobrecargar un mismo identificador de macro, a excepción de las macros predefinidas del lenguaje, para poder tener diferentes macro parametrizadas con distinto número de argumentos de entrada.

Estas son algunas de las macros predefinidas por el lenguaje:

| Nombre | Descripción |
|:------:|:------------|
| `?MODULE` | Nombre del módulo actual. |
| `?MODULE_STRING` | Nombre del módulo actual como cadena. |
| `?FILE` | Nombre del fichero del módulo actual. |
| `?LINE` | Número de línea actual. |
| `?MACHINE` | Nombre de la máquina: `'BEAM'`. |
| `?FUNCTION_NAME` | Nombre de la función actual. |
| `?FUNCTION_ARITY` | Número de argumentos de la función actual. |
| `?OTP_RELEASE` | Versión actual de Erlang/OTP. |

También podemos controlar parte del flujo del preprocesador con:

| Comando | Descripción |
|:-------:|:------------|
| `-undef(Macro).` | Borra la definición de la macro para el módulo actual a partir de esa posición dentro del fichero. |
| `-ifdef(Macro).` | Permite acceder a las líneas siguientes si la macro indicada ha sido definida. |
| `-ifndef(Macro).` | Permite acceder a las líneas siguientes si la macro indicada no ha sido definida. |
| `-if(Condición).` | Permite acceder a las líneas siguientes si la condición indicada se cumple, dando como resultado `true`. |
| `-elif(Condición).` | Sólo se pueden usar después de un bloque `-if` o `-elif`. Permitirá acceder a las líneas siguientes si la condición se cumple y no se ha cumplido ninguna de las condiciones de los bloques anteriores. |
| `-else.` | Sólo se pueden usar después de un bloque `-ifdef` o `-ifndef`. Si no se ha cumplido ninguna de las condiciones previas, permite acceder a las líneas siguientes. |
| `-endif.` | Cierra el último bloque de control condicional del preprocesador. |

Estos comandos no se pueden utilizar en el interior de la definición de una función. Normalmente se utilizan para tener diferentes versiones de código, dependiendo de alguna condición o de la existencia de una definición de macro previa.

Existen dos comandos adicionales para interactuar con la compilación de un módulo. Con `-error(Expresión)` podemos emitir un mensaje de error y con `-warning(Expresión)` podemos emitir un mensaje de aviso. Ambos comandos mostrarán dichos mensajes en tiempo de compilación.

## Procesos y comunicación

La concurrencia es una de las características principales del lenguaje Erlang, para ello podemos crear [**procesos**](https://www.erlang.org/doc/reference_manual/processes.html) que sean ejecutados aparentemente a la vez que otros. La arquitectura de Erlang permite que estos procesos sean ligeros y se puedan crear y destruir rápido.

Dentro de cada instancia iniciada de la máquina virtual, hay una serie de **planificadores** (*scheduler*) que tienen una **cola de ejecución** (*run queue*), para organizar qué procesos gestiona y su orden de ejecución. Por cada núcleo del procesador se tiene un planificador (salvo que se desactive el *SMP*), que organiza la ejecución de los procesos a su cargo de forma [**concurrente**](https://es.wikipedia.org/wiki/Computaci%C3%B3n_concurrente) pero no [**paralela**](https://es.wikipedia.org/wiki/Computaci%C3%B3n_paralela).

También es posible hacer **aplicaciones distribuidas**, para ello hay que configurar una red de instancias de la máquina virtual como [**nodos**](https://www.erlang.org/doc/reference_manual/distributed.html). Cada nodo tendrá sus propios planificadores y además cualquier nodo puede encargar la ejecución de un proceso a otro nodo.

### Creación simple de procesos

Para crear procesos tenemos la función `spawn`:

$$\texttt{spawn(} \mathit{funci\acute{o}n} \texttt{)}$$

$$\texttt{spawn(} \mathit{m\acute{o}dulo} \texttt{,} \mathit{funci\acute{o}n} \texttt{,} \mathit{argumentos} \texttt{)}$$

Ambas funciones devuelven como resultado un **identificador de proceso** o *PID*, cuyo tipo es `pid()`. El PID obtenido nos permitirá poder comunicarnos con el proceso creado. El parámetro *función* de `spawn/1` tiene que ser un valor funcional, mientras que en `spawn/3` los dos primeros parámetros han de ser un átomo y a continuación una lista con los argumentos necesarios para invocar la función. Por ejemplo:

```
1> spawn(fun() -> erlang:system_time() end).
<0.81.0>
2> spawn(fun erlang:system_time/0).
<0.86.0>
3> spawn(erlang, system_time, []).
<0.88.0>
```

Vemos varias formas de crear un proceso con la función `erlang:system_time/0`, que también podría haber incluido usar una variable que esté ligada a un valor funcional. Los resultados que vemos en la consola de Erlang, al usar `spawn`, es el PID devuelto que representa al proceso creado.

### Comunicación entre procesos

La comunicación entre procesos se realiza mediante el paso de mensajes. Para **enviar** uno se usa la siguiente sintaxis:

$$\mathit{proceso}\ \texttt{!}\ \mathit{expresi\acute{o}n}$$

Mientras que el mensaje puede ser cualquier *expresión*, el *proceso* puede ser identificado mediante un PID (`pid()`), una referencia (`reference()`), un puerto de comunicación (`port()`), un nombre registrado (`atom()`), o una tupla `{Nombre, Nodo}`, en la que ambas componentes son nombres que identifican al proceso y al nodo donde se encuentra. El resultado, de la expresión de envío, es la propia *expresión* enviada.

> La expresión `!` es azúcar sintáctico de la función `erlang:send/2`, siendo esta la función primitiva que realmente se usa al ejecutar el programa.

Para **recibir** mensajes necesitamos la sintaxis siguiente:

$$\texttt{receive} \qquad\qquad\qquad\qquad\qquad\qquad\qquad\qquad\qquad\qquad$$

$$\mathit{patr\acute{o}n_1}\ \textcolor{red}{[} \texttt{when}\ \mathit{guardas_1} \textcolor{red}{]}\ \texttt{->}\ \mathit{expresiones_1}\texttt{;}$$

$$\vdots$$

$$\mathit{patr\acute{o}n_n}\ \textcolor{red}{[} \texttt{when}\ \mathit{guardas_n} \textcolor{red}{]}\ \texttt{->}\ \mathit{expresiones_n}$$

$$\textcolor{red}{[} \texttt{after}\ \mathit{tiempo}\ \texttt{->}\ \mathit{expresiones}\textcolor{red}{]} \qquad\qquad\quad$$

$$\texttt{end} \qquad\qquad\qquad\qquad\qquad\qquad\qquad\qquad\qquad\qquad\qquad$$

Esencialmente `receive` es como `case` aplicado a los valores de la cola de mensajes del proceso. Se comportan igual en cuanto al funcionamiento de las cláusulas, la diferencia es que `receive` dispone de una cláusula `after`, que requiere de un valor que representa el máximo tiempo de espera en milisegundos para recibir un mensaje. Si el tiempo de espera se ha agotado, se ejecuta el cuerpo de expresiones y se sale de la expresión `receive`. Los valores que admite son enteros entre `0` y `4294967295`. Si se omite la cláusula `after`, por defecto se asigna al *tiempo* el átomo `infinity`, indicando así que se ha de esperar indefinidamente hasta recibir un mensaje.

```Erlang
foo() ->
    PID = spawn(
        fun Loop() ->
            receive
                stop ->
                    stop;
                X ->
                    io:format("~p~n", [X]),
                    Loop()
            end
        end
    ),
    PID ! "Hello",
    PID ! {data, [a,b,c]},
    PID ! stop,
    PID ! "Bye".
```

Al ejecutar esta función veremos los mensajes `"Hello"`  y `{data, [a,b,c]}`, pero no veremos `"Bye"` porque el proceso ya finalizó.

### Poniendo nombres y alias

Erlang permite poner asociar a un PID un átomo como nombre. Para gestionarlo tenemos las siguientes funciones nativas:

| Función | Descripción |
|:-------:|:------------|
| `register(Nombre, PID)` | Asocia un átomo como nombre para un PID. |
| `registered()` | Da la lista de todos los nombres registrados. |
| `whereis(Nombre)` | Da el PID asociado a un nombre registrado o `undefined` si no está registrado. |

Además podemos crear un alias para un proceso con la función `alias()`, que devuelve una referencia asociada al proceso que invoca la función.  Con `unalias(Referencia)` se desactiva el alias registrado.

### Controlando procesos

Erlang permite dos modos de controlar la muerte prematura de procesos. El primero es con **enlaces**, que conecta dos procesos entre sí y cuando uno muere el otro también lo hace recibiendo una *excepción*. Podemos crear un proceso enlazado al actual con:

$$\texttt{spawn\char95link(} \mathit{funci\acute{o}n} \texttt{)}$$

$$\texttt{spawn\char95link(} \mathit{m\acute{o}dulo} \texttt{,} \mathit{funci\acute{o}n} \texttt{,} \mathit{argumentos} \texttt{)}$$

Si queremos enlazar un proceso ya creado al actual usaremos `link(PID)`, pudiendo revertir el enlace con `unlink(PID)`. También se puede cambiar el comportamiento por defecto, para capturar la excepción como si fuera un mensaje recibido con `process_flag(trap_exit, true)`, mensajes que tendrían la forma:

$$\texttt{\char123'EXIT', } \mathit{pid} \texttt{, } \mathit{motivo} \texttt{\char125}$$

El *pid* es el identificador de proceso que ha muerto y el *motivo* es la información relativa a la excepción, que dependiendo del tipo tendrá la siguiente forma:

| Tipo | Forma |
|:----:|:-----:|
| `exit(Valor)` | `Valor` |
| `error(Valor)` | `{Valor, Pila}` |
| `throw(Valor)` | `{{nocatch, Valor}, Pila}` |

> Al activar el *flag* `trap_exit`, cuando termine un proceso de forma normal se recibirá un mensaje con la forma `{'EXIT', PID, normal}`, siendo *PID* el identificador del proceso que acaba de terminar. Esto es importante, porque `exit(normal)` es considerada una terminación normal del proceso, por lo que usarlo no finalizará al proceso enlazado si no tiene el *flag* `trap_exit` activado.

El segundo modo es con **monitores**, que conecta dos procesos entre sí, donde uno es el monitor y el otro el monitorizado. Cuando el proceso monitorizado muere, el proceso monitor recibe un mensaje con la forma:

$$\texttt{\char123'DOWN', } \mathit{referencia} \texttt{, process, } \mathit{pid} \texttt{, } \mathit{motivo} \texttt{\char125}$$

Podemos crear un proceso monitorizado por el actual con:

$$\texttt{spawn\char95monitor(} \mathit{funci\acute{o}n} \texttt{)}$$

$$\texttt{spawn\char95monitor(} \mathit{m\acute{o}dulo} \texttt{,} \mathit{funci\acute{o}n} \texttt{,} \mathit{argumentos} \texttt{)}$$

El otro método, para monitorizar un proceso, es usando la función `monitor(process, PID)` para activarlo, que nos devuelve una referencia para identificar la relación, y `demonitor(Referencia)` para desactivarlo.

Es posible finalizar la ejecución de un proceso con la función `exit(PID, Motivo)`. Al usar el átomo `kill`, se asume que se está matando al proceso de forma abrupta, obteniendo `killed` como motivo de la excepción al capturarla con un mensaje. Se pueden usar otros valores para terminar un proceso, pero intentarlo con `normal` no funcionará. Si un proceso termina desde dentro con `exit(kill)`, el motivo que se capturará como mensaje es `kill` en lugar de `killed`.

### Diccionario del proceso

Todo proceso tiene asociado al mismo un diccionario interno. Lo podemos manejar con las siguientes funciones:

| Función | Descripción |
|:-------:|:------------|
| `put(Clave, Valor)` | Asigna un valor a una clave. |
| `get(Clave)` | Obtiene el valor de una clave. Si no existe se devuelve `undefined`. |
| `get()` | Devuelve el contenido como una lista `{Clave, Valor}`. |
| `get_keys(Valor)` | Obtiene una lista con las claves que tienen el valor indicado. |
| `erase(Clave)` | Borra una clave del diccionario. Si la clave existe devuelve el valor asociado y si no `undefined`. |
| `erase()` | Borra el contenido del diccionario, devolviéndolo como una lista `{Clave, Valor}`. |

### Procesos distribuidos

Para crear un nodo hace falta iniciar la máquina virtual de Erlang dándole un nombre de nodo. Las opciones para configurar un nodo con el comando con `erl` son:

| Opción | Descripción |
|:------:|:------------|
| `-sname Nombre` | Activa el nodo con un nombre corto. |
| `-name Nombre` | Activa el nodo con un nombre largo. |
| `-setcookie Cookie` | Configura la cookie del nodo. |
| `-setcookie Nodo Cookie` | Configura la cookie del nodo. |
| `-hidden` | El nodo será invisible al resto de la red de nodos. |
| `-connect_all false` | Sólo se permiten las conexiones explícitas. |

Un nombre de nodo suele ser un átomo con la forma `Nombre@Máquina`, donde *máquina* varía dependiendo de si se elige un nombre corto o largo. La red de nodos de Erlang no está preparada para temas de seguridad, pues el sistema fue diseñado en los años 80, cuando el acceso a las redes era más rudimentario. Para separar las redes de nodos se puede usar una *cookie*, que es un átomo, para que sólo puedan conectarse aquellos nodos que comparten la misma *cookie*.

Algunas funciones nativas para gestionar los nodos son:

| Función | Descripción |
|:-------:|:------------|
| `node()` | Da el nombre del nodo actual. |
| `node(Valor)` | Da el nombre del nodo que encaja con el *valor* indicado, que puede ser un PID, una referencia o un puerto. |
| `nodes()` | Da la lista de nodos actual. |
| `nodes(Valor)` | Da la lista de nodos actual en base a la opción indicada como *valor*. |
| `is_alive()` | Devuelve si el nodo actual puede conectarse al resto de nodos. |
| `monitor_node(Nodo, Bool)` | Monitoriza el estado de un nodo, recibiendo `{nodedown, Nodo}` como mensaje si se pierde la conexión. |
| `erlang:get_cookie()` | Da la *cookie* actual del nodo. |
| `erlang:get_cookie(Nodo)` | Da la *cookie* actual de un nodo. |
| `erlang:set_cookie(Cookie)` | Cambia la *cookie* actual del nodo. |
| `erlang:set_cookie(Nodo, Cookie)` | Cambia la *cookie* actual de un nodo. |
| `erlang:disconnect_node(Nodo)` | Desconecta un nodo de la red. |

Además podemos crear un proceso en un nodo que queramos con:

$$\texttt{spawn(} \mathit{nodo} \texttt{,} \mathit{funci\acute{o}n} \texttt{)}$$

$$\texttt{spawn(} \mathit{nodo} \texttt{,} \mathit{m\acute{o}dulo} \texttt{,} \mathit{funci\acute{o}n} \texttt{,} \mathit{argumentos} \texttt{)}$$

También se puede aplicar esto para el caso de `spawn_link` y `spawn_monitor`.

## Comportamientos

Lo *comportamientos* en Erlang es un tipo de interfaz que un módulo puede implementar. Esta interfaz tienen que tener una serie de funciones determinadas, para que el módulo, que define la interfaz de comportamiento, pueda operar con el módulo que la implementa. Estas funciones que ha de tener un módulo para implementar un *comportamiento* se llaman *callbacks*. Declaramos la implementación de un *comportamiento* con el siguiente atributo:

$$\texttt{-behaviour(} \mathit{nombre} \texttt{)}$$

El nombre es un átomo con el nombre del módulo que define el *comportamiento* en cuestión, ya sea uno definido por el usuario o uno de los siguientes de la biblioteca estándar de OTP: `gen_server`, `gen_statem`, `gen_event`, `supervisor`. Erlang también permite usar `behavior` como etiqueta del atributo.

Para crear una interfaz de comportamiento propia, dentro de nuestro módulo tendremos que indicar una lista de atributos que definan los *callbacks* a implementar, usando una sintaxis similar a la [especificación de tipos](https://www.erlang.org/doc/reference_manual/typespec.html):

$$\texttt{-callback}\ \mathit{nombre} \texttt{(} \textcolor{red}{[} \mathit{var_1}\ \textcolor{red}{[} \mathtt{::}\ \mathit{tipo_1} \textcolor{red}{]} \textcolor{red}{[} \texttt{,} \dots \texttt{,} \mathit{var_n}\ \textcolor{red}{[} \mathtt{::}\ \mathit{tipo_n} \textcolor{red}{]} \textcolor{red}{]} \textcolor{red}{]} \texttt{)}\ \texttt{->}\ \mathit{tipo}$$

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

Este comportamiento se utiliza para crear [servidores genéricos](https://www.erlang.org/doc/design_principles/gen_server_concepts.html) que ofrecen una serie de servicios mediante peticiones. Los eventos que se han de implementar son:

| Función | Parámetros | Resultados | Descripción |
|:-------:|:----------:|:----------:|:------------|
| `init` | `(Argumentos)` | `{ok,Estado}`<br/>`{ok,Estado,Extra}`<br/>`{stop,Motivo}`<br/>`ignore` | Inicialización del servidor. |
| `handle_call` | `(Petición, Origen, Estado)` | `{reply,Resultado,Estado}`<br/>`{reply,Resultado,Estado,Extra}`<br/>`{noreply,Estado}`<br/>`{noreply,Estado,Extra}`<br/>`{stop,Motivo,Estado}`<br/>`{stop,Motivo,Resultado,Estado}` | Peticiones con respuesta. |
| `handle_cast` | `(Petición, Estado)` | `{noreply,Estado}`<br/>`{noreply,Estado,Extra}`<br/>`{stop,Motivo,Estado}` | Peticiones sin respuesta. |
| `handle_info` | `(Mensaje, Estado)` | `{noreply,Estado}`<br/>`{noreply,Estado,Extra}`<br/>`{stop,Motivo,Estado}` | Mensajes recibidos que no son peticiones para el servidor. |
| `code_change` | `(Versión, Estado, Extra)` | `{ok,Estado}`<br/>`{error,Motivo}` | Cambio en caliente. |
| `terminate` | `(Motivo, Estado)` | - | Terminación del servidor. |

Sólo son obligatorias `init`, `handle_call` y `handle_cast`, el resto son opcionales. En el caso de `terminate` podemos devolver cualquier valor que necesitemos. En el caso de `handle_info`, uno de sus usos es gestionar los mensajes que recibe cuando está enlazado o monitoriza otro proceso. 

Las opciones *extra* en la respuesta pueden ser `Timeout` e `hibernate`. El primero es un número entero de tiempo de espera en milisegundos o el átomo `infinity`, que es el valor por defecto como opción. El segundo envía al servidor a un estado de hibernación, a la espera de recibir un mensaje para reactivarse.

> El cambio en caliente (*hot swapping*) se refiere a cuando se carga en la máquina virtual otra versión de un módulo ya cargado. Comportamientos como el `gen_server` reaccionan ante esta eventualidad invocando a `code_change`, donde la *versión* puede ser o bien un átomo que identifica la nueva versión, o tener la forma `{down, Versión}` cuando se trata de cargar una versión anterior. Con este evento podemos transformar la información de estado del servidor, para adaptarla a la siguiente versión cargada.

Las operaciones que gestionan el comportamiento están en el módulo [`gen_server`](https://www.erlang.org/doc/man/gen_server.html), entre las que tenemos las siguientes funciones:

| Función | Parámetros | Descripción | Evento |
|:-------:|:----------:|:------------|:------:|
| `start` | `(Módulo, Argumentos, Opciones)`<br/>`(Nombre, Módulo, Argumentos, Opciones)` | Crea un proceso que ejecuta el servidor. | `init` |
| `start_link` | `(Módulo, Argumentos, Opciones)`<br/>`(Nombre, Módulo, Argumentos, Opciones)` | Crea un proceso enlazado que ejecuta el servidor. | `init` |
| `start_monitor` | `(Módulo, Argumentos, Opciones)`<br/>`(Nombre, Módulo, Argumentos, Opciones)` | Crea un proceso monitorizado que ejecuta el servidor. | `init` |
| `stop` | `(Identificador)`<br/>`(Identificador, Motivo, Timeout)` | Detiene un servidor creado. | `terminate` |
| `call` | `(Identificador, Petición)`<br/>`(Identificador, Petición, Timeout)` | Envía una petición que espera una respuesta de forma síncrona. | `handle_call` |
| `cast` | `(Identificador, Petición)` | Envía una petición que no espera una respuesta de forma asíncrona. | `handle_cast` |

El parámetro *nombre*, cuando se inicia un servidor, sirve para registrar el proceso con un átomo, para ello se puede usar `{local,Nombre}` o `{global,Nombre}`, entre otras opciones. Al indicar `local` se registra el proceso sólo en el nodo actual, mientras que con `global` se registra en la red de nodos.

### El comportamiento: `gen_statem`

Este comportamiento se utiliza para crear [máquinas de estados](https://www.erlang.org/doc/design_principles/statem.html) y sustituye al módulo [`gen_fsm`](https://www.erlang.org/doc/man/gen_fsm.html). Los eventos que se han de implementar son:

| Función | Parámetros | Resultados | Descripción |
|:-------:|:----------:|:----------:|:------------|
| `init` | `(Argumentos)` | `{ok,Estado,Datos}`<br/>`{ok,Estado,Datos,Acciones}`<br/>`{stop,Motivo}`<br/>`ignore` | Inicialización de la máquina de estados. |
| `callback_mode` | `()` | `state_functions`<br/>`handle_event_function`<br/>`[state_functions,state_enter]`<br/>`[handle_event_function,state_enter]` | Configuración del modo de la máquina de estados. |
| `Estado` | `(enter, EstAnt, Datos)`<br/>`(Evento, Mensaje, Datos)` | `{next_state,Estado,Datos}`<br/>`{next_state,Estado,Datos,Acciones}`<br/>`{keep_state,Datos}`<br/>`{keep_state,Datos,Acciones}`<br/>`keep_state_and_data`<br/>`{keep_state_and_data,Acciones}`<br/>`{repeat_state,Datos}`<br/>`{repeat_state,Datos,Acciones}`<br/>`repeat_state_and_data`<br/>`{repeat_state_and_data,Acciones}`<br/>`stop`<br/>`{stop,Motivo}`<br/>`{stop,Motivo,Datos}`<br/>`{stop_and_reply,Motivo,Respuestas}`<br/>`{stop_and_reply,Motivo,Respuestas,Datos}` | Gestión del estado `Estado`. |
| `handle_event` | `(enter, EstAnt, Estado, Datos)`<br/>`(Evento, Mensaje, Estado, Datos)` | `{next_state,Estado,Datos}`<br/>`{next_state,Estado,Datos,Acciones}`<br/>`{keep_state,Datos}`<br/>`{keep_state,Datos,Acciones}`<br/>`keep_state_and_data`<br/>`{keep_state_and_data,Acciones}`<br/>`{repeat_state,Datos}`<br/>`{repeat_state,Datos,Acciones}`<br/>`repeat_state_and_data`<br/>`{repeat_state_and_data,Acciones}`<br/>`stop`<br/>`{stop,Motivo}`<br/>`{stop,Motivo,Datos}`<br/>`{stop_and_reply,Motivo,Respuestas}`<br/>`{stop_and_reply,Motivo,Respuestas,Datos}` | Gestión de los estados. |
| `code_change` | `()` | `{ok,Estado,Datos}`<br/>`Motivo` | Cambio en caliente. |
| `terminate` | `()` | - | Terminación de la máquina de estados. |

A diferencia del anterior comportamiento, el estado aquí se refiere al nombre del estado que se está ejecutando dentro de la máquina virtual, por lo que los datos es la información interna que equivale al estado de un servidor genérico.

Sólo son obligatorias `init` y `callback_mode`, más las funciones `Estado` o `handle_event`, dependiendo de la configuración. El resto de funciones son opcionales.

Una vez se ha inicializado la máquina, se invoca el evento para configurar el modo de funcionamiento con `callback_mode`, que tiene que devolver como mínimo una de las dos siguientes opciones:
+ `state_functions`: Los eventos se gestionan con las funciones `Estado/3`, requiriendo una función particular para cada estado de la máquina.
+ `handle_event_function`: Los eventos se gestionan con la función `handle_event/4`.

De añadir el valor `state_enter`, se indicará que además habrá un evento de entrada para cada estado de la máquina.

Al gestionar los eventos que reciben los estados tenemos dos situaciones:
+ Si el primer parámetro es `enter`, es que tenemos activada la configuración de entrada a los estados, por lo que `EstAnt` será el estado anterior del que viene la máquina, salvo en el primer estado que entrará, que al no haber habido uno previo el valor será el propio estado.
+ Si el primer parámetro es un *evento*, tendremos como eventos las siguientes posibilidades: `{call,Origen}`, `cast`, `info`, `timeout`, `{timeout,Nombre}`, `state_timeout` o `internal`. El parámetro *mensaje* es la información que acompaña al evento generado para el estado.

Luego, al devolver la respuesta al comportamiento, `Respuestas` puede ser la tupla `{reply,Origen,Respuesta}` o una lista de varias de ellas. Algo similar ocurre con `Acciones` que puede ser uno de los siguientes elementos, así como una lista de varios de ellos:

| Acciones | Descripción |
|:--------:|:------------|
| `hibernate`<br/>`{hibernate,Bool}` | Manda a hibernar al proceso. |
| `postpone`<br/>`{postpone,Bool}` | Pospone el evento actual. |
| `{state_timeout,Timeout,Mensaje}`<br/>`{state_timeout,Timeout,Mensaje,Opciones}`<br/>`{state_timeout,update,Mensaje}`<br/>`{state_timeout,cancel}` | Inicia, actualiza o cancela el *timeout* de un estado. |
| `{{timeout,Nombre},Timeout,Mensaje}`<br/>`{{timeout,Nombre},Timeout,Mensaje, Opciones}`<br/>`{{timeout,Nombre},update,Mensaje}`<br/>`{{timeout,Nombre},cancel}` | Inicia, actualiza o cancela el *timeout* genérico. |
| `{timeout,Timeout,Mensaje}`<br/>`{timeout,Timeout,Mensaje,Opciones}`<br/>`Timeout` | Inicia un evento de tipo *timeout*. |
| `{reply,Origen,Respuesta}` | Responde al proceso que activó el evento. |
| `{next_event,Evento,Mensaje}` | Genera un evento. |
| `{change_callback_module,Módulo}` | Cambia el módulo encargado de gestionar los estados. |
| `{push_callback_module,Módulo}` | Añade un módulo a la pila de módulos que gestionan los estados. |
| `pop_callback_module` | Saca un módulo a la pila de módulos que gestionan los estados. |

Las operaciones que gestionan el comportamiento están en el módulo [`gen_statem`](https://www.erlang.org/doc/man/gen_statem.html), entre las que tenemos las siguientes funciones:

| Función | Parámetros | Descripción | Evento |
|:-------:|:----------:|:------------|:------:|
| `start` | `(Módulo, Argumentos, Opciones)`<br/>`(Nombre, Módulo, Argumentos, Opciones)` | Crea un proceso que ejecuta la máquina. | `init` |
| `start_link` | `(Módulo, Argumentos, Opciones)`<br/>`(Nombre, Módulo, Argumentos, Opciones)` | Crea un proceso enlazado que ejecuta la máquina. | `init` |
| `start_monitor` | `(Módulo, Argumentos, Opciones)`<br/>`(Nombre, Módulo, Argumentos, Opciones)` | Crea un proceso monitorizado que ejecuta la máquina. | `init` |
| `stop` | `(Identificador)`<br/>`(Identificador, Motivo, Timeout)` | Detiene una máquina creada. | `terminate` |
| `call` | `(Identificador, Mensaje)`<br/>`(Identificador, Mensaje, Timeout)` | Envía un mensaje que espera una respuesta de forma síncrona. | `Estado`<br/>`handle_event` |
| `cast` | `(Identificador, Mensaje)` | Envía un mensaje que no espera una respuesta de forma asíncrona. | `Estado`<br/>`handle_event` |

El parámetro *nombre*, cuando se inicia una máquina de estados, sirve para registrar el proceso con un átomo, para ello se puede usar `{local,Nombre}` o `{global,Nombre}`, entre otras opciones. Al indicar `local` se registra el proceso sólo en el nodo actual, mientras que con `global` se registra en la red de nodos.

### El comportamiento: `gen_event`

Este comportamiento se utiliza para la [gestión de eventos](https://www.erlang.org/doc/design_principles/events.html) en un programa. Los eventos que se han de implementar son:

| Función | Parámetros | Resultados | Descripción |
|:-------:|:----------:|:----------:|:------------|
| `init` | `(Argumentos)` | `{ok,Estado}`<br/>`{ok,Estado,hibernate}`<br/>`{error,Motivo}` | Inicialización del gestor de eventos. |
| `handle_call` | `(Petición, Estado)` | `{ok,Resultado,Estado}`<br/>`{ok,Resultado,Estado,hibernate}`<br/>`{swap_handler,Result,Args1,Estado,Gest2,Args2}`<br/>`{remove_handler,Resultado}` | Peticiones con respuesta. |
| `handle_event` | `(Evento, Estado)` | `{ok,Estado}`<br/>`{ok,Estado,hibernate}`<br/>`{swap_handler,Args1,Estado,Gest2,Args2}`<br/>`remove_handler` | Peticiones sin respuesta. |
| `handle_info` | `(Mensaje, Estado)` | `{ok,Estado}`<br/>`{ok,Estado,hibernate}`<br/>`{swap_handler,Args1,Estado,Gest2,Args2}`<br/>`remove_handler` | Mensajes recibidos que no son peticiones. |
| `code_change` | `(Versión, Estado, Extra)` | `{ok,Estado}` | Cambio en caliente. |
| `terminate` | `(Motivo, Estado)` | - | Terminación del gestor. |

Sólo son obligatorias `init`, `handle_call` y `handle_event`, el resto son opcionales. Los valores de `Gest2` son indicar un módulo con un átomo o la tupla `{Módulo,Id}`.

Las operaciones que gestionan el comportamiento están en el módulo [`gen_event`](https://www.erlang.org/doc/man/gen_event.html), entre las que tenemos las siguientes funciones:

| Función | Parámetros | Descripción | Evento |
|:-------:|:----------:|:------------|:------:|
| `start` | `(Opciones)`<br/>`(Nombre, Opciones)` | Crea un proceso que procesa eventos. | - |
| `start_link` | `()`<br/>`(Opciones)`<br/>`(Nombre, Opciones)` | Crea un proceso enlazado que procesa eventos. | - |
| `start_monitor` | `()`<br/>`(Opciones)`<br/>`(Nombre, Opciones)` | Crea un proceso monitorizado que procesa eventos. | - |
| `add_handler` | `(Identificador, Gestor, Argumentos)` | Añade un gestor de eventos al proceso. | `init` |
| `add_sup_handler` | `(Identificador, Gestor, Argumentos)` | Añade un gestor de eventos al proceso, cuyas peticiones estarán supervisadas mediante enlace. | `init` |
| `swap_handler` | `(Identificador, {Gestor1, Args1}, {Gestor2, Args2})` | Intercambia un gestor de eventos en el proceso. | `terminate`<br/>`init` |
| `swap_sup_handler` | `(Identificador, {Gestor1, Args1}, {Gestor2, Args2})` | Intercambia un gestor de eventos en el proceso, por uno nuevo supervisado. | `terminate`<br/>`init` |
| `delete_handler` | `(Identificador, Gestor, Argumentos)` | Elimina un gestor de eventos del proceso. | `terminate` |
| `stop` | `(Identificador)`<br/>`(Identificador, Motivo, Timeout)` | Detiene un gestor creado. | `terminate` |
| `call` | `(Identificador, Gestor, Petición)`<br/>`(Identificador, Gestor, Petición, Timeout)` | Envía una petición síncrona que espera una respuesta. | `handle_call` |
| `notify` | `(Identificador, Evento)` | Envía un evento asíncrono. | `handle_event` |
| `sync_notify` | `(Identificador, Evento)` | Envía un evento síncrono. | `handle_event` |

El parámetro *nombre*, cuando se inicia un procesador de eventos, sirve para registrar el proceso con un átomo, para ello se puede usar `{local,Nombre}` o `{global,Nombre}`, entre otras opciones. Al indicar `local` se registra el proceso sólo en el nodo actual, mientras que con `global` se registra en la red de nodos. El *nombre* se puede usar como una opción con las funciones `start/1`. El parámetro *gestor* de nuevo es el nombre del módulo que gestiona los eventos o una tupla `{Módulo,Id}`.

El funcionamiento del gestor de eventos consiste en crear un proceso, que va a administrar los gestores encargados de procesar los eventos que se produzcan, esto se hace con las funciones `start`. Una vez creado, se irán añadiendo gestores con `add_handler`. Configurado ya los gestores, se procederá a notificar los eventos con `notify`. El uso de `sync_notify` se reserva para cuando necesitamos que nuestro programa espere a que se termine de procesar el evento notificado. Si necesitamos hacer una petición con respuesta, usaremos la función `call`, para obtener información interna del gestor, por ejemplo.

### El comportamiento: `supervisor`

Este comportamiento se utiliza para [supervisar](https://www.erlang.org/doc/design_principles/sup_princ.html) la ejecución de procesos. Los eventos que se han de implementar son:

| Función | Parámetros | Resultados | Descripción |
|:-------:|:----------:|:----------:|:------------|
| `init` | `(Argumentos)` | `{ok,{Config,[Hijo]}}`<br/>`ignore` | Inicialización del supervisor. |

La inicialización debe devolver una *configuración* del modo de funcionamiento del supervisor, así como una especificación de cada *hijo*, cuyas estructuras son:

| Variable | Valores |
|:--------:|:--------|
| `Config` | `{Estrategia, Intensidad, Periodo}` |
| `Config` | `#{strategy => Estrategia, intensity => Intensidad, period => Periodo, auto_shutdown => Apagado}` |
| `Hijo` | `{Identificador, Llamada, Reinicio, Apagado, Tipo, Módulos}` |
| `Hijo` | `#{id => Identificador, start => Llamada, restart => Reinicio, significant => Significativo, shutdown => Apagado, type => Tipo, modules => Módulos}` |

Los valores que para la *configuración* son:

| Variable | Defecto | Descripción |
|:--------:|:-------:|:--------|
| `Estrategia` | `one_for_one` | Estrategia de reinicio ante la terminación de los hijos:<br/>- `one_for_one` = Sólo el proceso terminado.<br/>- `one_for_all` = Todos los procesos.<br/>- `rest_for_one` = El proceso terminado y los siguientes.<br/>- `simple_one_for_one` = Sólo el proceso terminado. |
| `Intensidad` | `1` | Número de reinicios máximos durante el periodo configurado. Superar la cifra aquí configurada finalizará la ejecución del supervisor y la de sus hijos. El valor será un entero mayor o igual que cero. |
| `Periodo` | `5` | Tiempo en segundos máximos para el límite de reinicios máximos. El valor será un entero mayor que cero. |
| `Apagado` | `never` | Estrategia de finalización ante la finalización de los hijos significativos del supervisor:<br/>- `never` = Nunca.<br/>- `any_significant` = Al morir alguno.<br/>- `all_significant` = Al morir todos. |

Los valores que para la *especificación de un hijo* son:

| Variable | Defecto | Valores |
|:--------:|:-------:|:--------|
| `Identificador` | - | Nombre identificador del proceso. |
| `Llamada` | - | Función de llamada para crear el proceso:<br/>`{Módulo, Función, Argumentos}` |
| `Reinicio` | `permanent` | Estrategia ante la terminación del proceso:<br/>- `permanent` = Reiniciar siempre.<br/>- `transient` = Reiniciar cuando falla.<br/>- `temporary` = Reiniciar nunca. |
| `Significativo` | `false` | Indica si el proceso es un hijo significativo con un `true` o `false`. |
| `Apagado` | `infinity` | Estrategia para terminar el proceso:<br/>- `brutal_kill` = Muerte inmediata.<br/>- `Timeout` = Muerte después de un tiempo.<br/>- `infinity` = Esperar a que termine. |
| `Tipo` | `worker` | Tipo de proceso:<br/>- `worker` = Trabajador.<br/>- `supervisor` = Supervisor. |
| `Módulos` | `[Módulo]` | Si el proceso implementa un comportamiento como `supervisor`, `gen_server` o `gen_statem`, con `[Módulo]` se indica cuál es el módulo con los *callbacks*, mientras que el valor `dynamic` se usa para los procesos de `gen_event`. Si no se indica su valor, es tomado del *módulo* indicado en la *llamada*. |

Las operaciones que gestionan el comportamiento están en el módulo [`supervisor`](https://www.erlang.org/doc/man/supervisor.html), entre las que tenemos las siguientes funciones:

| Función | Parámetros | Descripción |
|:-------:|:----------:|:------------|
| `start_link` | `(Módulo, Argumentos)`<br/>`(Nombre, Módulo, Argumentos)` | Crea un proceso enlazado de un supervisor. |
| `start_child` | `(IdSup, Hijo)` | Añade una especificación de un hijo del supervisor e inicia su proceso. |
| `terminate_child` | `(IdSup, IdHijo)` | Termina un proceso hijo del supervisor. |
| `restart_child` | `(IdSup, IdHijo)` | Reinicia un proceso hijo del supervisor. |
| `delete_child` | `(IdSup, IdHijo)` | Borra una especificación de un hijo del supervisor. |
| `get_childspec` | `(IdSup, IdHijo)` | Devuelve la especificación de un hijo del supervisor. |
| `count_children` | `(IdSup)` | Devuelve el estado actual de los hijos del supervisor. |
| `which_children` | `(IdSup)` | Devuelve una lista de todos los hijos del supervisor. |
| `check_childspecs` | `(Hijos)`<br/>`(Hijos, Apagado)` | Comprueba si una lista de especificaciones es correcta. |

Con `start_link` se inicia el proceso de supervisión, que invoca la función `init`. Se pueden gestionar hijos de forma dinámica usando `start_child`, `terminate_child`, `restart_child` y `delete_child`.

El parámetro *nombre*, cuando se inicia un supervisor, sirve para registrar el proceso con un átomo, para ello se puede usar `{local,Nombre}` o `{global,Nombre}`, entre otras opciones. Al indicar `local` se registra el proceso sólo en el nodo actual, mientras que con `global` se registra en la red de nodos.

Cuando el supervisor está configurado como `simple_one_for_one`, sólo se podrá tener una única especificación de hijo para supervisar, porque todos los hijos que se supervisen van a ser instancias dinámicas de esta especificación. Por ello, el parámetro *hijo* de `start_child`, en lugar de ser una especificación, es una lista de argumentos que se concatena a la llamada indicada en la especificación única del supervisor.

### El comportamiento: `application`

Este comportamiento se utiliza para [controlar aplicaciones](https://www.erlang.org/doc/design_principles/applications.html) de Erlang. Los eventos que se han de implementar son:

| Función | Parámetros | Resultados | Descripción |
|:-------:|:----------:|:----------:|:------------|
| `start` | `(Tipo, Argumentos)` | `{ok,PID}`<br/>`{ok,PID,Estado}`<br/>`{error,Motivo}` | Inicio de la aplicación. |
| `prep_stop` | `(Estado)` | `Estado` | La aplicación va a finalizar pero todavía no lo ha hecho. |
| `stop` | `(Estado)` | - | Fin de la aplicación. |

El *tipo* en la inicialización habitualmente es `normal`, pero en aplicaciones distribuidas nos podemos encontrar con `{takeover,Nodo}` y `{failover,Nodo}`. Los *argumentos* corresponden con los valores definidos en la clave `mod` del fichero de configuración de la aplicación.

Las operaciones que gestionan el comportamiento están en el módulo [`application`](https://www.erlang.org/doc/man/application.html), entre las que tenemos las siguientes funciones:

| Función | Parámetros | Descripción |
|:-------:|:----------:|:------------|
| `start` | `(Aplicación)`<br/>`(Aplicación, Modo)` | Inicia una aplicación. |
| `stop` | `(Application)` | Detiene una aplicación. |
| `unload` | `(Aplicación)` | Quita una aplicación cargada. |
| `loaded_applications` | `()` | Devuelve las aplicaciones cargadas. |
| `which_applications` | `()`<br/>`(Timeout)` | Devuelve las aplicaciones que están ejecutándose. |
| `get_all_env` | `()`<br/>`(Aplicación)` | Devuelve los valores definidos en el entorno de la aplicación. |
| `get_env` | `(Clave)`<br/>`(Aplicación, Clave)`<br/>`(Aplicación, Clave, Defecto)` | Devuelve un valor definido en el entorno de la aplicación. |
| `set_env` | `(Configuración)`<br/>`(Configuración, Opciones)`<br/>`(Aplicación, Clave, Valor)`<br/>`(Aplicación, Clave, Valor, Opciones)` | Modifica un valor definido en el entorno de la aplicación. |
| `get_all_key` | `()`<br/>`(Aplicación)` | Devuelve las claves usadas en la configuración de la aplicación. |
| `get_key` | `(Clave)`<br/>`(Aplicación, Clave)` | Devuelve un valor de la configuración de la aplicación. |

Para poder aplicar este comportamiento es necesario que el proyecto siga la siguiente estructura durante el desarrollo:

```
my_app
├── doc
│   ├── internal
│   ├── examples
│   └── src
├── include
├── priv
├── src
│   └── my_app.app.src
└── test
```

El directorio `src` es obligatorio. Son opcionales `priv` e `include`. Son recomendados `doc` y `test`. Para la versión de lanzamiento esta es la estructura necesaria:

```
my_app-version
├── bin
├── doc
│   ├── examples
│   ├── html
│   ├── internal
│   ├── man [1-9]
│   └── pdf
├── ebin
│   └── my_app.app
├── include
├── priv
│   ├── bin
│   └── lib
└── src
```

El directorio `ebin` es obligatorio. Son opcionales `src`, `priv`, `include`, `bin` y `doc`. Son recomendados `priv/lib` y `priv/bin`. Pero sobre todo es importante tener el fichero [`.app`](https://www.erlang.org/doc/man/app.html) que configura la aplicación y que tiene la siguiente forma:

```
{application, Nombre,
  [{description,           Descripción},
   {id,                    Identificador},
   {vsn,                   Versión},
   {modules,               Módulos},
   {maxP,                  Procesos},
   {maxT,                  Tiempo},
   {registered,            Nombres},
   {included_applications, Aplicaciones},
   {optional_applications, Aplicaciones},
   {applications,          Aplicaciones},
   {env,                   Entorno},
   {mod,                   {Módulo, Argumentos}},
   {start_phases,          Fases},
   {runtime_dependencies,  Dependencias}]}.
```

Cuyos tipos y valores son:

| Elemento | Tipo | Defecto | Descripción |
|:--------:|:----:|:-------:|:------------|
| `Nombre` | `atom()` | - | Nombre de la aplicación. |
| `description` | `string()` | `""` | Identificador del producto. |
| `id` | `string()` | `""` | Identificador del producto. |
| `vsn` | `string()` | `""` | Versión de la aplicación. |
| `modules` | `[atom()]` | `[]` | Módulos que introduce la aplicación. |
| `maxP` | `int()` | `infinity` | Número máximo de procesos. |
| `maxT` | `int()` | `infinity` | Tiempo máximo de ejecución. |
| `registered` | `[atom()]` | `[]` | Nombres registrados por la aplicación. |
| `included_applications` | `[atom()]` | `[]` | Aplicaciones incluidas que serán cargadas pero no iniciadas automáticamente. |
| `optional_applications` | `[atom()]` | `[]` | Aplicaciones opcionales de las que depende la aplicación. |
| `applications` | `[atom()]` | `[]` | Aplicaciones de las que depende y que serán cargadas e iniciadas. |
| `env` | `[{atom(), term()}]` | `[]` | Entorno con información necesaria para la aplicación. |
| `mod` | `{atom(), list()}` | `[]` | Llamada inicial para arrancar la aplicación. |
| `start_phases` | `{atom(), list()}` | `undefined` | Fases para arrancar la aplicación. |
| `runtime_dependencies` | `[string()]` | `[]` | Dependencias que tiene la aplicación para ser ejecutada. |

Por ejemplo:

```Erlang
{application, my_app,
 [{description, "My App"},
  {vsn, "1.0"},
  {modules, [my_app, my_sup, my_worker]},
  {registered, [my_worker]},
  {applications, [kernel, stdlib]},
  {mod, {my_app, []}}
 ]}.
```

Tenemos una aplicación con tres módulos, un nombre que se va a registrar y unas dependencias. Con esto llamaríamos a la función `start` de `application`, indicando que la aplicación es `my_app` y eligiendo uno de los siguientes modos:
+ `permanent`: Si termina normal se cierran las otras aplicaciones y se apaga la máquina virtual. Si termina abruptamente ocurre lo mismo que al terminar normal.
+ `transient`: Si termina normal no ocurre nada. Si termina abruptamente se informa del fallo, se cierran las otras aplicaciones y se apagar la máquina virtual.
+ `temporary`: Este es el valor por defecto. Si termina normal no ocurre nada. Si termina abruptamente se informa del fallo, y la aplicación termina sin reiniciarse.

Cuando queramos acceder a función del entorno definido en la configuración se puede usar la función `get_env`, que salvo que le hayamos indicado un valor de retorno por *defecto*, si no se encuentra la clave nos devolverá `undefined`, en caso contrario nos devuelve `{ok,Valor}`. Y para apagar la aplicación se utiliza la función `stop`.

## La biblioteca estándar

### Aplicaciones de la plataforma

Estas son las [aplicaciones](https://www.erlang.org/doc/applications.html) que conforma la plataforma Erlang/OTP:

| Categoría | Aplicación | Descripción |
|:---------:|:----------:|:------------|
| Básico | [`compiler`](https://www.erlang.org/doc/apps/compiler/index.html) | Compilador de Erlang. |
| Básico | [`erts`](https://www.erlang.org/doc/apps/erts/index.html) | Entorno de ejecución de Erlang. |
| Básico | [`kernel`](https://www.erlang.org/doc/apps/kernel/index.html) | Núcleo de ejecución de Erlang. |
| Básico | [`sasl`](https://www.erlang.org/doc/apps/sasl/index.html) | Sistema para soporte de bibliotecas. |
| Básico | [`stdlib`](https://www.erlang.org/doc/apps/stdlib/index.html) | Bibliotecas básicas de Erlang. |
| Datos | [`mnesia`](https://www.erlang.org/doc/apps/mnesia/index.html) | Base de datos distribuida [NoSQL](https://es.wikipedia.org/wiki/NoSQL). |
| Datos | [`odbc`](https://www.erlang.org/doc/apps/odbc/index.html) | Interfaz para bases de datos [SQL](https://es.wikipedia.org/wiki/SQL). |
| Interfaces | [`asn1`](https://www.erlang.org/doc/apps/asn1/index.html) | Soporte para [ASN.1](https://es.wikipedia.org/wiki/ASN.1) (notación de sintaxis abstracta). |
| Interfaces | [`crypto`](https://www.erlang.org/doc/apps/crypto/index.html) | Soporte para criptografía. |
| Interfaces | [`diameter`](https://www.erlang.org/doc/apps/diameter/index.html) | Soporte para el protocolo [Diameter](https://es.wikipedia.org/wiki/Diameter_%28protocolo%29). |
| Interfaces | [`eldap`](https://www.erlang.org/doc/apps/eldap/index.html) | Soporte para el protocolo [LDAP](https://es.wikipedia.org/wiki/Protocolo_ligero_de_acceso_a_directorios). |
| Interfaces | [`erl_interface`](https://www.erlang.org/doc/apps/erl_interface/index.html) | Interfaz de bajo nivel con [C](https://es.wikipedia.org/wiki/C_%28lenguaje_de_programaci%C3%B3n%29). |
| Interfaces | [`ftp`](https://www.erlang.org/doc/apps/ftp/index.html) | Soporte para el protocolo [FTP](https://es.wikipedia.org/wiki/Protocolo_de_transferencia_de_archivos). |
| Interfaces | [`inets`](https://www.erlang.org/doc/apps/inets/index.html) | Soporte para servidores [HTTP](https://es.wikipedia.org/wiki/Protocolo_de_transferencia_de_hipertexto). |
| Interfaces | [`jinterface`](https://www.erlang.org/doc/apps/jinterface/index.html) | Interfaz de bajo nivel con [Java](https://es.wikipedia.org/wiki/Java_%28lenguaje_de_programaci%C3%B3n%29). |
| Interfaces | [`megaco`](https://www.erlang.org/doc/apps/megaco/index.html) | Soporte para el protocolo [Megaco/H.248](https://es.wikipedia.org/wiki/Megaco). |
| Interfaces | [`public_key`](https://www.erlang.org/doc/apps/public_key/index.html) | Soporte para [claves públicas](https://es.wikipedia.org/wiki/Criptograf%C3%ADa_asim%C3%A9trica). |
| Interfaces | [`ssh`](https://www.erlang.org/doc/apps/ssh/index.html) | Soporte para el protocolo [SSH](https://es.wikipedia.org/wiki/Secure_Shell). |
| Interfaces | [`ssl`](https://www.erlang.org/doc/apps/ssl/index.html) | Soporte para el protocolo [SSL](https://es.wikipedia.org/wiki/Seguridad_de_la_capa_de_transporte). |
| Interfaces | [`tftp`](https://www.erlang.org/doc/apps/tftp/index.html) | Soporte para el protocolo [TFTP](https://es.wikipedia.org/wiki/TFTP). |
| Interfaces | [`wx`](https://www.erlang.org/doc/apps/wx/index.html) | Soporte para [wxWidgets](https://es.wikipedia.org/wiki/WxWidgets). |
| Interfaces | [`xmerl`](https://www.erlang.org/doc/apps/xmerl/index.html) | Soporte para el formato [XML 1.0](https://es.wikipedia.org/wiki/Extensible_Markup_Language). |
| Herramientas | [`debugger`](https://www.erlang.org/doc/apps/debugger/index.html) | Depurador de Erlang. |
| Herramientas | [`dialyzer`](https://www.erlang.org/doc/apps/dialyzer/index.html) | Analizador de tipos. |
| Herramientas | [`et`](https://www.erlang.org/doc/apps/et/index.html) | Trazador de eventos. |
| Herramientas | [`observer`](https://www.erlang.org/doc/apps/observer/index.html) | Inspector de sistemas distribuidos. |
| Herramientas | [`parsetools`](https://www.erlang.org/doc/apps/parsetools/index.html) | Parser y análisis léxico de código. |
| Herramientas | [`reltool`](https://www.erlang.org/doc/apps/reltool/index.html) | Gestor de aplicaciones para su lanzamiento final. |
| Herramientas | [`runtime_tools`](https://www.erlang.org/doc/apps/runtime_tools/index.html) | Herramientas para la ejecución. |
| Herramientas | [`syntax_tools`](https://www.erlang.org/doc/apps/syntax_tools/index.html) | Soporte para [árboles sintácticos abstractos](https://es.wikipedia.org/wiki/%C3%81rbol_de_sintaxis_abstracta) de Erlang. |
| Herramientas | [`tools`](https://www.erlang.org/doc/apps/tools/index.html) | Herramientas auxiliares del sistema. |
| Tests | [`common_test`](https://www.erlang.org/doc/apps/common_test/index.html) | Testing automático para aplicaciones. |
| Tests | [`eunit`](https://www.erlang.org/doc/apps/eunit/index.html) | Test unitarios para módulos. |
| Documentación | [`edoc`](https://www.erlang.org/doc/apps/edoc/index.html) | Genera documentación tomando las etiquetas en los comentarios de un módulo. |
| Documentación | [`erl_docgen`](https://www.erlang.org/doc/apps/erl_docgen/index.html) | Genera documentación para la OTP. |
| Mantenimiento | [`os_mon`](https://www.erlang.org/doc/apps/os_mon/index.html) | Monitor de recursos del sistema operativo. |
| Mantenimiento | [`snmp`](https://www.erlang.org/doc/apps/snmp/index.html) | Gestiona el protocolo SNMP. |

### Módulos de `erts`

Los módulos principales son:

| Módulo | Descripción |
|:------:|:------------|
| `atomics` | Soporte para operaciones atómicas. |
| `counters` | Soporte para operaciones de conteo. |
| `erlang` | Funciones nativas del lenguaje. |
| `erl_driver` | Interfaz para drivers de Erlang. |
| `erl_nif` | Interfaz para funciones nativas de usuario. |
| `erl_prim_loader` | Cargador de bajo nivel de Erlang. |
| `erl_tracer` | Comportamiento de trazado en Erlang. |
| `init` | Gestor del arranque del sistema Erlang. |
| `persistent_term` | Persistencia de datos. |
| `zlib` | Interfaz para ficheros `.zip`. |

### Módulos de `kernel`

Los módulos generales del sistema son:

| Módulo | Descripción |
|:------:|:------------|
| `application` | Soporte para aplicaciones OTP genéricas. |
| `code` | Servidor de código Erlang. |
| `erl_boot_server` | Servidor de arranque para otras máquinas Erlang. |
| `erl_ddll` | Carga y enlace dinámica de drivers en Erlang. |
| `erl_epmd` | Interfaz para el [`epmd`](https://www.erlang.org/doc/man/epmd.html). |
| `error_handler` | Gestor por defecto de errores del sistema. |
| `file` | Operaciones con ficheros. |
| `global` | Sistema para registrar nombres globales. |
| `global_group` | Grupos de nodos para los grupos de registro de nombres globales. |
| `heart` | Sistema para monitorizar el proceso `heart`, que controla qué nodos Erlang de la red siguen vivos. |
| `os` | Operaciones del sistema operativo. |
| `pg` | Grupos de procesos con nombre distribuidos. |
| `seq_trace` | Trazado secuencial de transferencias de información. |

Los módulos de comunicaciones son:

| Módulo | Descripción |
|:------:|:------------|
| `erpc` | Llamadas a rutinas remotas ([RPC](https://es.wikipedia.org/wiki/Llamada_a_procedimiento_remoto)) mejoradas. |
| `gen_sctp` | Comunicación con *sockets* usando [SCTP](https://es.wikipedia.org/wiki/Stream_Control_Transmission_Protocol). |
| `gen_tcp` | Comunicación con *sockets* usando [TCP](https://es.wikipedia.org/wiki/Protocolo_de_control_de_transmisi%C3%B3n). |
| `gen_udp` | Comunicación con *sockets* usando [UDP](https://es.wikipedia.org/wiki/Protocolo_de_datagramas_de_usuario). |
| `inet` | Soporte para el protocolo [TCP/IP](https://es.wikipedia.org/wiki/Protocolo_de_control_de_transmisi%C3%B3n). |
| `inet_res` | Cliente [DNS](https://es.wikipedia.org/wiki/Sistema_de_nombres_de_dominio) básico. |
| `net` | Soporte para la interfaz de red. |
| `net_adm` | Rutinas para administrar la red de nodos Erlang. |
| `net_kernel` | Núcleo de la red de nodos Erlang. |
| `rpc` | Llamadas a rutinas remotas ([RPC](https://es.wikipedia.org/wiki/Llamada_a_procedimiento_remoto)). |
| `socket` | Interfaz para manejar *sockets*. |

Los módulos de registro de eventos son:

| Módulo | Descripción |
|:------:|:------------|
| `disk_log` | Sistema de registro de eventos (*logs*) con ficheros. |
| `logger` | Interfaz para el registro de eventos (*logs*). |
| `logger_filters` | Filtrado del registro de eventos (*logs*). |
| `logger_formatter` | Formato para el registro de eventos (*logs*). |
| `logger_std_h` | Gestor estándar del registro de eventos (*logs*). |
| `logger_disk_log_h` | Registro de eventos (*logs*) con ficheros. |
| `wrap_log_reader` | Servicio para leer registros de disco de tipo *wrap* formateados internamente. |

### Módulos de `stdlib`

Los módulos generales son:

| Módulo | Descripción |
|:------:|:------------|
| `base64` | Codificación y decodificación con [Base64](https://es.wikipedia.org/wiki/Base64) ([RFC 2045](https://www.ietf.org/rfc/rfc2045.txt)). |
| `c` | Interfaz de la consola Erlang. |
| `calendar` | Manejo de fechas y horas. |
| `erl_error` | Utilidades para informar de errores. |
| `erl_tar` | Manejo de ficheros `.tar`. |
| `file_sorter` | Ordena el contenido de ficheros. |
| `filelib` | Utilidades para manejar ficheros. |
| `filename` | Manipulación de nombres de ficheros. |
| `gen_event` | Gestor de eventos genérico. |
| `gen_server` | Servidor genérico. |
| `gen_statem` | Máquina de estados genérica. |
| `io` | Interfaz estándar de entrada y salida. |
| `io_lib` | Funciones de entrada y salida. |
| `log_mf_h` | Gestor de eventos que registra eventos en ficheros. |
| `math` | Funciones matemáticas. |
| `peer` | Inicia y controla nodos enlazados. |
| `pool` | Gestor de distribución de carga con procesos. |
| `proc_lib` | Funciones para la creación de procesos. |
| `rand` | Generación de números pseudo-aleatorios. |
| `re` | Manejo de expresiones regulares para Erlang. |
| `shell` | Consola de comandos de Erlang. |
| `shell_docs` | Visualización de la documentación en la consola de Erlang. |
| `slave` | Inicia y controla nodos esclavos. |
| `supervisor` | Supervisor genérico de procesos. |
| `supervisor_bridge` | Puente supervisor genérico de procesos. |
| `sys` | Interfaz para mensajes de sistema. |
| `timer` | Manejo de temporizadores. |
| `unicode` | Conversión de caracteres Unicode. |
| `uri_string` | Procesado de [URIs](https://es.wikipedia.org/wiki/Identificador_de_recursos_uniforme). |
| `win32reg` | Manejo del registro de Windows. |
| `zip` | Manejo de ficheros `.zip`. |

Los módulos de estructuras de datos son:

| Módulo | Descripción |
|:------:|:------------|
| `array` | Manejo de arrays. |
| `binary` | Manejo de binarios. |
| `dict` | Manejo de diccionarios clave-valor. Las claves se comparan con `=:=`. |
| `digraph` | Manejo de grafos dirigidos. |
| `digraph_utils` | Algoritmos para grafos dirigidos. |
| `gb_sets` | Manejo de conjuntos implementados con árboles balanceados. Los elementos se comparan con `==`. |
| `gb_trees` | Manejo de árboles balanceados. Los elementos se comparan con `==`. |
| `lists` | Manejo de listas. |
| `maps` | Manejo de mapas clave-valor. |
| `orddict` | Manejo de diccionarios clave-valor implementados con listas ordenadas. Las claves se comparan con `==`. |
| `ordsets` | Manejo de conjuntos implementados con listas ordenadas. Los elementos se comparan con `==`. |
| `proplists` | Manejo de listas de propiedades clave-valor. Las claves se comparan con `=:=`. |
| `queue` | Manejo de colas. |
| `sets` | Manejo de conjuntos. Los elementos se comparan con `=:=`. |
| `sofs` | Manejo de conjuntos de conjuntos. Los elementos se comparan con `==`. |
| `string` | Manejo de cadenas de texto. |

Los módulos de bases de datos son:

| Módulo | Descripción |
|:------:|:------------|
| `dets` | Base de datos [NoSQL](https://es.wikipedia.org/wiki/NoSQL) en ficheros. |
| `ets` | Base de datos [NoSQL](https://es.wikipedia.org/wiki/NoSQL) en memoria. |
| `ms_transform` | Transformación de sintaxis para crear especificaciones de ajuste de patrones. |
| `qlc` | Interfaz de consultas a Mnesia, ETS, DETS y demás. |

Los módulos de gestión del lenguaje son:

| Módulo | Descripción |
|:------:|:------------|
| `beam_lib` | Interfaz del formato de ficheros BEAM. |
| `epp` | Preprocesador de código Erlang. |
| `erl_anno` | Tipo de datos abstracto para las anotaciones del compilador de Erlang. |
| `erl_eval` | Meta-interprete de Erlang. |
| `erl_expand_records` | Transforma formas abstractas de código Erlang. |
| `erl_features` | Manejo de características del lenguaje. |
| `erl_id_trans` | Transformación de parseado identidad. |
| `erl_internal` | Definiciones internas de Erlang. |
| `erl_lint` | *Linter* para el lenguaje Erlang. |
| `erl_parse` | Parser del lenguaje Erlang. |
| `erl_pp` | Representación legible de Erlang. |
| `erl_scan` | Generador de tokens del lenguaje Erlang. |

### Funciones nativas del lenguaje

El módulo [`erlang`](https://www.erlang.org/doc/man/erlang.html) contiene la mayor parte de las funciones nativas que hay en el lenguaje. Algunas de estas funciones no requieren indicar su módulo para invocarlas. Algunas de las funciones generales son:

| Función | Descripción |
|:-------:|:------------|
| `error` | Lanza un error de ejecución. |
| `garbage_collect` | Invoca al recolector de basura. |
| `halt` | Para el entorno de ejecución de Erlang. |
| `make_ref` | Crea una referencia única. |
| `memory` | Da información sobre la memoria usada por Erlang. |
| `nif_error` | Lanza un error de ejecución. |
| `raise` | Lanza una excepción en ejecución. |
| `statistics` | Devuelve estadísticas sobre el sistema. |
| `system_flag` | Modifica el comportamiento del sistema. |
| `system_info` | Devuelve información sobre el sistema. |
| `system_monitor` | Obtiene/modifica la configuración para monitorizar el sistema. |
| `system_profile` | Obtiene/modifica la configuración del sistema. |
| `throw` | Lanza una excepción en ejecución. |

Estas son las funciones para comprobar tipos:

| Función | Descripción |
|:-------:|:------------|
| `is_atom` | Indica si es de tipo átomo. |
| `is_binary` | Indica si es de tipo binario. |
| `is_bitstring` | Indica si es de tipo binario. |
| `is_boolean` | Indica si es de tipo booleano. |
| `is_float` | Indica si es de tipo coma flotante. |
| `is_function` | Indica si es de tipo función. |
| `is_integer` | Indica si es de tipo entero. |
| `is_list` | Indica si es de tipo lista. |
| `is_map` | Indica si es de tipo mapa. |
| `is_number` | Indica si es de tipo número. |
| `is_pid` | Indica si es de tipo PID. |
| `is_port` | Indica si es de tipo puerto. |
| `is_record` | Indica si es de tipo registro. |
| `is_reference` | Indica si es de tipo referencia. |
| `is_tuple` | Indica si es de tipo tupla. |

Estas son las funciones para convertir entre tipos:

| Función | Descripción |
|:-------:|:------------|
| `atom_to_binary` | De átomo a texto en binario. |
| `atom_to_list` | De átomo a texto en lista. |
| `binary_to_atom` | De texto en binario a átomo. |
| `binary_to_existing_atom` | De texto en binario a átomo. |
| `binary_to_float` | De texto en binario a coma flotante. |
| `binary_to_integer` | De texto en binario a entero. |
| `binary_to_list` | De binario a lista. |
| `binary_to_term` | De binario a valor literal. |
| `bitstring_to_list` | De binario a lista. |
| `float_to_binary` | De coma flotante a texto en binario. |
| `float_to_list` | De coma flotante a texto en lista. |
| `fun_to_list` | De valor funcional a texto en lista. |
| `integer_to_binary` | De entero a texto en binario. |
| `integer_to_list` | De entero a texto en lista. |
| `iolist_to_binary` | De lista de entrada a binario. |
| `iolist_to_iovec` | De lista de entrada a vector de entrada. |
| `list_to_atom` | De texto en lista a átomo. |
| `list_to_binary` | De lista a binario. |
| `list_to_bitstring` | De lista a binario. |
| `list_to_existing_atom` | De texto en lista a átomo. |
| `list_to_float` | De texto en lista a coma flotante. |
| `list_to_integer` | De texto en lista a entero. |
| `list_to_pid` | De texto en lista a PID. |
| `list_to_port` | De texto en lista a puerto. |
| `list_to_ref` | De texto en lista a referencia. |
| `list_to_tuple` | De lista a tupla. |
| `pid_to_list` | De PID a texto en lista. |
| `port_to_list` | De puerto a texto en lista. |
| `ref_to_list` | De referencia a texto en lista. |
| `term_to_binary` | De valor literal a binario. |
| `term_to_iovec` | De valor literal a vector de entrada. |
| `tuple_to_list` | De tupla a lista. |

Estas son las funciones para temas numéricos:

| Función | Descripción |
|:-------:|:------------|
| `abs` | Devuelve el valor absoluto de un número. |
| `adler32` | Calcula un *checksum* [*Adler-32*](https://en.wikipedia.org/wiki/Adler-32). |
| `adler32_combine` | Calcula un *checksum* [*Adler-32*](https://en.wikipedia.org/wiki/Adler-32). |
| `ceil` | Devuelve el menor entero igual o mayor que el número actual. |
| `crc32` | Calcula un *checksum* [*CRC-32*](https://es.wikipedia.org/wiki/Verificaci%C3%B3n_de_redundancia_c%C3%ADclica). |
| `crc32_combine` | Calcula un *checksum* [*CRC-32*](https://es.wikipedia.org/wiki/Verificaci%C3%B3n_de_redundancia_c%C3%ADclica). |
| `external_size` | Calcula el tamaño en bytes de un valor literal. |
| `float` | Transforma un número en coma flotante. |
| `floor` | Devuelve el mayor entero igual o menor que el número actual. |
| `max` | Devuelve el valor mayor. |
| `md5` | Calcula un [MD5](https://es.wikipedia.org/wiki/MD5). |
| `md5_final` | Finaliza el cálculo de un [MD5](https://es.wikipedia.org/wiki/MD5). |
| `md5_init` | Inicia el cálculo de un [MD5](https://es.wikipedia.org/wiki/MD5). |
| `md5_update` | Actualiza el cálculo de un [MD5](https://es.wikipedia.org/wiki/MD5). |
| `min` | Devuelve el valor menor. |
| `phash2` | Devuelve un *hash* para un valor literal. |
| `round` | Redondea un número. |
| `trunc` | Trunca un número quitando los decimales. |
| `unique_integer` | Genera un número entero único. |

Estas son las funciones para manejar fechas y horas:

| Función | Descripción |
|:-------:|:------------|
| `convert_time_unit` | Transforma marcas de tiempo. |
| `date` | Devuelve la fecha actual. |
| `localtime` | Devuelve la fecha y hora actual. |
| `localtime_to_universaltime` | Transforma a horario UTC. |
| `monotonic_time` | Devuelve el tiempo actual de ejecución. |
| `system_time` | Devuelve el tiempo actual del sistema. |
| `time` | Devuelve la hora actual. |
| `time_offset` | Devuelve la diferencia entre el tiempo monótono y el del sistema. |
| `timestamp` | Devuelve una marca de tiempo. |
| `universaltime` | Devuelve la fecha y hora actual en UTC. |
| `universaltime_to_localtime` | Transforma a horario local. |

Estas son las funciones para manejar temporizadores:

| Función | Descripción |
|:-------:|:------------|
| `cancel_timer` | Cancela un temporizador. |
| `read_timer` | Consulta un temporizador. |
| `start_timer` | Inicia un temporizador. |

Estas son las funciones para manejar listas:

| Función | Descripción |
|:-------:|:------------|
| `hd` | Devuelve la cabeza de la lista. |
| `length` | Devuelve el número de elementos de una lista. |
| `tl` | Devuelve la cola de la lista. |

Estas son las funciones para manejar tuplas:

| Función | Descripción |
|:-------:|:------------|
| `append_element` | Añade una componente adicional a una tupla. |
| `delete_element` | Borra una componente en una tupla. |
| `element` | Devuelve una componente en una tupla. |
| `insert_element` | Inserta una componente adicional a una tupla. |
| `make_tuple` | Crea una tupla con todas las componentes iguales. |
| `setelement` | Modifica una componente en una tupla. |
| `tuple_size` | Devuelve el número de componente de una tupla. |

Estas son las funciones para manejar mapas:

| Función | Descripción |
|:-------:|:------------|
| `is_map_key` | Indica si la clave está en el mapa. |
| `map_get` | Obtiene el valor para una clave en el mapa. |
| `map_size` | Devuelve el número de elementos de un mapa. |

Estas son las funciones para manejar funciones o módulos:

| Función | Descripción |
|:-------:|:------------|
| `apply` | Invoca una función con una serie de argumentos. |
| `check_old_code` | Comprueba si se está ejecutando código viejo. |
| `check_process_code` | Comprueba si se está ejecutando código viejo. |
| `function_exported` | Comprueba si existe una función. |
| `fun_info` | Devuelve información relativa a una función. |
| `is_builtin` | Indica si es de una función nativa. |
| `load_nif` | Carga código nativo para un módulo. |
| `loaded` | Devuelve la lista de todos los módulos cargados. |
| `pre_loaded` | Devuelve la lista de todos los módulos pre-cargados al iniciar el entorno de ejecución de Erlang. |

Estas son las funciones para manejar otras estructuras de datos:

| Función | Descripción |
|:-------:|:------------|
| `binary_part` | Devuelve un fragmento de un binario. |
| `bit_size` | Devuelve el tamaño en bits de un binario. |
| `byte_size` | Devuelve el tamaño en bytes de un binario. |
| `decode_packet` | Decodifica un paquete binario. |
| `iolist_size` | Devuelve el tamaño en bytes de una lista de entrada. |
| `match_spec_test` | Comprueba una especificación de encaje. |
| `size` | Devuelve el número de elementos en un binario o tupla. |
| `split_binary` | Parte un binario en dos fragmentos. |

Estas son las funciones para manejar procesos:

| Función | Descripción |
|:-------:|:------------|
| `alias` | Devuelve una referencia como alias del proceso actual. |
| `demonitor` | Elimina una relación de monitor. |
| `erase` | Borra elementos del diccionario del proceso. |
| `exit` | Termina la ejecución de un proceso. |
| `get` | Consulta elementos del diccionario del proceso. |
| `get_keys` | Devuelve las claves del diccionario del proceso. |
| `group_leader` | Obtiene/modifica el líder de grupo. |
| `hibernate` | Hiberna un proceso en ejecución. |
| `is_process_alive` | Indica si el proceso está vivo. |
| `link` | Enlaza el proceso actual con otro. |
| `monitor` | Establece una relación de monitor. |
| `process_display` | Muestra información sobre un proceso. |
| `process_flag` | Modifica el comportamiento de un proceso. |
| `process_info` | Devuelve información sobre un proceso. |
| `processes` | Devuelve los procesos actuales del nodo. |
| `put` | Modifica elementos del diccionario del proceso. |
| `self` | Devuelve el PID del proceso actual. |
| `send` | Envía un mensaje a un proceso o puerto. |
| `send_after` | Envía un mensaje a un proceso o puerto. |
| `send_nosuspend` | Envía un mensaje a un proceso o puerto. |
| `spawn` | Crea un proceso. |
| `spawn_link` | Crea un proceso enlazado. |
| `spawn_monitor` | Crea un proceso monitorizado. |
| `spawn_opt` | Crea un proceso avanzado. |
| `spawn_request` | Pide crear un proceso. |
| `spawn_request_abandon` | Descarta la petición de crear un proceso. |
| `unalias` | Elimina una referencia como alias del proceso actual. |
| `unlink` | Elimina un enlace de un proceso con otro. |
| `yield` | Cede a otro proceso en espera la ejecución. |

Estas son las funciones para manejar nodos:

| Función | Descripción |
|:-------:|:------------|
| `disconnect_node` | Fuerza la desconexión de un nodo. |
| `get_cookie` | Devuelve la *cookie* de un nodo. |
| `is_alive` | Indica si el nodo actual está vivo. |
| `monitor_node` | Modifica una relación de monitor con un nodo. |
| `node` | Devuelve el nombre de un nodo. |
| `nodes` | Devuelve nombres de nodos. |
| `register` | Registra un nombre en el nodo. |
| `registered` | Devuelve los nombres registrados. |
| `set_cookie` | Modifica la *cookie* de un nodo. |
| `unregister` | Elimina un nombre registrado en el nodo. |
| `whereis` | Devuelve el proceso o puerto asociado a un nombre. |

Estas son las funciones para manejar puertos de comunicación:

| Función | Descripción |
|:-------:|:------------|
| `open_port` | Abre un puerto. |
| `port_call` | Realiza una petición síncrona a un puerto. |
| `port_close` | Cierra un puerto. |
| `port_command` | Envía datos a un puerto. |
| `port_connect` | Cambia el dueño de un puerto. |
| `port_control` | Ejecuta una operación de control. |
| `port_info` | Devuelve información sobre un puerto. |
| `ports` | Devuelve los puertos usados por el nodo. |

### Manejo de estructuras de datos

..

### ETS, DETS y Mnesia

..

### EUnit

..

### Emakefile

Podemos incluir en nuestros proyectos un fichero llamado `Emakefile`, que nos permitirá automatizar la compilación. El contenido del fichero es una secuencia de definiciones con la forma `{Módulos, Opciones}.`, donde *módulos* son átomos que indican la ubicación relativa de los módulos a compilar y las *opciones* determinan cómo se va a compilar cada módulo. Por ejemplo:

```Erlang
{'sources/*', [debug_info,
               {i, "sources"},
               {i, "include"},
               {outdir, "ebin"}]}.
```

El fichero indica que nuestros módulos están en el directorio `sources` y luego una serie de opciones para la compilación. Entre las [opciones de compilación](https://www.erlang.org/doc/man/compile.html) que existen tenemos:

| Opción | Descripción |
|:------:|:------------|
| `debug_info` | Incluye información útil para la depuración. |
| `{i,Dir}` | Añade un directorio a la lista de búsqueda cuando se quiere incluir una cabecera con el preprocesador. |
| `{outdir,Dir}` | Establece el directorio de salida donde se guardará el resultado de la compilación. |
| `export_all` | Hace que todas las funciones del módulo sean exportadas y por lo tanto públicas al exterior. |
| `{d,Macro}` | Define una macro. |
| `{d,Macro,Valor}` | Define una macro con un valor asignado. |

Una vez configurado el fichero, para compilar el proyecto podemos usar el comando:

```
erl -make
```

O también desde la consola de Erlang invocar a:

```Erlang
make:all().
```

