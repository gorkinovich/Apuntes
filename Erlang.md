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

$$\textcolor{red}{[}\texttt{+}\textcolor{red}{|}\texttt{-}\textcolor{red}{]} \textcolor{red}{[}\mathit{base}\texttt{\#}\textcolor{red}{]} \mathit{d\acute{\imath}gitos}$$

La base puede ser un valor dentro del intervalo $[2,36]$ y por defecto es `10`. Ejemplos: `4`, `8`, `15`, `2#10000`, `8#27`, `16#2A`. También podemos definir **números reales** o de **coma flotante**:

$$\textcolor{red}{[}\texttt{+}\textcolor{red}{|}\texttt{-}\textcolor{red}{]} \mathit{d\acute{\imath}gitos}\textcolor{red}{[}\texttt{.}\mathit{d\acute{\imath}gitos}\textcolor{red}{]} \textcolor{red}{[}\texttt{E}\textcolor{red}{[}\texttt{+}\textcolor{red}{|}\texttt{-}\textcolor{red}{]} \mathit{d\acute{\imath}gitos}\textcolor{red}{]}$$

Enteros y reales tienen una representación interna en Erlang distinta, por ello a la hora de realizar una operación matemática, si fuera necesario, la máquina virtual transforma un valor entero en uno real automáticamente.

> La sintaxis de Erlang permite usar el símbolo `_` como separador visual entre los dígitos de un número, de modo que se puede usar como separador de millares. Por ejemplo: `1_234` o `1_2_3`. Al ser un elemento meramente estético, son eliminados a la hora de evaluar la expresión numérica.

### Átomos

..

### Texto

..

## Variables inmutables

..

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

