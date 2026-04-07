#ifndef PASSENGER_HPP
#define PASSENGER_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip> // for formatting
#include <chrono> // for time calculations
using namespace std;
using namespace std::chrono; // <--- ADD THIS LINE

// Constants
const int max_rows = 30;
const int max_cols = 6;
const int max_planes = 100;

// Passenger structure
struct Passenger {
    int id; 
    string name;
    int seatRow;
    string seatColumn;
    string flightClass;
    int planeNo; 
    
    Passenger* next;  // for linked list
};

// Plane structure: for handle multiple planes
struct Plane {
    Passenger info[max_rows][max_cols];
    bool seat[max_rows][max_cols];        // check seat avaibility: true = occupied / false = empty
    int occupiedSeats;
};

// Global variables declare
extern Plane plane[max_planes]; 
extern int planeCount;
extern Passenger* head; 


// Helper functions
int columnToIndex(string col);
string indexToColumn(int index);    
int validateInput(int min, int max);
void spaceTrack(string str); // Memory usage analyzer

// Helper functions for reserve seat
int selectAvailablePlane();
int getUniquePassengerID();
string getPassengerName();
bool selectSeat(int planeIndex, int& row, string& column);
string determineFlightClass(int row); 
void addedSuccessfull(int id, string name, int planeChose, int rowChose, string columnChose_A, string flightClass);


// flight system
void initializeSeatMap();
void addPassenger(Plane &plane, int r, int c, Passenger p);
void loadData(string filename);
void displaySeatMap(int planeNo);
void displaySummary();




#endif