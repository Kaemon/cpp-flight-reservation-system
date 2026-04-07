#include <iostream>
#include "passenger.hpp"
#include "array.hpp"
#include "linked_list.hpp"
using namespace std;

//  !!!!! every section need input validation & "Back" option  !!!!!!!!
//  for input validation: can use the validateInput(int min, int max); in passenger.cpp 
//  read👇🏻, everyone go to array.cpp and linked_list.cpp to write code into function respectively

// 1. Reserve Seat - kaemon
void reserveSeat(){
    int planeChose = selectAvailablePlane();
    if (planeChose == -1) { return; }
    
    int id = getUniquePassengerID();
    if (id == -1) { return; }
    
    string name = getPassengerName();
    
    int planeIndex = planeChose - 1;
    int rowChose;
    string columnChose_A;
    
    if (!selectSeat(planeChose, rowChose, columnChose_A)) { return; }
    
    string flightClass = determineFlightClass(rowChose);

    Passenger new_p;
    new_p.id = id;
    new_p.name = name;
    new_p.seatRow = rowChose;
    new_p.seatColumn = columnChose_A;
    new_p.flightClass = flightClass;
    new_p.planeNo = planeChose;
    new_p.next = nullptr;

    int rowChose_I = rowChose - 1;
    int columnChose_I = columnToIndex(columnChose_A);

    cout << "\n------------------------------------------\n";
    cout << "        Saving Reservation Info...        \n";
    cout << "------------------------------------------\n";
    reserveSeatArray(planeIndex, rowChose_I, columnChose_I, new_p);  
    reserveSeatLinkedList(new_p);
    addedSuccessfull(id, name, planeChose, rowChose, columnChose_A, flightClass);
}


// 2. Cancel Seat - hao
void cancelSeat(){
    cout << "\n\n~~~~~~~~~~~~~~~ CANCEL SEAT ~~~~~~~~~~~~~~~\n";

    // 1. Request User Input ONLY ONCE
    cout << "  Enter Passenger ID to cancel: ";
    int targetID;
    while(!(cin >> targetID)){
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid ID. Try again: ";
    }

    cout << "\n------------------------------------------\n";
    cout << "     Processing Cancellation...\n";
    cout << "------------------------------------------\n";

    // 2. Call both functions using the SAME ID
    cancelSeatArray(targetID);      
    cancelSeatLinkedList(targetID); 
    
    cout << "\n[Done]\n\nReturning to Main Menu...\n";
};


// 3. Search Seat - rejish
void searchSeat(){
    int targetID;
    
    cout << "\n\n~~~~~~~~~~~~~ SEARCH PASSENGER ~~~~~~~~~~~~~\n";
    cout << "   Enter passenger ID to search: ";
    
    // Input Validation
    while (!(cin >> targetID)) {
        cin.clear(); 
        cin.ignore(1000, '\n'); 
        cout << "Invalid input. Please enter a numeric ID: ";
    }

    // 1. Run Array Search
    searchSeatArray(targetID);

    // 2. Run Linked List Search
    searchSeatLinkedList(targetID);

    cout << "\n_________________________________________________\n";
    cout << "\n[Done]\n\nReturning to Main Menu...\n";
};


// 4. Seat Report - quan
void showReport(){
    int choice;
    do {
        cout << "\n\n~~~~~~~~~~~~~ SEAT REPORT MENU ~~~~~~~~~~~~~" << endl;
        cout << "   1. Array Report (Sorted by Seat)" << endl;
        cout << "   2. Linked List Report (Sorted by Arrival)" << endl;
        cout << "   3. Back to Main Menu" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << " Enter your choice (1-3): ";

        choice = validateInput(1, 3);
        switch (choice) {
            case 1:
                seatReporArray(); 
                break;                
            case 2:
                seatReporLinkedList();
                break;
            case 3:
                cout << "\n[Back]\n\nReturning to Main Menu...\n";
                return;
        }
    } while (true);
};


void displayMenu() {
    cout << "\n==========================================\n";
    cout << "------- FLIGHT RESERVATION SYSTEM --------\n";
    cout << "==========================================\n";            
    cout << "\t1. Reserve Seat\n";                   
    cout << "\t2. Cancel Seat\n";  
    cout << "\t3. Search Seat\n";        
    cout << "\t4. Seat Report\n";         
    cout << "\t5. Exit\n";
    cout << "==========================================\n";
}


int main() {
    initializeSeatMap();
    loadData("flight_passenger_data.csv");
    displaySummary();
    
    // main menu
    int choice = 0;
    do{
        displayMenu();
        cout << "Enter your choice (1-5): ";
        
        // Input Validation
        choice = validateInput(1, 5);

        switch (choice) {
            case 1:
                reserveSeat();
                break;
            case 2:
                cancelSeat();
                break;
            case 3:
                searchSeat();
                break;
            case 4: 
                showReport();
                break;
            case 5:
                cout << "\n\nExiting system... Goodbye!\n";
                break;
        }
    } while (choice != 5);  
}