################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../utils/debug.c \
../utils/fft.c \
../utils/led.c \
../utils/port.c 

OBJS += \
./utils/debug.o \
./utils/fft.o \
./utils/led.o \
./utils/port.o 

C_DEPS += \
./utils/debug.d \
./utils/fft.d \
./utils/led.d \
./utils/port.d 


# Each subdirectory must supply rules for building sources it contributes
utils/%.o: ../utils/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32F4 -DSTM32F407VGTx -DSTM32F407G_DISC1 -DDEBUG -DSTM32F40XX -DSTM32F40_41xxx -DUSE_STDPERIPH_DRIVER -I"C:/Users/Keven/Documents/workbench/medidor_f4/StdPeriph_Driver/inc" -I"C:/Users/Keven/Documents/workbench/medidor_f4/kiss_fft130" -I"C:/Users/Keven/Documents/workbench/medidor_f4/Utilities" -I"C:/Users/Keven/Documents/workbench/medidor_f4/utils" -I"C:/Users/Keven/Documents/workbench/medidor_f4/inc" -I"C:/Users/Keven/Documents/workbench/medidor_f4/CMSIS/device" -I"C:/Users/Keven/Documents/workbench/medidor_f4/CMSIS/core" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


