
#include "passenger.hpp"

// Global variables definitions
Plane plane[max_planes];
int planeCount = 0;
Passenger* head = nullptr;


// convert column letter to index
int columnToIndex(string col) { 
    if (col == "A") return 0;
    if (col == "B") return 1;
    if (col == "C") return 2;
    if (col == "D") return 3;
    if (col == "E") return 4;
    if (col == "F") return 5;
    return -1;
}

// convert index back to column letter
string indexToColumn(int index) {  
    string cols[] = {"A", "B", "C", "D", "E", "F"};
    if (index >= 0 && index < 6) return cols[index];
    return "?";
}

// for input validation
int validateInput(int min, int max) {
    int choice;
    while (true) {
        cin >> choice;
        // Check if input is a valid integer
        if (cin.fail()) {
            cin.clear(); // Clear error flag
            cin.ignore(1000, '\n'); // Discard invalid input
            cout << " > Invalid input! \n    Please enter number (" << min << "-" << max << "): ";
        } 
        // Check if input is within range
        else if (choice < min || choice > max) {
            cout << " > Out of range! \n    Please enter a number between " << min << " and " << max << ": ";
        } 
        else {
            return choice;
        }
    }
}

// Memory usage analyzer
void spaceTrack(string str) {
    long long memoryUsed = 0;
    string name = "";

    // 1. Calculate based on type
    if (str == "array") {
        memoryUsed = sizeof(plane); // Fixed size (Actual bytes)
    } 
    else if (str == "list") {
        // Count nodes for list
        Passenger* current = head;
        while (current != nullptr) {
            memoryUsed += sizeof(Passenger); // Size of node (Actual bytes)
            current = current->next;
        }
    }
    // 2. Output One Line
    // Format: [Type] ~ Total Memory: 12345 bytes (12.5 KB)
    cout << left << setw(20) << "  ~ Total Memory: " << memoryUsed << " bytes (" << fixed << setprecision(2) << (memoryUsed / 1024.0) << " KB)" << endl;
}



int selectAvailablePlane(){
    cout << "\n==========================================" << endl;
    cout << "------------ AVAILABLE FLIGHT ------------" << endl;
    cout << "==========================================" << endl;
    int total = max_cols * max_rows;
    int no_ = 1;
    int planeChose;
    int rowChose;
    string columnChose_A;
    string name;
    int id;

    for (int i=0; i < planeCount; i++){
        if(plane[i].occupiedSeats < total){
            cout << "\t     " << no_ << ". Plane "<< (i+1) << " " << endl;
            no_ ++;
        }
    }

    cout << "==========================================" << endl;

    bool validPlane = false;
    while (!validPlane) {
        cout << "Please enter the plane number (1-" << planeCount << ") or 0 to go back: Plane ";
        planeChose = validateInput(0, planeCount);
        
        if (planeChose == 0) {
            return -1;  
        }
        
        int planeIndex = planeChose - 1;
        
        if (plane[planeIndex].occupiedSeats < total) {
            validPlane = true;
            return planeChose;
        } else {
            cout << "Plane " << planeChose << " is fully occupied!\n";
            cout << "Please choose another plane.\n";
        }
    }
    return -1;
}

int getUniquePassengerID(){
    bool uniqueID = false;
    while (!uniqueID){
        cout << "==========================================" << endl;
        cout << "Please enter your IDs or (0 to cancel): ";
        int id = validateInput(0, 999999);
        if (id == 0){
            return -1;
        }
        Passenger* current = head;
        bool idExists = false;
        while (current != nullptr){
            if (current->id == id){
                idExists = true;
                break;
            }
            current = current->next;
        } 
        if (idExists){
            cout << "ID " << id << " already exists..." << endl;
        }else{
            uniqueID = true;
            return id;
        }
    }
    return -1;
}

string getPassengerName(){
    cout << "Please enter your name: ";
    cin.ignore();
    string name;
    getline(cin,name);
    return name;
}

bool selectSeat(int planeChose, int& rowChose, string& columnChose_A){
    bool validSeat = false;
    int planeIndex = planeChose - 1;

    while (!validSeat){
        displaySeatMap(planeChose);
        cout << "\n==========================================" << endl;
        cout << "Please enter the row number (1-30) or 0 to cancel: ";
        rowChose = validateInput(0, 30);
        if (rowChose == 0){
            return false;
        }
        cout << "Please enter the column letter (A-F): ";
        cin >> columnChose_A;

        if (columnChose_A.length() == 1) {
            columnChose_A[0] = toupper(columnChose_A[0]);
        }
        
        int columnChose_I = columnToIndex(columnChose_A);
        
        if (columnChose_I == -1){
            cout << "Invalid column...";
            continue;
        }

        int rowChose_I = rowChose - 1;
        if (plane[planeIndex].seat[rowChose_I][columnChose_I]){
            cout << "Seat " << rowChose << columnChose_A << " is occupied!\n";
        }else{
            validSeat = true;
            return true;
            
        }
    }
    return false;
}

string determineFlightClass(int rowChose){
    if (rowChose >= 1 && rowChose <= 3) {
        return "First Class";
    } else if (rowChose >= 4 && rowChose <= 10) {
        return "Business Class";
    } else {
        return "Economy Class";
    }
}

void addedSuccessfull(int id, string name, int planeChose, int rowChose, string columnChose_A, string flightClass){
    cout << "\n==========================================" << endl;
    cout << "    SEAT RESERVED SUCCESSFULLY!" << endl;
    cout << "==========================================" << endl;
    cout << "Passenger ID:   " << id << endl;
    cout << "Name:           " << name << endl;
    cout << "Plane:          " << planeChose << endl;
    cout << "Seat:           " << rowChose << columnChose_A << endl;
    cout << "Class:          " << flightClass << endl;
    cout << "==========================================" << endl;
    cout << "\n[Done]\n\nReturning to Main Menu...\n";

}







// create empty plane
void initializeSeatMap() {
    planeCount = 0;
    head = nullptr;
    
    // Initialize first plane
    for (int i = 0; i < max_rows; i++) {
        for (int j = 0; j < max_cols; j++) {
            plane[0].seat[i][j] = false;
            plane[0].info[i][j].id = 0;
            plane[0].info[i][j].name = "";
            plane[0].info[i][j].seatRow = 0;
            plane[0].info[i][j].seatColumn = "";
            plane[0].info[i][j].flightClass = "";
            plane[0].info[i][j].planeNo = 0;
            plane[0].info[i][j].next = nullptr;
        }
    }
    plane[0].occupiedSeats = 0;
    planeCount = 1;
}


// for add Passenger to both structure
void addPassenger(Plane &plane, int r, int c, Passenger p) {
    // 1. Array Update
    plane.info[r][c] = p;
    plane.seat[r][c] = true;
    plane.occupiedSeats++;

    // 2. Linked List Update
    Passenger* newNode = new Passenger;
    *newNode = p; // Copy the data
    newNode->next = head;
    head = newNode;
}


void loadData(string filename) {
    ifstream file(filename);
    
    if (!file.is_open()) {
        cout << "Error: Could not open file " << filename << endl;
        return;
    }

    cout << "\nLoading data..." << endl;

    string line;
    int loadedCount = 0;
    
    getline(file, line);  // ship hearder

    while (getline(file, line)) {
        stringstream ss(line);
        string idStr, name, seatRowStr, seatColumn, flightClass;

        // 1. Parse CSV
        getline(ss, idStr, ',');
        getline(ss, name, ',');
        getline(ss, seatRowStr, ',');
        getline(ss, seatColumn, ',');
        getline(ss, flightClass, ',');
        
        int id = stoi(idStr);
        int seatRow = stoi(seatRowStr);
        int rowIndex = seatRow - 1;
        int colIndex = columnToIndex(seatColumn);

        // passenger info
        Passenger psgInfo;
        psgInfo.id = id;                    
        psgInfo.name = name;                
        psgInfo.seatRow = seatRow;          
        psgInfo.seatColumn = seatColumn;    
        psgInfo.flightClass = flightClass;  
        psgInfo.next = nullptr;

        bool seated = false;

        // 2. Check existing planes for this specific seat
        for (int k = 0; k < planeCount; k++) {
            if (!plane[k].seat[rowIndex][colIndex]) {  // Check if the seat is empty or not

                // if yes then
                psgInfo.planeNo = k + 1; // plane number
                addPassenger(plane[k], rowIndex, colIndex, psgInfo);
                
                loadedCount++;
                seated = true;
                break;
            }
        }

        // 3. If seat was taken in existing planes, create a NEW plane
        if (!seated) {
            int currentPlaneNo = planeCount;

            // Initialize the new plane (Clear memory to be safe)
            for (int r = 0; r < max_rows; r++) {
                for (int c = 0; c < max_cols; c++) {
                    plane[currentPlaneNo].seat[r][c] = false;
                    plane[currentPlaneNo].info[r][c].id = 0;
                    plane[currentPlaneNo].info[r][c].name = "";
                    plane[currentPlaneNo].info[r][c].next = nullptr;
                }
            }
            plane[currentPlaneNo].occupiedSeats = 0;
            planeCount++; // update have one more plane
            psgInfo.planeNo = currentPlaneNo + 1;  // update passenger plane no
            addPassenger(plane[currentPlaneNo], rowIndex, colIndex, psgInfo);
            loadedCount++;
        }
    }
    file.close();
    cout << "\nDone! Loaded " << loadedCount << " passengers into " << planeCount << " planes." << endl;
}


// for visual
void displaySeatMap(int planeNo) {
    // Validate plane number
    if (planeNo < 1 || planeNo > planeCount) {
        cout << "\n > [Error] Invalid plane number! \n > Valid range: 1-" << planeCount << endl;
        return;
    }
    
    int planeIndex = planeNo - 1;  // Convert to array index
    
    cout << "\n============ PLANE " << planeNo << " SEAT MAP ============\n";
    cout << "     A     B     C  \t  D     E     F\n";
    
    for (int row = 0; row < max_rows; row++) {
        cout << setw(2) << (row + 1) << " ";
        
        for (int col = 0; col < 6; col++) {
            if (col == 3) {  
                cout << "\t";
            }
            if (plane[planeIndex].seat[row][col]) cout << "[ R ] "; 
            else cout << "[   ] ";
        }
        cout << endl;
    }
    
    cout << "\nOccupied seats: " << plane[planeIndex].occupiedSeats 
         << " / " << (max_rows * max_cols) << endl;
    cout << "[ R ] = Reserved    [   ] = Empty\n";
}


// display loaded data summary
void displaySummary() {
    if (planeCount == 0) {
        cout << "\nNo planes available.\n";
        return;
    }
    
    int totalSeatsPerPlane = max_rows * max_cols;
    int fullyOccupiedPlanes = 0;
    int availablePlanes = 0;
    int totalPassengers = 0;
    int availablePlaneNumbers[max_planes];  // Store plane numbers with available seats
    int availableIndex = 0;
    
    // Count total passengers from linked list
    Passenger* current = head;
    while (current != nullptr) {
        totalPassengers++;
        current = current->next;
    }
    
    // Calculate statistics
    for (int i = 0; i < planeCount; i++) {
        if (plane[i].occupiedSeats >= totalSeatsPerPlane) {
            fullyOccupiedPlanes++;
        } else {
            availablePlanes++;
            availablePlaneNumbers[availableIndex] = i + 1;  // Store plane number (1-based)
            availableIndex++;
        }
    }
    
    // Display summary
    cout << ".............................................." << endl;
    cout << left << setw(30) << "Total Passengers Loaded:" << totalPassengers << endl;
    cout << left << setw(30) << "Total Planes Created:" << planeCount << endl;
    cout << left << setw(30) << "Fully Occupied Planes:" << fullyOccupiedPlanes << endl;
    cout << left << setw(30) << "Available Planes:" << availablePlanes << endl;
}










