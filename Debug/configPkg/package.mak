#
#  Do not edit this file.  This file is generated from 
#  package.bld.  Any modifications to this file will be 
#  overwritten whenever makefiles are re-generated.
#

unexport MAKEFILE_LIST
MK_NOGENDEPS := $(filter clean,$(MAKECMDGOALS))
override PKGDIR = configPkg
XDCINCS = -I. -I$(strip $(subst ;, -I,$(subst $(space),\$(space),$(XPKGPATH))))
XDCCFGDIR = package/cfg/

#
# The following dependencies ensure package.mak is rebuilt
# in the event that some included BOM script changes.
#
ifneq (clean,$(MAKECMDGOALS))
D:/E_Eng/ELEX7820/CCS/CCS/xdctools_3_62_01_15_core/packages/xdc/utils.js:
package.mak: D:/E_Eng/ELEX7820/CCS/CCS/xdctools_3_62_01_15_core/packages/xdc/utils.js
D:/E_Eng/ELEX7820/CCS/CCS/xdctools_3_62_01_15_core/packages/xdc/xdc.tci:
package.mak: D:/E_Eng/ELEX7820/CCS/CCS/xdctools_3_62_01_15_core/packages/xdc/xdc.tci
D:/E_Eng/ELEX7820/CCS/CCS/xdctools_3_62_01_15_core/packages/xdc/template.xs:
package.mak: D:/E_Eng/ELEX7820/CCS/CCS/xdctools_3_62_01_15_core/packages/xdc/template.xs
D:/E_Eng/ELEX7820/CCS/CCS/xdctools_3_62_01_15_core/packages/xdc/om2.xs:
package.mak: D:/E_Eng/ELEX7820/CCS/CCS/xdctools_3_62_01_15_core/packages/xdc/om2.xs
D:/E_Eng/ELEX7820/CCS/CCS/xdctools_3_62_01_15_core/packages/xdc/xmlgen.xs:
package.mak: D:/E_Eng/ELEX7820/CCS/CCS/xdctools_3_62_01_15_core/packages/xdc/xmlgen.xs
D:/E_Eng/ELEX7820/CCS/CCS/xdctools_3_62_01_15_core/packages/xdc/xmlgen2.xs:
package.mak: D:/E_Eng/ELEX7820/CCS/CCS/xdctools_3_62_01_15_core/packages/xdc/xmlgen2.xs
D:/E_Eng/ELEX7820/CCS/CCS/xdctools_3_62_01_15_core/packages/xdc/Warnings.xs:
package.mak: D:/E_Eng/ELEX7820/CCS/CCS/xdctools_3_62_01_15_core/packages/xdc/Warnings.xs
D:/E_Eng/ELEX7820/CCS/CCS/xdctools_3_62_01_15_core/packages/xdc/IPackage.xs:
package.mak: D:/E_Eng/ELEX7820/CCS/CCS/xdctools_3_62_01_15_core/packages/xdc/IPackage.xs
D:/E_Eng/ELEX7820/CCS/CCS/xdctools_3_62_01_15_core/packages/xdc/package.xs:
package.mak: D:/E_Eng/ELEX7820/CCS/CCS/xdctools_3_62_01_15_core/packages/xdc/package.xs
D:/E_Eng/ELEX7820/CCS/CCS/xdctools_3_62_01_15_core/packages/xdc/services/global/Clock.xs:
package.mak: D:/E_Eng/ELEX7820/CCS/CCS/xdctools_3_62_01_15_core/packages/xdc/services/global/Clock.xs
D:/E_Eng/ELEX7820/CCS/CCS/xdctools_3_62_01_15_core/packages/xdc/services/global/Trace.xs:
package.mak: D:/E_Eng/ELEX7820/CCS/CCS/xdctools_3_62_01_15_core/packages/xdc/services/global/Trace.xs
D:/E_Eng/ELEX7820/CCS/CCS/xdctools_3_62_01_15_core/packages/xdc/bld/bld.js:
package.mak: D:/E_Eng/ELEX7820/CCS/CCS/xdctools_3_62_01_15_core/packages/xdc/bld/bld.js
D:/E_Eng/ELEX7820/CCS/CCS/xdctools_3_62_01_15_core/packages/xdc/bld/BuildEnvironment.xs:
package.mak: D:/E_Eng/ELEX7820/CCS/CCS/xdctools_3_62_01_15_core/packages/xdc/bld/BuildEnvironment.xs
D:/E_Eng/ELEX7820/CCS/CCS/xdctools_3_62_01_15_core/packages/xdc/bld/PackageContents.xs:
package.mak: D:/E_Eng/ELEX7820/CCS/CCS/xdctools_3_62_01_15_core/packages/xdc/bld/PackageContents.xs
D:/E_Eng/ELEX7820/CCS/CCS/xdctools_3_62_01_15_core/packages/xdc/bld/_gen.xs:
package.mak: D:/E_Eng/ELEX7820/CCS/CCS/xdctools_3_62_01_15_core/packages/xdc/bld/_gen.xs
D:/E_Eng/ELEX7820/CCS/CCS/xdctools_3_62_01_15_core/packages/xdc/bld/Library.xs:
package.mak: D:/E_Eng/ELEX7820/CCS/CCS/xdctools_3_62_01_15_core/packages/xdc/bld/Library.xs
D:/E_Eng/ELEX7820/CCS/CCS/xdctools_3_62_01_15_core/packages/xdc/bld/Executable.xs:
package.mak: D:/E_Eng/ELEX7820/CCS/CCS/xdctools_3_62_01_15_core/packages/xdc/bld/Executable.xs
D:/E_Eng/ELEX7820/CCS/CCS/xdctools_3_62_01_15_core/packages/xdc/bld/Repository.xs:
package.mak: D:/E_Eng/ELEX7820/CCS/CCS/xdctools_3_62_01_15_core/packages/xdc/bld/Repository.xs
D:/E_Eng/ELEX7820/CCS/CCS/xdctools_3_62_01_15_core/packages/xdc/bld/Configuration.xs:
package.mak: D:/E_Eng/ELEX7820/CCS/CCS/xdctools_3_62_01_15_core/packages/xdc/bld/Configuration.xs
D:/E_Eng/ELEX7820/CCS/CCS/xdctools_3_62_01_15_core/packages/xdc/bld/Script.xs:
package.mak: D:/E_Eng/ELEX7820/CCS/CCS/xdctools_3_62_01_15_core/packages/xdc/bld/Script.xs
D:/E_Eng/ELEX7820/CCS/CCS/xdctools_3_62_01_15_core/packages/xdc/bld/Manifest.xs:
package.mak: D:/E_Eng/ELEX7820/CCS/CCS/xdctools_3_62_01_15_core/packages/xdc/bld/Manifest.xs
D:/E_Eng/ELEX7820/CCS/CCS/xdctools_3_62_01_15_core/packages/xdc/bld/Utils.xs:
package.mak: D:/E_Eng/ELEX7820/CCS/CCS/xdctools_3_62_01_15_core/packages/xdc/bld/Utils.xs
D:/E_Eng/ELEX7820/CCS/CCS/xdctools_3_62_01_15_core/packages/xdc/bld/ITarget.xs:
package.mak: D:/E_Eng/ELEX7820/CCS/CCS/xdctools_3_62_01_15_core/packages/xdc/bld/ITarget.xs
D:/E_Eng/ELEX7820/CCS/CCS/xdctools_3_62_01_15_core/packages/xdc/bld/ITarget2.xs:
package.mak: D:/E_Eng/ELEX7820/CCS/CCS/xdctools_3_62_01_15_core/packages/xdc/bld/ITarget2.xs
D:/E_Eng/ELEX7820/CCS/CCS/xdctools_3_62_01_15_core/packages/xdc/bld/ITarget3.xs:
package.mak: D:/E_Eng/ELEX7820/CCS/CCS/xdctools_3_62_01_15_core/packages/xdc/bld/ITarget3.xs
D:/E_Eng/ELEX7820/CCS/CCS/xdctools_3_62_01_15_core/packages/xdc/bld/ITargetFilter.xs:
package.mak: D:/E_Eng/ELEX7820/CCS/CCS/xdctools_3_62_01_15_core/packages/xdc/bld/ITargetFilter.xs
D:/E_Eng/ELEX7820/CCS/CCS/xdctools_3_62_01_15_core/packages/xdc/bld/package.xs:
package.mak: D:/E_Eng/ELEX7820/CCS/CCS/xdctools_3_62_01_15_core/packages/xdc/bld/package.xs
package.mak: config.bld
D:/E_Eng/ELEX7820/tools/sysbios/bios_6_83_00_18/packages/ti/targets/ITarget.xs:
package.mak: D:/E_Eng/ELEX7820/tools/sysbios/bios_6_83_00_18/packages/ti/targets/ITarget.xs
D:/E_Eng/ELEX7820/tools/sysbios/bios_6_83_00_18/packages/ti/targets/C28_large.xs:
package.mak: D:/E_Eng/ELEX7820/tools/sysbios/bios_6_83_00_18/packages/ti/targets/C28_large.xs
D:/E_Eng/ELEX7820/tools/sysbios/bios_6_83_00_18/packages/ti/targets/C28_float.xs:
package.mak: D:/E_Eng/ELEX7820/tools/sysbios/bios_6_83_00_18/packages/ti/targets/C28_float.xs
D:/E_Eng/ELEX7820/tools/sysbios/bios_6_83_00_18/packages/ti/targets/package.xs:
package.mak: D:/E_Eng/ELEX7820/tools/sysbios/bios_6_83_00_18/packages/ti/targets/package.xs
package.mak: package.bld
D:/E_Eng/ELEX7820/CCS/CCS/xdctools_3_62_01_15_core/packages/xdc/tools/configuro/template/compiler.opt.xdt:
package.mak: D:/E_Eng/ELEX7820/CCS/CCS/xdctools_3_62_01_15_core/packages/xdc/tools/configuro/template/compiler.opt.xdt
D:/E_Eng/ELEX7820/CCS/CCS/xdctools_3_62_01_15_core/packages/xdc/services/io/File.xs:
package.mak: D:/E_Eng/ELEX7820/CCS/CCS/xdctools_3_62_01_15_core/packages/xdc/services/io/File.xs
D:/E_Eng/ELEX7820/CCS/CCS/xdctools_3_62_01_15_core/packages/xdc/services/io/package.xs:
package.mak: D:/E_Eng/ELEX7820/CCS/CCS/xdctools_3_62_01_15_core/packages/xdc/services/io/package.xs
D:/E_Eng/ELEX7820/CCS/CCS/xdctools_3_62_01_15_core/packages/xdc/tools/configuro/template/compiler.defs.xdt:
package.mak: D:/E_Eng/ELEX7820/CCS/CCS/xdctools_3_62_01_15_core/packages/xdc/tools/configuro/template/compiler.defs.xdt
D:/E_Eng/ELEX7820/CCS/CCS/xdctools_3_62_01_15_core/packages/xdc/tools/configuro/template/custom.mak.exe.xdt:
package.mak: D:/E_Eng/ELEX7820/CCS/CCS/xdctools_3_62_01_15_core/packages/xdc/tools/configuro/template/custom.mak.exe.xdt
D:/E_Eng/ELEX7820/CCS/CCS/xdctools_3_62_01_15_core/packages/xdc/tools/configuro/template/package.xs.xdt:
package.mak: D:/E_Eng/ELEX7820/CCS/CCS/xdctools_3_62_01_15_core/packages/xdc/tools/configuro/template/package.xs.xdt
endif

ti.targets.C28_float.rootDir ?= D:/E_Eng/ELEX7820/CCS/CCS/ccs/tools/compiler/ti-cgt-c2000_20.2.5.LTS
ti.targets.packageBase ?= D:/E_Eng/ELEX7820/tools/sysbios/bios_6_83_00_18/packages/ti/targets/
.PRECIOUS: $(XDCCFGDIR)/%.o28FP
.PHONY: all,28FP .dlls,28FP .executables,28FP test,28FP
all,28FP: .executables,28FP
.executables,28FP: .libraries,28FP
.executables,28FP: .dlls,28FP
.dlls,28FP: .libraries,28FP
.libraries,28FP: .interfaces
	@$(RM) $@
	@$(TOUCH) "$@"

.help::
	@$(ECHO) xdc test,28FP
	@$(ECHO) xdc .executables,28FP
	@$(ECHO) xdc .libraries,28FP
	@$(ECHO) xdc .dlls,28FP


all: .executables 
.executables: .libraries .dlls
.libraries: .interfaces

PKGCFGS := $(wildcard package.xs) package/build.cfg
.interfaces: package/package.xdc.inc package/package.defs.h package.xdc $(PKGCFGS)

-include package/package.xdc.dep
package/%.xdc.inc package/%_configPkg.c package/%.defs.h: %.xdc $(PKGCFGS)
	@$(MSG) generating interfaces for package configPkg" (because $@ is older than $(firstword $?))" ...
	$(XSRUN) -f xdc/services/intern/cmd/build.xs $(MK_IDLOPTS) -m package/package.xdc.dep -i package/package.xdc.inc package.xdc

.dlls,28FP .dlls: Lab2Idle.p28FP

-include package/cfg/Lab2Idle_p28FP.mak
-include package/cfg/Lab2Idle_p28FP.cfg.mak
ifeq (,$(MK_NOGENDEPS))
-include package/cfg/Lab2Idle_p28FP.dep
endif
Lab2Idle.p28FP: package/cfg/Lab2Idle_p28FP.xdl
	@


ifeq (,$(wildcard .libraries,28FP))
Lab2Idle.p28FP package/cfg/Lab2Idle_p28FP.c: .libraries,28FP
endif

package/cfg/Lab2Idle_p28FP.c package/cfg/Lab2Idle_p28FP.h package/cfg/Lab2Idle_p28FP.xdl: override _PROG_NAME := Lab2Idle.x28FP
package/cfg/Lab2Idle_p28FP.c: package/cfg/Lab2Idle_p28FP.cfg
package/cfg/Lab2Idle_p28FP.xdc.inc: package/cfg/Lab2Idle_p28FP.xdl
package/cfg/Lab2Idle_p28FP.xdl package/cfg/Lab2Idle_p28FP.c: .interfaces

clean:: clean,28FP
	-$(RM) package/cfg/Lab2Idle_p28FP.cfg
	-$(RM) package/cfg/Lab2Idle_p28FP.dep
	-$(RM) package/cfg/Lab2Idle_p28FP.c
	-$(RM) package/cfg/Lab2Idle_p28FP.xdc.inc

clean,28FP::
	-$(RM) Lab2Idle.p28FP
.executables,28FP .executables: Lab2Idle.x28FP

Lab2Idle.x28FP: |Lab2Idle.p28FP

-include package/cfg/Lab2Idle.x28FP.mak
Lab2Idle.x28FP: package/cfg/Lab2Idle_p28FP.o28FP 
	$(RM) $@
	@$(MSG) lnk28FP $@ ...
	$(RM) $(XDCCFGDIR)/$@.map
	$(ti.targets.C28_float.rootDir)/bin/cl2000 -fs $(XDCCFGDIR)$(dir $@). -q -u _c_int00 -z  -o $@ package/cfg/Lab2Idle_p28FP.o28FP   package/cfg/Lab2Idle_p28FP.xdl  -w -c -m $(XDCCFGDIR)/$@.map -l $(ti.targets.C28_float.rootDir)/lib/libc.a
	
Lab2Idle.x28FP: export C_DIR=
Lab2Idle.x28FP: PATH:=$(ti.targets.C28_float.rootDir)/bin/;$(PATH)
Lab2Idle.x28FP: Path:=$(ti.targets.C28_float.rootDir)/bin/;$(PATH)

Lab2Idle.test test,28FP test: Lab2Idle.x28FP.test

Lab2Idle.x28FP.test:: Lab2Idle.x28FP
ifeq (,$(_TESTLEVEL))
	@$(MAKE) -R -r --no-print-directory -f $(XDCROOT)/packages/xdc/bld/xdc.mak _TESTLEVEL=1 Lab2Idle.x28FP.test
else
	@$(MSG) running $<  ...
	$(call EXEC.Lab2Idle.x28FP, ) 
endif

clean,28FP::
	-$(RM) $(wildcard .tmp,Lab2Idle.x28FP,*)


clean:: clean,28FP

clean,28FP::
	-$(RM) Lab2Idle.x28FP
%,copy:
	@$(if $<,,$(MSG) don\'t know how to build $*; exit 1)
	@$(MSG) cp $< $@
	$(RM) $@
	$(CP) $< $@
Lab2Idle_p28FP.o28FP,copy : package/cfg/Lab2Idle_p28FP.o28FP
Lab2Idle_p28FP.s28FP,copy : package/cfg/Lab2Idle_p28FP.s28FP

$(XDCCFGDIR)%.c $(XDCCFGDIR)%.h $(XDCCFGDIR)%.xdl: $(XDCCFGDIR)%.cfg $(XDCROOT)/packages/xdc/cfg/Main.xs | .interfaces
	@$(MSG) "configuring $(_PROG_NAME) from $< ..."
	$(CONFIG) $(_PROG_XSOPTS) xdc.cfg $(_PROG_NAME) $(XDCCFGDIR)$*.cfg $(XDCCFGDIR)$*

.PHONY: release,configPkg
ifeq (,$(MK_NOGENDEPS))
-include package/rel/configPkg.tar.dep
endif
package/rel/configPkg/configPkg/package/package.rel.xml: package/package.bld.xml
package/rel/configPkg/configPkg/package/package.rel.xml: package/build.cfg
package/rel/configPkg/configPkg/package/package.rel.xml: package/package.xdc.inc
package/rel/configPkg/configPkg/package/package.rel.xml: .force
	@$(MSG) generating external release references $@ ...
	$(XS) $(JSENV) -f $(XDCROOT)/packages/xdc/bld/rel.js $(MK_RELOPTS) . $@

configPkg.tar: package/rel/configPkg.xdc.inc package/rel/configPkg/configPkg/package/package.rel.xml
	@$(MSG) making release file $@ "(because of $(firstword $?))" ...
	-$(RM) $@
	$(call MKRELTAR,package/rel/configPkg.xdc.inc,package/rel/configPkg.tar.dep)


release release,configPkg: all configPkg.tar
clean:: .clean
	-$(RM) configPkg.tar
	-$(RM) package/rel/configPkg.xdc.inc
	-$(RM) package/rel/configPkg.tar.dep

clean:: .clean
	-$(RM) .libraries $(wildcard .libraries,*)
clean:: 
	-$(RM) .dlls $(wildcard .dlls,*)
#
# The following clean rule removes user specified
# generated files or directories.
#

ifneq (clean,$(MAKECMDGOALS))
ifeq (,$(wildcard package))
    $(shell $(MKDIR) package)
endif
ifeq (,$(wildcard package/cfg))
    $(shell $(MKDIR) package/cfg)
endif
ifeq (,$(wildcard package/lib))
    $(shell $(MKDIR) package/lib)
endif
ifeq (,$(wildcard package/rel))
    $(shell $(MKDIR) package/rel)
endif
ifeq (,$(wildcard package/internal))
    $(shell $(MKDIR) package/internal)
endif
endif
clean::
	-$(RMDIR) package

include custom.mak
