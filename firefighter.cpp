#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Person {
protected:
    string name;
    int age;
    string role;

public:
    Person(string n, int a, string r) : name(n), age(a), role(r) {}

    virtual void performDuty() = 0; 
    string getName() { return name; }
    string getRole() { return role; }
};

class Firefighter : public Person {
private:
    string rank;
    string assignedStation;

public:
    Firefighter(string n, int a, string r, string rk, string station)
        : Person(n, a, r), rank(rk), assignedStation(station) {}

    void respondToEmergency() {
        cout << "\n--- Emergency Response ---" << endl;
        cout << name << " (Rank: " << rank << ") is responding to an emergency!" << endl;
    }

    void operateEquipment() {
        cout << name << " is operating firefighting equipment." << endl;
    }
    void performDuty() override {
        respondToEmergency();
    }
};

class Chief : public Person {
private:
    int yearsOfExperience;

public:
    Chief(string n, int a, string r, int exp)
        : Person(n, a, r), yearsOfExperience(exp) {}

    void assignTask(Firefighter& f) {
        cout << "\n--- Task Assignment ---" << endl;
        cout << name << " (Chief) is assigning a task to " << f.getName() << "." << endl;
    }

    void evaluateFireScene() {
        cout << "\n--- Fire Scene Evaluation ---" << endl;
        cout << name << " is evaluating the fire scene." << endl;
    }

    void performDuty() override {
        evaluateFireScene();
    }
};

class Equipment {
protected:
    string equipmentID;
    string status;

public:
    Equipment(string id, string s) : equipmentID(id), status(s) {}

    virtual void useEquipment() = 0; 

    void checkStatus() {
        cout << "Equipment " << equipmentID << " status: " << status << endl;
    }
};

class FireTruck : public Equipment {
private:
    int waterCapacity;
    int speed;

public:
    FireTruck(string id, string s, int capacity, int spd)
        : Equipment(id, s), waterCapacity(capacity), speed(spd) {}

    void drive() {
        cout << "\n--- Firetruck Driving ---" << endl;
        cout << "Firetruck is driving at " << speed << " km/h." << endl;
    }

    void sprayWater() {
        cout << "Firetruck is spraying water. Capacity left: " << waterCapacity << " liters." << endl;
    }

    void useEquipment() override {
        drive();
        sprayWater();
    }
};

class WaterHose : public Equipment {
private:
    int hoseLength;
    int pressure;

public:
    WaterHose(string id, string s, int length, int press)
        : Equipment(id, s), hoseLength(length), pressure(press) {}

    void connectToHydrant() {
        cout << "\n--- Water Hose Connection ---" << endl;
        cout << "Water hose is connected to the hydrant." << endl;
    }

    void controlWaterFlow() {
        cout << "Controlling water flow at pressure: " << pressure << " PSI." << endl;
    }

    void useEquipment() override {
        connectToHydrant();
        controlWaterFlow();
    }
};

class Task {
protected:
    string taskID;
    string description;

public:
    Task(string id, string desc) : taskID(id), description(desc) {}

    virtual void executeTask() = 0; 
};

class RescueTask : public Task {
private:
    int numberOfPeople;

public:
    RescueTask(string id, string desc, int people)
        : Task(id, desc), numberOfPeople(people) {}

    void performRescue() {
        cout << "\n--- Rescue Operation ---" << endl;
        cout << "Rescuing " << numberOfPeople << " people from the scene." << endl;
    }

    void executeTask() override {
        performRescue();
    }
};

class FireExtinguishingTask : public Task {
private:
    string fireLocation;
    string fireSeverity;

public:
    FireExtinguishingTask(string id, string desc, string location, string severity)
        : Task(id, desc), fireLocation(location), fireSeverity(severity) {}

    void extinguishFire() {
        cout << "\n--- Fire Extinguishing ---" << endl;
        cout << "Extinguishing fire at " << fireLocation << " with severity level: " << fireSeverity << endl;
    }

    void executeTask() override {
        extinguishFire();
    }
};

int main() {
    // Input Chief details
    string chiefName;
    int chiefAge, chiefExperience;

    cout << "Enter Chief's name: ";
    getline(cin, chiefName);
    cout << "Enter Chief's age: ";
    cin >> chiefAge;
    cout << "Enter Chief's years of experience: ";
    cin >> chiefExperience;
    Chief chief(chiefName, chiefAge, "Chief", chiefExperience);
    
    // Input Firefighters details
    int numFirefighters;
    cout << "\nEnter number of firefighters: ";
    cin >> numFirefighters;

    vector<Firefighter> firefighters;
    for (int i = 0; i < numFirefighters; ++i) {
        string name, rank, station;
        int age;
        
        cout << "\nEnter Firefighter " << i + 1 << " name: ";
        cin.ignore(); // Clear input buffer
        getline(cin, name);
        cout << "Enter age: ";
        cin >> age;
        cout << "Enter rank (e.g., Junior, Senior): ";
        cin.ignore();
        getline(cin, rank);
        cout << "Enter assigned station: ";
        getline(cin, station);
        
        firefighters.push_back(Firefighter(name, age, "Firefighter", rank, station));
    }

    // Input FireTruck details
    string truckID, truckStatus;
    int waterCapacity, speed;

    cout << "\nEnter FireTruck ID: ";
    cin.ignore();
    getline(cin, truckID);
    cout << "Enter FireTruck status (e.g., Operational): ";
    getline(cin, truckStatus);
    cout << "Enter FireTruck water capacity (liters): ";
    cin >> waterCapacity;
    cout << "Enter FireTruck speed (km/h): ";
    cin >> speed;
    FireTruck truck(truckID, truckStatus, waterCapacity, speed);

    // Input WaterHose details
    string hoseID, hoseStatus;
    int hoseLength, hosePressure;

    cout << "\nEnter WaterHose ID: ";
    cin.ignore();
    getline(cin, hoseID);
    cout << "Enter WaterHose status: ";
    getline(cin, hoseStatus);
    cout << "Enter WaterHose length (meters): ";
    cin >> hoseLength;
    cout << "Enter WaterHose pressure (PSI): ";
    cin >> hosePressure;
    WaterHose hose(hoseID, hoseStatus, hoseLength, hosePressure);

    // Input Fire Extinguishing Task details
    string fireTaskID, fireDescription, fireLocation, fireSeverity;

    cout << "\nEnter Fire Extinguishing Task ID: ";
    cin.ignore();
    getline(cin, fireTaskID);
    cout << "Enter task description: ";
    getline(cin, fireDescription);
    cout << "Enter fire location: ";
    getline(cin, fireLocation);
    cout << "Enter fire severity (e.g., High, Medium): ";
    getline(cin, fireSeverity);
    FireExtinguishingTask fireTask(fireTaskID, fireDescription, fireLocation, fireSeverity);

    // Input Rescue Task details
    string rescueTaskID, rescueDescription;
    int numberOfPeople;

    cout << "\nEnter Rescue Task ID: ";
    getline(cin, rescueTaskID);
    cout << "Enter task description: ";
    getline(cin, rescueDescription);
    cout << "Enter number of people to rescue: ";
    cin >> numberOfPeople;
    RescueTask rescueTask(rescueTaskID, rescueDescription, numberOfPeople);

    // Operations
    chief.assignTask(firefighters[0]);  // Assign a task to the first firefighter
    firefighters[0].performDuty();      // First firefighter performs the duty
    truck.useEquipment();               // Firetruck operation
    hose.useEquipment();                // Waterhose operation

    fireTask.executeTask();             // Fire extinguishing task execution
    rescueTask.executeTask();           // Rescue task execution

    chief.evaluateFireScene();          // Chief evaluates the fire scene

    return 0;
}
