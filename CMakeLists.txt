cmake_minimum_required(VERSION 3.20)

project(pss VERSION 0.1)

add_executable(pss
    "source/main.c"
    "source/log.c"
    "source/interface.c"
    "source/hash.c"
    "source/command.c"
) 

target_include_directories(pss 
    PUBLIC "include"
    PUBLIC "library/komihash"
)
