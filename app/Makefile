##### Project #####

PROJECT			?= app
# The path for generated files
BUILD_DIR		= Build

MCU_TYPE		= STM32G030xx

##### Options #####

# Enable printf float %f support, y:yes, n:no
ENABLE_PRINTF_FLOAT	?= n

##### Toolchains #######

ARM_TOOLCHAIN	?= /usr/bin

##### Paths ############

# C and CPP source folders
CDIRS		:=  ./src
# Single C and CPP source files
CFILES		:= 
CPPFILES	:= 

# ASM source folders
ADIRS		:= ./src
# Single ASM source files
AFILES		:= 

# Include paths
INCLUDES	:= ../vendor/CMSIS/CMSIS/Core/Include \
			../vendor/CMSIS/Device/ST/STM32G0/Include \
			$(CDIRS)

##### Library Paths ############

# Library flags
LIB_FLAGS		= $(MCU_TYPE)
# JLink device (Uppercases)
JLINK_DEVICE	?= $(shell echo $(MCU_TYPE) | tr '[:lower:]' '[:upper:]')
# PyOCD device (Lowercases)
PYOCD_DEVICE	?= $(shell echo $(MCU_TYPE) | tr '[:upper:]' '[:lower:]')
# Link descript file: 
LDSCRIPT		= ../STM32G030F6MX_FLASH.ld


# PY32F002B >>>
CFILES		+= ../vendor/CMSIS/Device/ST/STM32G0/Source/Templates/system_stm32g0xx.c

# Startup file
AFILES	:= ../vendor/CMSIS/Device/ST/STM32G0/Source/Templates/gcc/startup_stm32g030xx.s
# PY32F002B <<<

include ./rules.mk
