#include "vector.h"

#include "point.h"

#include <cmath>
#include <iostream>

Vector::Vector(double x, double y) : x_(x), y_(y) {}

Vector::Vector(const Point &p) : x_(p.x), y_(p.y) {}

Vector::Vector(const Vector &other) : x_(other.x_), y_(other.y_) {}

Vector &Vector::operator=(const Vector &other) {
  if (this != &other) { // Do not copy from itself
    x_ = other.x_;
    y_ = other.y_;
  }
  return *this;
}

double Vector::getX() const { 
  return x_;
}

double Vector::getY() const { return y_; }
double Vector::lengthSquared() const { return x_ * x_ + y_ * y_; }

double Vector::length() const { return std::sqrt(lengthSquared()); }

void Vector::setX(double x) { x_ = x; }

void Vector::setY(double y) { y_ = y; }

void Vector::set(double x, double y) {
  x_ = x;
  y_ = y;
}

void Vector::normalize() { normalize_internal(); }

Vector Vector::operator+(const Vector &other) const {
  return Vector(x_ + other.x_, y_ + other.y_);
}

Vector Vector::operator-(const Vector &other) const {
  return Vector(x_ - other.x_, y_ - other.y_);
}

Vector Vector::operator-() const { return Vector(-x_, -y_); }

Vector Vector::operator*(double scalar) const {
  return Vector(x_ * scalar, y_ * scalar);
}

Vector& Vector::operator+=(const Vector &other) {
  x_ += other.x_;
  y_ += other.y_;
  return *this; // Возвращаем ссылку на себя
}

Vector& Vector::operator-=(const Vector &other) {
  x_ -= other.x_;
  y_ -= other.y_;
  return *this;
}

Vector& Vector::operator*=(double scalar) {
  x_ *= scalar;
  y_ *= scalar;
  return *this;
}

bool Vector::operator==(const Vector &other) const {
  const double epsilon = 1e-10;
  return std::abs(x_ - other.x_) < epsilon && std::abs(y_ - other.y_) < epsilon;
}

bool Vector::operator!=(const Vector &other) const { return !(*this == other); }

// bool Vector::operator<(const Vector &other) const {
//   return lengthSquared() < other.lengthSquared();
// }

// bool Vector::operator>(const Vector &other) const {
//   return lengthSquared() > other.lengthSquared();
// }

// bool Vector::operator<=(const Vector &other) const {
//   return lengthSquared() <= other.lengthSquared();
// }

// bool Vector::operator>=(const Vector &other) const {
//   return lengthSquared() >= other.lengthSquared();
// }

void Vector::normalize_internal() {
  double len = length();
  if (len > 1e-10) {
    x_ /= len;
    y_ /= len;
  }
}

std::ostream &operator<<(std::ostream &os, const Vector &v) {
  // Имеем доступ к приватным полям x_ и y_
  os << "[" << v.x_ << ", " << v.y_ << "]\n";
  return os;
}
