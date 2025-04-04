ASM = nasm
CC = gcc
LD = ld

# Compilation en 64 bits (m64 pour l'architecture 64 bits)
CFLAGS = -m64 -fno-builtin -fno-exceptions -fno-stack-protector -nostdlib -nodefaultlibs
LDFLAGS = -m elf_x86_64 -T linker.ld

BOOT_SRC = asm/boot.asm
KERNEL_SRC = kernel/kernel.c

# Cible principale : générer le binaire du noyau dans iso/boot/kernel.bin
all: iso/boot/kernel.bin

# Lier les fichiers objets et créer le fichier binaire du noyau
iso/boot/kernel.bin: boot.o kernel.o
	$(LD) $(LDFLAGS) -o iso/boot/kernel.bin boot.o kernel.o

# Compiler le fichier d'assemblage boot.asm
boot.o: $(BOOT_SRC)
	$(ASM) -f elf64 -o boot.o $(BOOT_SRC)

# Compiler le fichier source kernel.c
kernel.o: $(KERNEL_SRC)
	$(CC) $(CFLAGS) -c -o kernel.o $(KERNEL_SRC)

# Nettoyer les fichiers objets et le fichier binaire
clean:
	rm -f *.o iso/boot/kernel.bin
