#include "Keeper.h"
#include "Book.h"
#include "Textbook.h"
#include "Stationery.h"
#include <iostream>

using namespace std;

Keeper::Keeper() : items(nullptr), size(0), capacity(2) {
    items = new Base*[capacity];
    cout << "Keeper created.\n";
}

Keeper::~Keeper() {
    for (size_t i = 0; i < size; ++i) {
        delete items[i];
    }
    delete[] items;
    cout << "Keeper destroyed.\n";
}

void Keeper::resize() {
    capacity *= 2;
    Base** newItems = new Base*[capacity];
    for (size_t i = 0; i < size; ++i) {
        newItems[i] = items[i];
    }
    delete[] items;
    items = newItems;
}

void Keeper::add(Base* item) {
    if (size == capacity) {
        resize();
    }
    items[size++] = item;
    cout << "Item added to Keeper.\n";
}

void Keeper::remove(size_t index) {
    if (index >= size) {
        throw out_of_range("Index out of range");
    }
    delete items[index];
    for (size_t i = index; i < size - 1; ++i) {
        items[i] = items[i + 1];
    }
    --size;
    cout << "Item removed from Keeper.\n";
}

void Keeper::displayAll() const {
    if (size == 0) {
        cout << "Keeper is empty.\n";
        return;
    }

    for (size_t i = 0; i < size; ++i) {
        cout << "Item " << i + 1 << ":\n";
        items[i]->display();
        cout << endl;
    }
}

void Keeper::saveToFile(const string& filename) const {
    ofstream out(filename);
    if (!out) {
        throw runtime_error("Unable to open file for writing");
    }

    out << size << '\n';
    for (size_t i = 0; i < size; ++i) {
        items[i]->save(out);
    }

    cout << "Keeper saved to file: " << filename << endl;
}

void Keeper::loadFromFile(const string& filename) {
    ifstream in(filename);
    if (!in) {
        throw runtime_error("Unable to open file for reading");
    }

    for (size_t i = 0; i < size; ++i) {
        delete items[i];
    }
    size = 0;

    size_t newSize;
    in >> newSize;
    in.ignore();

    for (size_t i = 0; i < newSize; ++i) {
        string type;
        getline(in, type);

        Base* item = nullptr;
        if (type == "Book") {
            item = new Book();
        } else if (type == "Textbook") {
            item = new Textbook();
        } else if (type == "Stationery") {
            item = new Stationery();
        } else {
            throw runtime_error("Unknown item type in file");
        }

        item->load(in);
        add(item);
    }

    cout << "Keeper loaded from file: " << filename << endl;
}