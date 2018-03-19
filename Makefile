CC = ~/opt/cross/bin/i386-elf-g++
AS = ~/opt/cross/bin/i386-elf-as
LNFLAGS = -T linker.ld -melf_i386
CCFLAGS = -c -ffreestanding -nostdlib -fno-builtin -fno-rtti -fno-exceptions
ASFLAGS = -c
CTMP = $(wildcard src/kernel/*.cpp)
ATMP = $(wildcard src/boot/*.s)
CFILE = $(subst src/kernel/, ,$(CTMP))
AFILE = $(subst src/boot/, ,$(ATMP))
CSRC = $(CFILE:.c=)
ASRC = $(AFILE:.s=)

OUT = $(wildcard out/*.o)

all: ccompile acompile link

ccompile:
	for file in $(CSRC) ; do \
		$(CC) $(CCFLAGS) src/kernel/$$file -o out/$$file.o ; \
	done

acompile:
	for file in $(ASRC) ; do \
		$(AS) $(ASFLAGS) src/boot/$$file.s -o out/$$file.o ; \
	done

link:
		ld $(LNFLAGS) -o latest.bin $(OUT)

run:
	qemu-system-i386 -kernel latest.bin

bochs:
	bochs -q -f bochsrc.txt

clean:
	rm -f $(OUT)
	rm -f latest.bin

buildiso:
	mkdir -p isodir/boot/grub
	cp latest.bin isodir/boot/kernel.elf
	cp grub.cfg isodir/boot/grub/grub.cfg
	sudo grub-mkrescue -o bootable.iso isodir
