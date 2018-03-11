################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
LD_SRCS += \
../src/lscript.ld 

CC_SRCS += \
../src/client.cc \
../src/main.cc 

C_SRCS += \
../src/platform.c 

CC_DEPS += \
./src/client.d \
./src/main.d 

OBJS += \
./src/client.o \
./src/main.o \
./src/platform.o 

C_DEPS += \
./src/platform.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 g++ compiler'
	arm-none-eabi-g++ -Wall -O0 -g3 -I"H:\MITCHELL_STUFF_2\Work\Berkeley\Berkeley_AIAA\Code_F2017\FPGA\Xilinx\RoverClient\RoverClient_FPGA.sdk\RoverClient_ConnManager_Core_0_bsp\ps7_cortexa9_0\include" -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -I../../RoverClient_ConnManager_Core_0_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 g++ compiler'
	arm-none-eabi-g++ -Wall -O0 -g3 -I"H:\MITCHELL_STUFF_2\Work\Berkeley\Berkeley_AIAA\Code_F2017\FPGA\Xilinx\RoverClient\RoverClient_FPGA.sdk\RoverClient_ConnManager_Core_0_bsp\ps7_cortexa9_0\include" -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -I../../RoverClient_ConnManager_Core_0_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


