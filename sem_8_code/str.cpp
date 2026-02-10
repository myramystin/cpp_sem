#include <iostream>
#include <string>
#include <vector>

void show_string_info(const std::string& s) {
    std::cout << "String: \"" << s << "\"\n";
    std::cout << "Size: " << s.size() << "\n";
    std::cout << "Capacity: " << s.capacity() << "\n";
    std::cout << "Data pointer: " << (void*)s.data() << "\n";
    std::cout << "Object address: " << (void*)&s << "\n";
    
    bool is_sso = (void*)s.data() >= (void*)&s && 
                  (void*)s.data() < (void*)(&s + 1);
    std::cout << "SSO active: " << (is_sso ? "YES" : "NO") << "\n\n";
}

void print_substring_basic(const std::string& s, size_t start, size_t len) {
    const std::string& sub = s.substr(start, len);
    std::cout << sub << "\n";
}

void print_substring_sv(std::string_view s, size_t start, size_t len) {
    std::string_view sub = s.substr(start, len);
    std::cout << sub << "\n";
}


void f(const std::vector<int>& x) {
    std::cout << x[0];
    std::cout << x.at(0);
}

int main() {
    // {

    //     std::string short_str = "hello";           // 5
    //     show_string_info(short_str);
        
    //     std::string medium_str = "hello world!";   // 12
    //     show_string_info(medium_str);
        
    //     std::string long_str = "this is a very long string that won't fit in SSO"; // >23
    //     show_string_info(long_str);

    // }

    // {

    //     std::string s = "AAABBB";
    //     std::string_view sv = s;  
    //     std::string_view sv2 = "literal"; 
    //     std::string_view sv3(s.data(), 3);  
        
    //     std::cout << sv << "\n"; 
    //     std::cout << sv.size() << "\n"; 
    //     std::cout << sv[0] << "\n";         
    //     std::cout << sv.front() << "\n";     
    //     std::cout << sv.back() << "\n";     

    // }

    // std::string a = "aaaa";
    // std::string_view a1 = a;
    // a[2] = 'b';
    // std::cout << a << ": " << a1 << " ";
    // a1 = "ssss";
    // std::cout << a << ": " << a1 << " ";


    // {
    //     std::string_view sv;
    //     {        
    //         std::string temp = "hello";
    //         sv = temp;

    //         // ~temp;
    //     }

    //     std::cout << sv << "\n";
    // }


    std::vector<double> V(3);
    V.resize(3);
    V.reserve(10);

    V[0] = 1.;
    V[1] = 1.;

    std::cout << "Idx | Val | Addr\n ---------------------\n" <<
                0 << " | " <<  V[0] << " | " << &V[0] << "\n" << 
                1 << " | " <<  V[1] << " | " << &V[1] << "\n" <<
                2 << " | " <<  V[2] << " | " << &V[2] << "\n"; 


    V[3] = .1;

    std::cout << 3 << " | " <<  V[3] << " | " << &V[3] << "\n"; 

    std::cout << 4 << " | " <<  V[4] << " | " << &V[4] << "\n"; 

    std::cout << "\n ---------------------\n";
    // std::cout << V.at(3) << "\n";

    f({1, 2});

    // std::cout << V[0] << "\n" << V[4] << "\n" << V[50] << "\n" << V[51] << "\n";
}