#include <iostream>
#include <string>
#include <format>

using namespace std;

int main() {
    /*Susikurkite penkis kintamuosius skaičiams saugoti ir įveskite juos.
     *Išveskite šių skaičių vidurkį. Nusibraižykite šiai realizacijai blokinę schemą.*/

    int n1;
    int n2;
    int n3;
    int n4;
    int n5;

    cout << "Enter first number" << endl;
    cin >> n1;
    cout << "Enter second number" << endl;
    cin >> n2;
    cout << "Enter third number" << endl;
    cin >> n3;
    cout << "Enter fourth number" << endl;
    cin >> n4;
    cout << "Enter fifth number" << endl;
    cin >> n5;

    int avg = (n1 + n2 + n3 + n4 + n5) / 5;

    cout << format("Average is {}", avg) << endl;
}
