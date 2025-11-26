// Library.cpp
// Implementation of Library class
// This is where all the collection management happens

#include "Library.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

// Constructor - initialize library with a name
Library::Library(const std::string& name) : libraryName(name) {
// catalog vector is automatically initialized as empty
}

// Private helper function to locate a book
// Linear search through catalog - simple but works fine for reasonable collection sizes
int Library::findBookIndex(const std::string& isbn) const {
    for (size_t i = 0; i < catalog.size(); i++) {
        if (catalog[i].getISBN() == isbn) {
            return i;  // found it!
        }
    }
    return -1;  // not found
}

// Add a new book to the library
bool Library::addBook(const Book& book) {
    // Check if book with same ISBN already exists
    if (findBookIndex(book.getISBN()) != -1) {
        std::cout << "Book with ISBN " << book.getISBN() << " already exists in catalog." << std::endl;
        return false;
    }

    // Add to catalog using vector's push_back
    catalog.push_back(book);
    std::cout << "Successfully added: " << book.getTitle() << std::endl;
    return true;
}

// Remove a book completely from the catalog
bool Library::removeBook(const std::string& isbn) {
    int index = findBookIndex(isbn);

    if (index == -1) {
        std::cout << "Book not found in catalog." << std::endl;
        return false;
    }

    // Check if any copies are currently borrowed
    if (catalog[index].getAvailableCopies() < catalog[index].getTotalCopies()) {
        std::cout << "Cannot remove book: Some copies are currently borrowed." << std::endl;
        return false;
    }

    // erase removes element at given position
    catalog.erase(catalog.begin() + index);
    std::cout << "Book removed from catalog." << std::endl;
    return true;
}

// Process a book borrowing
bool Library::borrowBook(const std::string& isbn) {
    int index = findBookIndex(isbn);

    if (index == -1) {
        std::cout << "Book not found in catalog." << std::endl;
        return false;
    }

    // Delegate to Book class's borrowBook method
    return catalog[index].borrowBook();

}

// Process a book return
bool Library::returnBook(const std::string& isbn) {
    int index = findBookIndex(isbn);

    if (index == -1) {
        std::cout << "Book not found in catalog." << std::endl;
        return false;
    }

    return catalog[index].returnBook();
}

// Find and return pointer to a book
// Returns nullptr if not found
Book* Library::findBook(const std::string& isbn) {
    int index = findBookIndex(isbn);

    if (index == -1) {
        return nullptr;
    }

    // Return address of the book in catalog
    return &catalog[index];
}

// Display all books in a nice table format
void Library::displayAllBooks() const {
    if (catalog.empty()) {
    std::cout << "The library catalog is empty." << std::endl;
    return;
    }

    std::cout << "\n" << libraryName << " - Complete Catalog" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << std::left << std::setw(15) << "ISBN" << std::setw(30) << "Title" << std::setw(20) << "Author" << "Copies (Avail/Total)" << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    for (const Book& book : catalog) {
        book.displayInfo();
    }
    std::cout << "\nTotal books in catalog: " << catalog.size() << "\n" << std::endl;
}

// Show only books that are currently available to borrow
void Library::displayAvailableBooks() const {
    std::cout << "\n" << libraryName << " - Available Books" << std::endl;
    std::cout << "========================================" << std::endl;

    int count = 0;
    for (const Book& book : catalog) {
        if (book.canBeBorrowed() && book.getAvailableCopies() > 0) {
            book.displayInfo();
            count++;
        }
    }

    if (count == 0) {
        std::cout << "No books currently available for borrowing." << std::endl;
    }
    std::cout << std::endl;
}

// Search for books by title (case-insensitive partial match)
void Library::searchByTitle(const std::string& title) const {
    std::cout << "\nSearch Results for Title: "" << title << """ << std::endl;
    std::cout << "========================================" << std::endl;

    int found = 0;
    for (const Book& book : catalog) {
        // Convert both strings to lowercase for comparison
        std::string bookTitle = book.getTitle();
        std::string searchTerm = title;
        
        // Simple case-insensitive search
        std::transform(bookTitle.begin(), bookTitle.end(), bookTitle.begin(), ::tolower);
        std::transform(searchTerm.begin(), searchTerm.end(), searchTerm.begin(), ::tolower);
        
        if (bookTitle.find(searchTerm) != std::string::npos) {
            book.displayDetailedInfo();
            found++;
        }
    }

    if (found == 0) {
        std::cout << "No books found matching that title." << std::endl;
    } else {
        std::cout << "Found " << found << " matching book(s).\n" << std::endl;
    }
}

// Search by author name
void Library::searchByAuthor(const std::string& author) const {
    std::cout << "\nSearch Results for Author: "" << author << """ << std::endl;
    std::cout << "========================================" << std::endl;

    int found = 0;
    for (const Book& book : catalog) {
        std::string bookAuthor = book.getAuthor();
        std::string searchTerm = author;
        
        std::transform(bookAuthor.begin(), bookAuthor.end(), bookAuthor.begin(), ::tolower);
        std::transform(searchTerm.begin(), searchTerm.end(), searchTerm.begin(), ::tolower);
        
        if (bookAuthor.find(searchTerm) != std::string::npos) {
            book.displayDetailedInfo();
            found++;
        }
    }

    if (found == 0) {
        std::cout << "No books found by that author." << std::endl;
    } else {
        std::cout << "Found " << found << " book(s) by this author.\n" << std::endl;
    }
}

// Search by genre
void Library::searchByGenre(const std::string& genre) const {
    std::cout << "\nSearch Results for Genre: "" << genre << """ << std::endl;
    std::cout << "========================================" << std::endl;

    int found = 0;
    for (const Book& book : catalog) {
        std::string bookGenre = book.getGenre();
        std::string searchTerm = genre;
        
        std::transform(bookGenre.begin(), bookGenre.end(), bookGenre.begin(), ::tolower);
        std::transform(searchTerm.begin(), searchTerm.end(), searchTerm.begin(), ::tolower);
        
        if (bookGenre.find(searchTerm) != std::string::npos) {
            book.displayDetailedInfo();
            found++;
        }
    }

    if (found == 0) {
        std::cout << "No books found in that genre." << std::endl;
    } else {
        std::cout << "Found " << found << " book(s) in this genre.\n" << std::endl;
    }
}

// Modify the number of copies for a book
// Positive change adds copies, negative removes them
bool Library::updateBookCopies(const std::string& isbn, int change) {
    Book* book = findBook(isbn);

    if (book == nullptr) {
        std::cout << "Book not found." << std::endl;
        return false;
    }

    if (change > 0) {
        book->addCopies(change);
        return true;
    } else if (change < 0) {
        return book->removeCopies(-change);  // convert to positive
    } else {
        std::cout << "No change specified." << std::endl;
        return false;
    }
}

// Enable or disable borrowing for a specific book
bool Library::setBorrowStatus(const std::string& isbn, bool status) {
    Book* book = findBook(isbn);

    if (book == nullptr) {
        std::cout << "Book not found." << std::endl;
        return false;
    }

    book->setBorrowStatus(status);
    std::cout << "Borrow status updated to: " 
            << (status ? "Available" : "Not Available") << std::endl;
    return true;

}

// Calculate total copies across all books
int Library::getTotalCopies() const {
    int total = 0;
    for (const Book& book : catalog) {
    total += book.getTotalCopies();
    }
    return total;
}

// Calculate available copies across all books
int Library::getAvailableCopies() const {
    int available = 0;
    for (const Book& book : catalog) {
    available += book.getAvailableCopies();
    }
    return available;
}

// Display library statistics
void Library::displayLibraryInfo() const {
    std::cout << "\n========================================" << std::endl;
    std::cout << "Library: " << libraryName << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "Unique Titles: " << catalog.size() << std::endl;
    std::cout << "Total Copies: " << getTotalCopies() << std::endl;
    std::cout << "Available Copies: " << getAvailableCopies() << std::endl;
    std::cout << "Borrowed Copies: " << (getTotalCopies() - getAvailableCopies()) << std::endl;
    std::cout << "========================================\n" << std::endl;
}
