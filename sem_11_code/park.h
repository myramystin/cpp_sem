#pragma once

#include "vechicle.h"

#include <memory>
#include <string>
#include <vector>

class TVehicleGroup : public IVehicle {
private:
  std::string name;
  std::vector<std::shared_ptr<IVehicle>> vehicles;

public:
  TVehicleGroup(const std::string &name) : name(name) {}

  void addVehicle(std::shared_ptr<IVehicle> vehicle);

  void start() override;

  void stop() override;

  std::string getInfo() override;

  void accept(IVehicleVisitor &visitor) override;

  size_t getVehicleCount() const;
};