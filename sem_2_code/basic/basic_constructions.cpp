#include "basic_constructions.h"

#include <iostream>

void first::Hello1() {
    std::cout << "Hello from 1\n";
}

namespace second {
    void Hello2() {

        std::cout << "Hello from 2\n";
    }

    void third::Hello2() {
        std::cout << "Hello from 3\n";
    }
}


namespace basic {
    bool DemonstrateConditions(int a) {
        std::cout << "====1====\n";
        if (a == 2 || a == 3) {
            std::cout << "2 or 3\n";
        } else if (a == 4) {
            std::cout << "4\n";
        } else {
            std::cout << "other\n";
        }

        return a == 1;
    }

    int DemonstrateConditions(int a, int b) {
        std::cout << "====2====\n";

        switch (a + b) {
            case 6:
                std::cout << "6\n";
                break;
            case 7:
                std::cout << "7\n";
                [[fallthrough]];
            case 8:
                std::cout << "8\n";
                break;
            default:
                std::cout << "other\n";
        }

        return a + b;
    }

    int DemonstrateConditions(int a, int b, int c, int d) {
        std::cout << "====3====\n";

        return a > b ? c : d;
    }


    void DemonstrateLoops(int a) {
        std::cout << "====4====\n";

        for (int i = 0; i < a; ++i) {
            std::cout << "i = " << i << "\n";
        }
        std::cout << "====\n";

        for (int i = 0; i < a; ++i) {
            if (i % 3 == 0) {
                continue;
            }
            if (i % 5 == 0) {
                break;
            }
            std::cout << "i = " << i << "\n";
        }
        std::cout << "====\n";

        {
            int i = 10;
            while (i > a) {
                std::cout << "i = " << i << "\n";
                --i;
            }
        }
        std::cout << "====\n";

        {
            int i = 10;
            do {
                std::cout << "i = " << i << "\n";
                --i;
            } while (i > a);
        }
       
    }
}