#include "elevator.h"
#include <sstream>

using namespace std;

int main(int argc, char* argv[])
{
    int startingFloor { stoi(argv[1]) };
    Elevator elevator { startingFloor };
    stringstream ss(argv[2]);
    for (int i; ss >> i;) {
        elevator.travelToFloor(i);
        if (ss.peek() == ',') {
            ss.ignore();
        }
    }
    elevator.printTravelTime();
    elevator.printTraversedFloors();
    return 0;
}