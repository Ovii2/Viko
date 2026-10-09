#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

int main() {
    /*Sukurk programą, kuri:
    Leidžia įvesti N studentų pažymius M dalykų (naudojant dvimatį masyvą).
    Apskaičiuoja:
    1.kiekvieno studento vidurkį,
    2.kiekvieno dalyko vidurkį,
    3.bendrą visos grupės vidurkį.
    4.Išveda rezultatus tvarkingoje lentelėje.*/


    int N = 0;
    int M = 0;
    int grades[10][10];
    double studentAverages[10];
    double subjectAverages[10];
    double totalSum = 0;

    do {
        cout << "Iveskite studentu skaiciu (1-10): ";

        if (!(cin >> N)) {
            if (cin.eof()) {
                return 0;
            }

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            N = 0;
        }

        if (N < 1 || N > 10) {
            cout << "Studentu skaicius turi buti nuo 1 iki 10.\n";
        }
    } while (N < 1 || N > 10);

    do {
        cout << "Iveskite dalyku skaiciu (1-10): ";

        if (!(cin >> M)) {
            if (cin.eof()) {
                return 0;
            }

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            M = 0;
        }

        if (M < 1 || M > 10) {
            cout << "Dalyku skaicius turi buti nuo 1 iki 10.\n";
        }
    } while (M < 1 || M > 10);

    for (int i = 0; i < N; ++i) {
        double sum = 0;

        for (int j = 0; j < M; ++j) {
            do {
                cout << "Studentas " << i + 1
                     << ", dalykas " << j + 1
                     << ", pazymys (1-10): ";

                if (!(cin >> grades[i][j])) {
                    if (cin.eof()) {
                        return 0;
                    }

                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    grades[i][j] = 0;
                }

                if (grades[i][j] < 1 || grades[i][j] > 10) {
                    cout << "Pazymys turi buti nuo 1 iki 10.\n";
                }
            } while (grades[i][j] < 1 || grades[i][j] > 10);

            sum += grades[i][j];
        }

        studentAverages[i] = sum / M;
        totalSum += sum;
    }

    for (int j = 0; j < M; ++j) {
        double sum = 0;

        for (int i = 0; i < N; ++i) {
            sum += grades[i][j];
        }

        subjectAverages[j] = sum / N;
    }

    cout << fixed << setprecision(2);
    cout << "\n" << setw(18) << "Studentas";

    for (int j = 0; j < M; ++j) {
        cout << setw(8) << j + 1;
    }

    cout << setw(12) << "Vidurkis" << '\n';

    for (int i = 0; i < N; ++i) {
        cout << setw(18) << i + 1;

        for (int j = 0; j < M; ++j) {
            cout << setw(8) << grades[i][j];
        }

        cout << setw(12) << studentAverages[i] << '\n';
    }

    cout << setw(18) << "Dalyko vidurkis";

    for (int j = 0; j < M; ++j) {
        cout << setw(8) << subjectAverages[j];
    }

    cout << "\n\nBendras grupes vidurkis: "
         << totalSum / (N * M) << '\n';

    return 0;
}