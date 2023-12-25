#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Class to represent a Book
class Book {
public:
    string title;
    string author;
    int year;

    // Constructor
    Book(const string& title, const string& author, int year)
        : title(title), author(author), year(year) {}
};

// Class to represent a Book Management System
class BookManager {
private:
    vector<Book> books;

public:
    // Function to add a book
    void addBook(const string& title, const string& author, int year) {
        books.push_back(Book(title, author, year));
        cout << "Book added successfully.\n";
    }

    // Function to search for a book by title
    void searchBook(const string& title) {
        for (const Book& book : books) {
            if (book.title == title) {
                cout << "Book found:\n";
                displayBook(book);
                return;
            }
        }
        cout << "Book not found.\n";
    }

    // Function to display all books
    void displayAllBooks() {
        if (books.empty()) {
            cout << "No books in the system.\n";
            return;
        }

        cout << "All Books:\n";
        for (const Book& book : books) {
            displayBook(book);
        }
    }

    // Function to display a single book
    void displayBook(const Book& book) {
        cout << "Title: " << book.title << "\n";
        cout << "Author: " << book.author << "\n";
        cout << "Year: " << book.year << "\n\n";
    }
};

int main() {
    BookManager bookManager;

    // Example usage
    bookManager.addBook("The Catcher in the Rye", "J.D. Salinger", 1951);
    bookManager.addBook("To Kill a Mockingbird", "Harper Lee", 1960);

    bookManager.displayAllBooks();

    bookManager.searchBook("To Kill a Mockingbird");

    return 0;
}
