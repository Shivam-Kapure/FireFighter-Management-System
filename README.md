# FireFighter-Management-System

## Overview
This project is a C++ simulation of a firefighting system designed to mimic the structure and duties of a firefighting team. It includes classes for `Person`, `Firefighter`, `Chief`, `Equipment`, and various task-specific actions. This simulation models emergency response, task assignments, and equipment operation in a firefighting scenario.

## Features
- **Chief and Firefighters**: Chief oversees the firefighting team, assigns tasks, and evaluates fire scenes. Firefighters respond to emergencies and operate equipment.
- **Equipment**: Firefighting equipment includes `FireTruck` and `WaterHose`, each with specific properties and functions.
- **Tasks**: Tasks such as `RescueTask` and `FireExtinguishingTask` define unique actions in emergency scenarios.
  
## Class Structure
### 1. `Person`
- **Description**: Base class for all personnel, including attributes like `name`, `age`, and `role`.
- **Methods**: `performDuty()` (abstract), `getName()`, `getRole()`.

### 2. `Firefighter` (inherits from `Person`)
- **Attributes**: `rank`, `assignedStation`.
- **Methods**: `respondToEmergency()`, `operateEquipment()`, and overridden `performDuty()`.

### 3. `Chief` (inherits from `Person`)
- **Attributes**: `yearsOfExperience`.
- **Methods**: `assignTask()`, `evaluateFireScene()`, and overridden `performDuty()`.

### 4. `Equipment`
- **Description**: Base class for all equipment.
- **Attributes**: `equipmentID`, `status`.
- **Methods**: `useEquipment()` (abstract), `checkStatus()`.

### 5. `FireTruck` and `WaterHose` (inherits from `Equipment`)
- **FireTruck**: Attributes like `waterCapacity`, `speed`.
- **WaterHose**: Attributes like `hoseLength`, `pressure`.

### 6. `Task`
- **Description**: Base class for tasks in a firefighting scenario.
- **Attributes**: `taskID`, `description`.
- **Methods**: `executeTask()` (abstract).

### 7. `RescueTask` and `FireExtinguishingTask` (inherits from `Task`)
- **RescueTask**: Attributes like `numberOfPeople`.
- **FireExtinguishingTask**: Attributes like `fireLocation`, `fireSeverity`.

## Usage
To run the simulation:
1. Compile the code with `g++ -o firefighter firefighter.cpp`.
2. Execute the program with `./firefighter`.

### Sample Input
The program will prompt you for input, including details for the Chief, Firefighters, FireTruck, WaterHose, and tasks.

### Sample Output
The program will display simulated actions based on the input data, such as emergency responses, equipment operations, task executions, and evaluations.

## Future Enhancements
- Adding more specific firefighter roles.
- Integrating more equipment types.
- Adding more complex task assignments and evaluations.

## License
This project is unlicensed.
