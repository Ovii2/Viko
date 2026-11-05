#include <iostream>
#include <fstream>
#include <string>
#include <format>
#include <limits>

#ifdef _WIN32
#define NOMINMAX
#include <windows.h>
#endif

using namespace std;

const int MAX_ITEMS = 100;
const int DISCOUNT_MIN_AMOUNT = 10;
const double DISCOUNT_RATE = 0.10;
const int TABLE_WIDTH = 115;

void showMenu() {
    cout << "\n";
    cout << "----------MENIU----------\n";
    cout << "1.Peržiūrėti visas užsakymo prekes.\n";
    cout << "2.Peržiūrėti pasirinktos kategorijos prekes.\n";
    cout << "3.Peržiūrėti viso užsakymo sumas.\n";
    cout << "4.Peržiūrėti sumas pagal kategorijas.\n";
    cout << "5.Parodyti visą užsakymo ataskaitą.\n";
    cout << "6.Išsaugoti visą ataskaitą į failą.\n";
    cout << "7.Išeiti.\n";
}

bool checkUserNumberInput() {
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Įveskite skaičių!\n";
        return false;
    }
    return true;
}

int readData(string filename, string categories[], string titles[], double prices[], int amounts[]) {
    ifstream fin(filename);
    int itemCount;

    if (!fin.is_open()) {
        cout << "Nepavyko atidaryti failo\n";
        return 0;
    }

    fin >> itemCount;

    if (!fin || itemCount < 1 || itemCount > MAX_ITEMS) {
        cout << "Neteisingas įrašų skaičius\n";
        return 0;
    }

    for (int i = 0; i < itemCount; ++i) {
        getline(fin >> ws, categories[i], ';');
        getline(fin, titles[i], ';');
        fin >> prices[i];
        fin.ignore();
        fin >> amounts[i];

        if (!fin) {
            cout << "Nepavyko nuskaityti įrašų\n";
            return 0;
        }

        if (prices[i] <= 0) {
            cout << "Neteisinga kaina\n";
            return 0;
        }
        if (amounts[i] <= 0) {
            cout << "Neteisingas kiekis\n";
            return 0;
        }
        if (categories[i] != "Dviraciai" && categories[i] != "Dalys" && categories[i] != "Aksesuarai") {
            cout << "Neteisinga kategorija\n";
            return 0;
        }
    }

    return itemCount;
}

double calculateSumBeforeDiscount(double price, int amount) {
    return price * amount;
}

double calculateDiscount(double sumBeforeDiscount, int amount) {
    if (amount < DISCOUNT_MIN_AMOUNT) {
        return 0;
    }
    return sumBeforeDiscount * DISCOUNT_RATE;
}

void printItems(int itemCount, string categories[], string titles[], double prices[], int amounts[]) {
    cout << format("{:<12}{:<47}{:>11}{:>8}{:>13}{:>11}{:>13}\n",
                   "Kategorija", "Pavadinimas", "Kaina", "Kiekis", "Suma", "Nuolaida", "Moketi");
    cout << string(TABLE_WIDTH, '-') << "\n";

    for (int i = 0; i < itemCount; ++i) {
        double sumBeforeDiscount = calculateSumBeforeDiscount(prices[i], amounts[i]);
        double discount = calculateDiscount(sumBeforeDiscount, amounts[i]);
        double finalSum = sumBeforeDiscount - discount;
        cout << format("{:<12}{:<47}{:>10.2f}€{:>8}{:>12.2f}€{:>10.2f}€{:>12.2f}€\n",
                       categories[i], titles[i], prices[i], amounts[i],
                       sumBeforeDiscount, discount, finalSum);
    }
}

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    int choice;

    string categories[MAX_ITEMS];
    string titles[MAX_ITEMS];
    double prices[MAX_ITEMS];
    int amounts[MAX_ITEMS];

    int itemCount = readData("uzsakymas.txt", categories, titles, prices, amounts);

    if (itemCount == 0) {
        return 1;
    }

    do {
        showMenu();

        cin >> choice;
        if (!checkUserNumberInput()) {
            choice = 0;
            continue;
        }

        switch (choice) {
            case 1:
                printItems(itemCount, categories, titles, prices, amounts);
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                cout << "Viso gero!\n";
                break;
            default:
                cout << "Blogas pasirinkimas!\n";
        }
    } while (choice != 7);
}
