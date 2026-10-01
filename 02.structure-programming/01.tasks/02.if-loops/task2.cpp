#include <iostream>

using namespace std;

int main() {
    /*Papildykite pirmą uždavinį sąlygos operatoriumi "if-else".
     *Jeigu pažymių vidurkis yra neigiamas išveskite "Vidurkis yra neigiamas". */

    double grade1 = 3.5;
    double grade2 = 5.4;
    double grade3 = 6.0;
    double grade4 = 7.5;

    double avg = (grade1 + grade2 + grade3 + grade4) / 4;

    cout << (avg <= 5.0 ? "Vidurkis neigiamas" : "Vidurkis teigimas") << endl;

    return 0;
}
