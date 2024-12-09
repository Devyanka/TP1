#include "Keeper.h"
#include "Book.h"
#include "Textbook.h"
#include "Stationery.h"
#include <iostream>
using namespace std;

int main() {
    Keeper keeper;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add Book\n";
        cout << "2. Add Textbook\n";
        cout << "3. Add Stationery\n";
        cout << "4. Display All\n";
        cout << "5. Save to File\n";
        cout << "6. Load from File\n";
        cout << "7. Remove Item\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        try {
            switch (choice) {
                case 1: {
                    Base* book = new Book();
                    book->input();
                    keeper.add(book);
                    break;
                }
                case 2: {
                    Base* textbook = new Textbook();
                    textbook->input();
                    keeper.add(textbook);
                    break;
                }
                case 3: {
                    Base* stationery = new Stationery();
                    stationery->input();
                    keeper.add(stationery);
                    break;
                }
                case 4:
                    keeper.displayAll();
                    break;
                case 5: {
                    string filename;
                    cout << "Enter filename to save: ";
                    cin >> filename;
                    keeper.saveToFile(filename);
                    break;
                }
                case 6: {
                    string filename;
                    cout << "Enter filename to load: ";
                    cin >> filename;
                    keeper.loadFromFile(filename);
                    break;
                }
                case 7: {
                    int index;
                    cout << "Enter index to remove: ";
                    cin >> index;
                    keeper.remove(index);
                    break;
                }
                case 8:
                    cout << "Exiting...\n";
                    break;
                default:
                    cout << "Invalid choice!\n";
            }
        } catch (const exception& e) {
            cerr << "Error: " << e.what() << endl;
        }
    } while (choice != 8);

    return 0;
}