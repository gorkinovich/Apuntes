10 DEF FN DG(R)=R*180/{pi}
20 DEF FN RD(D)=D*{pi}/180
30 DEF FN RO(X)=INT(X+0.5)
40 DEF FN L1(X)=LOG(X)/LOG(10)
50 PRINT FNL1(1),   FNRD(0),   TAB(30) FNDG(0)
60 PRINT FNL1(10),  FNRD(90),  FNDG({pi}/2)
70 PRINT FNL1(100), FNRD(180), FNDG({pi})
80 PRINT FNL1(1E3), FNRD(270), FNDG({pi}*3/4)
90 PRINT FNL1(1E4), FNRD(360), FNDG(2*{pi})
100 PRINT
110 PRINT FNRO(-3.6),FNRO(-2.5),FNRO(-1.0)
120 PRINT FNRO( 2.0),FNRO( 3.4),FNRO( 4.7)