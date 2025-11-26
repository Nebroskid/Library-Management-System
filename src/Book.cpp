// Book.cpp
// Implementation file for Book class
// Contains all the actual logic for book operations

#include "Book.h"
#include <iomanip>

// Constructor implementation
// Initialize all member variables when creating a book object
Book::Book(std::string isbn, std::string title, std::string author, std::string genre, int year, int copies) : isbn(isbn), title(title), author(author), genre(genre), publicationYear(year), totalCopies(copies), availableCopies(copies), isAvailableForBorrow(true) {}

// Try to borrow a book - returns true if successful
bool Book::borrowBook() {
    // Check if borrowing is allowed and copies are available
    if (!isAvailableForBorrow) {
        std::cout << "This book is not available for borrowing." << std::endl;
        return false;
    }

    if (availableCopies > 0) {
        availableCopies--;
        std::cout << "Book borrowed successfully!" << std::endl;
        std::cout << "Remaining copies: " << availableCopies << std::endl;
        return true;
    } else {
        std::cout << "Sorry, no copies available right now." << std::endl;
        return false;
    }
}

// Return a borrowed book
bool Book::returnBook() {
    // Make sure we don’t return more than we own
    if (availableCopies < totalCopies) {
        availableCopies++;
        std::cout << "Book returned successfully!" << std::endl;
        std::cout << "Available copies: " << availableCopies << std::endl;
        return true;
    } else {
        std::cout << "Error: Cannot return more copies than owned." << std::endl;
        return false;
    }
}

// Add more copies to the library’s collection
void Book::addCopies(int count) {
    if (count > 0) {
        totalCopies += count;
        availableCopies += count;
        std::cout << "Added " << count << " copies. Total: " << totalCopies << std::endl;
    } else {
        std::cout << "Invalid number of copies." << std::endl;
    }
}

// Remove copies from inventory (maybe damaged or lost)
bool Book::removeCopies(int count) {
    if (count <= 0) {
        std::cout << "Invalid number of copies." << std::endl;
        return false;
    }

    // Can't remove more copies than we have available
    if (count > availableCopies) {
        std::cout << "Cannot remove " << count << " copies. Only " 
                << availableCopies << " available." << std::endl;
        return false;
    }

    totalCopies -= count;
    availableCopies -= count;
    std::cout << "Removed " << count << " copies. Remaining: " << totalCopies << std::endl;
    return true;
}

// Quick display for lists
void Book::displayInfo() const {
    std::cout << std::left << std::setw(15) << isbn
    << std::setw(30) << title
    << std::setw(20) << author
    << std::setw(6) << availableCopies << "/" << totalCopies
    << std::endl;
}

// Detailed view for individual book
void Book::displayDetailedInfo() const {
    std::cout << "\n========================================" << std::endl;
    std::cout << "ISBN: " << isbn << std::endl;
    std::cout << "Title: " << title << std::endl;
    std::cout << "Author: " << author << std::endl;
    std::cout << "Genre: " << genre << std::endl;
    std::cout << "Publication Year: " << publicationYear << std::endl;
    std::cout << "Total Copies: " << totalCopies << std::endl;
    std::cout << "Available Copies: " << availableCopies << std::endl;
    std::cout << "Borrowing Status: " << (isAvailableForBorrow ? "Available" : "Not Available") << std::endl;
    std::cout << "========================================\n" << std::endl;
}
