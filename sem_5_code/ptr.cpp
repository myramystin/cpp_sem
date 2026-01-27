#include <iostream>

namespace {

//     void printArray1(int arr[10]) {  // На самом деле это int* arr
//     // sizeof(arr) вернет размер указателя (8 байт), а не массива!
//     int size = sizeof(arr) / sizeof(arr[0]);  // Не работает!
// }

void printArray2(int* arr, int size);

void printArray3(const int (&arr)[10]);

}


void f() {
    int x = 42;
    int* ptr = &x;

    std::cout << "Значение x: " << x << std::endl;
    std::cout << "Адрес x: " << &x << std::endl;
    std::cout << "Значение ptr: " << ptr << std::endl;
    std::cout << "Адрес ptr: " << &ptr << std::endl;
    std::cout << "Значение по ptr: " << *ptr << std::endl;

}

#include <cstdint>

int main() {

    int32_t a = -2;

    std::cout << (int32_t)(~a + 1) << "\n";

    // for (int i = 31; i >= 0; --i) {
    //     if (a & (1 << i)) {
    //         std::cout << "1";
    //     } else {
    //         std::cout << "0";
    //     }
    // }
    std::cout << "\n";

//     {
//         int x = 42;
//         int* ptr = &x;

//         // int& x1 = x;

//         // std::cout << "x1 " << x1 << " " << &x << " " << &x1 << " ";

//         std::cout << "Значение x: " << x << std::endl;
//         std::cout << "Адрес x: " << &x << std::endl;
//         std::cout << "Значение ptr: " << ptr << std::endl;
//         std::cout << "Адрес ptr: " << &ptr << std::endl;
//         std::cout << "Значение по ptr: " << *ptr << std::endl;

//         f();
//     }

//     {
//         int value = 42;
//         int other = 100;

//         const int third = 100;

//         const int* ptr0 = &third;

//         // *ptr0 = 50;

//         const int* ptr1 = &value;
//         // *ptr1 = 50; // -> error
//         ptr1 = &other;

//         int* const ptr2 = &value;
//         *ptr2 = 50;
//         // ptr1 = &other // -> error

//         const int* const ptr3 = &value;
//     }

//     {
//         int arr[5] = {10, 20, 30, 40, 50};

//         std::cout << arr[0] << std::endl;
//         std::cout << *arr << std::endl;
//         std::cout << *(arr + 0) << std::endl;

//         std::cout << arr[2] << std::endl;
//         std::cout << *(arr + 2) << std::endl;

//         // Даже так работает (но не делайте так!)
//         std::cout << 2[arr] << std::endl;

//     }

//     {
//         int matrix[3][4] = {
//     {1, 2, 3, 4},
//     {5, 6, 7, 8},
//     {9, 10, 11, 12}
// };

// // Что выведет?
// std::cout << matrix << std::endl; 
// std::cout << *matrix << std::endl; 
// std::cout << **matrix << std::endl;
// std::cout << *(*(matrix + 1) + 2) << std::endl;

//     }

//     {

//         int* ptr = new int(100);

//         // Память:
//         // СТЕК:
//         // p: [адрес]
//         //
//         // КУЧА:
//         // адрес: [100]

//         *p = 200;  // Меняем значение в куче
//         std::cout << p << std::endl;   // (адрес)
//         std::cout << *p << std::endl;  // 200 (значение)

//         delete p;

//         int* arr = new int[10];
//         delete[] arr;
//     }

    return 0;

}