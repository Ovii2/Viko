#include <iostream>

using namespace std;

bool checkGrade(int grade) {
    return grade >= 1 && grade <= 10;
}

void showMenu() {
    cout << "\n";
    cout << "-----MENIU-----\n";
    cout << "1.Įvesti mokinį ir jo pažymius.\n";
    cout << "2.Peržiūrėti visų mokinių pažymius.\n";
    cout << "3.Peržiūrėti konkretaus mokinio pažymius.\n";
    cout << "4.Atnaujinti pažymį.\n";
    cout << "5.Apskaičiuoti mokinio vidurkį.\n";
    cout << "6.Pašalinti mokinį.\n";
    cout << "7.Išeiti.\n";
}

int inputGrade(int gradeNumber) {
    int grade;
    do {
        cout << "Įveskite " << gradeNumber << " pažymį:\n";
        cin >> grade;
        if (!checkGrade(grade)) {
            cout << "Pažymys turi būti nuo 1 iki 10!\n";
        }
    } while (!checkGrade(grade));
    return grade;
}

int main() {
    string names[100];
    int grades[100][10];
    int studentCount = 0;
    int gradesCount[100] = {};

    int input;

    do {
        showMenu();

        cin >> input;

        switch (input) {
            case 1:
                if (studentCount >= 100) {
                    cout << "Mokinių limitas pasiektas!\n";
                    break;
                }

                cout << "Įveskite mokinio vardą:\n";
                cin >> names[studentCount];

                do {
                    cout << "Įveskite mokinio " << names[studentCount] << " pažymių skaičių (0–10):\n";
                    cin >> gradesCount[studentCount];
                    if (gradesCount[studentCount] < 0 || gradesCount[studentCount] > 10) {
                        cout << "Pažymių kiekis turi būti nuo 0 iki 10!\n";
                    }
                } while (gradesCount[studentCount] < 0 || gradesCount[studentCount] > 10);

                for (int i = 0; i < gradesCount[studentCount]; ++i) {
                    grades[studentCount][i] = inputGrade(i + 1);
                }

                studentCount++;
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                cout << "Viso gero!\n";
                break;
            default:
                cout << "Blogas pasirinkimas!";
        }
    } while (input != 7);
}
