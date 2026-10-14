#include <iostream>

using namespace std;

/**
 * @brief Patikrina, ar pažymys yra nuo 1 iki 10.
 * @param grade Tikrinamas pažymys.
 * @return true, jei pažymys tinkamas; kitu atveju false.
 */
bool checkGrade(int grade) {
    return grade >= 1 && grade <= 10;
}

/**
 * @brief Išveda pagrindinį meniu.
 */
void showMenu() {
    cout << "\n";
    cout << "----------MENIU----------\n";
    cout << "1.Įvesti mokinį ir jo pažymius.\n";
    cout << "2.Peržiūrėti visų mokinių pažymius.\n";
    cout << "3.Peržiūrėti konkretaus mokinio pažymius.\n";
    cout << "4.Atnaujinti pažymį.\n";
    cout << "5.Apskaičiuoti mokinio vidurkį.\n";
    cout << "6.Pašalinti mokinį.\n";
    cout << "7.Išeiti.\n";
}

/**
 * @brief Prašo įvesti pažymį, kol jo reikšmė yra nuo 1 iki 10.
 * @param gradeNumber Įvedamo pažymio eilės numeris.
 * @return Įvestas tinkamas pažymys.
 */
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

/**
 * @brief Patikrina įvestį ir išvalo cin klaidą.
 * @return true, jei įvestis tinkama; false, jei nepavyko nuskaityti.
 */
bool checkNumberInput() {
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Įveskite skaičių!\n";
        return false;
    }
    return true;
}

/**
 * @brief Išspausdina pasirinktą kiekį simbolių.
 * @param s Simbolis.
 * @param count simoblių kiekis.
 */
void printSymbols(char s, int count) {
    for (int i = 0; i < count; ++i) {
        cout << s;
    }
    cout << "\n";
}

int main() {
    string names[100];
    int grades[100][10];
    int studentCount = 0;
    int gradesCount[100] = {};
    int studentNumber;

    int input;

    do {
        showMenu();

        cin >> input;
        if (!checkNumberInput()) {
            input = 0;
            continue;
        }

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
                if (studentCount == 0) {
                    cout << "Mokinių sąrašas tuščias.\n";
                    break;
                }

                printSymbols('-', 20);
                for (int i = 0; i < studentCount; ++i) {
                    cout << i + 1 << ". " << names[i];
                    for (int j = 0; j < gradesCount[i]; ++j) {
                        cout << " " << grades[i][j];
                    }
                    cout << "\n";
                }
                printSymbols('-', 20);
                break;
            case 3:
                if (studentCount == 0) {
                    cout << "Mokinių sąrašas tuščias.\n";
                    break;
                }
                cout << "Šiuo metu yra mokinių: " << studentCount << "\n";

                do {
                    cout << "Įveskite mokinio numerį.\n";
                    cin >> studentNumber;
                } while (studentNumber < 1 || studentNumber > studentCount);

                printSymbols('-', 20);
                cout << studentNumber << ". " << names[studentNumber - 1] << " ";
                for (int i = 0; i < gradesCount[studentNumber - 1]; ++i) {
                    cout << grades[studentNumber - 1][i] << " ";
                }
                cout << "\n";
                printSymbols('-', 20);
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
                cout << "Blogas pasirinkimas!\n";
        }
    } while (input != 7);
}
