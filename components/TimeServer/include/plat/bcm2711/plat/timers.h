/*
 * Copyright 2019, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */
#pragma once

/*
 *  hwtimer.mem_paddr = 0xfe003000;                                     
 *  hwtimer.mem_size = 0x1000;                                          
 *  hwtimer.irq_irq_number = 97;                                        
 *  hwtimer.irq_irq_type = "arm";                                       
 *  hwtimer.irq_irq_trigger = "edge";
 */

#define HARDWARE_TIMER_INTERFACES                                                   \
    consumes Dummy bcm_timer;                                                       \
    emits Dummy dummy_source;
#define HARDWARE_TIMER_ATTRIBUTES
#define HARDWARE_TIMER_COMPOSITION                                                  \
        connection seL4DTBHardware bcm_timer_conn(from dummy_source, to bcm_timer);
#define HARDWARE_TIMER_CONFIG                                                       \
        bcm_timer.dtb = dtb({"path" : "/soc/timer@7e003000"});                      \
        bcm_timer.generate_interrupts = 1;
#define HARDWARE_TIMER_PLAT_INTERFACES
