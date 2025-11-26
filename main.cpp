// main.cpp
// Main driver program for the Library Management System
// Provides a menu-based interface for library operations

#include "Library.h"
#include <iostream>
#include <limits>

// Forward declarations for menu functions
void displayMenu();
void handleAddBook(Library& lib);
void handleRemoveBook(Library& lib);
void handleBorrowBook(Library& lib);
void handleReturnBook(Library& lib);
void handleSearchBooks(Library& lib);
void handleUpdateCopies(Library& lib);
void handleToggleBorrowStatus(Library& lib);
void clearInputBuffer();

int main() {
    // Create our library
    Library myLibrary("Central City Library");
    
    // Pre-populate with some sample books for demonstration
    myLibrary.addBook(Book("978-0-13-468599-1", "The C++ Programming Language", 
                          "Bjarne Stroustrup", "Programming", 2013, 3));
    myLibrary.addBook(Book("978-0-596-80967-3", "Effective Modern C++", 
                          "Scott Meyers", "Programming", 2014, 2));
    myLibrary.addBook(Book("978-0-06-112008-4", "To Kill a Mockingbird", 
                          "Harper Lee", "Fiction", 1960, 5));
    myLibrary.addBook(Book("978-0-7432-7356-5", "1984", 
                          "George Orwell", "Fiction", 1949, 4));
    myLibrary.addBook(Book("978-0-452-28423-4", "The Great Gatsby", 
                          "F. Scott Fitzgerald", "Fiction", 1925, 3));
    
    int choice;
    bool running = true;
    
    std::cout << "\n===== Welcome to " << "Central City Library" << " =====" << std::endl;
    
    // Main program loop
    while (running) {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        
        // Handle invalid input
        if (std::cin.fail()) {
            std::cin.clear();
            clearInputBuffer();
            std::cout << "\nInvalid input. Please enter a number.\n" << std::endl;
            continue;
        }
        
        clearInputBuffer();
        std::cout << std::endl;
        
        // Process user choice
        switch (choice) {
            case 1:
                myLibrary.displayAllBooks();
                break;
            case 2:
                myLibrary.displayAvailableBooks();
                break;
            case 3:
                handleSearchBooks(myLibrary);
                break;
            case 4:
                handleAddBook(myLibrary);
                break;
            case 5:
                handleRemoveBook(myLibrary);
                break;
            case 6:
                handleBorrowBook(myLibrary);
                break;
            case 7:
                handleReturnBook(myLibrary);
                break;
            case 8:
                handleUpdateCopies(myLibrary);
                break;
            case 9:
                handleToggleBorrowStatus(myLibrary);
                break;
            case 10:
                myLibrary.displayLibraryInfo();
                break;
            case 0:
                std::cout << "Thank you for using the Library Management System!" << std::endl;
                running = false;
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n" << std::endl;
        }
    }
    
    return 0;
}

// Display the main menu options
void displayMenu() {
    std::cout << "\n========== Library Management System ==========" << std::endl;
    std::cout << "1.  Display All Books" << std::endl;
    std::cout << "2.  Display Available Books" << std::endl;
    std::cout << "3.  Search Books" << std::endl;
    std::cout << "4.  Add New Book" << std::endl;
    std::cout << "5.  Remove Book" << std::endl;
    std::cout << "6.  Borrow Book" << std::endl;
    std::cout << "7.  Return Book" << std::endl;
    std::cout << "8.  Update Book Copies" << std::endl;
    std::cout << "9.  Toggle Borrow Status" << std::endl;
    std::cout << "10. Display Library Statistics" << std::endl;
    std::cout << "0.  Exit" << std::endl;
    std::cout << "===============================================" << std::endl;
}

// Add a new book to the library
void handleAddBook(Library& lib) {
    std::string isbn, title, author, genre;
    int year, copies;
    
    std::cout << "Enter ISBN: ";
    std::getline(std::cin, isbn);
    
    std::cout << "Enter Title: ";
    std::getline(std::cin, title);
    
    std::cout << "Enter Author: ";
    std::getline(std::cin, author);
    
    std::cout << "Enter Genre: ";
    std::getline(std::cin, genre);
    
    std::cout << "Enter Publication Year: ";
    std::cin >> year;
    
    std::cout << "Enter Number of Copies: ";
    std::cin >> copies;
    
    clearInputBuffer();
    
    // Create book object and add to library
    Book newBook(isbn, title, author, genre, year, copies);
    lib.addBook(newBook);
}

// Remove a book from the catalog
void handleRemoveBook(Library& lib) {
    std::string isbn;
    
    std::cout << "Enter ISBN of book to remove: ";
    std::getline(std::cin, isbn);
    
    lib.removeBook(isbn);
}

// Process a book borrowing request
void handleBorrowBook(Library& lib) {
    std::string isbn;
    
    std::cout << "Enter ISBN of book to borrow: ";
    std::getline(std::cin, isbn);
    
    lib.borrowBook(isbn);
}

// Process a book return
void handleReturnBook(Library& lib) {
    std::string isbn;
    
    std::cout << "Enter ISBN of book to return: ";
    std::getline(std::cin, isbn);
    
    lib.returnBook(isbn);
}

// Search for books using different criteria
void handleSearchBooks(Library& lib) {
    int searchChoice;
    std::string searchTerm;
    
    std::cout << "Search by:" << std::endl;
    std::cout << "1. Title" << std::endl;
    std::cout << "2. Author" << std::endl;
    std::cout << "3. Genre" << std::endl;
    std::cout << "Enter choice: ";
    std::cin >> searchChoice;
    
    clearInputBuffer();
    
    std::cout << "Enter search term: ";
    std::getline(std::cin, searchTerm);
    
    switch (searchChoice) {
        case 1:
            lib.searchByTitle(searchTerm);
            break;
        case 2:
            lib.searchByAuthor(searchTerm);
            break;
        case 3:
            lib.searchByGenre(searchTerm);
            break;
        default:
            std::cout << "Invalid search option." << std::endl;
    }
}

// Modify the number of copies for a book
void handleUpdateCopies(Library& lib) {
    std::string isbn;
    int change;
    
    std::cout << "Enter ISBN: ";
    std::getline(std::cin, isbn);
    
    std::cout << "Enter change in copies (positive to add, negative to remove): ";
    std::cin >> change;
    
    clearInputBuffer();
    
    lib.updateBookCopies(isbn, change);
}

// Change whether a book can be borrowed
void handleToggleBorrowStatus(Library& lib) {
    std::string isbn;
    char choice;
    
    std::cout << "Enter ISBN: ";
    std::getline(std::cin, isbn);
    
    std::cout << "Allow borrowing? (y/n): ";
    std::cin >> choice;
    
    clearInputBuffer();
    
    bool status = (choice == 'y' || choice == 'Y');
    lib.setBorrowStatus(isbn, status);
}

// Clear any remaining characters in input buffer
// Prevents issues with mixing getline and cin
void clearInputBuffer() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}