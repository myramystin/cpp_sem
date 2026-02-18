#pragma once

#include "vechicle.h"

class IVehicleVisitor;

class TTruck : public IVehicle {
  // Можно наследовать дальше (нет final)
protected:
  std::string model;
  double capacity;

public:
  TTruck(const std::string &model, double capacity)
      : model(model), capacity(capacity) {}

  std::string getModel() const;
  double getCapacity() const;

  void start() override;

  void stop() override;

  std::string getInfo() override;

  void accept(IVehicleVisitor &visitor) override;
};