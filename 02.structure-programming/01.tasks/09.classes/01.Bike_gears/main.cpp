#include <iostream>
#include "Bike.h"
#include <format>

using namespace std;

int main() {
    Bike bike;

    bike.gearDown();
    bike.gearUp();
    bike.gearUp();
    cout << format("Dabartine pavara: {}", bike.getGear());

    return 0;
}
