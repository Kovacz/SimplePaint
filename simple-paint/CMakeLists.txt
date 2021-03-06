cmake_minimum_required(VERSION 3.11 FATAL_ERROR) 

project(SimplePaint)

find_package(glfw3 REQUIRED)

set(CMAKE_CXX_FLAGS        "${CMAKE_CXX_FLAGS} -std=c++17")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo")

set(SRC_DIR     "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(LIBS_DIR    "${CMAKE_CURRENT_SOURCE_DIR}/external")
set(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(BUILD_DIR   "${CMAKE_CURRENT_SOURCE_DIR}/build")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/bin")

file(GLOB SOURCES "${SRC_DIR}/*.cpp" "${SRC_DIR}/*.vert" "${SRC_DIR}/*.frag")
file(GLOB HEADERS "${INCLUDE_DIR}/*.h" "${INCLUDE_DIR}/*.hpp")

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_DIR} "${LIBS_DIR}/SOIL/inc/SOIL") 
target_link_libraries(${PROJECT_NAME} glfw)

#add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/tests")

# SOIL
include_directories(${soil_lib})
set(SOIL_LIBRARY ${LIBS_DIR}/SOIL/libsoil.a)
target_link_libraries(${PROJECT_NAME} ${SOIL_LIBRARY})

# glad
set(GLAD_DIR "${LIBS_DIR}/glad")
add_library("GLAD" "${GLAD_DIR}/src/glad.c")
target_include_directories("GLAD" PRIVATE "${GLAD_DIR}/include")
target_include_directories(${PROJECT_NAME} PRIVATE "${GLAD_DIR}/include")
target_link_libraries(${PROJECT_NAME} "GLAD" ${CMAKE_DL_LIBS})
