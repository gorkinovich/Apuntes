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
| 16 | \$0010 | - | . |
| 17 | \$0011 | - | . |
| 18 | \$0012 | - | . |
| 19 | \$0013 | - | . |
| 20-21 | \$0014-\$0015 | - | . |
| 22 | \$0016 | - | . |
| 23-24 | \$0017-\$0018 | - | . |
| 25-33 | \$0019-\$0021 | - | . |
| 34-37 | \$0022-\$0025 | - | . |
| 38-41 | \$0026-\$0029 | - | . |
| 42 | \$002A | - | Sin uso salvo para responder cuál es el sentido de la vida, el universo y todo lo demás. |
| 43-44 | \$002B-\$002C | - | . |
| 45-46 | \$002D-\$002E | - | . |
| 47-48 | \$002F-\$0030 | - | . |
| 49-50 | \$0031-\$0032 | - | . |
| 51-52 | \$0033-\$0034 | - | . |
| 53-54 | \$0035-\$0036 | - | . |
| 55-56 | \$0037-\$0038 | - | . |
| 57-58 | \$0039-\$003A | - | . |
| 59-60 | \$003B-\$003C | - | . |
| 61-62 | \$003D-\$003E | - | . |
| 63-64 | \$003F-\$0040 | - | . |
| 65-66 | \$0041-\$0042 | - | . |
| 67-68 | \$0043-\$0044 | - | . |
| 69-70 | \$0045-\$0046 | - | . |
| 71-72 | \$0047-\$0048 | - | . |
| 73-74 | \$0049-\$004A | - | . |
| 75-76 | \$004B-\$004C | - | . |
| 77 | \$004D | - | . |
| 78-79 | \$004E-\$004F | - | . |
| 80-81 | \$0050-\$0051 | - | . |
| 82 | \$0052 | - | Sin uso. |
| 83 | \$0053 | - | . |
| 84-86 | \$0054-\$0056 | - | . |
| 87-91 | \$0057-\$005B | - | . |
| 92-96 | \$005C-\$0060 | - | . |
| 97-101 | \$0061-\$0065 | - | . |
| 102 | \$0066 | - | . |
| 103 | \$0067 | - | . |
| 104 | \$0068 | - | . |
| 105-109 | \$0069-\$006D | - | . |
| 110 | \$006E | - | . |
| 111-112 | \$006F-\$0070 | - | . |
| 113-114 | \$0071-\$0072 | - | . |
| 115-138 | \$0073-\$008A | - | . |
| 139-143 | \$008B-\$008F | - | . |
| 144 | \$0090 | - | . |
| 145 | \$0091 | - | . |
| 146 | \$0092 | - | . |
| 147 | \$0093 | - | . |
| 148 | \$0094 | - | . |
| 149 | \$0095 | - | . |
| 150 | \$0096 | - | . |
| 151 | \$0097 | - | . |
| 152 | \$0098 | - | . |
| 153 | \$0099 | - | . |
| 154 | \$009A | - | . |
| 155 | \$009B | - | . |
| 156 | \$009C | - | . |
| 157 | \$009D | - | . |
| 158 | \$009E | - | . |
| 159 | \$009F | - | . |
| 160-162 | \$00A0-\$00A2 | - | . |
| 163 | \$00A3 | - | . |
| 164 | \$00A4 | - | . |
| 165 | \$00A5 | - | . |
| 166 | \$00A6 | - | . |
| 167 | \$00A7 | - | . |
| 168 | \$00A8 | - | . |
| 169 | \$00A9 | - | . |
| 170 | \$00AA | - | . |
| 171 | \$00AB | - | . |
| 172-173 | \$00AC-\$00AD | - | . |
| 174-175 | \$00AE-\$00AF | - | . |
| 176-177 | \$00B0-\$00B1 | - | . |
| 178-179 | \$00B2-\$00B3 | - | . |
| 180 | \$00B4 | - | . |
| 181 | \$00B5 | - | . |
| 182 | \$00B6 | - | . |
| 183 | \$00B7 | - | . |
| 184 | \$00B8 | - | . |
| 185 | \$00B9 | - | . |
| 186 | \$00BA | - | . |
| 187-188 | \$00BB-\$00BC | - | . |
| 189 | \$00BD | - | . |
| 190 | \$00BE | - | . |
| 191 | \$00BF | - | . |
| 192 | \$00C0 | - | . |
| 193-194 | \$00C1-\$00C2 | - | . |
| 195-196 | \$00C3-\$00C4 | - | . |
| 197 | \$00C5 | - | . |
| 198 | \$00C6 | - | . |
| 199 | \$00C7 | - | . |
| 200 | \$00C8 | - | . |
| 201 | \$00C9 | - | . |
| 202 | \$00CA | - | . |
| 203 | \$00CB | - | . |
| 204 | \$00CC | - | . |
| 205 | \$00CD | - | . |
| 206 | \$00CE | - | . |
| 207 | \$00CF | - | . |
| 208 | \$00D0 | - | . |
| 209-210 | \$00D1-\$00D2 | - | . |
| 211 | \$00D3 | - | . |
| 212 | \$00D4 | - | . |
| 213 | \$00D5 | - | . |
| 214 | \$00D6 | - | . |
| 215 | \$00D7 | - | . |
| 216 | \$00D8 | - | . |
| 217-241 | \$00D9-\$00F1 | - | . |
| 242 | \$00F2 | - | . |
| 243-244 | \$00F3-\$00F4 | - | . |
| 245-246 | \$00F5-\$00F6 | - | . |
| 247-248 | \$00F7-\$00F8 | - | . |
| 249-250 | \$00F9-\$00FA | - | . |
| 251-254 | \$00FB-\$00FE | - | Sin uso (4 bytes). |
| 255-266 | \$00FF-\$010A | - | Buffer para convertir número flotantes a cadena (12 bytes).<br/>**NOTA:** Invade el espacio final de la pila de programa. |

## Pila de programa

| Dirección | Hexadecimal | Descripción |
|:---------:|:-----------:|-------------|
| 256-317 | \$0100-\$013D | Punteros a los bytes de lectura con errores durante la lectura del *datasette* (62 bytes, 31 entradas). |
| 256-511 | \$0100-\$01FF | Pila del procesador. También se utiliza para almacenar datos para gestionar los `FOR` y los `GOSUB`. |

## Memoria del sistema

| Dirección | Hexadecimal | Defecto | Descripción |
|:---------:|:-----------:|:-------:|-------------|
| 512-600 | \$0200-\$0258 | - | . |
| 601-610 | \$0259-\$0262 | - | . |
| 611-620 | \$0263-\$026C | - | . |
| 621-630 | \$026D-\$0276 | - | . |
| 631-640 | \$0277-\$0280 | - | . |
| 641-642 | \$0281-\$0282 | - | . |
| 643-644 | \$0283-\$0284 | - | . |
| 645 | \$0285 | - | Sin uso (serial bus timeout). |
| 646 | \$0286 | - | . |
| 647 | \$0287 | - | . |
| 648 | \$0288 | - | . |
| 649 | \$0289 | - | . |
| 650 | \$028A | - | . |
| 651 | \$028B | - | . |
| 652 | \$028C | - | . |
| 653 | \$028D | - | . |
| 654 | \$028E | - | . |
| 655-656 | \$028F-\$0290 | - | . |
| 657 | \$0291 | - | . |
| 658 | \$0292 | - | . |
| 659 | \$0293 | - | . |
| 660 | \$0294 | - | . |
| 661-662 | \$0295-\$0296 | - | . |
| 663 | \$0297 | - | . |
| 664 | \$0298 | - | . |
| 665-666 | \$0299-\$029A | - | . |
| 667 | \$029B | - | . |
| 668 | \$029C | - | . |
| 669 | \$029D | - | . |
| 670 | \$029E | - | . |
| 671-672 | \$029F-\$02A0 | - | . |
| 673 | \$02A1 | - | . |
| 674 | \$02A2 | - | . |
| 675 | \$02A3 | - | . |
| 676 | \$02A4 | - | . |
| 677 | \$02A5 | - | . |
| 678 | \$02A6 | - | . |
| 679-767 | \$02A7-\$02FF | - | Sin uso (89 bytes). |
| 768-769 | \$0300-\$0301 | - | . |
| 770-771 | \$0302-\$0303 | - | . |
| 772-773 | \$0304-\$0305 | - | . |
| 774-775 | \$0306-\$0307 | - | . |
| 776-777 | \$0308-\$0309 | - | . |
| 778-779 | \$030A-\$030B | - | . |
| 780 | \$030C | - | . |
| 781 | \$030D | - | . |
| 782 | \$030E | - | . |
| 783 | \$030F | - | . |
| 784-786 | \$0310-\$0312 | - | . |
| 787 | \$0313 | - | Sin uso. |
| 788-789 | \$0314-\$0315 | - | . |
| 790-791 | \$0316-\$0317 | - | . |
| 792-793 | \$0318-\$0319 | - | . |
| 794-795 | \$031A-\$031B | - | . |
| 796-797 | \$031C-\$031D | - | . |
| 798-799 | \$031E-\$031F | - | . |
| 800-801 | \$0320-\$0321 | - | . |
| 802-803 | \$0322-\$0323 | - | . |
| 804-805 | \$0324-\$0325 | - | . |
| 806-807 | \$0326-\$0327 | - | . |
| 808-809 | \$0328-\$0329 | - | . |
| 810-811 | \$032A-\$032B | - | . |
| 812-813 | \$032C-\$032D | - | . |
| 814-815 | \$032E-\$032F | \$FE66 | Sin uso. |
| 816-817 | \$0330-\$0331 | - | . |
| 818-819 | \$0332-\$0333 | - | . |
| 820-827 | \$0334-\$033B | - | Sin uso (8 bytes). |
| 828-1019 | \$033C-\$03FB | - | . |
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
| 53248 | \$D000 | - | . |
| 53249 | \$D001 | - | . |
| 53250 | \$D002 | - | . |
| 53251 | \$D003 | - | . |
| 53252 | \$D004 | - | . |
| 53253 | \$D005 | - | . |
| 53254 | \$D006 | - | . |
| 53255 | \$D007 | - | . |
| 53256 | \$D008 | - | . |
| 53257 | \$D009 | - | . |
| 53258 | \$D00A | - | . |
| 53259 | \$D00B | - | . |
| 53260 | \$D00C | - | . |
| 53261 | \$D00D | - | . |
| 53262 | \$D00E | - | . |
| 53263 | \$D00F | - | . |
| 53264 | \$D010 | - | . |
| 53265 | \$D011 | - | . |
| 53266 | \$D012 | - | . |
| 53267 | \$D013 | - | . |
| 53268 | \$D014 | - | . |
| 53269 | \$D015 | - | . |
| 53270 | \$D016 | - | . |
| 53271 | \$D017 | - | . |
| 53272 | \$D018 | - | . |
| 53273 | \$D019 | - | . |
| 53274 | \$D01A | - | . |
| 53275 | \$D01B | - | . |
| 53276 | \$D01C | - | . |
| 53277 | \$D01D | - | . |
| 53278 | \$D01E | - | . |
| 53279 | \$D01F | - | . |
| 53280 | \$D020 | - | . |
| 53281 | \$D021 | - | . |
| 53282 | \$D022 | - | . |
| 53283 | \$D023 | - | . |
| 53284 | \$D024 | - | . |
| 53285 | \$D025 | - | . |
| 53286 | \$D026 | - | . |
| 53287 | \$D027 | - | . |
| 53288 | \$D028 | - | . |
| 53289 | \$D029 | - | . |
| 53290 | \$D02A | - | . |
| 53291 | \$D02B | - | . |
| 53292 | \$D02C | - | . |
| 53293 | \$D02D | - | . |
| 53294 | \$D02E | - | . |
| 53295-53311 | \$D02F-\$D03F | - | . |
| 53312-54271 | \$D040-\$D3FF | - | . |

## Chip sonoro SID

| Dirección | Hexadecimal | Defecto | Descripción |
|:---------:|:-----------:|:-------:|-------------|
| 54272-54273 | \$D400-\$D401 | - | . |
| 54274-54275 | \$D402-\$D403 | - | . |
| 54276 | \$D404 | - | . |
| 54277 | \$D405 | - | . |
| 54278 | \$D406 | - | . |
| 54279-54280 | \$D407-\$D408 | - | . |
| 54281-54282 | \$D409-\$D40A | - | . |
| 54283 | \$D40B | - | . |
| 54284 | \$D40C | - | . |
| 54285 | \$D40D | - | . |
| 54286-54287 | \$D40E-\$D40F | - | . |
| 54288-54289 | \$D410-\$D411 | - | . |
| 54290 | \$D412 | - | . |
| 54291 | \$D413 | - | . |
| 54292 | \$D414 | - | . |
| 54293 | \$D415 | - | . |
| 54294 | \$D416 | - | . |
| 54295 | \$D417 | - | . |
| 54296 | \$D418 | - | . |
| 54297 | \$D419 | - | . |
| 54298 | \$D41A | - | . |
| 54299 | \$D41B | - | . |
| 54300 | \$D41C | - | . |
| 54301-54303 | \$D41D-\$D41F | - | . |
| 54304-55295 | \$D420-\$D7FF | - | . |

## Buffer de color de pantalla

| Dirección | Hexadecimal | Descripción |
|:---------:|:-----------:|-------------|
| 55296-56295 | \$D800-\$DBE7 |Buffer de color de la pantalla (1000 bytes)<br/>**Bits 0-3:** Color del 0 al 15. |
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

## CIA2: Serial Bus, RS-232, NMI

| Dirección | Hexadecimal | Descripción |
|:---------:|:-----------:|-------------|
| 56576 | \$DD00 | Puerto A: Serial Bus.<br/> + **Bits 0-1:** Banco del VIC-II. **00** = \$C000-\$FFFF (49152-65535); **01** = \$8000-\$BFFF (32768-49151); **10** = \$4000-\$7FFF (16384-32767); **11** = \$0000-\$3FFF (0-16383).<br/>+ **Bit 2:** TXD del RS-232 (bit de salida).<br/>+ **Bit 3:** ATN OUT del Serial Bus. **0** = Alto; **1** = Bajo.<br/>+ **Bit 4:** CLOCK OUT del Serial Bus. **0** = Alto; **1** = Bajo.<br/>+ **Bit 5:** DATA OUT del Serial Bus. **0** = Alto; **1** = Bajo.<br/>+ **Bit 6:** CLOCK IN del Serial Bus. **0** = Bajo; **1** = Alto.<br/>+ **Bit 7:** DATA IN del Serial Bus. **0** = Bajo; **1** = Alto. |
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
| 57344-65535 | \$E000-\$FFFF | - | ROM del KERNAL |
| 65530-65531 | \$FFFA-\$FFFB | \$FE43 | .Execution address of non-maskable interrupt service routine. |
| 65532-65533 | \$FFFC-\$FFFD | \$FCE2 | .Execution address of cold reset. |
| 65534-65535 | \$FFFE-\$FFFF | \$FF48 | .Execution address of interrupt service routine. |

