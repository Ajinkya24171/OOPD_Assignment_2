#include <iostream>
#include <string>
#include <cstdlib> 
#include <ctime>    
using namespace std;

class Person {
public:
    string name;

    Person(string n) : name(n) {}

    virtual void display() {
        cout << "Name: " << name << endl;
    }
};

class Dean : public Person {
public:
    Dean(string n) : Person(n) {}
};

class AssociateDean : public Person {
public:
    AssociateDean(string n) : Person(n) {}
};

class Registrar : public Person {
public:
    Registrar(string n) : Person(n) {}
};

class Faculty : public Person {
public:
    Faculty(string n) : Person(n) {}
};

class HOD : public Person {
public:
    HOD(string n) : Person(n) {}
};

class AdminOfficer : public Person {
public:
    AdminOfficer(string n) : Person(n) {}
};

class Complaint {
public:
    string description;
    Person* initialHandler;
    Person* currentHandler;
    int daysPassed;
    int complaintID;

    Complaint(string desc, Person* handler, int days, int id)
        : description(desc), initialHandler(handler), currentHandler(handler), daysPassed(days), complaintID(id) {}

    // Escalate in Administrative Department
    void escalateAdmin() {
        if (dynamic_cast<AssociateDean*>(currentHandler)) {
            currentHandler = new Dean("Dean: Vivek Ashok Bohara");
        } else if (dynamic_cast<Dean*>(currentHandler)) {
            currentHandler = new Registrar("Registrar: Dr. Deepika Bhaskar");
        }
    }

    // Escalate in Academic Department
    void escalateAcademic() {
        if (dynamic_cast<Faculty*>(currentHandler)) {
            currentHandler = new HOD("HOD: Dr. A V Subramanyam");
        } else if (dynamic_cast<HOD*>(currentHandler)) {
            currentHandler = new AdminOfficer("Admin Officer: Ashutosh Brahma");
        }
    }

    void displayInitialHandler() {
        cout << "Your complaint was originally handled by: " << initialHandler->name << endl;
    }

    void displayCurrentHandler() {
        cout << "Now, after " << daysPassed << " days, your complaint is being handled by: " << currentHandler->name << endl;
    }
};

class Administration {
public:
    void handleComplaint(Complaint& complaint, string department) {
        complaint.displayInitialHandler();  // Display original handler

        if (complaint.daysPassed <= 3) {
            cout << "Your complaint is still in the initial stage with " << complaint.currentHandler->name << endl;
        } 
        else if (complaint.daysPassed > 3 && complaint.daysPassed <= 6) {
            cout << "Since " << complaint.daysPassed << " days have passed, your complaint has been escalated to the next level." << endl;
            if (department == "Administrative") {
                complaint.escalateAdmin();
            } else if (department == "Academic") {
                complaint.escalateAcademic();
            }
            complaint.displayCurrentHandler();  // Display escalated handler
        } 
        else if (complaint.daysPassed > 6) {
            cout << "Since more than 6 days have passed, your complaint has been escalated to the highest level." << endl;
            if (department == "Administrative") {
                complaint.escalateAdmin();
                complaint.escalateAdmin(); // Escalate to the highest level
            } else if (department == "Academic") {
                complaint.escalateAcademic();
                complaint.escalateAcademic(); // Escalate to the highest level
            }
            complaint.displayCurrentHandler();  // Display highest level handler
        }
    }
};

// Function to generate a random 4-digit complaint ID
int generateComplaintID() {
    return rand() % 9000 + 1000;  // Generates a number between 1000 and 9999
}

int main() {
    srand(time(0));  // Seed for random number generation
    int choice, departmentChoice, daysPassed;
    string department, complaintDescription;

    cout << "Welcome to the Complaint System\n";
    cout << "1. Register a new complaint\n2. Check complaint status\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        // New complaint registration
        cout << "Choose department : \n 1: Administrative \n 2: Academic \n";
        cin >> departmentChoice;
        cin.ignore();  // Ignore remaining newline

        // Map department choice
        if (departmentChoice == 1) {
            department = "Administrative";
        } else if (departmentChoice == 2) {
            department = "Academic";
        } else {
            cout << "Invalid choice for department. Please choose 1 or 2." << endl;
            return 1;
        }

        // Input complaint description
        cout << "Enter your complaint description: ";
        getline(cin, complaintDescription);

        // Generate a 4-digit complaint ID
        int complaintID = generateComplaintID();
        cout << "Your complaint has been registered with ID: " << complaintID << endl;

        // Initialize handler to nullptr
        Person* handler = nullptr;

        // Create initial handler based on the department
        if (department == "Administrative") {
            handler = new AssociateDean("Associate Dean: Debarka Sengupta");
        } else if (department == "Academic") {
            handler = new Faculty("Faculty: Dr. Anuj Grover Sir");
        }

        // Create a complaint object
        Complaint complaint(complaintDescription, handler, 0, complaintID);

    } else if (choice == 2) {
        // Check complaint status
        cout << "How many days have passed since the complaint was filed? ";
        cin >> daysPassed;

        // Ask for department to handle escalation
        cout << "Choose department : \n 1: Administrative \n 2: Academic \n";
        cin >> departmentChoice;

        // Map department choice
        if (departmentChoice == 1) {
            department = "Administrative";
        } else if (departmentChoice == 2) {
            department = "Academic";
        } else {
            cout << "Invalid choice for department. Please choose 1 or 2." << endl;
            return 1;
        }

        // Initialize handler to nullptr
        Person* handler = nullptr;

        // For simplicity, using a pre-created handler and complaint (normally would retrieve from a database)
        if (department == "Administrative") {
            handler = new AssociateDean("Associate Dean: Debarka Sengupta");
        } else if (department == "Academic") {
            handler = new Faculty("Faculty: Dr. Anuj Grover  Sir");
        }

        // Example complaint, the actual code would retrieve the complaint using the ID
        Complaint complaint("Sample complaint description", handler, daysPassed, 1234);

        Administration admin;

        // Handle the complaint based on the department and days passed
        admin.handleComplaint(complaint, department);

    } else {
        cout << "Invalid choice. Please select 1 or 2." << endl;
        return 1;
    }

    return 0;
}

