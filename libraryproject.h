#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <iomanip>
#include <sstream>

std::string getCurrentDateTime();

class Book {
public:
    Book(const std::string& title, const std::string& author, int year, int copies = 1);
    std::string getTitle() const;
    std::string getAuthor() const;
    int getYear() const;
    int getAvailableCopies() const;
    int getTotalCopies() const;

    void checkOut();
    void returnBook();
    void addCopies(int additionalCopies);

private:
    std::string title;
    std::string author;
    int year;
    int availableCopies;
    int totalCopies;
};

class Room {
public:
    Room(int number, int capacity);
    void reserve(const std::string& user);
    void cancelReservation();
    void updateCapacity(int newCapacity);
    void printStatus() const;

    bool getIsReserved() const;
    int getNumber() const;
    int getCapacity() const;
    std::string getReservedBy() const;

private:
    int number;
    int capacity;
    bool reserved;
    std::string reservedBy;
};

class Library {
public:
    std::vector<Book> books;
    std::vector<Room> rooms;

    void addBook(const Book& book);
    void checkOutBook(const std::string& title);
    void returnBook(const std::string& title);
    void addRoom(const Room& room);
    void reserveRoom(int roomNumber, const std::string& userName);
    void cancelRoomReservation(int roomNumber);
    void updateRoomCapacity(int roomNumber, int newCapacity);
    void listRooms() const;
    void listBooks() const;
};

void displayMenu();

#endif // LIBRARY_H
