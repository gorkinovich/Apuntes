10  OPEN 1,8,4,"TEST,SEQ,W"
20  S$="":INPUT S$
30  PRINT# 1,S$
40  IF S$<>"" THEN 20
50  CLOSE 1
60  PRINT CHR$(147)
70  OPEN 1,8,4,"TEST,SEQ,R"
80  GET# 1,C$
90  PRINT C$;
100 IF 0=(STATUS AND 64) THEN 80
110 PRINT
120 CLOSE 1