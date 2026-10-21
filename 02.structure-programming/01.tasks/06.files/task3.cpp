#include <iostream>
#include <fstream>
#include <format>
#include <string>

using namespace std;

int main() {
    // 3. Temperatūrų analizė
    // Faile temperaturos.txt pateiktos 7 temperatūros. Nuskaitykite jas ir apskaičiuokite:
    //
    // temperatūrų vidurkį;
    // mažiausią temperatūrą;
    // didžiausią temperatūrą.
    // Visus tris rezultatus įrašykite į failą ataskaita.txt.
    //
    // Pavyzdinis temperaturos.txt turinys:
    //
    // 12.5
    // 14.2
    // 11.8
    // 9.7
    // 15.1
    // 13.4
    // 10.6
    // Rezultatų failo pavyzdys:
    //
    // Vidurkis: 12.47
    // Minimumas: 9.7
    // Maksimumas: 15.1
    // Reikalavimai:
    //
    // Patikrinti, ar temperaturos.txt sėkmingai atidarytas.
    // Patikrinti, ar pavyko nuskaityti visas 7 temperatūras.
    // Patikrinti, ar ataskaita.txt sėkmingai atidarytas rašymui.
    // Rezultatus įrašyti į ataskaita.txt.

    ifstream fin("temperaturos.txt");
    ofstream fout("ataskaita.txt");

    if (!fin.is_open()) {
        cout << "Nepavyko atidaryti failo\n";
        return 1;
    }

    double temp;
    double avg = 0.0;
    double sum = 0.0;

    fin >> temp;
    int count = 1;
    double min = temp;
    double max = temp;
    sum = temp;

    while (fin >> temp) {
        count++;
        sum += temp;
        if (temp < min) {
            min = temp;
        } else if (temp > max) {
            max = temp;
        }
    }

    avg = sum / 7;

    if (count != 7) {
        cout << "Faile rasta " << count << " temperatūrų, o reikia 7\n";
        return 1;
    }

    if (!fout.is_open()) {
        cout << "Nepavyko sukurti failo\n";
        return 1;
    }

    cout << format("Vidurkis: {:.2f}\n", avg);
    cout << format("Minimumas: {:.2f}\n", min);
    cout << format("Maksimumas: {:.2f}\n", max);

    fout << format("Vidurkis: {:.2f}\n", avg);
    fout << format("Minimumas: {:.2f}\n", min);
    fout << format("Maksimumas: {:.2f}\n", max);
}
