#ifndef BOOK_H
#define BOOK_H

#include "Base.h"

class Book : public Base {
private:
    string title;
    string author;
    int year;
    string annotation;
    string genre;
    int pages;
    double price;

public:
    Book();
    Book(const string& title, const string& author, int year, const string& annotation,
         const string& genre, int pages, double price);
    ~Book();

    void input() override;
    void display() const override;
    void save(ostream& out) const override;
    void load(istream& in) override;
};

#endif // BOOK_H