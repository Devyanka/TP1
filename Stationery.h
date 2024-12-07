#ifndef STATIONERY_H
#define STATIONERY_H

#include "Base.h"

class Stationery : public Base {
private:
    string type;
    string color;
    string purpose;
    double price;

public:
    Stationery();
    Stationery(const string& type, const string& color, const string& purpose, double price);
    ~Stationery();

    void input() override;
    void display() const override;
    void save(ostream& out) const override;
    void load(istream& in) override;
};

#endif // STATIONERY_H