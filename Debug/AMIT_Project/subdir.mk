################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../AMIT_Project/ADC_Program.c \
../AMIT_Project/AMIT_Program.c \
../AMIT_Project/DIO_Program.c \
../AMIT_Project/EXTI_Program.c \
../AMIT_Project/GIE_Program.c \
../AMIT_Project/Internal_EEPROM_Program.c \
../AMIT_Project/SEG_Program.c \
../AMIT_Project/Timer_Program.c \
../AMIT_Project/main.c 

OBJS += \
./AMIT_Project/ADC_Program.o \
./AMIT_Project/AMIT_Program.o \
./AMIT_Project/DIO_Program.o \
./AMIT_Project/EXTI_Program.o \
./AMIT_Project/GIE_Program.o \
./AMIT_Project/Internal_EEPROM_Program.o \
./AMIT_Project/SEG_Program.o \
./AMIT_Project/Timer_Program.o \
./AMIT_Project/main.o 

C_DEPS += \
./AMIT_Project/ADC_Program.d \
./AMIT_Project/AMIT_Program.d \
./AMIT_Project/DIO_Program.d \
./AMIT_Project/EXTI_Program.d \
./AMIT_Project/GIE_Program.d \
./AMIT_Project/Internal_EEPROM_Program.d \
./AMIT_Project/SEG_Program.d \
./AMIT_Project/Timer_Program.d \
./AMIT_Project/main.d 


# Each subdirectory must supply rules for building sources it contributes
AMIT_Project/%.o: ../AMIT_Project/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O2 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


