;---------------------------------------------------------------------------
; Cargador
;---------------------------------------------------------------------------
*=$0801 ; 10 SYS2064
        BYTE $0B,$08,$0A,$00,$9E,$32,$30,$36,$34,$00,$00,$00

;---------------------------------------------------------------------------
; Programa
;---------------------------------------------------------------------------
*=$0810
main    jsr $E544 ; KERNAL: Limpiar terminal
        ldx #$00
@loop   lda Message,x
        beq @end
        jsr $E716 ; KERNAL: Poner carácter
        inx
        jmp @loop
@end    rts

;---------------------------------------------------------------------------
; Datos
;---------------------------------------------------------------------------
Message  TEXT "hola mundo"
         BYTE 13,0