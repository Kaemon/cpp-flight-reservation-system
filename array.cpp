#include "array.hpp"
#include "passenger.hpp"


// kaemon
void reserveSeatArray(int planeIndex, int rowIndex, int columnIndex, Passenger p){
    auto start = high_resolution_clock::now();

    plane[planeIndex].info[rowIndex][columnIndex] = p;
    plane[planeIndex].seat[rowIndex][columnIndex] = true;
    plane[planeIndex].occupiedSeats++;

    auto stop = high_resolution_clock::now();
    double timeTaken = duration_cast<duration<double, micro>>(stop - start).count();

    cout << "\n>>> [ARRAY IMPLEMENTATION RESULTS] <<<\n";
    cout << "Status:      SUCCESS\n";
    
    cout << left << setw(20) << "  ~ Time Taken: " << fixed << setprecision(2) << timeTaken << " microseconds" << endl;
    spaceTrack("array");
};    


// hao
void cancelSeatArray(int targetID){
    auto start = high_resolution_clock::now();

    bool found = false;
    Passenger removedInfo; 

    // Search Logic
    for (int p = 0; p < max_planes; p++) {
        for (int r = 0; r < max_rows; r++) {
            for (int c = 0; c < max_cols; c++) {
                if (plane[p].seat[r][c] && plane[p].info[r][c].id == targetID) {
                    removedInfo = plane[p].info[r][c];

                    // DELETE
                    plane[p].seat[r][c] = false;       
                    plane[p].info[r][c] = Passenger(); 
                    plane[p].occupiedSeats--;          
                    
                    found = true;
                    goto end_loop; 
                }
            }
        }
    }

    end_loop:;

    auto stop = high_resolution_clock::now();
    double timeTaken = duration_cast<duration<double, micro>>(stop - start).count();

    cout << "\n>>> [ARRAY IMPLEMENTATION RESULTS] <<<\n";
    if (found) {
        cout << "Status:      SUCCESS\n";
        cout << "Passenger:   " << removedInfo.name << " (ID: " << targetID << ")\n";
        cout << "Flight Info: Plane " << removedInfo.planeNo << " | Seat " << removedInfo.seatRow << indexToColumn(columnToIndex(removedInfo.seatColumn)) << "\n";
    } else {
        cout << "Status:      FAILED (ID Not Found)\n";
    }
    cout << left << setw(20) << "  ~ Time Taken: " << fixed << setprecision(2) << timeTaken << " microseconds" << endl;
    spaceTrack("array");
};


// rijesh
void searchSeatArray(int targetID) {
    auto start = high_resolution_clock::now();
    
    bool found = false;
    Passenger foundInfo;
    for (int p = 0; p < planeCount; p++) {
        for (int r = 0; r < max_rows; r++) {
            for (int c = 0; c < max_cols; c++) {
                if (plane[p].seat[r][c] && plane[p].info[r][c].id == targetID) {
                    foundInfo = plane[p].info[r][c];
                    found = true;
                    goto end_loop;
                }
            }
        }
    }
    end_loop:;

    auto stop = high_resolution_clock::now();
    double timeTaken = duration_cast<duration<double, micro>>(stop - start).count();
    
    cout << "\n>>> [ARRAY IMPLEMENTATION RESULTS] <<<\n";
    if (found) {
        cout << "Status:      SUCCESS\n";
        cout << "Passenger:   " << foundInfo.name << " (ID: " << foundInfo.id << ")\n";
        cout << "Flight Info: Plane " << foundInfo.planeNo 
             << " | Seat " << (to_string(foundInfo.seatRow) + foundInfo.seatColumn) << "\n";
        cout << "Class:       " << foundInfo.flightClass << "\n";
    } else {
        cout << "Status:      FAILED (ID Not Found)\n";
    }

    cout << left << setw(20) << "  ~ Time Taken: " << fixed << setprecision(2) << timeTaken << " microseconds" << endl;
    spaceTrack("array");
}




// quan
void seatReporArray(){
    auto start = high_resolution_clock::now(); // START TIMER
    
    cout << "\n-------------------- ARRAY REPORT ---------------------\n";
    cout << left << setw(10) << "Plane" << setw(12) << "ID" << setw(20) << "Name" << setw(10) << "Seat" << "Class" << endl;
    cout << "---------------------------------------------------------\n";

    int count = 0;
    // Loop through ALL Planes
    for (int p = 0; p < planeCount; p++) {
        for (int r = 0; r < max_rows; r++) {
            for (int c = 0; c < max_cols; c++) {
                if (plane[p].seat[r][c]) {
                    cout << left 
                         << setw(10) << (p + 1)
                         << setw(12) << plane[p].info[r][c].id
                         << setw(20) << plane[p].info[r][c].name.substr(0, 19) // Crop long names
                        << setw(10) << (to_string(r + 1) + indexToColumn(c))
                         << plane[p].info[r][c].flightClass << endl;
                    count++;
                }
            }
        }
    }

    if (count == 0) cout << "No passengers found.\n";
    auto stop = high_resolution_clock::now();

    int totalCapacity = planeCount * max_rows * max_cols;
    int emptySeats = totalCapacity - count;

    cout << "--------------------------------------------------------------" << endl;
    cout << "   > Total Seats:           " << totalCapacity << " seats"  << endl;
    cout << "   > Occupied Seats:        " << count << endl;
    cout << "   > Empty Seats:           " << emptySeats << endl;

    double timeTaken = duration_cast<duration<double, micro>>(stop - start).count();
    cout << "--------------------------------------------------------------" << endl;
    cout << "           >>> [Array Seat Report Performance] <<<" << endl;
    cout << "--------------------------------------------------------------" << endl;
    cout << left << setw(20) << "  ~ Time Taken: " << fixed << setprecision(2) << timeTaken << " microseconds" << endl;
    spaceTrack("array");
};




