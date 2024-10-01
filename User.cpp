#include "User.h"

// Constructors
User::User() : name(""), isTeacher(false), borrowedCount(0)
{
    for (int i = 0; i < MAX_BORROWED_BOOKS; ++i)
    {
        borrowedBooks[i] = nullptr;
    }
}

User::User(const string &name, bool isTeacher) : name(name), isTeacher(isTeacher)
{
    borrowedCount = 0;
}

// Getter functions
string User::getName() const
{
    return name;
}

bool User::isTeacherUser() const
{
    return isTeacher;
}

int User::getBorrowedCount() const
{
    return borrowedCount;
}

int User::getMaxBorrowedBooks() const
{
    return MAX_BORROWED_BOOKS;
}

void User::incrementBorrowedCount()
{
    borrowedCount++;
}

// Function to check if a book is currently borrowed by the user
bool User::isBookBorrowed(Book *book) const
{
    for (int i = 0; i < MAX_BORROWED_BOOKS; ++i)
    {
        if (borrowedBooks[i] == book)
        {
            return true;
        }
    }
    return false;
}

bool User::canBorrowMoreBooks() const
{
    return getBorrowedCount() < MAX_BORROWED_BOOKS;
}

// Function to get the last borrow time for a specific book
time_t User::getLastBorrowTime(const Book *book) const
{
    for (int i = 0; i < MAX_BORROWED_BOOKS; ++i)
    {
        if (borrowedBooks[i] == book)
        {
            return borrowedDates[i];
        }
    }
    return 0; // Return 0 if the book is not found in the user's borrowed books
}

// Function to set the last borrow time for a specific book
void User::setLastBorrowTime(const Book *book, time_t borrowTime)
{
    for (int i = 0; i < MAX_BORROWED_BOOKS; ++i)
    {
        if (borrowedBooks[i] == book)
        {
            borrowedDates[i] = borrowTime;
            return; // Book found and last borrow time updated
        }
    }
}

// Function to get the last borrow time for a specific publication
time_t User::getLastBorrowPubTime(const PublicationRank *publicationRank) const
{
    for (int i = 0; i < MAX_BORROWED_BOOKS; ++i)
    {
        if (borrowedbooks[i] == publicationRank)
        {
            return borrowedDates[i];
        }
    }
    return 0; // Return 0 if the book is not found in the user's borrowed books
}

// Function to set the last borrow time for a specific publication
void User::setLastBorrowPubTime(const PublicationRank *publicationRank, time_t borrowTime)
{
    for (int i = 0; i < MAX_BORROWED_BOOKS; ++i)
    {
        if (borrowedbooks[i] == publicationRank)
        {
            borrowedDates[i] = borrowTime;
            return; // Book found and last borrow time updated
        }
    }
}
