# Python

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

> La sentencia `if` nos permite comprobar que se cumpla una condición, que en este caso es que el contenido de `__name__` sea igual a `"__main__"`, y ejecutar el siguiente bloque de código si es cierto. Si no es cierta la condición, se ejecuta el bloque de código de la sentencia `else`. Los bloques de código dependen del número de espacios con el que se tabulan. Es recomendable evitar mezclar espacios y tabulaciones. La explicación completa de todo esto está en la sección de *sentencias de control*.

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

Por ello debemos tener en cuenta que `import` va a ejecutar el código que se pueda ejecutar en el módulo. Lo recomendable es evitar ejecutar código alguno, prescindiendo en el ejemplo del bloque de la sentencia `else`. En caso de necesitar inicializar el módulo se puede definir una función para ello. Para definir una función usaremos:

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

| Operador | Descripción |
|:--------:|:-----------:|
| `X == Y`  | X es igual a Y. |
| `X != Y`  | X no es igual a Y. |
| `X <= Y`  | X es menor o igual que Y. |
| `X < Y`   | X es menor que Y. |
| `X >= Y`  | X es mayor o igual que Y. |
| `X > Y`   | X es mayor que Y. |
| `X is Y` | X e Y tienen la misma referencia. |
| `X is not Y` | X e Y tienen diferentes referencias. |

Donde X e Y son expresiones de Python, que se evalúan a un valor que va a ser comparado para determinar si es cierta o falsa la comparación. Nótese que no es lo mismo `==` que `is`, porque lo primero compara el valor final de la expresión y el segundo compara las direcciones de la memoria donde se almacenan dichos valores. Por implementación, las variables que almacenan objetos, que son instancias de una clase, lo que almacenan es un puntero a una dirección de memoria donde está almacenado el objeto de verdad. Estos punteros se les conoce en Python como referencias y es lo que se compara al usar los operadores `is` e `is not`, ya que con `==` lo que comparamos es el valor. Entonces, para lo que se usa, el operador `is`, es para comprobar si dos objetos representan la misma instancia.

> Python permite concatenar comparaciones para comprobar si un valor está dentro de un rango. Por ejemplo, con `1 <= X <= 10` comprobaríamos si `X` está entre el `1` y el `10`. Sería lo mismo que poner `0 < X < 11`, `10 >= X >= 1`, `11 > X > 0`, etcétera.

El segundo bloque son los operadores lógicos:

| Operador | Descripción |
|:--------:|:-----------:|
| `not X` | [Negación](https://es.wikipedia.org/wiki/Negaci%C3%B3n_l%C3%B3gica) de X. |
| `X and Y` | [Conjunción](https://es.wikipedia.org/wiki/Conjunci%C3%B3n_l%C3%B3gica) de X con Y. |
| `X or Y`  | [Disyunción](https://es.wikipedia.org/wiki/Disyunci%C3%B3n_l%C3%B3gica) de X con Y. |

De nuevo, X e Y son expresiones de Python. Estos operadores nos sirven para componer condiciones más complejas y para entenderlos mejor veamos sus [tablas de la verdad](https://es.wikipedia.org/wiki/Tabla_de_verdad):

|   `X`   |   `Y`   | `not X` | `not Y` | `X and Y` | `X or Y` |
|:-------:|:-------:|:-------:|:-------:|:---------:|:--------:|
| `True`  | `True`  | `False` | `False` |  `True`   | `True`   |
| `False` | `True`  | `True`  | `False` |  `False`  | `True`   |
| `True`  | `False` | `False` | `True`  |  `False`  | `True`   |
| `False` | `False` | `True`  | `True`  |  `False`  | `False`  |

El siguiente operador ternario, sirve para controlar la ejecución de expresiones en base a una condición booleana:

$$\mathit{expresi\acute{o}n_{True}}\ \texttt{if}\ \mathit{condici\acute{o}n}\ \texttt{else}\ \mathit{expresi\acute{o}n_{False}}$$

Si la *condición* es cierta, se ejecuta la primera *expresión*, si es falsa, se ejecuta la segunda. Aunque tengamos disponible este operador, no es recomendable su uso para evitar la ofuscación del código, en su lugar es mejor utilizar la sentencia `if`.

### Números

Python permite representar números [enteros](https://es.wikipedia.org/wiki/N%C3%BAmero_entero), [reales](https://es.wikipedia.org/wiki/N%C3%BAmero_real) e [imaginarios](https://es.wikipedia.org/wiki/N%C3%BAmero_imaginario) (para componer números [complejos](https://es.wikipedia.org/wiki/N%C3%BAmero_complejo)). Para representar números enteros tenemos:

$$\textcolor{red}{[} \texttt{0} \textcolor{red}{\char123} \texttt{b} \textcolor{red}{|} \texttt{o} \textcolor{red}{|} \texttt{x} \textcolor{red}{|} \texttt{B} \textcolor{red}{|} \texttt{O} \textcolor{red}{|} \texttt{X} \textcolor{red}{\char125} \textcolor{red}{]} \mathit{d\acute{\imath}gitos}$$

Con `b` o `B` expresamos números binarios, con `0` y `1` como dígitos. Con `o` o `O` expresamos números octales, con `0`.\.`7` como dígitos. Con `x` o `X` expresamos números hexadecimales, con `0`.\.`9` y `A`.\.`F` como dígitos, pudiendo usar también letras en minúsculas. Si no se usa ningún prefijo modificador, expresamos números decimales, con `0`.\.`9` como dígitos.

> Podemos expresar `-1` en Python, pero sólo `1` será parte de la expresión literal, el símbolo menos cuenta como un operador unario. Lo mismo ocurre para el caso de `+1`. Esto se aplica para todos los tipos de literales numéricos.

Para representar números reales o de coma flotante tenemos:

$$\mathit{d\acute{\imath}gitos} \texttt{.} \textcolor{red}{[} \mathit{d\acute{\imath}gitos} \textcolor{red}{]} \textcolor{red}{[} \textcolor{red}{\char123} \texttt{e} \textcolor{red}{|} \texttt{E} \textcolor{red}{\char125} \textcolor{red}{[} \texttt{+} \textcolor{red}{|} \texttt{-} \textcolor{red}{]} \mathit{d\acute{\imath}gitos} \textcolor{red}{]}$$

En este caso siempre será necesario el punto como separador decimal, pues de no indicarlo pasaría a ser un literal entero.

Para representar números imaginarios tenemos:

$$\mathit{n\acute{u}mero} \textcolor{red}{\char123} \texttt{j} \textcolor{red}{|} \texttt{J} \textcolor{red}{\char125}$$

Basta con indicar un número y terminar con una `j` para representar los números imaginarios en Python. Para componer números complejos tenemos dos formas. La primera es con la función `complex(R,I)`, donde `R` es la parte real e `I` la imaginaria, siendo ambos parámetros números enteros o reales. La segunda consiste en sumar a un número, entero o real, un número imaginario, por ejemplo `1+2j`.

> Una curiosidad de las expresiones literales numéricas es que podemos intercalar el carácter `_` entre los dígitos del número, sin que se altere su significado semántico. Este mecanismo existe para poder separar secciones visualmente. Por ejemplo, si queremos en nuestro código tener un separador de millares, podemos usar el guion bajo para tal propósito y tener `1_984` en lugar de `1984` si es de nuestro interés.

..

| `X` | `Y` | `~X` | `~Y` | `X & Y` | `X \| Y` | `X ^ Y` |
|:---:|:---:|:----:|:----:|:-------:|:-------:|:-------:|
| `1` | `1` |  `0` |  `0` |   `1`   |   `1`   |   `0`   |
| `0` | `1` |  `1` |  `0` |   `0`   |   `1`   |   `1`   |
| `1` | `0` |  `0` |  `1` |   `0`   |   `1`   |   `1`   |
| `0` | `0` |  `1` |  `1` |   `0`   |   `0`   |   `0`   |

..

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

Las cadenas *multilínea* se usan también para documentar clases y funciones. 

Por último, con el prefijo `r` se puede indicar que es una cadena *bruta* (*raw*), en la que las barras invertidas (`\`) no sean tomadas como secuencias de escape, sino como caracteres normales. La única salvedad, con este formato de cadenas, es que la barra invertida no puede ir al final de la cadena sin que de un error al interprete.

..

### Tuplas

..

### Listas

..

### Diccionarios

..

### Conjuntos

..

### Ficheros

..

### Precedencia de los operadores

Esta es la precedencia, de mayor a menor, de los operadores en Python:

| Operador | Descripción |
|:--------:|:------------|
| `{...}` | Diccionarios y conjuntos. |
| `[...]` | Listas. |
| `(...)` | Paréntesis, tuplas y generadores. |
| `X.atributo` | Referencia a un atributo de X. |
| `X(args)` | Invocación de la función X. |
| `X[i:j:k]` | Selección del contenedor X (*slicing*). |
| `X[i]` | Indexado del contenedor X. |
| `X ** Y` | X elevado a Y. |
| `~X` | Negación a nivel de bits de X. |
| `-X`<br/>`+X` | Negación e identidad de X. |
| `X * Y`<br/>`X % Y`<br/>`X / Y`<br/>`X // Y` | Multiplicación/repetición, módulo/formato, división y división entera de X con Y. |
| `X + Y`<br/>`X - Y` | Suma/concatenación y resta/diferencia de X con Y. |
| `X << Y`<br/>`X >> Y` | Desplazamiento a la izquierda o derecha Y bits de X. |
| `X & Y` | [Conjunción](https://es.wikipedia.org/wiki/Conjunci%C3%B3n_l%C3%B3gica) a nivel de bits o [intersección](https://es.wikipedia.org/wiki/Intersecci%C3%B3n_de_conjuntos) de conjuntos de X con Y. |
| `X ^ Y` | [Disyunción exclusiva](https://es.wikipedia.org/wiki/Disyunci%C3%B3n_exclusiva) a nivel de bits o [diferencia simétrica](https://es.wikipedia.org/wiki/Diferencia_sim%C3%A9trica) de conjuntos de X con Y. |
| `X \| Y` | [Disyunción](https://es.wikipedia.org/wiki/Disyunci%C3%B3n_l%C3%B3gica) a nivel de bits o [unión](https://es.wikipedia.org/wiki/Uni%C3%B3n_de_conjuntos) de conjuntos de X con Y. |
| `X == Y`<br/>`X != Y` | Igualdad y desigualdad de X con Y. |
| `X < Y`<br/>`X <= Y`<br/>`X > Y`<br/>`X >= Y` | Comparación y subconjunto o superconjunto de X con Y. |
| `X is Y`<br/>`X is not Y` | Comparación de referencias con los objetos X e Y. |
| `X in Y`<br/>`X not in Y` | Pertenencia o no de X al contenedor Y. |
| `not X` | [Negación](https://es.wikipedia.org/wiki/Negaci%C3%B3n_l%C3%B3gica) lógica de X. |
| `X and Y` | [Conjunción](https://es.wikipedia.org/wiki/Conjunci%C3%B3n_l%C3%B3gica) lógica de X con Y, donde Y se evaluará si X es `True`. |
| `X or Y` | [Disyunción](https://es.wikipedia.org/wiki/Disyunci%C3%B3n_l%C3%B3gica) lógica de X con Y, donde Y se evaluará si X es `False`. |
| `X if Y else Z` | X será evaluado si Y es `True`, si no se evalúa Z. |
| `lambda args: X` | Expresión lambda. |
| `yield X` | Generador de valores. |

## Sentencias de control

..

## Clases y objetos

..

## Funciones nativas

..

## Biblioteca estándar

..

