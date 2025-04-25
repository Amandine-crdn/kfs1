# 1. Préparer l'environnement de développement
	Installe les outils nécessaires: gcc, nasm, grub (demarrage du systeme), qemu ou kvm (emulateur)

# 2. Écrire le bootloader (code d'initialisation) en assembleur
	Definition : Le bootloader est un petit programme qui s'exécute juste après l'allumage du système. Il est responsable de charger le noyau en mémoire et de passer le contrôle au noyau.
	
### 2.1 boot.asm
	initialise le système et charge ton noyau avec GRUB: Explications des parties principales :

**[bits 32]** : Cette directive spécifie que nous écrivons du code pour une architecture 32 bits (c'est-à-dire x86).

**[global _start]** : Cette ligne rend l'étiquette _start accessible par le linker et l'assembleur. C'est le point d'entrée du programme, ce qui signifie que c'est l'endroit où le code commence à s'exécuter.

### 2.2 registres asm
L’assembleur est une représentation du langage machine.
	
Il y a autant d’assembleurs que de type de processeurs différent.

Il y a quatre registres de travaux: EAX, EDX, ECX, EBX**

**ex: Registre EAX (accumulateur)**

	- segments de mémoire. Utilisé pour les opérations arithmétiques et le stockage de la valeur de retour des appels systèmes. (registre de 16bits)
	- AH : Utiliser pour la valeur de retour (registre de 8 bits: octet de poids fort de AX.)
	- AL : Utiliser pour definir un caractere (registre de 8 bits: octet de poids faible de AX.)
	- B, C et D avec un Low et un Hight

**six registres de segment par registre de travaux :**

	- c'est la gestion de la mémoire dans l'architecture x86 
	- zone mémoire contenant les données du programme
		- CS : pointe vers les instructions du programme (code segment).
		- DS : pointe vers les données du programme (data segment).
		- SS : pointe vers la pile programme (stack segment).
		- ES : pointe vers les données du programme multi-segments (extra segment).
		- FS : pointe vers les données du programme multi-segments en mode protégé.
		- GS : pointe vers les données du programme multi-segments en mode protégé.


**Le registre d'états**

	Chaque bit du registre EFLAGS est un indicateur d'état qui peut être modifié à chaque instruction exécutée : retenue (addition ou soustraction), dépassement, comparaison, autoriser les interruptions,


	Sur les processeurs x86 limités à 16 bits, ce registre n'a pas le préfixe E et est donc nommé FLAG.

	Son nom est abrégé par son initiale F dans le nom de certaines instructions


**Le registre EIP (Le pointeur d'instruction):**


	Utilisé avec le segment du registre CS par le processeur pour connaitre la prochaine instruction à exécuter. Ce registre est donc modifié implicitement par le processeur (instruction suivante, saut à l'adresse indiquée, appel d'une fonction, interruption ...)



### 2.3 fonctions asm

	0x0E is the BIOS function for writing characters in TTY mode.

### 2.4 instruction asm
	INT: interruption
	L'interruption 0x10 est utilisée pour gérer l'affichage en mode texte. 


	https://pageperso.lis-lab.fr/~alexis.nasr/Ens/Compilation/cm07_intel_x86.pdf

	https://docs.oracle.com/cd/E19641-01/802-1948/802-1948.pdf




# 3. configurer GRUB

```
uname -m
x86_64
```

	Installe GRUB 
	- creer un fichier de conf qui appelle ton bootloader.
	- creer image iso: grub-mkrescue -o my-kernel.iso grub/

# 4. Développer le noyau en C

Crée un fichier kernel.c qui contient ta fonction main qui sera appelée après le bootloader. Ce fichier pourra afficher du texte à l'écran +  gérer quelques bases comme l'initialisation des types de base (int, char, etc.).

**compilation**: gcc -fno-builtin -fno-exception -fno-stack-protector -nostdlib -nodefaultlibs -o kernel.bin kernel.c

**creer un linker**: 
- cf ld file

5. Gérer la mémoire
6. Implémenter un système d'entrée-sortie (E/S)

# 7. MAKEFILE 

Compile d'abord ton noyau (kernel.bin).

Place-le dans le bon répertoire (iso/boot/).

Prépare la structure pour l'image ISO.

Crée l'image ISO à la fin

# 8. Tester et déboguer le noyau

qemu-system-x86_64 -cdrom iso/my-kernel.iso -m 512 -smp 2
qemu-system-i386 -boot d -cdrom ./iso/my-kernel.iso -m 512
du -hd1 iso/my-kernel.iso 

