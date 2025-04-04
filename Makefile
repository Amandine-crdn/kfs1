ASM = nasm
CC = gcc
LD = ld

# Compilation en 64 bits (m64 pour l'architecture 64 bits)
CFLAGS = -m64 -fno-builtin -fno-exceptions -fno-stack-protector -nostdlib -nodefaultlibs
LDFLAGS = -m elf_x86_64 -T linker.ld

BOOT_SRC = asm/boot.asm
KERNEL_SRC = kernel/kernel.c

all: kernel.bin

kernel.bin: boot.o kernel.o
	$(LD) $(LDFLAGS) -o grub/kernel.bin boot.o kernel.o

boot.o: $(BOOT_SRC)
	$(ASM) -f elf64 -o boot.o $(BOOT_SRC)

kernel.o: $(KERNEL_SRC)
	$(CC) $(CFLAGS) -c -o kernel.o $(KERNEL_SRC)


clean:
	rm -f *.o kernel.bin
