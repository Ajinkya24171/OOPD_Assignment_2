#ifndef JOURNALS_H
#define JOURNALS_H

#include <iostream>
#include <string>
#include "LibraryItem.h"

using namespace std;

class Journals : public LibraryItem
{
private:
    int ID;
    string title;

public:
    // Constructor
    Journals(int ID, const string& title);

    // Getter Functions
    int getID() const;
    string getTitle() const;

    // Overridden Function from LibraryItem
    void printDetails() const override;
};

#endif // JOURNALS_H
