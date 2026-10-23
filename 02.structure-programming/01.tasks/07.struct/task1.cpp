#include <iostream>
#include <format>
#include <string>

using namespace std;

struct Student {
    string name;
    unsigned int age = 0;
    double grade = 0.0;
};

int main() {
    // 1. Sukurti programą, kuri:
    //
    // apibrėžia Student struktūrą su laukais: vardas (string), amžius (int), pažymys (double);
    // leidžia vartotojui įvesti 3 studentų duomenis;
    // apskaičiuoja ir išveda bendrą pažymių vidurkį.

    Student students[3];
    double sum = 0;

    for (int i = 0; i < 3; ++i) {
        cout << "Įveskite " << i + 1 << " studento vardą:\n";
        cin >> students[i].name;

        cout << "Įveskite " << i + 1 << " studento amžių:\n";
        cin >> students[i].age;

        cout << "Įveskite studento " << i + 1 << " pažymį:\n";
        cin >> students[i].grade;

        sum += students[i].grade;
    }

    double avg = sum / 3;
    cout << format("Bendras vidurkis : {:.2f}", avg);
}
