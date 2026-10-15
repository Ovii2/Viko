#include <iostream>
#include <format>

using namespace std;

double skaiciuotiPlota(double ilgis, double plotis) {
    return ilgis * plotis;
}

double skaiciuotiPerimetra(double ilgis, double plotis) {
    return 2 * (ilgis + plotis);
}

int main() {
    //  1 užduotis. Stačiakampio plotas ir perimetras
    //
    // Parašykite C++ programą, kuri paprašo įvesti stačiakampio ilgį ir plotį bei išveda jo plotą ir perimetrą.
    //
    // Sukurkite dvi funkcijas:
    //
    // double skaiciuotiPlota(double ilgis, double plotis) – grąžina plotą.
    // double skaiciuotiPerimetra(double ilgis, double plotis) – grąžina perimetrą.
    // Duomenis įveskite ir rezultatus išveskite funkcijoje main().

    double plotis;
    double ilgis;

    cout << "Iveskite staciakampio ploti:\n";
    cin >> plotis;

    cout << "Iveskite staciakampio ilgi:\n";
    cin >> ilgis;

    double areaResult = skaiciuotiPlota(ilgis, plotis);
    double perimeterResult = skaiciuotiPerimetra(ilgis, plotis);

    cout << format("Staciakampio plotas yra {:.2f}\n", areaResult);
    cout << format("Staciakampio perimeteras yra {:.2f}\n", perimeterResult);
}
