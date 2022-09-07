################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include COTS/2-HAL/6-MOTORS/subdir.mk
-include COTS/2-HAL/5-KEYPAD/subdir.mk
-include COTS/2-HAL/4-CLCD/subdir.mk
-include COTS/2-HAL/2-LED/subdir.mk
-include COTS/2-HAL/1-Seven_Segment/subdir.mk
-include COTS/1-MCAL/6-\ TIMER/subdir.mk
-include COTS/1-MCAL/5-ADC/subdir.mk
-include COTS/1-MCAL/4-GIE/subdir.mk
-include COTS/1-MCAL/3-EXTI/subdir.mk
-include COTS/1-MCAL/2-PORT/subdir.mk
-include COTS/1-MCAL/1-DIO/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
MotorDashboard.lss \

FLASH_IMAGE += \
MotorDashboard.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: MotorDashboard.elf secondary-outputs

# Tool invocations
MotorDashboard.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,MotorDashboard.map -mmcu=atmega32 -o "MotorDashboard.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

MotorDashboard.lss: MotorDashboard.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S MotorDashboard.elf  >"MotorDashboard.lss"
	@echo 'Finished building: $@'
	@echo ' '

MotorDashboard.hex: MotorDashboard.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex MotorDashboard.elf  "MotorDashboard.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: MotorDashboard.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 MotorDashboard.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) MotorDashboard.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
