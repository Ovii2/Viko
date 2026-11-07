#include <iostream>
#include <fstream>
#include <string>
#include <format>
#include <locale>
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

void printMenuTitle(string title, int dashCount) {
    cout << "\n";
    cout << string(dashCount, '-') << title << string(dashCount, '-') << "\n";
}

void showMenu() {
    printMenuTitle("MENIU", 20);
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

void printTableHeader() {
    cout << format("{:<12}{:<47}{:>11}{:>8}{:>13}{:>11}{:>13}\n",
                   "Kategorija", "Pavadinimas", "Kaina", "Kiekis", "Suma", "Nuolaida", "Moketi");
    cout << string(TABLE_WIDTH, '-') << "\n";
}

void printTableRow(string category, string title, double price, int amount) {
    double sumBeforeDiscount = calculateSumBeforeDiscount(price, amount);
    double discount = calculateDiscount(sumBeforeDiscount, amount);
    double finalSum = sumBeforeDiscount - discount;
    cout << format("{:<12}{:<47}{:>10.2Lf}€{:>8}{:>12.2Lf}€{:>10.2Lf}€{:>12.2Lf}€\n",
                   category, title, price, amount,
                   sumBeforeDiscount, discount, finalSum);
}

void printItems(int itemCount, string categories[], string titles[], double prices[], int amounts[]) {
    printTableHeader();
    for (int i = 0; i < itemCount; ++i) {
        printTableRow(categories[i], titles[i], prices[i], amounts[i]);
    }
}


string chooseCategory() {
    int categoryChoice;

    do {
        printMenuTitle("Kategorijos", 10);
        cout << "1.Dviraciai\n";
        cout << "2.Dalys\n";
        cout << "3.Aksesuarai\n";

        cin >> categoryChoice;
        if (!checkUserNumberInput()) {
            categoryChoice = 0;
            continue;
        }

        if (categoryChoice < 1 || categoryChoice > 3) {
            cout << "Tokios kategorijos nėra.\n";
        }
    } while (categoryChoice < 1 || categoryChoice > 3);

    if (categoryChoice == 1) {
        return "Dviraciai";
    }
    if (categoryChoice == 2) {
        return "Dalys";
    }
    return "Aksesuarai";
}

double calculateCategorySum(string category, int itemCount, string categories[], double prices[], int amounts[]) {
    double categorySum = 0;
    for (int i = 0; i < itemCount; ++i) {
        if (categories[i] != category) {
            continue;
        }
        double sumBeforeDiscount = calculateSumBeforeDiscount(prices[i], amounts[i]);
        double discount = calculateDiscount(sumBeforeDiscount, amounts[i]);
        categorySum += sumBeforeDiscount - discount;
    }
    return categorySum;
}

void printCategoryItems(string category, int itemCount, string categories[], string titles[], double prices[],
                        int amounts[]) {
    int foundCount = 0;

    for (int i = 0; i < itemCount; ++i) {
        if (categories[i] != category) {
            continue;
        }
        if (foundCount == 0) {
            printTableHeader();
        }
        printTableRow(categories[i], titles[i], prices[i], amounts[i]);
        foundCount++;
    }

    if (foundCount == 0) {
        cout << "Šios kategorijos prekių užsakyme nėra.\n";
        return;
    }

    double categorySum = calculateCategorySum(category, itemCount, categories, prices, amounts);
    cout << format("\n{} kategorijos mokėtina suma: {:.2Lf}€\n", category, categorySum);
}

double calculateTotalBeforeDiscount(int itemCount, double prices[], int amounts[]) {
    double total = 0.0;
    for (int i = 0; i < itemCount; ++i) {
        total += calculateSumBeforeDiscount(prices[i], amounts[i]);
    }
    return total;
}

double calculateTotalDiscount(int itemCount, double prices[], int amounts[]) {
    double discount = 0.0;
    for (int i = 0; i < itemCount; ++i) {
        double sumBeforeDiscount = calculateSumBeforeDiscount(prices[i], amounts[i]);
        discount += calculateDiscount(sumBeforeDiscount, amounts[i]);
    }
    return discount;
}

void printOrderTotals(int itemCount, double prices[], int amounts[]) {
    double totalBeforeDiscount = calculateTotalBeforeDiscount(itemCount, prices, amounts);
    double totalDiscount = calculateTotalDiscount(itemCount, prices, amounts);
    double finalTotal = totalBeforeDiscount - totalDiscount;

    printMenuTitle("SUMOS", 17);
    cout << format("{:<25}{:>12.2Lf}€\n", "Suma prieš nuolaidas", totalBeforeDiscount);
    cout << format("{:<25}{:>12.2Lf}€\n", "Nuolaidų suma", totalDiscount);
    cout << string(38, '-') << "\n";
    cout << format("{:<25}{:>12.2Lf}€\n", "Mokėtina suma", finalTotal);
}

int main() {
    locale::global(locale("en_US.UTF-8"));

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
            case 2: {
                string chosenCategory = chooseCategory();
                printCategoryItems(chosenCategory, itemCount, categories, titles, prices, amounts);
                break;
            }
            case 3:
                printOrderTotals(itemCount, prices, amounts);
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
