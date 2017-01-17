#
# Licensed to the Apache Software Foundation (ASF) under one
# or more contributor license agreements. See the NOTICE file
# distributed with this work for additional information
# regarding copyright ownership. The ASF licenses this file
# to you under the Apache License, Version 2.0 (the
# "License"); you may not use this file except in compliance
# with the License. You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing,
# software distributed under the License is distributed on an
# "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
# KIND, either express or implied. See the License for the
# specific language governing permissions and limitations
# under the License.
#
SET(CMAKE_CXX_COMPILER g++)
cmake_minimum_required(VERSION 3.7)
find_package(Boost 1.53.0 REQUIRED)
include_directories(SYSTEM "${Boost_INCLUDE_DIRS}")
include_directories("../include")
include_directories("../include/zookeeper")

#Make sure gen-cpp files can be included
include_directories("${CMAKE_CURRENT_BINARY_DIR}")
#include_directories("${CMAKE_CURRENT_BINARY_DIR}/gen-cpp")
#include_directories("${PROJECT_SOURCE_DIR}/lib/cpp/src")

set(nuxcpp_SOURCES
    NZooKeeper.cpp
    NServicesRegistry.cpp
)

add_library(nuxcpp STATIC ${nuxcpp_SOURCES})
#LINK_AGAINST_THRIFT_LIBRARY(tutorialgencpp thrift)
target_link_libraries(nuxcpp zookeeper_mt)

add_executable(mainTest main.cpp)
target_link_libraries(mainTest nuxcpp)
#LINK_AGAINST_THRIFT_LIBRARY(TutorialServer thrift)
target_link_libraries(mainTest ${ZLIB_LIBRARIES})

install (TARGETS mainTest DESTINATION bin)

