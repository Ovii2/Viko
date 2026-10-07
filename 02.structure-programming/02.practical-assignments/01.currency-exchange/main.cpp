#include <iostream>
#include <string>
#include <iomanip>
#include <locale>
#include <format>
#include <limits>

using namespace std;

int main() {
    locale::global(locale("en_US.UTF-8"));

    const double GBP_Bendras = 0.8729;
    const double GBP_Pirkti = 0.8600;
    const double GBP_Parduoti = 0.9220;

    const double USD_Bendras = 1.1793;
    const double USD_Pirkti = 1.1460;
    const double USD_Parduoti = 1.2340;

    const double INR_Bendras = 104.6918;
    const double INR_Pirkti = 101.3862;
    const double INR_Parduoti = 107.8546;

    int input = 0;
    int currency = 0;
    double amount = 0;

    do {
        cout << "----MENU---\n"
                << "1. Valiutos kurso palyginimas su euru.\n"
                << "2. Valiutos pirkimas (EUR -> pasirinkta valiuta).\n"
                << "3. Valiutos pardavimas (pasirinkta valiuta -> EUR).\n"
                << "4. Iseiti.\n"
                << "Pasirinkite veiksma:\n";

        cin >> input;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            input = 0;
            cout << "Blogas pasirinkimas\n\n";
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (input) {
            case 1:
                cout << "\nPasirinkote valiutos kurso palyginima su euru.\n";

                do {
                    cout << "---Pasirinkite norima valiuta---\n"
                            << "1. USD\n"
                            << "2. GBP\n"
                            << "3. INR\n";

                    cin >> currency;
                    if (cin.fail()) {
                        cin.clear();
                        currency = 0;
                    }
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    if (currency < 1 || currency > 3) {
                        cout << "Blogas pasirinkimas" << endl
                                << "Galimi pasirinkimai : 1, 2, 3" << endl << endl;
                    }
                } while (currency < 1 || currency > 3);

                if (currency == 1) {
                    cout << "1 USD = " << USD_Bendras << " EUR" << endl;
                } else if (currency == 2) {
                    cout << "1 GBP = " << GBP_Bendras << " EUR" << endl;
                } else {
                    cout << "1 INR = " << INR_Bendras << " EUR" << endl;
                }
                cout << endl;
                break;
            case 2:
                cout << "\nPasirinkote valiutos pirkima (EUR -> pasirinkta valiuta).\n";

                do {
                    cout << "---Pasirinkite norima valiuta---\n"
                            << "1. EUR -> USD\n"
                            << "2. EUR -> GBP\n"
                            << "3. EUR -> INR\n";

                    cin >> currency;
                    if (cin.fail()) {
                        cin.clear();
                        currency = 0;
                    }
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    if (currency < 1 || currency > 3) {
                        cout << "Blogas pasirinkimas" << endl
                                << "Galimi pasirinkimai : 1, 2, 3" << endl << endl;
                    }
                } while (currency < 1 || currency > 3);

                do {
                    cout << "Iveskite norima kieki (10, 150, 4200...)" << endl;
                    cin >> amount;
                    if (cin.fail()) {
                        cin.clear();
                        amount = 0;
                    }
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    if (amount <= 0) {
                        cout << "Blogas kiekis" << endl << endl;
                    }
                } while (amount <= 0);

                if (currency == 1) {
                    cout << format("Jus nusipirkote {:.2Lf} USD uz {:.2Lf} EUR",
                                   amount * USD_Pirkti, amount) << endl;
                } else if (currency == 2) {
                    cout << format("Jus nusipirkote {:.2Lf} GBP uz {:.2Lf} EUR",
                                   amount * GBP_Pirkti, amount) << endl;
                } else {
                    cout << format("Jus nusipirkote {:.2Lf} INR uz {:.2Lf} EUR",
                                   amount * INR_Pirkti, amount) << endl;
                }
                cout << endl;
                break;
            case 3:
                cout << "\nPasirinkote valiutos pardavima (pasirinkta valiuta -> EUR).\n";

                do {
                    cout << "---Pasirinkite norima valiuta---\n"
                            << "1. USD -> EUR\n"
                            << "2. GBP -> EUR\n"
                            << "3. INR -> EUR\n";

                    cin >> currency;
                    if (cin.fail()) {
                        cin.clear();
                        currency = 0;
                    }
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    if (currency < 1 || currency > 3) {
                        cout << "Blogas pasirinkimas" << endl
                                << "Galimi pasirinkimai : 1, 2, 3" << endl << endl;
                    }
                } while (currency < 1 || currency > 3);

                do {
                    cout << "Iveskite norima kieki (15, 400, 1024...)" << endl;
                    cin >> amount;
                    if (cin.fail()) {
                        cin.clear();
                        amount = 0;
                    }
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    if (amount <= 0) {
                        cout << "Blogas kiekis" << endl << endl;
                    }
                } while (amount <= 0);

                if (currency == 1) {
                    cout << format("Jus pardavete {:.2Lf} USD uz {:.2Lf} EUR", amount,
                                   amount / USD_Parduoti) << endl;
                } else if (currency == 2) {
                    cout << format("Jus pardavete {:.2Lf} GBP uz {:.2Lf} EUR", amount,
                                   amount / GBP_Parduoti) << endl;
                } else {
                    cout << format("Jus pardavete {:.2Lf} INR uz {:.2Lf} EUR", amount,
                                   amount / INR_Parduoti) << endl;
                }
                cout << endl;
                break;
            case 4:
                cout << "\nViso gero!\n";
                break;
            default:
                cout << "Blogas pasirinkimas\n\n";
        }
    } while (input != 4);

    return 0;
}