#
_XDCBUILDCOUNT = 0
ifneq (,$(findstring path,$(_USEXDCENV_)))
override XDCPATH = C:/TexasInstruments/bios_6_83_00_18/packages
override XDCROOT = C:/TexasInstruments/ccs1040/xdctools_3_62_01_15_core
override XDCBUILDCFG = ./config.bld
endif
ifneq (,$(findstring args,$(_USEXDCENV_)))
override XDCARGS = 
override XDCTARGETS = 
endif
#
ifeq (0,1)
PKGPATH = C:/TexasInstruments/bios_6_83_00_18/packages;C:/TexasInstruments/ccs1040/xdctools_3_62_01_15_core/packages;..
HOSTOS = Windows
endif
