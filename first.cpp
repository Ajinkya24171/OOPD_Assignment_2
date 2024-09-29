#include <iostream>
#include <limits>  // For std::numeric_limits
using namespace std;

const int MAX_MEMBERS = 10;  // Maximum number of people per department

class Person {
public:
    string name;
    string roomNumber;
    string telePhnNo;
    string email;

    Person(string n, string rN, string telephn, string mail)
        : name(n), roomNumber(rN), telePhnNo(telephn), email(mail) {}

    Person() {}

    virtual void display() {
        cout << "Name: " << name << endl;
        cout << "Room Number: " << roomNumber << endl;
        cout << "Telephone: " << telePhnNo << endl;
        cout << "Email: " << email << endl;
    }
};

class Dean : public Person {
    string depart;
public:
    Dean(string n, string rN, string telephn, string mail, string dep)
        : Person(n, rN, telephn, mail), depart(dep) {}

    void display() override {
        Person::display();
        cout << "Dean of department: " << depart << endl;
    }
};

class AssociateDean : public Person {
    string depart;
public:
    AssociateDean(string n, string rN, string telephn, string mail, string dep)
        : Person(n, rN, telephn, mail), depart(dep) {}

    void display() override {
        Person::display();
        cout << "Associate Dean of department: " << depart << endl;
    }
};

class Library : public Person {
    string depart;
public:
    Library(string n, string rn, string telephn, string mail, string dep)
        : Person(n, rn, telephn, mail), depart(dep) {}

    void display() override {
        Person::display();
        cout << "Department is: " << depart << endl;
    }
};

class Department {
public:
    string deptName;
    Person* members[MAX_MEMBERS];  // Storing pointers to base class Person
    int memberCount;  // Track the number of members

    Department(string name) : deptName(name), memberCount(0) {}

    void addMember(Person* p) {
        if (memberCount < MAX_MEMBERS) {
            members[memberCount++] = p;
        } else {
            cout << "Error: Cannot add more members, department is full!" << endl;
        }
    }

    Person* findPerson(string name) {
        for (int i = 0; i < memberCount; i++) {
            // Check for partial matching, case-insensitive
            if (isPartialMatch(members[i]->name, name)) {
                return members[i];
            }
        }
        return nullptr;
    }

    static bool isPartialMatch(const string& fullName, const string& partialName) {
        size_t i = 0, j = 0; // Change int to size_t
        while (i < fullName.length() && j < partialName.length()) {
            // Compare characters case-insensitively
            if (tolower(fullName[i]) == tolower(partialName[j])) {
                j++; // Move to the next character in the partial name
            }
            i++; // Always move to the next character in the full name
        }
        return j == partialName.length(); // Check if all characters in partial name were matched
    }
};

class Administration {
public:
    Department* dep[7];  // Fixed number of departments
    int depCount = 0;

    string registrarName = "Dr. Deepika Bhaskar";
    string registrarRoom = "Room No. B-204 (Academic Block)";
    string registrarPhone = "+91-11-26907419, +91-11-26907410";
    string registrarEmail = "registrar@iiitd.ac.in";

    // Constructor that automatically initializes the departments and members
    Administration() {
        // Create people
        Dean* deanIRD = new Dean("Vivek Ashok Bohara", "Room 101", "+91-11-26907454", "dird@iiitd.ac.in", "IRD");
        Dean* deanCRE = new Dean("Pankaj Vajpayee", "Room 102", "+91-11-26907515", "dcre@iiitd.ac.in", "Corporate Relations & Entrepreneurship (CRE)");
        Dean* deanAlumniAffairs = new Dean("Sonia Baloni Ray", "Room 104", "+91-11-26907424", "dcaa@iiitd.ac.in", "Communication and Alumni Affairs (CAA)");
        Dean* deanAcademicAffairs = new Dean("Sumit J Darak", "Room 105", "+91-11-26907427", "doaa@iiitd.ac.in", "Academic Affairs (AA)");
        Dean* deanStudentAffairs = new Dean("Shobha Sundar Ram", "Room 109", "+91-11-26907460", "dosa@iiitd.ac.in", "Student Affairs (SA)");

        AssociateDean* assocDeanIRD = new AssociateDean("Debarka Sengupta", "Room 106", "+91-11-26907446", "adird@iiitd.ac.in", "IRD");
        AssociateDean* assocDeanFaculty = new AssociateDean("Sanjit Krishnan Kaul", "Room 103", "+91-11-26907457", "adofa@iiitd.ac.in", "Faculty Affairs");

        Library* librarian = new Library("Librarian", "Room 106", "011-678901", "librarian@iiitd.ac.in", "Library");

        // Create departments and add people
        dep[depCount++] = new Department("IRD");
        dep[depCount++] = new Department("Corporate Relations & Entrepreneurship (CRE)");
        dep[depCount++] = new Department("Student Affairs");
        dep[depCount++] = new Department("Faculty Affairs");
        dep[depCount++] = new Department("Communication and Alumni Affairs (CAA)");
        dep[depCount++] = new Department("Academic Affairs (AA)");
        dep[depCount++] = new Department("Library");

        dep[0]->addMember(deanIRD);
        dep[0]->addMember(assocDeanIRD);
        dep[1]->addMember(deanCRE);
        dep[2]->addMember(deanStudentAffairs);
        dep[3]->addMember(assocDeanFaculty);
        dep[4]->addMember(deanAlumniAffairs);
        dep[5]->addMember(deanAcademicAffairs);
        dep[6]->addMember(librarian);
    }

    Person* getPersonDetails(string name) {
        for (int i = 0; i < depCount; i++) {
            Person* person = dep[i]->findPerson(name);
            if (person) {
                return person;
            }
        }
        return nullptr;
    }

    bool isRegistrarMatch(const string& name) {
        return Department::isPartialMatch(registrarName, name); // Call static method from Department
    }
};

/// Main function
int main() {
    Administration admin;

    string personName;
    int choice;

    do {
        cout << "\n1. Search for a person\n2. Exit\nEnter your choice: ";

        // Input validation for choice
        while (true) {
            cin >> choice;

            // Check if input is an integer
            if (cin.fail()) {
                cin.clear(); // Clear the error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                cout << "Invalid input. Please enter 1 or 2: ";
            } else {
                cin.ignore(); // To clear the newline character from the input buffer
                break; // Exit the loop if input is valid
            }
        }

        if (choice == 1) {
            cout << "Enter the name of the person: ";
            getline(cin, personName);

            // Perform partial matching for the registrar
            if (admin.isRegistrarMatch(personName)) {
                cout << "Designation: Registrar" << endl;  // Add designation for registrar
                cout << "Name: " << admin.registrarName << endl;
                cout << "Room Number: " << admin.registrarRoom << endl;
                cout << "Telephone: " << admin.registrarPhone << endl;
                cout << "Email: " << admin.registrarEmail << endl;
            } else {
                // Check for other persons using partial matching
                Person* person = admin.getPersonDetails(personName);
                if (person) {
                    person->display();
                } else {
                    cout << "Person not found!" << endl;
                }
            }
        }
    } while (choice != 2);

    return 0;
}

