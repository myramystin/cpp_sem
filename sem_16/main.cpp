#include <iostream>

struct TTT {
    ~TTT() {
        std::cout << "destruct t";
    }

    int t = 100;
};


void foo(TTT&& x) {
    // Внутри функции x — это lvalue
    // (у x есть имя, можно взять адрес)

    // rvalue-ссылка — ссылка на временный объект
    // int* p = &x; // работает

    // std::cout << p << "\n";

    std::cout << "in foo\n";
}

// Хотим написать обёртку, которая передаёт аргументы "как есть"
void process(int& x)  { std::cout << "lvalue\n"; }
void process(int&& x) { std::cout << "rvalue\n"; }

// Плохой вариант — теряем rvalue-ность
template<typename T>
void bad_wrapper(T x) {  // x всегда lvalue внутри!
    process(x); // всегда вызовет process(int&)
}

// T&& в шаблоне — это НЕ rvalue-ссылка, а универсальная ссылка!
template<typename T>
void wrapper(T&& x) {
    // T&& здесь = "дай мне что угодно"
    process(std::forward<T>(x)); // передаём "как есть"
}

void show_p_forwarding() {

    int n = 5;
    bad_wrapper(n);   // "lvalue" 
    bad_wrapper(42);  // "lvalue" ожидали "rvalue"!

    int n1 = 5;
    wrapper(n1);   // T = int&,  x = int&  → "lvalue" 
    wrapper(42);  // T = int&&, x = int&& → "rvalue" 

    // std::forward работает так:
    // - если T = lvalue-ссылка → возвращает lvalue
    // - если T = rvalue-ссылка → возвращает rvalue (как move)
}

struct Heavy {
    int data[1000];
    Heavy() { std::cout << "Constructed\n"; }
    Heavy(const Heavy&) { std::cout << "Copied\n"; }
    Heavy(Heavy&&) { std::cout << "Moved\n"; }
};

// PRVO (Pure RVO / copy elision) — гарантировано с C++17
Heavy create() {
    return Heavy{}; // Объект создаётся СРАЗУ в месте назначения
}

// NRVO (Named RVO) — оптимизация, не гарантирована, но почти всегда
Heavy createNamed() {
    Heavy result;     // "Constructed"
    result.data[0] = 42;
    return result;    // компилятор строит result прямо в h
}


// NRVO работает не всегда
Heavy bad1(bool flag) {
    Heavy a, b;
    // return std::move(flag ? a : b); //  два кандидата — компилятор не знает какой

    if (flag) {
        return a;
    }

    return b;
}

Heavy bad2(bool flag) {
    Heavy result;
    if (flag) return result;   //  несколько точек возврата
    result.data[0] = 1;
    return result;
}

#include <string>

std::string f_s(std::string q) {
    q += "AAAA";
    return q;
}

// std::string x = "aaaaaaa";
// std::string y = f_s(x); <-----




void show_nrvo() {
    Heavy h = create();

    Heavy h1 = createNamed();
    // Обычно: только "Constructed"
    // Без NRVO: "Constructed" + "Moved"

    std::cout << "---\n";
    Heavy h2 = bad1(true);
    std::cout << "---\n";

    Heavy h3 = bad2(true);

}


int main() {

    // foo(42); // 42 — rvalue, можно передать
    int n = 5;
    // foo(n);  //  ошибка n — lvalue


    // std::move — это просто КАСТ к rvalue-ссылке
    // Никакого перемещения он сам по себе не делает!
    // TTT t;
    // std::cout << t.t << " | ";

    // TTT t1 = std::move(t);

    // std::cout << t.t << " | " << t1.t << "\n---\n";


    // foo(std::move(t));

    // теперь n недоступен


    show_p_forwarding();
    show_nrvo();

    // std::cout << "here\n";

    
    return 0;
}