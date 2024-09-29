# IIIT-D Administration System

This project implements a simple administration system for IIIT-Delhi, allowing users to search for and display information about various faculty members and staff.

## Features

- Supports partial name matching for easier searching
- Implements a class hierarchy to represent different roles within the institution

## Requirements

- C++17 compatible compiler (e.g., g++)
- Make (for using the provided Makefile)

## Compilation

The project includes a Makefile with targets for both debug and release builds.

To compile the debug version:

```
make debug
```

This will create an executable named `first_debug`.

To compile the release version:

```
make release
```

This will create an executable named `first_release`.

To clean up the build files:

```
make clean
```

## Usage

After compiling, run the program:

For debug version:
```
./first_debug
```

For release version:
```
./first_release
```

Follow the on-screen prompts to search for a person or exit the program.

## Project Structure

- `first.cpp`: Main source file containing all the classes and program logic
- `Makefile`: Build script for compiling the project
- `README.md`: This file, containing project information and instructions

## Classes

- `Person`: Base class for all individuals in the system
- `Dean`, `AssociateDean`, `Library`: Derived classes representing specific roles
- `Department`: Represents a department and manages its members
- `Administration`: Main class that initializes the system and handles searches

## Notes

- The system is pre-populated with some sample data for demonstration purposes
- The search function supports partial, case-insensitive name matching
- There's a limit of 10 members per department (defined by `MAX_MEMBERS`)
- The system includes 7 pre-defined departments

