################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
%.obj: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/TexasInstruments/ccs1040/ccs/tools/compiler/ti-cgt-c2000_20.2.5.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 --include_path="C:/TexasInstruments/projects/ELEX7820_RTOSproject" --include_path="C:/TexasInstruments/bios_6_83_00_18/packages/ti/posix/ccs" --include_path="C:/TexasInstruments/ccs1040/ccs/tools/compiler/ti-cgt-c2000_20.2.5.LTS/include" --define=CPU1 -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=coffabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

build-1652588097:
	@$(MAKE) --no-print-directory -Onone -f subdir_rules.mk build-1652588097-inproc

build-1652588097-inproc: ../Lab_proj_Idle.cfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: XDCtools'
	"C:/TexasInstruments/ccs1040/xdctools_3_62_01_15_core/xs" --xdcpath="C:/TexasInstruments/bios_6_83_00_18/packages;" xdc.tools.configuro -o configPkg -t ti.targets.C28_float -p ti.platforms.tms320x28:TMS320F28379D -r release -c "C:/TexasInstruments/ccs1040/ccs/tools/compiler/ti-cgt-c2000_20.2.5.LTS" --compileOptions "-g" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

configPkg/linker.cmd: build-1652588097 ../Lab_proj_Idle.cfg
configPkg/compiler.opt: build-1652588097
configPkg/: build-1652588097


