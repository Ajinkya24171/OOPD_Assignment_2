#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

class Person {
public:
    char name[50];
    char phoneNumber[20];
    char roomNumber[20];
    char designation[20];

    Person() {}
    Person(const char* n, const char* p, const char* r, const char* d) {
        strncpy(name, n, sizeof(name));
        strncpy(phoneNumber, p, sizeof(phoneNumber));
        strncpy(roomNumber, r, sizeof(roomNumber));
        strncpy(designation, d, sizeof(designation));
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Phone Number: " << phoneNumber << endl;
        cout << "Room Number: " << roomNumber << endl;
        cout << "Designation: " << designation << endl;
    }
};

void toLower(const char* str, char* result) {
    for (int i = 0; str[i] != '\0'; ++i) {
        result[i] = tolower(str[i]);
    }
    result[strlen(str)] = '\0'; // Null-terminate the string
}

class Department {
private:
    Person hod;
    Person adminOfficer;
    Person faculty[5];

public:
    Department(Person h, Person admin, Person facs[5]) : hod(h), adminOfficer(admin) {
        for (int i = 0; i < 5; ++i) {
            faculty[i] = facs[i];
        }
    }

    Person* findPerson(const char* name) {
        char lowerName[50];
        char lowerHod[50], lowerAdmin[50];

        toLower(name, lowerName);
        toLower(hod.name, lowerHod);
        toLower(adminOfficer.name, lowerAdmin);

        if (strstr(lowerHod, lowerName) != nullptr) return &hod;
        if (strstr(lowerAdmin, lowerName) != nullptr) return &adminOfficer;

        for (int i = 0; i < 5; ++i) {
            char lowerFaculty[50];
            toLower(faculty[i].name, lowerFaculty);
            if (strstr(lowerFaculty, lowerName) != nullptr) return &faculty[i];
        }
        return nullptr;
    }
};

class Administration {
private:
    Department* departments[6];

public:
    Administration() {
        // ECE Department
        Person hodECE("Dr. A V Subramanyam", "+91 011-26907437", "Room B-604", "HOD");
        Person adminECE("Sanjna Khosla", "011 2690 7593", "Room A-601", "Admin");
        Person facultyECE[5] = {
            Person("Abhijit Mitra", "011-26907450", "Room A-605", "Professor"),
            Person("Anuj Grover", "011-26907494", "Room A-610", "Professor"),
            Person("Sneh Saurabh", "011-26907456", "Room B-608", "Professor"),
            Person("Sujay Deb", "011-26907452", "Room A-607", "Professor"),
            Person("Sumit J Darak", "011-26907427", "Room B-605", "Professor")
        };
        departments[0] = new Department(hodECE, adminECE, facultyECE);

        // CSE Department
        Person hodCSE("Sambuddho Chakravarty", "011-26907478", "Room B-503", "HOD");
        Person adminCSE("Priti Patwal", "01126907411", "Room A-501", "Admin");
        Person facultyCSE[5] = {
            Person("Arani Bhattacharya", "011-26907434", "Room B-510", "Professor"),
            Person("Debajyoti Bera", "011-26907442", "Room B-508", "Professor"),
            Person("Bapi Chatterjee", "011-26907371", "Room B-402", "Professor"),
            Person("Pankaj Jalote", "011-26907499", "Room A-705", "Professor"),
            Person("Saket Anand", "011-26907425", "Room B-410", "Professor")
        };
        departments[1] = new Department(hodCSE, adminCSE, facultyCSE);

        // CSB Department
        Person hodCSB("GPS Raghava", "011-26907444", "Room A-302", "HOD");
        Person adminCSB("Shipra Jain", "333-2222", "Room A-301", "Admin");
        Person facultyCSB[5] = {
            Person("Arjun Ray", "011-26907438", "Room A-310", "Professor"),
            Person("Ganesh Bagler", "01126907443", "Room A-305", "Professor"),
            Person("Gaurav Ahuja", "01126907375", "Room A-303", "Professor"),
            Person("Jaspreet Kaur Dhanjal", "01126907522", "Room A-307", "Professor"),
            Person("N. Arul Murugan", "01126907372", "Room A-311", "Professor")
        };
        departments[2] = new Department(hodCSB, adminCSB, facultyCSB);

        // CSD Department
        Person hodCSD("Dr. Aman Parnami", "444-1111", "Room 401", "HOD");
        Person adminCSD("Binu Ann Joseph", "444-2222", "Room 402", "Admin");
        Person facultyCSD[5] = {
            Person("Dr. Anmol Srivastava", "444-3333", "Room 403", "Professor"),
            Person("Dr. Richa Gupta", "444-4444", "Room 404", "Professor"),
            Person("Dr. Kalpana Shankhwar", "444-5555", "Room 405", "Professor"),
            Person("Dr. Jainendra Shukla", "444-6666", "Room 406", "Professor"),
            Person("Dr. Rajiv Ratn Shah", "444-7777", "Room 407", "Professor")
        };
        departments[3] = new Department(hodCSD, adminCSD, facultyCSD);

        // CSAM Department
        Person hodCSAM("Kaushik Kalyanaraman", "011-26907456", "Room B-302", "HOD");
        Person adminCSAM("Risha Lal", "011-26907548", "Room B-301", "Admin");
        Person facultyCSAM[5] = {
            Person("Anuradha Sharma", "555-3333", "Room 503", "Professor"),
            Person("Manuj Mukherjee", "555-4444", "Room 504", "Professor"),
            Person("Monika Arora", "555-5555", "Room 505", "Professor"),
            Person("Nabanita Ray", "555-6666", "Room 506", "Professor"),
            Person("Debika Banerjee", "555-7777", "Room 507", "Professor")
        };
        departments[4] = new Department(hodCSAM, adminCSAM, facultyCSAM);

        // CSSS Department
        Person hodCSSS("J. V. Meenakshi", "011 26907 535", "Room B-205", "HOD");
        Person adminCSSS("Rubina Thakur", "91 11 2690 7497", "Room B-201", "Admin");
        Person facultyCSSS[5] = {
            Person("Manohar Kumar", "011 26907 557", "Room B-207", "Professor"),
            Person("Mrinmoy Chakrabarty", "011 26907 363", "Room A-202", "Professor"),
            Person("Nishad Patnaik", "011 26907 364", "Room A-205", "Professor"),
            Person("Paro Mishra", "011 26907 570", "Room A-209", "Professor"),
            Person("Praveen Priyadarshi", "011 26907 359", "Room A-203", "Professor")
        };
        departments[5] = new Department(hodCSSS, adminCSSS, facultyCSSS);
    }

    Person* getPersonDetails(const char* name) {
        for (int i = 0; i < 6; ++i) {
            Person* person = departments[i]->findPerson(name);
            if (person) return person;
        }
        return nullptr;
    }
};

int main() {
    Administration admin;
    int choice;
    char personName[50];

    while (true) {
        cout << "\n1. Search for a person\n2. Exit\nEnter your choice: ";
        
        // Check if input is valid
        if (!(cin >> choice)) {
            cin.clear(); // Clear error flag
            cin.ignore(10000, '\n'); // Discard invalid input
            cout << "Invalid input. Please enter 1 or 2." << endl;
            continue; // Go to the next iteration of the loop
        }
        
        cin.ignore();  // Clear the newline character from input buffer

        if (choice == 1) {
            cout << "Enter the name of the person to search: ";
            cin.getline(personName, sizeof(personName));

            Person* person = admin.getPersonDetails(personName);
            if (person) {
                person->display();
            } else {
                cout << "Person not found." << endl;
            }
        } else if (choice == 2) {
            break; // Exit the loop
        } else {
            cout << "Invalid choice. Please enter 1 or 2." << endl;
        }
    }
    return 0;
}

