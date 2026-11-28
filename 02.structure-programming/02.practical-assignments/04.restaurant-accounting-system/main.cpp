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

const int MAX_MENU_ITEMS = 20;
const int MAX_PORTIONS = 50;

struct menuItemType {
    string menuItem;
    double menuPrice;
};

bool checkUserNumberInput() {
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Įveskite skaičių!\n";
        return false;
    }
    return true;
}

void printGreeting() {
    cout << '\n';
    cout << string(20, '-') << "Sveiki atvykę į restoraną \"Doroklės masyvas\"" << string(20, '-') << "\n";
}

void showMenu(menuItemType menuList[], int itemCount) {
    printGreeting();
    for (int i = 0; i < itemCount; ++i) {
        cout << format("{:>2}. {:<40}{:>6.2f}€\n", i + 1, menuList[i].menuItem, menuList[i].menuPrice);
    }
    cout << format("\nĮveskite patiekalo numerį (1–{}) ir porcijų skaičių.\n", itemCount);
    cout << "Užsakymui baigti įveskite 0.\n";
    cout << "\n";
}

int getData(string filename, menuItemType menuList[]) {
    ifstream fin(filename);
    int itemCount = 0;

    if (!fin.is_open()) {
        cout << "Nepavyko atidaryti failo\n";
        return 0;
    }

    string header;
    getline(fin, header);
    if (!fin) {
        cout << "Meniu failas tuščias\n";
        return 0;
    }

    while (itemCount < MAX_MENU_ITEMS && getline(fin >> ws, menuList[itemCount].menuItem, ',')) {
        fin >> menuList[itemCount].menuPrice;
        if (!fin || menuList[itemCount].menuPrice <= 0) {
            cout << format("Klaidingi meniu duomenys {} eilutėje\n", itemCount + 2);
            return 0;
        }
        ++itemCount;
    }

    if (itemCount == 0) {
        cout << "Meniu neturi patiekalų\n";
        return 0;
    }

    return itemCount;
}

int readDishNumber(int itemCount) {
    int dishNumber = 0;
    while (true) {
        cout << "Patiekalo numeris: ";
        cin >> dishNumber;
        if (!checkUserNumberInput()) {
            continue;
        }
        if (dishNumber < 0 || dishNumber > itemCount) {
            cout << format("Neteisingas patiekalo numeris. Leistinas intervalas: 0–{}\n", itemCount);
            continue;
        }
        return dishNumber;
    }
}

int readPortions() {
    int portions = 0;
    while (true) {
        cout << "Porcijų skaičius: ";
        cin >> portions;
        if (!checkUserNumberInput()) {
            continue;
        }
        if (portions < 1 || portions > MAX_PORTIONS) {
            cout << format("Neteisingas porcijų kiekis. Leistinas intervalas: 1–{}\n", MAX_PORTIONS);
            continue;
        }
        return portions;
    }
}

void takeOrder(menuItemType menuList[], int itemCount, int portions[]) {
    while (true) {
        int dishNumber = readDishNumber(itemCount);
        if (dishNumber == 0) {
            cout << "Užsakymas baigtas.\n";
            break;
        }
        int amount = readPortions();
        portions[dishNumber - 1] += amount;
        cout << format("Pridėta: {} × {}\n", amount, menuList[dishNumber - 1].menuItem);
    }
}

int main() {
    locale::global(locale("en_US.UTF-8"));

#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    int portions[MAX_MENU_ITEMS] = {};
    menuItemType menuList[MAX_MENU_ITEMS];

    int itemCount = getData("menu.txt", menuList);

    if (itemCount == 0) {
        return 1;
    }
    showMenu(menuList, itemCount);
    takeOrder(menuList, itemCount, portions);
    return 0;
}
