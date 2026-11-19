#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    // 1 užduotis. Įveskite temperatūras (sveikus skaičius) į vektorių, kol bus įvesta 999. Išveskite:
    // kiekį;
    // vidurkį;
    // kiek temperatūrų žemesnės už 0.

    int input = 0;
    vector<int> output;

    int sum = 0;
    int belowZero = 0;

    cout << "Iveskite sveikus skaicius nuo 1 iki 999\n";
    cin >> input;

    while (input != 999) {
        output.push_back(input);
        cout << "Iveskite sekanti skaiciu\n";
        cin >> input;
    }

    for (int i: output) {
        sum += i;
        if (i < 0) {
            belowZero++;
        }
    }

    double avg = static_cast<double>(sum) / output.size();

    cout << format("Kiekis {}\n", output.size());
    cout << format("Vidurkis {:.2f}\n", avg);
    cout << format("Zemiau nulio {}\n", belowZero);
}
