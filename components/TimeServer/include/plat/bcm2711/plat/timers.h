/*
 * Copyright 2019, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */
#pragma once

#define HARDWARE_TIMER_INTERFACES                                                   \
    emits Dummy dummy_source;                                                       \
    consumes Dummy spt;
#define HARDWARE_TIMER_ATTRIBUTES
#define HARDWARE_TIMER_COMPOSITION                                                  \
        connection seL4DTBHardware spt_conn(from dummy_source, to spt);
#define HARDWARE_TIMER_CONFIG                                                       \
        spt.dtb = dtb({"path" : "/timer"});                                         \
        spt.generate_interrupts = 1;                                                \
        //spt.irq_irq_number = 42;                                                    
        //spt.irq_irq_type = "arm";                                                   
        //spt.irq_irq_trigger = "edge";                                               
#define HARDWARE_TIMER_PLAT_INTERFACES
