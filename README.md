<img width="1710" height="1107" alt="Screenshot 2026-03-26 at 3 15 32 PM" src="https://github.com/user-attachments/assets/329e1098-2eba-44c3-9847-80ed5ca38712" /># ✈️ Flight Reservation & Seating Management System

A C++ implementation of a flight reservation system using two data structure approaches: **Array-based** and **Linked List-based**, with performance comparison between both.

---

## 📌 Project Overview

Modern airlines depend on efficient digital systems to manage passenger bookings, seat allocation, and flight manifests. This project simulates a Flight Reservation & Seating Management Component that handles:

- Seat reservations and cancellations
- Passenger lookup by ID
- Full seating chart and manifest display
- Performance comparison between static (array) and dynamic (linked list) data structures

---

## 🗂️ Features

### Array-Based Component
- 2D array for seat assignment grid
- 1D array for passenger records
- Index-based fast seat access
- Sorting and filtering by row or class

### Linked List-Based Component
- Singly/Doubly linked list for dynamic passenger records
- Node-based insertion, deletion, searching, and traversal
- Flexible memory allocation

### Core Functionalities (Both Versions)
| Function | Description |
|---|---|
| **Reservation** | Allocate an available seat to a new passenger |
| **Cancellation** | Remove a passenger by PassengerID and free the seat |
| **Seat Lookup** | Retrieve passenger details using PassengerID |
| **Manifest & Seat Report** | Display full seating chart and passenger list |

---

## 📊 Performance Evaluation

| Operation | Array | Linked List |
|---|---|---|
| Search | O(n) | O(n) |
| Insertion | O(1) (by index) | O(1) (at head/tail) |
| Deletion | O(n) | O(n) |
| Memory | Static allocation | Dynamic allocation |

---

## 📁 Dataset

- `flight_passenger_data.csv` — Contains passenger booking records
  - Fields: `PassengerID`, `Name`, `SeatRow`, `SeatColumn`, `Class`

---

## 🛠️ Tech Stack

- Language: **C++**
- No STL containers (`<vector>`, `<list>`) — all data structures are custom-built

---

## 🚀 How to Run
```bash
# Compile
g++ -o main main.cpp

# Run
./main
```

Make sure `flight_passenger_data.csv` is in the same directory as the executable.

---

## 👥 Team Members

| Member | Role |
|---|---|
| Chan Xin Quan | Seat Report |
| Chen Zheng Hao | Cancel Seat (Deletion) |
| Kaemon Ng | Reserve Seat (Insertion) |
| Sawraw Madub | Search Seat |

---

## 📂 File Structure
```
cpp-flight-system-data-structure-full-version-v1/
├── array.cpp                    # Array-based reservation implementation
├── array.hpp                    # Array class header
├── linked_list.cpp              # Linked list-based reservation implementation
├── linked_list.hpp              # Linked list class header
├── passenger.cpp                # Passenger data model implementation
├── passenger.hpp                # Passenger class header
├── main.cpp                     # Driver program
└── flight_passenger_data.csv    # Dataset
```
