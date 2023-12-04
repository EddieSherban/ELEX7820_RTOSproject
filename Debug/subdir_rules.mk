################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
%.obj: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"D:/E_Eng/ELEX7820/CCS/CCS/ccs/tools/compiler/ti-cgt-c2000_20.2.5.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 --include_path="D:/E_Eng/ELEX7820/Labs/ELEX7820_RTOSproject_updated" --include_path="D:/E_Eng/ELEX7820/tools/sysbios/bios_6_83_00_18/packages/ti/posix/ccs" --include_path="D:/E_Eng/ELEX7820/CCS/CCS/ccs/tools/compiler/ti-cgt-c2000_20.2.5.LTS/include" --define=CPU1 -g --c11 --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=coffabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

build-1785692145:
	@$(MAKE) --no-print-directory -Onone -f subdir_rules.mk build-1785692145-inproc

build-1785692145-inproc: ../Lab2Idle.cfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: XDCtools'
	"D:/E_Eng/ELEX7820/CCS/CCS/xdctools_3_62_01_15_core/xs" --xdcpath="D:/E_Eng/ELEX7820/tools/sysbios/bios_6_83_00_18/packages;" xdc.tools.configuro -o configPkg -t ti.targets.C28_float -p ti.platforms.tms320x28:TMS320F28379D -r release -c "D:/E_Eng/ELEX7820/CCS/CCS/ccs/tools/compiler/ti-cgt-c2000_20.2.5.LTS" --compileOptions "-g" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

configPkg/linker.cmd: build-1785692145 ../Lab2Idle.cfg
configPkg/compiler.opt: build-1785692145
configPkg/: build-1785692145


