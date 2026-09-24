#include <iostream>

using namespace std;

int main() {
    /*Susikurkite kintamąjį egzamino įvertinimui saugoti.
     *Naudojant įdėtinės sąlygos operatorių "else if" patikrinkite šias sąlygas iš išveskite atitinkamą
     *įvertinimą žodžiais: jei pažymys yra lygus 10 išvesti "puiku"; jei pažymys lygus arba didesnis nei 9
     *išvesti "labai gerai"; jei pažymys yra lygus arba didesnis nei 7 išvesti "gerai"; jei pažymys yra lygus arba didesnis
     *nei 5 išvesti "patenkinamai"; jei pažymys mažesnis nei 5 išvesti "egzaminas neišlaikytas".*/

    double grade = 4.5;

    if (grade < 0 || grade > 10) {
        cout << "Klaida: Iveskite pazymi nuo 0 iki 10!" << endl;
    } else if (grade == 10) {
        cout << "Puiku" << endl;
    } else if (grade >= 9) {
        cout << "Labai gerai" << endl;
    } else if (grade >= 7) {
        cout << "Gerai" << endl;
    } else if (grade >= 5) {
        cout << "Patenkinamai" << endl;
    } else {
        cout << "Egzaminas neislaikytas" << endl;
    }
    return 0;
}
