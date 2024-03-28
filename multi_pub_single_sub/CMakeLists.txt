# Copyright (c) 2024 WATANABE Aoi
# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

project(multi_pub_single_sub LANGUAGES C)

include_directories(src include)

FILE(GLOB app_sources ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c)

target_sources(app PRIVATE ${app_sources})

FILE(GLOB event_sources src/events/*.c)
target_sources(app PRIVATE ${event_sources})
