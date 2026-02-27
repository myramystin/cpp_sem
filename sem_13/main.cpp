#include <iostream>

// class SimpleArray {
// private:
//     int* data;
//     int sz;
// public:
//     SimpleArray(const SimpleArray& other) : data(new int[](other.sz)), sz(other.sz) {
//         std::copy(other.data, other.data + size, data);
//     }

//     SimpleArray& operator=(const SimpleArray& other) {
//         int* tmp = new int[](other.sz);
//         std::copy(other.data, other.data + size, tmp);

//         delete[] data;
        
//         sz = other.sz;
//         data = tmp;

//         return *this;
//     }
// }



class ElegantArray {
private:
    int* data;
    size_t size;
    
public:
    explicit ElegantArray(size_t s = 0) 
        : data(s > 0 ? new int[s] : nullptr), size(s) {
        std::cout << "  Конструктор: создан массив размером " << size << "\n";
        for (size_t i = 0; i < size; ++i) {
            data[i] = static_cast<int>(i * 10);
        }
    }
    
    ElegantArray(const ElegantArray& other) 
        : data(other.size > 0 ? new int[other.size] : nullptr), size(other.size) {
        std::cout << "  Копирующий конструктор\n";
        std::copy(other.data, other.data + size, data);
    }
    
    ElegantArray(ElegantArray&& other) noexcept 
        : data(nullptr), size(0) {
        std::cout << " Перемещающий конструктор\n";
        swap(other);
    }
    
    // Деструктор
    ~ElegantArray() {
        std::cout << " Деструктор: освобождается массив размером " << size << "\n";
        delete[] data;
    }
    
    void swap(ElegantArray& other) noexcept {
        std::cout << "  Обмен массивов (размеры: " << size << " <-> " << other.size << ")\n";
        std::swap(data, other.data);
        std::swap(size, other.size);
    }
    
    // COPY-AND-SWAP ИДИОМА: принимаем ПО ЗНАЧЕНИЮ!
    ElegantArray& operator=(ElegantArray other) {  // ← Копия создаётся здесь автоматически!        
        swap(other);  // Обмениваемся с копией
        return *this;  // other уничтожается
    }
    
    void print() const {
        std::cout << "    ElegantArray[" << size << "]: ";
        for (size_t i = 0; i < size; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << "\n";
    }
    
    size_t getSize() const { return size; }
};


class Rectangle :  public virtual Shape {
    
}

int main() {
    ElegantArray array(5);
    ElegantArray array1(10);

    array = array1;
    array.print();
    array1.print();
}
