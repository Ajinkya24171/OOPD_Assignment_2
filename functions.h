#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>      // For input/output operations (e.g., std::cout)
#include <string>        // For std::string
#include <sstream>       // For std::stringstream and std::istringstream
#include <cctype>        // For std::isdigit, std::isalpha
#include <iomanip>  

using namespace std;

// Function Declarations

// Function to check if a string is numeric
bool isNumeric(const string& str);

// Function to split a CSV line into fields based on commas
void splitCSVLine(const string& line, string fields[], int fieldCount);

// Function to split a line into fields
void splitLine(const string& line, string fields[], int fieldCount);

// Function to split a string into fields based on commas
void splitString(const string& input, string fields[], int fieldCount);

// Function to validate a user name
bool isValidUserName(const string& userName);

// Function to get a specific field from a CSV line by index
string getField(const string& line, int fieldIndex);

#endif // FUNCTION_H
