cmake_minimum_required(VERSION 3.25)
project(voxel-game VERSION 0.0.6)

option(ENABLE_ADDRSAN "Enable the address sanitizer" OFF)
option(ENABLE_UBSAN "Enable the ub sanitizer" OFF)
option(ENABLE_TSAN "Enable the thread data race sanitizer" OFF)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(lib/blt-with-graphics)

add_compile_definitions(VOXEL_RES_DIR="${CMAKE_CURRENT_SOURCE_DIR}/res")

include_directories(include/)
file(GLOB_RECURSE PROJECT_BUILD_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_executable(voxel-game ${PROJECT_BUILD_FILES})

target_compile_options(voxel-game PRIVATE -Wall -Wextra -Wpedantic -Wno-comment)
target_link_options(voxel-game PRIVATE -Wall -Wextra -Wpedantic -Wno-comment)

target_link_libraries(voxel-game PRIVATE BLT_WITH_GRAPHICS)

if (${ENABLE_ADDRSAN} MATCHES ON)
    target_compile_options(voxel-game PRIVATE -fsanitize=address)
    target_link_options(voxel-game PRIVATE -fsanitize=address)
endif ()

if (${ENABLE_UBSAN} MATCHES ON)
    target_compile_options(voxel-game PRIVATE -fsanitize=undefined)
    target_link_options(voxel-game PRIVATE -fsanitize=undefined)
endif ()

if (${ENABLE_TSAN} MATCHES ON)
    target_compile_options(voxel-game PRIVATE -fsanitize=thread)
    target_link_options(voxel-game PRIVATE -fsanitize=thread)
endif ()
