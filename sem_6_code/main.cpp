#include "ops.h"
#include "point.h"
#include "timer.h"
#include "vector.h"

void timers() {
  setTimer(Minutes(5));
  // setTimer(300);
  // setTimer(Minutes{300});

  Minutes m {5};

  // Minutes a(10);
  // std::cout << a.getValue();

}

void points() {
  Point a;
  a.Print();

  Point b;
  b.x = 1.0;
  b.y = 2.0;
  b.Print();

  Point c(1.0, 2.0);
  c.Print();

  // Point d(5.0);
  // d.Print();

  // Point c = {.x = 3.0, .y = 4.0};

  // c.Print();

  // Point d(c);
  // d.Print();
}

void vectors() {
  Vector a;
  std::cout << a;
  Vector b(1.0, 2.0);
  std::cout << b;
  Vector c(Point{.x = 1.0, .y = 0.5});
  std::cout << c;
  Vector d(c);
  std::cout << d;
  const Vector e = d;
  std::cout << e;


  // const auto f = e / d;

  std::cout << "B: " << b.getX() << " " << b.getY() << " " << b.length()
            << "\n";

  b.setX(1.1);

  std::cout << "B: " << b.getX() << " " << b.getY() << " " << b.length()
            << "\n";

  // e.setX(0);

  b.normalize();

  std::cout << "-----\n";
  std::cout << "B: " << b.getX() << " " << b.getY() << " " << b.length()
            << "\n";

  std::cout << "b + c " << b + c << "\n";
  // std::cout << "b + 10 " << b + 10 << "\n";
  std::cout << "b - c " << b - c << "\n";
  std::cout << "-c " << -c << "\n";
  std::cout << "b * 10 " << b * 10 << "\n";



  b += c;
  std::cout << "B: " << b.getX() << " " << b.getY() << " " << b.length()
            << "\n";

  b -= c;
  std::cout << "B: " << b.getX() << " " << b.getY() << " " << b.length()
            << "\n";

  b *= 3;
  std::cout << "B: " << b.getX() << " " << b.getY() << " " << b.length()
            << "\n";

  std::cout << "----\n";

  std::cout << "b v c " << (b == c) << " " << (b != c) << " " << (b > c) << " "
            << (b < c) << "\n";

  std::cout << "----\n";
  std::cout << vector_ops::distanceBetween(b, e);
}

int main() {
  // timers();

  // points();

  vectors();

  return 0;
}
