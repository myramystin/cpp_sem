#pragma once

#include <string>

class IVehicleVisitor;

class IVehicle {
public:
  virtual ~IVehicle() = default;

  // Чисто виртуальные методы (абстрактные)
  virtual void start() = 0;
  virtual void stop() = 0;
  virtual std::string getInfo() = 0;
  virtual void accept(IVehicleVisitor &visitor) = 0;
};
