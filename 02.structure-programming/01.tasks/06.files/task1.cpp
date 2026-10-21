#include <iostream>
#include <fstream>
#include <format>
#include <string>

using namespace std;

int main() {
    // 1. Studentų filtravimas pagal pažymį
    // Faile studentai.txt pateikti studentų vardai ir jų pažymiai. Nuskaitykite duomenis ir į ekraną išveskite tik tuos studentus, kurių pažymys yra didesnis už 8.
    //
    // Failo studentai.txt pavyzdys:
    //
    // Tomas 8
    // Greta 10
    // Arnas 5
    // Jonas 8
    // Deividas 9
    // Klaudijus 7
    // Reikalavimai:
    //
    // Patikrinti, ar failas sėkmingai atidarytas.
    // Nuskaityti studento vardą ir pažymį.
    // Išvesti tik studentus, kurių pažymys > 8.

    ifstream fin("studentai.txt");

    if (!fin.is_open()) {
        cout << "Nepavyko atidaryti failo\n";
        return 1;
    }

    string name;
    int grade;

    while (fin >> name >> grade) {
        if (grade > 8) {
            cout << format("{} {}\n", name, grade);
        }
    }
}
