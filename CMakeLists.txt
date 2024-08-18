cmake_minimum_required(VERSION 3.10)
project(MemoryThreadUBProject)

set(CMAKE_CXX_STANDARD 11)

# Option to build with AddressSanitizer
option(ENABLE_ASAN "Enable AddressSanitizer" OFF)

# Option to build with UndefinedBehaviorSanitizer
option(ENABLE_UBSAN "Enable UndefinedBehaviorSanitizer" OFF)

# Option to build with ThreadSanitizer
option(ENABLE_TSAN "Enable ThreadSanitizer" OFF)

# Option to build with MemorySanitizer
option(ENABLE_MSAN "Enable MemorySanitizer" OFF)

# Option to build with LeakSanitizer
option(ENABLE_LSAN "Enable LeakSanitizer" OFF)

add_executable(MemoryThreadUBProject main.cpp)

if(ENABLE_ASAN)
    message(STATUS "AddressSanitizer enabled")
    target_compile_options(MemoryThreadUBProject PRIVATE -fsanitize=address -g)
    target_link_options(MemoryThreadUBProject PRIVATE -fsanitize=address)
endif()

if(ENABLE_UBSAN)
    message(STATUS "UndefinedBehaviorSanitizer enabled")
    target_compile_options(MemoryThreadUBProject PRIVATE -fsanitize=undefined -g)
    target_link_options(MemoryThreadUBProject PRIVATE -fsanitize=undefined)
endif()

if(ENABLE_TSAN)
    message(STATUS "ThreadSanitizer enabled")
    target_compile_options(MemoryThreadUBProject PRIVATE -fsanitize=thread -g)
    target_link_options(MemoryThreadUBProject PRIVATE -fsanitize=thread)
endif()

if(ENABLE_MSAN)
    message(STATUS "ThreadSanitizer enabled")
    target_compile_options(MemoryThreadUBProject PRIVATE -fsanitize=memory -g)
    target_link_options(MemoryThreadUBProject PRIVATE -fsanitize=memory)
endif()

if(ENABLE_LSAN)
    message(STATUS "ThreadSanitizer enabled")
    target_compile_options(MemoryThreadUBProject PRIVATE -fsanitize=leak -g)
    target_link_options(MemoryThreadUBProject PRIVATE -fsanitize=leak)
endif()

# Option to suggest using Valgrind
option(USE_VALGRIND "Suggest using Valgrind" OFF)

if(USE_VALGRIND)
    message(STATUS "Consider running the program with Valgrind: valgrind ./your_program")
endif()

