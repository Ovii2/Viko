#include <iostream>

using namespace std;

int main() {
    /*Sukurk programą, kuri:
 Leidžia įvesti N studentų pažymius M dalykų (naudojant dvimatį masyvą).
 Apskaičiuoja:
 1.kiekvieno studento vidurkį,
 2.kiekvieno dalyko vidurkį,
 3.bendrą visos grupės vidurkį.
 4.Išveda rezultatus tvarkingoje lentelėje.*/

    int N;
    int M;

    int arr[10][10];

    cout << "Iveskite pazymius";
    cin >> N;

    cout << "Iveskite dalyku skaiciu";
    cin >> M;


    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> arr[i][j];
        }
    }

    return 0;
}
