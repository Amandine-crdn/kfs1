[bits 32]            ; spécification du mode 32 bits (x86)
[global _start]      ; point d'entrée du bootloader

_start:
    ; Initialisation des segments de mémoire
    mov ax, 0x01     ; Initialisation des registres pour l'accès mémoire
    mov ds, ax
    mov es, ax

    ; Affichage du message "42" sur l'écran en mode texte (BIOS interrupt)
    mov ah, 0x0E     ; Service d'interruption pour l'affichage de caractère
    mov al, '4'      ; Affiche le caractère '4'
    int 0x10         ; Appelle l'interruption BIOS pour afficher '4'

    mov al, '2'      ; Affiche le caractère '2'
    int 0x10         ; Appelle à nouveau l'interruption BIOS pour afficher '2'

    jmp $            ; Boucle infinie, pour ne pas retourner au bootloader
