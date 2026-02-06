#include <iostream>
#include <string>
#include <unordered_map>

namespace destructor
{

class MyClass {
public:
    MyClass() {
        std::cout << "class is created\n";
    }

    ~MyClass() {
        std::cout << "class is deleted\n";
    }

    void F() const {
        std::cout << "call method\n";
    }
};


void f1() {
    MyClass a;
    a.F();
    return; // call destructor
}


void f2(const MyClass& a) {
    a.F();
    return;
}

void show_destructors() {
    std::cout << "1\n";
    {
        std::cout << "2\n";
        f1();
        std::cout << "3\n";
    }
    std::cout << "4\n";

    {
        std::cout << "5\n";
        f2(MyClass());
        // destructor 
        std::cout << "6\n";
    }
    std::cout << "7\n";

    {
        std::cout << "8\n";
        MyClass a;
        std::cout << "9\n";
        a.F();
        std::cout << "10\n";
        // call destructor 
    }
    std::cout << "11\n";
}

}

namespace n {

static int A = 10; // видна только в этом файле
constexpr int B = 100; // compile-time
static constexpr int C = 1000; // both

class Counter {
public:
    Counter() {
        ++instances_count;
        ++other_count;
        std::cout << "created class, instance count " << instances_count << " " << other_count << "\n";
    }

    ~Counter() {
        --instances_count;
        --other_count;
        std::cout << "del class, instance count " << instances_count << " " << other_count << "\n";
    }

    static int instances_count;
    int other_count = 0;
};

int Counter::instances_count = 0;

int simple_square(int x) {
    return x * x;
}

constexpr int constexpr_square(int x) {

    return x * x;
}

void counter() {
    static int count = 0;
    ++count;

    std::cout << count << " ";

    // ~int
}


void demo() {
    // {
    //     Counter count1;
    //     std::cout << "1: " << count1.instances_count << ", " << count1.other_count << "\n";
    //     Counter count2;
    //     std::cout << "2: " << count2.instances_count << ", " << count2.other_count << "\n";

    //     static int k = 0;

    //     for (int i = 0; i < 5; ++i) {
    //         ++k;
            
    //         std::cout << k << " ";
    //     }
    // }

    // {
    //     counter();
    //     counter();
    //     counter();
    //     std::cout << "\n----\n";
    // }

    // {
    //     // int x = 10;

    //     // const int z = 100;

    //     // constexpr int y = z;

    //     // for (int i = 0; i < z; ++i) {}

    //     // std::cout << x << " " << y << " " << z << "\n";


    //     int sq1 = simple_square(5);
    //     constexpr int sq2 = constexpr_square(5);
    //     // int arr1[sq1]; // error
    //     int arr2[sq2];
    //     std::cout << sq1 << " " << sq2 << "\n";
    // }

    {
        // {
        //     int x = 10;

        //     int sq1 = simple_square(x);
        //     constexpr int sq5 = constexpr_square(5);

        //     constexpr int sq2 = constexpr_square(x); //  -- error
        //     constexpr int sq3 = simple_square(5); //  -- error
        //     int sq4 = constexpr_square(x);
        // }

        {
            constexpr int y = 20;
            int sq1 = simple_square(y);
            constexpr int sq2 = constexpr_square(y);
            // constexpr int sq3 = simple_square(y); // -- error
            int sq4 = constexpr_square(y);
        }
    }


}

}


int main() {
    // destructor::show_destructors();

    n::demo();
    

    return 0;    
}
