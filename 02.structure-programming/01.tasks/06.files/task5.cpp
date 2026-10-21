#include <iostream>
#include <fstream>
#include <format>
#include <string>

using namespace std;

int main() {
    // 5. Miestų analizė
    // Faile miestai.txt kiekvienoje eilutėje pateiktas vienas miesto pavadinimas. Miesto pavadinimas negali būti tuščias.
    //
    // Reikia:
    //
    // suskaičiuoti, kiek miestų yra faile;
    // rasti ilgiausią miesto pavadinimą;
    // rezultatus įrašyti į failą ataskaita.txt.
    // Pavyzdinis miestai.txt turinys:
    //
    // Vilnius
    // Kaunas
    // Klaipėda
    // Šiauliai
    // Panevėžys
    // Rezultatų failo pavyzdys:
    //
    // Miestų skaičius: 5
    // Ilgiausias pavadinimas: Panevėžys
    // Pavadinimo ilgis: 10
    // Reikalavimai:
    //
    // Patikrinti, ar miestai.txt sėkmingai atidarytas.
    // Duomenis nuskaityti eilutė po eilutės.
    // Patikrinti, ar failas nėra tuščias.
    // Nevertinti tuščių eilučių kaip miesto pavadinimo.
    // Miesto pavadinimo ilgį nustatyti naudojant string::size().
    // Patikrinti, ar ataskaita.txt sėkmingai atidarytas rašymui.

    ifstream fin("miestai.txt");
    ofstream fout("miestu_ataskaita.txt");

    string city;
    int cityCount = 0;
    string longest;

    if (!fin.is_open()) {
        cout << "Nepavyko atidaryti failo\n";
        return 1;
    }

    while (getline(fin, city)) {
        if (city.empty()) {
            continue;
        }
        if (city.size() > longest.size()) {
            longest = city;
        }
        cityCount++;
    }

    if (cityCount == 0) {
        cout << "Failas yra tuščias.\n";
        return 1;
    }

    if (!fout.is_open()) {
        cout << "Nepavyko sukurti failo\n";
        return 1;
    }

    fout << format("Miestų skaičius: {}\n", cityCount);
    fout << format("Ilgiausias pavadinimas: {}\n", longest);
    fout << format("Pavadinimo ilgis: {}\n", longest.size());

    cout << format("Miestų skaičius: {}\n", cityCount);
    cout << format("Ilgiausias pavadinimas: {}\n", longest);
    cout << format("Pavadinimo ilgis: {}\n", longest.size());
}
