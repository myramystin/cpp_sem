#pragma once

class IVehicle;
class TCar;

class IVehicleVisitor {
public:
  virtual ~IVehicleVisitor() = default;
  virtual void visit(IVehicle &vechicle) = 0;
  virtual void visit(TCar &car) = 0;
};