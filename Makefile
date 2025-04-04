ASM = nasm
CC = gcc
LD = ld

CFLAGS = -m32 -fno-builtin -fno-exceptions -fno-stack-protector -nostdlib -nodefaultlibs
LDFLAGS = -m elf_i386 -T linker.ld

BOOT_SRC = asm/boot.asm
KERNEL_SRC = kernel/kernel.c

all: kernel.bin

kernel.bin: boot.o kernel.o
	$(LD) $(LDFLAGS) -o kernel.bin boot.o kernel.o

boot.o: $(BOOT_SRC)
	$(ASM) -f elf32 -o boot.o $(BOOT_SRC)

kernel.o: $(KERNEL_SRC)
	$(CC) $(CFLAGS) -c -o kernel.o $(KERNEL_SRC)

clean:
	rm -f *.o kernel.bin
