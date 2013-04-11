################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/game/TextAdventure.cpp 

OBJS += \
./src/game/TextAdventure.o 

CPP_DEPS += \
./src/game/TextAdventure.d 


# Each subdirectory must supply rules for building sources it contributes
src/game/%.o: ../src/game/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


