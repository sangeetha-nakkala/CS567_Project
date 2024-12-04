#include "libraryproject.h"

std::string getCurrentDateTime() {
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d %X", &tstruct);
    return buf;
}

// Constructor for Book
Book::Book(const std::string& title, const std::string& author, int year, int copies)
    : title(title), author(author), year(year), availableCopies(copies), totalCopies(copies) {}

std::string Book::getTitle() const { return title; }
std::string Book::getAuthor() const { return author; }
int Book::getYear() const { return year; }
int Book::getAvailableCopies() const { return availableCopies; }
int Book::getTotalCopies() const { return totalCopies; }

void Book::checkOut() {
    if (availableCopies > 0) {
        availableCopies--;
        std::cout << "Book checked out: " << title << std::endl;
    } else {
        std::cout << "No copies available to check out: " << title << std::endl;
    }
}

void Book::returnBook() {
    if (availableCopies < totalCopies) {
        availableCopies++;
        std::cout << "Book returned: " << title << std::endl;
    }
}

void Book::addCopies(int additionalCopies) {
    totalCopies += additionalCopies;
    availableCopies += additionalCopies;
    std::cout << "Added " << additionalCopies << " more copies of: " << title << std::endl;
}

// Constructor for Room
Room::Room(int number, int capacity)
    : number(number), capacity(capacity), reserved(false) {}

void Room::reserve(const std::string& user) {
    // Introduce a fault: always set reserved to true
    // Original: if (!reserved) {
    reserved = true;
    reservedBy = user;
    std::cout << "Room " << number << " reserved by " << user << std::endl;
    // } else {
    //     std::cout << "Room " << number << " is already reserved by " << reservedBy << std::endl;
    // }
}

void Room::cancelReservation() {
    if (reserved) {
        std::cout << "Reservation for room " << number << " cancelled." << std::endl;
        reserved = false;
        reservedBy = "";
    } else {
        std::cout << "Room " << number << " is not currently reserved." << std::endl;
    }
}

void Room::updateCapacity(int newCapacity) {
    capacity = newCapacity;
    std::cout << "Updated capacity of room " << number << " to " << capacity << std::endl;
}

void Room::printStatus() const {
    std::cout << "Room " << number << " - Capacity: " << capacity
              << (reserved ? " (Reserved by " + reservedBy + ")" : " (Available)") << std::endl;
}

bool Room::getIsReserved() const { return reserved; }
int Room::getNumber() const { return number; }
int Room::getCapacity() const { return capacity; }
std::string Room::getReservedBy() const { return reservedBy; }

// Library methods
void Library::addBook(const Book& book) {
    books.push_back(book);
}

void Library::checkOutBook(const std::string& title) {
    for (size_t i = 0; i < books.size(); ++i) {
        if (books[i].getTitle() == title && books[i].getAvailableCopies() > 0) {
            books[i].checkOut();
            return;
        }
    }
    std::cout << "Book not available or not found: " << title << std::endl;
}

void Library::returnBook(const std::string& title) {
    for (size_t i = 0; i < books.size(); ++i) {
        if (books[i].getTitle() == title) {
            books[i].returnBook();
            return;
        }
    }
    std::cout << "Book not found or not checked out: " << title << std::endl;
}

void Library::addRoom(const Room& room) {
    rooms.push_back(room);
}

void Library::reserveRoom(int roomNumber, const std::string& userName) {
    for (size_t i = 0; i < rooms.size(); ++i) {
        if (rooms[i].getNumber() == roomNumber) {
            rooms[i].reserve(userName);
            return;
        }
    }
    std::cout << "Room number " << roomNumber << " not found." << std::endl;
}

void Library::cancelRoomReservation(int roomNumber) {
    for (size_t i = 0; i < rooms.size(); ++i) {
        if (rooms[i].getNumber() == roomNumber) {
            rooms[i].cancelReservation();
            return;
        }
    }
    std::cout << "Room number " << roomNumber << " not found." << std::endl;
}

void Library::updateRoomCapacity(int roomNumber, int newCapacity) {
    for (size_t i = 0; i < rooms.size(); ++i) {
        if (rooms[i].getNumber() == roomNumber) {
            rooms[i].updateCapacity(newCapacity);
            return;
        }
    }
    std::cout << "Room number " << roomNumber << " not found." << std::endl;
}

void Library::listRooms() const {
    std::cout << "Room status:" << std::endl;
    for (size_t i = 0; i < rooms.size(); ++i) {
        rooms[i].printStatus();
    }
}

void Library::listBooks() const {
    std::cout << "Book list:" << std::endl;
    for (size_t i = 0; i < books.size(); ++i) {
        std::cout << books[i].getTitle() << " by " << books[i].getAuthor() << ", copies available: " << books[i].getAvailableCopies() << std::endl;
    }
}

void displayMenu() {
    std::cout << "\n* Library Management System *\n";
    std::cout << "1. List all books\n";
    std::cout << "2. List all rooms\n";
    std::cout << "3. Check out a book\n";
    std::cout << "4. Return a book\n";
    std::cout << "5. Reserve a room\n";
    std::cout << "6. Cancel room reservation\n";
    std::cout << "7. Exit\n";
    std::cout << "Enter your choice: ";
}


  
  