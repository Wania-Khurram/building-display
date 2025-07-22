# 🏢 Building Management System in C++

A **C++ console-based application** that allows users to input and manage information about a building, including its floors, rooms, and furniture. It demonstrates key programming concepts such as **structs**, **dynamic memory allocation**, and **manual string handling** to simulate a hierarchical structure.

---

## 📌 Features

- Add a **building** with a custom name and ID  
- Add multiple **floors**, each with a name and ID  
- Add multiple **rooms** per floor with room size  
- Add multiple **furniture items** per room with quantities  
- Display complete building information in a structured format  
- Calculate and display the **total area** of each floor and the building  
- Proper memory cleanup using dynamic deallocation  

---

## 🧠 Concepts Used

- `struct` data type  
- Multi-level data hierarchy (Building → Floors → Rooms → Furniture)  
- Dynamic memory allocation (`new`, `delete`)  
- Manual string handling using character arrays and custom functions  
- Nested loops and structured input/output  

---

## 📂 Code Structure

| Component             | Purpose                                           |
|----------------------|---------------------------------------------------|
| `struct Furniture`    | Represents a furniture item (name, quantity)     |
| `struct Room`         | Represents a room (ID, name, size, furniture)    |
| `struct Floor`        | Represents a floor (ID, name, rooms)             |
| `struct Building`     | Represents a building (ID, name, floors)         |
| `add()`               | Inputs all building data from the user           |
| `display()`           | Displays building, floor, room, and furniture info |
| `displayArea()`       | Calculates and displays total area               |
| `deleteMemory()`      | Cleans up all dynamically allocated memory       |

---

## 🖥️ Sample Output

<img width="667" height="573" alt="image" src="https://github.com/user-attachments/assets/34343fdf-b6fc-48bc-95a4-f3e4031611b3" />


---

## 🔧 How to Run

1. **Clone this repository**
   ```bash
   git clone https://github.com/wania-khurram/building-management-system.git
   cd building-management-system
 2. **Compile the code using a C++ compiler**
   ```bash
   g++ main.cpp -o BuildingApp
   ./BuildingApp

