cmake_minimum_required(VERSION 2.6)
project(BoidsSDL)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

#Note for Windows: find_package doesn't work well as we don't have lib directories, set an environment variable called SDL2 that has the path to your SDL directory.

set(PROJECT_INCLUDE_ROOT "${PROJECT_SOURCE_DIR}/include")
set(PROJECT_SOURCE_ROOT "${PROJECT_SOURCE_DIR}/source")
set(PROJECT_SHADER_ROOT "${PROJECT_SOURCE_DIR}/shaders")
set(PROJECT_ASSET_ROOT "${PROJECT_SOURCE_DIR}/assets")
set(PROJECT_GENERATED_ROOT "${PROJECT_SOURCE_DIR}/generated")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")
set(BIN_DIR ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

find_package(GLM REQUIRED)
find_package(OpenGL REQUIRED)
find_package(SDL2 REQUIRED)
find_package(GLEW REQUIRED)

include_directories(${GLM_INCLUDE_DIRS})
include_directories(${OPENGL_INCLUDE_DIRS})
include_directories(${SDL2_INCLUDE_DIR})
include_directories(${GLEW_INCLUDE_DIRS})

include_directories(${PROJECT_INCLUDE_ROOT} ${PROJECT_GENERATED_ROOT} ${PROJECT_ASSET_ROOT})
add_subdirectory(${PROJECT_INCLUDE_ROOT})
add_subdirectory(${PROJECT_SOURCE_ROOT})
add_subdirectory(${PROJECT_SHADER_ROOT})
add_subdirectory(${PROJECT_ASSET_ROOT})

#Tells IDEs where to put each file
source_group("include" FILES ${INCLUDE_LIST})
source_group("source" FILES ${SOURCE_LIST})
source_group("shaders" FILES ${SHADER_LIST})
source_group("assets" FILES ${ASSET_LIST})

#This makes the executable and links the libraries
add_executable(BoidsSDL ${SOURCE_LIST} ${INCLUDE_LIST} ${SHADER_LIST})
target_link_libraries(BoidsSDL ${OPENGL_LIBRARY})
target_link_libraries(BoidsSDL ${SDL2_LIBRARY})
target_link_libraries(BoidsSDL ${GLEW_LIBRARY})