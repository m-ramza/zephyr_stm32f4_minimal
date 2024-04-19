# Author: Mohd Ramza <mohdramza@yahoo.com>
# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)

set(BOARD_ROOT ${CMAKE_CURRENT_SOURCE_DIR})
set(BOARD com_f411ce)
set(CURR ${CMAKE_CURRENT_SOURCE_DIR})

list(APPEND DTC_OVERLAY_FILE ${CURR}/boards/target/blackpill_f411ce/blackpill_stm32f411ce.overlay)
message(status ${DTC_OVERLAY_FILE})

# set(BOARD qemu_x86)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(stm32f4_project)

# add top source files here
set(SOURCES src/MAIN/main.c
)

# likely not need to add a .h include here as most modules will go into its own sub directory
set(INCLUDES)

target_include_directories(app PRIVATE ${INCLUDES})
target_sources(app PRIVATE ${SOURCES})

# Specific part for documentation sbuild. You should  provide -DBUILD_DOC=1 in CMake call to let it build documentation.
if(BUILD_DOC)
    include(doc/build_doxygen_documentation.cmake)
endif()
