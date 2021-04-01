/*
 * Copyright 2019, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */
#pragma once

/*
 * 
 * TODO: what to do, bcm2711 does not have pinmux??
 *
 * #define HARDWARE_MUX_INTERFACES     \
 *     emits Dummy dummy_mux_source;   \
 *     consumes Dummy mux;
 *
 * #define HARDWARE_MUX_ATTRIBUTES
 *
 * #define HARDWARE_MUX_COMPOSITION                                        \
 *     connection seL4DTBHardware mux_conn(from dummy_mux_source, to mux);
 *
 * #define HARDWARE_MUX_CONFIG                 \
 *     mux.dtb = dtb({"path" : "/pinmux@2430000"});
*/

#define HARDWARE_MUX_INTERFACES

#define HARDWARE_MUX_ATTRIBUTES

#define HARDWARE_MUX_COMPOSITION

#define HARDWARE_MUX_CONFIG
