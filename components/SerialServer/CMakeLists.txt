#
# Copyright 2018, Data61, CSIRO (ABN 41 687 119 230)
# Copyright 2022, Technology Innovation Institute
#
# SPDX-License-Identifier: BSD-2-Clause
#

cmake_minimum_required(VERSION 3.8.2)

project(SerialServer C)

if(KernelArchARM)
    set(CAmkESDTS ON CACHE BOOL "" FORCE)
endif()

set(CAmkESCPP ON CACHE BOOL "" FORCE)

set(PlatIncPrefix "")
set(PlatSrcPrefix "")

# ARM platforms have similar serial configurations in their DTSes and can share
# similar headers and code
if(KernelArchARM)
    set(PlatSrcPrefix "arm_common")
    if(KernelPlatformRpi4)
        set(PlatIncPrefix "bcm2711")
    else()
        set(PlatIncPrefix "arm_common")
    endif()
else()
    set(PlatSrcPrefix "${KernelPlatform}")
    set(PlatIncPrefix "${KernelPlatform}")
endif()

DeclareCAmkESComponent(
    SerialServer
    SOURCES
    src/serial.c
    src/plat.c
    src/server_virtqueue.c
    src/plat/${PlatSrcPrefix}/plat.c
    LIBS
    virtqueue
    vswitch
)

CAmkESAddCPPInclude("${CMAKE_CURRENT_LIST_DIR}/include/plat/${PlatIncPrefix}/")

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/camkes-putchar-client camkes-putchar-client)
