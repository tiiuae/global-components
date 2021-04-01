/*
 * Copyright 2019, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */
#pragma once

/*
 * Finding these involved a lot of digging due to lack of BCM2711 datasheets >:(
 * 
 * from "util_libs/libplatsupport/plat_include/bcm2711/platsupport/plat/spt.h
 * 
 * For once, the README in ClockServer component folder was helpful too.
 * 
 * 
 * BCM2711 TRM
 * section 6.2.3. ARMC interrupts:                   0
 * section 6.3.   GIC-400 - ARMC peripheral IRQs:   64
 * => ARM Timer IRQ: 64 + 0 = 64
 *
 * #define SP804_TIMER_IRQ        64
 *
 * #define BUS_ADDR_OFFSET        0x7E000000
 * #define PADDDR_OFFSET          0xFE000000
 *
 *
 * According to BCM2711 TRM section 12.2. Timer Registers:
 *      0x7e00b000
 *
 * #define SP804_TIMER_BUSADDR    0x7E00B000
 * #define SP804_TIMER_PADDR      (SP804_TIMER_BUSADDR-BUS_ADDR_OFFSET+PADDDR_OFFSET)
 * 
 * 
 * => SP804_TIMER_PADDR = 0xFE00B000 ??
 */

#define HARDWARE_CLOCK_EXTRA_IMPORTS

#define HARDWARE_CLOCK_COMPONENT

#define HARDWARE_CLOCK_INTERFACES   \
    emits Dummy dummy_source;       \
    consumes Dummy clk;             \

#define HARDWARE_CLOCK_EXTRA_INTERFACES

#define HARDWARE_CLOCK_ATTRIBUTES

#define HARDWARE_CLOCK_COMPOSITION  \
    connection seL4DTBHardware clk_conn(from dummy_source, to clk); \

#define HARDWARE_CLOCK_CONFIG   \
    clk.dtb = dtb({ "path" : "/timer" });
