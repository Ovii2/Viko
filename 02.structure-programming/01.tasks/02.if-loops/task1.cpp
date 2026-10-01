#include <iostream>

using namespace std;

int main() {
    /*Susikurkite kelis kintamuosius studento pažymiams vertinti. Raskite studento pažymių vidurkį.
     *Patikrinkite ar pažymių vidurkis yra teigiamas (daugiau arba lygu 5-iems).
     *Jeigu vidurkis teigiamas išveskite "Vidurkis teigiamas". Naudokite tik sąlygos operatoių "if".*/

    double grade1 = 3.5;
    double grade2 = 5.4;
    double grade3 = 6.0;
    double grade4 = 7.5;

    double avg = (grade1 + grade2 + grade3 + grade4) / 4;

    if (avg >= 5.0) {
        cout << "Vidurkis teigiamas" << endl;
    }

    return 0;
}
