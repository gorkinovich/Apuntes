# Commodore 64: Mapa de memoria

Este es un resumen y traducción parcial del siguiente [mapa de memoria](https://sta.c64.org/cbm64mem.html) del Commodore 64. Para más información, en inglés, sobre los elementos en la memoria del C64 consulta la siguiente [documentación](https://sta.c64.org/cbmdocs.html).

## Página Cero

| Dirección | Hexadecimal | Defecto | Descripción |
|:---------:|:-----------:|:-------:|-------------|
| 0 | \$0000 | \$2F (00101111) | Configuración del registro de puertos de la CPU. **Bits 0-7:** **0** = Lectura; **1** = Escritura/Lectura. |
| 1 | \$0001 | \$37 (00110111) | Registro de puertos de la CPU:<br/>**Bits 0-2:** Configuración de los bloques de memoria en \$A000-\$BFFF, \$D000-\$DFFF y \$E000-\$FFFF.<br/> + **000;100** = RAM visible en los tres bloques.<br/> + **x01** = RAM visible en \$A000-\$BFFF y \$E000-\$FFFF.<br/> + **x10** = RAM visible en \$A000-\$BFFF y KERNAL ROM visible en \$E000-\$FFFF.<br/> + **x11** = BASIC ROM visible en \$A000-\$BFFF y KERNAL ROM visible en \$E000-\$FFFF.<br/> + **0xx** = ROM de caracteres visible en \$D000-\$DFFF (excepto valor 000).<br/> + **1xx** = Chips E/S visibles en \$D000-\$DFFF (excepto valor 100).<br/>**Bit 3:** Nivel de señal de salida del *datasette*.<br/>**Bit 4:** Estado de los botones del *datasette*: **0** = Uno o más botones pulsados; **1** = Ningún botón pulsado.<br/>**Bit 5:** Control del motor del *datasette*: **0** = Encendido; **1** = Apagado. |
| 2 | \$0002 | - | Sin uso. |
| 3-4 | \$0003-\$0004 | \$B1AA | Sin uso (dirección de la rutina de conversión de números flotantes a enteros). |
| 5-6 | \$0005-\$0006 | \$B391 | Sin uso (dirección de la rutina de conversión de números enteros a flotantes). |
| 7 | \$0007 | - | Usado por varias operaciones (`INPUT`, `AND`, `OR`, `INT`). |
| 8 | \$0008 | - | Usado por varias operaciones (*tokenizer*, `AND`, `OR`). |
| 9 | \$0009 | - | Columna actual al usar `SPC` y `TAB`. |
| 10 | \$000A | - | Flag `LOAD`/`VERIFY` (**\$00** = `LOAD`; **\$01**-**\$FF** = `VERIFY`). |
| 11 | \$000B | - | Usado por varias operaciones (*tokenizer*, editor BASIC, flag `AND`/`OR`, dimensiones de un array). |
| 12 | \$000C | - | Flag para operaciones con arrays (**\$00** = Fuera de un `DIM`; **\$40**-**\$FF** = Dentro de un `DIM`). |
| 13 | \$000D | - | Tipo de expresión (**\$00** = Numérica; **\$FF** = Cadena). |
| 14 | \$000E | - | Tipo de expresión numérica (**Bit 7:** **0** = Flotante; **1** = Entera). |
| 15 | \$000F | - | + Modo de dobles comillas del *tokenizer* (**Bit 6:** **0** = Desactivado; **1** = Activado) o de `LIST` (**\$00** = Desactivado; **\$FE** = Activado).<br/>+ Recolector de basura al reservar memoria para cadenas (**\$00**-**\$7F** = Recolección no realizada; **\$80** = Recolección realizada). |
| 16 | \$0010 | - | Flag durante la obtención del nombre de variable (**\$00** = Se aceptan variables enteras; **\$01-\$FF** = No se aceptan variables enteras). |
| 17 | \$0011 | - | Flag `GET`/`INPUT`/`READ` (**\$00** = `GET`; **\$40** = `INPUT`; **\$98** = `READ`). |
| 18 | \$0012 | - | Signo durante `SIN` y `TAN` (**\$00** = Positivo; **\$FF** = Negativo). |
| 19 | \$0013 | \$00 | Número de dispositivo de E/S actual. (Por defecto el teclado para la entrada y la pantalla para la salida.) |
| 20-21 | \$0014-\$0015 | - | Usado por varias operaciones (`GOSUB`, `GOTO`, `RUN`, `LIST`, `PEEK`, `POKE`, `SYS` y `WAIT`). |
| 22 | \$0016 | - | Puntero a la siguiente expresión en la pila de cadenas. |
| 23-24 | \$0017-\$0018 | - | Puntero a la anterior expresión en la pila de cadenas. |
| 25-33 | \$0019-\$0021 | - | Área temporal para procesar expresiones de cadenas (9 bytes, 3 entradas). |
| 34-37 | \$0022-\$0025 | - | Área temporal para varias operaciones (4 bytes). |
| 38-41 | \$0026-\$0029 | - | Registro aritmético auxiliar para divisiones y multiplicaciones (4 bytes). |
| 42 | \$002A | - | Sin uso salvo para responder cuál es el sentido de la vida, el universo y todo lo demás. |
| 43-44 | \$002B-\$002C | \$0801 | Puntero al inicio de la memoria de programas BASIC. |
| 45-46 | \$002D-\$002E | - | Puntero al inicio del bloque de variables. (Final de programa +1.) |
| 47-48 | \$002F-\$0030 | - | Puntero al inicio del bloque de variables de arrays. |
| 49-50 | \$0031-\$0032 | - | Puntero al final del bloque de variables. |
| 51-52 | \$0033-\$0034 | - | Puntero al inicio del bloque de variables de cadenas. (Crece desde el final de la memoria de programas BASIC hacia abajo.) |
| 53-54 | \$0035-\$0036 | - | Puntero a la memoria reservada para la variable de cadena actual. |
| 55-56 | \$0037-\$0038 | \$A000 | Puntero al final de la memoria de programas BASIC. |
| 57-58 | \$0039-\$003A | - | Línea actual de BASIC:<br/>+ **\$0000-\$F9FF** (0-63999) = Número de línea.<br/>+ **\$FF00-\$FFFF** = Modo directo, no se está ejecutando ningún programa BASIC. |
| 59-60 | \$003B-\$003C | - | Línea actual de BASIC para `CONT`. |
| 61-62 | \$003D-\$003E | - | Puntero a la siguiente instrucción BASIC para `CONT`:<br/>+ **\$0000-\$00FF** = No es posible continuar.<br/>+ **\$0100-\$FFFF** = Puntero a la siguiente instrucción. |
| 63-64 | \$003F-\$0040 | - | Línea actual de BASIC para el elemento actual de `DATA` para `READ`. |
| 65-66 | \$0041-\$0042 | - | Puntero al siguiente elemento `DATA` para `READ`. |
| 67-68 | \$0043-\$0044 | - | Puntero al resultado durante `GET`, `INPUT` y `READ`. |
| 69-70 | \$0045-\$0046 | - | Nombre y tipo de la variable actual:<br/>+ **Bits 0-6 de \$0045:** Primer carácter del nombre.<br/>+ **Bits 0-6 de \$0046:** Segundo carácter del nombre.<br/>+ **Bit 7 de \$0045 y \$0046:** **00** = Flotante; **01** = Cadena; **10** = Función; **11** = Entera. |
| 71-72 | \$0047-\$0048 | - | Puntero al valor de la variable o función `FN` actual. |
| 73-74 | \$0049-\$004A | - | Usado por varias operaciones (`LET`, `WAIT`, `OPEN`, `CLOSE`, `LOAD`, `SAVE` y `VERIFY`). |
| 75-76 | \$004B-\$004C | - | Área temporal para guardar el puntero original a la instrucción BASIC actual durante `GET`, `INPUT` y `READ`. |
| 77 | \$004D | - | Indicador de operador de comparación:<br/>+ **Bit 1:** **1** = `>` se encuentra en la expresión.<br/>+ **Bit 2:** **1** = `=` se encuentra en la expresión.<br/>+ **Bit 3:** **1** = `<` se encuentra en la expresión. |
| 78-79 | \$004E-\$004F | - | Puntero a la función `FN` actual. |
| 80-81 | \$0050-\$0051 | - | Puntero a la variable de cadena actual durante la reserva de memoria. |
| 82 | \$0052 | - | Sin uso. |
| 83 | \$0053 | - | Tamaño del incremento en la recolección de basura. |
| 84-86 | \$0054-\$0056 | - | Instrucción JMP ABS para saltar a la función BASIC actual, cuya dirección está en \$0055-\$0056 . |
| 87-91 | \$0057-\$005B | - | Registro aritmético 3 (5 bytes). |
| 92-96 | \$005C-\$0060 | - | Registro aritmético 4 (5 bytes). |
| 97-101 | \$0061-\$0065 | - | FAC: Registro aritmético 1 (5 bytes). |
| 102 | \$0066 | - | Signo del FAC (**Bit 7:** **0** = Positivo; **1** = Negativo). |
| 103 | \$0067 | - | Número de grados durante una evaluación polinómica. |
| 104 | \$0068 | - | Área temporal durante varias operaciones. |
| 105-109 | \$0069-\$006D | - | ARG: Registro aritmético 2 (5 bytes). |
| 110 | \$006E | - | Signo del ARG (**Bit 7:** **0** = Positivo; **1** = Negativo). |
| 111-112 | \$006F-\$0070 | - | Puntero a la primera expresión de cadena durante una comparación de cadenas. |
| 113-114 | \$0071-\$0072 | - | Usado por varias operaciones (arrays, `VAL`, evaluación polinómica). |
| 115-138 | \$0073-\$008A | - | Usado por CHRGET para leer el siguiente byte de un programa BASIC o comando directo (24 bytes). Dirección \$0079: Usado por CHRGOT para leer el byte actual de un programa BASIC o comando directo. Dirección \$007A-\$007B: Puntero al byte actual de un programa BASIC o comando directo. |
| 139-143 | \$008B-\$008F | - | Resultado anterior de `RND`. |
| 144 | \$0090 | - | Valor de la variable `STATUS` para el estado del dispositivo para la E/S del puerto serie y el *datasette*. Bits del puerto serie:<br/>+ **Bit 0:** Dirección al presentarse un *timeout* **0** = Entrada; **1** = Salida.<br/>+ **Bit 1:** **1** = Error de *timeout*.<br/>+ **Bit 4:** **1** = Error en `VERIFY`.<br/>+ **Bit 6:** **1** = Final de fichero.<br/>+ **Bit 7:** **1** = Error de dispositivo no encontrado.<br/> Bits del *datasette*:<br/>+ **Bit 2:** **1** = Bloque demasiado corto (< 192 bytes).<br/>+ **Bit 3:** **1** = Bloque demasiado largo (> 192 bytes).<br/>+ **Bit 4:** **1** = Error en `VERIFY`.<br/>+ **Bit 5:** **1** = Error de *checksum* .<br/>+ **Bit 6:** **1** = Final de fichero (sólo mientras está leyendo) . |
| 145 | \$0091 | - | Estado de la tecla `RUN/STOP` (**\$7F** = Pulsada; **\$FF** = No pulsada). |
| 146 | \$0092 | - | Desconocido. (Constante de tiempo durante la entrada del *datasette*.) |
| 147 | \$0093 | - | Flag `LOAD`/`VERIFY` (**\$00** = `LOAD`; **\$01**-**\$FF** = `VERIFY`). |
| 148 | \$0094 | - | Estado de la cache de salida del puerto serie (**Bit 7:** **1** = Cache de salida modificada, hay que transferir el contenido en la próxima salida del bus). |
| 149 | \$0095 | - | Cache de salida del puerto serie, byte previo para enviar al bus. |
| 150 | \$0096 | - | Desconocido. (Indicador de final de cinta durante la E/S del *datasette*.) |
| 151 | \$0097 | - | Área temporal para guardar el valor original del registro X durante la entrada del RS-232 o el registro Y durante la entrada del *datasette*. |
| 152 | \$0098 | - | Número de ficheros actualmente abiertos (0-10). |
| 153 | \$0099 | \$00 | Número de dispositivo de entrada actual (teclado por defecto). |
| 154 | \$009A | \$03 | Número de dispositivo de salida actual (pantalla por defecto). |
| 155 | \$009B | - | Desconocido. (Bit de paridad durante la E/S del *datasette*.) |
| 156 | \$009C | - | Desconocido. (Indicador de byte preparado durante la E/S del *datasette*.) |
| 157 | \$009D | - | Flag de mostrar errores del sistema:<br/>+ **Bit 6:** **0** = Eliminar mensajes de errores de E/S; **1** = Mostrarlos.<br/>+ **Bit 7:** **0** = Eliminar mensajes de errores de sistema; **1** = Mostrarlos. |
| 158 | \$009E | - | Usado por varias operaciones (E/S del RS-232 y del *datasette*, `LOAD`). |
| 159 | \$009F | - | Usado por varias operaciones (E/S del *datasette*, `LOAD`). |
| 160-162 | \$00A0-\$00A2 | - | Variable `TIME` (hora del día), incrementada en una unidad cada 60 Hz. |
| 163 | \$00A3 | - | Flag EOI durante la salida del puerto serie (**Bit 7:** **0** = Enviar byte después del *handshake*; **1** = Realizar retardo EOI primero).<br/>Contador de bits durante la salida del *datasette*. |
| 164 | \$00A4 | - | Buffer de bytes durante la entrada del puerto serie.<br/>Paridad durante la E/S del *datasette*. |
| 165 | \$00A5 | - | Contador de bits durante la E/S del puerto serie.<br/>Contador de la marca de sincronización durante la salida del *datasette*. |
| 166 | \$00A6 | - | Desplazamiento del byte actual en el buffer del *datasette*. |
| 167 | \$00A7 | - | Buffer de bits durante la entrada del RS-232. |
| 168 | \$00A8 | - | Contador de bits durante la entrada del RS-232. |
| 169 | \$00A9 | - | Flag de parada de bit durante la entrada del RS-232 (**\$00** = Bit de datos; **\$01-\$FF** = Bit de parada). |
| 170 | \$00AA | - | Buffer de bytes durante la entrada del RS-232. |
| 171 | \$00AB | - | Paridad durante la entrada del RS-232.<br/>*Checksum* de bloque durante la entrada del *datasette*. |
| 172-173 | \$00AC-\$00AD | - | Usado por varias operaciones (`SAVE`, desplazamiento de pantalla). |
| 174-175 | \$00AE-\$00AF | - | Usado por varias operaciones (`LOAD`, `VERIFY`, `SAVE`, desplazamiento del color de pantalla). |
| 176-177 | \$00B0-\$00B1 | - | Desconocido. |
| 178-179 | \$00B2-\$00B3 | \$033C | Puntero al buffer del *datasette*. |
| 180 | \$00B4 | - | Flag de contador de bits y bits de parada durante la salida del RS-232 (**Bits 0-6:** Contador de bits; **Bit 7:** **0** = Bit de datos; **1** = Bit de parada).<br/>Contador de bits durante la E/S del *datasette*. |
| 181 | \$00B5 | - | Buffer de bits durante la salida del RS-232. |
| 182 | \$00B6 | - | Buffer de bytes durante la salida del RS-232. |
| 183 | \$00B7 | - | Tamaño del nombre de fichero o comando de discos (**\$00** = Sin parámetro; **\$01-\$FF** = Tamaño). Usado por `LOAD`, `SAVE`, `VERIFY` y `OPEN`. |
| 184 | \$00B8 | - | Identificador del fichero actual. |
| 185 | \$00B9 | - | Modo secundario del fichero actual. |
| 186 | \$00BA | - | Número de dispositivo del fichero actual. |
| 187-188 | \$00BB-\$00BC | - | Puntero al nombre de fichero o comando de discos actual. Usado por `LOAD`, `SAVE`, `VERIFY` y `OPEN`. |
| 189 | \$00BD | - | Paridad durante la salida del RS-232.<br/>Buffer de bytes durante la E/S del *datasette*. |
| 190 | \$00BE | - | Bloqueo del contador durante la E/S del *datasette*. |
| 191 | \$00BF | - | Desconocido. |
| 192 | \$00C0 | - | Flag del motor del *datasette*:<br/>+ **\$00** = Ningún botón pulsado, motor desactivado. Si se pulsa algún botón se activará el motor.<br/>+ **\$01-\$FF** = Motor activado. |
| 193-194 | \$00C1-\$00C2 | - | Usado por varias operaciones (`LOAD`, `VERIFY`, `SAVE`, test de memoria). |
| 195-196 | \$00C3-\$00C4 | - | Usado por varias operaciones (`LOAD`, `VERIFY`, vectores de E/S). |
| 197 | \$00C5 | - | Código matriz de tecla previamente pulsado (**\$00-\$3F** = Tecla; **\$40** = Nada pulsado). |
| 198 | \$00C6 | - | Tamaño del buffer de teclado (**\$00** = Vacío; **\$01-\$0A** = Tamaño). |
| 199 | \$00C7 | - | Flag modo inverso (**\$00** = Normal; **\$12** = Invertido). |
| 200 | \$00C8 | - | Tamaño de línea menos 1 durante la entrada de pantalla (39, 79). |
| 201 | \$00C9 | - | Fila del cursor durante la entrada de pantalla (0-24). |
| 202 | \$00CA | - | Columna del cursor durante la entrada de pantalla (0-39). |
| 203 | \$00CB | - | Código matriz de tecla actualmente pulsado (**\$00-\$3F** = Tecla; **\$40** = Nada pulsado). |
| 204 | \$00CC | - | Flag de visibilidad del cursor (**\$00** = Encendido; **\$01-\$FF** = Apagado). |
| 205 | \$00CD | - | Retardo del cambio de fase del cursor (**\$00** = Debe cambiar de fase; **\$01-\$14** = Retardo). |
| 206 | \$00CE | - | Código de pantalla del carácter bajo el cursor. |
| 207 | \$00CF | - | Flag de fase del cursor (**\$00** = Fase apagada, carácter original visible; **\$01** = Fase encendida, carácter invertido visible). |
| 208 | \$00D0 | - | Flag de fin de línea durante la entrada de pantalla (**\$00** = Carácter de retorno alcanzado, fin de línea (EOL); **\$01-\$FF** = Seguir leyendo caracteres de la línea). |
| 209-210 | \$00D1-\$00D2 | - | Puntero a la línea actual de la memoria de pantalla. |
| 211 | \$00D3 | - | Columna actual del cursor (0-39). |
| 212 | \$00D4 | - | Flag modo comillas dobles (**\$00** = Modo normal; **\$01** = Modo comillas dobles). |
| 213 | \$00D5 | - | Tamaño de línea actual de pantalla menos 1 (39, 79). |
| 214 | \$00D6 | - | Fila actual del cursor (0-24). |
| 215 | \$00D7 | - | Usado por varias operaciones (E/S de pantalla, *datasette*). |
| 216 | \$00D8 | - | Número de inserciones (**\$00** = Ninguna; **\$01-\$FF** = Inserciones). Cuando se insertan huecos en una línea, la entrada de la pantalla actuará de forma similar al modo comillas dobles para esas posiciones. |
| 217-241 | \$00D9-\$00F1 | - | Byte alto de punteros a cada línea en la memoria de pantalla (25 bytes; **\$00-\$7F** = Byte alto del puntero; **\$80-\$FF** = Sin puntero, la línea es una extensión de la anterior). |
| 242 | \$00F2 | - | Área temporal durante el desplazamiento de la pantalla. |
| 243-244 | \$00F3-\$00F4 | - | Puntero a la línea actual en la RAM de color. |
| 245-246 | \$00F5-\$00F6 | - | Puntero a la tabla de conversión durante la traducción de códigos de matriz de teclado a PETSCII. |
| 247-248 | \$00F7-\$00F8 | - | Puntero al buffer de entrada del RS-232 (**\$0000-\$00FF** = Buffer no definido; **\$0100-\$FFFF** = Puntero al buffer). |
| 249-250 | \$00F9-\$00FA | - | Puntero al buffer de salida del RS-232 (**\$0000-\$00FF** = Buffer no definido; **\$0100-\$FFFF** = Puntero al buffer). |
| 251-254 | \$00FB-\$00FE | - | Sin uso (4 bytes). |
| 255-266 | \$00FF-\$010A | - | Buffer para convertir número flotantes a cadena (12 bytes).<br/>**NOTA:** Invade el espacio final de la pila de programa. |

## Pila de programa

| Dirección | Hexadecimal | Descripción |
|:---------:|:-----------:|-------------|
| 256-317 | \$0100-\$013D | Punteros a los bytes de lectura con errores durante la lectura del *datasette* (62 bytes, 31 entradas). |
| 256-511 | \$0100-\$01FF | Pila del procesador. También se utiliza para almacenar datos para gestionar los `FOR` y los `GOSUB`. |

## Gestión de Entrada/Salida

| Dirección | Hexadecimal | Defecto | Descripción |
|:---------:|:-----------:|:-------:|-------------|
| 512-600 | \$0200-\$0258 | - | Buffer de entrada, para leer datos de la pantalla (89 bytes). |
| 601-610 | \$0259-\$0262 | - | Identificadores de ficheros abiertos (10 bytes, 10 entradas). |
| 611-620 | \$0263-\$026C | - | Dispositivos de los ficheros abiertos (10 bytes, 10 entradas). |
| 621-630 | \$026D-\$0276 | - | Modo secundario de los ficheros abiertos (10 bytes, 10 entradas). |
| 631-640 | \$0277-\$0280 | - | Buffer de teclado (10 bytes, 10 entradas). |
| 641-642 | \$0281-\$0282 | \$0800 | Puntero al inicio de la memoria para BASIC después del test de memoria. |
| 643-644 | \$0283-\$0284 | \$A000 | Puntero al final de la memoria para BASIC después del test de memoria. |
| 645 | \$0285 | - | Sin uso (*timeout* del puerto serie). |
| 646 | \$0286 | - | Color del cursor (**\$00**-**\$0F**). |
| 647 | \$0287 | - | Color del carácter bajo el cursor (**\$00**-**\$0F**). |
| 648 | \$0288 | \$04 | Byte alto del puntero a la memoria de pantalla para la entrada/salida de la terminal. |
| 649 | \$0289 | - | Tamaño máximo del buffer de teclado (**\$00** = Sin buffer; **\$01-\$0F** = Tamaño). |
| 650 | \$028A | - | Flag de repetición del teclado. **Bits 6-7:** **00** = `⇑CRSR⇓`, `⇐CRSR⇒`, `INST/DEL` y `SPACE`; **01** = Ninguna; **1x** = Todas. |
| 651 | \$028B | - | Retardo durante la repetición, entre sucesivas repeticiones (**\$00** = Sin retardo; **\$01-\$04** = Con retardo). |
| 652 | \$028C | - | Retardo durante la repetición, para retardar antes de la primera repetición (**\$00** = Sin retardo; **\$01-\$04** = Con retardo). |
| 653 | \$028D | - | Indicador de teclas modificadoras:<br/>+ **Bit 0:** **1** = Alguna tecla `SHIFT` está pulsada.<br/>+ **Bit 1:** **1** = La tecla `C=` está pulsada.<br/>+ **Bit 2:** **1** = La tecla `CTRL` está pulsada. |
| 654 | \$028E | - | Indicador previo de teclas modificadoras en el anterior escaneo:<br/>+ **Bit 0:** **1** = Alguna tecla `SHIFT` estuvo pulsada.<br/>+ **Bit 1:** **1** = La tecla `C=` estuvo pulsada.<br/>+ **Bit 2:** **1** = La tecla `CTRL` estuvo pulsada. |
| 655-656 | \$028F-\$0290 | \$EB48 | Puntero a la rutina, que basada en el estado de las teclas modificadoras, modifica el puntero en la dirección \$00F5-\$00F6 a la tabla de conversión pertinente que traduce códigos de teclado a PETSCII. |
| 657 | \$0291 | - | Flag `C=`+`SHIFT` para cambiar entre los modos de fuente de la terminal (**Bit 7:** **0** = Activado; **1** = Desactivado). |
| 658 | \$0292 | - | Flag de dirección del desplazamiento en la terminal (**\$00** = Insertar líneas desplazando hacia abajo; **\$01-\$FF** = Insertar líneas desplazando hacia arriba). |
| 659 | \$0293 | - | Registro de control del RS-232:<br/>+ **Bits 0-3:** Velocidad de transferencia en baudios. Valores:<br/>**0000** = Valor Usuario;<br/>**0001** = 50 bit/s;<br/>**0010** = 75 bit/s;<br/>**0011** = 110 bit/s;<br/>**0100** = 150 bit/s;<br/>**0101** = 300 bit/s;<br/>**0110** = 600 bit/s;<br/>**0111** = 1200 bit/s;<br/>**1000** = 2400 bit/s;<br/>**1001** = 1800 bit/s;<br/>**1010** = 2400 bit/s;<br/>**1011** = 3600 bit/s;<br/>**1100** = 4800 bit/s;<br/>**1101** = 7200 bit/s;<br/>**1110** = 9600 bit/s;<br/>**1111** = 19200 bit/s.<br/>+ **Bits 5-6:** Número de bits de datos por byte (**00** = 8; **01** = 7; **10** = 6; **11** = 5).<br/>+ **Bit 7:** Número de bits de parada (**0** = 1; **1** = 2). |
| 660 | \$0294 | - | Registro de comandos del RS-232:<br/>+ **Bit 0:** Tipo de sincronización (**0** = 3 líneas; **1** = X líneas).<br/>+ **Bit 4:** Tipo de transmisión (**0** = Duplex; **1** = Half duplex).<br/>+ **Bits 5-7:** Modo de paridad. Valores:<br/>**xx0** = Sin comprobación de paridad, el bit 7 no existe;<br/>**001** = Paridad impar;<br/>**011** = Paridad par;<br/>**101** = Sin comprobación de paridad, el bit 7 es siempre 1;<br/>**111** = Sin comprobación de paridad, el bit 7 es siempre 0. |
| 661-662 | \$0295-\$0296 | - | Valor por defecto del reloj de salida del RS-232, basado en la velocidad en baudios. (Debe ser configurado, antes de cualquier operación de E/S, si la velocidad en baudios es "Valor Usuario" en \$0293.) |
| 663 | \$0297 | - | Valor de la variable `STATUS` para el estado del dispositivo para la E/S del RS-232:<br/>+ **Bit 0:** **1** = Error de paridad.<br/>+ **Bit 1:** **1** = Error de marco (bit de stop con el valor 0).<br/>+ **Bit 2:** **1** = Desbordamiento del buffer de entrada (demasiada información ha llegado sin ser leída del buffer).<br/>+ **Bit 3:** **1** = Buffer de entrada vacío, nada que leer.<br/>+ **Bit 4:** **0** = *Sender* en CTS; **1** = *Sender* no preparado para enviar.<br/>+ **Bit 6:** **0** = *Receiver* en DSR; **1** = *Receiver* no preparado para recibir.<br/>+ **Bit 7:** **1** = Fallo de envío, un bit de parada y de datos ambos con el valor 0. |
| 664 | \$0298 | - | Tamaño de byte del RS-232, número de bits de datos por byte de datos, valor por defecto del conteo de bits. |
| 665-666 | \$0299-\$029A | - | Valor por defecto del reloj de entrada del RS-232, basado en la velocidad en baudios. (Calculado automáticamente con el valor en \$0295-\$0296.) |
| 667 | \$029B | - | Desplazamiento del byte recibido en el búfer de entrada RS-232. |
| 668 | \$029C | - | Desplazamiento del byte actual en el búfer de entrada RS-232. |
| 669 | \$029D | - | Desplazamiento del byte recibido en el búfer de salida RS-232. |
| 670 | \$029E | - | Desplazamiento del byte actual en el búfer de salida RS-232. |
| 671-672 | \$029F-\$02A0 | - | Área temporal para guardar el puntero original a la rutina de servicio de interrupciones durante la E/S del *datasette*:<br/>+ **\$0000-\$00FF** = Ninguna E/S del *datasette* ha ocurrido o el puntero original ya ha sido restaurado.<br/>+ **\$0100-\$FFFF** = El puntero original, E/S del *datasette* actualmente en progreso. |
| 673 | \$02A1 | - | Área temporal para guardar el estado original del registro de control de interrupciones de la CIA2 (\$DD0D) durante la E/S del RS-232. |
| 674 | \$02A2 | - | Área temporal para guardar el estado original del registro de control de la cuenta atrás B de la CIA2 (\$DC0F) durante la E/S del *datasette*. |
| 675 | \$02A3 | - | Área temporal para guardar el estado original del registro de control de interrupciones de la CIA1 (\$DC0D) durante la E/S del *datasette*. |
| 676 | \$02A4 | - | Área temporal para guardar el estado original del registro de control de la cuenta atrás A de la CIA2 (\$DC0E) durante la E/S del *datasette*. |
| 677 | \$02A5 | - | Número de línea siendo desplazada durante el desplazamiento de la pantalla. |
| 678 | \$02A6 | - | Flag PAL/NTSC, para seleccionar la velocidad adecuada en baudios para el RS-232 (**\$00** = NTSC; **\$01** = PAL). |
| 679-767 | \$02A7-\$02FF | - | Sin uso (89 bytes). |

## Memoria del Sistema

| Dirección | Hexadecimal | Defecto | Descripción |
|:---------:|:-----------:|:-------:|-------------|
| 768-769 | \$0300-\$0301 | \$E38B | Puntero a la rutina de reinicio suave, mostrando si hay algún mensaje de error y entrando en el bucle de inactividad de BASIC. |
| 770-771 | \$0302-\$0303 | \$A483 | Puntero a la rutina del bucle de inactividad de BASIC. |
| 772-773 | \$0304-\$0305 | \$A57C | Puntero a la rutina del *tokenizer* de BASIC. |
| 774-775 | \$0306-\$0307 | \$A71A | Puntero a la rutina de descodificación de tokens de BASIC. |
| 776-777 | \$0308-\$0309 | \$A7E4 | Puntero a la rutina de ejecución de instrucciones BASIC. |
| 778-779 | \$030A-\$030B | \$AE86 | Puntero a la rutina que lee el siguiente elemento en una expresión BASIC. |
| 780 | \$030C | - | Registro A para `SYS`. |
| 781 | \$030D | - | Registro X para `SYS`. |
| 782 | \$030E | - | Registro Y para `SYS`. |
| 783 | \$030F | - | Registro de estado para `SYS`. |
| 784-786 | \$0310-\$0312 | - | Instrucción JMP ABS para saltar a la función `USR`, cuya dirección está en \$0311-\$0312. |
| 787 | \$0313 | - | Sin uso. |
| 788-789 | \$0314-\$0315 | \$EA31 | Puntero a la rutina de servicio de interrupciones. |
| 790-791 | \$0316-\$0317 | \$FE66 | Puntero a la rutina de servicio BRK. |
| 792-793 | \$0318-\$0319 | \$FE47 | Puntero a la rutina de servicio de interrupciones no-enmascarables. |
| 794-795 | \$031A-\$031B | \$F34A | Puntero a OPEN, rutina para abrir ficheros. |
| 796-797 | \$031C-\$031D | \$F291 | Puntero a CLOSE, rutina para cerrar ficheros. |
| 798-799 | \$031E-\$031F | \$F20E | Puntero a CHKIN, rutina para definir un fichero como entrada por defecto. |
| 800-801 | \$0320-\$0321 | \$F250 | Puntero a CHKOUT, rutina para definir un fichero como salida por defecto. |
| 802-803 | \$0322-\$0323 | \$F333 | Puntero a CLRCHN, rutina de inicialización de la E/S. |
| 804-805 | \$0324-\$0325 | \$F157 | Puntero a CHRIN, rutina de entrada de datos, salvo para el teclado y RS-232. |
| 806-807 | \$0326-\$0327 | \$F1CA | Puntero a CHROUT, rutina de salida de datos de propósito general. |
| 808-809 | \$0328-\$0329 | \$F6ED | Puntero a STOP, rutina para comprobar el estado del indicador de la tecla `RUN/STOP`, en la dirección \$0091. |
| 810-811 | \$032A-\$032B | \$F13E | Puntero a GETIN, rutina de entrada de datos de propósito general. |
| 812-813 | \$032C-\$032D | \$F32F | Puntero a CLALL, rutina para inicializar la E/S y limpiar la tablas de asignación de ficheros. |
| 814-815 | \$032E-\$032F | \$FE66 | Sin uso. |
| 816-817 | \$0330-\$0331 | \$F4A5 | Puntero a LOAD, rutina de cargar ficheros. |
| 818-819 | \$0332-\$0333 | \$F5ED | Puntero a SAVE, rutina de guardar fichero. |
| 820-827 | \$0334-\$033B | - | Sin uso (8 bytes). |
| 828-1019 | \$033C-\$03FB | - | Buffer del *datasette* (192 bytes). |
| 1020-1023 | \$03FC-\$03FF | - | Sin uso (4 bytes). |

## Buffer de pantalla inicial

| Dirección | Hexadecimal | Descripción |
|:---------:|:-----------:|-------------|
| 1024-2023 | \$0400-\$07E7 | Buffer de pantalla (1000 bytes). |
| 2024-2039 | \$07E8-\$07F7 | Sin uso (16 bytes). |
| 2040-2047 | \$07F8-\$07FF | Punteros de sprites (8 bytes). |

**NOTA:** Al iniciar el C64 esta es la región por defecto para el buffer de pantalla y los punteros de sprite, pero se puede cambiar esa configuración en los registros del VIC-II.

## Memoria de programas

| Dirección | Hexadecimal | Descripción |
|:---------:|:-----------:|-------------|
| 2048 | \$0800 | Sin uso (necesita el valor 0 para poder ejecutar los programas BASIC). |
| 2049-40959 | \$0801-\$9FFF | Memoria para programas BASIC (38911 bytes). |
| 32768-40959 | \$8000-\$9FFF | ROM de cartuchos opcional (8192 bytes).<br/>\$8000-\$8001: Puntero a la ejecución del reinicio frío.<br/>\$8002-\$8003: Puntero a la ejecución de rutinas de interrupción no enmascarables.<br/>\$8004-\$8008: Firma del cartucho, si contiene la cadena PETSCII `"CBM80"` los vectores de rutinas son aceptados por el KERNAL. |
| 40960-49151 | \$A000-\$BFFF | ROM BASIC/Memoria RAM. |
| 49152-53247 | \$C000-\$CFFF | Memoria RAM superior. |

## ROM de las fuentes de caracteres

| Dirección | Hexadecimal | Descripción |
|:---------:|:-----------:|-------------|
| 53248-55295 | \$D000-\$D7FF | Fuente del modo mayúsculas (2048 bytes, 256 caracteres). |
| 55295-57343 | \$D800-\$DFFF | Fuente del modo minúsculas (2048 bytes, 256 caracteres). |

<p align="center"><img src="https://upload.wikimedia.org/wikipedia/commons/d/d8/Fonts-C64.png" alt="Fuentes del C64"></p>

**NOTA:** Por defecto esta ROM no es accesible, porque la memoria está configurada para acceder a los registros en memoria del VIC-II, SID, CIA1 y CIA2, para realizar operaciones de entrada y salida.

## Chip gráfico VIC-II

| Dirección | Hexadecimal | Defecto | Descripción |
|:---------:|:-----------:|:-------:|-------------|
| 53248 | \$D000 | - | Coordenada X del *sprite* 0 (bits del 0-7). |
| 53249 | \$D001 | - | Coordenada Y del *sprite* 0. |
| 53250 | \$D002 | - | Coordenada X del *sprite* 1 (bits del 0-7). |
| 53251 | \$D003 | - | Coordenada Y del *sprite* 1. |
| 53252 | \$D004 | - | Coordenada X del *sprite* 2 (bits del 0-7). |
| 53253 | \$D005 | - | Coordenada Y del *sprite* 2. |
| 53254 | \$D006 | - | Coordenada X del *sprite* 3 (bits del 0-7). |
| 53255 | \$D007 | - | Coordenada Y del *sprite* 3. |
| 53256 | \$D008 | - | Coordenada X del *sprite* 4 (bits del 0-7). |
| 53257 | \$D009 | - | Coordenada Y del *sprite* 4. |
| 53258 | \$D00A | - | Coordenada X del *sprite* 5 (bits del 0-7). |
| 53259 | \$D00B | - | Coordenada Y del *sprite* 5. |
| 53260 | \$D00C | - | Coordenada X del *sprite* 6 (bits del 0-7). |
| 53261 | \$D00D | - | Coordenada Y del *sprite* 6. |
| 53262 | \$D00E | - | Coordenada X del *sprite* 7 (bits del 0-7). |
| 53263 | \$D00F | - | Coordenada Y del *sprite* 7. |
| 53264 | \$D010 | - | Bit 8 de la coordenada X de los *sprites* 0-7. |
| 53265 | \$D011 | \$1B (00011011) | Registro de control de la pantalla:<br/>+ **Bits 0-2:** Desplazamiento del *raster* vertical (*scroll raster*).<br/>+ **Bit 3:** Altura de pantalla. **0** = 24 filas; **1** = 25 filas.<br/>+ **Bit 4:** **0** = Pantalla apagada; **1** = Pantalla encendida.<br/>+ **Bit 5:** **0** = Modo texto; **1** = Modo bitmap.<br/>+ **Bit 6:** **1** = Modo fondo extendido activado.<br/>+ **Bit 7:** Lectura: Línea actual del *raster* (bit 8); Escritura: Línea del *raster* en la que generar una interrupción (bit 8). |
| 53266 | \$D012 | - | Lectura: Línea actual del *raster* (bits 0-7); Escritura: Línea del *raster* en la que generar una interrupción (bits 0-7). |
| 53267 | \$D013 | - | Coordenada X del lápiz de luz (bits 1-8). |
| 53268 | \$D014 | - | Coordenada Y del lápiz de luz. |
| 53269 | \$D015 | - | Registro de activación de *sprites*. **Bits 0-7:** *Sprite* 0-7 activado para dibujarlo en pantalla. |
| 53270 | \$D016 | \$C8 (11001000) | Registro 2 de control de la pantalla:<br/>+ **Bits 0-2:** Desplazamiento del *raster* horizontal (*scroll raster*).<br/>+ **Bit 3:** Ancho de pantalla. **0** = 38 filas; **1** = 40 filas.<br/>+ **Bit 4:** **1** = Modo multicolor activado. |
| 53271 | \$D017 | - | Registro de doble altura de *sprites*. **Bits 0-7:** Doble altura del *sprite* 0-7 activada. |
| 53272 | \$D018 | - | Registro de configuración de la memoria:<br/>+ **Bits 1-3:** Puntero a la memoria de caracteres en el modo texto (bits 11-13), relativo al banco seleccionado para el VIC con \$DD00. Valores:<br/>**000** = \$0000-\$07FF (0-2047);<br/>**001** = \$0800-\$0FFF (2048-4095);<br/>**010** = \$1000-\$17FF (4096-6143);<br/>**011** = \$1800-\$1FFF (6144-8191);<br/>**100** = \$2000-\$27FF (8192-10239);<br/>**101** = \$2800-\$2FFF (10240-12287);<br/>**110** = \$3000-\$37FF (12288-14335);<br/>**111** = \$3800-\$3FFF (14336-16383).<br/>(Los valores 010 y 011 con el banco 0 y 2 del VIC selecciona la ROM de caracteres en lugar de la RAM.)<br/>+ **Bits 1-3:** Puntero a la memoria de bitmap en el modo bitmap (bit 13), relativo al banco seleccionado para el VIC con \$DD00. Valores:<br/>**0xx** = \$0000-\$1FFF (0-8191);<br/>**1xx** = \$2000-\$3FFF (8192-16383).<br/>+ **Bits 4-7:** Puntero a la memoria de pantalla (bits 10-13), relativo al banco seleccionado para el VIC con \$DD00. Valores:<br/>**0000** = \$0000-\$03FF (0-1023);<br/>**0001** = \$0400-\$07FF (1024-2047);<br/>**0010** = \$0800-\$0BFF (2048-3071);<br/>**0011** = \$0C00-\$0FFF (3072-4095);<br/>**0100** = \$1000-\$13FF (4096-5119);<br/>**0101** = \$1400-\$17FF (5120-6143);<br/>**0110** = \$1800-\$1BFF (6144-7167);<br/>**0111** = \$1C00-\$1FFF (7168-8191);<br/>**1000** = \$2000-\$23FF (8192-9215);<br/>**1001** = \$2400-\$27FF (9216-10239);<br/>**1010** = \$2800-\$2BFF (10240-11263);<br/>**1011** = \$2C00-\$2FFF (11264-12287);<br/>**1100** = \$3000-\$33FF (12288-13311);<br/>**1101** = \$3400-\$37FF (13312-14335);<br/>**1110** = \$3800-\$3BFF (14336-15359);<br/>**1111** = \$3C00-\$3FFF (15360-16383). |
| 53273 | \$D019 | - | Registro de estado de interrupciones. Bits de lectura:<br/>+ **Bit 0:** **1** = La línea actual de *raster* es igual a la que genera una interrupción.<br/>+ **Bit 1:** **1** = Colisión *sprite*-fondo.<br/>+ **Bit 2:** **1** = Colisión *sprite*-*sprite*.<br/>+ **Bit 3:** **1** = Señal recibida del lápiz de luz.<br/>+ **Bit 7:** **1** = Se ha generado una interrupción, por un evento o varios, y esta no ha sido admitida.<br/>Bits de escritura:<br/>+ **Bit 0:** **1** = Admitida una interrupción de *raster*.<br/>+ **Bit 1:** **1** = Admitida una interrupción de colisión *sprite*-fondo.<br/>+ **Bit 2:** **1** = Admitida una interrupción de colisión *sprite*-*sprite*.<br/>+ **Bit 3:** **1** = Admitida una interrupción de lápiz de luz. |
| 53274 | \$D01A | - | Registro de control de interrupciones:<br/>+ **Bit 0:** **1** = Activa las interrupciones de *raster*.<br/>+ **Bit 1:** **1** = Activa las interrupciones de colisión *sprite*-fondo.<br/>+ **Bit 2:** **1** = Activa las interrupciones de colisión *sprite*-*sprite*.<br/>+ **Bit 3:** **1** = Activa las interrupciones de lápiz de luz. |
| 53275 | \$D01B | - | Registro de prioridad de *sprites*. **Bits 0-7:** **0** = Pintar *sprite* 0-7 delante de la pantalla; **1** = Pintar *sprite* 0-7 detrás de la pantalla. |
| 53276 | \$D01C | - | Registro de modo multicolor de *sprites*. **Bits 0-7:** **0** = *Sprite* 0-7 monocolor; **1** = *Sprite* 0-7 multicolor. |
| 53277 | \$D01D | - | Registro de doble anchura de *sprites*. **Bits 0-7:** Doble anchura del *sprite* 0-7 activada. |
| 53278 | \$D01E | - | Registro de colisión *sprite*-*sprite*. Lectura de bits: **Bits 0-7:** **1** = El *sprite* 0-7 ha colisionado con otro *sprite*. Escritura de bits: Activa la detección de las colisiones *sprite*-*sprite*. |
| 53279 | \$D01F | - | Registro de colisión *sprite*-fondo. Lectura de bits: **Bits 0-7:** **1** = El *sprite* 0-7 ha colisionado con el fondo. Escritura de bits: Activa la detección de las colisiones *sprite*-fondo. |
| 53280 | \$D020 | - | Color del borde. **Bits 0-3:** 0-15. |
| 53281 | \$D021 | - | Color del fondo. **Bits 0-3:** 0-15. |
| 53282 | \$D022 | - | Color extra 1 del fondo. **Bits 0-3:** 0-15. |
| 53283 | \$D023 | - | Color extra 2 del fondo. **Bits 0-3:** 0-15. |
| 53284 | \$D024 | - | Color extra 3 del fondo. **Bits 0-3:** 0-15. |
| 53285 | \$D025 | - | Color extra 1 de *sprites*. **Bits 0-3:** 0-15. |
| 53286 | \$D026 | - | Color extra 2 de *sprites*. **Bits 0-3:** 0-15. |
| 53287 | \$D027 | - | Color del *sprite* 0. **Bits 0-3:** 0-15. |
| 53288 | \$D028 | - | Color del *sprite* 1. **Bits 0-3:** 0-15. |
| 53289 | \$D029 | - | Color del *sprite* 2. **Bits 0-3:** 0-15. |
| 53290 | \$D02A | - | Color del *sprite* 3. **Bits 0-3:** 0-15. |
| 53291 | \$D02B | - | Color del *sprite* 4. **Bits 0-3:** 0-15. |
| 53292 | \$D02C | - | Color del *sprite* 5. **Bits 0-3:** 0-15. |
| 53293 | \$D02D | - | Color del *sprite* 6. **Bits 0-3:** 0-15. |
| 53294 | \$D02E | - | Color del *sprite* 7. **Bits 0-3:** 0-15. |
| 53295-53311 | \$D02F-\$D03F | - | Sin uso (17 bytes). |
| 53312-54271 | \$D040-\$D3FF | - | Duplicados del VIC-II (segmentos de 64 bytes). |

## Chip sonoro SID

| Dirección | Hexadecimal | Modo L/E | Descripción |
|:---------:|:-----------:|:--------:|-------------|
| 54272-54273 | \$D400-\$D401 | Escritura | Frecuencia de la voz 1 (*Frequency*). |
| 54274-54275 | \$D402-\$D403 | Escritura | Ancho de pulso de la voz 1 (*Pulse Width*). |
| 54276 | \$D404 | Escritura | Registros de control de la voz 1:<br/>+ **Bit 0:** **0** = Apagar voz (modo *Release*); **1** = Encender voz (modo *Attack-Decay-Sustain*).<br/>+ **Bit 1:** **1** = Activar sincronización.<br/>+ **Bit 2:** **1** = Activar modulación de anillo (*Ring Modulator*).<br/>+ **Bit 3:** **1** = Desactivar voz, reiniciar generador de ruido (*Noise Generator*).<br/>+ **Bit 4:** **1** = Activar onda triangular (*Triangle*).<br/>+ **Bit 5:** **1** = Activar onda en sierra (*Saw*).<br/>+ **Bit 6:** **1** = Activar onda cuadrada (*Square*).<br/>+ **Bit 7:** **1** = Activar ruido (*Noise*). |
| 54277 | \$D405 | Escritura | *Attack* y *Decay* de la voz 1:<br/>+ **Bits 0-3:** Nivel de *Decay* (0-15).<br/>+ **Bits 4-7:** Nivel de *Attack* (0-15). |
| 54278 | \$D406 | Escritura | *Sustain* y *Release* de la voz 1:<br/>+ **Bits 0-3:** Nivel de *Release* (0-15).<br/>+ **Bits 4-7:** Volumen de *Sustain* (0-15). |
| 54279-54280 | \$D407-\$D408 | Escritura | Frecuencia de la voz 2 (*Frequency*). |
| 54281-54282 | \$D409-\$D40A | Escritura | Ancho de pulso de la voz 2 (*Pulse Width*). |
| 54283 | \$D40B | Escritura | Registros de control de la voz 2. |
| 54284 | \$D40C | Escritura | *Attack* y *Decay* de la voz 2. |
| 54285 | \$D40D | Escritura | *Sustain* y *Release* de la voz 2. |
| 54286-54287 | \$D40E-\$D40F | Escritura | Frecuencia de la voz 3 (*Frequency*). |
| 54288-54289 | \$D410-\$D411 | Escritura | Ancho de pulso de la voz 3 (*Pulse Width*). |
| 54290 | \$D412 | Escritura | Registros de control de la voz 3. |
| 54291 | \$D413 | Escritura | *Attack* y *Decay* de la voz 3. |
| 54292 | \$D414 | Escritura | *Sustain* y *Release* de la voz 3. |
| 54293 | \$D415 | Escritura | Filtro de corte de frecuencias (*Cut Off*).<br/>**Bits 0-2:** Bits 0-2 del valor final. |
| 54294 | \$D416 | Escritura | Filtro de corte de frecuencias (*Cut Off*).<br/>**Bits 0-7:** Bits 3-10 del valor final. |
| 54295 | \$D417 | Escritura | Control del filtro:<br/>+ **Bit 0:** **1** = Voz 1 filtrada.<br/>+ **Bit 1:** **1** = Voz 2 filtrada.<br/>+ **Bit 2:** **1** = Voz 3 filtrada.<br/>+ **Bit 3:** **1** = Voz externa filtrada.<br/>+ **Bits 4-7:** Resonancia del filtro (*Resonance*). |
| 54296 | \$D418 | Escritura | Volumen y modos de filtrado:<br/>+ **Bits 0-3:** Volumen.<br/>+ **Bit 4:** **1** = Filtro de paso bajo activado (LPF).<br/>+ **Bit 5:** **1** = Filtro de paso banda activado (BPF).<br/>+ **Bit 6:** **1** = Filtro de paso alto activado (HPF).<br/>+ **Bit 7:** Voz 3 desactivada. |
| 54297 | \$D419 | Lectura | Valor X del paddle seleccionado en \$DC00. (Se actualiza cada 512 ciclos.) |
| 54298 | \$D41A | Lectura | Valor Y del paddle seleccionado en \$DC00. (Se actualiza cada 512 ciclos.) |
| 54299 | \$D41B | Lectura | Salida de onda de la voz 3. |
| 54300 | \$D41C | Lectura | Salida del ADSR de la voz 3. |
| 54301-54303 | \$D41D-\$D41F | - | Sin uso (3 bytes). |
| 54304-55295 | \$D420-\$D7FF | - | Duplicados del SID (segmentos de 32 bytes). |

Tabla de valores para los niveles del ADSR:

| Nivel | Binario | Hexadecimal | Attack | Decay | Release |
|:-----:|:-------:|:-----------:|:------:|:-----:|:-------:|
| 0  | 0000 | 0 |   2 ms |   6 ms |   6 ms |
| 1  | 0001 | 1 |   8 ms |  24 ms |  24 ms |
| 2  | 0010 | 2 |  16 ms |  48 ms |  48 ms |
| 3  | 0011 | 3 |  24 ms |  72 ms |  72 ms |
| 4  | 0100 | 4 |  38 ms | 114 ms | 114 ms |
| 5  | 0101 | 5 |  56 ms | 168 ms | 168 ms |
| 6  | 0110 | 6 |  68 ms | 204 ms | 204 ms |
| 7  | 0111 | 7 |  80 ms | 240 ms | 240 ms |
| 8  | 1000 | 8 | 100 ms | 300 ms | 300 ms |
| 9  | 1001 | 9 | 250 ms | 750 ms | 750 ms |
| 10 | 1010 | A | 500 ms | 1.5 s  | 1.5 s  |
| 11 | 1011 | B | 800 ms | 2.4 s  | 2.4 s  |
| 12 | 1100 | C |   1 s  |   3 s  |   3 s  |
| 13 | 1101 | D |   3 s  |   9 s  |   9 s  |
| 14 | 1110 | E |   5 s  |  15 s  |  15 s  |
| 15 | 1111 | F |   8 s  |  24 s  |  24 s  |

## Buffer de color de pantalla

| Dirección | Hexadecimal | Descripción |
|:---------:|:-----------:|-------------|
| 55296-56295 | \$D800-\$DBE7 |Buffer de color de la pantalla (1000 bytes).<br/>**Bits 0-3:** Color del 0 al 15. |
| 56296-56319 | \$DBE8-\$DBFF | Sin uso (24 bytes). |

## CIA1: Entrada, Datasette, IRQ

| Dirección | Hexadecimal | Descripción |
|:---------:|:-----------:|-------------|
| 56320 | \$DC00 | Puerto A: Matriz de teclado y joystick 2. Lectura de bits:<br>+ **Bit 0:** **0** = Arriba del Joystick 2 pulsado.<br>+ **Bit 1:** **0** = Abajo del Joystick 2 pulsado.<br>+ **Bit 2:** **0** = Izquierda del Joystick 2 pulsado.<br>+ **Bit 3:** **0** = Derecha del Joystick 2 pulsado.<br>+ **Bit 4:** **0** = Disparo del Joystick 2 pulsado.<br>Escritura de bits:<br>+ **Bit 0-7:** **0** = Seleccionar que fila en la matriz del teclado leer.<br>+ **Bit 6-7:** **01** Paddle 1; **10** Paddle 2. |
| 56321 | \$DC01 | Puerto B: Matriz de teclado y joystick 1. Lectura de bits:<br>+ **Bit 0:** **0** = Arriba del Joystick 1 pulsado.<br>+ **Bit 1:** **0** = Abajo del Joystick 1 pulsado.<br>+ **Bit 2:** **0** = Izquierda del Joystick 1 pulsado.<br>+ **Bit 3:** **0** = Derecha del Joystick 1 pulsado.<br>+ **Bit 4:** **0** = Disparo del Joystick 1 pulsado.<br>+ **Bit 0-7:** **0** = Tecla pulsada en la fila seleccionada de la matriz del teclado. |
| 56322 | \$DC02 | Configuración del puerto A. **Bits 0-7:** **0** = Lectura; **1** = Escritura/Lectura. |
| 56323 | \$DC03 | Configuración del puerto B. **Bits 0-7:** **0** = Lectura; **1** = Escritura/Lectura. |
| 56324-56325 | \$DC04-\$DC05 | Cuenta atrás A (*Timer*). Lectura: Valor actual. Escritura: Marca de tiempo inicial. |
| 56326-56327 | \$DC06-\$DC07 | Cuenta atrás B (*Timer*). Lectura: Valor actual. Escritura: Marca de tiempo inicial. |
| 56328 | \$DC08 | Reloj Del Sistema: Décimas en formato BCD (\$00-\$09). Lectura: Valor actual. Escritura: Configurar RDS o alarma. |
| 56329 | \$DC09 | Reloj Del Sistema: Segundos en formato BCD (\$00-\$59). Lectura: Valor actual. Escritura: Configurar RDS o alarma. |
| 56330 | \$DC0A | Reloj Del Sistema: Minutos en formato BCD (\$00-\$59). Lectura: Valor actual. Escritura: Configurar RDS o alarma. |
| 56331 | \$DC0B | Reloj Del Sistema: Horas en formato BCD (**Bits 0-5:** Horas; **Bit 7:** **0** = AM, **1** = PM). Lectura: Valor actual. Escritura: Configurar RDS o alarma. |
| 56332 | \$DC0C | Registro de cambios en serie (*serial shift*). (Los bits son leídos y escritos cada salto positivo del pin CNT.) |
| 56333 | \$DC0D | Registro de estado y control de interrupciones. Bits de lectura:<br>+ **Bit 0:** **1** = Desbordamiento inferior en la cuenta atrás A.<br>+ **Bit 1:** **1** = Desbordamiento inferior en la cuenta atrás B.<br>+ **Bit 2:** **1** = El RDS es igual a la hora de alarma.<br>+ **Bit 3:** **1** = Un byte completo se ha recibido o enviado desde el registro de cambios en serie (*serial shift*).<br>+ **Bit 4:** Nivel de señal en el pin FLAG, lectura del *datasette*.<br>+ **Bit 7:** Una interrupción ha sido generada.<br>Bits de escritura:<br>+ **Bit 0:** **1** = Activar las interrupciones de desbordamiento inferior en la cuenta atrás A.<br>+ **Bit 1:** **1** = Activar las interrupciones de desbordamiento inferior en la cuenta atrás B.<br>+ **Bit 2:** **1** = Activar las interrupciones de la alarma.<br>+ **Bit 3:** **1** = Activar las interrupciones por recibir/enviar un byte completo en el registro de cambios en serie (*serial shift*).<br>+ **Bit 4:** **1** = Activar las interrupciones por un salto positivo en el pin FLAG.<br>+ **Bit 7:** Bit de relleno para los bits 0-6 (1 = Toman el valor del bit; 0 = No son modificados). |
| 56334 | \$DC0E | Registro de control de la cuenta atrás A:<br>+ **Bit 0:** **0** = Parar; **1** = Iniciar.<br>+ **Bit 1:** **1** = Indica desbordamiento inferior del temporizador en el bit 6 del puerto B.<br>+ **Bit 2:** **0** = Invertir el bit 6 del puerto B con el desbordamiento inferior; **1** = Generar con el desbordamiento inferior un salto positivo en el bit 6 del puerto B durante un ciclo de la CPU.<br>+ **Bit 3:** Acción de la cuenta atrás cuando hay un desbordamiento inferior. **0** = Reiniciar; **1** = Parar.<br>+ **Bit 4:** **1** = Carga el valor de inicio de la cuenta atrás.<br>+ **Bit 5:** Modo de la cuenta atrás. **0** = Ciclos de la CPU; **1** = Saltos positivos del pin CNT.<br>+ **Bit 6:** Configuración del registro de cambios en serie (*serial shift*). **0** = Lectura; **1** = Escritura.<br>+ **Bit 7:** Velocidad del RDS. **0** = 60 Hz; **1** = 50 Hz. |
| 56335 | \$DC0F | Registro de control de la cuenta atrás B:<br>+ **Bit 0:** **0** = Parar; **1** = Iniciar.<br>+ **Bit 1:** **1** = Indica desbordamiento inferior del temporizador en el bit 7 del puerto B.<br>+ **Bit 2:** **0** = Invertir el bit 7 del puerto B con el desbordamiento inferior; **1** = Generar con el desbordamiento inferior un salto positivo en el bit 7 del puerto B durante un ciclo de la CPU.<br>+ **Bit 3:** Acción de la cuenta atrás cuando hay un desbordamiento inferior. **0** = Reiniciar; **1** = Parar.<br>+ **Bit 4:** **1** = Carga el valor de inicio de la cuenta atrás.<br>+ **Bit 5-6:** Acciones de la cuenta atrás. **00** = Contar ciclos de la CPU; **01** = Contar saltos positivos del pin CNT; **10** = Contar desbordamientos inferiores de la cuenta atrás A; **11** = Contar desbordamientos inferiores de la cuenta atrás A que ocurren cuando hay un salto positivo en el pin CNT.<br>+ **Bit 7:** Acción cuando se escribe el RDS. **0** = Configurar el RDS; **1** = Configurar la alarma. |
| 56336-56575 | \$DC10-\$DCFF | Duplicados de la CIA1 (segmentos de 16 bytes). |

## CIA2: Puerto Serie, RS-232, NMI

| Dirección | Hexadecimal | Descripción |
|:---------:|:-----------:|-------------|
| 56576 | \$DD00 | Puerto A: Puerto Serie.<br/> + **Bits 0-1:** Banco del VIC-II. **00** = Banco 3 \$C000-\$FFFF (49152-65535); **01** = Banco 2 \$8000-\$BFFF (32768-49151); **10** = Banco 1 \$4000-\$7FFF (16384-32767); **11** = Banco 0 \$0000-\$3FFF (0-16383).<br/>+ **Bit 2:** TXD del RS-232 (bit de salida).<br/>+ **Bit 3:** ATN OUT del Puerto Serie. **0** = Alto; **1** = Bajo.<br/>+ **Bit 4:** CLOCK OUT del Puerto Serie. **0** = Alto; **1** = Bajo.<br/>+ **Bit 5:** DATA OUT del Puerto Serie. **0** = Alto; **1** = Bajo.<br/>+ **Bit 6:** CLOCK IN del Puerto Serie. **0** = Bajo; **1** = Alto.<br/>+ **Bit 7:** DATA IN del Puerto Serie. **0** = Bajo; **1** = Alto. |
| 56577 | \$DD01 | Puerto B: RS-232. Bits de lectura:<br/>+ **Bit 0:** RXD del RS-232 (bit de entrada).<br/>+ **Bit 3:** RI del RS-232.<br/>+ **Bit 4:** DCD del RS-232.<br/>+ **Bit 5:** Pin H del puerto de usuario.<br/>+ **Bit 6:** CTS del RS-232. 1 = *Sender* preparado para enviar.<br/>+ **Bit 7:** DSR del RS-232. 1 = *Receiver* preparado para recibir.<br/>Bits de escritura:<br/>+ **Bit 1:** RTS del RS-232. 1 = *Sender* preparado para enviar.<br/>+ **Bit 2:** DTR del RS-232. 1 = *Receiver* preparado para recibir.<br/>+ **Bit 3:** RI del RS-232.<br/>+ **Bit 4:** DCD del RS-232.<br/>+ **Bit 5:** Pin H del puerto de usuario. |
| 56578 | \$DD02 | Configuración del puerto A. **Bits 0-7:** **0** = Lectura; **1** = Escritura/Lectura. |
| 56579 | \$DD03 | Configuración del puerto B. **Bits 0-7:** **0** = Lectura; **1** = Escritura/Lectura. |
| 56580-56581 | \$DD04-\$DD05 | Cuenta atrás A (*Timer*). Lectura: Valor actual. Escritura: Marca de tiempo inicial. |
| 56582-56583 | \$DD06-\$DD07 | Cuenta atrás B (*Timer*). Lectura: Valor actual. Escritura: Marca de tiempo inicial. |
| 56584 | \$DD08 | Reloj Del Sistema: Décimas en formato BCD (\$00-\$09). Lectura: Valor actual. Escritura: Configurar RDS o alarma. |
| 56585 | \$DD09 | Reloj Del Sistema: Segundos en formato BCD (\$00-\$59). Lectura: Valor actual. Escritura: Configurar RDS o alarma. |
| 56586 | \$DD0A | Reloj Del Sistema: Minutos en formato BCD (\$00-\$59). Lectura: Valor actual. Escritura: Configurar RDS o alarma. |
| 56587 | \$DD0B | Reloj Del Sistema: Horas en formato BCD (**Bits 0-5:** Horas; **Bit 7:** **0** = AM, **1** = PM). Lectura: Valor actual. Escritura: Configurar RDS o alarma. |
| 56588 | \$DD0C | Registro de cambios en serie (*serial shift*). (Los bits son leídos y escritos cada salto positivo del pin CNT.) |
| 56589 | \$DD0D | Registro de estado y control de interrupciones. Bits de lectura:<br>+ **Bit 0:** **1** = Desbordamiento inferior en la cuenta atrás A.<br>+ **Bit 1:** **1** = Desbordamiento inferior en la cuenta atrás B.<br>+ **Bit 2:** **1** = El RDS es igual a la hora de alarma.<br>+ **Bit 3:** **1** = Un byte completo se ha recibido o enviado desde el registro de cambios en serie (*serial shift*).<br>+ **Bit 4:** Nivel de señal en el pin FLAG.<br>+ **Bit 7:** Una interrupción no-enmascarable ha sido generada.<br>Bits de escritura:<br>+ **Bit 0:** **1** = Activar las interrupciones no-enmascarables de desbordamiento inferior en la cuenta atrás A.<br>+ **Bit 1:** **1** = Activar las interrupciones no-enmascarables de desbordamiento inferior en la cuenta atrás B.<br>+ **Bit 2:** **1** = Activar las interrupciones no-enmascarables de la alarma.<br>+ **Bit 3:** **1** = Activar las interrupciones no-enmascarables por recibir/enviar un byte completo en el registro de cambios en serie (*serial shift*).<br>+ **Bit 4:** **1** = Activar las interrupciones no-enmascarables por un salto positivo en el pin FLAG.<br>+ **Bit 7:** Bit de relleno para los bits 0-6 (1 = Toman el valor del bit; 0 = No son modificados). |
| 56590 | \$DD0E | Registro de control de la cuenta atrás A:<br>+ **Bit 0:** **0** = Parar; **1** = Iniciar.<br>+ **Bit 1:** **1** = Indica desbordamiento inferior del temporizador en el bit 6 del puerto B.<br>+ **Bit 2:** **0** = Invertir el bit 6 del puerto B con el desbordamiento inferior; **1** = Generar con el desbordamiento inferior un salto positivo en el bit 6 del puerto B durante un ciclo de la CPU.<br>+ **Bit 3:** Acción de la cuenta atrás cuando hay un desbordamiento inferior. **0** = Reiniciar; **1** = Parar.<br>+ **Bit 4:** **1** = Carga el valor de inicio de la cuenta atrás.<br>+ **Bit 5:** Modo de la cuenta atrás. **0** = Ciclos de la CPU; **1** = Saltos positivos del pin CNT.<br>+ **Bit 6:** Configuración del registro de cambios en serie (*serial shift*). **0** = Lectura; **1** = Escritura.<br>+ **Bit 7:** Velocidad del RDS. **0** = 60 Hz; **1** = 50 Hz. |
| 56591 | \$DD0F | Registro de control de la cuenta atrás B:<br>+ **Bit 0:** **0** = Parar; **1** = Iniciar.<br>+ **Bit 1:** **1** = Indica desbordamiento inferior del temporizador en el bit 7 del puerto B.<br>+ **Bit 2:** **0** = Invertir el bit 7 del puerto B con el desbordamiento inferior; **1** = Generar con el desbordamiento inferior un salto positivo en el bit 7 del puerto B durante un ciclo de la CPU.<br>+ **Bit 3:** Acción de la cuenta atrás cuando hay un desbordamiento inferior. **0** = Reiniciar; **1** = Parar.<br>+ **Bit 4:** **1** = Carga el valor de inicio de la cuenta atrás.<br>+ **Bit 5-6:** Acciones de la cuenta atrás. **00** = Contar ciclos de la CPU; **01** = Contar saltos positivos del pin CNT; **10** = Contar desbordamientos inferiores de la cuenta atrás A; **11** = Contar desbordamientos inferiores de la cuenta atrás A que ocurren cuando hay un salto positivo en el pin CNT.<br>+ **Bit 7:** Acción cuando se escribe el RDS. **0** = Configurar el RDS; **1** = Configurar la alarma. |
| 56592-56831 | \$DD10-\$DDFF | Duplicados de la CIA2 (segmentos de 16 bytes). |

## Bloques finales de memoria

| Dirección | Hexadecimal | Defecto | Descripción |
|:---------:|:-----------:|:-------:|-------------|
| 56832-57087 | \$DE00-\$DEFF | - | Área E/S Nº 1 (256 bytes): Registros y/o subrutinas de dispositivos externos opcionales. |
| 57088-57343 | \$DF00-\$DFFF | - | Área E/S Nº 2 (256 bytes): Registros y/o subrutinas de dispositivos externos opcionales. |
| 57344-65535 | \$E000-\$FFFF | - | ROM del KERNAL. |
| 65530-65531 | \$FFFA-\$FFFB | \$FE43 | Puntero a la rutina de servicio de interrupciones no-enmascarables. |
| 65532-65533 | \$FFFC-\$FFFD | \$FCE2 | Puntero al reinicio frío. |
| 65534-65535 | \$FFFE-\$FFFF | \$FF48 | Puntero a la rutina de servicio de interrupciones. |

