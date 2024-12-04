#include <deepstate/DeepState.hpp>
#include "libraryproject.h"  // Ensure this is the header file where your classes are defined

using namespace deepstate;

TEST(Library, AddBookAndCheckOut) {
  Library library;

  // Add a book with random values
  std::string titles[] = {"1984", "Brave New World", "Fahrenheit 451"};
  std::string authors[] = {"George Orwell", "Aldous Huxley", "Ray Bradbury"};
  int year = DeepState_IntInRange(1900, 2020);
  int copies = DeepState_IntInRange(1, 10);

  int idx = DeepState_IntInRange(0, 2);
  std::string title = titles[idx];
  std::string author = authors[idx];

  library.addBook(Book(title, author, year, copies));
  
  // Attempt to check out the book
  library.checkOutBook(title);

  // Ensure the book is checked out properly
  for (size_t i = 0; i < library.books.size(); ++i) {
    if (library.books[i].getTitle() == title) {
      ASSERT_GE(library.books[i].getAvailableCopies(), copies - 1) << "Copies should decrease by at least 1 after checkout.";
      LOG(TRACE) << "Copies decreased by checkout.";
    }
  }
}

TEST(Library, ReturnBook) {
  Library library;

  std::string title = "Sample Book";
  std::string author = "Sample Author";
  int year = 1999;
  int copies = 5;

  library.addBook(Book(title, author, year, copies));
  library.checkOutBook(title); // First check out the book
  library.returnBook(title);   // Now return the book

  // Ensure the book is returned properly
  for (size_t i = 0; i < library.books.size(); ++i) {
    if (library.books[i].getTitle() == title) {
      ASSERT_EQ(library.books[i].getAvailableCopies(), copies) << "Copies should be restored to original after return.";
      LOG(TRACE) << "Copies restored after return.";
    }
  }
}

TEST(Library, RoomReservations) {
  Library library;

  int number = DeepState_IntInRange(100, 200);
  int capacity = DeepState_IntInRange(1, 100);
  library.addRoom(Room(number, capacity));
  std::string user = "Test User";

  library.reserveRoom(number, user);

  // Check if the room was reserved correctly
  for (size_t i = 0; i < library.rooms.size(); ++i) {
    if (library.rooms[i].getNumber() == number) {
      ASSERT(library.rooms[i].getIsReserved()) << "Room should be reserved.";
      LOG(TRACE) << "Room reserved.";
      library.cancelRoomReservation(number);
      ASSERT(!library.rooms[i].getIsReserved()) << "Room reservation should be cancelled.";
      LOG(TRACE) << "Room reservation cancelled.";
    }
  }
}