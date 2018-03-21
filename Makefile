CXX = ~/opt/cross/bin/i386-elf-g++
CXX_FLAGS = -c -ffreestanding -nostdlib -fno-builtin -fno-rtti -fno-exceptions
ASM = ~/opt/cross/bin/i386-elf-as
ASM_FLAGS = -c
LN_FLAGS = -T linker.ld -melf_i386


C_FILE = $(wildcard src/kernel/*.c) \
           $(wildcard src/kernel/arch/i386/*.c)
C_SRC = $(C_FILE:.c=)


CXX_FILE = $(wildcard src/kernel/*.cpp) \
           $(wildcard src/kernel/arch/i386/*.cpp)
CXX_SRC = $(CXX_FILE:.c=)


ASM_FILE = $(wildcard src/kernel/arch/i386/*.s)
ASM_SOURCE = $(ASM_FILE:.s=)

OUT_TEMP = $(wildcard a_out/*.o)
OUT = $(wildcard out/*.o)

all: ccompile cxxcompile acompile

ccompile:
	for file in $(C_SRC) ; do \
		$(CXX) $(CXX_FLAGS) $$file.c -o a_out/$$file.o ; \
	done

cxxcompile:
	for file in $(CXX_SRC) ; do \
		$(CXX) $(CXX_FLAGS) $$file -o a_out/$$file.o ; \
	done

acompile:
	for file in $(ASM_SOURCE) ; do \
	    $(ASM) $(ASM_FLAGS) $$file.s -o a_out/$$file.o ; \
	done
link:
		ld $(LN_FLAGS) -o latest.bin $(OUT)

run:
	qemu-system-i386 -kernel latest.bin

clean:
	rm -f $(OUT)
	rm -f latest.bin

buildiso:
	mkdir -p isodir/boot/grub
	cp latest.bin isodir/boot/kernel.elf
	cp grub.cfg isodir/boot/grub/grub.cfg
	sudo grub-mkrescue -o bootable.iso isodir


