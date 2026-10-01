#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    /*Tyrime dalyvavo 40 studentų. Jiems buvo duotas žaisti toks pats kompiuterinis žaidimas ir paprašyta jį
    įvertinti nuo 1 iki 10 balų. Patalpinti atsakymus į masyvą ir gauti apklausos rezultatus. T.y. koks vertinimas
    kiek kartų pasikartojo*/

    int results[40];

    for (int i = 0; i < 40; ++i) {
        results[i] = rand() % 10 + 1;
    }

    int counts[10] = {};

    for (int i = 0; i < 40; ++i) {
        counts[results[i] - 1]++;
    }

    for (int i = 0; i < 10; ++i) {
        cout << "Ivertinimas " << i + 1 << " kartojosi " << counts[i] << endl;
    }
}
