################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/EventManager.cpp \
../src/Game.cpp \
../src/StateManager.cpp \
../src/State_Intro.cpp \
../src/Window.cpp \
../src/main.cpp 

OBJS += \
./src/EventManager.o \
./src/Game.o \
./src/StateManager.o \
./src/State_Intro.o \
./src/Window.o \
./src/main.o 

CPP_DEPS += \
./src/EventManager.d \
./src/Game.d \
./src/StateManager.d \
./src/State_Intro.d \
./src/Window.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++0x -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


