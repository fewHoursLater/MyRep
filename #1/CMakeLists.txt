cmake_minimum_required(VERSION 2.8)

project(Printer)

#aux_source_directory(. SRC_LIST)

set(Printer_SRC main.cpp CIntN.cpp CData1.cpp CData0.cpp Autotests.cpp)
set(Printer_HDR Header.h CIntN.h CData.h CData0.h CData1.h Autotests.h)

add_executable(${PROJECT_NAME} ${Printer_SRC} ${Printer_HDR})

#target_link_libraries(${PROJECT_NAME} vector)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")