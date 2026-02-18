#pragma once

#include "vechicle_visitor.h"

class TInspectionVisitor : public IVehicleVisitor {
private:
  int carsInspected = 0;
  int vechiclesInspected = 0;

public:
  void visit(IVehicle &car) override;
  void visit(TCar &car) override;

  void printReport();
};