# Создаем библиотеку из basic_constructions
add_library(basic_constructions
    basic_constructions.cpp
    basic_constructions.h
)

# Указываем директории для include
target_include_directories(basic_constructions
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

# Если есть main файл для демонстрации, можно создать исполняемый файл
add_executable(basic_demo main.cpp)
target_link_libraries(basic_demo PRIVATE basic_constructions)
