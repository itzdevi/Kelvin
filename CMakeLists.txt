cmake_minimum_required(VERSION 3.15) 
PROJECT ( kelvin )

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

include_directories(${PROJECT_SOURCE_DIR})

include_directories(
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/src
)

file(GLOB all_SRCS
        "${PROJECT_SOURCE_DIR}/include/*.h"
        "${PROJECT_SOURCE_DIR}/src/*.c"
        "${PROJECT_SOURCE_DIR}/src/*.h"
)


add_executable(  ${PROJECT_NAME} ${all_SRCS})

target_link_libraries(${PROJECT_NAME} "${PROJECT_SOURCE_DIR}/lib/SDL2.lib" "${PROJECT_SOURCE_DIR}/lib/SDL2main.lib")