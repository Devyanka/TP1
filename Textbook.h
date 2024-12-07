#ifndef TEXTBOOK_H
#define TEXTBOOK_H

#include "Base.h"

class Textbook : public Base {
private:
    string title;
    string author;
    int year;
    string institution;
    int studyYear;
    int pages;
    double price;

public:
    Textbook();
    Textbook(const string& title, const string& author, int year,
             const string& institution, int studyYear, int pages, double price);
    ~Textbook();

    void input() override;
    void display() const override;
    void save(ostream& out) const override;
    void load(istream& in) override;
};

#endif // TEXTBOOK_H