#include "Stationery.h"

Stationery::Stationery() : type(""), color(""), purpose(""), price(0.0) {
    cout << "Default constructor called for Stationery\n";
}

Stationery::Stationery(const string& type, const string& color, const string& purpose, double price)
    : type(type), color(color), purpose(purpose), price(price) {
    cout << "Parameterized constructor called for Stationery\n";
}

Stationery::~Stationery() {
    cout << "Destructor called for Stationery\n";
}

void Stationery::input() {
    cout << "Enter type: ";
    cin.ignore();
    getline(cin, type);
    cout << "Enter color: ";
    getline(cin, color);
    cout << "Enter purpose: ";
    getline(cin, purpose);
    cout << "Enter price: ";
    cin >> price;
}

void Stationery::display() const {
    cout << "Stationery: " << type << ", Color: " << color
         << ", Purpose: " << purpose << ", Price: $" << price << endl;
}

void Stationery::save(ostream& out) const {
    out << "Stationery\n" << type << '\n' << color << '\n' << purpose << '\n' << price << '\n';
}

void Stationery::load(istream& in) {
    getline(in, type);
    getline(in, color);
    getline(in, purpose);
    in >> price;
    in.ignore();
}