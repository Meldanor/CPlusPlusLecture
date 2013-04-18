################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/debugging/map.cpp \
../src/debugging/program.cpp 

OBJS += \
./src/debugging/map.o \
./src/debugging/program.o 

CPP_DEPS += \
./src/debugging/map.d \
./src/debugging/program.d 


# Each subdirectory must supply rules for building sources it contributes
src/debugging/%.o: ../src/debugging/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


