#include <iostream>

enum ECurrency {
  USD = 840,
  EUR = 978,
  RUB = 643,
};

int main() {
  std::cout << ECurrency::EUR;
  return 0;
}