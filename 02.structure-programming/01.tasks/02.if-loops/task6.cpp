#include <iostream>
#include <format>

using namespace std;

int main() {
    /* Klientas padėjo 1000€ indėlį į banką su 5% metinių palūkanų.
     * Kokią pinigų sumą jis gaus po 10 metų. */

    double amount = 1000.0;
    double interest = 0.05;

    for (int year = 1; year <= 10; ++year) {
        amount += amount * interest;
    }

    cout << format("{:.2f}", amount) << endl;

    return 0;
}
