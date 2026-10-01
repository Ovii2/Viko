#include <iostream>

using namespace std;

int main() {
    /*Parašykite programą, kuri apskaičiuotų visų nelyginių skaičių sumą intervale [1; 20]*/

    int sum = 0;

    for (int i = 1; i <= 20; i += 2) {
        sum += i;
    }

    cout << "Nelyginiu skaiciu suma yra : " << sum << endl;
    return 0;
}
