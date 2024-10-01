#ifndef BOOK_H
#define BOOK_H

#include "LibraryItem.h"  // Including the base class
#include <string>
#include<iostream>
using namespace std;

class Book : public LibraryItem {
private:
    int ID;
    int book_id;
    int isbn;
    string title;
    string authors;
    int original_publication_year;
    bool borrowed;

public:
    // Constructors
    Book();
    Book(int ID, int book_id, int isbn, const std::string &title, const std::string &authors, int original_publication_year);

    // Getter functions
    int getID() const;
    void setID(int id);
    int getBookID() const;
    void setBookID(int bookid);
    int getISBN() const;
    void setISBN(int Isbn);
    string getTitle() const;
    void setTitle(const std::string &newTitle);
    string getAuthors() const;
    void setAuthors(const std::string &newAuthor);
    int getPublicationYear() const;
    void setPublicationYear(int year);
    bool isBorrowed() const;
    void setBorrowed(bool status);

    // Print details
    void printDetails() const override;
};

#endif
