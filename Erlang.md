# Erlang

[Erlang](https://www.erlang.org/) es un lenguaje de programación diseñado para desarrollar sistemas de comunicación grandes en tiempo real con alta disponibilidad, que sean escalables y tolerantes a fallos. Es un lenguaje de [programación funcional](https://es.wikipedia.org/wiki/Programaci%C3%B3n_funcional), cuya característica principal es disponer de [concurrencia](https://es.wikipedia.org/wiki/Concurrencia_%28inform%C3%A1tica%29).

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

Los átomos son **valores** literales representados por un **nombre**. Para definirlos hay dos maneras. La primera es aquellas cadenas compuestas por letras, números, el guion bajo (`_`) y la arroba (`@`), que empiezan por una letra minúscula. La segunda es aquellas cadenas delimitadas por comillas simples (`'`), que contienen cualquier cadena de texto. Por motivos obvios, la segunda forma no puede contener una comilla simple, salvo que vaya precedida que la barra invertida, es decir: `\'`. Por ejemplo:

```Erlang
plastic_love,
'Mariya Takeuchi'.
```

Como curiosidad, para representar valores **booleanos** se utilizan los átomos `true` y `false`.

> Existen algunas palabras claves reservadas del lenguaje que no pueden ser utilizadas como átomos: `after`, `and`, `andalso`, `band`, `begin`, `bnot`, `bor`, `bsl`, `bsr`, `bxor`, `case`, `catch`, `cond`, `div`, `end`, `fun`, `if`, `let`, `not`, `of`, `or`, `orelse`, `query`, `receive`, `rem`, `try`, `when`, `xor`.

### Texto

Se puede utilizar caracteres y cadenas de texto en Erlang como valores literales. Para los **caracteres** hay que utilizar el símbolo `$` seguido de la letra en cuestión. Para las **cadenas** hay que delimitarlas con las comillas dobles (`"`). Por ejemplo:

```Erlang
$ñ,
"La letra eñe.".
```

Realmente, como pasa en tantos otros lenguajes, la representación de cada letra es un valor numérico y por extensión el de una cadena es una lista de números. Es decir, que esta sintaxis es azúcar sintáctico, pero no por ello deja de ser útil su uso.

> Se puede dividir la definición de una cadena en varios segmentos si es necesario, sin que ello altere el resultado final. Por lo tanto, es lo mismo la cadena `"abcdefgh"` que la cadena `"abcd" "efgh"`.

## Variables inmutables

Las variables son **valores asociados** a un **nombre identificador**. Para definir un nombre de variable, se necesita una cadena compuesta por una serie de letras, números, guiones bajos (`_`) y/o arrobas (`@`), que empieza por una letra mayúscula o un guion bajo. A diferencia de los átomos, que son valores por sí mismos, las variables necesitan ser inicializadas. Una de las formas posibles es utilizar el operador de asignación (`=`) de la siguiente manera:

```Erlang
Year = 1984,
Name = george_orwell.
```

La otra forma, en que se asignan valores a una variable, es al invocar una función con una serie de valores utilizados como argumentos de la aplicación de dicha función. Al invocarla, se pasan los valores de los argumentos y se asignan a las variables que representan los parámetros de la función.

Hay que tener en cuenta, que una vez que se asigna un valor a cualquier variable, no se puede volver a asignar otro valor nuevo a la misma, ya que estas son **inmutables**. Al principio esto puede parecer un escollo insalvable, pero ya iremos viendo cómo superar esta aparente dificultad.

> El guion bajo a solas (`_`) es una variable especial que se utiliza en el lenguaje para cuando no nos interesa el valor que tiene asignado. Internamente, al compilarlo, genera una variable fresca para evitar la colisión de nombres entre las diferentes apariciones de esta variable comodín.

## Estructuras de datos

### Tuplas

..

### Listas

..

### Diccionarios

..

### Binarios

..

### Encaje de patrones

..

## Operadores

..

## Funciones

..

## Ramificación

..

## Concurrencia

..

## Errores y excepciones

..

## Comportamientos

..

