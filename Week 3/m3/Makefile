SOURCES = main.c misc.c
INCLUDES = -I./

#Common flags for both platforms
TARGET = run
LINKER_FILE = msp432p401r.lds
CFLAGS = -Wall -Werror -g -O0 -std=c99
CPPFLAGS = $(INCLUDES)
LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)

#Compiler and linker
CC = gcc
LD = ld


#Rules
OBJS = $(SOURCES:.c=.o)

%.o : %.c
	$(CC) -c $< $(CFLAGS) $(CPPFLAGS) -o $@
	
%.i : %.c
	$(CC) -E $< $(CFLAGS) $(CPPFLAGS) -o $@

%.asm : %.c $(TARGET).out
	$(CC) -S $< $(CFLAGS) $(CPPFLAGS) -o $@
	objdump --disassemble-all $(TARGET).out > $(TARGET).asm
	
.PHONY: compile-all
compile-all: $(OBJS)

.PHONY: build
build: all

.PHONY: all
all: $(TARGET).out

$(TARGET).out: $(OBJS)
	$(CC) $(CPPFLAGs) $(OBJS) $(CFLAGS) -o $@ $(LDFLAGS) $(ARMFLAGS)
	size -Bx $@
	size -Bx $@
	nm $(OBJS)

.PHONY: clean
clean:
	rm -f *.o $(TARGET).out $(TARGET).map *.asm *.i *.d
