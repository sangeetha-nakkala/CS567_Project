#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <iomanip>
#include <sstream>
#include "libraryproject.h"
#include "libraryproject.cpp"

int main() {
    Library library;
    library.addBook(Book("1984", "George Orwell", 1949, 3));
    library.addBook(Book("To Kill a Mockingbird", "Harper Lee", 1960, 2));
    library.addBook(Book("Catch-22", "Joseph Heller", 1961, 4));
    library.addRoom(Room(101, 4));
    library.addRoom(Room(102, 2));
    library.addRoom(Room(103, 6));

    int choice;
    std::string title, user;
    int roomNumber;

    while (true) {
        displayMenu();
        std::cin >> choice;
        switch (choice) {
            case 1:
                library.listBooks();
                break;
            case 2:
                library.listRooms();
                break;
            case 3:
                std::cout << "Enter the title of the book to check out: ";
                std::cin.ignore();
                getline(std::cin, title);
                library.checkOutBook(title);
                break;
            case 4:
                std::cout << "Enter the title of the book to return: ";
                std::cin.ignore();
                getline(std::cin, title);
                library.returnBook(title);
                break;
            case 5:
                std::cout << "Enter the room number to reserve: ";
                std::cin >> roomNumber;
                std::cout << "Enter your name: ";
                std::cin.ignore();
                getline(std::cin, user);
                library.reserveRoom(roomNumber, user);
                break;
            case 6:
                std::cout << "Enter the room number to cancel the reservation: ";
                std::cin >> roomNumber;
                library.cancelRoomReservation(roomNumber);
                break;
            case 7:
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    }

    return 0;
}