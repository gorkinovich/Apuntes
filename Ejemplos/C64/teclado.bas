10  REM INICIALIZAR DATOS
20  DIM K$(7,7), M%(7)
30  N%=1
40  FOR I=0 TO 7
50  M%(I)=N%
60  N%=N%*2
70  NEXT I
80  K$(0,0)="DEL":K$(0,1)="RET":K$(0,2)="LRC":K$(0,3)="F7"
90  K$(0,4)="F1":K$(0,5)="F3":K$(0,6)="F5":K$(0,7)="UDC"
100 K$(1,0)="3":K$(1,1)="W":K$(1,2)="A":K$(1,3)="4"
110 K$(1,4)="Z":K$(1,5)="S":K$(1,6)="E":K$(1,7)="LSH"
120 K$(2,0)="5":K$(2,1)="R":K$(2,2)="D":K$(2,3)="6"
130 K$(2,4)="C":K$(2,5)="F":K$(2,6)="T":K$(2,7)="X"
140 K$(3,0)="7":K$(3,1)="Y":K$(3,2)="G":K$(3,3)="8"
150 K$(3,4)="B":K$(3,5)="H":K$(3,6)="U":K$(3,7)="V"
160 K$(4,0)="9":K$(4,1)="I":K$(4,2)="J":K$(4,3)="0"
170 K$(4,4)="M":K$(4,5)="K":K$(4,6)="O":K$(4,7)="N"
180 K$(5,0)="+":K$(5,1)="P":K$(5,2)="L":K$(5,3)="-"
190 K$(5,4)=".":K$(5,5)=":":K$(5,6)="@":K$(5,7)=","
200 K$(6,0)="{pound}":K$(6,1)="*":K$(6,2)=";":K$(6,3)="HOM"
210 K$(6,4)="RSH":K$(6,5)="=":K$(6,6)="^":K$(6,7)="/"
220 K$(7,0)="1":K$(7,1)="{arrow left}":K$(7,2)="CTR":K$(7,3)="2"
230 K$(7,4)="SPC":K$(7,5)="C=":K$(7,6)="Q":K$(7,7)="STP"
240 REM INICIALIZAR PANTALLA
250 PRINT "{clear}";
260 POKE 646,1    : REM COLOR CURSOR
270 POKE 53281,0  : REM COLOR FONDO
280 POKE 53280,12 : REM COLOR BORDE
290 FOR I=0 TO 7
300 FOR J=0 TO 7
310 PRINT TAB(5*J);K$(I,J);
320 NEXT J:PRINT
330 NEXT I
340 REM CONFIGURAR TECLADO
350 POKE 56322,255
360 POKE 56323,0
370 REM BUCLE PRINCIPAL
380 X=55296 : REM BUFFER DE COLOR
390 FOR I=0 TO 7
400 POKE 56320,255-M%(I)
410 K%=PEEK(56321)
420 FOR J=0 TO 7
430 C%=1:IF (K% AND M%(J))=0 THEN C%=10
440 POKE X,C%:X=X+1
450 POKE X,C%:X=X+1
460 POKE X,C%:X=X+3
470 NEXT J,I
480 GOTO 380