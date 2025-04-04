ENTRY(_start)

SECTIONS {
    . = 0x10000; /* Début du noyau en mémoire */
    
    .text : {
        *(.text)
    }

    .data : {
        *(.data)
    }
    
    .bss : {
        *(.bss)
    }
}
