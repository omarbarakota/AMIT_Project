################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC_Program.c \
../AMIT_Program.c \
../DIO_Program.c \
../EXTI_Program.c \
../GIE_Program.c \
../Internal_EEPROM_Program.c \
../SEG_Program.c \
../Timer_Program.c \
../main.c 

OBJS += \
./ADC_Program.o \
./AMIT_Program.o \
./DIO_Program.o \
./EXTI_Program.o \
./GIE_Program.o \
./Internal_EEPROM_Program.o \
./SEG_Program.o \
./Timer_Program.o \
./main.o 

C_DEPS += \
./ADC_Program.d \
./AMIT_Program.d \
./DIO_Program.d \
./EXTI_Program.d \
./GIE_Program.d \
./Internal_EEPROM_Program.d \
./SEG_Program.d \
./Timer_Program.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O2 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


