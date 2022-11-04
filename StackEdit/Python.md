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

Una **clase** representa lo que se denomina un tipo, que es una representación abstracta de un concepto con el que va a trabajar el programa. Por un lado tendremos la definición del tipo y por otro las instancias de un tipo, que son los valores concretos con los que está trabajando el programa. Se podría decir que la definición es la forma y la instancia es el contenido. Para definir un tipo, hace falta definir sus **atributos**, que son las propiedades y operaciones del mismo, donde las propiedades son variables y las operaciones son funciones. En Python se denomina clase a la definición de un tipo y objeto a la instancia del mismo. También se denomina a las funciones de una clase como métodos de la misma.

El **ámbito** de una variable es aquellas ubicaciones donde se puede utilizar la misma. El módulo, la función, la clase o el método, son algunos de los diferentes ámbitos donde se puede declarar una variable. Para declarar una variable basta con asignarle un valor:

```Python
año = 1984
```

Volviendo al código del ejemplo `hola.py`, la sentencia `import` nos permite acceder a otros módulos, por lo que `import sys` nos permite acceder al contenido de `sys.py`, que es un módulo de la biblioteca estándar de Python, y con `sys.argv` accedemos al contenido de la variable `argv` de dicho módulo, que contiene los argumentos de entrada utilizados al ejecutar nuestra aplicación.

Cuando usamos la consola de Python también podemos usar `import` para cargar un módulo. Por ejemplo:

```
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

```
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

```
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

## Tipos y operadores básicos

### Nulo o vacío

El valor `None` pertenece al tipo `NoneType` y representa el concepto de la semántica vacía o nula. Cuando algo no tiene valor, usamos este valor para indicarlo en nuestros programas. Por ejemplo, si una función no devuelve ningún valor explícitamente, se devolverá `None` como resultado.

> Aunque parezca una contradicción, usar un valor para expresar algo que no tiene valor, en teoría de lenguajes una cosa son los conceptos teóricos que queremos representar y otra cómo necesitamos implementarlos.

### Booleanos

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

### Números

Python permite representar números [enteros](https://es.wikipedia.org/wiki/N%C3%BAmero_entero), [reales](https://es.wikipedia.org/wiki/N%C3%BAmero_real) e [imaginarios](https://es.wikipedia.org/wiki/N%C3%BAmero_imaginario) (para componer números [complejos](https://es.wikipedia.org/wiki/N%C3%BAmero_complejo)). Para representar números enteros, que pertenecen al tipo `int`, tenemos:

$$\textcolor{red}{[} \texttt{0} \textcolor{red}{\char123} \texttt{b} \textcolor{red}{|} \texttt{o} \textcolor{red}{|} \texttt{x} \textcolor{red}{|} \texttt{B} \textcolor{red}{|} \texttt{O} \textcolor{red}{|} \texttt{X} \textcolor{red}{\char125} \textcolor{red}{]} \mathit{d\acute{\imath}gitos}$$

Con `b` o `B` expresamos números binarios, con `0` y `1` como dígitos. Con `o` o `O` expresamos números octales, con `0`.\.`7` como dígitos. Con `x` o `X` expresamos números hexadecimales, con `0`.\.`9` y `A`.\.`F` como dígitos, pudiendo usar también letras en minúsculas. Si no se usa ningún prefijo modificador, expresamos números decimales, con `0`.\.`9` como dígitos.

> Podemos expresar `-1` en Python, pero sólo `1` será parte de la expresión literal, el símbolo menos cuenta como un operador unario. Lo mismo ocurre para el caso de `+1`. Esto se aplica para todos los tipos de literales numéricos.

Para representar números reales o de coma flotante, que pertenecen al tipo `float`, tenemos:

$$\mathit{d\acute{\imath}gitos} \texttt{.} \textcolor{red}{[} \mathit{d\acute{\imath}gitos} \textcolor{red}{]} \textcolor{red}{[} \textcolor{red}{\char123} \texttt{e} \textcolor{red}{|} \texttt{E} \textcolor{red}{\char125} \textcolor{red}{[} \texttt{+} \textcolor{red}{|} \texttt{-} \textcolor{red}{]} \mathit{d\acute{\imath}gitos} \textcolor{red}{]}$$

En este caso siempre será necesario el punto como separador decimal, pues de no indicarlo pasaría a ser un literal entero.

Para representar números imaginarios tenemos:

$$\mathit{n\acute{u}mero} \textcolor{red}{\char123} \texttt{j} \textcolor{red}{|} \texttt{J} \textcolor{red}{\char125}$$

Basta con indicar un número y terminar con una `j` para representar los números imaginarios en Python. Para componer números complejos, que pertenecen al tipo `complex`, tenemos dos formas. La primera es con la función `complex(R,I)`, donde `R` es la parte real e `I` la imaginaria, siendo ambos parámetros números enteros o reales. La segunda consiste en sumar a un número, entero o real, un número imaginario, por ejemplo `1+2j`. Hay que tener en cuenta que Python no tiene como tipo el conjunto de los números imaginarios, por lo que `1j` es interpretado como `0+1j` y pertenecerá al tipo `complex`.

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

### Cadenas de texto

Las cadenas de texto se delimitan con comillas dobles (`"`) o comillas simples (`'`). Es lo mismo `"texto"` que `'texto'`. La expresión `"ho" "la"` equivale a `"hola"`. Hay diferentes tipos de cadenas en Python:

| Tipo | Forma | Descripción |
|:----:|:-----:|:------------|
| `str` | `"..."`<br/>`'...'`<br/>`str(b,e)` | Cadena de texto Unicode (UTF-8) inmutable, donde `b` es una cadena de bytes y `e` es una cadena de texto con la codificación. |
| `bytes` | `b"..."`<br/>`b'...'`<br/>`bytes(s,e)` | Cadena de bytes inmutable, donde `s` es una cadena de texto y `e` es una cadena de texto con la codificación. |
| `bytearray` | `bytearray(b)`<br/>`bytearray(s,e)` | Cadena de bytes mutable, donde `b` es una cadena de bytes, `s` es una cadena de texto y `e` es una cadena de texto con la codificación. |

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

### Tuplas

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

### Listas

Las listas son estructuras secuenciales cuyos elementos tienen un orden definido. En el caso de Python las listas son mutables y pertenecen al tipo `list`. Sus elementos son accesibles mediante una posición de índice. Para definir una lista se usa la siguiente sintaxis:

$$\texttt{[} \textcolor{red}{[} \mathit{expresi\acute{o}n_1} \textcolor{red}{[} \texttt{,} \textcolor{red}{\dots} \texttt{,} \mathit{expresi\acute{o}n_n} \textcolor{red}{]} \textcolor{red}{]} \textcolor{red}{]} \texttt{]}$$

Donde `[]` es la lista vacía y el resto son listas con un tamaño arbitrario de elementos. Se pueden anidar otras estructuras dentro de las listas, así como otras listas también. Además, se puede utilizar la función constructora `list(I)` para construir nuevas instancias, donde `I` es un iterador, como ocurría con el caso de las tuplas. Por ejemplo, `list('abc')` dará como resultado el valor `['a','b','c']`.

Una sintaxis alternativa, para definir listas, son las *listas intensionales* que tienen la siguiente sintaxis:

$$\texttt{[} \mathit{expresi\acute{o}n}\ \texttt{for}\ \mathit{patr\acute{o}n_1}\ \texttt{in}\ \mathit{iterador_1}\ \textcolor{red}{[} \texttt{if}\ \mathit{condici\acute{o}n_1} \textcolor{red}{]}$$

$$\qquad\quad\ \ \textcolor{red}{[}\ \textcolor{red}{\dots}\ \texttt{for}\ \mathit{patr\acute{o}n_n}\ \texttt{in}\ \mathit{iterador_n}\ \textcolor{red}{[} \texttt{if}\ \mathit{condici\acute{o}n_n} \textcolor{red}{]} \textcolor{red}{]} \texttt{]}$$

De este modo, podemos construir listas a partir de otros contenedores, mediante el [producto cartesiano](https://es.wikipedia.org/wiki/Producto_cartesiano). Para ello, tomamos un *iterador* y ajustamos cada elemento del mismo a un *patrón* (una variable o composición estructurada de variables), y opcionalmente podemos pedir que estos elementos cumplan una *condición*. Con el resultado del producto cartesiano de todos los elementos, que hayan cumplido las condiciones indicadas, construimos una *expresión* que conformará cada elemento de la lista final. Por ejemplo:

```
>>> [(a,b) for a in range(1,7) if a % 2 != 0
...        for b in range(1,7) if b % 2 == 0]
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

### Iteradores y generadores

Un iterador es un tipo de objeto cuyo propósito es el de recorrer el contenido de un contenedor de datos. Para ello hay dos funciones básicas:

| Función | Descripción |
|:-------:|:-----------:|
| `iter(X)` | Devuelve un iterador para el objeto `X`, siempre que su clase tenga implementada la interfaz para la iteración. |
| `next(I)` | Devuelve el elemento actual y sitúa el iterador en el siguiente elemento. Si no quedan más elementos que recorrer, se lanza un `StopIteration`. |

Por ejemplo:

```
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

```
>>> lista=[1,2,3,4]
>>> [x*2 for x in lista]
[2, 4, 6, 8]
>>> list(x*2 for x in lista)
[2, 4, 6, 8]
```

Los generadores no dejan de ser instancias del tipo `generator` y que implementan la interfaz para la iteración. Por ejemplo:

```
>>> g = (x*2 for x in [1,2,3])
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

### Operaciones con secuencias

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
s1 = [1,2,3,4,5,6]
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
s1 = [[1,2],[3,4],[5,6]]
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

### Diccionarios

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
|:---------:|:-----------:|
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

### Conjuntos

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
|:---------:|:-----------:|
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

### Ficheros

..

### Asignación de valores

..

| Operación | Descripción |
|:---------:|:-----------:|
| ` ` | .. |

..

### Precedencia de los operadores

Esta es la precedencia, de mayor a menor, de los operadores en Python:

| Operación | Descripción |
|:---------:|:-----------:|
| `{...}` | Diccionarios y conjuntos. |
| `[...]` | Listas. |
| `(...)` | Paréntesis, tuplas y generadores. |
| `X.atributo` | Referencia a un atributo de X. |
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

> En la categoría de la multiplicación estaría el operador `@`, que la documentación de Python lo denomina como [multiplicador de matrices](https://peps.python.org/pep-0465/), aunque la biblioteca estándar no implementa este operador. Sin embargo, bibliotecas como [`numpy`](https://numpy.org/) sí que lo usan para multiplicar matrices.

## Sentencias de control

..

## Definición de funciones

..

## Clases y objetos

..

## Cadenas con formato

..

## Biblioteca estándar

La [biblioteca estándar](https://docs.python.org/3/library/index.html) de Python es muy completa y comprende varias áreas de trabajo.

..

### Funciones nativas

..

### Constantes nativas

..

### Tipos nativos

..

### Excepciones nativas

..

## Módulos matemáticos

..

## Módulos de cadenas

..

## Módulos de estructuras

..

## Módulos funcionales

..

## Módulos de ficheros y directorios

..

## Módulos del sistema operativo

..

## Módulos de concurrencia

..

## Módulos de comunicaciones

..

## Módulos de almacenamiento

..

