#include <iostream>

using namespace std;

int main() {
    /*Trečią užduotį perrašykite naudodami jungiklio operatorių "switch".*/

    int grade = 8;

    switch (grade) {
        case 10:
            cout << "Puiku" << endl;
            break;
        case 8:
        case 9:
            cout << "Labai gerai" << endl;
            break;
        case 7:
        case 6:
            cout << "Gerai" << endl;
            break;
        case 5:
            cout << "Patenkinamai" << endl;
            break;
        case 4:
        case 3:
        case 2:
        case 1:
        case 0:
            cout << "Egzaminas neislaikytas" << endl;
            break;
        default:
            cout << "Klaida: Iveskite pazymi nuo 0 iki 10!" << endl;
    }
}
