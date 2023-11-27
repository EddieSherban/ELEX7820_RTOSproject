# invoke SourceDir generated makefile for Lab_proj_Idle.p28FP
Lab_proj_Idle.p28FP: .libraries,Lab_proj_Idle.p28FP
.libraries,Lab_proj_Idle.p28FP: package/cfg/Lab_proj_Idle_p28FP.xdl
	$(MAKE) -f D:\E_Eng\ELEX7820\Labs\ELEX7820_RTOSproject/src/makefile.libs

clean::
	$(MAKE) -f D:\E_Eng\ELEX7820\Labs\ELEX7820_RTOSproject/src/makefile.libs clean

