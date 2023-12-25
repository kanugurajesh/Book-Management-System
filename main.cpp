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

    // Function to delete a book
    void deleteBook(const string& title) {
        for (int i = 0; i < books.size(); i++) {
            if (books[i].title == title) {
                books.erase(books.begin() + i);
                cout << "Book deleted successfully.\n";
                return;
            }
        }
        cout << "Book not found.\n";
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

        cout << "\nAll Books:\n";
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

    int choice = 1;
    string title, author;
    int year;

    while (choice!=0)
    {
        cout << "1. Add Book\n";
        cout << "2. Delete Book\n";
        cout << "3. Search Book\n";
        cout << "4. Display All Books\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the title of the book" << endl;
            cin >> title;
            cout << "Enter the author of the book" << endl;
            cin >> author;
            cout << "Enter the year of the book" << endl;
            cin >> year;
            bookManager.addBook(title, author, year);
            break;
        case 2:
            cin >> title;
            bookManager.deleteBook(title);
            break;
        case 3:
            cin >> title;
            bookManager.searchBook(title);
            break;
        case 4:
            bookManager.displayAllBooks();
            break;
        case 0:
            choice = 0;
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }
    
    return 0;
}
