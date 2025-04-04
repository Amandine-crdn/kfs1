void main() {
    const char *message = "42";

    unsigned short *video_memory = (unsigned short *) 0xB8000;
    // mémoire est mappée dans le segment de mémoire à l'adresse 0xB8000

    unsigned short color = 0x07; // Couleur par défaut

// affiche caractere par caractere selon la videomemory strucure:

    // le premier octet est le caractère lui-même (selon le code ASCII)
    // le second octet contient des informations sur la couleur de fond et la couleur du texte.
        // Bits 0-3 : Couleur du texte (ici, 0x07 = blanc).
        // Bits 4-7 : Couleur de fond (ici, 0x00 = fond noir).
        
    for (int i = 0; message[i] != '\0'; i++) {
            video_memory[i] = (color << 8) | message[i];
        }
}
