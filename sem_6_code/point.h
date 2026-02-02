#pragma once

struct Point {
  double x;
  double y;

  void Print() const;

  // Point() = default;

  // Point(double x) : x(x) {}

  // Point(double x_val, double y_val)
  // : x(x_val + y_val)
  // , y(y_val)
  // {}

  // Point(const Point& other) = delete;


  // Point(double x_val = 0, double y_val = 0) : x(x_val), y(y_val) {} //
  // конструктор по умолчанию
};
