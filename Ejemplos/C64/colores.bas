10  REM VER LISTA DE COLORES
20  TB=1024:CB=55296:T=160
30  FOR I=0 TO 24
40  FOR J=0 TO 39
50  C=INT(J/5)
60  IF I>12 THEN C=C+8
70  POKE TB+(40*I+J),T
80  POKE CB+(40*I+J),C
90  NEXT J
100 NEXT I
110 GET K$
120 IF K$="" THEN 110