# Python 3

## Primeros pasos

[Python](https://www.python.org/) es un lenguaje interpretado popular con una sintaxis sencilla. Entre propiedades destacadas tenemos múltiples paradigmas, orientación a objetos, tipado dinámico o funciones de primer orden. Para ejecutar un programa necesitamos usar el comando `python`, por ejemplo:

```Python
# Fichero: hola.py
print("¡Hola mundo!")
```

En Python, los **comentarios** de una línea empiezan con `#` y la función `print` muestra por consola un valor. Para **ejecutar** este programa, usaremos el siguiente comando:

```
python hola.py
```

Se pueden pasar **argumentos** al programa accediendo al contenido de `sys.argv`, que es una lista cuyo primer elemento es el fichero que se está ejecutando. Por ejemplo:

```Python
# Fichero: hola.py
import sys

print("¡Hola mundo!")
print(sys.argv)
```

Entonces, para la siguiente llamada, nos dará la siguiente salida:

```
$ python hola.py 20 febrero 1991
¡Hola mundo!
['hola.py', '20', 'febrero', '1991']
```

Cada fichero `.py` representa lo que se denomina un **módulo**, que contiene código para ejecutar así como **definiciones** de clases, funciones y variables. Toda definición requiere de un **nombre** para identificarla, que es una secuencia de caracteres compuesta por letras, números y el guion bajo (`_`), pero que no puede comenzar por un número, es decir, es un nombre `aux_1` pero no lo será `1_aux`. Es recomendable que los nombres sean **descriptivos** de aquello que representan, para facilitar el mantenimiento futuro del código del módulo.

> Por convención, de la [**guía de estilo**](https://peps.python.org/pep-0008/) de Python, se usará para variables y funciones nombres que comiencen con una letra minúscula con [*snake case*](https://en.wikipedia.org/wiki/Snake_case) (por ejemplo, `textura_avatar`), y para clases nombres que comienzan por una letra mayúscula con [*camel case*](https://en.wikipedia.org/wiki/Camel_case) (por ejemplo, `TexturaAvatar`).

Una **variable** es una "caja" que tiene un nombre y su contenido es un valor que puede ir cambiando a lo largo de la ejecución del programa. Desde el punto de vista de la implementación, una variable es el nombre que le ponemos a una zona de la memoria que almacena un valor, porque siempre es más fácil para el humano recordar un nombre que un número con la dirección de memoria donde se ubica nuestro valor.

Una **función** representa un código modular que podemos utilizar con diferentes valores de entrada, para obtener diferentes resultados de salida. En esencia es muy parecido al concepto de función matemática, donde tenemos un nombre, unos parámetros representados por variables de ámbito local a la función, un cuerpo de expresiones que define lo que hace y unos valores como resultado.

Una **clase** representa lo que se denomina un tipo, que es una representación abstracta de un concepto con el que va a trabajar el programa. Por un lado tendremos la definición del tipo y por otro las instancias de un tipo, que son los valores concretos con los que está trabajando el programa. Se podría decir que la definición es la forma y la instancia es el contenido. Para definir un tipo, hace falta definir sus **miembros**, que son los atributos y las operaciones del mismo, donde los atributos son variables y las operaciones son funciones. En Python se denomina clase a la definición de un tipo y objeto a la instancia del mismo. También se denomina a las funciones de una clase como métodos de la misma.

El **ámbito** de una variable es aquellas ubicaciones donde se puede utilizar la misma. El módulo, la función, la clase o el método, son algunos de los diferentes ámbitos donde se puede declarar una variable. Para declarar una variable basta con asignarle un valor:

```Python
año = 1984
```

Volviendo al código del ejemplo `hola.py`, la sentencia `import` nos permite acceder a otros módulos, por lo que `import sys` nos permite acceder al contenido de `sys.py`, que es un módulo de la biblioteca estándar de Python, y con `sys.argv` accedemos al contenido de la variable `argv` de dicho módulo, que contiene los argumentos de entrada utilizados al ejecutar nuestra aplicación.

Cuando usamos la consola de Python también podemos usar `import` para cargar un módulo. Por ejemplo:

```Python
>>> import hola
¡Hola mundo!
['']
```

Si queremos evitar que se ejecute el programa cuando cargamos el módulo desde la consola de Python, podemos usar la siguiente estructura:

```Python
# Fichero: hola.py
import sys

if __name__ == "__main__":
    print("¡Hola mundo!")
    print(sys.argv)
else:
    print("¡Hola importado!")
```

Que al importarlo dará como resultado:

```Python
>>> import hola
¡Hola importado!
```

Si ejecutamos el módulo `python.py` con el comando `python`, veremos que sigue funcionando como antes. Esto es posible porque `__name__` es una variable especial que se configura al importar o ejecutar un módulo. Cuando se ejecuta un módulo su valor es `"__main__"`.

> La sentencia `if` nos permite comprobar que se cumpla una condición, que en este caso es que el contenido de `__name__` sea igual a `"__main__"`, y ejecutar el siguiente bloque de código si es cierto. Si no es cierta la condición, se ejecuta el bloque de código de la sentencia `else`. Los bloques de código dependen del número de espacios con el que se tabulan. Es recomendable evitar mezclar espacios y tabulaciones. La explicación completa, sobre la sentencia `if` y los bloques, se puede encontrar en la sección de *sentencias de control*.

Para que entendamos mejor la situación, supongamos que tenemos:

```Python
# Fichero: adios.py
import hola

print("¡Adiós mundo!")
```

Si ejecutamos el programa, tendremos la siguiente salida:

```
$ python adios.py
¡Hola importado!
¡Adiós mundo!
```

Y si lo importamos, tendremos la siguiente salida:

```Python
>>> import adios
¡Hola importado!
¡Adiós mundo!
```

Por ello debemos tener en cuenta que `import` va a ejecutar el código que se pueda ejecutar en el módulo. Lo recomendable es evitar ejecutar código alguno, prescindiendo en el ejemplo del bloque de la sentencia `else`. En caso de necesitar inicializar el módulo se puede definir una función para ello. Para definir una **función** usaremos:

$$\texttt{def}\ \mathit{nombre} \texttt{(} \textcolor{red}{[} \mathit{variable_1} \textcolor{red}{[} \texttt{,} \textcolor{red}{\dots} \texttt{,} \mathit{variable_n} \textcolor{red}{]} \textcolor{red}{]} \texttt{)} \texttt{:}$$

$$\mathit{bloque\ de\ expresiones}$$

Revisando el ejemplo de `hola.py` y `adios.py`, tendremos que:

```Python
# Fichero: hola.py
import sys

def main():
    print("Entrada: " + __name__)
    print("¡Hola mundo!")
    print(sys.argv)

if __name__ == "__main__":
    main()
```

```Python
# Fichero: adios.py
import hola

print("¡Adiós mundo!")
hola.main()
```

Hemos añadido un `print` de la variable `__name__`, para ver mejor lo que está ocurriendo. Entonces, si ejecutamos el módulo `hola` y `adios`, obtendremos la siguiente salida:

```
$ python hola.py 20 febrero 1991
Entrada: __main__
¡Hola mundo!
['hola.py', '20', 'febrero', '1991']

$ python adios.py
¡Adiós mundo!
Entrada: hola
¡Hola mundo!
['adios.py']
```

Por último, para poder pedir información por consola, usaremos la función `input`. Por ejemplo:

```Python
# Fichero: saludo.py
nombre = input("Buenas, ¿cuál es su nombre? ")
print("Te doy la bienvenida " + nombre + ".")
```

Que al ejecutar nos dará la siguiente salida:

```
$ python saludo.py
Buenas, ¿cuál es su nombre? Arturo
Te doy la bienvenida Arturo.
```

Con la función `input` mostramos un mensaje por la consola y nos devuelve una cadena de texto, que luego es usada para construir el mensaje que mostramos con `print`.

## Nulo o vacío

El valor `None` pertenece al tipo `NoneType` y representa el concepto de la semántica vacía o nula. Cuando algo no tiene valor, usamos este valor para indicarlo en nuestros programas. Por ejemplo, si una función no devuelve ningún valor explícitamente, se devolverá `None` como resultado.

> Aunque parezca una contradicción, usar un valor para expresar algo que no tiene valor, en teoría de lenguajes una cosa son los conceptos teóricos que queremos representar y otra cómo necesitamos implementarlos.

## Booleanos y condiciones

Los valores booleanos vienen del [álgebra de Boole](https://es.wikipedia.org/wiki/%C3%81lgebra_de_Boole) y se usan para representar cuando una condición es verdadera o falsa. Para ello tenemos la constante `True` como verdadero y `False` como falso. Ambos valores pertenecen al tipo `bool`.

> Por temas de implementación en el lenguaje, se considera como falso también el número cero (`0` o `0.0`), los contenedores de datos vacíos (`""`, `[]`, `{}`, etcétera) o el valor nulo (`None`). Todos los objetos tienen un valor booleano.

Tenemos diferentes operadores para construir expresiones booleanas. El primer bloque son los operadores de comparación:

| Operación | Descripción |
|:---------:|:-----------:|
| `X == Y`  | `X` es igual a `Y`. |
| `X != Y`  | `X` no es igual a `Y`. |
| `X <= Y`  | `X` es menor o igual que `Y`. |
| `X < Y`   | `X` es menor que `Y`. |
| `X >= Y`  | `X` es mayor o igual que `Y`. |
| `X > Y`   | `X` es mayor que `Y`. |
| `X is Y` | `X` e `Y` tienen la misma referencia. |
| `X is not Y` | `X` e `Y` tienen diferentes referencias. |

Donde X e Y son expresiones de Python, que se evalúan a un valor que va a ser comparado para determinar si es cierta o falsa la comparación. Nótese que no es lo mismo `==` que `is`, porque lo primero compara el valor final de la expresión y el segundo compara las direcciones de la memoria donde se almacenan dichos valores. Por implementación, las variables que almacenan objetos, que son instancias de una clase, lo que almacenan es un puntero a una dirección de memoria donde está almacenado el objeto de verdad. Estos punteros se les conoce en Python como referencias y es lo que se compara al usar los operadores `is` e `is not`, ya que con `==` lo que comparamos es el valor. Entonces, para lo que se usa, el operador `is`, es para comprobar si dos objetos representan la misma instancia.

> Python permite concatenar comparaciones para comprobar si un valor está dentro de un rango. Por ejemplo, con `1 <= X <= 10` comprobaríamos si `X` está entre el `1` y el `10`. Sería lo mismo que poner `0 < X < 11`, `10 >= X >= 1`, `11 > X > 0`, etcétera.

El segundo bloque son los operadores lógicos:

| Operación | Descripción |
|:---------:|:-----------:|
| `not X` | [Negación](https://es.wikipedia.org/wiki/Negaci%C3%B3n_l%C3%B3gica) de `X`. |
| `X and Y` | [Conjunción](https://es.wikipedia.org/wiki/Conjunci%C3%B3n_l%C3%B3gica) de `X` con `Y`. |
| `X or Y`  | [Disyunción](https://es.wikipedia.org/wiki/Disyunci%C3%B3n_l%C3%B3gica) de `X` con `Y`. |

De nuevo, X e Y son expresiones de Python. Estos operadores nos sirven para componer condiciones más complejas y para entenderlos mejor veamos sus [tablas de la verdad](https://es.wikipedia.org/wiki/Tabla_de_verdad):

|   `X`   |   `Y`   | `not X` | `not Y` | `X and Y` | `X or Y` |
|:-------:|:-------:|:-------:|:-------:|:---------:|:--------:|
| `True`  | `True`  | `False` | `False` |  `True`   | `True`   |
| `False` | `True`  | `True`  | `False` |  `False`  | `True`   |
| `True`  | `False` | `False` | `True`  |  `False`  | `True`   |
| `False` | `False` | `True`  | `True`  |  `False`  | `False`  |

> Los operadores `and` y `or` funcionan con *lógica de cortocircuito*, es decir, al evaluar el primer operando se conoce el resultado final de la expresión, porque sea `False` en el caso de `and` o `True` en el caso de `or`, no se evaluará el segundo operando.

El siguiente operador ternario, sirve para controlar la ejecución de expresiones en base a una condición booleana:

$$\mathit{expresi\acute{o}n_{True}}\ \texttt{if}\ \mathit{condici\acute{o}n}\ \texttt{else}\ \mathit{expresi\acute{o}n_{False}}$$

Si la *condición* es cierta, se ejecuta la primera *expresión*, si es falsa, se ejecuta la segunda. Aunque tengamos disponible este operador, no es recomendable su uso para evitar la ofuscación del código, en su lugar es mejor utilizar la sentencia `if`.

## Números enteros, reales y complejos

Python permite representar números [enteros](https://es.wikipedia.org/wiki/N%C3%BAmero_entero), [reales](https://es.wikipedia.org/wiki/N%C3%BAmero_real) e [imaginarios](https://es.wikipedia.org/wiki/N%C3%BAmero_imaginario) (para componer números [complejos](https://es.wikipedia.org/wiki/N%C3%BAmero_complejo)). Para representar números enteros, que pertenecen al tipo `int`, tenemos:

$$\textcolor{red}{[} \texttt{0} \textcolor{red}{\char123} \texttt{b} \textcolor{red}{|} \texttt{o} \textcolor{red}{|} \texttt{x} \textcolor{red}{|} \texttt{B} \textcolor{red}{|} \texttt{O} \textcolor{red}{|} \texttt{X} \textcolor{red}{\char125} \textcolor{red}{]} \mathit{d\acute{\imath}gitos}$$

Con `b` o `B` expresamos números binarios, con `0` y `1` como dígitos. Con `o` o `O` expresamos números octales, con `0`.\.`7` como dígitos. Con `x` o `X` expresamos números hexadecimales, con `0`.\.`9` y `A`.\.`F` como dígitos, pudiendo usar también letras en minúsculas. Si no se usa ningún prefijo modificador, expresamos números decimales, con `0`.\.`9` como dígitos.

> Podemos expresar `-1` en Python, pero sólo `1` será parte de la expresión literal, el símbolo menos cuenta como un operador unario. Lo mismo ocurre para el caso de `+1`. Esto se aplica para todos los tipos de literales numéricos.

Para representar números reales o de coma flotante, que pertenecen al tipo `float`, tenemos:

$$\mathit{d\acute{\imath}gitos} \texttt{.} \textcolor{red}{[} \mathit{d\acute{\imath}gitos} \textcolor{red}{]} \textcolor{red}{[} \textcolor{red}{\char123} \texttt{e} \textcolor{red}{|} \texttt{E} \textcolor{red}{\char125} \textcolor{red}{[} \texttt{+} \textcolor{red}{|} \texttt{-} \textcolor{red}{]} \mathit{d\acute{\imath}gitos} \textcolor{red}{]}$$

En este caso siempre será necesario el punto como separador decimal, pues de no indicarlo pasaría a ser un literal entero.

> Existen tres valores especiales que son `float('nan')`, `float('-inf')` y `float('inf')`, para representar un no-número (*not a number*), menos infinito e infinito. Con el módulo `math` se pueden comprobar si se tratan de estos valores con las funciones `isnan(x)` e `isinf(x)`.

Para representar números imaginarios tenemos:

$$\mathit{n\acute{u}mero} \textcolor{red}{\char123} \texttt{j} \textcolor{red}{|} \texttt{J} \textcolor{red}{\char125}$$

Basta con indicar un número y terminar con una `j` para representar los números imaginarios en Python. Para componer números complejos, que pertenecen al tipo `complex`, tenemos dos formas. La primera es con la función `complex(R,I)`, donde `R` es la parte real e `I` la imaginaria, siendo ambos parámetros números enteros o reales. La segunda consiste en sumar o restar a un número, entero o real, un número imaginario, por ejemplo `1+2j` o `3-4j`. Hay que tener en cuenta que Python no tiene como tipo el conjunto de los números imaginarios, por lo que `1j` es interpretado como `0+1j` y pertenecerá al tipo `complex`.

> Una curiosidad de las expresiones literales numéricas es que podemos intercalar el carácter `_` entre los dígitos del número, sin que se altere su significado semántico. Este mecanismo existe para poder separar secciones visualmente. Por ejemplo, si queremos en nuestro código tener un separador de millares, podemos usar el guion bajo para tal propósito y tener `1_984` en lugar de `1984` si es de nuestro interés.

En cuanto a las operaciones que podemos realizar con números, el primer bloque de operadores es el de los aritméticos:

| Operación | Descripción |
|:---------:|:-----------:|
| `+X` | Signo positivo. |
| `-X` | Signo negativo. |
| `X + Y` | Suma: `X` más `Y`. |
| `X - Y` | Resta: `X` menos `Y`. |
| `X * Y` | Multiplicación: `X` por `Y`. |
| `X / Y` | División: `X` entre `Y`. |
| `X // Y` | División entera: `X` entre `Y`. |
| `X % Y` | Resto de dividir `X` entre `Y`. |
| `X ** Y` | `X` elevado a `Y`. |

El segundo bloque son los operadores a nivel de bits:

| Operación | Descripción |
|:---------:|:-----------:|
| `~X` | [Negación](https://es.wikipedia.org/wiki/Negaci%C3%B3n_l%C3%B3gica) de los bits de `X`. |
| `X & Y` | [Conjunción](https://es.wikipedia.org/wiki/Conjunci%C3%B3n_l%C3%B3gica) de los bits de `X` con `Y`. |
| `X | Y` | [Disyunción](https://es.wikipedia.org/wiki/Disyunci%C3%B3n_l%C3%B3gica) de los bits de `X` con `Y`. |
| `X ^ Y` | [Disyunción exclusiva](https://es.wikipedia.org/wiki/Disyunci%C3%B3n_exclusiva) de los bits de `X` con `Y`. |
| `X << Y` | Desplazamiento a la izquierda `Y` bits de `X`. |
| `X >> Y` | Desplazamiento a la derecha `Y` bits de `X`. |

De modo similar a los operadores lógicos, aquí están las [tablas de la verdad](https://es.wikipedia.org/wiki/Tabla_de_verdad) de los operadores lógicos aplicados a nivel de bits:

| `X` | `Y` | `~X` | `~Y` | `X & Y` | `X | Y` | `X ^ Y` |
|:---:|:---:|:----:|:----:|:-------:|:-------:|:-------:|
| `1` | `1` |  `0` |  `0` |   `1`   |   `1`   |   `0`   |
| `0` | `1` |  `1` |  `0` |   `0`   |   `1`   |   `1`   |
| `1` | `0` |  `0` |  `1` |   `0`   |   `1`   |   `1`   |
| `0` | `0` |  `1` |  `1` |   `0`   |   `0`   |   `0`   |

Además de estos operadores, existen las funciones nativas `abs`, `divmod` y `pow`, así como los módulo `math`, `cmath`, `numbers`, `decimal`, `fractions`, `random` y `statistics`, para trabajar con números. Estas funciones y módulos se verán en futuras secciones.

## Cadenas de texto

Las cadenas de texto se delimitan con comillas dobles (`"`) o comillas simples (`'`). Es lo mismo `"texto"` que `'texto'`. La expresión `"ho" "la"` equivale a `"hola"`. Hay diferentes tipos de cadenas en Python:

| Tipo | Forma | Descripción |
|:----:|:-----:|:------------|
| `str` | `"..."`<br/>`'...'`<br/>`str(B,E)` | Cadena de texto Unicode (UTF-8) inmutable, donde `B` es una cadena de bytes y `E` es una cadena de texto con la codificación. |
| `bytes` | `b"..."`<br/>`b'...'`<br/>`bytes(S,E)` | Cadena de bytes inmutable, donde `S` es una cadena de texto y `E` es una cadena de texto con la codificación. |
| `bytearray` | `bytearray(B)`<br/>`bytearray(S,E)` | Cadena de bytes mutable, donde `B` es una cadena de bytes, `S` es una cadena de texto y `E` es una cadena de texto con la codificación. |

El cada letra en Unicode, dependiendo de su representación, puede ocupar entre 1 y 3 bytes, mientras que en ASCII sólo puede ocupar 1 byte. Por ello, el tamaño en letras de una cadena `str` puede ser menor que en bytes y, por lo tanto, se requiere indicar la codificación a usar para transformar de texto a bytes y viceversa. Algunas de las codificaciones más conocidas son: `ascii`, `utf-8`, `utf-16`, `utf-32`, `latin`.

Las cadenas de texto de tipo `str` y `bytes` son inmutables, esto quiere decir que no se puede modificar su contenido. Sin embargo, `bytearray` si permite que el contenido sea mutable y por lo tanto modificable.

Las cadenas permiten contener secuencias de escape, que se transforman en ciertos valores. Las secuencias de escape permitidas en Python son:

| Secuencia | Significado | Secuencia | Significado |
|:---------:|:------------|:---------:|:------------|
| `\` *(salto de línea)* | Ignorar continuación. | `\t` | Tabulación horizontal. |
| `\\` | Carácter `\`. | `\v` | Tabulación vertical. |
| `\'` | Carácter `'`. | `\ooo` | Carácter octal *ooo*. |
| `\"` | Carácter `"`. | `\xhh` | Carácter hexadecimal *hh*. |
| `\a` | Alarma. | `\N{n}` | Carácter con nombre en la base de datos Unicode. |
| `\b` | Retroceso. | `\uhhhh` | Carácter Unicode 16-bit. |
| `\f` | Alimentación. | `\Uhhhhhhhh` | Carácter Unicode 32-bit. |
| `\n` | Nueva línea. | `\0` | Carácter nulo, distinto del fin de cadena de C/C++. |
| `\r` | Retroceso de línea. | | |

Se puede definir cadenas usando varias líneas con `"""` o `'''`, por ejemplo:

```Python
"Cadena normal"
"""Cadena
multi-línea"""
```

> Las cadenas *multilínea* se usan también para generar la [documentación](https://peps.python.org/pep-0257/) de clases y funciones en Python.

Con el prefijo `r` se puede indicar que es una cadena *bruta* (*raw*), en la que las barras invertidas (`\`) no sean tomadas como secuencias de escape, sino como caracteres normales. La única salvedad, con este formato de cadenas, es que la barra invertida no puede ir al final de la cadena sin que de un error al interprete.

En cuanto a las operaciones que podemos realizar con cadenas, están explicadas en la sección sobre *operaciones con secuencias*. No obstante hay algunos métodos de la clase `str` a tener en cuenta. El primer bloque de métodos son las funciones de búsqueda en cadenas:

| Función | Descripción |
|:-------:|:------------|
| `S.count(SX)`<br/>`S.count(SX,i)`<br/>`S.count(SX,i,j)` | Devuelve el número de veces que encuentra `SX` en la cadena, entre las posiciones `i` y `j-1`. |
| `S.find(SX)`<br/>`S.find(SX,i)`<br/>`S.find(SX,i,j)` | Devuelve la posición de la primera aparición de `SX` en la cadena, entre las posiciones `i` y `j-1`. Si no se encuentra `SX` devuelve `-1`. |
| `S.rfind(SX)`<br/>`S.rfind(SX,i)`<br/>`S.rfind(SX,i,j)` | Devuelve la posición de la última aparición de `SX` en la cadena, entre las posiciones `i` y `j-1`. Si no se encuentra `SX` devuelve `-1`. |
| `S.index(SX)`<br/>`S.index(SX,i)`<br/>`S.index(SX,i,j)` | Devuelve la posición de la primera aparición de `SX` en la cadena, entre las posiciones `i` y `j-1`. Si no se encuentra `SX` se lanza un `ValueError`. |
| `S.rindex(SX)`<br/>`S.rindex(SX,i)`<br/>`S.rindex(SX,i,j)` | Devuelve la posición de la última aparición de `SX` en la cadena, entre las posiciones `i` y `j-1`. Si no se encuentra `SX` se lanza un `ValueError`. |
| `S.startswith(SX)`<br/>`S.startswith(SX,i)`<br/>`S.startswith(SX,i,j)` | Comprueba si la subcadena, entre las posiciones `i` y `j-1`, empieza igual que `SX`. |
| `S.endswith(SX)`<br/>`S.endswith(SX,i)`<br/>`S.endswith(SX,i,j)` | Comprueba si la subcadena, entre las posiciones `i` y `j-1`, termina igual que `SX`. |

En todas estas funciones de búsqueda, por defecto, `i` tiene el valor `0` y `j` un valor superior al tamaño de la cadena. En el segundo bloque de métodos de `str` están las funciones para unir y partir cadenas:

| Función | Descripción |
|:-------:|:------------|
| `S.join(I)` | Devuelve una cadena que concatena las cadenas en el iterador `I`, usando como separador a `S`. Se lanza un `TypeError` si el iterador contiene elementos distintos al tipo `S`. |
| `S.partition(SX)` | Busca la primera aparición de `SX` en la cadena y devuelve una tupla de tres componentes, con el lado izquierdo, `SX` y el lado derecho de la partición. Si no encuentra `SX` se devuelve `(S,'','')`. |
| `S.rpartition(SX)` | Busca la última aparición de `SX` en la cadena y devuelve una tupla de tres componentes, con el lado izquierdo, `SX` y el lado derecho de la partición. Si no encuentra `SX` se devuelve `('','',S)`. |
| `S.split(sep=None, maxsplit=-1)` | Devuelve una lista con todas las *palabras* que se forman al usar `sep` como separador. Con `None` como separador, se utilizarán los espacios en blanco. Con `maxsplit` indicamos el número máximo de particiones a realizar desde el inicio. |
| `S.rsplit(sep=None, maxsplit=-1)` | Devuelve una lista con todas las *palabras* que se forman al usar `sep` como separador. Con `None` como separador, se utilizarán los espacios en blanco. Con `maxsplit` indicamos el número máximo de particiones a realizar desde el final. |
| `S.splitlines(keepends=False)` | Devuelve una lista con todas las líneas que hay en la cadena. Salvo que `keepends` sea `True`, no se incluirán los saltos de línea en el resultado. |
| `S.replace(S1,S2)`<br/>`S.replace(S1,S2,N)` | Devuelve una copia donde todas las apariciones de `S1` son sustituidas por `S2`. Cuando se indica `N`, en lugar de ser todas sólo se sustituyen las `N` primeras. |

El tercer bloque de métodos de `str` son las funciones para dar formato a cadenas:

| Función | Descripción |
|:-------:|:------------|
| `S.format(*args, **kwargs)` | Devuelve una cadena que toma `S` como patrón de formato. (Ver la sección *cadenas con formato* para más información.) |
| `S.format_map(M)` | Similar a `S.format(**M)`, pero usando directamente el objeto `M`, en lugar de copiarlo a un diccionario como pasaría con `format`. |
| `S.capitalize()` | Devuelve una copia con la primera posición en mayúsculas. |
| `S.casefold()` | Devuelve una copia en minúsculas, incluyendo letras especiales que no cubre el método `lower`. |
| `S.lower()` | Devuelve una copia en minúsculas. |
| `S.upper()` | Devuelve una copia en mayúsculas. |
| `S.swapcase()` | Devuelve una copia con mayúsculas y minúsculas intercambiadas. |
| `S.title()` | Devuelve una copia con cada palabra empezando por mayúsculas. |
| `S.zfill(N)` | Devuelve una copia rellenando con ceros por la izquierda hasta alcanzar un ancho de `N`. Si `S` tiene como prefijo un signo, `+` o `-`, los ceros se insertan después del signo. |
| `S.center(N)`<br/>`S.center(N,C)` | Devuelve una copia centrada con un ancho de `N` posiciones, usando como relleno el carácter `C`. Por defecto, `C` es `' '`. |
| `S.ljust(N)`<br/>`S.ljust(N,C)` | Devuelve una copia alineada en la izquierda con un ancho de `N` posiciones, usando como relleno el carácter `C`. Por defecto, `C` es `' '`. |
| `S.rjust(N)`<br/>`S.rjust(N,C)` | Devuelve una copia alineada en la derecha con un ancho de `N` posiciones, usando como relleno el carácter `C`. Por defecto, `C` es `' '`. |
| `S.expandtabs(tabsize=8)` | Devuelve una copia donde las tabulaciones (`\t`) son sustituidas por espacios, en base a un ancho de columna definido por el parámetro `tabsize`. |
| `S.lstrip()`<br/>`S.lstrip(SX)` | Devuelve una copia donde se eliminan, por la izquierda, caracteres que existen en `SX`, hasta encontrar uno que no. Si `SX` es `None` o no se indica, se borrarán espacios en blanco. |
| `S.rstrip()`<br/>`S.rstrip(SX)` | Devuelve una copia donde se eliminan, por la derecha, caracteres que existen en `SX`, hasta encontrar uno que no. Si `SX` es `None` o no se indica, se borrarán espacios en blanco. |
| `S.strip()`<br/>`S.strip(SX)` | Devuelve una copia donde se eliminan, por ambos lados, caracteres que existen en `SX`, hasta encontrar uno que no. Si `SX` es `None` o no se indica, se borrarán espacios en blanco. |
| `S.removeprefix(SX)` | Si la cadena empieza con `SX`, devuelve una copia donde queda eliminado dicho prefijo. |
| `S.removesuffix(SX)` | Si la cadena termina con `SX`, devuelve una copia donde queda eliminado dicho sufijo. |
| `S.translate(T)` | Devuelve una copia donde se han sustituido los caracteres originales usando una tabla de traducción. |
| `str.maketrans(x)`<br/>`str.maketrans(x,y)`<br/>`str.maketrans(x,y,z)` | Devuelve una tabla de traducción para usar con `translate`. |

El último bloque de métodos de `str` son operaciones generales con cadenas:

| Función | Descripción |
|:-------:|:------------|
| `S.encode(encoding='utf-8', errors='strict')` | Codifica una cadena de texto a una cadena de bytes, utilizando una codificación y una política de gestión de los errores. |
| `S.isalnum()` | Devuelve `True` si la cadena no es vacía y todos los caracteres que contiene son alfanuméricos. Si no, devuelve `False`. |
| `S.isalpha()` | Devuelve `True` si la cadena no es vacía y todos los caracteres que contiene son alfabéticos. Si no, devuelve `False`. |
| `S.isascii()` | Devuelve `True` si la cadena no es vacía y todos los caracteres que contiene son ASCII. Si no, devuelve `False`. |
| `S.isdecimal()` | Devuelve `True` si la cadena no es vacía y todos los caracteres que contiene son números decimales. Si no, devuelve `False`. |
| `S.isdigit()` | Devuelve `True` si la cadena no es vacía y todos los caracteres que contiene son números. Si no, devuelve `False`. |
| `S.isidentifier()` | Devuelve `True` si la cadena no es vacía y cumple las reglas para ser un identificador válido en Python. Si no, devuelve `False`. |
| `S.islower()` | Devuelve `True` si la cadena no es vacía y todos los caracteres que contiene son minúsculas. Si no, devuelve `False`. |
| `S.isnumeric()` | Devuelve `True` si la cadena no es vacía y todos los caracteres que contiene son números Unicode. Si no, devuelve `False`. |
| `S.isprintable()` | Devuelve `True` si la cadena no es vacía y todos los caracteres que contiene se pueden mostrar. Si no, devuelve `False`. |
| `S.isspace()` | Devuelve `True` si la cadena no es vacía y todos los caracteres que contiene son espacios en blanco. Si no, devuelve `False`. |
| `S.istitle()` | Devuelve `True` si la cadena no es vacía y cada palabra empieza por mayúscula. Si no, devuelve `False`. |
| `S.isupper()` | Devuelve `True` si la cadena no es vacía y todos los caracteres que contiene son mayúsculas. Si no, devuelve `False`. |

Exceptuando `casefold`, `isnumeric`, `isidentifier`, `isprintable`, `format_map`, `encode`, `isdecimal` y `format`, el resto de métodos también están disponibles para los tipos `bytes` y `bytearray`. Estos dos tipos tienen, además, los siguientes métodos que no tiene `str`:

| Función | Descripción |
|:-------:|:------------|
| `B.decode(encoding='utf-8', errors='strict')` | Decodifica una cadena de bytes a una cadena de texto, utilizando una codificación y una política de gestión de los errores. |
| `B.hex()`<br/>`B.hex(C)`<br/>`B.hex(C,N)` | Transforma una cadena de bytes `B` a una cadena de texto con un número hexadecimal, donde `C` es el carácter separador utilizado entre grupos de bytes y `N` el número de bytes en cada grupo. Por defecto, `S` es una cadena vacía y `N` es `1`. |
| `bytes.fromhex(S)` | Convierte la cadena de texto `S`, que contiene números hexadecimales, en una cadena de bytes. Los espacios en blanco son ignorados para la transformación. En caso de error se lanza un `ValueError`. |

Finalmente, el tipo `bytearray` tiene los siguientes métodos, que no tienen `str` y `bytes` por ser inmutables:

| Función | Descripción |
|:-------:|:------------|
| `B.append(X)` | Añade `X` al final de la cadena. |
| `B.clear()` | Elimina todos los elementos de la cadena. |
| `B.copy()` | Copia *superficial* de la cadena. |
| `B.extend(I)` | Añade el contenido del iterador `I` al final de la cadena. |
| `B.insert(i,X)` | Inserta `X` en la posición `i` de la cadena. |
| `B.pop()`<br/>`B.pop(i)` | Elimina el elemento en la posición `i` de la cadena y lo devuelve como resultado. Por defecto, `i` es `-1`. |
| `B.remove(X)` | Elimina la primera aparición de `X` en la cadena. Si no se encuentra `X` se lanza un `ValueError`. |
| `B.reverse()` | Invierte el orden de los elementos de la cadena. |

## Tuplas

Las tuplas son estructuras cuyos elementos, llamados componentes, tienen un orden fijo. Son estructuras de datos secuenciales e inmutables en Python, que pertenecen al tipo `tuple`. Las componentes no tienen un nombre asociado a ellas, pero sí una posición de índice. Para definir una tupla se usa la siguiente sintaxis:

$$\texttt{(} \textcolor{red}{[} \mathit{expresi\acute{o}n_1} \texttt{,} \textcolor{red}{[} \mathit{expresi\acute{o}n_2} \textcolor{red}{[} \texttt{,} \textcolor{red}{\dots} \texttt{,} \mathit{expresi\acute{o}n_n} \textcolor{red}{]} \textcolor{red}{]} \textcolor{red}{]} \texttt{)}$$

Es decir, que `()` es la tupla vacía, `(1,)` la tupla con una componente, `(1,2)` la tupla con dos componentes y así sucesivamente. Nótese que hace falta dejar la coma, para el caso de una componente, o se tomarán los paréntesis como el operador `(` `)`. Se pueden anidar otras estructuras dentro de las tuplas, así como otras tuplas también.

> En ocasiones se puede definir una tupla sin usar los paréntesis, como es el caso de la asignación con `=` o el retorno de una función con `return` o `yield`.

También se puede utilizar la función constructora `tuple(I)` para construir nuevas instancias, donde `I` es un iterador, que se trata de un tipo de objeto que recorre el contenido de un objeto contenedor. Por ejemplo, `tuple('abc')` dará como resultado el valor `('a','b','c')`.

En cuanto a las operaciones que podemos realizar con tuplas, están explicadas en la sección sobre *operaciones con secuencias*. No obstante hay dos métodos de la clase `tuple` a tener en cuenta:

| Función | Descripción |
|:-------:|:------------|
| `T.count(X)` | Devuelve el número de veces que encuentra `X` en el contenedor. |
| `T.index(X)`<br/>`T.index(X,i)`<br/>`T.index(X,i,j)` | Devuelve la posición de la primera aparición de `X` en el contenedor, entre las posiciones `i` y `j-1`. Por defecto, `i` es `0` y `j` un valor superior al tamaño del contenedor. Si no se encuentra `X` se lanza un `ValueError`. |

## Listas

Las listas son estructuras secuenciales cuyos elementos tienen un orden definido. En el caso de Python las listas son mutables y pertenecen al tipo `list`. Sus elementos son accesibles mediante una posición de índice. Para definir una lista se usa la siguiente sintaxis:

$$\texttt{[} \textcolor{red}{[} \mathit{expresi\acute{o}n_1} \textcolor{red}{[} \texttt{,} \textcolor{red}{\dots} \texttt{,} \mathit{expresi\acute{o}n_n} \textcolor{red}{]} \textcolor{red}{]} \textcolor{red}{]} \texttt{]}$$

Donde `[]` es la lista vacía y el resto son listas con un tamaño arbitrario de elementos. Se pueden anidar otras estructuras dentro de las listas, así como otras listas también. Además, se puede utilizar la función constructora `list(I)` para construir nuevas instancias, donde `I` es un iterador, como ocurría con el caso de las tuplas. Por ejemplo, `list('abc')` dará como resultado el valor `['a','b','c']`.

Una sintaxis alternativa, para definir listas, son las *listas intensionales* que tienen la siguiente sintaxis:

$$\texttt{[} \mathit{expresi\acute{o}n}\ \texttt{for}\ \mathit{patr\acute{o}n_1}\ \texttt{in}\ \mathit{iterador_1}\ \textcolor{red}{[} \texttt{if}\ \mathit{condici\acute{o}n_1} \textcolor{red}{]}$$

$$\qquad\quad\ \ \textcolor{red}{[}\ \textcolor{red}{\dots}\ \texttt{for}\ \mathit{patr\acute{o}n_n}\ \texttt{in}\ \mathit{iterador_n}\ \textcolor{red}{[} \texttt{if}\ \mathit{condici\acute{o}n_n} \textcolor{red}{]} \textcolor{red}{]} \texttt{]}$$

De este modo, podemos construir listas a partir de otros contenedores, mediante el [producto cartesiano](https://es.wikipedia.org/wiki/Producto_cartesiano). Para ello, tomamos un *iterador* y ajustamos cada elemento del mismo a un *patrón* (una variable o composición estructurada de variables), y opcionalmente podemos pedir que estos elementos cumplan una *condición*. Con el resultado del producto cartesiano de todos los elementos, que hayan cumplido las condiciones indicadas, construimos una *expresión* que conformará cada elemento de la lista final. Por ejemplo:

```Python
>>> [(a, b) for a in range(1, 7) if a % 2 != 0
...         for b in range(1, 7) if b % 2 == 0]
[(1, 2), (1, 4), (1, 6),
 (3, 2), (3, 4), (3, 6),
 (5, 2), (5, 4), (5, 6)]
```

Aquí estamos agrupando en tuplas lo tres primeros números impares, con los tres primeros pares. Para ello usamos la función `range(i,j)` que devuelve un iterador con números de `i` hasta `j-1`. La función `range` se verá mejor en la sección *sentencias de control*.

En cuanto a las operaciones que podemos realizar con listas, están explicadas en la sección sobre *operaciones con secuencias*. No obstante hay algunos métodos de la clase `list` a tener en cuenta:

| Función | Descripción |
|:-------:|:------------|
| `L.append(X)` | Añade `X` al final del contenedor. |
| `L.clear()` | Elimina todos los elementos del contenedor. |
| `L.copy()` | Copia *superficial* del contenedor. |
| `L.count(X)` | Devuelve el número de veces que encuentra `X` en el contenedor. |
| `L.extend(I)` | Añade el contenido del iterador `I` al final del contenedor. |
| `L.index(X)`<br/>`L.index(X,i)`<br/>`L.index(X,i,j)` | Devuelve la posición de la primera aparición de `X` en el contenedor, entre las posiciones `i` y `j-1`. Por defecto, `i` es `0` y `j` un valor superior al tamaño del contenedor. Si no se encuentra `X` se lanza un `ValueError`. |
| `L.insert(i,X)` | Inserta `X` en la posición `i` del contenedor. |
| `L.pop()`<br/>`L.pop(i)` | Elimina el elemento en la posición `i` del contenedor y lo devuelve como resultado. Por defecto, `i` es `-1`. |
| `L.remove(X)` | Elimina la primera aparición de `X` en el contenedor. Si no se encuentra `X` se lanza un `ValueError`. |
| `L.reverse()` | Invierte el orden de los elementos del contenedor. |
| `L.sort(key=None, reverse=False)` | Ordena el contenido del contenedor, donde `key` es una función de un parámetro (usada habitualmente para devolver la clave a usar para la ordenación dentro de una estructura) y `reverse` es un *flag* para indicar si se ha de ordenar en sentido inverso o no. |

## Iteradores y generadores

Un iterador es un tipo de objeto cuyo propósito es el de recorrer el contenido de un contenedor de datos. Para ello hay dos funciones básicas:

| Función | Descripción |
|:-------:|:------------|
| `iter(X)` | Devuelve un iterador para el objeto `X`, siempre que su clase tenga implementada la interfaz para la iteración. |
| `next(I)` | Devuelve el elemento actual y sitúa el iterador en el siguiente elemento. Si no quedan más elementos que recorrer, se lanza un `StopIteration`. |

Por ejemplo:

```Python
>>> v = iter("abc")
>>> next(v)
'a'
>>> next(v)
'b'
```

Aquellos tipos que son iterables, no hace falta llamar a la función `iter` cuando se usa después de un `in`, porque el propio interprete es capaz de deducir que ha de obtener el iterador del contenedor sin indicarlo.

> Téngase en cuenta que un iterador sólo avanza en una dirección. Una vez llega al final del contenedor, se terminó el recorrido y no queda nada más que hacer con el iterador. En este caso, para volver a recorrer el contenedor, haría falta crear un nuevo iterador a partir del contenedor.

Otro elemento iterable que existe en el lenguaje son los generadores, que tienen la siguiente sintaxis:

$$\texttt{(} \mathit{expresi\acute{o}n}\ \texttt{for}\ \mathit{patr\acute{o}n_1}\ \texttt{in}\ \mathit{iterador_1}\ \textcolor{red}{[} \texttt{if}\ \mathit{condici\acute{o}n_1} \textcolor{red}{]}$$

$$\qquad\quad\ \ \textcolor{red}{[}\ \textcolor{red}{\dots}\ \texttt{for}\ \mathit{patr\acute{o}n_n}\ \texttt{in}\ \mathit{iterador_n}\ \textcolor{red}{[} \texttt{if}\ \mathit{condici\acute{o}n_n} \textcolor{red}{]} \textcolor{red}{]} \texttt{)}$$

Realmente, una lista intensional, es un generador definido entre corchetes. Sería lo mismo que definir un generador como argumento de la función constructora `list`:

```Python
>>> lista = [1, 2, 3, 4]
>>> [x * 2 for x in lista]
[2, 4, 6, 8]
>>> list(x * 2 for x in lista)
[2, 4, 6, 8]
```

Los generadores no dejan de ser instancias del tipo [`generator`](https://docs.python.org/3/reference/expressions.html#generator-iterator-methods) y que implementan la interfaz para la iteración. Por ejemplo:

```Python
>>> g = (x * 2 for x in [1, 2, 3])
>>> type(g)
<class 'generator'>
>>> next(g)
2
>>> next(g)
4
>>> next(g)
6
>>> next(g)
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
StopIteration
```

Como se puede ver, primero se crea un generador usando los paréntesis para delimitarlo. A continuación, con `type` obtenemos cuál es el tipo para una expresión, que en este caso es que `g` es de tipo clase `generator`. Después se va iterando, mediante la función `next`, hasta que se obtiene la excepción `StopIteration`, porque se ha llegado al final del recorrido.

## Operaciones con secuencias

Hemos visto varios tipos de estructuras secuenciales: `str`, `bytes`, `bytearray`, `tuple` y `list`. Se pueden usar los siguientes operadores y funciones con todas ellas:

| Operación | Descripción |
|:---------:|:-----------:|
| `X in S` | `X` existe en `S`. |
| `X not in S` | `X` no existe en `S`. |
| `S1 + S2` | `S1` y `S2` concatenadas. |
| `S * N`<br/>`N * S` | `S` repetida `N` veces. |
| `S[i]` | Elemento en la posición `i` de `S`. |
| `S[i:j]` | Elementos desde `i` hasta `j-1` de `S`. |
| `S[i:j:k]` | Elementos desde `i`, con saltos de `k` unidades, hasta `j-1` de `S`. |
| `S[i:]` | Elementos desde `i` hasta el final de `S`. |
| `S[:j]` | Elementos desde cero hasta `j-1` de `S`. |
| `S[:]` | Copia *superficial* de `S`. |
| `len(S)` | Número de elementos de `S`. |
| `max(S)` | Elemento máximo de `S`. |
| `min(S)` | Elemento mínimo de `S`. |
| `iter(S)` | Iterador de `S`. |
| `map(F,S)` | Aplica `F` a cada elemento de `S`. |

El operador de acceso con índices en Python es muy versátil. Si un contenedor `S` tiene `N` elementos, los índices que podremos usar para acceder a su contenido serán los valores del `0` hasta `N-1`. Adicionalmente, si usamos valores negativos, accederemos desde el último elemento hasta el inicio, siendo `-1` el último elemento de `S`, `-2` el penúltimo y así sucesivamente. Si intentamos acceder a un elemento fuera de los límites, se lanza como error un `IndexError`.

En el caso de acceder manejando rangos, si indicamos uno fuera de los límites de `S`, se devolverá un contenedor vacío. Si indicamos un rango que comienza en una `i` dentro del tamaño de `S` y una `j` en el exterior, se nos devolverán los elementos de `S` que hay desde `i` hasta el final del contenedor, sin que se produzca ningún error.

Téngase en cuenta que, todas aquellas operaciones que devuelven como resultado un contenedor, están devolviendo uno nuevo con los elementos copiados. Por ejemplo:

```Python
# Fichero: copias.py
s1 = [1, 2, 3, 4, 5, 6]
s2 = s1[:4]
s2[1] = 'due'
print(s1)
print(s2)
```

```
$ python copias.py
[1, 2, 3, 4, 5, 6]
[1, 'due', 3, 4]
```

Como se puede ver, tenemos una instancia del tipo lista en `S1` y, al seleccionar los cuatro primeros elementos de esta, se crea una instancia nueva del tipo lista en `S2` con una copia del contenido de `S1`. Perfecto, ¿no? Sí, pero no. Hay que recordar que las variables en Python manejan referencias y no valores directamente. Por ejemplo:

```Python
# Fichero: copias.py
s1 = [[1, 2], [3, 4], [5, 6]]
s2 = s1[:2]
s2[0][1] = "O_O"
print(s1)
print(s2)
```

```
$ python copias.py
[[1, 'O_O'], [3, 4], [5, 6]]
[[1, 'O_O'], [3, 4]]
```

Efectivamente `S2` es una copia de `S1`, siendo instancias distintas, pero el primer elemento de ambas apuntan al mismo objeto en memoria. Por ello, si se modifica dicho objeto desde uno de los contenedores, se verá también afectado el otro. Para poder hacer una copia profunda, en caso de ser necesario, existe la función [`copy.deepcopy`](https://docs.python.org/3/library/copy.html).

De las estructuras secuenciales que existen, sólo `bytearray` y `list` son mutables, y por lo tanto el resto son inmutables. Teniendo en cuenta esto, los siguientes operadores y funciones se pueden usar con contenedores mutables:

| Operación | Descripción |
|:---------:|:-----------:|
| `S[i] = X` | Modifica con `X` el elemento en la posición `i` de `S`. |
| `S[i:j] = I` | Sustituye el segmento desde `i` hasta `j-1` de `S` con el contenido del iterador `I`. |
| `S[i:j:k] = I` | Sustituye los elementos desde `i`, con saltos de `k` unidades, hasta `j-1` de `S` con el contenido del iterador `I`. Si el tamaño del rango indicado y de `I` no son iguales, se lanza un `ValueError`. |
| `S[i:] = I` | Sustituye el segmento desde `i` hasta el final de `S` con el contenido del iterador `I`. |
| `S[:j] = I` | Sustituye el segmento desde cero hasta `j-1` de `S` con el contenido del iterador `I`. |
| `S[:] = I` | Sustituye el contenido de `S` con el contenido del iterador `I`. |
| `del S[i]` | Elimina el elemento en la posición `i` de `S`. |
| `del S[i:j]` | Elimina los elementos desde `i` hasta `j-1` de `S`. |
| `del S[i:j:k]` | Elimina los elementos desde `i`, con saltos de `k` unidades, hasta `j-1` de `S`. |
| `del S[i:]` | Elimina los elementos desde `i` hasta el final de `S`. |
| `del S[:j]` | Elimina los elementos desde cero hasta `j-1` de `S`. |
| `del S[:]` | Elimina el contenido de `S`. |

En general, la sustitución del contenido de `S` por el de un iterador `I`, consiste en borrar el segmento indicado en `S` e insertar los valores de `I` en el hueco. La excepción es al usar `S[i:j:k] = I`, ya que no hay una forma clara de resolver esa situación, cuando no coinciden en tamaño el número de elementos a modificar, porque en este caso no se trata de un segmento sino de elementos salteados y por lo tanto hay que ir modificando uno a uno.

> Otras operaciones que se pueden realizar con contenedores mutables y operadores de *slicing* son:
> + `S[len(L):] = I` equivale a usar el método `S.extend(I)`.
> + `L[:0] = I` inserta al inicio del contenedor el contenido del iterador.
> + `L[i:i] = [X]` equivale a usar el método `L.insert(i,X)`, por lo tanto, `L[i:i] = I` inserta en la posición `i` el contenido del iterador.

## Diccionarios

Los diccionarios son estructuras, con forma de conjunto, que relacionan una clave con un valor. En el caso de Python los diccionarios son mutables y pertenecen al tipo `dict`. Sus elementos son accesibles mediante una clave. Para definir un diccionario se usan las siguientes formas:

$$\texttt{\char123} \textcolor{red}{[} \mathit{clave_1} \texttt{:} \mathit{expresi\acute{o}n_1} \textcolor{red}{[} \texttt{,} \textcolor{red}{\dots} \texttt{,} \mathit{clave_n} \texttt{:} \mathit{expresi\acute{o}n_n} \textcolor{red}{]} \textcolor{red}{]} \textcolor{red}{]} \texttt{\char125}$$

$$\texttt{dict(} \textcolor{red}{[} \mathit{clave_1} \texttt{=} \mathit{expresi\acute{o}n_1} \textcolor{red}{[} \texttt{,} \textcolor{red}{\dots} \texttt{,} \mathit{clave_n} \texttt{=} \mathit{expresi\acute{o}n_n} \textcolor{red}{]} \textcolor{red}{]} \textcolor{red}{]} \texttt{)}$$

$$\texttt{dict([} \texttt{[} \mathit{clave_1} \texttt{,} \mathit{expresi\acute{o}n_1} \texttt{]} \textcolor{red}{[} \texttt{,} \textcolor{red}{\dots} \texttt{,} \texttt{[} \mathit{clave_n} \texttt{,} \mathit{expresi\acute{o}n_n} \texttt{]} \textcolor{red}{]} \textcolor{red}{]} \texttt{])}$$

Donde `[]` y `dict()` son el diccionario vacío y el resto son diccionarios con un tamaño arbitrario de elementos.

> La clave en un diccionario es un valor también. Es habitual usar una cadena de texto para dar nombre a la clave, por ejemplo, `{'edad':21}`. Para hacer lo mismo con `dict`, siempre que el nombre pueda ajustarse a un identificador de Python, sería con `dict(edad=21)`.

También existe como alternativa el uso de generadores, para crear diccionarios intensionales con la siguiente sintaxis:

$$\texttt{\char123} \mathit{expresi\acute{o}n_c} \texttt{:} \mathit{expresi\acute{o}n_v}\ \texttt{for}\ \mathit{patr\acute{o}n_1}\ \texttt{in}\ \mathit{iterador_1}\ \textcolor{red}{[} \texttt{if}\ \mathit{condici\acute{o}n_1} \textcolor{red}{]}$$

$$\qquad\qquad\qquad\qquad\quad \textcolor{red}{[}\ \textcolor{red}{\dots}\ \texttt{for}\ \mathit{patr\acute{o}n_n}\ \texttt{in}\ \mathit{iterador_n}\ \textcolor{red}{[} \texttt{if}\ \mathit{condici\acute{o}n_n} \textcolor{red}{]} \textcolor{red}{]} \texttt{\char125}$$

En cuanto a las operaciones que podemos realizar con diccionarios, tenemos los siguientes operadores y funciones:

| Operación | Descripción |
|:---------:|:-----------:|
| `D[K]` | Devuelve el valor asociado a la clave `K` en `D`. |
| `D[K] = X` | Asocia el valor `X` a la clave `K` en `D`. |
| `del D[K]` | Elimina la entrada con la clave `K` en `D`. |
| `D | D2` | Añade el contenido de `D2` a `D`. |
| `K in D` | Comprueba si la clave `K` existe en `D`. |
| `K not in D` | Comprueba si la clave `K` no existe en `D`. |
| `len(D)` | Número de elementos de `D`. |
| `iter(D)` | Iterador de las claves de `D`. |

> Si se intenta acceder a una clave, que no existe en un diccionario, se lanzará un `KeyError`.

En cuanto a los métodos de la clase `dict`, tenemos los siguientes:

| Operación | Descripción |
|:---------:|:------------|
| `D.keys()` | Devuelve un iterador para recorrer las claves del diccionario. |
| `D.values()` | Devuelve un iterador para recorrer los valores del diccionario. |
| `D.items()` | Devuelve un iterador para recorrer los elementos `(clave,valor)` del diccionario. |
| `D.clear()` | Borra el contenido del diccionario. |
| `D.copy()` | Copia *superficial* del diccionario. |
| `D.update(D2)` | Añade el contenido de `D2` al diccionario. Si existen la clave a añadir, se actualiza el valor asociado por el de `D2`. |
| `D.get(K)`<br/>`D.get(K,X)` | Devuelve el valor asociado a la clave `K` en `D`. El argumento `X` actúa como valor por defecto si `K` no existe, si no se indica un valor `X`, se lanza un `KeyError`. |
| `D.setdefault(K)`<br/>`D.setdefault(K,X)` | Devuelve el valor asociado a la clave `K` en `D`. Si no existe `K`, crea una nueva entrada en `D` y le asigna el valor `X`, que por defecto es `None`. |
| `D.popitem()` | Elimina un elemento arbitrario en `D` y lo devuelve como un resultado `(clave,valor)`. Si el diccionario está vacío, se lanza un `KeyError`. |
| `D.pop(K)`<br/>`D.pop(K,X)` | Elimina la entrada con la clave `K` en `D` y devuelve el valor asociado. Si no existe `K`, devuelve `X` como valor asociado, si no se indica un valor `X`, se lanza un `KeyError`. |
| `dict.fromkeys(I)`<br/>`dict.fromkeys(I,X)` | Crea un diccionario que tiene como claves los valores obtenidos con el iterador `I` y le asigna como valor `X`. que por defecto es `None`. |

## Conjuntos

Los conjuntos son estructuras que contienen una serie de elementos sin orden fijo, ni duplicados. En el caso de Python los conjuntos son mutables y pertenecen al tipo `set`. Para definir un conjunto se usa la siguiente sintaxis:

$$\texttt{\char123} \mathit{expresi\acute{o}n_1} \textcolor{red}{[} \texttt{,} \textcolor{red}{\dots} \texttt{,} \mathit{expresi\acute{o}n_n} \textcolor{red}{]} \textcolor{red}{]} \texttt{\char125}$$

Donde `set()` es el conjunto vacío y el resto son conjuntos con un tamaño arbitrario de elementos. También existe como alternativa el uso de generadores, para crear conjuntos intensionales con la siguiente sintaxis:

$$\texttt{\char123} \mathit{expresi\acute{o}n}\ \texttt{for}\ \mathit{patr\acute{o}n_1}\ \texttt{in}\ \mathit{iterador_1}\ \textcolor{red}{[} \texttt{if}\ \mathit{condici\acute{o}n_1} \textcolor{red}{]}$$

$$\qquad\quad\ \ \textcolor{red}{[}\ \textcolor{red}{\dots}\ \texttt{for}\ \mathit{patr\acute{o}n_n}\ \texttt{in}\ \mathit{iterador_n}\ \textcolor{red}{[} \texttt{if}\ \mathit{condici\acute{o}n_n} \textcolor{red}{]} \textcolor{red}{]} \texttt{\char125}$$

Además, se puede utilizar la función constructora `set(I)` para construir nuevas instancias, donde `I` es un iterador. Por ejemplo, `set('abc')` dará como resultado el valor `{'a','b','c'}`. Y si queremos tener conjuntos inmutables tenemos el tipo `frozenset`, que tiene la función constructora `frozenset(I)`, donde `I` es un iterador.

En cuanto a las operaciones que podemos realizar con conjuntos, tenemos los siguientes operadores y funciones:

| Operación | Descripción |
|:---------:|:-----------:|
| `X in S` | `X` pertenece a `S`. |
| `X not in S` | `X` no pertenece a `S`. |
| `S1 <= S2`  | `S1` es subconjunto de `S2`. |
| `S1 < S2`   | `S1` es subconjunto de `S2` y distintos. |
| `S1 >= S2`  | `S1` es superconjunto de `S2`. |
| `S1 > S2`   | `S1` es superconjunto de `S2` y distintos. |
| `S1 - S2` | [Diferencia](https://es.wikipedia.org/wiki/Diferencia_de_conjuntos) de `S1` con `S2`. |
| `S1 | S2` | [Unión](https://es.wikipedia.org/wiki/Uni%C3%B3n_de_conjuntos) de `S1` con `S2`. |
| `S1 & S2` | [Intersección](https://es.wikipedia.org/wiki/Intersecci%C3%B3n_de_conjuntos) de `S1` con `S2`. |
| `S1 ^ S2` | [Diferencia simétrica](https://es.wikipedia.org/wiki/Diferencia_sim%C3%A9trica) de `S1` con `S2`. |
| `len(S)` | Número de elementos de `S`. |

En cuanto a los métodos de la clase `set`, tenemos los siguientes:

| Operación | Descripción |
|:---------:|:------------|
| `S.add(X)` | Añade el elemento `X` al conjunto. |
| `S.discard(X)` | Elimina el elemento `X` del conjunto si existe. |
| `S.remove(X)` | Elimina el elemento `X` del conjunto. Si no existe, se lanza un `KeyError`. |
| `S.pop()` | Elimina un elemento arbitrario del conjunto y lo devuelve como un resultado. Si el conjunto está vacío, se lanza un `KeyError`. |
| `S.clear()` | Borra el contenido del conjunto . |
| `S.copy()` | Copia *superficial* del conjunto . |
| `S.isdisjoint(S2)` | Comprueba que no existan elementos en común entre conjuntos. |
| `S.issubset(S2)` | Comprueba que `S` es subconjunto de `S2`. Equivale a `S <= S2`. |
| `S.issuperset(S2)` | Comprueba que `S` es superconjunto de `S2`. Equivale a `S >= S2`. |
| `S.union(*SS)` | Devuelve la unión de `S` con todos los conjuntos que hay en `*SS`. Equivale a `S | S1 | ... | SN`, donde `*SS` es `S1,...,SN`. |
| `S.update(*SS)` | Actualiza `S` con la unión de `S` con todos los conjuntos que hay en `*SS`. Equivale a `S |= S1 | ... | SN`, donde `*SS` es `S1,...,SN`. |
| `S.intersection(*SS)` | Devuelve la intersección de `S` con todos los conjuntos que hay en `*SS`. Equivale a `S & S1 & ... & SN`, donde `*SS` es `S1,...,SN`. |
| `S.intersection_update(*SS)` | Actualiza `S` con la intersección de `S` con todos los conjuntos que hay en `*SS`. Equivale a `S &= S1 & ... & SN`, donde `*SS` es `S1,...,SN`. |
| `S.symmetric_difference(S2)` | Devuelve la diferencia simétrica de `S` con `S2`. Equivale a `S ^ S2`. |
| `S.symmetric_difference_update(S2)` | Actualiza `S` con la diferencia simétrica de `S` con `S2`. Equivale a `S ^= S2`. |
| `S.difference(*SS)` | Devuelve la diferencia de `S` con todos los conjuntos que hay en `*SS`. Equivale a `S - S1 - ... - SN`, donde `*SS` es `S1,...,SN`. |
| `S.difference_update(*SS)` | Actualiza `S` con la diferencia de `S` con todos los conjuntos que hay en `*SS`. Equivale a `S -= S1 | ... | SN`, donde `*SS` es `S1,...,SN`. |

El tipo `frozenset` no dispone de los métodos `add`, `clear`, `difference_update`, `discard`, `intersection_update`, `pop`, `remove`, `symmetric_difference_update` y `update`, pero sí tiene un método `set()` que devuelve una copia mutable de su contenido.

## Conversión de tipos

Las funciones para convertir entre tipos básicos son las siguientes:

| Función | Tipos | Descripción |
|:-------:|:-----:|:------------|
| `int(X)` | Cadena o número | Devuelve un número entero. |
| `int(S,B)` | Cadena | De cadena de texto un número entero, indicando la base del mismo con `B`. |
| `float` | Cadena o número | Devuelve un número entero real. |
| `chr(N)` | Número entero | De número entero a su valor como carácter de texto. |
| `ord(C)` | Carácter de texto | De carácter a su valor numérico entero. |
| `str(X)` | Cualquiera | Devuelve el valor del objeto como una cadena de texto. |
| `repr(X)` | Cualquiera | Devuelve la representación interna del objeto como una cadena de texto. |
| `bin(N)` | Número entero | De número a cadena de texto con el número en representación binaria. |
| `oct(N)` | Número entero | De número a cadena de texto con el número en representación octal. |
| `hex(N)` | Número entero | De número a cadena de texto con el número en representación hexadecimal. |
| `list(I)` | Iterables | De iterable a lista. |
| `tuple(I)` | Iterables | De iterable a tupla . |
| `eval(S)` | Cadena de texto | Evalúa la expresión Python de la cadena y devuelve el valor de su ejecución. |
| `''.join(IS) ` | Iterable con cadenas de texto | De iterable a cadena de texto. |

## Asignación de valores

Para asignar un valor a una variable se utiliza la sentencia `=`:

```Python
lenguaje = "Python"
```

Decimos sentencia y no operador, porque no se puede combinar con otras expresiones. A la izquierda del igual ha de ir una variable y a la derecha una expresión con el valor a asignar. En caso necesario, se puede concatenar un número arbitrario de asignaciones:

```Python
a = b = c = 123
```

Además, podemos hacer algunos ajustes de patrón con estructuras:

$$\mathit{variable_1} \textcolor{red}{[} \texttt{,} \textcolor{red}{\dots} \texttt{,} \mathit{variable_n} \textcolor{red}{]}\ \texttt{=}\ \mathit{iterador\ de\ n\ elementos}$$

$$\texttt{(} \mathit{variable_1} \textcolor{red}{[} \texttt{,} \textcolor{red}{\dots} \texttt{,} \mathit{variable_n} \textcolor{red}{]} \texttt{)}\ \texttt{=}\ \mathit{iterador\ de\ n\ elementos}$$

$$\texttt{[} \mathit{variable_1} \textcolor{red}{[} \texttt{,} \textcolor{red}{\dots} \texttt{,} \mathit{variable_n} \textcolor{red}{]} \texttt{]}\ \texttt{=}\ \mathit{iterador\ de\ n\ elementos}$$

Técnicamente hablando, las dos primeras son la misma forma, porque cuando no indicamos los paréntesis se manejan tuplas internamente. Hay que tener en cuenta, que la expresión a la derecha de la asignación, debe ser un contenedor o iterador con el mismo número de elementos que se trata de asignar, de lo contrario se lanza un `ValueError`. Veamos algunos ejemplos de asignación:

```Python
a = 1; b = 2
b, a = a, b
(c, d) = range(1, 3)
[e, f, g] = range(5, 8)
```

> En Python se puede tener varias sentencias en una misma línea utilizando el punto y coma para separarlas.

¿Qué hacer si sólo queremos extraer unos elementos del principio o del final? Podemos utilizar la notación `*variable`, para agrupar en una lista los elementos que no necesitamos separar. Por ejemplo:

```Python
a, b, *c = "hola"
# a = 'h'
# b = 'o'
# c = ['l', 'a']
*a, b, c = "hola"
# a = ['h', 'o']
# b = 'l'
# c = 'a'
a, *b, c = "hola"
# a = 'h'
# b = ['o', 'l']
# c = 'a'
```

No se puede usar más de una variable con `*` en la asignación, pues Python no sería capaz de decidir cómo repartir los elementos de un contenedor. De variables sin `*` hay que usar mínimo una, para usar esta forma, y un máximo de tantos elementos como tenga el contenedor. Por ejemplo, `a,*b=[1]` asignaría `1` a la variable `a` y `[]` a `b`.

> Otros patrones con los que se puede ajustar valores usando `*variable` son dentro de listas `[valor,*valores]` y tuplas `(valor,*valores)`. Téngase en cuenta que `*variable` agrupa valores en forma de lista y `**variable` los agrupa en forma de diccionario.
> 
> También se puede hacer el paso inverso, expandir el contenido de una lista o diccionario al asignar. Por ejemplo, si tenemos `v=[1,2,3]`, la expresión `[0,v]` da como resultado `[0,[1,2,3]]`, pero con `[0,*v]` obtendremos `[0,1,2,3]`. Lo mismo se aplica a `**variable` con los diccionarios. En la sección *definición de funciones* volveremos a ver un uso de estos mecanismos.

Existe un operador `:=` para poder asignar variables dentro de otras expresiones, es decir, no puede usarse a solas este operador, porque para eso está la sentencia de asignación, pero sí puede usarse dentro de una condición o una operación aritmética, entre muchas otras. El ejemplo más habitual sería:

```Python
if objeto := mi_función():
    print(objeto.dato)
```

Digamos que `mi_función` devuelve un valor y es asignado a la variable `objeto`. Si es una instancia no nula, suponiendo que si no se puede instanciar el tipo devolveríamos `None`, pues trabajaremos con el objeto. En este caso se accede a su atributo `dato`, como ejemplo.

También existe un conjunto de sentencias de asignación, que combinan algún operador numérico con la asignación. Son los siguientes:

| Operación | Equivalencia |
|:---------:|:-----------:|
| `X += Y` | `X = X + Y` |
| `X -= Y` | `X = X - Y` |
| `X *= Y` | `X = X * Y` |
| `X /= Y` | `X = X / Y` |
| `X //= Y` | `X = X // Y` |
| `X %= Y` | `X = X % Y` |
| `X **= Y` | `X = X ** Y` |
| `X &= Y` | `X = X & Y` |
| `X |= Y` | `X = X | Y` |
| `X ^= Y` | `X = X ^ Y` |
| `X >>= Y` | `X = X >> Y` |
| `X <<= Y` | `X = X << Y` |

## Precedencia de operadores

Esta es la precedencia, de mayor a menor, de los operadores en Python:

| Operación | Descripción |
|:---------:|:-----------:|
| `{...}` | Diccionarios y conjuntos. |
| `[...]` | Listas. |
| `(...)` | Paréntesis, tuplas y generadores. |
| `X.miembro` | Referencia a un miembro de X. |
| `X(args)` | Invocación de la función `X`. |
| `X[i:j:k]` | Selección del contenedor `X` (*slicing*). |
| `X[i]` | Indexado del contenedor `X`. |
| `await X` | Espera la evaluación de `X`. |
| `X ** Y` | `X` elevado a `Y`. |
| `~X` | [Negación](https://es.wikipedia.org/wiki/Negaci%C3%B3n_l%C3%B3gica) a nivel de bits de `X`. |
| `-X`<br/>`+X` | Negación e identidad de `X`. |
| `X * Y`<br/>`X % Y`<br/>`X / Y`<br/>`X // Y` | Multiplicación/repetición, módulo/formato, división y división entera de `X` con `Y`. |
| `X + Y`<br/>`X - Y` | Suma/concatenación y resta/[diferencia](https://es.wikipedia.org/wiki/Diferencia_de_conjuntos) de `X` con `Y`. |
| `X << Y`<br/>`X >> Y` | Desplazamiento a la izquierda o derecha `Y` bits de `X`. |
| `X & Y` | [Conjunción](https://es.wikipedia.org/wiki/Conjunci%C3%B3n_l%C3%B3gica) a nivel de bits o [intersección](https://es.wikipedia.org/wiki/Intersecci%C3%B3n_de_conjuntos) de conjuntos de `X` con `Y`. |
| `X ^ Y` | [Disyunción exclusiva](https://es.wikipedia.org/wiki/Disyunci%C3%B3n_exclusiva) a nivel de bits o [diferencia simétrica](https://es.wikipedia.org/wiki/Diferencia_sim%C3%A9trica) de conjuntos de `X` con `Y`. |
| `X | Y` | [Disyunción](https://es.wikipedia.org/wiki/Disyunci%C3%B3n_l%C3%B3gica) a nivel de bits o [unión](https://es.wikipedia.org/wiki/Uni%C3%B3n_de_conjuntos) de conjuntos de `X` con `Y`. |
| `X == Y`<br/>`X != Y` | Igualdad y desigualdad de `X` con `Y`. |
| `X < Y`<br/>`X <= Y`<br/>`X > Y`<br/>`X >= Y` | Comparación y subconjunto o superconjunto de `X` con `Y`. |
| `X is Y`<br/>`X is not Y` | Comparación de referencias con los objetos `X` e `Y`. |
| `X in Y`<br/>`X not in Y` | Pertenencia o no de `X` al contenedor `Y`. |
| `not X` | [Negación](https://es.wikipedia.org/wiki/Negaci%C3%B3n_l%C3%B3gica) lógica de `X`. |
| `X and Y` | [Conjunción](https://es.wikipedia.org/wiki/Conjunci%C3%B3n_l%C3%B3gica) lógica de `X` con `Y`, donde `Y` se evaluará si `X` es `True`. |
| `X or Y` | [Disyunción](https://es.wikipedia.org/wiki/Disyunci%C3%B3n_l%C3%B3gica) lógica de `X` con `Y`, donde `Y` se evaluará si `X` es `False`. |
| `X if Y else Z` | `X` será evaluado si `Y` es `True`, si no se evalúa `Z`. |
| `lambda args: X` | Expresión lambda. |
| `X := Y` | Asignación del valor `Y` en la variable `X`. |
| `yield X` | Generador de valores. |

> En la categoría de la multiplicación estaría el operador `@`, que la documentación de Python lo denomina como [multiplicador de matrices](https://peps.python.org/pep-0465/), aunque la biblioteca estándar no implementa este operador. Sin embargo, bibliotecas como [`numpy`](https://numpy.org/) sí que lo usan para multiplicar matrices. También existe su versión con asignación `@=`, para las clases que quieran implementar su uso.

## Formato de cadenas

### Estilo `printf`

El primer método es heredado de los tiempos de Python 2 y se utiliza el operador `%` para dar formato a cadenas, usando la sintaxis `cadena % valores`. Por ejemplo:

```Python
>>> "Banda: %s" % "Queen"
'Banda: Queen'
>>> "%s (%d)" % ("A Kind of Magic", 1986)
'A Kind of Magic (1986)'
>>> "%(d)s (%(y)d)" % {'d': "A Night at the Opera", 'y': 1975}
'A Night at the Opera (1975)'
```

Se usa la siguiente sintaxis como expresión de formato dentro de la cadena:

$$\texttt{\char37} \textcolor{red}{[} \texttt{(} \mathit{nombre} \texttt{)} \textcolor{red}{]} \textcolor{red}{[} \mathit{flag} \textcolor{red}{]} \textcolor{red}{[} \mathit{ancho} \textcolor{red}{]} \textcolor{red}{[} \texttt{.} \mathit{precisi\acute{o}n} \textcolor{red}{]} \mathit{tipo}$$

El *nombre* hace referencia a una clave dentro de un diccionario. El *flag* sirven para indicar la alineación del texto y estos son los siguientes valores:

| Valor | Alineación | Ejemplo | Resultado |
|:-----:|:----------:|:-------:|:---------:|
| ` ` | A la derecha. | `"% 4i"%(123)` | `' 123'` |
| `+` | A la derecha, mostrando el signo. | `"%+4i"%(123)` | `'+123'` |
| `-` | A la izquierda. | `"%-4i"%(123)` | `'123 '` |
| `0` | A la derecha con ceros. | `"%04i"%(123)` | `'0123'` |

El *flag* por defecto es el espacio. El *ancho* es un entero para indicar el ancho que debe ocupar el dato y se puede usar `*` para tomar el valor entero de los valores de entrada. La *precisión* es un entero para indicar el número de decimales que mostrar con un número real y también se puede usar `*` como con el *ancho*. Por último están los *tipos* de datos:

| Tipo | Descripción | Tipo | Descripción |
|:----:|:------------|:----:|:------------|
| `s` | Equivale a `str(X)`. | `f` | Número real con coma flotante. |
| `r` | Equivale a `repr(X)`. | `F` | Número real con coma flotante. |
| `c` | Carácter en `str` o `int`. | `e` | Número real con exponente. |
| `i` | Número entero. | `E` | Número real con exponente. |
| `o` | Número entero en base 8. | `g` | Opciones `f` o `e`. |
| `d` | Número entero en base 10. | `G` | Opciones `F` o `E`. |
| `x` | Número entero en base 16. | `%` | Para mostrar el carácter `%`. |
| `X` | Número entero en base 16. | | |

### Cadenas plantilla

Otro método de formato para cadenas es el tipo `Template` dentro del módulo `string`, que se inicializa con una cadena que tendrá una serie de nombres identificadores con la forma `$nombre`. De este modo, se podrá invocar al método `substitute` con un diccionario como argumento, para que lo vaya consultando para sustituir las marcas de la plantilla. Si no se encuentra, alguno de los nombres de la plantilla, se lanza un `KeyError`. Si queremos evitar este comportamiento último, está el método `safe_substitute`, que en caso de no encontrar algún nombre, en lugar de lanzar un error, se limita a no realizar la sustitución.

A continuación, un ejemplo del uso del tipo `Template`:

```Python
>>> import string
>>> t = string.Template("$song ($autor)")
>>> t.substitute({'autor': "Björk", 'song': "Human Behaviour"})
'Human Behaviour (Björk)'
>>> t.safe_substitute({'song': "Greensleeves"})
'Greensleeves ($autor)'
```

> El código `$$` sirve para indicar el carácter `$` dentro de la cadena de formato.

### Método `format`

En Python 3 se añadió el método `format` para dar formato a cadenas, usando la sintaxis `cadena.format(valores)`. Por ejemplo:

```Python
>>> "Canción: {0}".format("How soon is now?")
'Canción: How soon is now?'
>>> "{} ({}-{})".format("The Smiths", 1982, 1987)
'The Smiths (1982-1987)'
>>> "{n} -> {p}".format(n="Morrissey", p="Voz")
'Morrissey -> Voz'
```

Se usa la siguiente sintaxis como expresión de formato dentro de la cadena:

$$\texttt{\char123} \textcolor{red}{[} \mathit{\acute{\imath}ndice} \textcolor{red}{]}\ \textcolor{red}{[} \mathit{acceso} \textcolor{red}{]}\ \textcolor{red}{[} \texttt{!} \mathit{conversi\acute{o}n} \textcolor{red}{]} \textcolor{red}{[} \texttt{:} \mathit{formato} \textcolor{red}{]} \texttt{\char125}$$

El *índice* es un entero que representa la posición del dato dentro de los valores pasados como argumentos. El *acceso* consiste en un mecanismo opcional para acceder a información interna del valor, ya sea a un atributo del objeto (`.nombre`) o a un elemento de contenedor (`[índice]`). La marca de *conversión* es una de las siguientes:

| Valor | Descripción |
|:-----:|:------------|
| `s` | El dato se procesa con `str(X)`. |
| `r` | El dato se procesa con `repr(X)`. |
| `a` | El dato se procesa con `ascii(X)`. |

El valor por defecto para la *conversión* es `s`. En cuanto al *formato*, se ha de seguir la siguiente sintaxis para especificarlo:

$$\textcolor{red}{[} \textcolor{red}{[} \mathit{relleno} \textcolor{red}{]}\ \mathit{alineamiento} \textcolor{red}{]} \textcolor{red}{[} \mathit{signo} \textcolor{red}{]} \textcolor{red}{[} \texttt{z} \textcolor{red}{]} \textcolor{red}{[} \texttt{\char35} \textcolor{red}{]} \textcolor{red}{[} \texttt{0} \textcolor{red}{]} \textcolor{red}{[} \mathit{ancho} \textcolor{red}{]} \textcolor{red}{[} \texttt{,} \textcolor{red}{]} \textcolor{red}{[} \texttt{.} \mathit{precisi\acute{o}n} \textcolor{red}{]} \textcolor{red}{[} \mathit{tipo} \textcolor{red}{]}$$

El *relleno* consiste en un carácter cualquiera (exceptuando `{` y `}`) para rellenar el ancho de columna indicado con *ancho*. El *alineamiento* indica hacia dónde quedará el dato con respecto al relleno, siendo sus valores los siguientes:

| Valor | Alineación |
|:-----:|:----------:|
| `<` | Izquierda |
| `>` | Derecha |
| `^` | Centrado |
| `=` | Relleno detrás del signo |

El *signo* indica qué se debe hacer con el signo de un número:

| Valor | Descripción |
|:-----:|:-----------:|
| `+` | Se debe mostrar tanto el signo positivo como el negativo. |
| `-` | Se debe mostrar sólo el signo negativo. |
| ` ` | Se debe usar un espacio en blanco para el signo positivo y usar el signo negativo tal cual. |

La opción `z` fuerza a que el cero negativo de los números de coma flotante se muestre como positivo. La opción `#` activa la forma alternativa de representación, que depende del tipo de dato a representar. La opción `0` se usa para rellenar con ceros detrás del signo un tipo numérico en base al *ancho*. La opción `,` indica que se debe utilizar la coma como separador de millares. Existe también una opción `_`, en lugar de `,`, para insertar el guion bajo como separador de millares en números reales y enteros, pero para enteros binarios, octales y hexadecimales, la separación es en grupos de cuatro dígitos en lugar de tres.

 El *ancho* es un entero para indicar el ancho que debe ocupar el dato y se puede usar `*` para tomar el valor entero de los valores de entrada. La *precisión* es un entero para indicar el número de decimales que mostrar con un número real y también se puede usar `*` como con el *ancho*. No se puede usar la opción de *precisión* con datos que no sean números reales.

Por último están los *tipos* de datos:

| Tipo | Descripción | Tipo | Descripción |
|:----:|:------------|:----:|:------------|
| `s` | Cadena de texto. | `f` | Número real con coma flotante. |
| `c` | Carácter en `int`. | `F` | Número real con coma flotante. |
| `n` | Número con formato local. | `e` | Número real con exponente. |
| `b` | Número entero en base 2. | `E` | Número real con exponente. |
| `o` | Número entero en base 8. | `g` | Opciones `f` o `e`. |
| `d` | Número entero en base 10. | `G` | Opciones `F` o `E`. |
| `x` | Número entero en base 16. | `%` | Formato con porcentaje. |
| `X` | Número entero en base 16. | | |

Las opciones `X`, `F`, `E` y `G` mostrarán en mayúsculas cualquier elemento alfabético. Como curiosidad, el *formato* aquí definido es el que se usa como segundo parámetro de la función nativa `format`, siendo el primer parámetro el objeto a transformar en cadena de texto. 

> Para poder representar los caracteres `{` y `}`, como parte de una cadena de formato, hay que utilizar los códigos `{{` y `}}` respectivamente. Estos códigos no se pueden usar como carácter de relleno en la expresión de formato.

### Cadenas interpoladas

El último método para dar formato a cadenas son las [cadenas interpoladas](https://peps.python.org/pep-0498/), que permiten usar variables del programa dentro de cadenas. Para poder hacerlo hay que definir la cadena con el prefijo `f`, que se puede combinar con el prefijo `r` de las cadenas en bruto.  Por ejemplo:

```Python
>>> foo=2001
>>> f"Debug: {foo = }"
'Debug: foo = 2001'
```

Se usa la siguiente sintaxis como expresión de formato dentro de la cadena:

$$\texttt{\char123} \textcolor{red}{[} \mathit{expresi\acute{o}n} \textcolor{red}{]}\ \textcolor{red}{[} \texttt{=} \textcolor{red}{]}\ \textcolor{red}{[} \texttt{!} \mathit{conversi\acute{o}n} \textcolor{red}{]} \textcolor{red}{[} \texttt{:} \mathit{formato} \textcolor{red}{]} \texttt{\char125}$$

Las similitudes con el método `format` son considerables, ya que tanto la *conversión*, como el *formato*, son en principio iguales. De hecho, la implementación de `{X:formato}` equivale a `format(X,"formato")`. La única diferencia es que se puede tener expresiones de formato anidadas, pudiendo hacer cosas como `{variable:{ancho}.{precisión}}`.

La opción `=` sirve para mostrar la *expresión* seguido de un igual y por último el valor formateado. Para la opción igual, se tomará como parte de la *expresión* todo aquello que se encuentre después de `{` hasta encontrar `}`, `!` o `:`, por lo tanto será sensible a todos los espacios que haya y no será lo mismo `{a=}` que `{a = }`, por ejemplo.

En cuanto al tipo de expresiones que se pueden utilizar, la implementación actual es bastante flexible, pero existen algunas limitaciones documentadas en la [documentación oficial](https://docs.python.org/3/reference/lexical_analysis.html#f-strings). Por ejemplo, no se puede dejar una expresión vacía, y en el caso de expresiones lambda, y el uso del operador `:=`, requieren estar entre paréntesis.

## Sentencias de control

Python no tiene separador de **líneas de programa**, asume que cada nueva línea del código es una línea separada de programa si están al mismo **nivel de tabulación**. Cuando la siguiente línea tiene un nivel mayor de tabulación, puede deberse a que estamos continuando la expresión de la línea anterior o estamos iniciando un nuevo bloque de programa, porque la línea anterior era una sentencia de control especial para ello.

Para poder tener dos líneas de programa en una misma línea, se utiliza el `;` para separar las expresiones, por ejemplo, `v += 1; print(v)`. Aunque no es recomendable abusar de esta opción, para evitar que se ofusque mucho el código y se pierda claridad en su lectura.

### Usando condiciones

La sentencia `if` permite decidir si ejecutar un bloque de código en base a una condición:

$$\begin{array}{l}
\texttt{if}\ \mathit{condici\acute{o}n_1} \texttt{:}
\\[0.5em] \qquad \mathit{bloque_1}
\\[0.5em] \textcolor{red}{[} \texttt{elif}\ \mathit{condici\acute{o}n_2} \texttt{:}
\\[0.5em] \qquad \mathit{bloque_2} \textcolor{red}{]}
\\[0.5em] \qquad\qquad \textcolor{red}{\vdots}
\\[0.5em] \textcolor{red}{[} \texttt{else} \texttt{:}
\\[0.5em] \qquad \mathit{bloque_n} \textcolor{red}{]}
\end{array}$$

Con esta sentencia primero se comprueba si la *condición~1~* se cumple, si fuera así se ejecuta el *bloque~1~*, si no se cumple, se comprueba la *condición~2~* y así sucesivamente hasta que se cumpla alguna condición. Si no se cumple ninguna condición, se ejecuta el *bloque~n~*, en caso de haberse definido una sección `else`. La único requisito obligatorio es que debe haber al menos un `if`, seguido de un número arbitrario de `elif`, para finalizar con un `else` si así se desea. La sección `if` debe ir siempre al inicio y la `else` al final.

### Manejando bucles

Para repetir la ejecución de un bloque varias veces, tenemos primero la sentencia `while`, que repetirá el bloque mientras se cumpla una condición:

$$\begin{array}{l}
\texttt{while}\ \mathit{condici\acute{o}n} \texttt{:}
\\[0.5em] \qquad \mathit{bloque_1}
\\[0.5em] \textcolor{red}{[} \texttt{else} \texttt{:}
\\[0.5em] \qquad \mathit{bloque_2} \textcolor{red}{]}
\end{array}$$

Mientras se cumpla la *condición*, se ejecutará el *bloque~1~*. Cuando deje de cumplirse la *condición*, se sale del bucle y se ejecuta la sección `else` si se ha definido.

La segunda opción es la sentencia `for`, que recorre una secuencia de elementos:

$$\begin{array}{l}
\texttt{for}\ \mathit{variables}\ \texttt{in}\ \mathit{iterador} \texttt{:}
\\[0.5em] \qquad \mathit{bloque_1}
\\[0.5em] \textcolor{red}{[} \texttt{else} \texttt{:}
\\[0.5em] \qquad \mathit{bloque_2} \textcolor{red}{]}
\end{array}$$

Donde *variables* es una secuencia de variables separadas por comas. Mientras haya elementos, sobre los que iterar, se asignan los valores a las *variables* y se ejecutará el *bloque~1~*. Cuando no queden elementos, se sale del bucle y se ejecuta la sección `else` si se ha definido.

¿Qué ocurre si queremos repetir N veces un bloque? Para ello podemos usar la sentencia `for` junto a la función `range`:

$$\texttt{range(} \mathit{l\acute{\imath}mite} \texttt{)}$$

$$\texttt{range(} \mathit{inicio} \texttt{,} \mathit{l\acute{\imath}mite} \textcolor{red}{[} \texttt{,} \mathit{salto} \textcolor{red}{]} \texttt{)}$$

Esta función genera una secuencia de números que empieza desde *inicio* hasta *límite-1*, saltando las unidades indicadas en *salto*. Por defecto, el *inicio* es `0` y el *salto* es `1`. Por ejemplo:

```Python
>>> aux = ""
>>> for v in range(2, 11, 2):
...     aux += str(v) + " "
...
>>> print(aux)
2 4 6 8 10
```

La ejecución de los bucles se puede alterar con las sentencias `continue` y `break`. La primera fuerza al bucle a saltar a la siguiente iteración, mientras que la segunda termina la ejecución del bucle, saltándose la sección `else` si la hubiera. Por ejemplo:

```Python
>>> aux = ""
>>> for v in range(0, 100):
...     if v > 10: break
...     if v % 2 == 0: continue
...     aux += str(v) + " "
... else:
...     aux += "..."
...
>>> print(aux)
1 3 5 7 9
```

### Definir e invocar funciones

La sentencia `def` permite crear funciones dentro de un bloque de código, es decir, se pueden crear funciones dentro de otras funciones. La sintaxis para definir funciones es:

$$\begin{array}{l}
\texttt{def}\ \mathit{nombre} \texttt{(} \textcolor{red}{[} \mathit{par\acute{a}metro_1} \textcolor{red}{[} \texttt{,} \textcolor{red}{\dots} \texttt{,} \mathit{par\acute{a}metro_n} \textcolor{red}{]} \textcolor{red}{]} \texttt{)} \texttt{:}
\\[0.5em] \qquad \mathit{bloque}
\end{array}$$

Una función puede tener cero o más parámetros, que tendrán las siguientes formas posibles:

| Forma | Descripción |
|:-----:|:------------|
| `var` | Parámetros que reciben su valor por argumentos posicionales únicamente. Esta forma de parámetros siempre han de ir antes que el resto de formas. |
| `var=valor` | Parámetros con un valor por defecto, que reciben su valor por argumentos posicionales o con nombre. Si no se usa ningún argumento, tomará como valor el definido en `valor`. |
| `*var` | Agrupa en una tupla todos los argumentos posicionales que se encuentre a continuación. Sólo se puede definir una única vez dentro de la secuencia de parámetros. Se puede ubicar delante de parámetros con un valor por defecto. |
| `**var` | Agrupa en un diccionario un número arbitrario de argumentos con nombre. Sólo se puede definir al final y una única vez dentro de la secuencia de parámetros. |

> Existen dos marcas [especiales](https://docs.python.org/3/tutorial/controlflow.html#special-parameters) al definir los bloques de parámetros que son `/,` y `*,`. La primera marca, separa un primer bloque de parámetros que sólo permite argumentos posicionales, de un segundo bloque que permite argumentos posicionales y con nombres. El segunda marca, separa el bloque que permite argumentos posicionales y con nombres, del siguiente bloque que sólo permite argumentos con nombre. Más allá de lo esotérico de estas herramientas, es posible encontrarse con ellas al revisar funciones de la biblioteca estándar de Python y por ello es recomendable entender lo que hacen.

Todas las funciones devuelven un valor, que por defecto es el valor `None`, pero para cambiarlo por otro valor se usa la sentencia `return`, que indica el valor o secuencia de valores que se van a devolver. También se puede usar para salir arbitrariamente de una función, devolviendo `None` como resultado. Esta es su sintaxis:

$$\texttt{return}\ \textcolor{red}{[} \mathit{expresi\acute{o}n_1} \textcolor{red}{[} \texttt{,} \textcolor{red}{\dots} \texttt{,} \mathit{expresi\acute{o}n_n} \textcolor{red}{]} \textcolor{red}{]}$$

Por ejemplo:

```Python
>>> def flip(a, b):
...     return b, a
...
>>> flip(1, 2)
(2, 1)
```

Es decir, que al devolver una secuencia separada por comas, lo que realmente se devuelve es una tupla, porque es azúcar sintáctico. Obviamente podemos usar `a, b = flip(1, 2)`, como vimos en la sección de la asignación de variables.

Para invocar una función definida se usa la siguiente sintaxis:

$$\mathit{nombre} \texttt{(} \textcolor{red}{[} \mathit{argumento_1} \textcolor{red}{[} \texttt{,} \textcolor{red}{\dots} \texttt{,} \mathit{argumento_n} \textcolor{red}{]} \textcolor{red}{]} \texttt{)}$$

Donde las formas de los argumentos son las siguientes:

| Forma | Descripción |
|:-----:|:------------|
| `X` | Argumentos posicionales, que dependiendo en la posición que estén, asignan su valor al parámetro en dicha posición. |
| `var=X` | Argumentos con nombre, que asignan su valor directamente a al parámetro `var`. No pueden usarse delante de un parámetro posicional, porque Python no sabría entonces cómo organizar aquello. |
| `*X` | Inyecta una secuencia de valores como argumentos posicionales. Si tiene más valores que parámetros posicionales, se lanza un `TypeError`. |
| `**X` | Inyecta una secuencia de valores como argumentos con nombre. Se lanza un `TypeError` cuando hay una clave que no existe como nombre de parámetro en la función. |

Por ejemplo:

```Python
>>> def foo(a, b=None, *c, **d):
...     print(a, b, c, d)
...
>>> foo(123)
123 None () {}
>>> foo(1, 2, 3, 4)
1 2 (3, 4) {}
>>> foo(*[1, 2, 3, 4])
1 2 (3, 4) {}
>>> foo(a=1, b=2, c=3, d=4, e=5)
1 2 () {'c': 3, 'd': 4, 'e': 5}
>>> foo(**{'a':1, 'b':2, 'c':3, 'd':4, 'e':5})
1 2 () {'c': 3, 'd': 4, 'e': 5}
```

### Ámbito de las variables

Para declarar una variable hay dos formas: definirla como un parámetro, en funciones o clases, o asignarle un valor con la sentencia de asignación. En ambos casos, para que la variable sea creada y se pueda usar, hay que asignarle un valor primero. Con los parámetros se asigna su valor con la invocación de la función y con el resto cuando se usa la sentencia de asignación.

El lugar donde ha sido asignada, por primera vez la variable, es su ámbito. Los diferente ámbitos que hay son los módulos, las funciones y las clases. Una variable declarada en un ámbito, es accesible desde ámbitos internos sin necesitar hacer nada, pero aquí está el problema:

```Python
# Fichero: ambito.py
x = 10
print(f"{x = }")

def foo():
    x += 1
    print(f"{x = }")

foo()
```

Al intentar ejecutarlo se lanza un `UnboundLocalError`, diciéndonos que el valor de `x` no es accesible porque no ha sido inicializada. Esto ocurre porque toda asignación en Python es tomada como una declaración local de la variable asignada, por lo tanto `x` en `foo` es local al ámbito de dicha función y es una variable diferente a la `x` declarada en el ámbito del módulo. Para superar este escollo tenemos la sentencia `global`:

$$\texttt{global}\ \mathit{variable_1} \textcolor{red}{[} \texttt{,} \textcolor{red}{\dots} \texttt{,} \mathit{variable_n} \textcolor{red}{]} $$

Todas las variables que declaremos con esta sentencia, son identificadas como variables globales al módulo. Se pueden indicar variables que no hayan sido creadas todavía, aunque para usarlas haya que inicializarlas primero, que será en esa primera asignación que se creará la variable, pero se hará en el ámbito del módulo y no del local. Por ejemplo:

```Python
# Fichero: ambito.py
x = 10
print(f"{x = }")

def foo():
    global x, y
    x += 1
    y = x * 2
    print(f"{x = }")

foo()
print(f"{y = }")
```

Cuya ejecución nos muestra por pantalla:

```Python
x = 10
x = 11
y = 22
```

Pero veamos ahora qué ocurre si:

```Python
# Fichero: ambitof.py
def bar():
    x = 20
    def foo():
        global x
        x //= 10
    foo()
    print(f"bar: {x = }")

x = 10
bar()
print(f"mod: {x = }")
```

El resultado es:

```Python
bar: x = 20
mod: x = 1
```

Para modificar la `x` en `bar`, y no la global, usamos la sentencia `nonlocal`:

$$\texttt{nonlocal}\ \mathit{variable_1} \textcolor{red}{[} \texttt{,} \textcolor{red}{\dots} \texttt{,} \mathit{variable_n} \textcolor{red}{]}$$

Donde todas las variables declaradas como no locales son buscadas en los ámbitos locales más próximos, descartando el ámbito global. De ese modo tendríamos:

```Python
# Fichero: ambitof.py
def barnl():
    x = 20
    def foo():
        nonlocal x
        x //= 10
    foo()
    print(f"bnl: {x = }")

def bargl():
    x = 20
    def foo():
        global x
        x //= 10
    foo()
    print(f"bgl: {x = }")

x = 10
barnl()
print(f"mod: {x = }")
bargl()
print(f"mod: {x = }")
```

Y ahora el resultado sería:

```Python
bnl: x = 2
mod: x = 10
bgl: x = 20
mod: x = 1
```

### Selección de patrones

La sentencia `match` permite evaluar una expresión, y dependiendo del valor obtenido, decidir si ejecutar un bloque de código si el valor se ajusta a un patrón:

$$\begin{array}{l}
\texttt{match}\ \mathit{expresi\acute{o}n} \texttt{:}
\\[0.5em] \qquad \texttt{case}\ \mathit{patr\acute{o}n_1}\ \textcolor{red}{[} \texttt{if}\ \mathit{condici\acute{o}n_1} \textcolor{red}{]} \texttt{:}
\\[0.5em] \qquad\qquad \mathit{bloque_1}
\\[0.5em] \qquad\qquad\qquad \textcolor{red}{\vdots}
\\[0.5em] \qquad \texttt{case}\ \mathit{patr\acute{o}n_n}\ \textcolor{red}{[} \texttt{if}\ \mathit{condici\acute{o}n_n} \textcolor{red}{]} \texttt{:}
\\[0.5em] \qquad\qquad \mathit{bloque_n}
\end{array}$$

Este tipo de expresiones son típicas de lenguajes funcionales como [Haskell](https://es.wikipedia.org/wiki/Haskell) o [Erlang](https://es.wikipedia.org/wiki/Erlang), donde *expresión* se evalúa a un valor y se intenta ajustar con las cláusulas `case` definidas en el orden que están declaradas. El orden es importante, porque se ejecutará sólo el bloque de la primera cláusula a la que se pueda ajustar el valor. Para que se ajuste un valor a una cláusula tiene que encajar en el patrón definido y cumplirse la condición indicada si tiene la sección `if` definida. La condición de una cláusula es conocida también como guarda. Es una forma elegante y expresiva de ramificar la ejecución en un programa.

Un patrón es una definición de un valor estructurado que combina valores literales con variables, que se asignarán con los valores contenidos en el valor obtenido al evaluar la *expresión*. De modo que al ajustar el valor a un patrón, se tendrá que cumplir la igualdad con las posiciones que tengan valores literales y las que tengan variables se les tendrá que asignar los valores internos del valor que se está ajustando. Veamos ejemplos para hacernos una idea mejor:

| Categoría | Ejemplos | Descripción |
|:---------:|:--------:|:------------|
| Literales | `None`, `True`, `False`, `123`, `1.23`, `2+3j`, `"abc"`, etc. | Valores constantes de los tipos básicos `int`, `float`, `complex`, `bool`, `str`, `bytes`, etcétera. |
| Tuplas | `()`, `(a, )`, `(a, b)`, `(a, *vs)`, etc. | Tuplas de N componentes, donde cada componente es un patrón a su vez. Permite usar la notación `*vs` para agrupar en una variable varios valores, igual que en la sentencia de la asignación. |
| Listas | `[]`, `[a]`, `[a, b]`, `[a, *vs]`, etc. | Listas de N elementos, donde cada posición es un patrón a su vez. Permite usar la notación `*vs` para agrupar en una variable varios valores, igual que en la sentencia de la asignación. |
| Diccionarios | `{}`, `{"k1": a}`, `{"k1": a, "k2": b}`, etc. | Diccionarios de N o más elementos, donde cada entrada tiene la forma clave-patrón. Si el diccionario tiene más elementos, de los indicados con el patrón, se ignoran. Se puede usar la notación `**kvs`, pero no se permite la forma `**_` al ser redundante. |
| Tipos | `Tipo()`, `Tipo(a,b,c)`, `Tipo(a,n=b)`, etc. | Tipos con una serie de parámetros posicionales o con nombre, donde cada argumento especificado es un patrón con el que ajustar los miembros del objeto. |
| Miembros | `obj.miembro ` | Se usa el valor de un atributo en un objeto como patrón contra el que ajustar. |
| Enumeraciones | `Tipo.NOMBRE` | Las valores de enumeraciones requieren indicar el nombre del tipo donde han sido definidos, para evitar que la sentencia los utilice como variables que asignar. |
| Alias. | `p as v ` | Permite asignar el valor que se ajusta con el patrón `p` en la variable `v`. |
| Comodín | `_` | Se usa como una variable especial para cuando se quieren descartar valores que no se van a usar. Por ejemplo, si queremos un patrón que obtenga la cabeza de una lista, sería `[x, *_]`. |

Sobre la asignación de variables, en los parámetros con nombre (`nombre=patrón`), no se modifican los atributos del objeto, sino las variables del patrón. Del mismo modo, cuando se usa un miembro de un objeto, este no se verá modificado como ocurre con las variables sueltas.

Se pueden agrupar patrones con el operador `|` para no tener que repetir código innecesario, por ejemplo, `case None | False:`. Para más información, hay más detalles sobre los patrones soportados en la [documentación](https://docs.python.org/3/reference/compound_stmts.html) oficial y ejemplos en el [tutorial](https://docs.python.org/3/tutorial/controlflow.html) del lenguaje.

> Con los tipos `bool`, `bytearray`, `bytes`, `dict`, `float`, `frozenset`, `int`, `list`, `set`, `str` y `tuple`, si se intenta usarlos como un patrón de tipo, con sus parámetros posicionales, la implementación lo gestiona de otra forma diferente al resto de tipos.
> 
> También hay que tener en cuenta que hay funciones constructoras de tipos que no tienen parámetros posicionales, porque todos sus parámetros tienen un valor por defecto, como es el caso de `complex`. En estos casos hay que usar como patrón los parámetros con nombre, por ejemplo, `complex(real=r, imag=i)`.

### Gestión de recursos

La sentencia `with` sirve para gestionar correctamente la limpieza de recursos, como sería el caso de manejar ficheros en un programa. Su sintaxis es:

$$\begin{array}{l}
\texttt{with}\ \mathit{expresi\acute{o}n_1}\ \textcolor{red}{[} \texttt{as}\ \mathit{destino_1} \textcolor{red}{]} \textcolor{red}{[} \texttt{,} \textcolor{red}{\dots} \texttt{,} \mathit{expresi\acute{o}n_n}\ \textcolor{red}{[} \texttt{as}\ \mathit{destino_n} \textcolor{red}{]} \textcolor{red}{]} \texttt{:}
\\[0.5em] \qquad \mathit{bloque}
\end{array}$$

Se evalúa la *expresión* y se asigna su resultado al *destino*, que será una o más variables. Las instancias de los tipos que se crean, y se asignan a *destino*, tienen que implementar el protocolo de gestión de recursos, que tiene una función de entrada y una de salida al bloque. Por ejemplo, en la función de salida estará el código que cierra un fichero que esté todavía abierto.

> La sentencia `with` garantiza que si la función de entrada se ejecuta con éxito, siempre se llamará a la función de salida cuando se salga del `with`, sin importar que se haya producido un error durante la ejecución del bloque.

### Otras operaciones

La sentencia `pass` es una operación que no hace nada. Ya que no hay delimitadores de bloque en Python, esta sentencia es la única manera de definir un bloque vacío, algo que en lenguajes estilo C se haría con `{}`.

> Una forma útil de utilizar `pass` es cuando tenemos una jerarquía de clases y queremos definir una interfaz global, que las clases hijas podrán sobrescribir o no. Entonces, para evitar que las funciones de la clase padre hagan nada, se puede utilizar `pass` como cuerpo de dichos métodos. De ese modo, podemos invocar el método con seguridad en clases hijas que no necesiten sobrescribirlo.

La sentencia `del`, que hemos visto en las operaciones con estructuras de datos, sirve para eliminar elementos en la memoria. Su sintaxis es:

$$\texttt{del}\ \mathit{v\acute{\imath}ctima}$$

Donde la víctima tiene alguna de las siguientes formas:

| Forma | Descripción |
|:-----:|:------------|
| `var` | Borra una variable de la memoria. |
| `var[i]`<br/>`var[i:j]`<br/>`var[i:j:k]` | Borra elementos dentro de un contenedor. |
| `var.miembro` | Borra un atributo de un objeto. |

La sentencia `import`, carga un módulo o elementos del mismo, para poder usarlos en el módulo actual. Para ello tenemos la siguiente sintaxis:

$$\texttt{import}\ \mathit{m\acute{o}dulo_1}\ \textcolor{red}{[} \texttt{as}\ \mathit{nombre_1} \textcolor{red}{]} \textcolor{red}{[} \texttt{,} \textcolor{red}{\dots} \texttt{,} \mathit{m\acute{o}dulo_n}\ \textcolor{red}{[} \texttt{as}\ \mathit{nombre_n} \textcolor{red}{]} \textcolor{red}{]}$$

Con esta sentencia podemos cargar diferentes módulos y asignarles un nombre identificador distinto, para utilizarlos. Por ejemplo, `import foo as f` nos permite utilizar los miembros de `foo` como `f.miembro` en lugar de `foo.miembro`. Otra forma de usar elementos de otros módulos es con la siguiente sintaxis:

$$\texttt{from}\ \mathit{m\acute{o}dulo}\ \texttt{import}\ \textcolor{red}{\char123} \texttt{*} \textcolor{red}{|} \mathit{miembro_1}\ \textcolor{red}{[} \texttt{as}\ \mathit{nombre_1} \textcolor{red}{]} $$

$$\qquad\qquad\qquad\qquad\ \ \textcolor{red}{[} \texttt{,} \textcolor{red}{\dots} \texttt{,} \mathit{miembro_n}\ \textcolor{red}{[} \texttt{as}\ \mathit{nombre_n} \textcolor{red}{]} \textcolor{red}{]} \textcolor{red}{\char125}$$

Aquí tenemos que indicar el *módulo* al que queremos acceder, para seleccionar los *miembros* que queremos importar y con qué *nombres* los vamos a usar. Con la sentencia `from` no hace falta usar la notación `módulo.miembro`, porque hemos importado al ámbito del módulo actual dichos elementos. Con `*` lo que se hace es importar todos los miembros que hay en el *módulo*. Hay que tener en cuenta que puede haber problemas de colisiones de nombres si no se tiene cuidado al importar definiciones con `from`.

> Para indicar el módulo que queremos importar, se usa como notación una secuencia de nombres separados por punto, por ejemplo, `juego.datos.jugador`. Esto lo que hace es ir al directorio `juego/datos` y buscar a `jugador.py` para importarlo.

Por último, tenemos el operador `lambda`, que nos permite crear funciones anónimas con ciertas limitaciones. Esta es su sintaxis:

$$\texttt{lambda}\ \textcolor{red}{[} \mathit{var_1} \textcolor{red}{[} \texttt{,} \textcolor{red}{\dots} \texttt{,} \mathit{var_n} \textcolor{red}{]} \textcolor{red}{]} \texttt{:}\ \mathit{expresi\acute{o}n}$$

Sólo podemos definir parámetros posicionales y el cuerpo de la función es una única expresión. Es mucho menos flexible que las lambda abstracciones de otros lenguajes, pero sigue teniendo su utilidad para funciones de orden superior.

## Clases y objetos

Para definir nuevos tipos en el lenguaje se utiliza la sentencia `class`:

$$\begin{array}{l}
\texttt{class}\ \mathit{nombre} \textcolor{red}{[} \texttt{(} \mathit{tipo_1} \textcolor{red}{[} \texttt{,} \textcolor{red}{\dots} \texttt{,} \mathit{tipo_n} \textcolor{red}{]} \textcolor{red}{[} \texttt{,} \texttt{metaclass=} \mathit{tipo_m} \textcolor{red}{]} \texttt{)} \textcolor{red}{]} \texttt{:}
\\[0.5em] \qquad \mathit{bloque\ de\ definiciones}
\end{array}$$

Le damos un *nombre* a la clase, para poder identificar al tipo. Una clase puede heredar de una o varias clases, por defecto, si no se indica ninguna se hereda de `object`. La herencia nos permite acceder a definiciones de la clase padre desde la hija, así como sobrescribir cuando sea necesario alguna de las definiciones.

> Para decidir cuál es la definición que se selecciona, a la hora de buscar entre las clases padres, se utiliza el algoritmo [MRO](https://www.python.org/download/releases/2.3/mro/) para dicha búsqueda. En líneas generales, se hace un recorrido por niveles, de izquierda a derecha, para buscar los elementos en el árbol de herencia.
> 
> Entrando en más detalle, una definición se inicia su búsqueda en la clase actual. Cuando no se encuentra el elemento, se añade a una cola, en el orden que están definidos, los tipos de los que se hereda. A continuación, se toma el primer elemento en la cola donde buscar la definición, si no se encuentra se añade sus padres a la cola (descartando aquellos que ya hubieran sido añadidos previamente) y se continua el proceso tomando el siguiente candidato.

### Miembros

Supongamos, por ejemplo, la siguiente clase:

```Python
class Vector:
    def __init__(self, x=0, y=0):
        self.x = x
        self.y = y
```

Para crear una nueva instancia de la clase haremos:

```Python
>>> a = Vector(1, 2)
>>> print(a.x, a.y)
1 2
```

La notación `Tipo(args)` crea un objeto de la clase `Tipo` en la memoria e invoca su método constructor `self.__init__(args)`. Para acceder a los miembros de un objeto se usa la notación con el punto `objeto.miembro`. Pero para definir métodos, que vayan a usar las instancias de la clase `objeto.método(args)`, es necesario que exista un parámetro extra al inicio, que contendrá la referencia al objeto que invoca el método. Se recomienda llamar `self` a este parámetro, para seguir las normas de estilo del lenguaje. Por ejemplo:

```Python
class Vector:
    def __init__(self, x=0, y=0, z=0):
        self.x = x
        self.y = y
    def show(self):
        print(self.x, self.y)
```

```Python
>>> a = Vector(1, 2)
>>> a.show()
1 2
```

Los objetos en Python permiten que se puedan extender arbitrariamente, dada la naturaleza dinámica del lenguaje. Para ello se usa la notación punto `objeto.nombre`, usando el *nombre* indicado como clave para buscar en el diccionario interno asociado al objeto. Por ejemplo:

```Python
>>> a.name = "Juan"
>>> a.name
'Juan'
```

Se puede hacer con cualquier instancia, exceptuando las creadas con la clase `object`. De hecho en `__init__` es esto lo que estamos haciendo al asignar un valor a `self.x` o `self.y`.

También los módulos y los tipos tienen un diccionario interno que podremos extender, ya que son objetos en la memoria que gestiona el interprete de Python. Así que podríamos, por ejemplo, hacer lo siguiente:

```Python
>>> Vector.z = 0
>>> print(a.x, a.y, a.z)
1 2 0
>>> b = Vector(3, 4)
>>> b.z = 5
>>> print(b.x, b.y, b.z)
3 4 5
>>> print(a.x, a.y, a.z)
1 2 0
>>> Vector.z = 1
>>> print(a.x, a.y, a.z)
1 2 1
```

¿Qué ha ocurrido aquí exactamente? Primero hemos definido el atributo `z` para la clase `Vector`, modificando su diccionario interno. Cuando queremos consultar un atributo en un objeto, se busca primero en su diccionario y después en el de la clase si no se encuentra nada en la instancia. Por ello `a.z` nos devuelve el valor que hemos asignado en el diccionario de `Vector`.  Pero al asignar un valor a `b.z` no se modifica el diccionario de `Vector`, sino el del objeto `b`, y por ello `a.z` sigue valiendo cero, hasta que modificamos su valor en el diccionario del tipo.

> Los atributos almacenados en el diccionario de la clase, vienen a ser el equivalente a las variables estáticas en clases de lenguajes estilo C. Para poder acceder a un atributo estático de la clase, desde un método de un objeto, hay que usar la notación punto `Tipo.nombre`, ya que usando el nombre a secas irá a buscar la variable fuera del ámbito de la clase.

Si queremos añadir un método nuevo a un objeto, fuera de su definición, tendremos que añadirlo al diccionario de la clase. Si intentamos añadir el método al diccionario del objeto, al invocarlo nos dará como error que falta un parámetro en su invocación, porque no se está pasando la referencia al objeto como primer argumento. Por ejemplo:

```Python
>>> a.show()
1 2
>>> Vector.sum = lambda s: s.x + s.y
>>> a.sum()
3
```

### Visibilidad

¿Se puede declarar miembros privados en Python? No se puede, porque el diccionario del objeto es público y se guarda todas las variables en él. Se ofrece como mecanismo, sobre todo para evitar colisión entre los atributos de las clases padres con las hijas, la notación `__miembro` que el compilador convierte en el identificador `_Tipo__miembro`. Por ejemplo:

```Python
>>> class Foo:
...     __bar = 0
...
>>> dir(Foo)
['_Foo__bar', ...]
```

> La función `dir` sirve para consultar los miembros de cualquier elemento en memoria, sea un módulo, clase u objeto.

### Atributos especiales

Todo en Python tiene un tipo y por lo tanto se pueden crear instancias en la memoria. Algunas instancias las gestiona el programador, mientras que otras como los módulos, tipos o funciones, las gestiona el propio interprete. Hay que tener en cuenta que los módulos son instancias de la clase `module`, los tipos de `type` y las funciones de `function`. Como consecuencia de esto último, estos objetos tienen algunos atributos especiales a los que podemos acceder:

| Miembro | Tipo | Descripción |
|:-------:|:----:|:------------|
| `__doc__` | `function`<br/>`module`<br/>`type` | Documentación del objeto. |
| `__name__` | `function`<br/>`module`<br/>`type` | Nombre del objeto. |
| `__annotations__` | `function`<br/>`module`<br/>`type` | Diccionario con las anotaciones de tipos de los parámetros en las funciones o las variables en los módulos y tipos. La clave para el tipo de retorno de una función es `return`. |
| `__module__` | `function`<br/>`type` | Nombre del módulo al que pertenece la función o el tipo. |
| `__dict__` | `function`<br/>`type` | Diccionario con los atributos de la función o la clase. |
| `__qualname__` | `function` | Nombre completo del objeto, incluyendo las clases a las que pertenece la función. |
| `__defaults__` | `function` | Tupla con los valores por defecto de los parámetros posicionales o `None` si no lo tiene. |
| `__kwdefaults__` | `function` | Diccionario con los valores por defecto de los parámetros no posicionales. |
| `__globals__` | `function` | Diccionario con las variables globales para la función. (Sólo de lectura.) |
| `__closure__` | `function` | Tupla de celdas que contiene enlaces a las variables libres de la función. (Sólo de lectura.) |
| `__code__` | `function` | Objeto de código que representa el cuerpo compilado de la función. |
| `__file__` | `module` | Ruta del fichero donde está el módulo. |
| `__bases__` | `type` | Tupla con las clases de las que se hereda. |
| `__mro__` | `type` | Tupla con las clases de las que se hereda ordenadas mediante el algoritmo MRO. |

> El atributo `X.__class__` da el objeto que representa al tipo al que pertenece una instancia `X`. La función nativa `type(X)` equivale al usar este atributo.

### Métodos especiales

Existen una serie de nombres especiales a la hora de definir métodos en Python, que sirven para implementar diversos protocolos o interfaces de comportamiento. Los métodos de operaciones generales para implementar son los siguientes:

| Método | Parámetros | Descripción |
|:------:|:----------:|:------------|
| `__new__` | `(cls, ...args)` | Es un método estático que se invoca cuando se quiere crear una nueva instancia del tipo `cls`. |
| `__init__` | `(self, ...args)` | Se invoca para inicializar el objeto después de haber sido creado. También conocido como el método constructor de la clase. |
| `__del__` | `(self)` | Se invoca cuando el objeto va a ser destruido. También conocido como el método destructor de la clase. |
| `__eq__` | `(self, X)` | Equivale a `self == X`. |
| `__ne__` | `(self, X)` | Equivale a `self != X`. |
| `__lt__` | `(self, X)` | Equivale a `self < X`. |
| `__le__` | `(self, X)` | Equivale a `self <= X`. |
| `__gt__` | `(self, X)` | Equivale a `self > X`. |
| `__ge__` | `(self, X)` | Equivale a `self >= X`. |
| `__bool__` | `(self)` | Invocado por `bool(self)`, devuelve el valor booleano que representa al objeto. |
| `__str__` | `(self)` | Invocado por `str(self)`, devuelve una cadena de texto que representa al objeto. |
| `__repr__` | `(self)` | Invocado por `repr(self)`, devuelve la representación interna del objeto como una cadena de texto. |
| `__format__` | `(self, fmtspec)` | Invocado por `format(self, fmtspec)`, devuelve una cadena de texto que representa al objeto, con un formato determinado. |
| `__bytes__` | `(self)` | Invocado por `bytes(self)`, devuelve una cadena de bytes que representa al objeto. |
| `__hash__` | `(self)` | Invocado por `hash(self)`, devuelve un número entero como valor hash que representa el identificador único del objeto. Este método es invocado cuando se usa el objeto como clave para un diccionario. |
| `__call__` | `(self, ...args)` | Se invoca al usar el objeto como una llamada a función. Equivale a `self(args)`. |
| `__instancecheck__` | `(self, instance)` | Invocado por `instancecheck`, para comprobar si `instance` es una instancia de una clase. |
| `__subclasscheck__` | `(self, subclass)` | Invocado por `subclasscheck`, para comprobar si `subclass` es una subclase de una clase. |

Estos son los métodos para implementar el acceso a atributos:

| Método | Parámetros | Descripción |
|:------:|:----------:|:------------|
| `__getattribute__` | `(self, name)` | Se invoca al consultar un atributo de un objeto con `self.name`. Cuando no existe se devuelve un `AttributeError`. |
| `__getattr__` | `(self, name)` | Se invoca cuando al consultar un atributo, de un objeto con `self.name`, este no existe y `__getattribute__` ha lanzado un `AttributeError`. |
| `__setattr__` | `(self, name, value)` | Se invoca cuando se quiere asignar un valor a un atributo de un objeto con `self.name = value`. |
| `__delattr__` | `(self, name)` | Se invoca cuando se quiere eliminar un atributo de un objeto con `del self.name`. |
| `__dir__` | `(self)` | Invocado por `dir(self)`, devuelve una secuencia con todos los atributos del objeto. |

Estos son los métodos para implementar descriptores de atributos:

| Método | Parámetros | Descripción |
|:------:|:----------:|:------------|
| `__get__` | `(self, instance, owner=None)` | Se invoca cuando se consulta un descriptor con `instance.self` o `owner.self`, dependiendo de si el atributo se encuentra en una instancia de una clase o en la clase. |
| `__set__` | `(self, instance, value)` | Se invoca cuando se modifica un descriptor con `instance.self = value`. |
| `__delete__` | `(self, instance)` | Se invoca cuando se elimina un descriptor con `del instance.self`. |

Estos son los métodos para implementar contenedores de datos:

| Método | Parámetros | Descripción |
|:------:|:----------:|:------------|
| `__len__` | `(self)` | Invocado por `len(self)`, devuelve número de elementos del contenedor. |
| `__getitem__` | `(self, key)` | Invocado por `self[key]`, para consultar un elemento del contenedor. Se deberá lanzar un `TypeError` si `key` es del tipo equivocado, un `IndexError` al intentar acceder a una posición fuera de los límites, o un `KeyError` si la clave no existe en el diccionario. |
| `__setitem__` | `(self, key, value)` | Invocado por `self[key] = value`, para modificar un elemento del contenedor. Se deberá lanzar las mismas excepciones que `__getitem__`. |
| `__delitem__` | `(self, key)` | Invocado por `del self[key]`, para eliminar un elemento del contenedor. Se deberá lanzar las mismas excepciones que `__getitem__`. |
| `__missing__` | `(self, key)` | Invocado por `__getitem__`, en subclases de `dict`, cuando la clave no ha sido encontrada. |
| `__contains__` | `(self, item)` | Invocado por `item in self`, para determinar la existencia de un elemento en el contenedor. |
| `__reversed__` | `(self)` | Invocado por `reversed(self)`, para devolver una iterador que recorre el contenedor de forma inversa. |
| `__iter__` | `(self)` | Invocado por `iter(self)`, para obtener un iterador que recorre el contenedor. |
| `__next__` | `(self)` | Invocado por `next(self)`, para devolver el elemento actual y avanzar una posición el puntero del iterador actual. Se deberá lanzar un `StopIteration` cuando se invoque después de terminar el recorrido. |

Estos son los métodos para implementar tipos numéricos:

| Método | Parámetros | Descripción |
|:------:|:----------:|:------------|
| `__add__` | `(self, X)` | Equivale a `self + X`. |
| `__sub__` | `(self, X)` | Equivale a `self - X`. |
| `__mul__` | `(self, X)` | Equivale a `self * X`. |
| `__matmul__` | `(self, X)` | Equivale a `self @ X`. |
| `__truediv__` | `(self, X)` | Equivale a `self / X`. |
| `__floordiv__` | `(self, X)` | Equivale a `self // X`. |
| `__mod__` | `(self, X)` | Equivale a `self % X`. |
| `__divmod__` | `(self, X)` | Equivale a `divmod(self, X)`. |
| `__pow__` | `(self, X)`<br/>`(self, X, Y)` | Equivale a `self ** X`, `pow(self, X)` o `pow(self, X, Y)`. |
| `__lshift__` | `(self, X)` | Equivale a `self << X`. |
| `__rshift__` | `(self, X)` | Equivale a `self >> X`. |
| `__and__` | `(self, X)` | Equivale a `self & X`. |
| `__xor__` | `(self, X)` | Equivale a `self ^ X`. |
| `__or__` | `(self, X)` | Equivale a `self | X`. |
| `__radd__` | `(self, X)` | Equivale a `X + self`. |
| `__rsub__` | `(self, X)` | Equivale a `X - self`. |
| `__rmul__` | `(self, X)` | Equivale a `X * self`. |
| `__rmatmul__` | `(self, X)` | Equivale a `X @ self`. |
| `__rtruediv__` | `(self, X)` | Equivale a `X / self`. |
| `__rfloordiv__` | `(self, X)` | Equivale a `X // self`. |
| `__rmod__` | `(self, X)` | Equivale a `X % self`. |
| `__rdivmod__` | `(self, X)` | Equivale a `divmod(X, self)`. |
| `__rpow__` | `(self, X)`<br/>`(self, X, Y)` | Equivale a `X ** X`, `pow(X, self)` o `pow(X, self, Y)`. |
| `__rlshift__` | `(self, X)` | Equivale a `X << self`. |
| `__rrshift__` | `(self, X)` | Equivale a `X >> self`. |
| `__rand__` | `(self, X)` | Equivale a `X & self`. |
| `__rxor__` | `(self, X)` | Equivale a `X ^ self`. |
| `__ror__` | `(self, X)` | Equivale a `X | self`. |
| `__iadd__` | `(self, X)` | Equivale a `self += X`. |
| `__isub__` | `(self, X)` | Equivale a `self -= X`. |
| `__imul__` | `(self, X)` | Equivale a `self *= X`. |
| `__imatmul__` | `(self, X)` | Equivale a `self @= X`. |
| `__itruediv__` | `(self, X)` | Equivale a `self /= X`. |
| `__ifloordiv__` | `(self, X)` | Equivale a `self //= X`. |
| `__imod__` | `(self, X)` | Equivale a `self %= X`. |
| `__ipow__` | `(self, X)` | Equivale a `self **= X`. |
| `__ilshift__` | `(self, X)` | Equivale a `self <<= X`. |
| `__irshift__` | `(self, X)` | Equivale a `self >>= X`. |
| `__iand__` | `(self, X)` | Equivale a `self &= X`. |
| `__ixor__` | `(self, X)` | Equivale a `self ^= X`. |
| `__ior__` | `(self, X)` | Equivale a `self |= X`. |
| `__neg__` | `(self)` | Equivale a `-self`. |
| `__pos__` | `(self)` | Equivale a `+self`. |
| `__abs__` | `(self)` | Equivale a `abs(self)`. |
| `__invert__` | `(self)` | Equivale a `~self`. |
| `__complex__` | `(self)` | Equivale a `complex(self)`. |
| `__int__` | `(self)` | Equivale a `int(self)`. |
| `__float__` | `(self)` | Equivale a `float(self)`. |
| `__index__` | `(self)` | Equivale a `operator.index(self)`. |
| `__round__` | `(self)`<br/>`(self, ndigits)` | Equivale a `round(self)` o `round(self, ndigits)`. |
| `__trunc__` | `(self)` | Equivale a `math.trunc(self)`. |
| `__floor__` | `(self)` | Equivale a `math.floor(self)`. |
| `__ceil__` | `(self)` | Equivale a `math.ceil(self)`. |

> Cuando no se quiera soportar un operador determinado, es recomendable devolver el valor especial `NotImplemented`, que luego provocará una excepción de tipo `TypeError` fuera del método.

Estos son los métodos para implementar gestores de recursos:

| Método | Parámetros | Descripción |
|:------:|:----------:|:------------|
| `__enter__` | `(self)` | Se invoca al entrar en el contexto asociado al objeto manejado por la sentencia `with`. |
| `__exit__` | `(self, extype, exvalue, traceback)` | Se invoca al salir del contexto asociado al objeto. Si se sale sin ninguna excepción, los tres últimos parámetros valdrán `None`, en caso contrario, se recibe el tipo de la excepción, su valor y su pila de ejecución. |

Estos son los métodos para implementar protocolos asíncronos:

| Método | Parámetros | Descripción |
|:------:|:----------:|:------------|
| `__await__` | `(self)` | Devuelve un iterador como resultado de la espera de un resultado con `await self`. |
| `__aiter__` | `(self)` | Devuelve un iterador asíncrono con `aiter(self)`. |
| `__anext__` | `(self)` | Devuelve el valor actual y pasa al siguiente en un iterador asíncrono con `anext(self)`. El método debe ser una corrutina `async def`. |
| `__aenter__` | `(self)` | Entra en un contexto de gestión de recursos asíncrono con `async with`. El método debe ser una corrutina `async def`. |
| `__aexit__` | `(self)` | Sale de un contexto de gestión de recursos asíncrono con `async with`. El método debe ser una corrutina `async def`. |

### Herencia y polimorfismo

Las clases pueden heredar definiciones de otras clases y para acceder a ellas se utiliza el algoritmo [MRO](https://www.python.org/download/releases/2.3/mro/) descrito al inicio de la sección. Es por ello que el orden en el que se definen los padres de una clase es importante. Por ejemplo:

```Python
# Fichero: herencia.py

class Abuelos:
    def __init__(self):
        print("Los abuelos han llegado.")

    def saludar(self):
        print("¡Los abuelos saludan!")

class Padres(Abuelos):
    def __init__(self):
        super().__init__()
        print("Los padres han llegado.")

    def saludar(self):
        print("¡Los padres saludan!")

class Tíos(Abuelos):
    def __init__(self):
        super().__init__()
        print("Los tíos han llegado.")

    def saludar(self):
        print("¡Los tíos saludan!")

class Hijos(Padres, Tíos):
    def __init__(self):
        super().__init__()
        print("Los hijos han llegado.")

    def saludar(self, salsup=True):
        if salsup:
            super(Hijos, self).saludar()
        print("¡Los hijos saludan!")

    def saludos(self):
        Abuelos.saludar(self)
        Padres.saludar(self)
        Tíos.saludar(self)
        self.saludar(False)

if __name__ == "__main__":
    hijos = Hijos()
    print()
    hijos.saludar()
    print()
    hijos.saludos()
```

```
$ python herencia.py
Los abuelos han llegado.
Los tíos han llegado.
Los padres han llegado.
Los hijos han llegado.

¡Los padres saludan!
¡Los hijos saludan!

¡Los abuelos saludan!
¡Los padres saludan!
¡Los tíos saludan!
¡Los hijos saludan!
```

La función nativa `super` ayuda a seleccionar el siguiente tipo en la secuencia de herencia para la instancia de un objeto. Esta función recibe dos parámetros posibles, un tipo y una instancia, pero se pueden omitir usando `super()`, que equivale a poner `super(Hijos, self)` dentro de la clase `Hijos`. En caso de querer acceder a un método concreto, de uno de los padres, podemos usar la notación `Padre.método(self, ...)`, como es el caso de `Abuelos.saludar(self)`.

### Decoradores

Los decoradores son funciones para procesar definiciones dentro de un módulo y tienen la siguiente sintaxis:

```Python
@decorador
def nombre(args):
    # Código...
```

Que se traduce en lo siguiente:

```Python
def nombre(args):
    # Código...

nombre = decorador(nombre)
```

Se puede aplicar también a clases y a los métodos de una clase. También hay que tener en cuenta que se puede usar una función constructora de clase como decorador, aunque ello implica que dicha clase tendrá que implementar protocolos especiales para usar el objeto instanciado como una función.

Se pueden usar varios decoradores con una sola definición y también se puede tener argumentos de entrada:

```Python
@f(arg)
class NombreTipo:
    pass

@f1
@f2
def nombre_función():
    pass
```

Que se traduce en lo siguiente:

```Python
class NombreTipo:
    pass

def nombre_función():
    pass

NombreTipo = f(arg)(NombreTipo)
nombre_función = f1(f2(nombre_función))
```

La biblioteca estándar de Python trae tres funciones nativas que se pueden usar como decoradores: `classmethod`, `property` y `staticmethod`. 

| Función | Descripción |
|:-------:|:------------|
| `classmethod(F)` | Define la función `F` como un método de clase. Este tipo de métodos recibe como primer parámetro una referencia al tipo. Se puede invocar con la notación `Tipo.F()`, aunque también permite hacerlo con `objeto.F()`, ignorando el objeto para tener sólo en cuenta el tipo del mismo. |
| `property(fget=None, fset=None, fdel=None, doc=None)` | Define un atributo de clase utilizando una serie de funciones (`fget`, `fset`, `fdel`) y una cadena de documentación (`doc`). De este modo se puede redefinir cómo se accede a una variable. |
| `staticmethod(F)` | Define la función `F` como un método estático. Este tipo de métodos no recibe como primer parámetro la referencia de su invocador. Se puede invocar con la notación `Tipo.F()` y `objeto.F()`. |

Por ejemplo:

```Python
class Foo:
    bar = 0

    @staticmethod
    def inc_bar(valor):
        Foo.bar += valor

    @classmethod
    def show_bar(cls):
        print(cls.bar)

    def __init__(self, data):
        self.__data = data

    @property
    def data(self):
        """Propiedad 'data' de 'Foo'."""
        print("get data:", self.__data)
        return self.__data

    @data.setter
    def data(self, value):
        print("set data:", self.__data, "=", value)
        self.__data = value

    @data.deleter
    def data(self):
        print("del data:", self.__data)
        del self.__data
```

Usando así los métodos de clase y estáticos:

```Python
>>> Foo.show_bar()
0
>>> Foo.inc_bar(10)
>>> Foo.show_bar()
10
```

Y usando así las propiedades de un objeto:

```Python
>>> v = Foo(123)
>>> v.data
get data: 123
123
>>> v.data = 321
set data: 123 = 321
>>> del v.data
del data: 321
>>> Foo.data.__doc__
"Propiedad 'data' de 'Foo'."
```

## Errores y excepciones

Cuando se genera un error, o una situación inesperada en un algoritmo, es normal lanzar una excepción para indicar que no se ha podido realizar una operación con éxito. Esta es la sintaxis para lanzar excepciones:

$$\texttt{raise}\ \textcolor{red}{[} \mathit{excepci\acute{o}n_1}\ \textcolor{red}{[} \texttt{from}\ \mathit{excepci\acute{o}n_2} \textcolor{red}{]} \textcolor{red}{]}$$

Las *excepciones* son clases que heredan de la clase `Exception` y con la sentencia `raise` podemos lanzar una. La sección `from` sirve para encadenar varias excepciones y procesarlas conjuntamente. Con `from None` se elimina la cadena de excepciones. Los miembros destacados del tipo `Exception` son:

| Miembros | Descripción |
|:--------:|:------------|
| `Exception(*args)` | Constructor de la clase que recibe una tupla de argumentos como información descriptiva sobre las causas que han provocado la excepción. |
| `e.args` | Tupla con información descriptiva sobre las causas que han provocado la excepción. |
| `e.with_traceback(tb)` | Modifica la información sobre la pila de ejecución al generarse la excepción. |
| `e.add_note(note)` | Añade una cadena de texto `note` a la lista de notas de la excepción, para añadir más información sobre las causas que han provocado la excepción. |
| `e.__notes__` | Lista de notas de la excepción. Este atributo se crea con la primera llamada a `add_note`. |


También se pueden lanzar grupos de excepciones con `ExceptionGroup`, e incluso heredar de la misma, cuando hace falta lanzar varias excepciones a la vez. Esta clase hereda de `Exception` y sus miembros adicionales destacados son:

| Miembros | Descripción |
|:--------:|:------------|
| `ExceptionGroup(msg, excs)` | Constructor de la clase que recibe una cadena de texto `msg` y una lista de excepciones `excs`. |
| `e.message` | El mensaje de texto que describe al grupo. |
| `e.exceptions` | La lista con el grupo de excepciones. |
| `e.subgroup(cond)` | Selecciona un subgrupo de excepciones y devuelve un `ExceptionGroup` con ellas. Para seleccionar los candidatos se usa `cond`, que puede ser una función predicado, un tipo excepción o una tupla de ellos. |
| `e.split(cond)` | Devuelve una tupla `(match, rest)`, donde `match` es el resultado de `subgroup(cond)` y `rest` es un `ExceptionGroup` con el resto de excepciones que no han cumplido la condición. |
| `e.derive(excs)` | Devuelve una copia de la excepción, sustituyendo la lista con el grupo de excepciones. |

Una vez lanzada la excepción, para poder capturarla y tomar medidas, necesitamos la sentencia `try`, cuya primera variante sintáctica es:

$$\begin{array}{l}
\texttt{try} \texttt{:}
\\[0.5em] \qquad \mathit{bloque\ inicial}
\\[0.5em] \texttt{except}\ \textcolor{red}{[} \mathit{tipo_1}\ \textcolor{red}{[} \texttt{as}\ \mathit{variable_1} \textcolor{red}{]} \textcolor{red}{]} \texttt{:}
\\[0.5em] \qquad \mathit{bloque_1}
\\[0.5em] \qquad\qquad \textcolor{red}{\vdots}
\\[0.5em] \textcolor{red}{[} \texttt{except}\ \textcolor{red}{[} \mathit{tipo_n}\ \textcolor{red}{[} \texttt{as}\ \mathit{variable_n} \textcolor{red}{]} \textcolor{red}{]} \texttt{:}
\\[0.5em] \qquad \mathit{bloque_n} \textcolor{red}{]}
\\[0.5em] \textcolor{red}{[} \texttt{else} \texttt{:}
\\[0.5em] \qquad \mathit{bloque\ else} \textcolor{red}{]}
\\[0.5em] \textcolor{red}{[} \texttt{finally} \texttt{:}
\\[0.5em] \qquad \mathit{bloque\ final} \textcolor{red}{]}
\end{array}$$

Con esta forma podemos capturar excepciones sueltas de un *tipo* determinado, y acceder a su contenido mediante una *variable*, con la sección `except`. La sección `else` se ejecutará si el *bloque inicial* se ha ejecutado sin que se lance ninguna excepción. La sección `finally` se ejecutará siempre, se produzca una excepción o no. Además, también será ejecutado de forma previa, el *bloque final* de `finally`, al uso dentro del `try` de las sentencias `return`, `continue` o `break`.

La segunda variante de `try` es:

$$\begin{array}{l}
\texttt{try} \texttt{:}
\\[0.5em] \qquad \mathit{bloque\ inicial}
\\[0.5em] \texttt{except*}\ \textcolor{red}{[} \mathit{tipo_1}\ \textcolor{red}{[} \texttt{as}\ \mathit{variable_1} \textcolor{red}{]} \textcolor{red}{]} \texttt{:}
\\[0.5em] \qquad \mathit{bloque_1}
\\[0.5em] \qquad\qquad \textcolor{red}{\vdots}
\\[0.5em] \textcolor{red}{[} \texttt{except*}\ \textcolor{red}{[} \mathit{tipo_n}\ \textcolor{red}{[} \texttt{as}\ \mathit{variable_n} \textcolor{red}{]} \textcolor{red}{]} \texttt{:}
\\[0.5em] \qquad \mathit{bloque_n} \textcolor{red}{]}
\\[0.5em] \textcolor{red}{[} \texttt{else} \texttt{:}
\\[0.5em] \qquad \mathit{bloque\ else} \textcolor{red}{]}
\\[0.5em] \textcolor{red}{[} \texttt{finally} \texttt{:}
\\[0.5em] \qquad \mathit{bloque\ final} \textcolor{red}{]}
\end{array}$$

La diferencia con la primera son las secciones `except*` que permiten capturar *tipos* de excepciones que haya dentro de grupos de excepciones (`ExceptionGroup` y familia). Dependiendo de las excepciones lanzadas, se pueden llegar a ejecutar varias secciones `except*`.

La última variante de `try` es:

$$\begin{array}{l}
\texttt{try} \texttt{:}
\\[0.5em] \qquad \mathit{bloque\ inicial}
\\[0.5em] \texttt{finally} \texttt{:}
\\[0.5em] \qquad \mathit{bloque\ final}
\end{array}$$

## Manejo de ficheros

Para trabajar con ficheros se usa el tipo `file`, pero para abrir ficheros se necesita la función nativa `open`, que devuelve instancias de `file`. Usaremos la siguiente sentencia:

$$\texttt{with}\ \texttt{open(} \mathit{ruta} \texttt{,} \mathit{modo} \texttt{)}\ \texttt{as}\ \mathit{variable} \texttt{:}$$

Con esto podremos operar con el fichero en el bloque anidado dentro de la sentencia `with`, donde *variable* es la instancia del fichero abierto, *ruta* es la ubicación del fichero a manipular y *modo* es una cadena de texto que contiene el modo de apertura indicado. Las opciones disponibles para el modo de apertura son las siguientes:

| Opciones | Descripción |
|:----:|:------------|
| `r` | Modo lectura (modo por defecto). |
| `w` | Modo escritura (trunca el contenido). |
| `x` | Creación exclusiva (falla si existe). |
| `a` | Modo escritura, si existe el fichero añade el contenido al final. |
| `b` | Formato binario. |
| `t` | Formato texto. |
| `+` | Modo lectura y escritura. |

Por defecto el modo es `"r"` que abre el fichero para lectura de texto, sería lo mismo que poner `"rt"`, es decir, si no se indica el formato se asume que es de texto y no binario. Con los modos `"w+"` y `"w+b"` se trunca el contenido del fichero, pero con `"r+"` y `"r+b"` no se trunca.

> Se puede abrir un fichero usando la asignación con `v = open(ruta,modo)`, en lugar de usar la sentencia `with`, pero con este último se garantiza que, en caso de error durante la ejecución, se cerrará el objeto que ha abierto el fichero.

Estos son los métodos y atributos disponibles en la clase `file`:

| Miembro | Descripción | Resultado |
|:-------:|:------------|:----------|
| `F.read()` | Lee el contenido entero del fichero. | **t:** `str`<br/>**b:** `bytes` |
| `F.read(N)` | Lee `N` caracteres/bytes del fichero. | **t:** `str`<br/>**b:** `bytes` |
| `F.readline()` | Lee una línea del fichero. | **t:** `str` |
| `F.readlines()` | Lee las líneas del fichero. | **t:** `list` de `str` |
| `F.write(X)` | Escribe una cadena en el fichero. (Nota: En modo texto añade un `\n` al final de la cadena añadida al fichero.) | - |
| `F.writelines(X)` | Escribe una lista de cadenas en el fichero. | - |
| `F.close()` | Cierra el fichero. | - |
| `F.tell()` | Devuelve la posición actual en el fichero. | `int` |
| `F.seek(N)`<br/>`F.seek(N,M)` | Modifica la posición actual en el fichero, donde `N` es el número de posiciones que avanzar y `M` el punto de partida (`0` desde el inicio, `1` desde la posición actual, `2` desde el final). | - |
| `F.isatty()` | Comprueba si el fichero está conectado a un comando TTY. | `bool` |
| `F.flush()` | Limpia el buffer de entrada. | - |
| `F.truncate()`<br/>`F.truncate(N)` | Trunca el contenido a un tamaño de `N` bytes, que por defecto su valor es `0`. | - |
| `F.fileno()` | Devuelve el número identificador del descriptor de fichero, valor que se usa en módulos como `os`. | `int` |
| `F.closed` | Devuelve si el fichero está cerrado o no. | `bool` |
| `F.mode` | Devuelve el modo de apertura del fichero. | - |
| `F.name` | Devuelve la ruta del fichero. | - |

> Cuando el fichero se abre en modo lectura de texto, podemos utilizarlo como si fuera un iterador con `for S in F`, para ir procesando las líneas del fichero.

### Ficheros JSON

El módulo `json` permite trabajar con el formato [JSON](https://es.wikipedia.org/wiki/JSON) con las siguientes funciones:

| Función | Descripción |
|:-------:|:------------|
| `json.dump(X,F)` | Guarda en un fichero de texto `F` un valor de Python `X` convertido al formato JSON. |
| `json.dumps(X)` | Devuelve una cadena con un valor de Python `X` convertido al formato JSON. |
| `json.load(X)` | Devuelve un valor de Python obtenido de leer un fichero de texto `F` con formato JSON. |
| `json.loads(S)` | Devuelve un valor de Python obtenido de una cadena de texto `S` con formato JSON. |

Los parámetros opcionales de `dump` y `dumps` son:

| Parámetro | Descripción |
|:---------:|:------------|
| `skipkeys=False` | Con `True` se saltan aquellas claves de diccionario que no sean tipos básicos transformables (`str`, `int`, `float`, `bool`, `None`). |
| `ensure_ascii=True` | Con `True` se todos los caracteres que no sean ASCII se convierten a secuencias de escape (`\uhhhh`). |
| `check_circular=True` | Con `True` se hacen comprobaciones de referencias circulares en las estructuras, para evitar que se pueda producir un error de tipo `RecursionError`. |
| `allow_nan=True` | Con `True` se salta la especificación de JSON, permitiendo representar `nan`, `-inf` e `inf`, con sus equivalentes de JavaScript (`NaN`, `-Infinity` e `Infinity`). |
| `cls=None` | Instancia alternativa para codificar la salida en formato JSON. Por defecto se usa el tipo `json.JSONEncoder`. |
| `indent=None` | Con un número natural se indica los espacios de identación a usar para la representación final. |
| `separators=None` | Con una tupla `(isep,csep)` se indica el separador de ítems en listas y claves en objetos al generar el JSON. Por ejemplo, `(',',':')` genera una salida compacta, mientras que `(', ',': ')` sería la opción por defecto si no hay identación. |
| `default=None` | Función, que recibe un argumento, usada cuando no se puede serializar un valor de Python. Por ejemplo, con `default=lambda x:str(x)` nos convierte a cadena todo valor no serializable, en lugar de lanzar un `TypeError`. |
| `sort_keys=False` | Con `True` se las claves de los diccionarios se muestran en orden. |

Los parámetros opcionales de `load` y `loads` son:

| Parámetro | Descripción |
|:---------:|:------------|
| `cls=None` | Instancia alternativa para decodificar la entrada en formato JSON. Por defecto se usa el tipo `json.JSONDecoder`. |
| `object_hook=None` | Función para gestionar el evento de decodificar un diccionario, recibe como argumento un `dict`. |
| `parse_float=None` | Función para gestionar el evento de decodificar un número real, recibe como argumento un `float`. |
| `parse_int=None` | Función para gestionar el evento de decodificar un número entero, recibe como argumento un `int`. |
| `parse_constant=None` | Función para gestionar el evento de decodificar una constante (`NaN`, `-Infinity` e `Infinity`), recibe como argumento un `str`. |
| `object_pairs_hook=None` | Función para gestionar el evento de decodificar un diccionario, recibe como argumento un `list` con pares clave-valor. Además, esta función tendrá prioridad sobre la definida con `object_hook`. |

El tipo `JSONEncoder` codificar valores a formato JSON usando el método `encode(X)`, donde `X` es el valor a serializar. Si el tipo del valor no está soportado por el codificador, este se pasa al método `default(X)`, que por defecto lanza un `TypeError`.

El tipo `JSONDecoder` decodifica cadenas en formato JSON a valores usando el método `decode(S)`, donde `S` es una cadena de texto.

Para ampliar el comportamiento base del módulo `json`, tenemos que extenderlo de la siguiente manera:

```Python
# Fichero: jsonex.py
import json

class ComplexEncoder(json.JSONEncoder):
    def default(self, obj):
        if isinstance(obj, complex):
            return {'class': 'complex',
                    'real' : obj.real,
                    'imag' : obj.imag}
        else:
            return json.JSONEncoder.default(self, obj)

def complex_decoder(data):
    if 'class' in data and data['class'] == 'complex':
        return complex(data['real'], data['imag'])
    else:
        return data

def decode(victim):
    return json.loads(victim, object_hook=complex_decoder)

def encode(victim):
    return json.dumps(victim, cls=ComplexEncoder)

def test(victim):
    print(f"{victim    = }")
    to_json = encode(victim)
    print(f"{to_json   = }")
    from_json = decode(to_json)
    print(f"{from_json = }")
```

```Python
>>> import jsonex
>>> jsonex.test([1, 2.3, 4+5j])
victim    = [1, 2.3, (4+5j)]
to_json   = '[1, 2.3, {"class": "complex", "real": 4.0, "imag": 5.0}]'
from_json = [1, 2.3, (4+5j)]
```

En este ejemplo tomamos el tipo `complex`, que no está soportado por defecto por el módulo `json`, y creamos una clase codificadora que sobrescribe el método `default` para transformarlo a un diccionario con una forma concreta. Luego añadimos una función para gestionar diccionarios a la hora de decodificar el formato JSON.

## Concurrencia

### Ejecución "perezosa" y generadores

Python ofrece mecanismos para realizar cierto tipo de ejecución perezosa mediante la sentencia `yield`:

$$\texttt{yield}\ \textcolor{red}{\char123} \mathit{expresi\acute{o}n_1} \textcolor{red}{[} \texttt{,} \textcolor{red}{\dots} \texttt{,} \mathit{expresi\acute{o}n_n} \textcolor{red}{]} \textcolor{red}{|} \texttt{from}\ \mathit{iterador} \textcolor{red}{\char125}$$

Una función que contenga una o más sentencias `yield` se convierte en un objeto de tipo [`generator`](https://docs.python.org/3/reference/expressions.html#generator-iterator-methods), que sigue las mismas reglas que vimos en la sección de *iteradores y generadores*. Podemos lanzar una serie de valores, obtenidos por una serie de *expresiones*, o podemos ir devolviendo valores dentro de un iterador con la sección `from` de la sentencia.

Veamos un ejemplo de función generadora de valores:

```Python
>>> def nums():
...     n = 0
...     while True:
...         yield n
...         n += 1
...
>>> i = nums()
>>> i
<generator object nums at 0x0000020F>
>>> next(i)
0
>>> next(i)
1
>>> next(i)
2
```

Definimos una función `nums`, que va lanzando números enteros con `yield`. Cada vez que se invoque la función, se devuelve un objeto de tipo `generator`, que podemos recorrer con la función `next`. En este caso, el objeto generador no tiene un final y por ello nunca se lanzará un `StopIteration`.

### Corrutinas y ejecución asíncrona

Las [corrutinas](https://peps.python.org/pep-0492/) es otro mecanismo del lenguaje para gestionar la ejecución asíncrona del código. Para definir una, necesitamos definir una función como `async def`. Esto indica al compilador que se trata de un objeto de tipo [`coroutine`](https://docs.python.org/3/reference/datamodel.html#coroutines), similar a `generator`, pero sin implementar el protocolo de iteración (`__iter__` y `__next__`). Luego, dentro de las corrutinas, se puede utilizar el operador `await`, que suspende la ejecución de la función a la espera del resultado de la expresión que lo acompaña. Las expresiones que pueden acompañar a `await` han de implementar la interfaz `__await__`, por ejemplo, una instancia del tipo `coroutine` lo hace. Veamos un ejemplo:

```Python
async def foo(n):
    print(n)
    if n > 0:
        return n + await foo(n - 1)
    else:
        return 0

try:
    f = foo(5)
    f.send(None)
except StopIteration as e:
    print(e.args)
```

La variable `f` almacena la instancia de la corrutina y para ejecutarla hay que utilizar el método `send`, pasando `None` como argumento por temas de implementación. Una vez se termina de ejecutar, se lanza una excepción de tipo `StopIteration`, que tiene como argumentos el resultado devuelto por la función.

Para poder ejecutar varias corrutinas, de forma concurrente, tenemos el módulo [`asyncio`](https://docs.python.org/3/library/asyncio.html). Veamos un ejemplo parecido al anterior:

```Python
# Fichero: concurrente.py
import asyncio
import random
import sys

async def foo(id, value):
    result = 0
    while value >= 0:
        print(f"{id}: {value}")
        await asyncio.sleep(random.uniform(1,2))
        result += value
        value -= 1
    return id, result

async def bar(maxids, maxval):
    if maxids > 0:
        print("INICIO")
        random.seed()
        crs = [foo(id, maxval) for id in range(maxids)]
        [print(type(i)) for i in crs]
        print("EJECUTAR")
        results = await asyncio.gather(*crs)
        print("FINAL")
        print(f"{results = }")
    else:
        print("NADA")

def test(maxids, maxval):
    asyncio.run(bar(maxids, maxval))

if __name__ == "__main__":
    ids = 3
    val = 6

    try:
        if len(sys.argv) >= 3:
            val = int(sys.argv[2])
        if len(sys.argv) >= 2:
            ids = int(sys.argv[1])
    except:
        pass

    test(ids, val)
```

Tenemos dos corrutinas, `foo` y `bar`. La primera función suma todos los enteros desde `value` hasta `0`, haciendo una llamada asíncrona a [`asyncio.sleep`](https://docs.python.org/3/library/asyncio-task.html#asyncio.sleep), que recibe un número aleatorio de segundos entre `1` y `2`, para ejecutar un retardo que simule una operación asíncrona exterior. La segunda función configura el número de instancias de `foo` que vamos a crear y las ejecuta con [`asyncio.gather`](https://docs.python.org/3/library/asyncio-task.html#asyncio.gather) de forma concurrente, recibiendo el resultado de todas ellas en `results`. Por último, con [`asyncio.run`](https://docs.python.org/3/library/asyncio-runner.html#asyncio.run) podemos ejecutar una corrutina y recibir su resultado.

> En ocasiones puede hacer falta usar versiones asíncronas de [iteradores](https://docs.python.org/3/reference/datamodel.html#asynchronous-iterators) y [gestores de recursos](https://docs.python.org/3/reference/datamodel.html#asynchronous-context-managers). Para ello se puede modificar el comportamiento de `for` y `with` con `async for` y `async with`, que son azúcar sintáctico que permite manejar las versiones asíncronas de iteradores y gestores de recursos. Los iteradores asíncronos han de implementar los métodos especiales `__aiter__` y `__anext__`. Los gestores de recursos asíncronos han de implementar los métodos especiales `__aenter__` y `__aexit__`. Estos métodos especiales deben ser implementados como corrutinas.

Se puede utilizar `yield` dentro de una `async def`, pero en lugar de generar una instancia de corrutina, lo que genera es una instancia de un [generador asíncrono](https://peps.python.org/pep-0525/), que es de tipo `async_generator`, que es un tipo de iterador asíncrono. Por ejemplo:

```Python
>>> async def foo(n):
...     for i in range(n):
...         yield i
...
>>> async def bar(n):
...     async for i in foo(n):
...         print(i)
...
>>> asyncio.run(bar(4))
0
1
2
3
```

Aquí las instancias de `foo` serán de tipo `async_generator`, mientras que las instancias de `bar` serán de tipo `coroutine`. Con el bucle `async for` lo que se hace es instanciar `foo`, como si hiciéramos `f = foo(n)`, e invocar `anext(f).send(None)` para obtener una excepción de tipo `StopIteration`, que contiene en sus argumentos el valor que queremos asignar a `i`. Cuando ya no quedan más elementos, sobre los que iterar, se lanza una excepción de tipo `StopAsyncIteration`.

## Enumeraciones

La forma básica de crear una enumeración es de la siguiente manera:

```Python
>>> from enum import Enum
>>> class Color(Enum):
...     ROJO  = 1
...     VERDE = 2
...     AZUL  = 3
...
>>> Color.ROJO
<Color.ROJO: 1>
>>> print(Color.ROJO)
Color.ROJO
```

La clase `Enum` dentro del módulo [`enum`](https://docs.python.org/3/library/enum.html) nos permite definir enumeraciones de valores, de forma similar a otros lenguajes. Por indicaciones, de la guía de estilo del código, se recomienda poner en mayúsculas los nombres identificadores, para hacer notar que se tratan de valores constantes. También podemos hacer lo anterior, asignando valores de forma automática con la función `auto`:

```Python
>>> from enum import Enum, auto
>>> class Color(Enum):
...     ROJO  = auto()
...     VERDE = auto()
...     AZUL  = auto()
...
>>> (Color.ROJO, Color.VERDE, Color.AZUL)
(<Color.ROJO: 1>, <Color.VERDE: 2>, <Color.AZUL: 3>)
```

> Existe el decorador `@unique` para comprobar que en efecto los  valores asignados a cada identificador son únicos dentro de la enumeración, como alternativa a la función `auto()` si necesitamos usar una secuencia de valores distinta.

Las enumeraciones de tipo `Enum` sólo pueden asignar un único valor por variable. Existen variantes como `IntEnum`, `StrEnum` o `ReprEnum`, que limitan los valores a los que se puede inicializar cada identificador de la enumeración a números enteros y cadenas de texto. En caso de querer asignar a una variable una combinación de valores, haremos lo siguiente:

```Python
>>> from enum import Flag, auto
>>> class Color(Flag):
...     ROJO  = auto()
...     VERDE = auto()
...     AZUL  = auto()
...
>>> (Color.ROJO, Color.VERDE, Color.AZUL)
(<Color.ROJO: 1>, <Color.VERDE: 2>, <Color.AZUL: 4>)
>>> fucsia = Color.ROJO | Color.AZUL
>>> fucsia
<Color.ROJO|AZUL: 5>
```

El tipo `Flag` nos permite crear enumeraciones para trabajar con combinaciones de valores usando los operadores a nivel de bits (`&`, `|`, `^`, `~`). Existe `IntFlag` como variante a `Flag`, ya que este último no permite comparaciones con valores que no pertenezcan al mismo tipo de enumeración, mientras que el primero permite ser comparado con otros valores enteros. Esta diferencia también se cumple entre `IntEnum` y `Enum`. También se pueden usar los operadores a nivel de bits con `IntFlag`, para trabajar con combinaciones de valores. Los operadores de igualdad y desigualdad sí se pueden utilizar con todos los tipos de enumeración, pero tanto `Enum` como `Flag`, darán como falsa la condición `Color.ROJO == 1`, cosa que no pasaría de heredar de `IntEnum` o `IntFlag`.

Los valores en una enumeración tienen dos atributos importantes: `name` y `value`. El primero muestra el nombre identificador del valor y el segundo el valor asignado:

```Python
>>> for c in Color:
...     print(c.name, "=", c.value)
...
ROJO = 1
VERDE = 2
AZUL = 4
```

## Funciones nativas

El lenguaje Python tiene las siguientes [funciones nativas](https://docs.python.org/3/library/functions.html):

| Función | Descripción |
|:-------:|:------------|
| `abs(x)` | Da el valor absoluto del número `x`. |
| `aiter(obj)` | Da un iterador asíncrono del contenedor `obj`. |
| `all(iterable)` | Da `True` si todos los elementos del iterador son `True` (o si el contenedor está vacío). |
| `anext(iterator)`<br/>`anext(iterator, default)` | Da el siguiente elemento del iterador asíncrono, si no quedan más elementos devuelve el valor por defecto o lanza `StopAsyncIteration`. |
| `any(iterable)` | Da `True` si algún elemento del iterador es `True`. Si el contenedor está vacío devuelve `False`. |
| `ascii(obj)` | Da la cadena de texto que representa al objeto, usando secuencias de escape para los caracteres no ASCII. |
| `bin(x)` | Da la cadena de texto que representa el número entero `x` en binario. |
| `bool(x=False)` | Da el valor booleano que representa al objeto `x`. |
| `breakpoint(*args, **kws)` | Produce un punto de ruptura en la ejecución para invocar al depurador del lenguaje. |
| `bytearray(b)`<br/>`bytearray(s,e)` | Da una cadena de bytes mutable, donde `b` es una cadena de bytes, `s` es una cadena de texto y `e` es una cadena de texto con la codificación. |
| `bytes(b)`<br/>`bytes(s,e)` | Da una cadena de bytes inmutable, donde `b` es una cadena de bytes, `s` es una cadena de texto y `e` es una cadena de texto con la codificación. |
| `callable(obj)` | Da `True` si el objeto puede ser usado como una función. |
| `chr(n)` | Da el carácter Unicode que representa al número entero `n`. |
| `@classmethod` | Transforma un método en un método de clase. |
| `compile(source, filename, mode)` | Compila un fichero para devolver un objeto con el AST (árbol sintáctico abstracto) que poder ejecutar. |
| `complex(real=0, imag=0)`<br/>`complex(string)` | Construye un número complejo a partir de dos números o de una cadena. |
| `delattr(obj, name)` | Borra un atributo con nombre del objeto. |
| `dict(**kwarg)`<br/>`dict(i, /, **kwarg)` | Construye un diccionario a partir de la información recibida en los argumentos y el iterador `i`. |
| `dir()`<br/>`dir(obj)` | Da el nombre de los atributos del objeto o del ámbito local donde es invocada sin argumentos. |
| `divmod(x, y)` | Da una tupla cuyo resultado es `(x // y, x % y)`. En el caso de que sean números flotantes, la primera componente es el resultado de `math.floor(x / y)`. |
| `enumerate(iterable, start=0)` | Da una lista de tuplas, cuya primera componente es un entero (empezando por `start`) y la segunda cada elemento del iterador. |
| `eval(expression, /, globals=None, locals=None)` | Evalúa una expresión para ejecutarla y obtener su resultado. La expresión puede ser un AST o una cadena de texto con código. |
| `exec(object, globals=None, locals=None, /, *, closure=None)` | Ejecuta un objeto AST para obtener su resultado. |
| `filter(function, iterable)` | Da un iterador que filtra elementos del iterador con una función predicado. |
| `float(x=0.0)` | Construye un número real a partir de un número. |
| `format(value, format_spec='')` | Da la cadena de texto que representa a `value` con el formato especificado en `format_spec`. |
| `frozenset(iterable=set())` | Construye un conjunto inmutable a partir de un iterador. |
| `getattr(obj, name)`<br/>`getattr(obj, name, default)` | Obtiene un atributo con nombre del objeto, devolviendo un valor por defecto si no existe o lanzando un `AttributeError` si no se indica un valor por defecto. |
| `globals()` | Da un diccionario con el espacio de nombres del módulo actual. |
| `hasattr(obj, name)` | Consulta si existe un atributo con nombre en el objeto. |
| `hash(obj)` | Da el valor hash que representa al objeto. |
| `help()`<br/>`help(request)` | Invoca al sistema de ayuda nativo. |
| `hex(x)` | Da la cadena de texto que representa el número entero `x` en hexadecimal. |
| `id(obj)` | Da un número entero que sirve como identificador único de un objeto mientras esté vivo en la memoria. |
| `input()`<br/>`input(prompt)` | Pide al usuario que introduzca una cadena de texto por la terminal, mostrando el mensaje `prompt` previamente. |
| `int(x=0)`<br/>`int(x, /, base=10)` | Construye un número entero a partir de un número o una cadena de texto, indicando la base en la que está codificada. |
| `isinstance(obj, classinfo)` | Da `True` si el objeto es una instancia de la clase `classinfo`. |
| `issubclass(class, classinfo)` | Da `True` si la clase `class` es una subclase de la clase `classinfo`. |
| `iter(obj)`<br/>`iter(obj, sentinel)` | Da un iterador del contenedor `obj`. |
| `len(s)` | Da el número de elementos del contenedor `s`. |
| `list()`<br/>`list(iterable)` | Construye una lista a partir de un iterador. |
| `locals()` | Da un diccionario con la tabla de nombres local actual. |
| `map(function, iterable, /, *iterables)` | Da un iterador que aplica a los elementos del iterador una función. |
| `max(iterable, /, *, key=None)`<br/>`max(iterable, /, *, default, key=None)`<br/>`max(arg1, arg2, /, *, *args, key=None)` | Da el mayor elemento en un iterador o secuencia de argumentos. Si el iterador es vacío se lanza un `ValueError` o se devuelve `default`. La parámetro `key` será una función que recibe un elemento y devuelve el valor clave. |
| `min(iterable, /, *, key=None)`<br/>`min(iterable, /, *, default, key=None)`<br/>`min(arg1, arg2, /, *, *args, key=None)` | Da el menor elemento en un iterador o secuencia de argumentos. Si el iterador es vacío se lanza un `ValueError` o se devuelve `default`. El parámetro `key` será una función que recibe un elemento y devuelve el valor clave. |
| `anext(iterator)`<br/>`anext(iterator, default)` | Da el siguiente elemento del iterador, si no quedan más elementos devuelve el valor por defecto o lanza `StopIteration`. |
| `oct(x)` | Da la cadena de texto que representa el número entero `x` en octal. |
| `open(file, mode='r', buffering=-1, encoding=None, errors=None, newline=None, closefd=True, opener=None)` | Abre un fichero y devuelve un objeto para manejarlo. |
| `ord(c)` | Da el número entero que representa al carácter Unicode `c`. |
| `por(base, exp, mod=None)` | Da el resultado de la operación `base ** exp` si `mod` es `None`, si no da el resultado de `(base ** exp) % mod`. |
| `print(*objects, sep=' ', end='\n', file=None, flush=False)` | Muestra un mensaje por pantalla en la terminal. |
| `property(fget=None, fset=None, fdel=None, doc=None)` | Decorador para crear una propiedad como atributo de una clase. |
| `range(stop)`<br/>`range(start, stop, step=1)` | Construye una secuencia inmutable de números. |
| `repr(obj)` | Da la cadena de texto que conforma la representación interna de un objeto. |
| `reversed(seq)` | Da un iterador que recorre una secuencia iterable en orden inverso. |
| `round(number, ndigits=None)` | Redondea un número con una precisión indicada. Si la precisión de `ndigits` es `None`, se redondea al número entero más cercano. |
| `set()`<br/>`set(iterable)` | Construye un conjunto vacío o a partir de un iterador. |
| `setattr(obj, name, value)` | Asigna o modifica un atributo con nombre del objeto. |
| `slice(stop)`<br/>`slice(start, stop, step=1)` | Construye un objeto `slice` que representa los índices requeridos por `range`. |
| `sorted(iterable, /, *, key=None, reverse=False)` |  Da un iterador que recorre de forma ordenada una secuencia iterable. El parámetro `key` será una función que recibe un elemento y devuelve el valor clave y `reverse` indica si se ha de ordenar en orden inverso o no. |
| `@staticmethod` | Transforma un método en un método estático. |
| `str(object='')`<br/>`str(object=b'', encoding='utf-8', errors='strict')` | Da una cadena de texto que representa a un objeto o una cadena binaria, con una codificación determinada. |
| `sum(iterable, /, start=0)` | Da la suma de todos los elementos de un iterador. |
| `super()`<br/>`super(type, object_or_type=None)` | Da el siguiente objeto proxy en la cadena de herencia actual. |
| `tuple()`<br/>`tuple(iterable)` | Construye una tupla vacía o a partir de un iterador. |
| `type(object)`<br/>`type(name, bases, dict, /, **kwds)` | Con un argumento da el tipo de un objeto. Con tres o más argumentos, devuelve una nueva instancia de una clase. |
| `vars()`<br/>`vars(object)` | Da un diccionario con los atributos de un módulo, clase, instancia u otro objeto con el atributo `__dict__`. |
| `<ip(*iterables, strict=False)` | Da un iterador en el que cada elemento es una tupla, donde cada componente es un elemento de los iteradores pasados como argumentos. |

## Biblioteca estándar

La [biblioteca estándar](https://docs.python.org/3/library/index.html) de Python es muy completa y comprende varias áreas de trabajo. Dentro del [tutorial oficial](https://docs.python.org/3/tutorial/) de Python, hay una introducción abarcando algunos aspectos básicos de la misma. Estas son las áreas o categorías que hay en la biblioteca:
- [Manejo de texto](https://docs.python.org/3/library/text.html)
- [Manejo de datos binarios](https://docs.python.org/3/library/binary.html)
- [Tipos de datos del lenguaje](https://docs.python.org/3/library/datatypes.html)
- [Números y matemáticas](https://docs.python.org/3/library/numeric.html)
- [Programación funcional](https://docs.python.org/3/library/functional.html)
- [Acceso a ficheros y directorios](https://docs.python.org/3/library/filesys.html)
- [Persistencia de datos](https://docs.python.org/3/library/persistence.html)
- [Compresión y archivado de datos](https://docs.python.org/3/library/archiving.html)
- [Formatos de ficheros](https://docs.python.org/3/library/fileformats.html)
- [Criptografía](https://docs.python.org/3/library/crypto.html)
- [Manejo genérico de sistemas operativos](https://docs.python.org/3/library/allos.html)
- [Ejecución concurrente](https://docs.python.org/3/library/concurrency.html)
- [Comunicación entre procesos y redes](https://docs.python.org/3/library/ipc.html)
- [Manejo de datos de internet](https://docs.python.org/3/library/netdata.html)
- [Herramientas para lenguajes de marcado](https://docs.python.org/3/library/markup.html)
- [Protocolos y soporte de internet](https://docs.python.org/3/library/internet.html)
- [Multimedia](https://docs.python.org/3/library/mm.html)
- [Localización de textos](https://docs.python.org/3/library/i18n.html)
- [Frameworks para programas](https://docs.python.org/3/library/frameworks.html)
- [Interfaces gráficas con Tk](https://docs.python.org/3/library/tk.html)
- [Herramientas de desarrollo](https://docs.python.org/3/library/development.html)
- [Depuración y análisis de ejecución](https://docs.python.org/3/library/debug.html)
- [Empacado y distribución de software](https://docs.python.org/3/library/distribution.html)
- [Servicios de ejecución de Python](https://docs.python.org/3/library/python.html)
- [Interpretes propios de Python](https://docs.python.org/3/library/custominterp.html)
- [Importación de módulos](https://docs.python.org/3/library/modules.html)
- [Servicios del lenguaje Python](https://docs.python.org/3/library/language.html)
- [Servicios de MS Windows](https://docs.python.org/3/library/windows.html)
- [Servicios de Unix](https://docs.python.org/3/library/unix.html)
- [Módulos reemplazados](https://docs.python.org/3/library/superseded.html)

Algunos de los módulos más destacados son los siguientes:

| Módulo | Descripción |
|:------:|:------------|
| [`string`](https://docs.python.org/3/library/string.html) | Operaciones comunes con cadenas de texto. |
| [`re`](https://docs.python.org/3/library/re.html) | Operaciones con expresiones regulares. |
| [`struct`](https://docs.python.org/3/library/struct.html) | Interpretar bytes como paquetes de datos binarios. |
| [`codecs`](https://docs.python.org/3/library/codecs.html) | Registro y clases base de codificación de texto. |
| [`datetime`](https://docs.python.org/3/library/datetime.html) | Tipos básicos para fechas y horas. |
| [`zoneinfo`](https://docs.python.org/3/library/zoneinfo.html) | Soporte para los usos horarios de la [IANA](https://es.wikipedia.org/wiki/Internet_Assigned_Numbers_Authority). |
| [`calendar`](https://docs.python.org/3/library/calendar.html) | Funciones generales con calendarios. |
| [`collections`](https://docs.python.org/3/library/collections.html) | Tipos de datos contenedores. |
| [`heapq`](https://docs.python.org/3/library/heapq.html) | Algoritmo del montículo con una cola. |
| [`bisect`](https://docs.python.org/3/library/bisect.html) | Algoritmo del array de bisección. |
| [`array`](https://docs.python.org/3/library/array.html) | Array de valores numéricos eficiente. |
| [`weakref`](https://docs.python.org/3/library/weakref.html) | Referencias débiles. |
| [`types`](https://docs.python.org/3/library/types.html) | Creación de tipos dinámicos y nombres para tipos nativos. |
| [`copy`](https://docs.python.org/3/library/copy.html) | Operaciones de copia ligera y profunda. |
| [`enum`](https://docs.python.org/3/library/enum.html) | Soporte para enumeraciones. |
| [`graphlib`](https://docs.python.org/3/library/graphlib.html) | Operaciones con estructuras de tipo grafo. |
| [`numbers`](https://docs.python.org/3/library/numbers.html) | Clases abstractas base para números. |
| [`math`](https://docs.python.org/3/library/math.html) | Funciones matemáticas. |
| [`cmath`](https://docs.python.org/3/library/cmath.html) | Funciones matemáticas para números complejos. |
| [`decimal`](https://docs.python.org/3/library/decimal.html) | Aritmética de punto fijo y punto flotante. |
| [`fractions`](https://docs.python.org/3/library/fractions.html) | Números racionales. |
| [`random`](https://docs.python.org/3/library/random.html) | Generación de números pseudo-aleatorios. |
| [`statistics`](https://docs.python.org/3/library/statistics.html) | Funciones matemáticas estadísticas. |
| [`operator`](https://docs.python.org/3/library/operator.html) | Operadores estándar como funciones. |
| [`os`](https://docs.python.org/3/library/os.html) | Interfaces varias del sistema operativo. |
| [`io`](https://docs.python.org/3/library/io.html) | Herramientas base para trabajar con flujos. |
| [`time`](https://docs.python.org/3/library/time.html) | Acceso y conversión de tiempos. |
| [`logging`](https://docs.python.org/3/library/logging.html) | Sistema para registrar eventos. |
| [`curses`](https://docs.python.org/3/library/curses.html) | Gestor para representar una terminal de texto. |
| [`pathlib`](https://docs.python.org/3/library/pathlib.html) | Rutas del sistema de fichero. |
| [`os.path`](https://docs.python.org/3/library/os.path.html) | Manipulación estándar de rutas. |
| [`filecmp`](https://docs.python.org/3/library/filecmp.html) | Comparación de ficheros y directorios. |
| [`tempfile`](https://docs.python.org/3/library/tempfile.html) | Generación temporal de ficheros y directorios. |
| [`shutil`](https://docs.python.org/3/library/shutil.html) | Operaciones de alto nivel con ficheros. |
| [`sqlite3`](https://docs.python.org/3/library/sqlite3.html) | Interfaz DB-API 2.0 para bases de datos SQLite. |
| [`zipfile`](https://docs.python.org/3/library/zipfile.html) | Lectura y escritura de ficheros ZIP. |
| [`tarfile`](https://docs.python.org/3/library/tarfile.html) | Lectura y escritura de ficheros TAR. |
| [`threading`](https://docs.python.org/3/library/threading.html) | Paralelismo basado en hilos. |
| [`multiprocessing`](https://docs.python.org/3/library/multiprocessing.html) | Paralelismo basado en procesos. |
| [`queue`](https://docs.python.org/3/library/queue.html) | Clase cola síncrona. |
| [`asyncio`](https://docs.python.org/3/library/asyncio.html) | Lectura y escritura asíncrona. |
| [`socket`](https://docs.python.org/3/library/socket.html) | Interfaz de red de bajo nivel. |
| [`json`](https://docs.python.org/3/library/json.html) | Codificador y decodificador de JSON. |
| [`html`](https://docs.python.org/3/library/html.html) | Soporte para HTML. |
| [`xml.dom`](https://docs.python.org/3/library/xml.dom.html) | Soporte para DOM. |
| [`xml.sax`](https://docs.python.org/3/library/xml.sax.html) | Soporte para SAX2. |
|  [`webbrowser`](https://docs.python.org/3/library/webbrowser.html) | Controlador básico del navegador web. |
| [`urllib`](https://docs.python.org/3/library/urllib.html) | Manejo de URLs. |
| [`http`](https://docs.python.org/3/library/http.html) | Soporte para HTTP. |
| [`socketserver`](https://docs.python.org/3/library/socketserver.html) | Framework para servidores de red. |
| [`ipaddress`](https://docs.python.org/3/library/ipaddress.html) | Soporte para manipular IPv4/IPv6. |

