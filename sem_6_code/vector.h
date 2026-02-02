#pragma once

#include <iostream>

#include <compare>

struct Point; // forward declaration

class Vector;

namespace vector_ops {
double distanceBetween(const Vector &v1, const Vector &v2);
} // namespace vector_ops

class Vector {
public:
  Vector() = default;
  explicit Vector(double x, double y);
  explicit Vector(const Point &p);

  Vector(const Vector &other); // copy constructor
  Vector &operator=(const Vector &other);

  double getX() const;
  double getY() const;
  double length() const;
  double lengthSquared() const;

  void setX(double x);

  void setY(double y);

  void set(double x, double y);

  void normalize();

  Vector operator+(const Vector &other) const;
  Vector operator-(const Vector &other) const;
  Vector operator-() const;
  Vector operator*(double scalar) const;

  Vector& operator+=(const Vector &other);

  Vector& operator-=(const Vector &other);
  Vector& operator*=(double scalar);

  bool operator==(const Vector &other) const;
  bool operator!=(const Vector &other) const;

  // bool operator<(const Vector &other) const;

  // bool operator>(const Vector &other) const;

  // bool operator<=(const Vector &other) const;

  // bool operator>=(const Vector &other) const;

  auto operator<=>(const Vector &other) const {

    const double epsilon = 1e-10;
    if (std::abs(x_ - other.x_) < epsilon &&
        std::abs(y_ - other.y_) < epsilon) {
      return std::strong_ordering::equal;
    }

    return lengthSquared() < other.lengthSquared()
               ? std::strong_ordering::less
               : std::strong_ordering::greater;
  }

  friend double vector_ops::distanceBetween(const Vector &v1, const Vector &v2);

  friend std::ostream &operator<<(std::ostream &os, const Vector &v);

private:
  double x_ = 0.;
  double y_ = 0.;

private:
  void normalize_internal();
};

std::ostream& operator<<(std::ostream &os, const Vector &v);
