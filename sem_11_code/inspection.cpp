#include "inspection.h"
#include "car.h"
#include "vechicle.h"

#include <iostream>

void TInspectionVisitor::visit(IVehicle &vechicle) {
  std::cout << "Inspect vechicle " << vechicle.getInfo() << "\n";
  ++vechiclesInspected;
}
void TInspectionVisitor::visit(TCar &car) {
  std::cout << "Inspect car " << car.getInfo() << " has " << car.getDoors()
            << " doors \n";
  ++vechiclesInspected;
  ++carsInspected;
}

void TInspectionVisitor::printReport() {
  std::cout << "\ninspected " << vechiclesInspected << " vechicles, "
            << carsInspected << " of them were cars\n";
}