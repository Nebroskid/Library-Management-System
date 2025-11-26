// Book.h
// Header file for the Book class
// Represents individual books in the library system

#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>

class Book {
    private:
        std::string isbn;           // unique identifier for each book
        std::string title;
        std::string author;
        std::string genre;
        int publicationYear;
        int totalCopies;            // total number of copies library owns
        int availableCopies;        // copies currently available for borrowing
        bool isAvailableForBorrow;  // can this book be borrowed at all?

    public:
        // Constructor with default parameters - makes object creation flexible
        Book(std::string isbn = "", std::string title = "", std::string author = "", std::string genre = "", int year = 0, int copies = 1);

        // Getters - allow read access to private members
        std::string getISBN() const { return isbn; }
        std::string getTitle() const { return title; }
        std::string getAuthor() const { return author; }
        std::string getGenre() const { return genre; }
        int getPublicationYear() const { return publicationYear; }
        int getTotalCopies() const { return totalCopies; }
        int getAvailableCopies() const { return availableCopies; }
        bool canBeBorrowed() const { return isAvailableForBorrow; }

        // Setters - controlled write access to private members
        void setTitle(const std::string& newTitle) { title = newTitle; }
        void setAuthor(const std::string& newAuthor) { author = newAuthor; }
        void setGenre(const std::string& newGenre) { genre = newGenre; }
        void setPublicationYear(int year) { publicationYear = year; }
        void setBorrowStatus(bool status) { isAvailableForBorrow = status; }

        // Core functionality methods
        bool borrowBook();          // attempt to borrow a copy
        bool returnBook();          // return a borrowed copy
        void addCopies(int count);  // increase stock
        bool removeCopies(int count); // decrease stock

        // Display information
        void displayInfo() const;
        void displayDetailedInfo() const;
};

#endif
