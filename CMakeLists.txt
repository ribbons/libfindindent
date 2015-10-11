# This file is part of libfindindent.
# Copyright © 2015 by the authors - see the AUTHORS file for details.
#
# This program is free software: you can redistribute it and/or modify it under the terms of the GNU General
# Public License as published by the Free Software Foundation, either version 3 of the License, or (at your
# option) any later version.
#
# This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
# License for more details.
#
# You should have received a copy of the GNU General Public License along with this program.  If not, see
# <http://www.gnu.org/licenses/>.

cmake_minimum_required(VERSION 2.8)
project(libfindindent)

set(Boost_USE_STATIC_LIBS ON)
find_package(Boost REQUIRED COMPONENTS unit_test_framework)
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})

add_library(findindent FindIndent.cpp FindIndent.h)

add_executable(Tests Tests/Tests.cpp)
TARGET_LINK_LIBRARIES(Tests findindent ${Boost_LIBRARIES})
add_custom_command(TARGET Tests POST_BUILD COMMAND Tests)
