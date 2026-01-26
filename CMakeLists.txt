cmake_minimum_required(VERSION 3.15)
project(Seminar2 VERSION 1.0.0 LANGUAGES CXX)

# Настройки компилятора
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(ENABLE_UBSAN "Enable UndefinedBehaviorSanitizer" OFF)
option(ENABLE_MSAN "Enable MemorySanitizer" OFF)


# Флаги компиляции
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(
        -Wall
        -Wextra
    )
endif()


if(ENABLE_UBSAN)
    message("ubsan")
    add_compile_options(-fsanitize=undefined -fno-sanitize-recover=all)
    add_link_options(-fsanitize=undefined)
endif()

# Подключение поддиректорий
add_subdirectory(sem_2_code/basic)
add_subdirectory(sem_2_code/ub)
add_subdirectory(sem_3_code)
add_subdirectory(sem_4_code)

