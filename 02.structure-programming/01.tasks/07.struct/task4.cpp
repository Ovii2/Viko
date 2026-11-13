#include <iostream>
#include <format>
#include <string>
#include <fstream>

using namespace std;

struct Item {
    string title;
    double price;
    int amount;
};

double calculateStockValue(Item item) {
    return item.amount * item.price;
}

double calculateTotalStockValue(Item items[], int itemCount) {
    double sum = 0;
    for (int i = 0; i < itemCount; ++i) {
        sum += calculateStockValue(items[i]);
    }
    return sum;
}

void printMostValuableItem(Item items[], int itemCount) {
    int best = 0;
    for (int i = 1; i < itemCount; ++i) {
        if (calculateStockValue(items[i]) > calculateStockValue(items[best])) {
            best = i;
        }
    }
    cout << format("Didziausios vertes preke: {}, {:.2f}€\n",
                   items[best].title, calculateStockValue(items[best]));
}

int main() {
    // 4.Sukurti programą, kuri:
    //
    // apibrėžia Preke struktūrą su laukais: pavadinimas (string), kaina (double), kiekis (int);
    // iš failo prekes.txt nuskaito prekių duomenis;
    // apskaičiuoja kiekvienos prekės atsargų vertę (kaina × kiekis);
    // išveda prekių pavadinimus ir jų atsargų vertes;
    // apskaičiuoja ir išveda bendrą visų prekių atsargų vertę bei didžiausią atsargų vertę turinčios prekės pavadinimą.

    ifstream fin("prekes.txt");

    if (!fin.is_open()) {
        cout << "Nepavyko atidaryti failo\n";
        return 1;
    }

    const int MAX_ITEMS = 100;
    Item items[MAX_ITEMS];
    int itemCount;
    fin >> itemCount;

    if (!fin || itemCount < 1 || itemCount > MAX_ITEMS) {
        cout << "Neteisingas prekiu skaicius\n";
        return 1;
    }

    for (int i = 0; i < itemCount; ++i) {
        getline(fin >> ws, items[i].title, ';');
        fin >> items[i].price;
        fin.ignore();
        fin >> items[i].amount;
        if (!fin) {
            cout << format("Nepavyko nuskaityti {} prekiu duomenu\n", i + 1);
            return 1;
        }

        if (items[i].price <= 0 || items[i].amount < 0) {
            cout << format("Neteisingi {} prekiu duomenys\n", i + 1);
            return 1;
        }
        double value = calculateStockValue(items[i]);
        cout << format("{}, {:.2f}€\n", items[i].title, value);
    }
    double total = calculateTotalStockValue(items, itemCount);
    cout << format("\nBendra atsargu verte: {:.2f}€\n", total);
    printMostValuableItem(items, itemCount);
}
