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

# Common source files
COMSRC = main.c memory.c
# Platform specific source files
MSPSRC = interrupts_msp432p401r_gcc.c startup_msp432p401r_gcc.c system_msp432p401r.c

ifeq ($(PLATFORM),MSP432)
	SOURCES =	$(COMSRC) $(MSPSRC)
else
	SOURCES =	$(COMSRC)
endif

#Include paths
INCLUDES =	\
	-I../include/CMSIS \
	-I../include/common \
	-I../include/msp432
