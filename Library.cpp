#include "Library.h"
#include "classFunction.h"

    // / Constructor
Library::Library() : itemCount(0), studentCount(0), teacherCount(0)
{
    nextBookId = 100;
    totalCopies = 1;
}

int Library::getStudentCount() const
{
    return studentCount;
}

int Library::getTeacherCount() const
{
    return teacherCount;
}

int Library::getTotalUsers() const
{
    return studentCount + teacherCount;
}

int Library::getTotalItems() const
{
    return itemCount;
}

void Library::addItem(LibraryItem *item)
{
    if (itemCount < MAX_ITEMS)
    {
        libraryItems[itemCount] = item;
        itemCount++;
    }
    else
    {
        cout << "Library is full. Cannot add more items." << endl;
    }
}

void Library::printAllItems() const
{
    for (int i = 0; i < itemCount; ++i)
    {
        if (libraryItems[i])
        {
            libraryItems[i]->printDetails();
            cout << "------------------------\n";
        }
    }
}

Book *Library::getBookByID(int bookID) const
{
    for (int i = 0; i < itemCount; i++)
    {
        Book *book = dynamic_cast<Book *>(libraryItems[i]);
        if (book && book->getBookID() == bookID)
        {
            return book; // Found the book with the specified ID
        }
    }
    return nullptr; // Book with the specified ID not found
}

Book *Library::getBookByIsbn(int bookIsbn) const
{
    for (int i = 0; i < itemCount; i++)
    {
        Book *book = dynamic_cast<Book *>(libraryItems[i]);
        if (book && book->getISBN() == bookIsbn)
        {
            return book; // Found the book with the specified Isbn
        }
    }
    return nullptr; // Book with the specified Isbn not found
}

    void searchBooksByAuthor(const string &bookAuthor, Book *matchingBooks[], int &matchingCount);
    void searchBooksByTitle(const string &bookAuthor, Book *matchingBooks[], int &matchingCount);
    void searchPublication(const string &bookAuthor, PublicationRank *matchingBooks[], int &matchingCount);
    void searchJournal(const string &bookAuthor, Journals *matchingBooks[], int &matchingCount);

   void Library::registerUser(const string &name, bool isTeacher)
{
    if (isTeacher)
    {
        teachers[teacherCount++] = User(name, true);
        cout << "Registered as a Teacher." << endl;
    }
    else
    {
        students[studentCount++] = User(name, false);
        cout << "Registered as a Student." << endl;
    }
    cout << "-------------------------" << endl;
}

void Library::showAllRegisteredUsers()
{
    cout << "Registered Students:" << endl;
    for (int i = 0; i < studentCount; ++i)
    {
        cout << students[i].getName() << endl;
    }

    cout << "Registered Teachers:" << endl;
    for (int i = 0; i < teacherCount; ++i)
    {
        cout << teachers[i].getName() << endl;
    }
    cout << "-------------------------" << endl;
}

bool Library::isEqualIgnoreCase(const string &str1, const string &str2)
{
    // Compare two strings case-insensitively
    if (str1.size() != str2.size())
    {
        return false;
    }

    for (size_t i = 0; i < str1.size(); ++i)
    {
        if (tolower(str1[i]) != tolower(str2[i]))
        {
            return false;
        }
    }

    return true;
}

bool Library::isEqualIgnore(const string &str1, const string &str2)
{
    // Check if the lengths of the strings are equal
    if (str1.length() != str2.length())
    {
        return false;
    }

    // Compare characters case-insensitively
    for (size_t i = 0; i < str1.length(); ++i)
    {
        if (tolower(str1[i]) != tolower(str2[i]))
        {
            return false;
        }
    }

    return true;
}

void Library::addBook(int isbn, const string &author, const string &title, int originalPublicationYear)
{
    if (itemCount >= MAX_ITEMS)
    {
        cout << "The library is full. Cannot add more books." << endl;
        return;
    }

    // Create a new Book object with the next available book ID
    Book *newBook = new Book();
    newBook->setID(ID++);
    newBook->setBookID(nextBookId++);
    newBook->setISBN(isbn);
    newBook->setAuthors(author);
    newBook->setTitle(title);
    newBook->setPublicationYear(originalPublicationYear);

    // Add the new book to the library
    addItem(newBook);

    cout << "Added book with ID " << newBook->getBookID() << " to the library." << endl;
}

bool borrowBook(const string &userName, int bookIdToBorrow);


bool returnBook(Book *book);

bool borrowPublication(const string &userName, int publication);

bool returnPub(PublicationRank *publicationRank);

bool borrowJournal(const string &userName, int title);


Library::~Library()
{
    // Destructor implementation if needed
}
