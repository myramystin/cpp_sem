#include "dumptruck.h"

#include <iostream>

void TDumpTruck::start() { std::cout << "Dumptruck starts\n"; }

void TDumpTruck::dump() const { std::cout << "Dumptruck dumps\n"; }

void TDumpTruck::do_sth() { std::cout << "do_sth1\n"; }
