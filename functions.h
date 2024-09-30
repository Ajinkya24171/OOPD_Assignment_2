
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
#include <sstream>
#include <cctype>

// Function to check if a string is numeric
bool isNumeric(const std::string &str);

// Function to split a CSV line into fields based on commas
void splitCSVLine(const std::string &line, std::string fields[], int fieldCount);

// Function to split a line into fields based on newlines
void splitLine(const std::string &line, std::string fields[], int fieldCount);

// Function to split a string into fields based on commas
void splitString(const std::string &input, std::string fields[], int fieldCount);

// Function to validate a username
bool isValidUserName(const std::string &userName);

// Function to get a specific field from a CSV line
std::string getField(const std::string& line, int fieldIndex);

#endif //FUNCTIONS_H
