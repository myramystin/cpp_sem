#pragma once

#include "truck.h"

class IVehicleVisitor;

class TDumpTruck : public TTruck {
public:
  TDumpTruck(const std::string &model, double capacity)
      : TTruck(model, capacity) {}

  void start() override;

  void dump() const;
};