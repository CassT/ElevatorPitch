#include <iostream>
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

void Elevator::printTravelTime() {
    cout << "Travel time: " << totalTravelTime << endl;
}

void Elevator::printTraversedFloors() {
    cout << "Visited floors: ";
    for (size_t i = 0; i < visitedFloors.size() - 1; i++) {
        cout << visitedFloors[i] << ",";
    }
    cout << visitedFloors[visitedFloors.size() - 1] << endl;
}
