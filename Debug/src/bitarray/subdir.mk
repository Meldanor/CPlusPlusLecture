################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/bitarray/bitarray.cpp \
../src/bitarray/main.cpp 

OBJS += \
./src/bitarray/bitarray.o \
./src/bitarray/main.o 

CPP_DEPS += \
./src/bitarray/bitarray.d \
./src/bitarray/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/bitarray/%.o: ../src/bitarray/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


