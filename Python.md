# Python

## Primeros pasos

[Python](https://www.python.org/) es un lenguaje interpretado popular con una sintaxis sencilla. Entre propiedades destacadas tenemos múltiples paradigmas, orientación a objetos, tipado dinámico o funciones de primer orden. Para ejecutar un programa necesitamos usar el comando `python`, por ejemplo:

```Python
# Fichero: hello.py
print("Hello, world!")
```

En Python, los comentarios de una línea empiezan con `#` y la función `print` muestra por consola un valor. Para ejecutar este programa, usaremos el siguiente comando:

```
python hello.py
```

Se pueden pasar argumentos al programa accediendo al contenido de `sys.argv`, que es una lista cuyo primer elemento es el fichero que se está ejecutando. Por ejemplo:

```Python
# Fichero: hello.py
print("Hello, world!")
print(sys.argv)
```

Entonces, para la siguiente llamada, nos dará la siguiente salida:

```
$ python hello.py 20 febrero 1991
Hello, world!
['hello.py', '20', 'febrero', '1991']
```

## Literales

### Nulo o vacío

El valor `None` en Python representa el concepto de la semántica vacía o nula. Cuando algo no tiene valor, usamos este valor para indicarlo en nuestros programas. 

> Aunque parezca una contradicción, usar un valor para expresar algo que no tiene valor, en teoría de lenguajes una cosa son los conceptos teóricos que queremos representar y otra cómo necesitamos implementarlos.

### Booleanos

Los valores booleanos vienen del [álgebra de Boole](https://es.wikipedia.org/wiki/%C3%81lgebra_de_Boole) y se usan para representar cuando una condición es verdadera o falsa. Para ello tenemos la constante `True` como verdadero y `False` como falso.

> Por temas de implementación en el lenguaje, se considera como falso también el número cero (`0` o `0.0`), los contenedores de datos vacíos (`""`, `[]`, `{}`, etcétera) o el valor nulo (`None`). Todos los objetos tienen un valor booleano.

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

## Tipos básicos

..

## Operadores

..

## Entrada y salida básica

..


## Estructuras de control

..

## Clases y objetos

..

