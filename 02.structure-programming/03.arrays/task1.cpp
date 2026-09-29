#include <iostream>

using namespace std;

int main() {
    /*Parašykite programą, kurioje naudotojas įveda 5 sveikuosius skaičius ir juos išsaugo masyve.
     *Programa turi apskaičiuoti visų masyvo elementų sumą, rasti didžiausią ir mažiausią elementą masyve.
     *Į atsakymų lauką turi būti atspausdinta suma, didžiausias ir mažiausias masyvo elementas.*/

    int arr[5];

    int sum = 0;

    for (int i = 0; i < 5; ++i) {
        cout << "Iveskite " << i + 1 << " sveikaji skaiciu:" << endl;
        cin >> arr[i];
    }

    int min = arr[0];
    int max = arr[0];

    for (int i: arr) {
        sum += i;
        if (i < min) min = i;
        if (i > max) max = i;
    }

    cout << "Suma yra " << sum << endl;
    cout << "Maziausias elementas yra " << min << endl;
    cout << "Didziausias elementas yra " << max << endl;


    return 0;
}
