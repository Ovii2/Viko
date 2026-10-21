#include <iostream>
#include <fstream>
#include <format>
#include <string>
#include <sstream>

using namespace std;

int main() {
    //     2. Failo statistika
    // Nuskaitykite pasirinktą tekstinį failą eilutė po eilutės ir apskaičiuokite pagrindinę jo statistiką.
    //
    // Reikia nustatyti:
    //
    //     eilučių skaičių;
    //     simbolių skaičių;
    //     žodžių skaičių.
    //     Galite naudoti studentai.txt arba kitą tekstinį failą.
    //
    //     Rezultato pavyzdys:
    //
    //     Eilučių skaičius: ...
    //     Simbolių skaičius: ...
    //     Žodžių skaičius: ...
    //
    //     Reikalavimai:
    //
    //     Patikrinti, ar failas sėkmingai atidarytas.
    //     Failą nuskaityti eilutė po eilutės.
    //     Apskaičiuotus rezultatus išvesti į ekraną.

    ifstream fin("studentai.txt");

    if (!fin.is_open()) {
        cout << "Nepavyko atidaryti failo\n";
        return 1;
    }

    string line;
    int linesCount = 0;
    int symbolsCount = 0;
    int wordsCount = 0;

    while (getline(fin, line)) {
        linesCount++;
        symbolsCount += line.size();

        istringstream iss(line);
        string word;
        while (iss >> word) {
            wordsCount++;
        }
    }
    cout << "Eilučių skaičius: " << linesCount << "\n";
    cout << "Simbolių skaičius: " << symbolsCount << "\n";
    cout << "Žodžių skaičius: " << wordsCount << "\n";
}
