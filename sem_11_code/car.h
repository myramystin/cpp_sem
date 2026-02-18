#pragma once

#include "vechicle.h"

class IVehicleVisitor;

class TCar final : public IVehicle {
  // final - нельзя наследовать от Car
private:
  std::string brand;
  int doors;

public:
  TCar(const std::string &brand, int doors) : brand(brand), doors(doors) {}

  std::string getBrand() const;
  int getDoors() const;

  // Реализация абстрактных методов
  void start() override;

  void stop() override;

  std::string getInfo() override;

  void accept(IVehicleVisitor &visitor) override;
};