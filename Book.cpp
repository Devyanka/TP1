#include "Book.h"

Book::Book() : title(""), author(""), year(0), annotation(""), genre(""), pages(0), price(0.0) {
    cout << "Default constructor called for Book\n";
}

Book::Book(const string& title, const string& author, int year, const string& annotation,
           const string& genre, int pages, double price)
    : title(title), author(author), year(year), annotation(annotation), genre(genre), pages(pages), price(price) {
    cout << "Parameterized constructor called for Book\n";
}

Book::~Book() {
    cout << "Destructor called for Book\n";
}

void Book::input() {
    cout << "Enter title: ";
    cin.ignore();
    getline(cin, title);
    cout << "Enter author: ";
    getline(cin, author);
    cout << "Enter year: ";
    cin >> year;
    cout << "Enter annotation: ";
    cin.ignore();
    getline(cin, annotation);
    cout << "Enter genre: ";
    getline(cin, genre);
    cout << "Enter pages: ";
    cin >> pages;
    cout << "Enter price: ";
    cin >> price;
}

void Book::display() const {
    cout << "Book: " << title << " by " << author << ", " << year << endl;
    cout << "Annotation: " << annotation << ", Genre: " << genre
         << ", Pages: " << pages << ", Price: $" << price << endl;
}

void Book::save(ostream& out) const {
    out << "Book\n" << title << '\n' << author << '\n' << year << '\n'
        << annotation << '\n' << genre << '\n' << pages << '\n' << price << '\n';
}

void Book::load(istream& in) {
    getline(in, title);
    getline(in, author);
    in >> year;
    in.ignore();
    getline(in, annotation);
    getline(in, genre);
    in >> pages >> price;
    in.ignore();
}