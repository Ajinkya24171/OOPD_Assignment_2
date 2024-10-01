#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <string>
#include <cctype>
#include <ctime>
#include <thread>
#include <chrono>
#include "LibraryItem.h"
#include "Book.h"
#include "PublicationRank.h"
#include "Journals.h"
#include "User.h"

using namespace std;

class Library
{
private:
    LibraryItem* libraryItems[MAX_ITEMS];
    int itemCount;
    int nextBookId;
    int totalCopies;

    User students[100]; // Assuming a maximum of 100 students
    int studentCount;

    User teachers[50]; // Assuming a maximum of 50 teachers
    int teacherCount;

public:
    // Constructor
    Library();

    // Getter methods
    int getStudentCount() const;
    int getTeacherCount() const;
    int getTotalUsers() const;
    int getTotalItems() const;

    // Library item management
    void addItem(LibraryItem *item);
    void printAllItems() const;
    Book* getBookByID(int bookID) const;
    Book* getBookByIsbn(int bookIsbn) const;
    
    // Search functions
    void searchBooksByAuthor(const std::string &bookAuthor, Book *matchingBooks[], int &matchingCount);
    void searchBooksByTitle(const std::string &bookTitle, Book *matchingBooks[], int &matchingCount);
    void searchPublication(const std::string &publicationName, PublicationRank *matchingBooks[], int &matchingCount);
    void searchJournal(const std::string &journalName, Journals *matchingBooks[], int &matchingCount);

    // User registration
    void registerUser(const std::string &name, bool isTeacher);
    void showAllRegisteredUsers();

    // Utility functions
    bool isEqualIgnoreCase(const std::string &str1, const std::string &str2);
    bool isEqualIgnore(const std::string &str1, const std::string &str2);

    // Book management
    void addBook(int isbn, const std::string &author, const std::string &title, int originalPublicationYear);
    bool borrowBook(const std::string &userName, int bookIdToBorrow);
    bool returnBook(Book *book);
    bool borrowPublication(const std::string &userName, int publication);
    bool returnPub(PublicationRank *publicationRank);
    bool borrowJournal(const std::string &userName, int title);

    // Destructor
    virtual ~Library();
};

#endif // LIBRARY_H
