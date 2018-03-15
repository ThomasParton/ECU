################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/debug.c \
../Src/freertos.c \
../Src/gyro_8b.c \
../Src/main.c \
../Src/memory.c \
../Src/stm32f4xx_hal_msp.c \
../Src/stm32f4xx_hal_timebase_TIM.c \
../Src/stm32f4xx_it.c \
../Src/system_stm32f4xx.c 

OBJS += \
./Src/debug.o \
./Src/freertos.o \
./Src/gyro_8b.o \
./Src/main.o \
./Src/memory.o \
./Src/stm32f4xx_hal_msp.o \
./Src/stm32f4xx_hal_timebase_TIM.o \
./Src/stm32f4xx_it.o \
./Src/system_stm32f4xx.o 

C_DEPS += \
./Src/debug.d \
./Src/freertos.d \
./Src/gyro_8b.d \
./Src/main.d \
./Src/memory.d \
./Src/stm32f4xx_hal_msp.d \
./Src/stm32f4xx_hal_timebase_TIM.d \
./Src/stm32f4xx_it.d \
./Src/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F429xx -I"C:/Users/thomas/Documents/School/2018/thesis/software/Github/ecu_thomas/ECU/STM_code/Inc" -I"C:/Users/thomas/Documents/School/2018/thesis/software/Github/ecu_thomas/ECU/STM_code/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/thomas/Documents/School/2018/thesis/software/Github/ecu_thomas/ECU/STM_code/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/thomas/Documents/School/2018/thesis/software/Github/ecu_thomas/ECU/STM_code/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"C:/Users/thomas/Documents/School/2018/thesis/software/Github/ecu_thomas/ECU/STM_code/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/thomas/Documents/School/2018/thesis/software/Github/ecu_thomas/ECU/STM_code/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Users/thomas/Documents/School/2018/thesis/software/Github/ecu_thomas/ECU/STM_code/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"C:/Users/thomas/Documents/School/2018/thesis/software/Github/ecu_thomas/ECU/STM_code/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


