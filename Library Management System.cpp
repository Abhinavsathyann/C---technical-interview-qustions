#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Book {
    int id;
    string title;
    string author;
    bool isIssued;
};

class Library {
    vector<Book> books;

public:
    void addBook(int id, string title, string author) {
        books.push_back({id, title, author, false});
    }

    void issueBook(int id) {
        for (auto &b : books) {
            if (b.id == id && !b.isIssued) {
                b.isIssued = true;
                cout << "Book issued successfully.\n";
                return;
            }
        }
        cout << "Book not found or already issued.\n";
    }

    void returnBook(int id) {
        for (auto &b : books) {
            if (b.id == id && b.isIssued) {
                b.isIssued = false;
                cout << "Book returned successfully.\n";
                return;
            }
        }
        cout << "Invalid return attempt.\n";
    }

    void showBooks() {
        cout << "\nAvailable Books:\n";
        for (auto &b : books)
            cout << b.id << " - " << b.title << " by " << b.author
                 << (b.isIssued ? " [Issued]" : " [Available]") << endl;
    }
};

int main() {
    Library lib;
    lib.addBook(1, "C++ Basics", "Bjarne Stroustrup");
    lib.addBook(2, "Algorithms", "CLRS");

    lib.showBooks();
    lib.issueBook(1);
    lib.showBooks();
    lib.returnBook(1);
    lib.showBooks();
    return 0;
}
