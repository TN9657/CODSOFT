/*Book Database: Store book information (title, author, ISBN) in a
database.
Book Search: Allow users to search for books based on title, author, or
ISBN.
Book Checkout: Enable librarians to check out books to borrowers.
Book Return: Record book returns and update availability status.
Fine Calculation: Implement a fine calculation system for overdue
books.
User Interface: Design a user-friendly interface for easy interaction.

*/
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <ctime>

using namespace std;

struct Book {
    string title;
    string author;
    string ISBN;
    bool isAvailable;
    time_t dueDate;
};

struct Borrower {
    string name;
    vector<string> borrowedBooks;
};

vector<Book> bookDatabase;
vector<Borrower> borrowerDatabase;

void addBook() {
    Book book;
    cout << "Enter book title: ";
    cin.ignore();
    getline(cin, book.title);
    cout << "Enter book author: ";
    getline(cin, book.author);
    cout << "Enter book ISBN: ";
    getline(cin, book.ISBN);
    book.isAvailable = true;
    bookDatabase.push_back(book);
    cout << "Book added successfully!" << endl;
}

void searchBook() {
    string query;
    cout << "Enter title, author, or ISBN to search: ";
    cin.ignore();
    getline(cin, query);

    bool found = false;
    for (const auto& book : bookDatabase) {
        if (book.title == query || book.author == query || book.ISBN == query) {
         cout << "Book found: " << book.title << " by " << book.author << ", ISBN: " << book.ISBN << (book.isAvailable ? " (Available)" : " (Checked out)") << endl;
          found = true;
        }
    }
    if (!found) {
        cout << "No book found matching the query." << endl;
    }
}

void checkOutBook() {
    string ISBN, borrowerName;
    cout << "Enter book ISBN to check out: ";
    cin.ignore();
    getline(cin, ISBN);
    cout << "Enter borrower's name: ";
    getline(cin, borrowerName);

    for (auto& book : bookDatabase) {
        if (book.ISBN == ISBN && book.isAvailable) {
            book.isAvailable = false;
            time_t now = time(0);
            book.dueDate = now + 30 * 24 * 60 * 60; 
            bool borrowerFound = false;
            for (auto& borrower : borrowerDatabase) {
                if (borrower.name == borrowerName) {
                    borrower.borrowedBooks.push_back(ISBN);
                    borrowerFound = true;
                    break;
                }
            }
            if (!borrowerFound) {
                Borrower borrower;
                borrower.name = borrowerName;
                borrower.borrowedBooks.push_back(ISBN);
                borrowerDatabase.push_back(borrower);
            }

            cout << "Book checked out successfully!" << endl;
            cout<<"Coution: If you cannot Return the book in 30 days\nYou will have to pay fine for it......."<<endl;
            return;
        }
    }
    cout << "Book not available or not found." << endl;
}

void returnBook() {
    string ISBN;
    cout << "Enter book ISBN to return: ";
    cin.ignore();
    getline(cin, ISBN);

    for (auto& book : bookDatabase) {
        if (book.ISBN == ISBN && !book.isAvailable) {
            book.isAvailable = true;

            time_t now = time(0);
            double overdueDays = difftime(now, book.dueDate) / (60 * 60 * 24);
            if (overdueDays > 0) {
                cout << "Book is overdue by " << overdueDays << " days.  Fine: $" << fixed << setprecision(2) << overdueDays * 0.50 << endl;
            } else {
                cout << "Book returned on time." << endl;
            }

            for (auto& borrower : borrowerDatabase) {
                for (auto it = borrower.borrowedBooks.begin(); it != borrower.borrowedBooks.end(); ++it) {
                    if (*it == ISBN) {
                        borrower.borrowedBooks.erase(it);
                        break;
                    }
                }
            }

            return;
        }
    }
    cout << "Book not found or not checked out." << endl;
}

void displayMenu() {
    cout << "1. Add Book" << endl;
    cout << "2. Search Book" << endl;
    cout << "3. Check Out Book" << endl;
    cout << "4. Return Book" << endl;
    cout << "5. Exit" << endl;
}

int main() {
    int choice;
    while (true) {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                searchBook();
                break;
            case 3:
                checkOutBook();
                break;
            case 4:
                returnBook();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}
