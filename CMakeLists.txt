cmake_minimum_required(VERSION 3.20)

project(Notes VERSION 0.1)
add_executable(Notes
    source/main.c
    source/error.c
) 
target_include_directories(Notes 
    PUBLIC include
    PUBLIC library/highwayhash
)
target_link_libraries(Notes
    ${CMAKE_CURRENT_SOURCE_DIR}/library/highwayhash/lib/libhighwayhash.a
)
