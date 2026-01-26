#include <cstdint>
#include <iostream>
#include <limits>
#include <typeinfo>

int main() {
  auto printer = [](auto param) {
    std::cout << "Type: " << typeid(param).name() << ", size: " << sizeof(param)
              << ", min: " << std::numeric_limits<decltype(param)>::min()
              << ", max: " << std::numeric_limits<decltype(param)>::max()
              << "\n----\n";
  };

  bool a = true;  
  int b = 4;
  char c = '1';
  float d = .1;
  double e = 1e-2;
  long int f = 1;
  long long int g = 1;
  unsigned int h = 3u;
  long double i = .1;
  size_t j = 1;

  int16_t k = 2;
  uint16_t l = 2;
  int32_t m = 2;
  uint32_t n = 2;
  int64_t o = 2;
  uint64_t p = 2;

  printer(a);
  printer(b);
  printer(c);
  printer(d);
  printer(e);
  printer(f);
  printer(g);
  printer(h);
  printer(i);
  printer(j);
  printer(k);
  printer(l);
  printer(m);
  printer(n);
  printer(o);
  printer(p);

  return 0;
}