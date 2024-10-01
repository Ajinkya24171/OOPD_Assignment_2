#ifndef LIBRARYITEM_H
#define LIBRARYITEM_H




#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <cstring>
#include <cctype>
#include <limits>
#include <chrono>
#include <thread>
#include <iomanip>
using namespace std;
extern int ID;
const int MAX_ITEMS=500;
class LibraryItem {
public:
    // Pure virtual function to print details of the item
    virtual void printDetails() const = 0;

    // Virtual destructor for proper cleanup of derived classes
    virtual ~LibraryItem() {}
};

#endif
