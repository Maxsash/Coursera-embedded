#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# The Makefile for the Week 2 Assignment for Introduction to Embedded Systems Software and Development course on Coursera.
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#		supported targets are:
#		%.o : returns object file(%.o); dependencies include source(%.c) file.
#		%.i : returns preprocessed file(%.i); dependecies include source(%.c) file.
#		%.asm : returns assembly files(%.asm) for corresponding source(%.c) file and project output file(c1m2.out)
#		compile-all : returns object files(%.o) for all source files(%.c)
#		build : returns dependency files(%.d) and object files(%.o) corresponding to all source files(%.c); Map file(c1m2.map) and project outputfile (c1m2.out)
#		all : returns dependency files(%.d) and object files(%.o) corresponding to all source files(%.c); Map file(c1m2.map) and project outputfile (c1m2.out)
#		clean : removes all the generated files. 
#
# Platform Overrides:
#      PLATFORM has two supported values:
#		MSP432
#		HOST
#		default value is set to HOST in case nothing is specified.
#------------------------------------------------------------------------------
include sources.mk

#Set default value of PLATFORM to HOST
ifndef PLATFORM
PLATFORM=HOST
endif

#Common flags for both platforms
TARGET = c1m2
LINKER_FILE = ../msp432p401r.lds
CFLAGS = -Wall -Werror -g -O0 -std=c99 -MD
CPPFLAGS = $(INCLUDES)
LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)

# Architectures Specific Flags
CPU = -mcpu=cortex-m4
ARCH = -march=armv7e-m -mthumb
SPECS = --specs=nosys.specs
FPABI = -mfloat-abi=hard
FPUARCH = -mfpu=fpv4-sp-d16

# PLatform Specific Flags
ifeq ($(PLATFORM),MSP432)
	EXT = arm-none-eabi-
	ARMFLAGS = $(CPU) $(ARCH) $(SPECS) $(FLOATABI) $(FPUARCH)
endif

#Compiler and linker
CC = $(EXT)gcc
LD = $(EXT)ld


#Rules
OBJS = $(SOURCES:.c=.o)

%.o : %.c
	$(CC) -c $< $(CFLAGS) $(CPPFLAGS) -o $@ $(ARMFLAGS) -D$(PLATFORM)
	
%.i : %.c
	$(CC) -E $< $(CFLAGS) $(CPPFLAGS) -o $@ $(ARMFLAGS) -D$(PLATFORM)

%.asm : %.c $(TARGET).out
	$(CC) -S $< $(CFLAGS) $(CPPFLAGS) -o $@ $(ARMFLAGS) -D$(PLATFORM)
	$(EXT)objdump --disassemble-all $(TARGET).out > $(TARGET).asm
	
.PHONY: compile-all
compile-all: $(OBJS)

.PHONY: build
build: all

.PHONY: all
all: $(TARGET).out

$(TARGET).out: $(OBJS)
	$(CC) $(CPPFLAGs) $(OBJS) $(CFLAGS) -o $@ $(LDFLAGS) $(ARMFLAGS)
	size $@

.PHONY: clean
clean:
	rm -f *.o $(TARGET).out $(TARGET).map *.asm *.i *.d
