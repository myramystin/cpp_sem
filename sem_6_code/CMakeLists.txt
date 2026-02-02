add_library(timers
    timer.cpp
    timer.h
)

add_library(points
    point.cpp
    point.h
)

add_library(vectors
    vector.cpp
    vector.h
    ops.h
    ops.cpp
)



# Указываем директории для include
target_include_directories(timers
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(classes_demo main.cpp)
target_link_libraries(classes_demo PRIVATE timers)
target_link_libraries(classes_demo PRIVATE points)
target_link_libraries(vectors PRIVATE points)
target_link_libraries(classes_demo PRIVATE vectors)
