/*
 * Do not modify this file; it is automatically generated from the template
 * linkcmd.xdt in the ti.platforms.tms320x28 package and will be overwritten.
 */

/*
 * put '"'s around paths because, without this, the linker
 * considers '-' as minus operator, not a file name character.
 */


<<<<<<< HEAD
-l"C:\TexasInstruments\projects\ELEX7820_RTOSproject\Debug\configPkg\package\cfg\Lab_proj_Idle_p28FP.o28FP"
-l"C:\TexasInstruments\projects\ELEX7820_RTOSproject\src\sysbios\sysbios.a28FP"
-l"C:\TexasInstruments\bios_6_83_00_18\packages\ti\targets\rts2800\lib\ti.targets.rts2800.a28FP"
-l"C:\TexasInstruments\bios_6_83_00_18\packages\ti\targets\rts2800\lib\boot.a28FP"
-l"C:\TexasInstruments\bios_6_83_00_18\packages\ti\catalog\c2800\initF2837x\lib\Boot.a28FP"
=======
-l"D:\E_Eng\ELEX7820\Labs\ELEX7820_RTOSproject\Debug\configPkg\package\cfg\Lab2Idle_p28FP.o28FP"
-l"D:\E_Eng\ELEX7820\Labs\ELEX7820_RTOSproject\src\sysbios\sysbios.a28FP"
-l"D:\E_Eng\ELEX7820\tools\sysbios\bios_6_83_00_18\packages\ti\targets\rts2800\lib\ti.targets.rts2800.a28FP"
-l"D:\E_Eng\ELEX7820\tools\sysbios\bios_6_83_00_18\packages\ti\targets\rts2800\lib\boot.a28FP"
-l"D:\E_Eng\ELEX7820\tools\sysbios\bios_6_83_00_18\packages\ti\catalog\c2800\initF2837x\lib\Boot.a28FP"
>>>>>>> a441adcca9b728eb3ca94857d959210f385f6e41

/* function aliases */

--symbol_map _xdc_runtime_System_asprintf_va__E=_xdc_runtime_System_asprintf_va__F
--symbol_map _xdc_runtime_System_snprintf_va__E=_xdc_runtime_System_snprintf_va__F
--symbol_map _xdc_runtime_System_printf_va__E=_xdc_runtime_System_printf_va__F
--symbol_map _xdc_runtime_System_aprintf_va__E=_xdc_runtime_System_aprintf_va__F
--symbol_map _xdc_runtime_System_sprintf_va__E=_xdc_runtime_System_sprintf_va__F

/* Elf symbols */
--symbol_map ___TI_STACK_BASE=__stack
--symbol_map ___TI_STACK_SIZE=__STACK_SIZE
--symbol_map ___TI_STATIC_BASE=___bss__
--symbol_map __c_int00=_c_int00


--args 0x0
-heap  0x0
-stack 0x100

/*
 * Linker command file contributions from all loaded packages:
 */

/* Content from xdc.services.global (null): */

/* Content from xdc (null): */

/* Content from xdc.corevers (null): */

/* Content from xdc.rov (null): */

/* Content from xdc.runtime (null): */

/* Content from xdc.rov.runtime (null): */

/* Content from xdc.shelf (null): */

/* Content from xdc.services.spec (null): */

/* Content from xdc.services.intern.xsr (null): */

/* Content from xdc.services.intern.gen (null): */

/* Content from xdc.services.intern.cmd (null): */

/* Content from xdc.bld (null): */

/* Content from ti.targets (null): */

/* Content from ti.catalog.c2800.initF2837x (ti/catalog/c2800/initF2837x/linkcmd.xdt): */
-u _ti_catalog_c2800_initF2837x_Boot_entry


SECTIONS {
    .text:ti_catalog_c2800_initF2837x_flashfuncs : LOAD = FLASHA PAGE = 0,
                                              RUN = D01SARAM PAGE = 0,
                                              table(BINIT)
}


/* Content from xdc.services.getset (null): */

/* Content from ti.targets.rts2800 (null): */

/* Content from ti.sysbios.interfaces (null): */

/* Content from ti.sysbios.family (null): */

/* Content from ti.sysbios.rts (null): */

/* Content from xdc.runtime.knl (null): */

/* Content from ti.sysbios.family.c28.f2837x (null): */

/* Content from ti.catalog.c2800 (null): */

/* Content from ti.catalog (null): */

/* Content from xdc.platform (null): */

/* Content from xdc.cfg (null): */

/* Content from ti.platforms.tms320x28 (null): */

/* Content from ti.sysbios (null): */

/* Content from ti.sysbios.family.c28 (null): */

/* Content from ti.sysbios.hal (null): */

/* Content from ti.sysbios.knl (null): */

/* Content from ti.sysbios.gates (null): */

/* Content from ti.sysbios.xdcruntime (null): */

/* Content from ti.sysbios.utils (null): */

/* Content from configPkg (null): */

/* Content from xdc.services.io (null): */



/*
 * symbolic aliases for static instance objects
 */
_xdc_runtime_Startup__EXECFXN__C = 1;
_xdc_runtime_Startup__RESETFXN__C = 1;
_xdc_rov_runtime_Mon__checksum = 1;
_xdc_rov_runtime_Mon__write = 1;


SECTIONS
{
    .ti_catalog_c2800_initF2837x_begin: load > BEGIN


    xdc.meta: type = COPY
    xdc.noload: type = COPY
}
