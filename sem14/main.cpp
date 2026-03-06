#include <vector>
#include <iostream>
#include <concepts>


template<typename Container>
void print_first(const Container& c) {
    // Без typename компилятор думает, что value_type - это переменная
    typename Container::value_type first = c[0];
    std::cout << first << "\n";
}

template<typename T>
T divide(T a, T b) {
    return a / b;
}

template<typename T>
T divide1(T a, T b) {
    return a / b;
}

template<>
double divide1(double a, double b) {
    std::cout << "we are in safe divide\n";
    return a / b;
}


// SFINAE + type_traits
template<typename T>
std::enable_if_t<std::is_arithmetic_v<T>, T>
divide2(T a, T b) {
    return a / b;
}

// CONCEPTS

template<typename T>
requires std::integral<T>
T factorial(T n) {
    return (n <= 1) ? 1 : n * factorial(n - 1);
}

auto factorial1(std::integral auto n) {
    return (n <= 1) ? 1 : n * factorial(n - 1);
}

template<typename T>
concept Addable = requires(T a) {
    a + a;

    { a + a } -> std::convertible_to<T>;
    std::convertible_to<decltype(a + a), T>;

    // T::value_type;
    // T::Func(T x) -> T;
};

// template<typename T, typename V>
// concept Addable = requires {
//     std::convertible_to<V>(a);
// };

template<typename T>
requires (bool(Addable<T> ^ std::integral<T>))
T sum(T a, T b) {
    return a + b;
}




int main() {
    // std::vector<int> vec = {1, 2, 3};
    // print_first(vec);

    // std::cout << divide(1, 2) << "\n";
    // std::cout << divide(1.0, 2.0) << "\n";
    // // std::cout << divide("a", "b") << "\n";

    // std::cout << divide1(1, 2) << "\n";
    // std::cout << divide1(1.0, 2.0) << "\n";

    // std::cout << divide2(1, 2) << "\n";
    // std::cout << divide2(1.0, 2.0) << "\n";
    // std::cout << divide2("a", "b") << "\n";


    // std::cout << factorial(3) << "\n";
    // std::cout << factorial1(5) << "\n";

    // std::cout << sum(1.4, 1.0) << "\n";

    return 0;
}
