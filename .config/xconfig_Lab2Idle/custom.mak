## THIS IS A GENERATED FILE -- DO NOT EDIT
.configuro: .libraries,28FP linker.cmd package/cfg/Lab2Idle_p28FP.o28FP

# To simplify configuro usage in makefiles:
#     o create a generic linker command file name 
#     o set modification times of compiler.opt* files to be greater than
#       or equal to the generated config header
#
linker.cmd: package/cfg/Lab2Idle_p28FP.xdl
	$(SED) 's"^\"\(package/cfg/Lab2Idle_p28FPcfg.cmd\)\"$""\"D:/E_Eng/ELEX7820/Labs/Lab2/Lab2/.config/xconfig_Lab2Idle/\1\""' package/cfg/Lab2Idle_p28FP.xdl > $@
	-$(SETDATE) -r:max package/cfg/Lab2Idle_p28FP.h compiler.opt compiler.opt.defs
