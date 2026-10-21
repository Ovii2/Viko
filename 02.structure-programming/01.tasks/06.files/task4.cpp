#include <iostream>
#include <fstream>
#include <format>
#include <string>

using namespace std;

int main() {
    // 4. Pažymių dažniai
    // Faile pazymiai.txt pateikti sveikieji pažymiai. Faile gali būti ne daugiau kaip 100 pažymių.
    //
    // Apskaičiuokite, kiek kartų pasikartoja kiekvienas pažymys nuo 1 iki 10, ir rezultatą įrašykite į failą rezultatai.txt.
    //
    // Pavyzdinis pazymiai.txt turinys:
    //
    // 8 10 7 8 6 10 5 8 9 10
    // Rezultatų failo pavyzdys:
    //
    // 1: 0
    // 2: 0
    // 3: 0
    // 4: 0
    // 5: 1
    // 6: 1
    // 7: 1
    // 8: 3
    // 9: 1
    // 10: 3
    //
    // Bendras pažymių kiekis: 10
    //
    // Reikalavimai:
    //
    // Patikrinti, ar pazymiai.txt sėkmingai atidarytas.
    // Priimti tik sveikuosius pažymius nuo 1 iki 10.
    // Neleisti nuskaityti daugiau kaip 100 pažymių.
    // Aptikus netinkamą pažymį, išvesti klaidos pranešimą.
    // Patikrinti, ar rezultatai.txt sėkmingai atidarytas rašymui.
    // Į rezultatų failą įrašyti kiekvieno pažymio dažnį ir bendrą pažymių skaičių.

    ifstream fin("pazymiai.txt");
    ofstream fout("rezultatai.txt");

    if (!fin.is_open()) {
        cout << "Nepavyko atidaryti failo\n";
        return 1;
    }


    int grade;
    int frequencies[11] = {};
    int count = 0;

    while (fin >> grade) {
        if (grade < 1 || grade > 10) {
            cout << "Galimi tik sveikieji skaičiai nuo 1 iki 10\n";
            return 1;
        }

        if (count >= 100) {
            cout << "Pažymių limitas pasiektas\n";
            return 1;
        }

        frequencies[grade]++;
        count++;
    }

    if (!fout.is_open()) {
        cout << "Nepavyko sukurti failo\n";
        return 1;
    }

    for (int i = 1; i <= 10; ++i) {
        fout << format("{}: {}\n", i, frequencies[i]);
    }
    fout << "\nBendras pažymių kiekis: " << count << "\n";
}
