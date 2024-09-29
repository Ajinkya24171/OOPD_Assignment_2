# IIIT-D Faculty Search System

This project implements a faculty search system for IIIT-Delhi, allowing users to search for and display information about faculty members across different departments.

## Features

- Search for faculty members, HODs, and administrative staff by name
- Display detailed information about each person, including their name, phone number, room number, and designation
- Supports partial and case-insensitive name matching for easier searching
- Implements a class hierarchy to represent different roles within the institution
- Includes data for six departments: ECE, CSE, CSB, CSD, CSAM, and CSSS

## Requirements

- C++17 compatible compiler (e.g., g++)
- Make (for using the provided Makefile)

## Compilation

The project includes a Makefile with targets for both debug and release builds.

To compile the debug version:

```
make debug
```

This will create an executable named `Second_debug`.

To compile the release version:

```
make release
```

This will create an executable named `Second_release`.

To clean up the build files:

```
make clean
```

## Usage

After compiling, run the program:

For debug version:
```
./second_debug
```

For release version:
```
./second_release
```

Follow the on-screen prompts to search for a person or exit the program.

## Project Structure

- `code.cpp`: Main source file containing all the classes and program logic
- `Makefile`: Build script for compiling the project
- `README.md`: This file, containing project information and instructions

## Classes

- `Person`: Represents an individual with their details
- `Department`: Represents a department and manages its members (HOD, Admin Officer, and Faculty)
- `Administration`: Main class that initializes the system and handles searches across all departments

## Notes

- The system is pre-populated with sample data for six departments
- Each department has one HOD, one Administrative Officer, and five faculty members
- The search function supports partial, case-insensitive name matching
- Input validation is implemented to handle invalid user inputs

