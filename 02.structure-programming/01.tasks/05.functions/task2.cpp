#include <iostream>
#include <format>

using namespace std;

void swapNumbers(int &num1, int &num2) {
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

int main() {
    // 2 užduotis. Skaičių sukeitimas//
    // Parašykite C++ programą, kuri paprašo įvesti du sveikuosius skaičius ir sukeičia jų reikšmes.//
    // Sukurkite funkciją void sukeisti(int &pirmas, int &antras), kuriai kintamieji perduodami nuoroda.
    // Funkcijoje main() išveskite jų reikšmes prieš sukeitimą ir po jo.//
    // Pavyzdys: įvedus 5 ir 12, po sukeitimo pirmojo kintamojo reikšmė turi būti 12, antrojo – 5.

    int num1;
    int num2;

    cout << "Iveskite pirmaji sveika skaiciu:\n";
    cin >> num1;

    cout << "Iveskite antraji sveika skaiciu:\n";
    cin >> num2;

    cout << format("Skaiciai pries pakeitima: {} {}\n", num1, num2);
    swapNumbers(num1, num2);
    cout << format("Skaiciai po pakeitimo: {} {}\n", num1, num2);
}
