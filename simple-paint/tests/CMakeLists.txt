cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

project(SimplePaint_UnitTests)
find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)
find_library(COCOA_LIBRARY Cocoa)
find_library(IOKIT_LIBRARY IOKit REQUIRED)
find_library(COREVID_LIBRARY CoreVideo REQUIRED)
# This module will be used for downloading third party code.
include(ExternalProject)

set(THIRDPARTY "${CMAKE_CURRENT_SOURCE_DIR}/../external")

########################################################################################################################
# Catch2 unit testing framework.
########################################################################################################################

ExternalProject_Add(
    Catch2

    GIT_REPOSITORY		"https://github.com/catchorg/Catch2.git"
    GIT_TAG 			"master"

    SOURCE_DIR 			"${THIRDPARTY}/Catch2-master"

    # Don't update and patch.
    UPDATE_COMMAND		""
    PATCH_COMMAND 		""

    # Don't configure and build.
    CONFIGURE_COMMAND 	""
    BUILD_COMMAND     	""

    # Don't test and install.
    TEST_COMMAND		""
    INSTALL_COMMAND		"")


set(Catch2_INCLUDE_DIR "${THIRDPARTY}/Catch2-master/single_include")

########################################################################################################################
# GLM  v.0.9.4.6
#   - the same version that is available through CocoaPods.
########################################################################################################################

ExternalProject_Add(
    GLM

    GIT_REPOSITORY		"https://github.com/g-truc/glm.git"
    GIT_TAG 			"0.9.4.6"

    SOURCE_DIR 			"${THIRDPARTY}/glm-0.9.4.6"

    # Don't update and patch.
    UPDATE_COMMAND		""
    PATCH_COMMAND 		""

    # Don't configure and build.
    CONFIGURE_COMMAND 	""
    BUILD_COMMAND     	""

    # Don't test and install.
    TEST_COMMAND		""
    INSTALL_COMMAND		"")

set(GLM_INCLUDE_DIRS "${THIRDPARTY}/glm-0.9.4.6")

########################################################################################################################
# Static library, built from project source code.
########################################################################################################################

add_library(SimplePaint STATIC

    "${THIRDPARTY}/glad/src/glad.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../src/main.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/../src/window.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/../src/texture.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/../src/shader.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/../src/shaderbuilder.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/../src/graphicsystem.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/../src/system.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/../src/component.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/../src/entity.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/../src/line.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/../src/application.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/../src/brush.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/../src/event.cpp"
    )

target_include_directories(SimplePaint PUBLIC

    "${THIRDPARTY}/SOIL/inc/SOIL"
#    "${THIRDPARTY}/SOIL/src"
    "${THIRDPARTY}/glad/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/../include"
    "${CMAKE_CURRENT_SOURCE_DIR}/../src"
    "${GLM_INCLUDE_DIRS}"
    )

target_compile_features(SimplePaint PUBLIC cxx_std_17)

add_dependencies(SimplePaint GLM)

########################################################################################################################
# Unit tests executable.
########################################################################################################################

add_executable(${PROJECT_NAME}

    "${CMAKE_CURRENT_SOURCE_DIR}/window_test.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/texture_test.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/shader_test.cpp"

    "${CMAKE_CURRENT_SOURCE_DIR}/multibuffer_test.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/graphicsystem_test.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp"
    )

target_include_directories(${PROJECT_NAME} PRIVATE ${Catch2_INCLUDE_DIR})


set(SOIL "${CMAKE_CURRENT_SOURCE_DIR}/../external/SOIL/libsoil.a")
target_link_libraries(${PROJECT_NAME} glfw SimplePaint ${SOIL})
target_link_libraries(${PROJECT_NAME} ${COCOA_LIBRARY} ${OPENGL_LIBRARIES} ${IOKIT_LIBRARY} ${COREVID_LIBRARY})

#add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD COMMAND "$<TARGET_FILE:${PROJECT_NAME}>")

add_dependencies(${PROJECT_NAME} Catch2)
