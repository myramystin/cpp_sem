#include "basic_constructions.h"


#include <iostream>


int main() {
    first::Hello1();
    second::Hello2();
    second::third::Hello2();


    std::cout << basic::DemonstrateConditions(4) << "\n";

    std::cout << basic::DemonstrateConditions(4, 2)  << "\n";
    std::cout << basic::DemonstrateConditions(4, 3)  << "\n";
     std::cout << basic::DemonstrateConditions(4, 4)  << "\n";
     std::cout << basic::DemonstrateConditions(4, 0) << "\n";

    std::cout << basic::DemonstrateConditions(4, 2, 4) << "\n";
    std::cout << basic::DemonstrateConditions(2, 4, 4) << "\n";
    std::cout << basic::DemonstrateConditions(2, 4, 4, -1) << "\n";

    basic::DemonstrateLoops(5);



    return 0;
}