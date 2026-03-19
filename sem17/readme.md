# Caches

Чт по памяти:

```
CPU registers    ~0.3 нс  
L1 cache  32KB   ~1   нс  
L2 cache  256KB  ~4   нс
L3 cache  8MB    ~40  нс
RAM              ~100 нс  
SSD              ~100 мкс

```

данные загружаются кэш-линиями по 64 байта

```cpp
// AoS - Array of Structures (привычно)
struct Particle {
    float x, y, z;    // 12 байт
    float vx, vy, vz; // 12 байт
    float mass;        // 4 байт
    // итого 28 байт + 4 паддинг = 32 байта
};
std::vector<Particle> particles(1000);

// Хотим обновить только позиции (типичная физика)
for (auto& p : particles) {
    p.x += p.vx;
}

// SoA - Structure of Arrays
struct Particles {
    std::vector<float> x, y, z;
    std::vector<float> vx, vy, vz;
    std::vector<float> mass;
};
Particles particles;

for (int i = 0; i < N; i++) {
    particles.x[i] += particles.vx[i]; // x[0..15] в кэше, используем все!
    particles.y[i] += particles.vy[i];
    particles.z[i] += particles.vz[i];
}
```


# Padding

```cpp

// Правило: поле выравнивается по своему размеру
// char  - по 1
// short - по 2
// int   - по 4
// double - по 8

struct Bad {
    char   a;  // 1 байт
               // 7 байт паддинг!
    double b;  // 8 байт
    char   c;  // 1 байт
               // 7 байт паддинг!
};
// sizeof(Bad) == 24

struct Good {
    double b;  // 8 байт
    char   a;  // 1 байт
    char   c;  // 1 байт
               // 6 байт паддинг (выравнивание структуры = max поля = 8)
};
// sizeof(Good) == 16

```