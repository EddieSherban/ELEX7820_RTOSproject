# invoke SourceDir generated makefile for Lab2Idle.p28FP
Lab2Idle.p28FP: .libraries,Lab2Idle.p28FP
.libraries,Lab2Idle.p28FP: package/cfg/Lab2Idle_p28FP.xdl
	$(MAKE) -f D:\E_Eng\ELEX7820\Labs\lab_project/src/makefile.libs

clean::
	$(MAKE) -f D:\E_Eng\ELEX7820\Labs\lab_project/src/makefile.libs clean

