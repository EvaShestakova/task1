cmake_minimum_required(VERSION 2.8)

project(kr1)

#aux_source_directory(. SRC_LIST)

set(VECTOR_SRC main.cpp CVector.cpp CVectorHori.cpp AutoTest.cpp CVectorVert.cpp Temp.cpp)
set(VECTOR_HDR CVector.h CVectorHori.h CVectorVert.h Temp.h)

#add_executable(${PROJECT_NAME} ${SRC_LIST})
#add_library(vector STATIC ${VECTOR_SRC} ${VECTOR_HDR})
add_executable(${PROJECT_NAME} ${VECTOR_SRC} ${VECTOR_HDR})

#target_link_libraries(${PROJECT_NAME} vector)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")