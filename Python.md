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

