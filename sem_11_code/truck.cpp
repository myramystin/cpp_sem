#include "truck.h"

#include "vechicle_visitor.h"

#include <iostream>

std::string TTruck::getModel() const { return model; }
double TTruck::getCapacity() const { return capacity; }

void TTruck::start() { std::cout << "Truck starts\n"; }

void TTruck::stop() { std::cout << "Truck stops\n"; }

std::string TTruck::getInfo() {
  return "Truck " + model + "capacity " + std::to_string(capacity) + "";
}

void TTruck::accept(IVehicleVisitor &visitor) { visitor.visit(*this); }


void TTruck::do_sth() { std::cout << "do_sth\n"; }
