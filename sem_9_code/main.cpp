#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> 

template <typename T>
void printvec(const std::vector<T>& vec) {
    for (const auto& i : vec) {
        std::cout << i << " ";
    }

    std::cout << "\n";
}


void find() {
    std::vector<int> v1 = {-5, 3, -2, 8, 0, -1, 4};

    for (const auto i: v1) {
        std::cout << i << " ";
    }

    std::cout << "\n---\n";


    auto it1 = std::find_if(v1.begin(), v1.end(), [](const auto& i) { return i == -5;});
    if (it1 != v1.end()) {
        std::cout << "found " << *it1 << "\n";
    } else {
        std::cout << "Not found -5\n";
    }

    auto it2 = std::find_if(v1.begin(), v1.end(), [](const auto& i) { return i == -4;});
    if (it2 != v1.end()) {
        std::cout << "found " << *it2 << "\n";
    } else {
        std::cout << "Not found -4\n";
    }

    *it1 = -4;

    auto it3 = std::find_if(v1.begin(), v1.end(), [](const auto& i) { return i == -4;});


    if (it3 != v1.end()) {
        std::cout << "found " << *it3 << "\n";
    } else {
        std::cout << "Not found -4\n";
    }

    printvec(v1);
}

void count() {
    std::vector<int> v2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int count = std::count_if(v2.begin(), v2.end(), 
                          [](int x) { return x % 2 == 0; });
    std::cout << "Even: " << count << "\n";
}

void sort() {
    std::vector<int> v1 = {-5, 3, -2, 8, 0, -1, 4};
    std::vector<int> v2 = v1;

    std::sort(v1.begin(), v1.end());
    printvec(v1);

    std::sort(v2.begin(), v2.begin() + 3);
    printvec(v2);

    std::sort(v2.begin(), v2.end(), [](const int lhs, const int rhs) {
        return lhs > rhs;
    });

    printvec(v2);

    std::sort(v2.begin(), v2.end(), [](const auto lhs, const auto rhs) {
        return lhs < rhs;
    });

    printvec(v2);
}

void copy_rm() {
    std::vector<int> v1 = {-5, 3, -2, 8, 0, -1, 4};

    auto bIt = std::back_inserter(v1);

    // std::cout << (bIt == v1.end() ? "end" : "not");

    // condition ? if true : if false;
    
    /*
    
    uint x;
    if x > 0 return x;
    else return 10;

    if (x) <=> x > 0

    return x ?: 10;
    
    */


    *bIt = 42;

    printvec(v1);

    *bIt = 43;
    printvec(v1);

    std::vector<int> v2;

    // std::copy_if(v1.begin(), v1.end(), v2.begin(), [](const auto& x) {
    //     return x > 0;
    // });

    std::copy_if(v1.begin(), v1.end(), std::back_inserter(v2), [](const auto& x) {
        return x > 0;
    });

    // std::copy_if(v1.begin(), v1.end(), std::back_inserter(v2), [](const auto& x) {
    //     return x > 0;
    // });

    std::cout << "Copied ";
    printvec(v2);
    std::vector<int> v3 = v2;

    std::cout << "Try Remove ";
    std::remove_if(v2.begin(), v2.end(), [](const auto& x) {
        return x % 4 != 0;
    });

    printvec(v2);

    auto it = std::remove_if(v3.begin(), v3.end(), [](const auto& x) {
        return x % 4 != 0;
    });

    std::cout << *it << "\n";

    std::cout << v3.size() << "\n";

    v3.erase(it, v3.end());
    printvec(v3);



}

void accumulate() {
    std::vector<int> v2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sum = std::accumulate(v2.begin(), v2.end(), 0);
    std::cout << "Sum: " << sum << "\n";

    sum = std::accumulate(v2.begin(), v2.end(), 5);
    std::cout << "Sum with 5: " << sum << "\n";

    sum = std::accumulate(v2.begin(), v2.end(), 0, [](const auto a, const auto b) {
        return (a + b) * 2;
    });
    std::cout << "Sum*: " << sum << "\n";

}

void transform() {
    std::vector<int> v2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> v3;
    int pow = 2;
    std::transform(v2.begin(), v2.end(), std::back_inserter(v3), [&pow](auto x) {
        return std::pow(x, pow);
    });

    printvec(v2);
    printvec(v3);
}

int main() {

    // find();

    // std::cout << "\n---\n";

    // count();

    // std::cout << "\n---\n";

    // sort();

    std::cout << "\n---\n";

    copy_rm();

    std::cout << "\n---\n";

    accumulate();

    std::cout << "\n---\n";

    transform();



    return 0;
}