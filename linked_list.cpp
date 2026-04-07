#include "linked_list.hpp"
#include "passenger.hpp"



// kaemon
void reserveSeatLinkedList(Passenger p) {
    auto start = high_resolution_clock::now();

    Passenger* newNode = new Passenger;
    *newNode = p;        
    newNode->next = head;
    head = newNode;      

    auto stop = high_resolution_clock::now();
    double timeTaken = duration_cast<duration<double, micro>>(stop - start).count();

    cout << "\n>>> [LINKED LIST IMPLEMENTATION RESULTS] <<<\n";
    cout << "Status:      SUCCESS\n";

    cout << left << setw(20) << "  ~ Time Taken: " << fixed << setprecision(2) << timeTaken << " microseconds" << endl;
    spaceTrack("list");
}  


// hao
void cancelSeatLinkedList(int targetID){
    auto start = high_resolution_clock::now();

    Passenger* current = head;
    Passenger* prev = nullptr;
    bool found = false;
    Passenger removedInfo;

    // Search Logic
    while (current != nullptr) {
        if (current->id == targetID) {
            removedInfo.name = current->name;
            removedInfo.seatRow = current->seatRow;
            removedInfo.seatColumn = current->seatColumn;
            removedInfo.planeNo = current->planeNo;

            // DELETE
            if (prev == nullptr) {
                head = current->next; 
            } else {
                prev->next = current->next; 
            }
            
            delete current; 
            found = true;
            break;
        }
        prev = current;
        current = current->next;
    }

    auto stop = high_resolution_clock::now();
    double timeTaken = duration_cast<duration<double, micro>>(stop - start).count();

    // OUTPUT
    cout << "\n>>> [LINKED LIST IMPLEMENTATION RESULTS] <<<\n";
    if (found) {
        cout << "Status:      SUCCESS\n";
        cout << "Passenger:   " << removedInfo.name << " (ID: " << targetID << ")\n";
        cout << "Flight Info: Plane " << removedInfo.planeNo << " | Seat " << removedInfo.seatRow << removedInfo.seatColumn << "\n";
    } else {
        cout << "Status:      FAILED (ID Not Found)\n";
    }
    cout << left << setw(20) << "  ~ Time Taken: " << fixed << setprecision(2) << timeTaken << " microseconds" << endl;
    spaceTrack("list");
};



// rijesh
void searchSeatLinkedList(int targetID){
    auto start = high_resolution_clock::now();

    bool found = false;
    Passenger* current = head;
    Passenger* foundNode = nullptr;

    while (current != nullptr) {
        if (current->id == targetID) {
            foundNode = current;
            found = true;
            break;
        }
        current = current->next;
    }

    auto stop = high_resolution_clock::now();
    double timeTaken = duration_cast<duration<double, micro>>(stop - start).count();
    
    cout << "\n>>> [LINKED LIST IMPLEMENTATION RESULTS] <<<\n";
    if (found) {
        cout << "Status:      SUCCESS\n";
        cout << "Passenger:   " << foundNode->name << " (ID: " << foundNode->id << ")\n";
        cout << "Flight Info: Plane " << foundNode->planeNo 
             << " | Seat " << (to_string(foundNode->seatRow) + foundNode->seatColumn) << "\n";
        cout << "Class:       " << foundNode->flightClass << "\n";
    } else {
        cout << "Status:      FAILED (ID Not Found)\n";
    }

    cout << left << setw(20) << "  ~ Time Taken: " << fixed << setprecision(2) << timeTaken << " microseconds" << endl;
    spaceTrack("list");
};


// quan
void seatReporLinkedList(){
    auto start = high_resolution_clock::now();

    cout << "\n--------------- LINKED LIST REPORT ---------------" << endl;
    cout << left << setw(10) << "Plane" << setw(12) << "ID" << setw(20) << "Name" << setw(10) << "Seat" << "Class" << endl;
    cout << "---------------------------------------------------------" << endl;

    int count = 0;
    Passenger* current = head;

    // 1. Traverse the list until the end
    while (current != nullptr) {
        cout << left 
             << setw(10) << current->planeNo
             << setw(12) << current->id
             << setw(20) << current->name.substr(0, 19)
             << setw(10) << (to_string(current->seatRow) + current->seatColumn)
             << current->flightClass << endl;
        count++;
        current = current->next; // Move to next node
    }

    if (count == 0) cout << "No passengers found." << endl;
    auto stop = high_resolution_clock::now();

    cout << "--------------------------------------------------------------" << endl;
    cout << "   > Total Loaded Nodes:    " << count << "\n";

    double timeTaken = duration_cast<duration<double, micro>>(stop - start).count();
    cout << "--------------------------------------------------------------" << endl;
    cout << "       >>> [Linked List Seat Report Performance] <<<" << endl;
    cout << "--------------------------------------------------------------" << endl;
    cout << left << setw(20) << "  ~ Time Taken: " << fixed << setprecision(2) << timeTaken << " microseconds" << endl;
    spaceTrack("list");
};


