################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := D:/E_Eng/ELEX7820/CCS/CCS/ccs/tools/compiler/ti-cgt-c2000_20.2.5.LTS

GEN_OPTS__FLAG := --cmd_file="configPkg/compiler.opt" 
GEN_CMDS__FLAG := -l"configPkg/linker.cmd" 

ORDERED_OBJS += \
"./DelayUs.obj" \
"./F2837xD_GlobalVariableDefs.obj" \
"./LabProject_DevInit.obj" \
"./LabProject_main.obj" \
"./dsp/RFFT_f32.obj" \
"./dsp/RFFT_f32_mag.obj" \
"./dsp/RFFT_f32_phase.obj" \
"./dsp/RFFT_f32_sincostable.obj" \
"./periph/F28379DZTQ/F28379D_adc.obj" \
"./periph/F28379DZTQ/F28379D_gpio.obj" \
"./periph/F28379DZTQ/F28379D_pwm.obj" \
"../F2837xD_Headers_BIOS_cpu1.cmd" \
"../TMS320F28379D.cmd" \
$(GEN_CMDS__FLAG) \
-llibc.a \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include dsp/subdir_vars.mk
-include periph/F28379DZTQ/subdir_vars.mk
-include subdir_rules.mk
-include dsp/subdir_rules.mk
-include periph/F28379DZTQ/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
labproject.out \

EXE_OUTPUTS__QUOTED += \
"labproject.out" \

BIN_OUTPUTS += \
labproject.hex \

BIN_OUTPUTS__QUOTED += \
"labproject.hex" \


# All Target
all: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "labproject.out"

# Tool invocations
labproject.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: "$@"'
	@echo 'Invoking: C2000 Linker'
	"D:/E_Eng/ELEX7820/CCS/CCS/ccs/tools/compiler/ti-cgt-c2000_20.2.5.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 --define=CPU1 -g --c11 --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=coffabi -z -m"labproject.map" --stack_size=0x200 --warn_sections -i"D:/E_Eng/ELEX7820/CCS/CCS/ccs/tools/compiler/ti-cgt-c2000_20.2.5.LTS/lib" -i"D:/E_Eng/ELEX7820/CCS/CCS/ccs/tools/compiler/ti-cgt-c2000_20.2.5.LTS/include" --reread_libs --diag_wrap=off --display_error_number --xml_link_info="labproject_linkInfo.xml" --rom_model -o "labproject.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '

labproject.hex: $(EXE_OUTPUTS)
	@echo 'Building secondary target: "$@"'
	@echo 'Invoking: C2000 Hex Utility'
	"D:/E_Eng/ELEX7820/CCS/CCS/ccs/tools/compiler/ti-cgt-c2000_20.2.5.LTS/bin/hex2000" --diag_wrap=off -o "labproject.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building secondary target: "$@"'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(BIN_OUTPUTS__QUOTED)$(GEN_FILES__QUOTED)$(EXE_OUTPUTS__QUOTED)
	-$(RM) "DelayUs.obj" "F2837xD_GlobalVariableDefs.obj" "LabProject_DevInit.obj" "LabProject_main.obj" "dsp\RFFT_f32.obj" "dsp\RFFT_f32_mag.obj" "dsp\RFFT_f32_phase.obj" "dsp\RFFT_f32_sincostable.obj" "periph\F28379DZTQ\F28379D_adc.obj" "periph\F28379DZTQ\F28379D_gpio.obj" "periph\F28379DZTQ\F28379D_pwm.obj" 
	-$(RM) "F2837xD_GlobalVariableDefs.d" "LabProject_DevInit.d" "LabProject_main.d" "dsp\RFFT_f32_sincostable.d" "periph\F28379DZTQ\F28379D_adc.d" "periph\F28379DZTQ\F28379D_gpio.d" "periph\F28379DZTQ\F28379D_pwm.d" 
	-$(RM) "DelayUs.d" "dsp\RFFT_f32.d" "dsp\RFFT_f32_mag.d" "dsp\RFFT_f32_phase.d" 
	-$(RMDIR) $(GEN_MISC_DIRS__QUOTED)
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

