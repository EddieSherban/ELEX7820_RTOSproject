## THIS IS A GENERATED FILE -- DO NOT EDIT
.configuro: .libraries,28FP linker.cmd package/cfg/Lab_proj_Idle_p28FP.o28FP

# To simplify configuro usage in makefiles:
#     o create a generic linker command file name 
#     o set modification times of compiler.opt* files to be greater than
#       or equal to the generated config header
#
linker.cmd: package/cfg/Lab_proj_Idle_p28FP.xdl
	$(SED) 's"^\"\(package/cfg/Lab_proj_Idle_p28FPcfg.cmd\)\"$""\"D:/E_Eng/ELEX7820/Labs/ELEX7820_RTOSproject/.config/xconfig_Lab_proj_Idle/\1\""' package/cfg/Lab_proj_Idle_p28FP.xdl > $@
	-$(SETDATE) -r:max package/cfg/Lab_proj_Idle_p28FP.h compiler.opt compiler.opt.defs
