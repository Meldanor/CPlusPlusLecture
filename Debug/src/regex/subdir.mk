################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/regex/parser.cpp \
../src/regex/program.cpp 

OBJS += \
./src/regex/parser.o \
./src/regex/program.o 

CPP_DEPS += \
./src/regex/parser.d \
./src/regex/program.d 


# Each subdirectory must supply rules for building sources it contributes
src/regex/%.o: ../src/regex/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


