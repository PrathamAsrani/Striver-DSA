#include <bits/stdc++.h>
using namespace std;

// Book class representing a book in the library
class Book {
    string name;
    string author;
    string ISBN;
    bool isIssued;

public:
    // Constructor
    Book(string name, string author, string ISBN)
        : name(name), author(author), ISBN(ISBN), isIssued(false) {}

    // Getter methods
    string getName() const { return name; }
    string getAuthor() const { return author; }
    string getISBN() const { return ISBN; }

    // Issue a book
    void issue() { isIssued = true; }
    
    // Return a book
    void returnBook() { isIssued = false; }
    
    // Check if a book is issued
    bool checkIssued() const { return isIssued; }
};

// Student class representing a student in the system
class Student {
    string name;
    int studentID;
    vector<Book> borrowedBooks;

public:
    // Constructor
    Student(string name, int id) : name(name), studentID(id) {}

    // Borrow a book
    void borrowBook(Book& book) {
        if (!book.checkIssued()) {
            book.issue();
            borrowedBooks.push_back(book);
            cout << name << " borrowed: " << book.getName() << endl;
        } else {
            cout << book.getName() << " is already issued.\n";
        }
    }

    // Return a book
    void returnBook(Book& book) {
        auto it = find_if(borrowedBooks.begin(), borrowedBooks.end(),
            [&book](const Book& b) { return b.getISBN() == book.getISBN(); });
        
        if (it != borrowedBooks.end()) {
            book.returnBook();
            borrowedBooks.erase(it);
            cout << name << " returned: " << book.getName() << endl;
        } else {
            cout << name << " doesn't have the book: " << book.getName() << endl;
        }
    }

    // Display borrowed books
    void displayBorrowedBooks() const {
        cout << "Books borrowed by " << name << ":\n";
        for (const auto& book : borrowedBooks) {
            cout << "- " << book.getName() << " by " << book.getAuthor() << endl;
        }
    }
};

// Library class managing books and students
class Library {
    vector<Book> books;
    map<int, Student> students;  // Map of student ID to Student object

public:
    // Add book to the library
    void addBook(const Book& book) {
        books.push_back(book);
        cout << book.getName() << " added to the library.\n";
    }

    // Add student to the system
    void addStudent(const Student& student) {
        students[studentID] = student;
        cout << student.getName() << " added to the system.\n";
    }

    // Borrow book
    void issueBook(int studentID, const string& isbn) {
        auto studentIt = students.find(studentID);
        if (studentIt == students.end()) {
            cout << "Student not found.\n";
            return;
        }

        for (auto& book : books) {
            if (book.getISBN() == isbn) {
                studentIt->second.borrowBook(book);
                return;
            }
        }

        cout << "Book with ISBN " << isbn << " not found.\n";
    }

    // Return book
    void returnBook(int studentID, const string& isbn) {
        auto studentIt = students.find(studentID);
        if (studentIt == students.end()) {
            cout << "Student not found.\n";
            return;
        }

        for (auto& book : books) {
            if (book.getISBN() == isbn) {
                studentIt->second.returnBook(book);
                return;
            }
        }

        cout << "Book with ISBN " << isbn << " not found.\n";
    }

    // Display all books
    void displayBooks() const {
        cout << "Books in the library:\n";
        for (const auto& book : books) {
            cout << "- " << book.getName() << " by " << book.getAuthor()
                 << " (ISBN: " << book.getISBN() << ")\n";
        }
    }

    // Display all students
    void displayStudents() const {
        cout << "Students in the system:\n";
        for (const auto& pair : students) {
            cout << "- " << pair.second.getName() << " (ID: " << pair.first << ")\n";
        }
    }
};

int main() {
    Library library;

    // Adding books to the library
    Book b1("The Alchemist", "Paulo Coelho", "123ABC");
    Book b2("To Kill a Mockingbird", "Harper Lee", "456DEF");
    library.addBook(b1);
    library.addBook(b2);

    // Adding students
    Student s1("John Doe", 101);
    Student s2("Jane Smith", 102);
    library.addStudent(s1);
    library.addStudent(s2);

    // Issue and return books
    library.issueBook(101, "123ABC");
    library.issueBook(102, "456DEF");

    library.returnBook(101, "123ABC");

    // Display books and students
    library.displayBooks();
    library.displayStudents();

    return 0;
}
