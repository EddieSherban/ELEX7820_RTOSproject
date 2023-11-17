#
_XDCBUILDCOUNT = 
ifneq (,$(findstring path,$(_USEXDCENV_)))
override XDCPATH = D:/E_Eng/ELEX7820/tools/sysbios/bios_6_83_00_18/packages;D:/E_Eng/ELEX7820/Labs/ELEX7820_RTOSproject/.config
override XDCROOT = D:/E_Eng/ELEX7820/CCS/CCS/xdctools_3_62_01_15_core
override XDCBUILDCFG = ./config.bld
endif
ifneq (,$(findstring args,$(_USEXDCENV_)))
override XDCARGS = 
override XDCTARGETS = 
endif
#
ifeq (0,1)
PKGPATH = D:/E_Eng/ELEX7820/tools/sysbios/bios_6_83_00_18/packages;D:/E_Eng/ELEX7820/Labs/ELEX7820_RTOSproject/.config;D:/E_Eng/ELEX7820/CCS/CCS/xdctools_3_62_01_15_core/packages;..
HOSTOS = Windows
endif
