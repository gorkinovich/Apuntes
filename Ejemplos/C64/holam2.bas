10 PRINT CHR$(147);":)";
20 C=10:R=8 :GOSUB 60:PRINT "HOLA"
30 C=20:R=16:GOSUB 60:PRINT "MUNDO"
40 C=0 :R=21:GOSUB 60:PRINT "ADIOS"
50 END
60 POKE 211,C : REM $00D3=C
70 POKE 214,R : REM $00D6=R
80 SYS 58640  : REM JSR $E510
90 RETURN