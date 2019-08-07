################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Anim_Base.cpp \
../src/Anim_Directional.cpp \
../src/EventManager.cpp \
../src/Game.cpp \
../src/SpriteSheet.cpp \
../src/StateManager.cpp \
../src/State_Game.cpp \
../src/State_Intro.cpp \
../src/State_MainMenu.cpp \
../src/State_Paused.cpp \
../src/Window.cpp \
../src/main.cpp 

OBJS += \
./src/Anim_Base.o \
./src/Anim_Directional.o \
./src/EventManager.o \
./src/Game.o \
./src/SpriteSheet.o \
./src/StateManager.o \
./src/State_Game.o \
./src/State_Intro.o \
./src/State_MainMenu.o \
./src/State_Paused.o \
./src/Window.o \
./src/main.o 

CPP_DEPS += \
./src/Anim_Base.d \
./src/Anim_Directional.d \
./src/EventManager.d \
./src/Game.d \
./src/SpriteSheet.d \
./src/StateManager.d \
./src/State_Game.d \
./src/State_Intro.d \
./src/State_MainMenu.d \
./src/State_Paused.d \
./src/Window.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++0x -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


