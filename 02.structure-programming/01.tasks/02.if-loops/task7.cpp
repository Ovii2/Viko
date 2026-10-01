#include <iostream>

using namespace std;

int main() {
    /*Parašyti for ciklą, kuris eitų per kiekvieną skaičių nuo 1 iki 20.
     *Jame apsirašyti sąlygos operatorių "if", kuris patikrintų ar
     *dabartinis skaičius dalinasi iš 4, jei taip tai šį skaičių išvesti.*/

    for (int i = 1; i <= 20; ++i) {
        if (i % 4 == 0) {
            cout << i << endl;
        }
    }
    return 0;
}
