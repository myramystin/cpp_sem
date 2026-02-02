#include "timer.h"

#include <iostream>

Minutes::Minutes(int minutes) : value_(minutes) {
  std::cout << "Created Minutes: " << value_ << "\n";
}

int Minutes::getValue() const { return value_; }


Seconds::Seconds(int seconds) : value_(seconds) {
  std::cout << "Created Seconds: " << value_ << "\n";
}

int Seconds::getValue() const { return value_; }

void setTimer(Minutes m) {
  std::cout << "Timer set to " << m.getValue() << " minutes\n";
}