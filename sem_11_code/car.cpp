#include "car.h"

#include "vechicle_visitor.h"

#include <iostream>

std::string TCar::getBrand() const { return brand; }
int TCar::getDoors() const { return doors; }

void TCar::start() { std::cout << "Car starts\n"; }

void TCar::stop() { std::cout << "Car stops\n"; }

std::string TCar::getInfo() {
  return "Car with " + std::to_string(doors) + "doors and brand = " + brand;
}

void TCar::accept(IVehicleVisitor &visitor) { visitor.visit(*this); }
