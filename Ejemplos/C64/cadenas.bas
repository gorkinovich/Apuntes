10 INPUT S$
20 S%=LEN(S$)
30 HS%=INT(LEN(S$)/2+0.5)
40 SL$=LEFT$(S$,HS%)
50 SR$=RIGHT$(S$,HS%)
60 PRINT "CADENA:    ";S$
70 PRINT "TAMANO:    ";S%
80 PRINT "IZQUIERDA: ";SL$
90 PRINT "DERECHA:   ";SR$
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