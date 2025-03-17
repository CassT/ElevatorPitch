#include <iostream>
#include <string>
#include <sstream>
using namespace std;

constexpr int DEFAULT_FLOOR_TRAVEL_TIME = 10;

class Elevator
{
private:
    int floor {};
    int floorTravelTime {};
    int totalTravelTime { 0 };
    vector<int> visitedFloors {};

public:
    Elevator(int initialFloor, int initialSpeed = DEFAULT_FLOOR_TRAVEL_TIME) {
        floor = initialFloor;
        floorTravelTime = initialSpeed;
        visitedFloors.push_back(initialFloor);
    }

    void travelToFloor(int destinationFloor) {
        visitedFloors.push_back(destinationFloor);
        int travelDistance = (floor > destinationFloor) ? (floor - destinationFloor) : (destinationFloor - floor);
        int travelTime = travelDistance * floorTravelTime;
        totalTravelTime += travelTime;
        floor = destinationFloor;
    }

    void printTravelTime() {
        cout << "Travel time: " << totalTravelTime << endl;
    }

    void printTraversedFloors() {
        cout << "Visited floors: ";
        for (size_t i = 0; i < visitedFloors.size() - 1; i++) {
            cout << visitedFloors[i] << ",";
        }
        cout << visitedFloors[visitedFloors.size() - 1] << endl;
    }
};

int main(int argc, char* argv[])
{
    if (argc != 3) {
        throw runtime_error("incorrect number of arguments, usage: ./elevator <starting floor> <floors to visit (comma-seperated)>");
    }
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