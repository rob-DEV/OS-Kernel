CXX = ~/opt/cross/bin/i386-elf-g++
CXX_FLAGS = -c -ffreestanding -nostdlib -fno-builtin -fno-rtti -fno-exceptions
AS = ~/opt/cross/bin/i386-elf-as
LNFLAGS = -T linker.ld -melf_i386

ASFLAGS = -c


CFILE = $(wildcard src/kernel/*.cpp) \
        $(wildcard src/kernel/include/*.cpp)
CSRC = $(CFILE:.c=)


all: ccompile

ccompile:
	for file in $(CSRC) ; do \
		$(CXX) $(CXX_FLAGS) $$file -o $$file.o ; \
	done


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


