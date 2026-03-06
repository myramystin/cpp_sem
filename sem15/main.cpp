/*
                    Input Iterator
                         ↓
                    Forward Iterator
                         ↓
                  Bidirectional Iterator
                         ↓
                 Random Access Iterator
                         ↓
                Contiguous Iterator (C++20)
*/

#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <set>
#include <iterator>
#include <sstream>
#include <algorithm>

int main() {
    
    // ========== 1. INPUT ITERATOR ==========
    {
        std::istringstream stream("10 20 30 40 50");
        std::istream_iterator<int> it(stream);
        std::istream_iterator<int> end;
        
        std::cout << "Reading from stream (one-pass, forward-only):\n";
        while (it != end) {
            std::cout << *it << " ";
            ++it;  // можно только вперёд
        }
        std::cout << "\n";
        
        //
        // --it;  // нет декремента
        // it[2]; // нет произвольного доступа
        // int x = *it; ++it; int y = x; // x может быть инвалидирован
    }
    
    // ========== 2. OUTPUT ITERATOR ==========
    {
        std::vector<int> vec = {1, 2, 3, 4, 5};
        
        std::cout << "Writing to stream (write-only):\n";
        std::ostream_iterator<int> out(std::cout, " ");
        
        for (int x : vec) {
            *out = x;  // запись
            ++out;
        }
        std::cout << "\n";
        
        // back_inserter - специальный Output Iterator
        std::vector<int> dest;
        std::cout << "Using back_inserter:\n";
        auto back_it = std::back_inserter(dest);
        for (int x : vec) {
            *back_it = x * 2;  // dest.push_back(x * 2)
            ++back_it;
        }
        
        std::cout << "dest: ";
        for (int x : dest) std::cout << x << " ";
        std::cout << "\n";
        
        // int x = *out; // нет чтения
    }
    
    // ========== 3. FORWARD ITERATOR ==========
    {
        std::forward_list<int> flist = {10, 20, 30, 40, 50};
        
        std::cout << "Forward list (one direction, multi-pass):\n";
        auto it = flist.begin();
        
        // Можем читать многократно
        std::cout << "First element: " << *it << "\n";
        std::cout << "First element again: " << *it << "\n";
        
        // Можем делать копии итераторов
        auto it_copy = it;
        ++it;
        std::cout << "After increment - it: " << *it << ", copy: " << *it_copy << "\n";
        
        // Можем проходить несколько раз
        std::cout << "Full traversal: ";
        for (auto it = flist.begin(); it != flist.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << "\n";
        
        // std::advance работает с Forward Iterator
        it = flist.begin();
        std::advance(it, 2);  // O(n) для Forward Iterator
        std::cout << "After advance(it, 2): " << *it << "\n";
        
        // std::distance работает с Forward Iterator
        auto dist = std::distance(flist.begin(), flist.end());  // O(n)
        std::cout << "Distance from begin to end: " << dist << "\n";
        
        // --it;  // нет декремента
        // it + 5; // нет произвольного доступа
        // flist.rbegin(); // нет обратных итераторов
    }
    
    // ========== 4. BIDIRECTIONAL ITERATOR ==========
    {
        std::list<int> lst = {10, 20, 30, 40, 50};
        
        std::cout << "List (forward and backward):\n";
        auto it = lst.begin();
        ++it; ++it;  // указывает на 30
        
        std::cout << "Current: " << *it << "\n";
        
        // Можем идти назад
        --it;
        std::cout << "After decrement: " << *it << "\n";
        
        ++it; ++it;
        std::cout << "After two increments: " << *it << "\n";
        
        // Обратные итераторы доступны
        std::cout << "Reverse traversal: ";
        for (auto rit = lst.rbegin(); rit != lst.rend(); ++rit) {
            std::cout << *rit << " ";
        }
        std::cout << "\n";
        
        // std::advance работает в обе стороны
        it = lst.begin();
        std::advance(it, 3);   // O(n) вперёд
        std::cout << "After advance(it, 3): " << *it << "\n";
        
        std::advance(it, -2);  // O(n) назад
        std::cout << "After advance(it, -2): " << *it << "\n";
        
        // std::distance
        auto it1 = lst.begin();
        auto it2 = lst.end();
        std::cout << "Distance: " << std::distance(it1, it2) << "\n";  // O(n)
        
        // std::next и std::prev
        auto next_it = std::next(it, 1);
        std::cout << "std::next(it, 1): " << *next_it << "\n";
        
        auto prev_it = std::prev(it, 1);
        std::cout << "std::prev(it, 1): " << *prev_it << "\n";
        
        // Алгоритмы требующие Bidirectional
        std::reverse(lst.begin(), lst.end());
        std::cout << "After reverse: ";
        for (int x : lst) std::cout << x << " ";
        std::cout << "\n";
        
        // it + 5;  // нет произвольного доступа
        // it[2];   // нет индексации
        // std::sort(lst.begin(), lst.end()); // sort требует Random Access
    }
    
    // ========== 5. RANDOM ACCESS ITERATOR ==========
    {
        std::vector<int> vec = {10, 20, 30, 40, 50};
        
        std::cout << "Vector (random access):\n";
        auto it = vec.begin();
        
        // Арифметика указателей
        std::cout << "it[0]: " << it[0] << "\n";
        std::cout << "it[2]: " << it[2] << "\n";
        std::cout << "it[4]: " << it[4] << "\n";
        
        // Прыжки на произвольное расстояние
        auto it2 = it + 3;
        std::cout << "*(it + 3): " << *it2 << "\n";
        
        it2 -= 2;
        std::cout << "After it2 -= 2: " << *it2 << "\n";
        
        // Разность итераторов
        auto it3 = vec.end();
        auto diff = it3 - it;
        std::cout << "end - begin: " << diff << "\n";
        
        // Сравнение по порядку
        if (it < it2) {
            std::cout << "it < it2\n";
        }
        
        if (it2 <= it3) {
            std::cout << "it2 <= it3\n";
        }
        
        // std::advance - O(1) для Random Access!
        it = vec.begin();
        std::advance(it, 2);
        std::cout << "After advance(it, 2): " << *it << "\n";
        
        std::advance(it, -1);
        std::cout << "After advance(it, -1): " << *it << "\n";
        
        // std::distance - O(1) для Random Access!
        auto distance = std::distance(vec.begin(), vec.end());
        std::cout << "Distance (O(1)): " << distance << "\n";
        
        // std::next и std::prev - O(1)
        auto next_it = std::next(it, 2);
        std::cout << "std::next(it, 2): " << *next_it << "\n";
        
        auto prev_it = std::prev(vec.end(), 2);
        std::cout << "std::prev(end, 2): " << *prev_it << "\n";
        
        // Алгоритмы требующие Random Access
        std::sort(vec.begin(), vec.end(), std::greater<int>());
        std::cout << "After sort (descending): ";
        for (int x : vec) std::cout << x << " ";
        std::cout << "\n";
        
        std::nth_element(vec.begin(), vec.begin() + 2, vec.end());
        std::cout << "After nth_element (2nd position): ";
        for (int x : vec) std::cout << x << " ";
        std::cout << "\n";
    }
    
    // ========== 6. CONTIGUOUS ITERATOR (C++20) ==========
    {
        std::vector<int> vec = {10, 20, 30, 40, 50};
        
        std::cout << "Vector (contiguous memory):\n";
        auto it = vec.begin();
        
        // Всё что есть в Random Access + гарантия последовательности в памяти
        std::cout << "Elements via iterator: ";
        for (int i = 0; i < 5; ++i) {
            std::cout << it[i] << " ";
        }
        std::cout << "\n";
        
        // Можем получить прямой указатель на память
        int* ptr = &(*it);  // или vec.data()
        std::cout << "Elements via raw pointer: ";
        for (int i = 0; i < 5; ++i) {
            std::cout << ptr[i] << " ";
        }
        std::cout << "\n";
        
        // Можем использовать std::distance для получения индекса
        auto it2 = vec.begin() + 3;
        auto index = std::distance(vec.begin(), it2);  // O(1)
        std::cout << "Index of it2: " << index << "\n";
        std::cout << "Direct access: vec[" << index << "] = " << vec[index] << "\n";
        
        // Преимущество: можно передать в C API
        int* data_ptr = vec.data();
        std::cout << "Can pass to C functions: data_ptr[2] = " << data_ptr[2] << "\n";
        
        // Концепты C++20
        static_assert(std::contiguous_iterator<decltype(vec.begin())>,
                     "vector::iterator is contiguous");
        
        std::cout << "✓ vector has contiguous iterator\n";
    }
    
   

    return 0;
}
