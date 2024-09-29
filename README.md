# IIIT-D Complaint Management System

This project implements a complaint management system for IIIT-Delhi, allowing users to register new complaints and check the status of existing complaints. The system includes an escalation mechanism based on the time elapsed since the complaint was filed.

## Features

- Register new complaints for Administrative or Academic departments
- Check the status of existing complaints
- Automatic complaint escalation based on time elapsed
- Unique 4-digit complaint ID generation
- Hierarchical complaint handling structure for each department

## Requirements

- C++17 compatible compiler (e.g., g++)
- Make (for using the provided Makefile)

## Compilation

The project includes a Makefile with targets for both debug and release builds.

To compile the debug version:

```
make debug
```

This will create an executable named `third_debug`.

To compile the release version:

```
make release
```

This will create an executable named `third_release`.

To clean up the build files:

```
make clean
```

## Usage

After compiling, run the program:

For debug version:
```
./third_debug
```

For release version:
```
./third_release
```

Follow the on-screen prompts to register a new complaint or check the status of an existing complaint.

## Project Structure

- `code.cpp`: Main source file containing all the classes and program logic
- `Makefile`: Build script for compiling the project
- `README.md`: This file, containing project information and instructions

## Classes

- `Person`: Base class for all individuals in the system
- `Dean`, `AssociateDean`, `Registrar`, `Faculty`, `HOD`, `AdminOfficer`: Derived classes representing specific roles
- `Complaint`: Represents a complaint with its details and handling logic
- `Administration`: Manages the complaint handling process

## Complaint Escalation

The system automatically escalates complaints based on the time elapsed:

- 0-3 days: Handled by the initial handler
- 4-6 days: Escalated to the next level
- 7+ days: Escalated to the highest level

### Administrative Department Escalation Path
1. Associate Dean
2. Dean
3. Registrar

### Academic Department Escalation Path
1. Faculty
2. HOD (Head of Department)
3. Admin Officer


This project is open-source and available under the MIT License.
