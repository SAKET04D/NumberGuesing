#include <iostream>

using namespace std;

const int MAX_BOOKS = 5;
const int MAX_BORROWERS = 5;

struct Book
{
    string title;
    string author;
    string isbn;
    bool isAvailable;
};

struct Borrower
{
    string name;
    string id;
};

Book books[MAX_BOOKS];
Borrower borrowers[MAX_BORROWERS];
int bookCount = 0;
int borrowerCount = 0;

void addBook()
{
    if (bookCount >= MAX_BOOKS)
    {
        cout << "Book database is full.\n";
        return;
    }
    cout << "Enter book title: ";
    cin.ignore();
    getline(cin, books[bookCount].title);
    cout << "Enter book author: ";
    getline(cin, books[bookCount].author);
    cout << "Enter book ISBN: ";
    getline(cin, books[bookCount].isbn);
    books[bookCount].isAvailable = true;
    bookCount++;
    cout << "Book added successfully!\n";
}

void searchBook()
{
    string searchTerm;
    cout << "Enter title, author, or ISBN to search: ";
    cin.ignore();
    getline(cin, searchTerm);

    for (int i = 0; i < bookCount; i++)
    {
        if (books[i].title == searchTerm || books[i].author == searchTerm || books[i].isbn == searchTerm)
        {
            cout << "Book found:\n";
            cout << "Title: " << books[i].title << "\n";
            cout << "Author: " << books[i].author << "\n";
            cout << "ISBN: " << books[i].isbn << "\n";
            cout << "Availability: " << (books[i].isAvailable ? "Available" : "Checked Out") << "\n";
            return;
        }
    }
    cout << "Book not found.\n";
}

void checkoutBook()
{
    string isbn;
    cout << "Enter book ISBN to checkout: ";
    cin >> isbn;

    for (int i = 0; i < bookCount; i++)
    {
        if (books[i].isbn == isbn && books[i].isAvailable)
        {
            books[i].isAvailable = false;
            cout << "Book checked out successfully!\n";
            return;
        }
    }
    cout << "Book is either not available or not found.\n";
}

void returnBook()
{
    string isbn;
    cout << "Enter book ISBN to return: ";
    cin >> isbn;

    for (int i = 0; i < bookCount; i++)
    {
        if (books[i].isbn == isbn && !books[i].isAvailable)
        {
            books[i].isAvailable = true;
            cout << "Book returned successfully.\n";
            return;
        }
    }
    cout << "Book is either already returned or not found.\n";
}

void menu()
{
    cout << "\nLibrary Management System\n";
    cout << "1. Add Book\n";
    cout << "2. Search Book\n";
    cout << "3. Checkout Book\n";
    cout << "4. Return Book\n";
    cout << "5. Exit\n";
}

int main()
{
    int choice;
    do
    {
        menu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addBook();
            break;
        case 2:
            searchBook();
            break;
        case 3:
            checkoutBook();
            break;
        case 4:
            returnBook();
            break;
        case 5:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
