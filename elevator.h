#ifndef ELEVATOR_H
#define ELEVATOR_H
#include <vector>
#include <string>

constexpr int DEFAULT_FLOOR_TRAVEL_TIME { 10 };

class Elevator 
{
private:
    int floor {};
    int floorTravelTime {};
    int totalTravelTime { 0 };
    std::vector<int> visitedFloors {};
public:
    Elevator(int initialFloor, int initialFloorTravelTime = DEFAULT_FLOOR_TRAVEL_TIME);
    void travelToFloor(int destinationFloor);
    int getTotalTravelTime();
    std::string getPrintedListOfFloors();
};

#endif