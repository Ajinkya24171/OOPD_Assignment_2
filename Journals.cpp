#include "Journals.h"

// Constructor
Journals::Journals(int ID, const string &title)
    : ID(ID), title(title)
{
}

// Getter functions
int Journals::getID() const
{
    return ID;
}

string Journals::getTitle() const
{
    return title;
}

// Print details
void Journals::printDetails() const
{
    cout << "ID: " << ID << "\nJournal Title: " << title << "\n";
}
