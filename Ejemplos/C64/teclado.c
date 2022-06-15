#include <stdio.h>
#include <conio.h>

#define POKE(A,X)  (*(unsigned char *)A) = (X)
#define PEEK(A)    (*(unsigned char *)A)
#define POKEW(A,X) (*(unsigned int *)A) = (X)
#define PEEKW(A)   (*(unsigned int *)A)

#define MAX_ROWS 8
#define MAX_COLS 8

void main() {
    unsigned int offset;
    unsigned char aux, row, col, mask[MAX_COLS], keys, color;
    
    aux = 1;
    for(col = 0; col < MAX_COLS; ++col) {
        mask[col] = aux;
        aux *= 2;
    }
    
    POKE(53272, 21); // Fuente mayúsculas
    POKE(  646,  1); // Color cursor
    POKE(53281,  0); // Color fondo
    POKE(53280, 12); // Color borde
    
    clrscr();
    printf("keyboard test!\n");
    printf("\n");
    printf("del  ret  lrc  f7   f1   f3   f5   udc\n");
    printf("3    w    a    4    z    s    e    lsh\n");
    printf("5    r    d    6    c    f    t    x\n");
    printf("7    y    g    8    b    h    u    v\n");
    printf("9    i    j    0    m    k    o    n\n");
    printf("+    p    l    -    .    :    @    ,\n");
    printf("%c    *    ;    hom  rsh  =    %c    /\n", 92, 94);
    printf("1    %c    ctr  2    spc  c=   q    run\n", 95);
    
    POKE(56322, 255); // CIA1 Puerto A en escritura
    POKE(56323,   0); // CIA1 Puerto B en lectura
    
    while(1) {
        offset = 55296 + 80;
        for(row = 0; row < MAX_ROWS; ++row) {
            POKE(56320, 255 - mask[row]);
            keys = PEEK(56321);
            for(col = 0; col < MAX_COLS; ++col) {
                if ((keys & mask[col]) == 0) {
                    color = 10;
                } else {
                    color = 1;
                }
                for(aux = 0; aux < 5; ++aux, ++offset) {
                    POKE(offset, color);
                }
            }
        }
    }
}