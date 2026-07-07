CC = gcc
LD = ld

CFLAGS = -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector -nostartfiles -nodefaultlibs -Wall -O -Iinclude

LDFLAGS = -T linker.ld -m elf_i386

SRC = $(wildcard kernel/*.c) $(wildcard drivers/*.c)

OBJ = $(SRC:.c=.o)

all: kernel.bin

kernel.bin: $(OBJ)
	$(LD) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f kernel/ *.o drivers/ *.o kernel.bin
