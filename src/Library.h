// Library.h
// Header file for the Library class
// Manages the entire collection of books and library operations

#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include <vector>
#include <string>

class Library {
    private:
        std::vector<Book> catalog;    // dynamic array to store all books
        std::string libraryName;

        // Helper method to find a book by ISBN
        // Returns -1 if not found, otherwise returns index in catalog
        int findBookIndex(const std::string& isbn) const;

    public:
        // Constructor
        Library(const std::string& name = "City Library");

        // Core library operations
        bool addBook(const Book& book);
        bool removeBook(const std::string& isbn);
        bool borrowBook(const std::string& isbn);
        bool returnBook(const std::string& isbn);

        // Search and display functions
        Book* findBook(const std::string& isbn);
        void displayAllBooks() const;
        void displayAvailableBooks() const;
        void searchByTitle(const std::string& title) const;
        void searchByAuthor(const std::string& author) const;
        void searchByGenre(const std::string& genre) const;

        // Stock management
        bool updateBookCopies(const std::string& isbn, int change);
        bool setBorrowStatus(const std::string& isbn, bool status);

        // Statistics
        int getTotalBooks() const { return catalog.size(); }
        int getTotalCopies() const;
        int getAvailableCopies() const;

        // Display library info
        void displayLibraryInfo() const;
};

#endif
