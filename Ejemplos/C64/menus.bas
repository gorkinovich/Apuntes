5   REM PINTAR EL MENU
10  PRINT "1. NUEVA PARTIDA"
20  PRINT "2. CARGAR PARTIDA"
30  PRINT "3. OPCIONES"
40  PRINT "4. SALIR"
50  PRINT
55  REM INTRODUCIR UNA OPCION
60  INPUT "ELIGE UNA OPCION";N
70  PRINT
75  REM SALTAR A LA OPCION
80  ON N GOTO 100,110,120,130
90  M$="INCORRECTO"  :GOTO 150
100 M$="JUGANDO"     :GOTO 150
110 M$="CARGANDO"    :GOTO 150
120 M$="CONFIGURANDO":GOTO 150
130 PRINT "SALIENDO" :GOTO 140
140 END
145 REM RUTINA PARA PINTAR MENSAJES
150 PRINT M$:PRINT
160 GOTO 10