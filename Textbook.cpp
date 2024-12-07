#include "Textbook.h"

Textbook::Textbook()
    : title(""), author(""), year(0), institution(""), studyYear(0), pages(0), price(0.0) {
    cout << "Default constructor called for Textbook\n";
}

Textbook::Textbook(const string& title, const string& author, int year,
                   const string& institution, int studyYear, int pages, double price)
    : title(title), author(author), year(year), institution(institution), studyYear(studyYear), pages(pages), price(price) {
    cout << "Parameterized constructor called for Textbook\n";
}

Textbook::~Textbook() {
    cout << "Destructor called for Textbook\n";
}

void Textbook::input() {
    cout << "Enter title: ";
    cin.ignore();
    getline(cin, title);
    cout << "Enter author: ";
    getline(cin, author);
    cout << "Enter year: ";
    cin >> year;
    cout << "Enter institution: ";
    cin.ignore();
    getline(cin, institution);
    cout << "Enter study year: ";
    cin >> studyYear;
    cout << "Enter pages: ";
    cin >> pages;
    cout << "Enter price: ";
    cin >> price;
}

void Textbook::display() const {
    cout << "Textbook: " << title << " by " << author << ", " << year << endl;
    cout << "Institution: " << institution << ", Study Year: " << studyYear
         << ", Pages: " << pages << ", Price: $" << price << endl;
}

void Textbook::save(ostream& out) const {
    out << "Textbook\n" << title << '\n' << author << '\n' << year << '\n'
        << institution << '\n' << studyYear << '\n' << pages << '\n' << price << '\n';
}

void Textbook::load(istream& in) {
    getline(in, title);
    getline(in, author);
    in >> year;
    in.ignore();
    getline(in, institution);
    in >> studyYear >> pages >> price;
    in.ignore();
}