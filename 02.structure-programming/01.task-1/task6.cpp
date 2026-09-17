#include <iostream>
#include <string>
#include <format>

using namespace std;

int main() {
    /*
     * Sunkesnis: Įveskite dviženkli skaičių ir raskite jo skaitmenų sumą.
     * Skaitmenų sumai rasti naudokite tik matematinius veiksmus. Nusibraižykite šiai realizacijai blokinę schemą.
     */

    int number;

    cout << "Enter number\n";
    cin >> number;

    int n1 = number / 10;
    int n2 = number % 10;

    int sum = n1 + n2;

    cout << format("Sum of {} and {} is {}", n1, n2, sum) << endl;
    return 0;
}
