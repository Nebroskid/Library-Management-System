# Library Management System

![language](https://img.shields.io/badge/language-C++11-blue)
![status](https://img.shields.io/badge/status-In%20Progress-orange)

A comprehensive C++ application demonstrating object-oriented programming principles through a functional library management system.

## 📚 Project Overview

This project implements a library management system with full CRUD operations for book management, borrowing/returning functionality, and search capabilities. It’s designed to showcase fundamental OOP concepts and practical programming skills.

## 🎯 Key Features

- **Book Management**: Add, remove, and update books in the catalog
- **Inventory Control**: Track total and available copies for each book
- **Borrowing System**: Process book checkouts and returns
- **Search Functionality**: Search by title, author, or genre
- **Status Management**: Toggle borrowing availability for individual books
- **Statistical Reports**: View library statistics and inventory summaries

## 🏗️ Architecture & OOP Concepts Demonstrated

### Encapsulation

- Private data members with controlled access through public getters/setters
- Implementation details hidden from users of the classes

### Abstraction

- High-level interface for library operations
- Complex operations simplified into intuitive method calls

### Class Design

- **Book Class**: Represents individual books with all relevant attributes
- **Library Class**: Manages collection of books and provides library-level operations
- Clear separation of concerns between data (Book) and management (Library)

### Data Structures

- `std::vector` for dynamic book storage
- Efficient searching and iteration through collections

### Const Correctness

- Proper use of `const` methods that don’t modify object state
- Const references in parameters to avoid unnecessary copying

## 📁 File Structure

```
Library-Management-System/
│
├── src/
│   ├── Book.h              # Book class declaration
│   ├── Book.cpp            # Book class implementation
│   ├── Library.h           # Library class declaration
│   ├── Library.cpp         # Library class implementation
│   └── main.cpp            # Main program with menu interface
│
└── .github/
    └── workflows/
        └── c-cpp.yml
```

## 🔧 Installation
Ensure you have a C++ compiler installed:
- macOS: Xcode command line tools
- Linux: g++
- Windows: MinGW or Visual Studio

## 🔧 Compilation

### Using g++ (Linux/Mac):

```bash
g++ -std=c++11 main.cpp Book.cpp Library.cpp -o Library
./Library
```

### Using g++ (Windows):

```bash
g++ -std=c++11 main.cpp Book.cpp Library.cpp -o Library.exe
Library.exe
```

### Using Visual Studio:

1. Create a new C++ Console Application project
1. Add all .cpp and .h files to the project
1. Build and run (F5)

## 💡 Usage Example

The system provides an interactive menu:

1. View all books in catalog
1. View available books only
1. Search by title, author, or genre
1. Add new books to catalog
1. Remove books from catalog
1. Borrow books (decrements available copies)
1. Return books (increments available copies)
1. Update inventory (add/remove copies)
1. Toggle borrowing status
1. View library statistics

## 🎓 Learning Outcomes

This project demonstrates understanding of:

- **Class design and implementation**
- **Memory management** (stack allocation, references, pointers)
- **STL containers** (vector)
- **Input/output handling** and formatting
- **Search algorithms** (linear search)
- **String manipulation** and case-insensitive comparison
- **Error handling** and validation
- **Multi-file project organization**
- **Header guards** to prevent multiple inclusion
- **Const correctness** throughout the codebase

## 🔍 Technical Highlights

### Initializer Lists

Uses initializer lists in constructors for efficient member initialization

### Range-Based For Loops

Leverages C++11 range-based loops for cleaner iteration

### Error Checking

Comprehensive validation of user input and operations

### Modular Design

Clear separation between interface (.h) and implementation (.cpp)

## 🚀 Future Enhancements (For Discussion)

- Member/user management system
- Due date tracking for borrowed books
- Fine calculation for late returns
- File persistence (save/load library data)
- Sorting capabilities (by title, author, year)
- ISBN validation
- Database integration

## 📝 Code Quality

- Descriptive variable and function names
- Comprehensive inline comments explaining logic
- Consistent formatting and indentation
- Defensive programming practices
- Clear separation of concerns

-----

**Author Note**: This project is designed to demonstrate solid understanding of C++ fundamentals and OOP principles. The code prioritizes clarity, maintainability, and proper object-oriented design over advanced features, making it an excellent portfolio piece for entry to mid-level positions.
