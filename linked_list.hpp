#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "passenger.hpp"
using namespace std;


void reserveSeatLinkedList(Passenger p);
void cancelSeatLinkedList(int targetID);
void searchSeatLinkedList(int targetID);
void seatReporLinkedList();



#endif