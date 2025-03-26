#include <string>
#include "elevator.h"
using namespace std;

Elevator::Elevator(
    int initialFloor, 
    int initialFloorTravelTime
) 
    : floor { initialFloor }
    , floorTravelTime { initialFloorTravelTime }
{}

void Elevator::travelToFloor(int destinationFloor) {
    visitedFloors.push_back(destinationFloor);
    int travelDistance = (floor > destinationFloor)
        ? (floor - destinationFloor)
        : (destinationFloor - floor);
    totalTravelTime += travelDistance * floorTravelTime;
    floor = destinationFloor;
}

int Elevator::getTotalTravelTime() {
    return totalTravelTime;
}

string Elevator::getPrintedListOfFloors() {
    string listOfFloors;
    for (size_t i = 0; i < visitedFloors.size() - 1; i++) {
        listOfFloors += to_string(visitedFloors[i]);
        listOfFloors += ",";
    }
    listOfFloors += to_string(visitedFloors[visitedFloors.size() - 1]);
    return listOfFloors;
}
