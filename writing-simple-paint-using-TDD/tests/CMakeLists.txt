cmake_minimum_required(VERSION 3.11)

project(SimplePaint_UnitTests)
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

    "${CMAKE_CURRENT_SOURCE_DIR}/../src/renderwindow.cpp"
    )

target_include_directories(SimplePaint
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/../src"
        "${GLM_INCLUDE_DIRS}")

target_compile_features(SimplePaint PUBLIC cxx_std_17)

add_dependencies(SimplePaint GLM)

########################################################################################################################
# Unit tests executable.
########################################################################################################################

add_executable(${PROJECT_NAME}

    "${CMAKE_CURRENT_SOURCE_DIR}/first_test.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp"
    )

target_include_directories(${PROJECT_NAME} PRIVATE ${Catch2_INCLUDE_DIR})

target_link_libraries(${PROJECT_NAME} SimplePaint)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD COMMAND "$<TARGET_FILE:${PROJECT_NAME}>")

add_dependencies(${PROJECT_NAME} Catch2)
