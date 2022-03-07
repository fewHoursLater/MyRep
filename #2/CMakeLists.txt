cmake_minimum_required(VERSION 2.8)

project(ProPrinter)

#aux_source_directory(. SRC_LIST)

set(ProPrinter_SRC main.cpp CIntN.cpp CIntN_Vert.cpp CIntN_Hori.cpp Autotests.cpp)
set(ProPrinter_HDR Header.h CIntN.h CIntN_Vert.h CIntN_Hori.h Autotests.h Factory.h Factory_Vert.h Factory_Hori.h)

add_executable(${PROJECT_NAME} ${ProPrinter_SRC} ${ProPrinter_HDR})

#target_link_libraries(${PROJECT_NAME} vector)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")