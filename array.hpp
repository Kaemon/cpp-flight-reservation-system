#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "passenger.hpp"
using namespace std;


void reserveSeatArray(int planeIndex, int rowIndex, int columnIndex, Passenger p);
void cancelSeatArray(int targetID);
void searchSeatArray(int targetID);
void seatReporArray();



#endif

