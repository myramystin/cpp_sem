#include "park.h"

#include <iostream>

void TVehicleGroup::addVehicle(std::shared_ptr<IVehicle> vehicle) {
  vehicles.push_back(vehicle);
}

void TVehicleGroup::start() {
  std::cout << "starting group " << name << "\n";
  for (auto &vehicle : vehicles) {
    vehicle->start();
  }
}

void TVehicleGroup::stop() {
  std::cout << "stopping group " << name << "\n";
  for (auto &vehicle : vehicles) {
    vehicle->stop();
  }
}

std::string TVehicleGroup::getInfo() {
  std::string info = "Группа " + name + " (" + std::to_string(vehicles.size()) +
                     " транспорта:\n";
  for (size_t i = 0; i < vehicles.size(); i++) {
    info += "  " + std::to_string(i + 1) + ". " + vehicles[i]->getInfo() + "\n";
  }
  return info;
}

void TVehicleGroup::accept(IVehicleVisitor &visitor) {
  // Группа сама не посещается, но её элементы - да
  for (auto &vehicle : vehicles) {
    vehicle->accept(visitor);
  }
}

size_t TVehicleGroup::getVehicleCount() const { return vehicles.size(); }
