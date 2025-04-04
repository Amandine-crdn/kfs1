ASM = nasm
CC = gcc
LD = ld

# Compilation en 32 bits (m32 pour l'architecture 32 bits)
CFLAGS = -m32 -fno-builtin -fno-exceptions -fno-stack-protector -fno-rtti -nostdlib -nodefaultlibs
LDFLAGS = -m elf_i386 -T linker.ld

BOOT_SRC = asm/boot.asm
KERNEL_SRC = kernel/kernel.c

# Répertoires de destination
ISO_DIR = iso
BOOT_DIR = $(ISO_DIR)/boot
GRUB_DIR = $(BOOT_DIR)/grub

# Noms de fichiers
KERNEL_BIN = $(BOOT_DIR)/kernel.bin
GRUB_CFG = $(GRUB_DIR)/grub.cfg

all: my-kernel.iso

# Création de l'image ISO
my-kernel.iso: $(KERNEL_BIN)
	grub-mkrescue -o $(ISO_DIR)/my-kernel.iso $(ISO_DIR)

# Compilation du noyau
$(KERNEL_BIN): boot.o kernel.o
	$(LD) $(LDFLAGS) -o $(KERNEL_BIN) boot.o kernel.o

# Compilation de boot.asm en boot.o
# Compilation du bootloader :
boot.o: $(BOOT_SRC)
	$(ASM) -f elf32 -o boot.o $(BOOT_SRC)

# Compilation du noyau en kernel.o
kernel.o: $(KERNEL_SRC)
	$(CC) $(CFLAGS) -c -o kernel.o $(KERNEL_SRC)

# Nettoyage
clean:
	rm -f *.o $(KERNEL_BIN) $(ISO_DIR)/my-kernel.iso