#include <iostream>
#include <format>
#include <string>

using namespace std;

struct Item {
    string name;
    double price;
    unsigned int amount;
};

int main() {
    // 2. Sukurti programą, kuri:
    //
    // apibrėžia Preke struktūrą su laukais: pavadinimas (string), kaina (double), kiekis (int);
    // leidžia vartotojui įvesti 5 prekes;
    // išveda brangiausios prekės pavadinimą.

    Item items[5];
    Item mostExpensive;

    for (int i = 0; i < 5; ++i) {
        cout << "Įveskite " << i + 1 << " prekės pavadinimą:\n";
        cin >> items[i].name;

        cout << "Įveskite " << i + 1 << " prekės kainą:\n";
        cin >> items[i].price;

        cout << "Įveskite " << i + 1 << " prekės kiekį:\n";
        cin >> items[i].amount;

        if (i == 0 || mostExpensive.price < items[i].price) {
            mostExpensive = items[i];
        }
    }
    cout << format("Brangiausia prekė: {} €{:.2f}\n", mostExpensive.name, mostExpensive.price);
}
