#include <chrono>
#include <cmath>
#include <iostream>

bool IsOdd(int32_t n) { 
  return n & 1;
}

bool IsEven(int32_t n) { return !(n & 1); }

bool IsPowerOfTwo(int32_t n) { return n > 0 && (n & (n - 1)) == 0; }


namespace {

  int32_t ChangeSign(int32_t n) { return ~n + 1; }

}

int main() {
  // &  -- bitwise and
  std::cout << int(3 & 2) << "\n";
  // |  -- bitwise or
  std::cout << int(3 | 2) << "\n";
  // ~ -- bitwise not
  std::cout << static_cast<unsigned int>(~2) << "\n";

  // ^ -- bitwise xor
  std::cout << int(3 ^ 2) << "\n";
  // << - move left
  std::cout << "----\n";
  std::cout << int(1 << 2) << "\n";
  std::cout << int(2 << 2) << "\n";
  std::cout << int(2 >> 2) << "\n";
  std::cout << int(4 >> 2) << "\n";

  // >> move right










  // std::cout << "Is Odd " << IsOdd(2) << " IsEven " << IsEven(2) << "\n---\n";

  // std::cout << "IsPowerOfTwo " << IsPowerOfTwo(2) << " " << IsPowerOfTwo(3)
  //           << "\n---\n";


  // // {
  // //   std::cout << "Signs " << ChangeSign(2) << " " << ChangeSign(-2) << "\n---\n";
  // // }


  // {
  //   int a = 5;
  //   int b = 3;

  //   a ^= b; // a = 6 (110)      b = 3 (011)
  //   b ^= a; // a = 3 (011)      b = 5 (101)
  //   a ^= b; // a = 3 (011)      b = 5 (101)

  //   std::cout << "A " << a << " B " << b << "\n";
  // }

  return 0;
}