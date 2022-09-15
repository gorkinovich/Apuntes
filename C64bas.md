# Commodore 64: Lenguaje BASIC V2

## Hola mundo

Para empezar recurriremos al clásico Hola Mundo:

```BASIC
10 REM ESTO ES UN COMENTARIO
20 PRINT "HOLA MUNDO"
```

Todo programa en BASIC está compuesto por líneas con comandos. Cada línea empieza por un número identificador, de 0 a 63999, seguido de un comando del lenguaje. Las líneas tendrán un tamaño máximo de 80 caracteres. Opcionalmente podemos usar `:` para tener varios comandos dentro de una misma línea.

En el ejemplo tenemos dos líneas como parte del programa. En la primera tenemos un comentario de código usando el comando `REM`. En la segunda, con el comando `PRINT`, se envía un mensaje de texto a la pantalla. Para poder ejecutar el programa usaremos el comando `RUN`.

El C64 nos permite ver el código del programa cargado en memoria con `LIST`. 

$$\texttt{LIST}\ \textcolor{red}{[[} \mathit{primera} \textcolor{red}{]} \texttt{-} \textcolor{red}{[} \mathit{última} \textcolor{red}{]]}$$

| Parámetro | Descripción |
|:---------:|-------------|
| *primera* | Número de línea inicial del listado, por defecto es 0. |
| *última* | Número de línea final del listado, por defecto es 63999. |

Por ejemplo:

```BASIC
LIST 10     : REM Lista la línea 10 del programa.
LIST -10    : REM Lista hasta la línea 10 del programa.
LIST 10-    : REM Lista desde la línea 10 del programa.
LIST 10-100 : REM Lista desde la línea 10 hasta a la 100.
```

## Comentarios

Con el comando `REM` podemos comentar el código para documentarlo, pero estos comentarios ocupan espacio en la memoria de programa. Este comando ignora el uso de `:` para añadir varios comandos en la misma línea, ya que será ignorado todo lo que venga después de `REM` en la línea.

## Constantes

BASIC tiene tres tipos de datos: **números enteros**, **números flotantes** y **cadenas de texto**. Los tres los podemos expresar como valores literales de la siguiente manera:

+ **Enteros:** Números de 16 bits con signo (2 bytes). Desde `-32768` hasta `+32767`, usando [complemento a dos](https://es.wikipedia.org/wiki/Complemento_a_dos), usando la siguiente sintaxis:

$$\textcolor{red}{[}\texttt{+}\textcolor{red}{|}\texttt{-}\textcolor{red}{]} \mathit{d\acute{\imath}gitos}$$ 

+ **Flotantes:** Números flotantes de 40 bits (5 bytes). El exponente puede tener un valor desde `-39` hasta `+38`. Usan la siguiente sintaxis:

$$\textcolor{red}{[}\texttt{+}\textcolor{red}{|}\texttt{-}\textcolor{red}{]} \mathit{d\acute{\imath}gitos}\textcolor{red}{[}\texttt{.}\mathit{d\acute{\imath}gitos}\textcolor{red}{]} \textcolor{red}{[}\texttt{E}\textcolor{red}{[}\texttt{+}\textcolor{red}{|}\texttt{-}\textcolor{red}{]} \mathit{d\acute{\imath}gitos}\textcolor{red}{]}$$

+ **Cadenas:** Cualquier texto que empieza y termina por dobles comillas (`"`).

Por ejemplo:

```BASIC
10 PRINT "CADENA DE TEXTO"     : REM CADENA DE TEXTO
20 PRINT "POSITIVO:"  1234     : REM POSITIVO: 1234     
30 PRINT "NEGATIVO:" -4321     : REM NEGATIVO:-4321
40 PRINT "FLOTANTE:" 6.543E-21 : REM FLOTANTE: 6.543E-21
```

El único carácter que no puede contener un literal de cadena de texto son las dobles comillas, sin embargo usando la función `CHR$(34)` podemos obtener una cadena de texto que contenga dobles comillas:
 
```BASIC
10 PRINT CHR$(34) "AMIGA" CHR$(34) : REM "AMIGA"
```

Por último, la constante **pi** está representada por la letra griega `π`, que se escribe con las teclas `MAYÚS`+`AvPág` en VICE y con `MAYÚS`+`SUPR` en CCS64.

```BASIC
10 PRINT π : REM 3.14159265
```

## Variables

Las variables nos permiten guardar valores con un nombre identificador, para poder recuperarlos y/o modificarlos más tarde. Un nombre identificador es una secuencia compuesta por letras (`A-Z`) y dígitos (`0-9`), que debe empezar siempre por una letra. Los tipos de variables que existen son:

+ **Flotantes:** Almacenan números de coma flotante. Es el tipo por defecto de las variables, simplemente hay que definir un nombre identificador. Por ejemplo: `X`, `Y`, `Z`, etc.
+ **Enteras:** Almacenan números enteros. Este tipo se asigna terminando el nombre identificador con el símbolo `%`. Por ejemplo: `I%`, `J%`, `K%`, etc.
+ **Cadenas:** Almacenan cadenas de texto. Este tipo se asigna terminando el nombre identificador con el símbolo `$`. Por ejemplo: `N$`, `M$`, `S$`, etc.

Podemos asignar un valor a una variable con el operador `=`:

```BASIC
10 U  = 1.234
20 V% = 12345
30 W$ = "ABC"
```

El tamaño de un nombre identificador puede ser tan largo como una línea, pero el intérprete de BASIC sólo tiene en cuenta las dos primeras letras y su tipo. Es decir:

```BASIC
10 RAX  = 10
20 RAY  = 20
30 RAZ% = 30
40 PRINT RAX  : REM 20
50 PRINT RAZ% : REM 30
```

No podemos utilizar como nombres identificadores los que ya están asignados para los comandos de BASIC, así como sus abreviaciones, a las que llamaremos palabras reservadas del lenguaje.

## Operadores

El lenguaje dispone de diferentes operaciones para poder trabajar con los valores. A la hora de aplicar un operador, este tiene un nivel de prioridad que veremos al final de la sección. La primera categoría de operadores son los aritméticos:

| Símbolo | Descripción              |
|:-------:|--------------------------|
| `+`     | Suma / Prefijo positivo  |
| `-`     | Resta / Prefijo negativo |
| `*`     | Multiplicación           |
| `/`     | División                 |
| `↑`     | Exponenciación           |

El símbolo `↑` se escribe con la tecla `AvPág` en VICE y con `SUPR` en CCS64. Al editar programas en BASIC en el CBM prg Studio usaremos el carácter `^` para la exponenciación. Estas operaciones aritméticas se pueden utilizar con números enteros y reales. Por ejemplo:

```BASIC
10 A = 3 : B = 2
20 PRINT A + -B      : REM 1
30 PRINT A - B       : REM 1
40 PRINT A * B       : REM 6
50 PRINT A / B       : REM 1.5
60 PRINT A ↑ B       : REM 9
70 PRINT A + B / 2   : REM 4
80 PRINT (A + B) / 2 : REM 2.5
```

Nótese que con los paréntesis podemos alterar el orden de aplicación de los operadores, porque los paréntesis también son operadores en sí mismos.

El siguiente grupo de operadores son los de comparación:

| Símbolo | Descripción   |
|:-------:|---------------|
| `<`     | Menor         |
| `<=`    | Menor o igual |
| `=`     | Igual         |
| `>=`    | Mayor o igual |
| `>`     | Mayor         |
| `<>`    | Distinto      |

Podemos usar estos operadores con cualquier valor, para determinar qué orden tienen entre sí. Vemos que el símbolo `=` es usado por los operadores de igualdad y de asignación, pero sólo hay dos situaciones donde se usa la asignación:

```BASIC
10 A = 1
20 LET B = 2
30 PRINT A = B
```

Hemos dicho dos situaciones, pero en realidad es sólo una. En la línea `20` usamos el comando `LET`, que nos permite asignar a una variable (situada a la izquierda del `=`) un valor obtenido con una expresión (situada a la derecha del `=`). En la línea `10` en realidad estamos también usando el comando `LET`, pero podemos prescindir de la palabra clave `LET` para asignar un valor a una variable.

El siguiente grupo de operadores son los lógicos:

| Símbolo | Descripción   |
|:-------:|---------------|
| `NOT`   | Negación      |
| `AND`   | Conjunción    |
| `OR`    | Disyunción    |

Antes de continuar, necesitamos una pequeña explicación teórica:

> Los operadores de comparación, junto a los operadores lógicos, permiten crear **expresiones booleanas** que representan condiciones dentro de los programas, para poder tomar decisiones durante la ejecución. El resultado de una expresión booleana es un **valor booleano**, pero al no existir este tipo de dato en BASIC se utilizan los números enteros, usando `0` para indicar que la condición es **falsa** y cualquier otro valor entero para indicar que es **verdadera** (por ejemplo, cuando una comparación es verdadera se obtiene como resultado el `-1`).

Para entender mejor los operadores lógicos vamos a ver sus *tablas de verdad*:

| `A` | `B` | `NOT A` | `NOT B` | `A AND B` | `A OR B` |
|:---:|:---:|:-------:|:-------:|:---------:|:--------:|
|  V  |  V  |    F    |    F    |     V     |    V     |
|  F  |  V  |    V    |    F    |     F     |    V     |
|  V  |  F  |    F    |    V    |     F     |    V     |
|  F  |  F  |    V    |    V    |     F     |    F     |

Estos operadores lógicos funcionan a [nivel de bits](https://es.wikipedia.org/wiki/Operador_a_nivel_de_bits), es decir, se aplican a cada bit de los 16 que hay en un número entero de BASIC. Por lo tanto, si hacemos `2 OR 1` el resultado será `3`. Si intentamos usar un número real, con un operador lógico, el valor será transformado a un valor entero, para poder operar con él.

Finalmente, tenemos el grupo de operadores para manejar cadenas, que está compuesto únicamente por la concatenación, que utiliza el símbolo `+`. Por ejemplo:

```BASIC
10 A$ = "HOLA"
20 B$ = " MUNDO"
30 PRINT A$ + B$ : REM HOLA MUNDO
```

Por último, vamos a ver la prioridad de cada operador a la hora de ser aplicados en una expresión:
| Nivel | Operadores | Descripción |
|:-----:|:----------:|-------------|
| 1 | `↑` | Exponenciación |
| 2 | `+`<br/>`-` | Prefijos |
| 3 | `*`<br/>`/` | Multiplicación<br/>División |
| 4 | `+`<br/>`-` | Suma/Concatenación<br/>Resta |
| 5 | `<`<br/>`<=`<br/>`=`<br/>`>=`<br/>`>`<br/>`<>` | Comparación |
| 6 | `NOT` | Negación |
| 7 | `AND` | Conjunción |
| 8 | `OR` | Disyunción |

## Arrays

Los arrays son "tablas" de una o más dimensiones donde cada celda contiene un valor. En BASIC se utilizan los paréntesis, a la derecha de un nombre de variable con su tipo, para asignar o acceder a los valores que hay dentro. Por ejemplo:

```BASIC
10 A$(0) = "HOLA"
20 A$(1) = "MUNDO"
30 PRINT A$(0) " " A$(1) : REM HOLA MUNDO
```

Los arrays hay que definir su número de dimensiones y el tamaño de las mismas, ya que de no hacerlo se asignará por defecto un tamaño de 1 dimensión de 10 posiciones (índices del 0 al 9) la primera vez que utilicemos dicho array en el programa. Una vez dimensionado el array, no se podrá redimensionar su tamaño, porque nos saltaría un error de ejecución. Para definir el tamaño se utiliza el comando `DIM`:

$$\texttt{DIM}\ \mathit{variable} \texttt{(} \mathit{n_1} \textcolor{red}{[} \texttt{,}\ \mathit{n_2} \textcolor{red}{[} \texttt{,}\ \textcolor{red}{\dots]]} \texttt{)} \textcolor{red}{[} \texttt{,}\ \textcolor{red}{\dots]}$$

Con este comando podemos definir el tamaño de varios arrays, separado por comas. Un array puede tener hasta 255 dimensiones y el rango máximo disponible para cada índice es del 0 al 32767. Con $n_1$ definimos que la primera dimensión tiene tamaño $n_1$+1, es decir, que el índice de esta dimensión tiene como rango del 0 al $n_1$. Con $n_2$ definimos la segunda dimensión y así sucesivamente. Por ejemplo:

```BASIC
10 L(2) = 10  : REM TAM=10  L(0..9)     
20 DIM V(3)   : REM TAM=4   V(0..3)
30 DIM M(3,3) : REM TAM=4X4 M(0..3,0..3)
```

El interprete de BASIC trata como si fueran variables de programa distintas aquellas que son arrays, de las que no lo son, aunque compartan el mismo nombre, es decir, `A` y `A(0)` son variables diferentes dentro del programa. Por ejemplo:

```BASIC
10 A(0) = 1
20 A = 2
30 PRINT A(0) : REM 1
40 PRINT A    : REM 2
```

Podemos utilizar los arrays como parte de expresiones complejas junto a operadores y funciones del lenguaje.

## Usando la terminal

Definimos la terminal o consola como aquel dispositivo que utilizamos para interactuar con un computador. Normalmente está compuesto por una pantalla y un teclado. Cuando iniciamos el C64 veremos que nos muestra información sobre la máquina, el lenguaje y la memoria del sistema, para luego ver que hay un cuadrado parpadeando que nos indica la posición actual del cursor. Si pulsamos la tecla `A`, veremos que en efecto aparece en la pantalla la letra `A`. Esto es así porque al arrancar el C64 se ejecuta el programa que permite usar la máquina como una terminal de programación en BASIC. En esta sección veremos cómo usar la terminal con programas BASIC.

En el C64 hay dos modos de fuente que usa la terminal de base. En el modo mayúsculas sólo tenemos las letras mayúsculas y en el modo minúsculas tendremos minúsculas al escribir y con la tecla `SHIFT` (`MAYUS` en VICE) podemos usar las letras mayúsculas. Para alternar entre los dos tipos se utiliza la combinación `SHIFT`+`C=` (`MAYUS`+`TAB` en VICE). En la siguiente imagen se ven las diferencias entre las dos fuentes:

<p align="center"><img src="https://gorkinovich.github.io/learn/C64-Fonts.png" alt="Fuentes del C64"></p>

Aunque ya lo hemos usado en varios de los ejemplos, para mostrar un mensaje por pantalla utilizamos el comando `PRINT`, que tiene la siguiente sintaxis:

$$\texttt{PRINT}\ \textcolor{red}{[} \mathit{expresión} \textcolor{red}{]\ [[} \texttt{;} \textcolor{red}{|} \texttt{,} \textcolor{red}{]}\ \mathit{expresión}\ \textcolor{red}{\dots]}$$

Una *expresión* es cualquier combinación de constantes, variables, operadores y funciones, que generan como resultado un valor que el comando usará para mostrarlo en la terminal. Por lo tanto, el resultado de una expresión será un número entero, un número flotante o una cadena de texto. Para separar las expresiones podemos usar `;`, sin que añada espacios en blanco, pero con `,` añadirá una tabulación entre un valor y el siguiente por pantalla. Por ejemplo:

```BASIC
10 PRINT "A";"B" : REM AB
20 PRINT "A","B" : REM A         B
```

El tabulado usa columnas de 10 caracteres de tamaño, por eso en la línea `20` la letra `B` se muestra en la columna 10, en lugar de la columna 1 como ocurre con la línea `10`. En algunos ejemplos previos, hemos visto que no era necesario usar `;` para separar algunas expresiones, sobre todo trabajando con cadenas, pero en caso de duda es mejor usar `;` y hacer más claro el código. Si usamos el `;` al final del comando `PRINT`, el cursor del terminal no realizará el salto de línea que habitualmente se hace al finalizar el comando. Otro comportamiento peculiar, que hay que tener en cuenta, es al mostrar un número se añadirá un espacio en blanco al inicio y al final del número:

```BASIC
10 PRINT "(";"ABC";")" : REM (ABC)
20 PRINT "(";12345;")" : REM ( 12345 )
30 PRINT "(";1.234;")" : REM ( 1.234 )
```

El comando `PRINT` sin nada se limita a dar un salto de línea con el cursor de la terminal.

Con el comando `INPUT` podemos introducir valores con el teclado, para obtener números y cadenas de texto. Para ello usamos la siguiente sintaxis:

$$\texttt{INPUT}\ \textcolor{red}{[} \mathit{cadena}\texttt{;} \textcolor{red}{]}\ \mathit{variable} \textcolor{red}{[} \texttt{,}\ \mathit{variable}\ \textcolor{red}{\dots]}$$

Con el parámetro opcional *cadena* podemos mostrar un mensaje inicial antes de introducir los valores. Tanto si usamos un mensaje inicial, como si no, lo siguiente que hace el comando es añadir a la terminal el carácter `?` y un espacio en blanco, para luego mostrar el cursor parpadeando, señal de que podemos introducir información. Los parámetros *variable* estarán separados por comas y dependiendo de su tipo habrá que meter un tipo de valor u otro por parte del usuario. Sólo al pulsar `RETURN` (`ENTER` en VICE) se procesa lo que hayamos escrito, para convertirlo a un valor que pueda ser almacenado en la variable. Si intentamos meter un valor de un tipo, en una variable de otro tipo, se producirá un error y se parará la ejecución. Por ejemplo:

```BASIC
10 INPUT A$,A%,A
20 PRINT "TEXTO:  ";A$
30 PRINT "ENTERO:";A%
40 PRINT "REAL:  ";A
```

El siguiente método de entrada es el comando `GET`:

$$\texttt{GET}\ \mathit{variable} \textcolor{red}{[} \texttt{,}\ \mathit{variable}\ \textcolor{red}{\dots]}$$

Este comando nos permite obtener caracteres del buffer de entrada que maneja la terminal, que tiene un tamaño de 10 caracteres (es decir, 10 bytes). El comando no bloquea la ejecución con su uso, por lo que si el buffer de entrada está vacío se le asignará el valor nulo por defecto a las variables (`""` para las cadenas y `0` para los números). Aunque podemos usar variables numéricas, es mejor usar variables de cadena de texto, para ir obteniendo el primer carácter del buffer de entrada, ya que con las numéricas recibiremos un error si pulsamos cualquier tecla que no sea un dígito o un carácter con el que se pueda escribir un número. Con este comando podemos hacer más dinámico el uso del teclado desde BASIC.

Por último, vamos a cubrir las funciones relacionadas con la entrada y salida de la terminal. La función `POS` nos devuelve la columna actual del cursor (desde `0` hasta `79`):

$$\texttt{POS(} \mathit{basura} \texttt{)}$$

Una limitación que tiene el interprete de BASIC es que no se puede definir en el lenguaje funciones sin parámetros, por ello `POS` tiene el parámetro *basura* que da igual el valor que le pasemos, porque no se va a utilizar. Por motivos de eficiencia, relacionados con la implementación del interprete, lo más óptimo es pasarle el literal pi (`π`).

Las funciones `SPC` y `TAB` las podemos usar con el comando `PRINT`. La primera añade espacios en blanco y la segunda define el ancho de columna para tabular:

$$\texttt{SPC(} \mathit{número} \texttt{)}$$

$$\texttt{TAB(} \mathit{número} \texttt{)}$$

Con el parámetro *número* indicamos el número de espacios que queremos añadir en `SPC` y el ancho de columna en `TAB`. Este número ha de ser un entero del `0` al `255`, de lo contrario se lanzará un error de ejecución. Hay una diferencia importante entre usar `TAB` y `,` dentro de `PRINT`. Si el valor previo excede el ancho de columna, la función `TAB` no añadirá más espacios, pero con `,` moverá el siguiente valor a la siguiente columna de tabulación.

## Sentencias de control

Después de ver diferentes aspectos básicos del lenguaje, vamos a explicar cómo controlar la ejecución del programa. Lo primero que debemos aprender es la sentencia condicional:

$$\texttt{IF}\ \mathit{condición}\ \texttt{THEN}\ \mathit{comando}\ \textcolor{red}{[} \texttt{:}\ \mathit{comando}\ \textcolor{red}{\dots]}$$

El comando `IF` nos permite ejecutar una serie de comandos si la *condición* es cierta. Las condiciones son expresiones booleanas, que vimos antes en la sección de los operadores. Por ejemplo:

```BASIC
10 INPUT "DAME UN NUMERO";N
20 IF N=0 THEN PRINT "CERO"
30 IF N>0 THEN PRINT "POSITIVO"
40 IF N<0 THEN PRINT "NEGATIVO"
```

Ahora que podemos tomar decisiones, vamos a aprender las sentencias de salto. La primera de ellas es el salto incondicional con `GOTO`:

$$\texttt{GOTO}\ \mathit{l\acute{\imath}nea}$$

Con este comando podemos enviar la ejecución actual a otra línea del programa. Luego tenemos la llamada a una subrutina con `GOSUB`

$$\texttt{GOSUB}\ \mathit{l\acute{\imath}nea}$$

Es similar a la anterior, pero la diferencia es que cuando encuentre una línea con el comando `RETURN`, volverá la posición de la ejecución a la línea del `GOSUB` que ha invocado la subrutina. Por ejemplo:

```BASIC
10 GOSUB 30
20 GOTO 10
30 PRINT "PULSA STOP/ESCAPE"
40 RETURN
```

El ejemplo llama primero con `GOSUB` a una subrutina ubicada en la línea `30`. La subrutina nos muestra un mensaje por pantalla y vuelve al punto de ejecución anterior con `RETURN`. Después con `GOTO` se realiza un bucle infinito. Pulsando la tecla `RUN/STOP` (`ESCAPE` en VICE) paramos la ejecución del interprete de BASIC y por ello logramos salir del bucle a lo bruto.

Ahora que conocemos los comandos de salto, vamos a ver una variante del comando `IF`:

$$\texttt{IF}\ \mathit{condición}\ \textcolor{red}{ \\{ }\texttt{THEN}\textcolor{red}{|}\texttt{GOTO}\textcolor{red}{ \\} }\ \mathit{l\acute{\imath}nea}$$

Con este comando aplicaremos un salto directo si se cumple la condición. Por ejemplo:

```BASIC
10 PRINT "PULSA UNA TECLA"
20 GET K$
30 IF K$="" THEN 20
40 PRINT "PULSASTE: ";K$
50 IF K$<>CHR$(13) THEN 20
```

Este ejemplo ya tenemos bucles condicionales. En la línea `30` si no se ha capturado nada con `GET` volvemos a repetir el comando. Después de pulsar y capturar una tecla pulsada, mostramos cuál ha sido y en la línea `50` volveremos a dar la vuelta si no se ha pulsado la tecla `RETURN` (`ENTER` en VICE).

Los dos siguientes comandos sirven para realizar bucles con un número fijo de iteraciones:

$$\texttt{FOR}\ \mathit{variable}\texttt{=}\mathit{inicio}\ \texttt{TO}\ \mathit{final}\ \textcolor{red}{[} \texttt{STEP}\ \mathit{incremento} \textcolor{red}{]}$$

$$\texttt{NEXT}\ \textcolor{red}{[} \mathit{variable} \textcolor{red}{[} \texttt{,}\ \mathit{variable}\ \textcolor{red}{\dots]]}$$

El comando `FOR` inicia el bucle y `NEXT` lo cierra, permitiendo que en cada vuelta la *variable* (que sólo puede ser de tipo flotante por limitaciones de la implementación del interprete) vaya tomando valores numéricos desde *inicio* hasta *final*. Lo común es ir incrementando en una unidad la *variable*, pero con `STEP` podemos indicar en *incremento* un valor alternativo a `+1`, incluso poner valores negativos para realizar recorridos hacia atrás. Por ejemplo:

```BASIC
10  PRINT CHR$(147);     : REM LIMPIAR PANTALLA
20  FOR I=1 TO 5         : REM POTENCIAS DE 2
30  PRINT I,2↑I          : REM PINTAR DATOS
40  NEXT I               : REM SIGUIENTE ITERACIÓN
50  PRINT                : REM SALTO DE LINEA
60  FOR I=5 TO 1 STEP -1 : REM LISTA DE NUMEROS
70  PRINT I,6-I          : REM PINTAR DATOS
80  NEXT I               : REM SIGUIENTE ITERACIÓN
90  PRINT                : REM SALTO DE LINEA
100 FOR I=2 TO 10 STEP 2 : REM PARES E IMPARES
110 PRINT I-1,I          : REM PINTAR DATOS
120 NEXT I               : REM SIGUIENTE ITERACIÓN
```

Este programa nos muestra secuencias numéricas en orden ascendente la primera, en orden descendente la segunda y en un orden ascendente con saltos en la tercera. Recordemos que `↑` en el CBM prg Studio sería con `^`. Este tipo de bucles son útiles cuando sabemos de antemano el número de vueltas o iteraciones que tenemos que dar. Un buen ejemplo para su uso es al trabajar con arrays, donde sabemos previamente cuál es su tamaño.

Podemos salir de un bucle `FOR` antes de su finalización con `GOTO`, pero esto provoca que no se borre de la pila de programa la información que utilizan los comandos `FOR` y `NEXT`, es decir, que si  se sale el suficiente número de veces de un bucle `FOR` sin terminarlo se terminará lanzando un error de memoria agotada. Hay una serie de situaciones donde se borra la información de estos bucles en la pila de programa:

+ Al terminar un bucle `FOR` completando su recorrido.
+ Al encontrar un `NEXT` con una variable, se borra la información de los bucles internos.
+ Al ejecutar el `RETURN` de una subrutina, se borra la información en la pila de aquellos bucles `FOR` en su interior.
+ Al encontrar un bucle `FOR`que utilice la misma variable que uno anterior sin terminar.

Una solución, si nos preocupa este problema es añadir este código después del bucle que nos pueda dar problemas:

```BASIC
FOR I=1 TO 1:NEXT I
```

Podemos anidar unos nueve bucles `FOR` entre sí y BASIC nos permite usar un único `NEXT` con todos ellos, pero honestamente no es recomendable hacer eso de cara a mantener el código legible para futuras revisiones del mismo. Si no se indica una variable junto a `NEXT`, se procederá a modificar la última variable contador de un `FOR`, es decir, se actualizará la variable del bucle interno anidado en el que estemos. Como recomendación, de cara a la legibilidad, es recomendable hacer explícita la variable que `NEXT` vaya a actualizar.

El comando `ON` nos permite saltar en la ejecución del programa mediante un índice:

$$\texttt{ON}\ \mathit{expresión}\ \textcolor{red}{ \\{ }\texttt{GOSUB}\textcolor{red}{|}\texttt{GOTO}\textcolor{red}{ \\} }\ \mathit{l\acute{\imath}nea} \textcolor{red}{[} \texttt{,}\ \mathit{l\acute{\imath}nea}\ \textcolor{red}{\dots]}$$

Esta sentencia de control requiere de una *expresión* numérica que de como resultado un valor desde `1` hasta *N*, siendo *N* el número de *líneas* que hayamos indicado en el comando. Siendo más precisos, *expresión* debe ser un valor desde `0` hasta  `255` o nos dará un error en ejecución. Si metemos un número con decimales, este será redondeado, si metemos una opción que está fuera del la cantidad de líneas que tenemos, no se realizará salto alguno y continuará la ejecución con la siguiente línea al comando `ON`. Esta sentencia nos vendrá bien para hacer menús de forma sencilla, por ejemplo:

```BASIC
5   REM PINTAR EL MENU
10  PRINT "1. NUEVA PARTIDA"
20  PRINT "2. CARGAR PARTIDA"
30  PRINT "3. OPCIONES"
40  PRINT "4. SALIR"
50  PRINT
55  REM INTRODUCIR UNA OPCION
60  INPUT "ELIGE UNA OPCION";N
70  PRINT
75  REM SALTAR A LA OPCION
80  ON N GOTO 100,110,120,130
90  M$="INCORRECTO"  :GOTO 150
100 M$="JUGANDO"     :GOTO 150
110 M$="CARGANDO"    :GOTO 150
120 M$="CONFIGURANDO":GOTO 150
130 PRINT "SALIENDO" :GOTO 140
140 END
145 REM RUTINA PARA PINTAR MENSAJES
150 PRINT M$:PRINT
160 GOTO 10
```

Primero, el comando `END` termina la ejecución del programa. Como podemos ver, pintamos un menú, pedimos un número del `1` al `4` y aplicamos el salto en base a lo que se haya metido. Si metemos un valor mayor que `4` o un `0`, la ejecución pasará a la línea `90`. Si metemos un número negativo o mayor que `255` nos lanzará un error de ejecución, por ello es recomendable añadir código que realice comprobaciones con la entrada como:

```BASIC
65 IF N<1 OR N>4 THEN N=0
```

De esta manera, cualquier número introducido que no esté entre las opciones válidas será convertido al valor `0`.

Finalmente, aunque lo hemos visto con anterioridad, el comando `LET` nos permite asignar valores a variables en el lenguaje:

$$\textcolor{red}{[}\texttt{LET}\textcolor{red}{]}\ \mathit{variable}\texttt{=}\mathit{expresión}$$

Es opcional poner `LET` y, como ya hemos explicado, la *expresión* es una combinación de constantes, variables, operadores y funciones.

## Funciones numéricas

Las funciones matemáticas del BASIC de C64 tienen la siguiente forma:

$$\mathit{nombre}\texttt{(}\mathit{expresión}\texttt{)}$$

Primero hay que indicar el *nombre* identificador de la función y luego la *expresión* que vamos a pasar como parámetro de la llamada. El resultado será un número de coma flotante, aunque se pueda almacenar en una variable entera, en este último caso el valor se trunca dejando tan la parte entera únicamente. Estas son las funciones disponibles para trabajar con números:

| Nombre   | Descripción |
|:--------:|-------------|
| `ABS(X)` | Calcula el **valor absoluto** de X (elimina su signo). |
| `ATN(X)` | Calcula el **arcotangente** con radianes. |
| `COS(X)` | Calcula el **coseno** con radianes. |
| `EXP(X)` | Exponenciación de *e*<sup>X</sup>. |
| `INT(X)` | Redondea X hacia abajo. |
| `LOG(X)` | Logaritmo neperiano de X: log<sub>e</sub>(X). |
| `RND(X)` | Genera un número real aleatorio entre `0` y `1` (incluyendo el 0 pero no el 1 en su rango). |
| `SGN(X)` | Devuelve el signo de X (`-1` = Negativo, `0` = Cero, `+1` = Positivo). |
| `SIN(X)` | Calcula el **seno** con radianes. |
| `SQR(X)` | Calcula la **raíz cuadrada** de X. |
| `TAN(X)` | Calcula la **tangente** con radianes. |

Veamos algunas consideraciones sobre estas funciones. Las funciones trigonométricas funcionan con [radianes](https://es.wikipedia.org/wiki/Radi%C3%A1n) en lugar de [grados](https://es.wikipedia.org/wiki/Grado_sexagesimal), por lo que veremos luego cómo se hace la conversión entre ambas medidas. El número *e* es `2.71828183`, pero a diferencia de `π`, no existe un símbolo en el C64 para representar esta constante. La función `EXP` es el inverso de `LOG` y viceversa. Para calcular un logaritmo en otra base usaremos la siguiente fórmula:

$$\mathit{log_y}(x) = \dfrac{\mathit{log_e}(x)}{\mathit{log_e}(y)}$$

En cuanto a la función `RND(X)` hemos de tener en cuenta que:

+ Si `X` es positivo dará un número aleatorio en cada llamada, obtenido de la secuencia predeterminada interna del C64.
+ Si `X` es negativo devuelve siempre el mismo número de la secuencia predeterminada interna. Cada valor negativo tiene asociado un elemento de la secuencia.
+ Si `X` es cero genera un número aleatorio utilizando el reloj interno, aunque esto provocará resultados limitados que no servirán para generar números grandes.

También podemos definir funciones matemáticas propias con el comando:

$$\texttt{DEF}\ \texttt{FN}\ \mathit{nombre}\texttt{(}\mathit{variable}\texttt{)} \texttt{=} \mathit{expresión}$$

Para ello tenemos que indicar un nombre identificador que no esté ya reservado, recordando que sólo se tendrán en cuenta los dos primeros caracteres, luego indicar un nombre de variable de coma flotante que vayamos a usar dentro de la función y finalmente la expresión matemática que calcula la función. Por ejemplo:

```BASIC
10 DEF FN DG(R)=R*180/π
20 DEF FN RD(D)=D*π/180
30 DEF FN RO(X)=INT(X+0.5)
40 DEF FN L1(X)=LOG(X)/LOG(10)
```

Tenemos cuatro funciones definidas: pasar de radianes a grados, pasar de grados a radianes, redondear un número y calcular el logaritmo en base 10. Las dos primeras son las típicas funciones obtenidas por una regla de tres:

$$\dfrac{\mathit{rad}}{\mathit{deg}} = \dfrac{\mathit{2 * \pi}}{\mathit{360}} = \dfrac{\mathit{\pi}}{\mathit{180}}$$

La tercera viene a suplir una deficiencia de `INT`, que realmente es una función de "suelo" más que de redondear. Para redondear con `INT` basta con sumar `0.5` al valor de entrada y con ello los valores que están entre $[0.5,1.0)$ o $[-0.5,0.0)$ se redondearán hacia arriba, mientras que el resto de casos redondeará hacia abajo. La cuarta función es la aplicación de lo que vimos para calcular un logaritmo en una base distinta al número *e*, que es la que maneja la función `LOG`.

Para poder aplicar estas funciones tenemos el comando:

$$\texttt{FN}\ \mathit{nombre}\texttt{(}\mathit{expresión}\texttt{)}$$

Indicamos el nombre de la función y entre paréntesis la expresión matemática que generará el valor que será pasado como parámetro a la función. Por ejemplo, usando las funciones del ejemplo anterior:

```BASIC
50  PRINT FNL1(1),   FNRD(0),   TAB(30) FNDG(0)
60  PRINT FNL1(10),  FNRD(90),  FNDG(π/2)
70  PRINT FNL1(100), FNRD(180), FNDG(π)
80  PRINT FNL1(1E3), FNRD(270), FNDG(π*3/4)
90  PRINT FNL1(1E4), FNRD(360), FNDG(2*π)
100 PRINT
110 PRINT FNRO(-3.6),FNRO(-2.5),FNRO(-1.0)
120 PRINT FNRO( 2.0),FNRO( 3.4),FNRO( 4.7)
```

Otro ejemplo interesante a contemplar es el siguiente:

```BASIC
10 DEF FN D6(X)=INT(RND(X)*6)+1
20 FOR I=1 TO 10
30 PRINT FN D6(1)
40 NEXT I
```

Aquí definimos una función para hacer una tirada de un dado de seis caras con la función de números aleatorios. Después mostramos por pantalla 10 resultados de tirada de dados.

## Funciones de cadenas

Tenemos también funciones para trabajar con cadenas. La primera calcula el tamaño de una cadena:

$$\texttt{LEN(} \mathit{cadena} \texttt{)}$$

Donde *cadena* es una expresión que devuelve un valor de cadena de texto y este valor es pasado como argumento a la función cuando es invocada. Esencialmente nos dice el número de caracteres que tiene la cadena que le pasemos. Recordemos que las cadenas pueden tener tamaños desde `0` hasta `255`.

El siguiente grupo de funciones nos permite convertir valores numéricos a cadenas y viceversa:

$$\begin{array}{ccc}
\texttt{ASC(} \mathit{cadena} \texttt{)}
& \qquad &
\texttt{VAL(} \mathit{cadena} \texttt{)}
\\\\[0.2cm]
\texttt{CHR\\$(} \mathit{número} \texttt{)}
& \qquad &
\texttt{STR\\$(} \mathit{número} \texttt{)}
\end{array}$$

La función `ASC` recibe una cadena y convierte el carácter al inicio en el número entero que corresponde con su código PETSCII. Si le pasamos una cadena vacía lanzará un error en tiempo de ejecución. La función inversa a `ASC` es `CHR$`, que toma un código PETSCII y devuelve una cadena de un carácter que representa a dicho código. Los códigos PETSCII son números enteros desde `0` hasta `255`.

La función `VAL` recibe una cadena y la intenta convertir en un número entero o flotante, si no pudiera nos devolvería el valor `0`. Hay que señalar que los espacios en blanco son ignorados al procesar la cadena. Su función contraria es `STR$`, que recibe un número y lo convierte en una cadena.

Otro grupo importante son las funciones que nos permiten extraer un fragmento del interior de una cadena:

$$\texttt{LEFT\\$(} \mathit{cadena}\texttt{,}\ \mathit{tamaño} \texttt{)}$$

$$\texttt{RIGHT\\$(} \mathit{cadena}\texttt{,}\ \mathit{tamaño} \texttt{)}$$

$$\texttt{MID\\$(} \mathit{cadena} \texttt{,}\ \mathit{inicio} \textcolor{red}{[}\texttt{,}\ \mathit{tamaño} \textcolor{red}{]} \texttt{)}$$

Donde *cadena* es la expresión que devuelve la cadena que vamos a pasar como parámetro de la función y *tamaño* es el número de caracteres que queremos extraer, que puede ser un tamaño desde `0` hasta `255`. ¿Qué pasa si queremos extraer más caracteres de los que hay en la cadena? Cuando llega al final de la cadena el algoritmo para de copiar caracteres y nos devuelve la cadena que ha extraído sin provocar un error de ejecución. Luego hay otro parámetro más en el caso de `MID$`, que es *inicio*, y este consiste en indicar a partir de qué posición vamos a empezar a extraer caracteres. A diferencia de los arrays, la primera posición de una cadena es el `1` y no el cero, lo cual hay que tener en cuenta porque si intentamos extraer la posición `0` se lanzará un error de ejecución.

Para entender mejor algunas de estas funciones vamos a ver el siguiente ejemplo:

```BASIC
10  INPUT S$
20  S%=LEN(S$)
30  HS%=INT(LEN(S$)/2+0.5)
40  SL$=LEFT$(S$,HS%)
50  SR$=RIGHT$(S$,HS%)
60  PRINT "CADENA:    ";S$
70  PRINT "TAMANO:    ";S%
80  PRINT "IZQUIERDA: ";SL$
90  PRINT "DERECHA:   ";SR$
100 PRINT:GOSUB 170:PRINT
110 Z=HS%:IF HS%=INT(LEN(S$)/2) THEN Z=Z+1
120 PRINT S$
130 FOR I=1 TO Z
140 PRINT SPC(I-1);MID$(S$,I,HS%)
150 NEXT I
160 END
170 V=VAL(S$)
180 IF (V<>0) OR (V=0 AND S$="0") THEN 210
190 PRINT "NO ES UN NUMERO"
200 RETURN
210 PRINT "ES UN NUMERO:";V
220 RETURN
```

Metemos una cadena por teclado y calculamos su tamaño, la mitad del mismo y tomamos la mitad izquierda y luego la mitad derecha. Las líneas `60-90` nos muestra la información que hemos obtenido. En la línea `100` llamamos a una subrutina que convierte la cadena a número y comprueba si se ha realizado la conversión correctamente. Para ello tiene que comprobar que no es cero el valor devuelto, pero si fuera cero hemos de comprobar que es la cadena `"0"` (aunque esto tiene un bug si metemos una cadena con varios ceros). Una peculiaridad de `VAL` es que si los primeros caracteres son un número, devolverá ese valor que pueda encontrar al principio, por ejemplo con `"123ABC"` nos devolvería el número `123`. Después de volver de la subrutina, vamos a recorrer la cadena para extraer todos los posibles segmentos de la misma que ocupen la mitad de su tamaño. Como hemos avisado, la posición inicial ha de empezar del valor `1` en adelante.

## El reloj del sistema

Como tantas otras máquinas, el C64 tiene un reloj interno que se pone en funcionamiento en cuanto se inicia el sistema. Para acceder a su valor usamos la variable `TIME`, que devuelve un valor en el que cada unidad corresponde a `1/60` segundos, es decir, 60 Hz como las televisiones [NTSC](https://es.wikipedia.org/wiki/NTSC), frente a los 50 Hz del sistema [PAL](https://es.wikipedia.org/wiki/PAL). Para que se entienda mejor `TIME/60` nos da el número de segundos que han transcurrido desde el inicio de la máquina. Hay que señalar que consultar esta variable puede conllevar imprecisiones, ya que al ejecutar operaciones de entrada y salida con las CIAs se podría poner en pausa la actualización del contador de tiempo.

Además de lo anterior, con la variable `TIME$` obtenemos una cadena en formato `HHMMSS` donde nos indica las horas, minutos y segundos que han transcurrido en formato de 24 horas. Esta variable, a diferencia de la anterior, podemos asignarle el valor que queramos, ya que de intentar asignar un valor a `TIME`, se produce un error en tiempo de ejecución. Al poder modificar el valor de `TIME$`, indirectamente cambiaremos el valor de `TIME`, por lo que podemos resetear el tiempo y hacer cronómetros en caso de necesitarlos. Los valores que podemos asignar son desde `"000000"` (00:00:00) hasta `"235959"` (23:59:59), ya que cuando incremente este último valor en un segundo dará la vuelta a la hora cero.

## Manejo de datos

Un aspecto peculiar del lenguaje BASIC son los comandos `DATA` y `READ`, que permiten una suerte de manejo de datos en el código de un programa. Digamos que queremos almacenar una información, por ejemplo un nivel de un juego, que vamos a cargar luego en ejecución, para lograrlo usaríamos el comando `DATA`:

$$\texttt{DATA}\ \mathit{constante} \textcolor{red}{[} \texttt{,}\ \mathit{constante}\ \textcolor{red}{\dots]}$$

Con este comando vamos poniendo secuencias de valores constantes, que luego vamos a rescatar con el comando `READ`

$$\texttt{READ}\ \mathit{variable} \textcolor{red}{[} \texttt{,}\ \mathit{variable}\ \textcolor{red}{\dots]}$$

Obviamente, no podemos leer con una variable numérica una constante de cadena de texto, por lo que de intentarlo obtendríamos un error en tiempo de ejecución. Lo que sí podemos hacer es usar una variable de cadena de texto para leer cualquier dato y luego intentar convertirlo a número si fuera necesario, claro que esto será menos eficiente.

¿Qué ocurre si queremos volver a leer datos anteriores? Si ya hemos leído todas las constantes definidas con `DATA`, e intentamos ejecutar un `READ`, se producirá un error de ejecución. Para evitarlo, con el comando `RESTORE` pondremos el puntero de lectura de datos al inicio del todo, permitiendo que volvamos a leer datos anteriores. Pero esto tiene el problema de tener que recorrer toda la información previa a la que buscamos, de forma secuencial, como si estuviéramos en una cinta de casete.

Es importante, cuando tenemos información que cargar en nuestros programas, estudiar si será mejor opción utilizar ficheros externos o no. El uso de ficheros externos nos permite evitar los accesos secuenciales, salvo que estemos usando un casete, donde el modelo de lectura también es secuencial. Sin embargo, el uso de disquetes se puede volver en nuestra contra al manejar ficheros "grandes", pues la lectora Commodore 1541 tuvo problemas en su diseño que la llevaron a tener velocidades de lectura muy bajas. Concretamente hablamos de un ancho de banda entre 300 y 400 B/s. Para que se comprenda bien, la cara de un disquete tiene un tamaño máximo de 174.848 bytes, que con una velocidad de 300 B/s son aproximadamente 583 segundos en total para leer el disco entero, que son 9 minutos y 43 segundos.

## Gestión de ficheros

Para trabajar con un fichero lo primero que hay que hacer es abrirlo:

$$\texttt{OPEN}\ \mathit{nid} \textcolor{red}{[}\texttt{,}\ \mathit{dispositivo} \textcolor{red}{[}\texttt{,}\ \mathit{modo} \textcolor{red}{[}\texttt{,}\ \mathit{fichero} \textcolor{red}{]]]}$$

El parámetro *nid* es un número identificador con valor desde `1` hasta `255`, aunque es preferible que sea menor de `128`. Los parámetros *dispositivo* y *modo* hacen referencia a con qué dispositivo de entrada o salida vamos a trabajar:

| Dispositivo | Modo | Descripción |
|:-----------:|:----:|-------------|
| `0` | `0` | Lectura del Teclado. |
| `1` | `0`<br/>`1`<br/>`2` | Lectura del *datasette*.<br/>Escritura del *datasette*.<br/>Escritura del *datasette* seguido de la marca `EOT` (End Of Tape). |
| `2` | `0` | Modem / RS-232. |
| `3` | `0`,`1` | Escritura y lectura de la pantalla. |
| `4`-`5` | `0`<br/>`7` | Modo mayúsculas de la impresora.<br/>Modo minúsculas de la impresora. |
| `8`-`15` | `2`-`14`<br/>`15` | Canales de datos de la disquetera.<br/>Canales de comandos de la disquetera. |

Por último el parámetro *fichero* indica la ruta del fichero con el que trabajar:

$$\mathit{fichero} = \texttt{"} \mathit{nombre} \textcolor{red}{[} \texttt{,} \textcolor{red}{\\{} \texttt{SEQ} \textcolor{red}{|} \texttt{REL} \textcolor{red}{|} \texttt{USR} \textcolor{red}{\\}} \textcolor{red}{[} \texttt{,} \textcolor{red}{\\{} \texttt{R} \textcolor{red}{|} \texttt{W} \textcolor{red}{\\}} \textcolor{red}{]]}\texttt{"}$$

Para indicar la ruta primero necesitamos el *nombre* del fichero, seguido del tipo de fichero y finalmente si es para leer (`R`) o escribir (`W`). Los tipos de fichero que tenemos son secuenciales (`SEQ`), de acceso aleatorio con registros (`REL`) o de usuario (`USR`). Lo habitual es trabajar con ficheros secuenciales desde BASIC.

Como suele ser habitual con la gestión de recursos, manejar ficheros conlleva muchas opciones de provocar fallos en ejecución:

+ `?TOO MANY FILES`: Al tener más de 10 ficheros abiertos a la vez.
+ `?FILE NOT OPEN`: Al usar un comando de ficheros con un fichero que no ha sido abierto.
+ `?FILE OPEN`: Al intentar abrir un fichero ya abierto.
+ `?DEVICE NOT PRESENT`: El dispositivo no existe o no está encendido. También puede ser que no se ha identificado el `EOT` en la cinta del *datasette*.
+ `?FILE NOT FOUND`: No se ha encontrado el fichero en la ruta indicada.
+ `?FILE EXISTS`: La ruta indicada pertenece a otro fichero reservado del disco.

Por desgracia, no podemos capturar los fallos de ejecución en el lenguaje BASIC, por lo que de producirse se terminará la ejecución de nuestro programa abruptamente. Cuando usemos el *datasette* sólo los cuatro primeros errores podrán ocurrir.

Para cerrar un fichero abierto usaremos:

$$\texttt{CLOSE}\ \mathit{nid}$$

Si tratamos de cerrar un identificador, que no esté abierto, no se producirá ningún error en ejecución. Si un programa se interrumpe por un error y había ficheros abiertos, estos no se cerrarán automáticamente, por lo que habrá que cerrarlos manualmente, para evitar comportamientos inesperados al volver a ejecutar el programa (o reiniciar la consola).

El siguiente bloque de comandos nos resultará familiar:

$$\texttt{PRINT\\#}\ \mathit{nid} \texttt{,}\  \mathit{expresión} \textcolor{red}{[[} \texttt{;} \textcolor{red}{|} \texttt{,} \textcolor{red}{]}\ \mathit{expresión}\ \textcolor{red}{\dots]}$$

$$\texttt{INPUT\\#}\ \mathit{nid} \texttt{,}\ \mathit{variable} \textcolor{red}{[} \texttt{,}\ \mathit{variable}\ \textcolor{red}{\dots]}$$

$$\texttt{GET\\#}\ \mathit{nid} \texttt{,}\ \mathit{variable} \textcolor{red}{[} \texttt{,}\ \mathit{variable}\ \textcolor{red}{\dots]}$$

Estos comandos son muy similares a `PRINT`, `INPUT` y `GET`, con algunas diferencias. Con `PRINT#` podemos escribir información en un fichero. Con `INPUT#` podemos leer información de un fichero, pero no podemos leer cadenas mayores de 80 caracteres sin provocar un error en ejecución. El comando `INPUT#` no muestra por pantalla ningún mensaje para trabajar. Con `GET#` podemos leer un carácter de un fichero, lo cual nos permitirá leer cadenas de más de 80 caracteres. Cuando `GET#` se encuentra con `CHR$(0)` devuelve la cadena vacía. Al llegar al final de fichero, el comando `GET#` devolverá por defecto `CHR$(199)`, para poder distinguir que efectivamente hemos llegado al final usaremos la variable `STATUS`. Esta variable representa el byte de memoria en la dirección `144` (`$0090`) y es sólo de lectura:

| Bit | Máscara | Puerto Serie | Datasette | RS-232 |
|:---:|:-------:|--------------|-----------|--------|
| 0 | 1   | En caso de *timeout*:<br/>0 = Lectura (Entrada)<br/>1 = Escritura (Salida) | - | Error de paridad |
| 1 | 2   | Error de *timeout* | - | Error de *framing* |
| 2 | 4   | - | Bloque demasiado corto (< 192 bytes) | Buffer de entrada sobrescrito |
| 3 | 8   | - | Bloque demasiado largo (> 192 bytes) | Buffer de entrada vacío |
| 4 | 16  | Error en `VERIFY` | Error en `VERIFY` | Señal CTS no encontrada |
| 5 | 32  | - | Error de *checksum* | - |
| 6 | 64  | Final de fichero | Final de fichero (sólo mientras está leyendo) | Señal RTS perdida |
| 7 | 128 | Error de dispositivo no encontrado | - | BREAK detectado |

Por ejemplo:

```BASIC
10 OPEN 1,8,4,"TEST,SEQ,W"
20 S$="":INPUT S$
30 PRINT# 1,S$
40 IF S$<>"" THEN 20
50 CLOSE 1
```

En este programa vamos pidiendo cadenas al usuario, para escribirlas en el un fichero secuencial. Si no vaciamos la variable `S$`, al ejecutar el comando `INPUT`, si metemos una cadena vacía no se sobrescribe la variable y estaríamos en un bucle infinito. Tras terminar de escribir en el fichero, lo podemos leer con el siguiente ejemplo:

```BASIC
10 OPEN 1,8,4,"TEST,SEQ,R"
20 GET# 1,C$
30 PRINT C$;
40 IF 0=(STATUS AND 64) THEN 20
50 PRINT
60 CLOSE 1
```

Suponiendo que no esté vacío el fichero, con este programa leeríamos byte a byte el fichero entero y lo mostraríamos por pantalla. En la línea `40` si no hemos llegado al final de fichero, continuamos leyendo. Si llegamos al final de fichero continuamos por la línea `50` y en la siguiente se cierra el fichero.

Por último, tenemos el siguiente comando para redirigir la salida de la pantalla hacia un fichero:

$$\texttt{CMD }\ \mathit{nid} \textcolor{red}{[}\texttt{,}\  \textcolor{red}{[}\mathit{expresión} \textcolor{red}{]\ [[} \texttt{;} \textcolor{red}{|} \texttt{,} \textcolor{red}{]}\ \mathit{expresión}\ \textcolor{red}{\dots]]}$$

Una vez ejecutado el comando, el fichero abierto asociado a *nid* irá guardando los `PRINT` y demás comando que envíen información a la pantalla de la terminal del C64.

## Gestión del sistema

En esta sección vamos a aprender algunos aspectos de bajo nivel del lenguaje BASIC del C64. Empezaremos con la función que nos devuelve cuanta memoria libre queda para programas BASIC:

$$\texttt{FRE}\texttt{(} \mathit{basura} \texttt{)}$$

De nuevo da igual qué valor pasemos como parámetro a esta función, porque no se va a utilizar. Lo primero que hace `FRE` es llamar al recolector de basura para liberar la memoria de cadenas de texto sin usar y después calcular cuánta memoria libre queda en el segmento para programas BASIC. Por un detalle de implementación, este cálculo es un entero sin signo de 16 bits, pero al convertirlo en número flotante lo interpreta como si fuera un entero con signo, por lo que al superar los 32.767 bytes nos devuelve un valor negativo al que hay que sumar `65536`. Por ejemplo:

```BASIC
10 V=FRE(0)
20 IF V<0 THEN V=V+65536
30 PRINT V
```

El resultado que nos mostrará es `38861`, por lo que el programa ocupa 50 bytes. También podemos definir la siguiente función para calcular la memoria libre:

```BASIC
DEF FN FM(X)=FRE(0)-65536*(FRE(0)<0)
```

Recordemos que cuando una condición es verdadera obtendremos el valor entero `-1`, que multiplicado por `65536` pasa a ser un número negativo y al restar con un número negativo estamos realmente sumando (menos por menos es más). Si tenemos programas largos, como puede ser un juego, posiblemente no necesitemos tener esta función declarada.

Para manipular la memoria del C64 tenemos:

$$\texttt{PEEK}\texttt{(} \mathit{dirección} \texttt{)}$$

$$\texttt{POKE}\ \mathit{dirección} \texttt{,}\ \mathit{valor}$$

Con `PEEK`, indicando la dirección de memoria que queremos consultar, obtendremos el byte almacenado en la dirección. Con `POKE` podemos almacenar un byte en una dirección de la memoria, es decir, *valor* admite desde `0` hasta `255`. Las direcciones se indican en base 10, ya que no tenemos en este lenguaje la posibilidad de indicar valores hexadecimales, y son enteros sin signo de 16 bits (desde `0` hasta `65536`).

El comando para acceder a subrutinas de código máquina es:

$$\texttt{SYS}\ \mathit{dirección}$$

El comando `SYS` nos permite que se ejecute una subrutina almacenada en la dirección indicada. Para poder comunicar BASIC con el código máquina, hay una serie de direcciones de memoria que son cargadas en los registros de la CPU, se ejecuta la subrutina y antes de finalizar se guardan en dichas posiciones de memoria el contenido de los registros, para poder leerlos desde BASIC. Estas son las direcciones para escribir y leer los registros de la CPU al ejecutar `SYS`:

| Dirección | Registro |
|:---------:|:--------:|
| 780 | **A** |
| 781 | **X** |
| 782 | **Y** |
| 783 | **P** |

El registro **A** se le conoce como el acumulador y el **P** contiene el estado de los flags de la CPU, para controlar el resultado de algunas operaciones. Estos registros están explicados con más detenimiento en el apartado del lenguaje ensamblador. Veamos un ejemplo de lo que podemos hacer:

```BASIC
10 PRINT CHR$(147);":)";
20 C=10:R=8 :GOSUB 60:PRINT "HOLA"
30 C=20:R=16:GOSUB 60:PRINT "MUNDO"
40 C=0 :R=21:GOSUB 60:PRINT "ADIOS"
50 END
60 POKE 211,C : REM $00D3=C
70 POKE 214,R : REM $00D6=R
80 SYS 58640  : REM JSR $E510
90 RETURN
```

Con la subrutina de la línea `60` podemos modificar las coordenadas del cursor de la terminal. Para entenderlo hay que comprender el código máquina de la subrutina [`PLOT`](http://unusedino.de/ec64/technical/aay/c64/rome50a.htm) del KERNAL, pero como no es el objetivo de este manual, vamos a resumirlo en que vamos directamente a guardar en la memoria las los datos que va a usar el sistema y llamamos la subrutina que va a usar `PLOT` para mover el cursor.

Existe la función `USR(X)`, que permite invocar una subrutina de código máquina para devolver un número flotante. Para ello hay almacenar en las direcciones 785–786 ($0311–$0312) la dirección de la subrutina. Cuando esta es invocada hay que consultar el FAC (acumulador de coma flotante), direcciones $0061–$0066, para obtener el parámetro cuando es un número de coma flotante, si fuera una cadena de texto serían las direcciones $0064-$0065, que es el puntero al descriptor de cadena. Cuando termine la rutina, antes de ejecutar la instrucción `RTS`, hay que almacenar el resultado en el FAC. Realmente este método es complejo, al implicar la utilización de números de coma flotante, por lo que no es especialmente recomendable.

El último comando de esta sección permite paralizar la ejecución del programa:

$$\texttt{WAIT}\ \mathit{dirección} \texttt{,}\ \mathit{máscara_{and}} \textcolor{red}{[}\texttt{,}\ \mathit{máscara_{xor}} \textcolor{red}{]}$$

El comando va a la *dirección* indicada, lee el byte de la memoria y entra en un bucle donde: se aplica un *XOR* con la segunda máscara (por defecto el valor es `0`), se aplica un *AND* con la primera máscara y si el resultado es cero se repite el bucle. El operador lógico *XOR* o [disyunción exclusiva](https://es.wikipedia.org/wiki/Disyunci%C3%B3n_exclusiva) sirve para invertir bits dentro de un byte en aquellas posiciones que tengamos un `1`, ya que con `0` se deja el bit tal cual. ¿Para qué se quiere la máscara del *XOR*? Esencialmente para cuando queremos comprobar que un bit en la memoria pasa de `1` a `0`, en lugar de `0` a `1`.

Esta operación nos puede servir para esperar eventos como colisiones entre elementos gráficos (sprites y caracteres) u otras posibilidades. Una aplicación útil que tiene es aplicar retardos de tiempo (*delays*), como muestra este ejemplo:

```BASIC
10 T=90
20 POKE 162,128-T
30 WAIT 162,128
```

El reloj interno de la máquina tiene 24 bits y empieza en la posición 162 como byte inferior, luego 161 como byte intermedio y 160 como byte más alto. Estas son las posiciones que la variable `TIME` lee. Dentro de un byte, el valor `128` es el bit más alto, por lo tanto si restamos un valor inferior o igual, el reloj terminará volviendo a activar dicho bit pasado 2,13 segundos, ya que cada unidad es 1/60 de segundo. En el ejemplo se espera 1,5 segundos hasta que se activa el bit más alto de la dirección 162. De ese modo se pueden programar fácilmente pequeños retardos, para ralentizar la ejecución si esta va demasiado rápida para que pueda reaccionar un jugador.

## Control del interprete

Esta última sección de comandos nos permitirán controlar algunos aspectos del interprete de BASIC del C64, empezando por el comando que inicia la ejecución de un programa:

$$\texttt{RUN }\ \textcolor{red}{[} \mathit{l\acute{\imath}nea} \textcolor{red}{]}$$

Con `RUN` iniciamos los programas, pudiendo indicar de forma opcional a partir de qué línea queremos que arranque. Una vez iniciada la ejecución, la podemos parar con `STOP` o `END`, para luego continuar con `CONT`. El uso de `STOP` no tiene efectos secundarios sobre la pila de programa. 

Con `NEW` se libera toda la memoria de BASIC y la pila de programa, borrando el programa cargado y todas las estructuras de datos generadas durante la última ejecución. Con `CLR` se borra la memoria de datos y la pila de programa, es decir, borra todo menos el programa cargado en la memoria. Cuando ejecutamos un `RUN` se invoca el comando `CLR` internamente.

Además de lo anterior, tenemos un grupo de comandos para cargar y guardar programas en ficheros:

$$\texttt{LOAD}\ \textcolor{red}{[} \texttt{"}\mathit{fichero}\texttt{"} \textcolor{red}{[}\texttt{,}\ \mathit{dispositivo} \textcolor{red}{[}\texttt{,}\ \mathit{modo} \textcolor{red}{]]]}$$

$$\texttt{SAVE}\ \textcolor{red}{[} \texttt{"}\mathit{fichero}\texttt{"} \textcolor{red}{[}\texttt{,}\ \mathit{dispositivo} \textcolor{red}{[}\texttt{,}\ \mathit{modo} \textcolor{red}{]]]}$$

$$\texttt{VERIFY}\ \textcolor{red}{[} \texttt{"}\mathit{fichero}\texttt{"} \textcolor{red}{[}\texttt{,}\ \mathit{dispositivo} \textcolor{red}{]]}$$

Con *fichero* indicamos el nombre del programa. Los dispositivos disponibles para trabajar son `1`, para el *datasette*, y `8`-`15`, para las disqueteras. Por defecto, se asume que se usará el dispositivo `1` si no se indica lo contrario. En cuanto a los modos disponibles, para `LOAD` son:

+ `0`: El programa es cargado en la dirección de inicio de la memoria de programas BASIC (2049/$0801).
+ `1`: El programa es cargado en la dirección indicada por los dos primeros bytes del fichero PRG a cargar.

Por defecto el modo para `LOAD` es el valor `0`. Los modos disponibles para `SAVE` son:

+ `0`: El programa se guarda como un programa BASIC.
+ `1`: El programa se guarda en modo absoluto, utilizado por programas en código máquina.
+ `2`: Es necesario únicamente con el *datasette* para escribir la marca EOT (fin de cinta).

También el modo para `SAVE` por defecto es el valor `0`. En cuanto al comando `VERIFY`, su utilidad estriba en comprobar si efectivamente lo que hemos guardado en el fichero es una copia de lo que hay en la memoria. Hay que entender que en los años 80 la tecnología no era tan fiable como actualmente y de ahí la necesidad de este comando.

## Códigos de escape

Cuando usamos el teclado del C64 este genera códigos PETSCII que podemos utilizar con los comandos de entrada y salida que hemos visto. Algunos de estos códigos de escape permiten operaciones especiales con el comando `PRINT`, los podemos incorporar con la función `CHR$` o con el modo de edición especial de las comillas dobles.

El modo de edición de las comillas dobles se activa cuando pulsamos `"` y se desactiva cuando volvemos a pulsar `"` por segunda vez. Este modo está disponible mientras estemos escribiendo un programa en BASIC con el C64. Con este modo podemos introducir, como caracteres visibles, los códigos de escape en lugar de que se ejecute su subrutina. Por ejemplo, si pulsamos la tecla `⇑ CRSR ⇓`, esta envía el código 17, que es capturado y como consecuencia mueve el cursor una posición hacia abajo. Si pulsamos esa tecla, estando en el modo de edición especial, podemos observar que nos pinta en pantalla un `Q` con los colores invertidos, que es la representación visual de dicho código de escape. Si pasamos a `PRINT` una cadena que contenga dicho carácter, veremos que el mensaje se parte por dos, con una parte en una línea y la otra en la siguiente.

Desde el entorno de desarrollo *CBM prg Studio* podemos introducir estos códigos de escape mediante ciertas marcas especiales dentro de las cadenas de texto, ya que estas tienen que ser traducidas de ASCII a PETSCII. Estas marcas van entre llaves `{}`, poniendo dentro el nombre que identifica al código de escape. Por ejemplo, para el código 17 que hemos visto antes, tendremos la marca `{down}`. Podemos ver cuáles están disponibles desde `Tools`+`Screen Code Builder...` o pulsando `F4`, nos aparecerá una ventana llamada `Screen Codes` donde está la pestaña `Key Codes`.

El primer grupo de código de escapes nos permiten cambiar la configuración de la terminal del C64:

| PETSCII | C64 | VICE | CBM prg Studio | Descripción |
|:-------:|:---:|:----:|:--------------:|-------------|
| 8   | `CTRL`+`H` | `CTRL`+`H` | `{ct h}` | Desactiva el cambio de modo de fuente. |
| 9   | `CTRL`+`I` | `CTRL`+`I` | `{ct i}` | Activa el cambio de modo de fuente. |
| 14  | `CTRL`+`N` | `CTRL`+`N` | `{ct n}` | Activa el modo de fuente minúsculas. |
| 18  | `CTRL`+`9` | `CTRL`+`9` | `{reverse on}` | Color invertido activado. |
| 146 | `CTRL`+`0` | `CTRL`+`0` | `{reverse off}` | Color invertido desactivado. |
| 142 | | | `{142}`  | Activa el modo de fuente mayúsculas. |

El segundo grupo nos permite, mientras estemos usando el comando `PRINT`, poder modificar la terminal y la posición actual del cursor:

| PETSCII | C64 | VICE | CBM prg Studio | Descripción |
|:-------:|:---:|:----:|:--------------:|-------------|
| 147 | `SHIFT`+`CLR/HOME` | `MAYUS`+`INICIO` | `{clear}` | Borra la pantalla. |
| 20  | `INST/DEL` | `RETROCEDER` | `{delete}` | Elimina el carácter a la izquierda del cursor. |
| 148 | `SHIFT`+`INST/DEL` | `MAYUS`+`RETROCEDER` | `{148}` | Mueve los caracteres a la derecha para insertar un carácter. |
| 19  | `CLR/HOME` | `INICIO` | `{home}` | Mueve el cursor a la esquina superior izquierda. |
| 17  | `⇑ CRSR ⇓` | `ABAJO` | `{down}` | Mueve el cursor hacia abajo. |
| 29  | `⇐ CRSR ⇒` | `DERECHA` | `{right}` | Mueve el cursor hacia la derecha. |
| 145 | `SHIFT`+`⇑ CRSR ⇓` | `ARRIBA` | `{up}` | Mueve el cursor hacia la arriba. |
| 157 | `SHIFT`+`⇐ CRSR ⇒` | `IZQUIERDA` | `{left}` | Mueve el cursor hacia la izquierda. |

El siguiente grupo de códigos de escape nos permitirán cambiar el color de salida en la pantalla:

| PETSCII | C64        | VICE       | CBM prg Studio  | Descripción        |
|:-------:|:----------:|:----------:|:---------------:|--------------------|
| 144     | `CTRL`+`1` | `CTRL`+`1` | `{black}`       | Color negro        |
| 5       | `CTRL`+`2` | `CTRL`+`2` | `{white}`       | Color blanco       |
| 28      | `CTRL`+`3` | `CTRL`+`3` | `{red}`         | Color rojo         |
| 159     | `CTRL`+`4` | `CTRL`+`4` | `{cyan}`        | Color cian         |
| 156     | `CTRL`+`5` | `CTRL`+`5` | `{purple}`      | Color púrpura      |
| 30      | `CTRL`+`6` | `CTRL`+`6` | `{green}`       | Color verde        |
| 31      | `CTRL`+`7` | `CTRL`+`7` | `{blue}`        | Color azul         |
| 158     | `CTRL`+`8` | `CTRL`+`8` | `{yellow}`      | Color amarillo     |
| 129     | `C=`+`1`   | `TAB`+`1`  | `{orange}`      | Color naranja      |
| 149     | `C=`+`2`   | `TAB`+`2`  | `{brown}`       | Color marrón       |
| 150     | `C=`+`3`   | `TAB`+`3`  | `{pink}`        | Color rosa         |
| 151     | `C=`+`4`   | `TAB`+`4`  | `{dark gray}`   | Color gris oscuro  |
| 152     | `C=`+`5`   | `TAB`+`5`  | `{gray}`        | Color gris         |
| 153     | `C=`+`6`   | `TAB`+`6`  | `{light green}` | Color verde claro  |
| 154     | `C=`+`7`   | `TAB`+`7`  | `{light blue}`  | Color azul claro   |
| 155     | `C=`+`8`   | `TAB`+`8`  | `{light gray}`  | Color gris claro   |

Por último tenemos los siguientes códigos de escape que nos serán útiles de cara a trabajar con los valores obtenidos por el comando `GET`:

| PETSCII | C64              | VICE            | CBM prg Studio  |
|:-------:|:----------------:|:---------------:|:---------------:|
| 3       | `RUN/STOP`       | `ESC`           | `{ct c}`        |
| 13      | `RETURN`         | `ENTER`         | `{return}`      |
| 32      | `SPACE`          | `ESPACIO`       | ` `             |
| 133     | `F1`             | `F1`            | `{f1}`          |
| 134     | `F3`             | `F3`            | `{f3}`          |
| 135     | `F5`             | `F5`            | `{f5}`          |
| 136     | `F7`             | `F7`            | `{f7}`          |
| 137     | `SHIFT`+`F1`     | `F2`            | `{f2}`          |
| 138     | `SHIFT`+`F3`     | `F4`            | `{f4}`          |
| 139     | `SHIFT`+`F5`     | `F6`            | `{f6}`          |
| 140     | `SHIFT`+`F7`     | `F8`            | `{f8}`          |
| 141     | `SHIFT`+`RETURN` | `MAYUS`+`ENTER` | `{141}`         |

El código de escape de `RETURN` y `SHIFT`+`RETURN` tienen el mismo efecto.

## Abreviaturas

| Com.   | Abr.  | Com.   | Abr.  | Com.    | Abr.  | Com.   | Abr.  |
|:------:|:-----:|:------:|:-----:|:-------:|:-----:|:------:|:-----:|
| ABS    |A, ⇧+B | AND    |A, ⇧+N | ASC     |A, ⇧+S | ATN    |A, ⇧+T |
| CHR$   |C, ⇧+H | CLOSE  |CL, ⇧+O| CLR     |C, ⇧+L | CMD    |C, ⇧+M |
| CONT   |C, ⇧+O | COS    |       | DATA    |D, ⇧+A | DEF    |D, ⇧+E |
| DIM    |D, ⇧+I | END    |E, ⇧+N | EXP     |E, ⇧+X | FN     |       |
| FOR    |F, ⇧+O | FRE    |F, ⇧+R | GET     |G, ⇧+E | GET#   |       |
| GOSUB  |GO, ⇧+S| GOTO   |G, ⇧+O | IF      |       | INPUT  |       |
| INPUT# |I, ⇧+N | INT    |       | LEFT$   |LE, ⇧+F| LEN    |       |
| LET    |L, ⇧+E | LIST   |L, ⇧+I | LOAD    |L, ⇧+O | LOG    |       |
| MID$   |M, ⇧+I | NEW    |       | NEXT    |N, ⇧+E | NOT    |N, ⇧+O |
| ON     |       | OPEN   |O, ⇧+P | OR      |       | PEEK   |P, ⇧+E |
| POKE   |P, ⇧+O | POS    |       | PRINT   |?      | PRINT# |PR     |
| READ   |R, ⇧+E | REM    |       | RESTORE |RE, ⇧+S| RETURN |RE, ⇧+T|
| RIGHT$ |R, ⇧+I | RND    |R, ⇧+N | RUN     |R, ⇧+U | SAVE   |S, ⇧+A |
| SGN    |S, ⇧+G | SIN    |S, ⇧+I | SPC     |S, ⇧+P | SQR    |S, ⇧+Q |
| STATUS |ST     | STEP   |ST, ⇧+E| STOP    |S, ⇧+T | STR$   |ST, ⇧+R|
| SYS    |S, ⇧+Y | TAB    |T, ⇧+A | TAN     |       | THEN   |T, ⇧+H |
| TIME   |TI     | TIME$  |TI$    | TO      |       | USR    |U, ⇧+S |
| VAL    |V, ⇧+A | VERIFY |V, ⇧+E | WAIT    |W, ⇧+A |        |       |

