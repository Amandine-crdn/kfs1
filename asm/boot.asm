[bits 32]
[global _start]

_start:
    ;initialisation des registres a 0x01
    mov ax, 0x00
    mov ds, ax
    mov es, ax

    mov ah, 0x0E ; service dinteruption de type caractere
    mov al, 'H' ; caractere a afficher
    int 0x10; interruption de type afficher un caractere (mode texte vidéo)

    jmp $

