#include <iostream>

namespace functions {

    int calculate(int x, int y, std::function<int(int, int)> op) {
        return op(x, y);
    }

    int add(int x, int y) {
        return x + y;
    }

}


// int& t (int& p) {   // INVALID

//     int p = 10;
//     int& result = p;

    
//     return result;
// }



void B();

void A() {
    B();
}

void B() {
    A();
}


int main() {

    // [capture](parameters) -> return_type { body }

    auto f1 = []() {
        std::cout << "f1\n";
    };

    f1();

    int x;
    int y = 5;

    x = 10;

    
    auto f2 = [=]() {
        std::cout << "f2 " << x << " " << y << "\n";
        // x = 15; 
    };

    x++;

    f2();

    auto f3 = [&]() {
        std::cout << "f3 " << x << " " << y  <<"\n";
        x = 15; 
    };

    auto f4 = [x, &y]() {
        std::cout << "f3 " << x << " " << y<< "\n";
        // x = 15; 
        y = 10;
    };


    // std::unordered_set<int> key;

    // std::vector<int> vals;
    // std::sort(vals.begin(), vals.end(), );

    // auto do_sth = [&key](int val) {
    //     if (key.contains(val)) {
    //         ....
    //     } else {
    //         ....
    //     }
    // }
    // for (auto i: vals) {
    //     do_sth(i);
    // }

    f3();
    f4();

    {
        int z = 10;

        auto lambda = [z]() mutable {
            z++;
            std::cout << z << "\n";
        };

        lambda();
        lambda();
        std::cout << z << "\n";
    }


    {
        auto printer = [](auto x) {
            std::cout << "\nX is " << x;
        };

        int arr1[5] = {1, 2, 3, 4, 5};
        for (int i : arr1) {
            printer(i);
        }
    }


    {
        int a = 10;
        int b = 15;
        std::cout << "\nAdding a to b " << functions::calculate(a, b, functions::add) << "\n";
        std::cout << "mul a to b " << functions::calculate(a, b, [](int x, int y) {
            return x * y;
        }) << "\n";
    }

    // std::cout << a;

}