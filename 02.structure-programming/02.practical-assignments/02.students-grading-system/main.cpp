#include <iomanip>
#include <iostream>
#include <format>

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
 * @brief Patikrina įvestį ir išvalo cin klaidą.
 * @return true, jei įvestis tinkama; false, jei nepavyko nuskaityti.
 */
bool checkUserNumberInput() {
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Įveskite skaičių!\n";
        return false;
    }
    return true;
}

/**
 * @brief Prašo įvesti pažymį, kol jo reikšmė yra nuo 1 iki 10.
 * @param gradeNumber Įvedamo pažymio eilės numeris.
 * @return Įvestas tinkamas pažymys.
 */
int inputGrade(int gradeNumber) {
    int grade = 0;
    do {
        cout << "Įveskite " << gradeNumber << " pažymį:\n";
        cin >> grade;

        if (!checkUserNumberInput()) {
            grade = 0;
        } else if (!checkGrade(grade)) {
            cout << "Pažymys turi būti nuo 1 iki 10!\n";
        }
    } while (!checkGrade(grade));

    return grade;
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

/**
 * @brief Patikrina, ar sąraše yra mokinių. Jei tuščias, išveda pranešimą.
 * @param studentCount Mokinių skaičius sąraše.
 * @return true, jei mokinių yra; false, jei sąrašas tuščias.
 */
bool checkStudentsCount(int studentCount) {
    if (studentCount == 0) {
        cout << "Mokinių sąrašas tuščias.\n";
        return false;
    }
    return true;
}

/**
 * @brief Išveda mokinio numerį, vardą ir pažymius.
 * @param names Mokinių vardų masyvas.
 * @param grades Mokinių pažymių masyvas.
 * @param gradesCount Kiekvieno mokinio pažymių kiekis.
 * @param studentNumber Mokinio numeris, skaičiuojamas nuo 1.
 */
void printStudentNameAndGrades(string names[100], int grades[100][10], int gradesCount[100], int studentNumber) {
    printSymbols('-', 20);
    cout << studentNumber << ". " << names[studentNumber - 1] << " ";
    for (int i = 0; i < gradesCount[studentNumber - 1]; ++i) {
        cout << grades[studentNumber - 1][i] << " ";
    }
    cout << "\n";
    printSymbols('-', 20);
}

/**
 * @brief Prašo mokinio numerio, kol įvedamas numeris nuo 1 iki studentCount.
 * @param studentCount Esamas mokinių skaičius.
 * @return Tinkamas mokinio numeris.
 */
int inputStudentNumber(int studentCount) {
    int studentNumber = 0;

    do {
        cout << "Įveskite mokinio numerį.\n";
        cin >> studentNumber;

        if (!checkUserNumberInput()) {
            studentNumber = 0;
        } else if (studentNumber < 1 || studentNumber > studentCount) {
            cout << "Neteisingas mokinio numeris. Įveskite nuo 1 iki " << studentCount << ".\n";
        }
    } while (studentNumber < 1 || studentNumber > studentCount);

    return studentNumber;
}

/**
 * @brief Patikrina, ar mokinys turi pažymių. Jei neturi, išveda pranešimą.
 * @param count Mokinio pažymių kiekis.
 * @return true, jei pažymių yra; false, jei nėra.
 */
bool checkGradesCount(int count) {
    if (count == 0) {
        cout << "Mokinys pažymių neturi.\n";
        return false;
    }
    return true;
}

int main() {
    string names[100];
    int grades[100][10];
    int studentCount = 0;
    int gradesCount[100] = {};

    int studentNumber;
    int gradeNumber;

    int input;

    do {
        showMenu();

        cin >> input;
        if (!checkUserNumberInput()) {
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

                    if (!checkUserNumberInput()) {
                        gradesCount[studentCount] = -1;
                    } else if (gradesCount[studentCount] < 0 || gradesCount[studentCount] > 10) {
                        cout << "Pažymių kiekis turi būti nuo 0 iki 10!\n";
                    }
                } while (gradesCount[studentCount] < 0 || gradesCount[studentCount] > 10);

                for (int i = 0; i < gradesCount[studentCount]; ++i) {
                    grades[studentCount][i] = inputGrade(i + 1);
                }

                studentCount++;
                break;
            case 2:
                if (!checkStudentsCount(studentCount)) {
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
                if (!checkStudentsCount(studentCount)) {
                    break;
                }

                cout << "Šiuo metu yra mokinių: " << studentCount << "\n";
                studentNumber = inputStudentNumber(studentCount);
                printStudentNameAndGrades(names, grades, gradesCount, studentNumber);
                break;
            case 4:
                if (!checkStudentsCount(studentCount)) {
                    break;
                }

                studentNumber = inputStudentNumber(studentCount);
                cout << "Jūs pasirinkote mokinį nr " << studentNumber << ".\n";

                if (!checkGradesCount(gradesCount[studentNumber - 1])) {
                    break;
                }

                cout << "Dabartiniai pažymiai: ";
                for (int i = 0; i < gradesCount[studentNumber - 1]; ++i) {
                    cout << grades[studentNumber - 1][i] << " ";
                }

                do {
                    cout << "\nĮveskite pažymio eilės numerį (nuo 1 iki " << gradesCount[studentNumber - 1] << "):\n";
                    cin >> gradeNumber;
                    if (!checkUserNumberInput()) {
                        gradeNumber = 0;
                    } else if (gradeNumber < 1 || gradeNumber > gradesCount[studentNumber - 1]) {
                        cout << "Neteisingas pažymio numeris. Įveskite nuo 1 iki " << gradesCount[studentNumber - 1] <<
                                ".\n";
                    }
                } while (gradeNumber < 1 || gradeNumber > gradesCount[studentNumber - 1]);

                grades[studentNumber - 1][gradeNumber - 1] = inputGrade(gradeNumber);
                cout << "Pažymys sėkmingai atnaujintas\n";
                printStudentNameAndGrades(names, grades, gradesCount, studentNumber);
                break;
            case 5: {
                if (!checkStudentsCount(studentCount)) {
                    break;
                }
                studentNumber = inputStudentNumber(studentCount);
                if (!checkGradesCount(gradesCount[studentNumber - 1])) {
                    break;
                }
                double sum = 0;

                for (int i = 0; i < gradesCount[studentNumber - 1]; ++i) {
                    sum += grades[studentNumber - 1][i];
                }
                double avg = sum / gradesCount[studentNumber - 1];
                cout << format("Studento {} vidurkis yra: {:.2f}\n", names[studentNumber - 1], avg);
                break;
            }
            case 6:
                if (!checkStudentsCount(studentCount)) {
                    break;
                }

                studentNumber = inputStudentNumber(studentCount);

                for (int i = studentNumber - 1; i < studentCount - 1; ++i) {
                    names[i] = names[i + 1];
                    gradesCount[i] = gradesCount[i + 1];

                    for (int j = 0; j < gradesCount[i]; ++j) {
                        grades[i][j] = grades[i + 1][j];
                    }
                }

                studentCount--;
                cout << "Mokinys pašalintas.\n";
                break;
            case 7:
                cout << "Viso gero!\n";
                break;
            default:
                cout << "Blogas pasirinkimas!\n";
        }
    } while (input != 7);
}
