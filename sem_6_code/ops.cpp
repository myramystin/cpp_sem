#include "ops.h"
#include "vector.h"

#include <cmath>

namespace vector_ops {
double distanceBetween(const Vector &v1, const Vector &v2) {
  double dx = v1.x_ - v2.x_;
  double dy = v1.y_ - v2.y_;
  return std::sqrt(dx * dx + dy * dy);
}
} // namespace vector_ops
