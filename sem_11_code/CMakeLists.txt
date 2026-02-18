add_library(lib
    vechicle.cpp
    vechicle.h

    vechicle_visitor.cpp
    vechicle_visitor.h

    car.cpp
    car.h

    truck.cpp
    truck.h

    dumptruck.cpp
    dumptruck.h

    inspection.cpp
    inspection.h

    park.cpp
    park.h

    factory.cpp
    factory.h
)

add_executable(patterns main.cpp)
target_link_libraries(patterns PRIVATE lib)


