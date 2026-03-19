#include <iostream>
#include <string>
#include <vector>

#include <expected>
#include <variant> 

// перегруженные функции
struct Printer {
    void operator()(int i)                { std::cout << "int: " << i; }
    void operator()(double d)             { std::cout << "double: " << d; }
    void operator()(const std::string& s) { std::cout << "string: " << s; }
};

// overloaded trick

/*
лямбда — это уникальный анонимный struct с operator()

auto f = [](int i) { std::cout << i; };

// Компилятор превращает это примерно в:
struct __lambda_42 {
    void operator()(int i) const {
        std::cout << i;
    }
};

auto f = __lambda_42{};

// Можем ли мы унаследоваться от лямбды?
auto lam = [](int i) { std::cout << i; };

struct MyStruct : decltype(lam) {
    // наследуем operator()(int)
};

Значит можно унаследоваться от нескольких лямбд сразу

Проблема — неоднозначность имён

Поиск имён в C++ работает так:

1. Ищем имя в самом классе
2. Ищем в базовых классах — в КАЖДОМ отдельно
3. Если нашли в НЕСКОЛЬКИХ базах — ошибка ambiguous
   (даже если сигнатуры разные!)

cpp
struct Combined : decltype(l1), decltype(l2) {
    // Два operator() из разных базовых классов
    // Компилятор видит 2 разных имени в разных областях видимости
    // При вызове Combined{}(42) — ambiguous
};

НО using затягивает имена в один scope
struct C : A, B {
    using A::foo; // \
    using B::foo; //  > оба foo теперь в одном scope — C
};

C c;
c.A::foo(42);    // выбирает A::foo(int)
c.B::foo(3.14);  // выбирает B::foo(double)


*/
template<typename... Ts> // Шаблон с вариативными параметрами
struct overloaded : Ts... { // наследуемся от ВСЕХ переданных типов
    using Ts::operator()...;
    //    ^^^^^^^^^^^^^^^^^^^
    //    pack expansion — раскрывается в:
    //    using T1::operator();
    //    using T2::operator();
    //    using T3::operator();
};


void show_var() {
    std::variant<std::string, int, std::vector<int>> v;
    std::visit(overloaded{
        [](int i)                { std::cout << "int: " << i; },
        [](double d)             { std::cout << "double: " << d; },
        [](const std::string& s) { std::cout << "string: " << s; },
    }, v);

    v = 1;
    v = "aaa";

    // лямбда с auto
    std::visit([](const auto& val) {
        std::cout << val << '\n';
    }, v);

    std::cout << "---\n";

    std::visit(Printer{}, v);

    std::cout << "\n---\n";

    
}

std::optional<int> f_opt(int q) {
    if (q % 2 == 0) {
        return q;
    }

    return std::nullopt;
}

std::expected<int, std::string> f_exp(int q) {
    if (q % 2 == 0) {
        return q;
    }

    return std::unexpected("bad val some text");
}



void show_opt() {
    auto op_1 = f_opt(1);
    auto op_2 = f_opt(2);

    if (op_1.has_value()) {
        std::cout << "1 val\n";
    } else {
        std::cout << "1 no val\n";
    }

    if (op_2.has_value()) {
        std::cout << "2 val\n";
    } else {
        std::cout << "2 no val\n";
    }

    std::cout << op_1.value_or(1991919191) << "\n";
    std::cout << op_2.value_or(1991919191) << "\n";

    auto exp_1 = f_exp(1);
    auto exp_2 = f_exp(2);

    if (exp_1) {
        std::cout << *exp_1 << "\n";
    } else {
        std::cout << exp_1.error() << "\n";
    }

    if (exp_2) {
        std::cout << *exp_2 << "\n";
    } else {
        std::cout << exp_2.error() << "\n";
    }


}

int main() {
    // show_opt();
    show_var();
    
    

    return 0;
}

