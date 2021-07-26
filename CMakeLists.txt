# Copyright © 2015 Matt Robinson
#
# SPDX-License-Identifier: GPL-3.0-or-later

cmake_minimum_required(VERSION 2.8)
project(libfindindent)

set(Boost_USE_STATIC_LIBS ON)
find_package(Boost REQUIRED COMPONENTS unit_test_framework)
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})

add_library(findindent FindIndent.cpp FindIndent.h)

add_executable(Tests Tests/Tests.cpp)
TARGET_LINK_LIBRARIES(Tests findindent ${Boost_LIBRARIES})
add_custom_command(TARGET Tests POST_BUILD COMMAND Tests)
