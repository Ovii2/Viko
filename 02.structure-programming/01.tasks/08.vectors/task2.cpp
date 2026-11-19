#include <iostream>
#include <vector>
#include <string>
#include <format>

using namespace std;

void printReverseNames(vector<string> names) {
    for (int i = names.size() - 1; i >= 0; --i) {
        cout << format("{}\n", names[i]);
    }
}

int main() {
    // 2 užduotis. Įveskite vardus į vector<string>, kol bus įvestas žodis stop. Išveskite:
    // vardus atvirkščia tvarka;
    // ilgiausią vardą.

    vector<string> names;
    string name;

    cout << "Iveskite vardus\n";
    cin >> name;

    while (name != "stop") {
        names.push_back(name);
        cout << "Iveskite sekanti varda\n";
        cin >> name;
    }

    string longestName = names[0];

    for (int i = 0; i < names.size(); ++i) {
        if (longestName.size() < names[i].size()) {
            longestName = names[i];
        }
    }

    printReverseNames(names);
    cout << format("Ilgiausias vardas: {}\n", longestName);
}
