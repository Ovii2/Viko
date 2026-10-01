#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    const double GBP_Bendras = 0.8729;
    const double GBP_Pirkti = 0.8600;
    const double GBP_Parduoti = 0.9220;

    const double USD_Bendras = 1.1793;
    const double USD_Pirkti = 1.1460;
    const double USD_Parduoti = 1.2340;

    const double INR_Bendras = 104.6918;
    const double INR_Pirkti = 101.3862;
    const double INR_Parduoti = 107.8546;

    int input;
    int currency;

    do {
        cout << "----MENU---\n"
                << "1. Valiutos kurso palyginimas su euru.\n"
                << "2. Valiutos pirkimas (EUR -> pasirinkta valiuta).\n"
                << "3. Valiutos pardavimas (pasirinkta valiuta -> EUR).\n"
                << "4. Iseiti.\n"
                << "Pasirinkite veiksma:\n";

        cin >> input;

        switch (input) {
            case 1:
                cout << "\nPasirinkote valiutos kurso palyginima su euru.\n";

                cout << "---Pasirinkite norima valiuta---\n"
                        << "1. USD\n"
                        << "2. GBP\n"
                        << "3. INR\n";

                cin >> currency;

                if (currency == 1) {
                    cout << "1 USD = " << USD_Bendras << " EUR\n";
                } else if (currency == 2) {
                    cout << "1 GBP = " << GBP_Bendras << " EUR\n";
                } else if (currency == 3) {
                    cout << "1 INR = " << INR_Bendras << " EUR\n";
                } else {
                    cout << "Blogas pasirinkimas\n"
                            << "Galimi pasirinkimai : 1, 2, 3\n";
                }
                break;
            case 2:
                double usdAmount;

                cout << "\nPasirinkote valiutos pirkima (EUR -> pasirinkta valiuta).\n";
                cout << "---Pasirinkite norima valiuta---\n"
                        << "1. EUR -> USD\n"
                        << "2. EUR -> GBP\n"
                        << "3. EUR -> INR\n";

                cin >> currency;

                if (currency == 1) {
                    cout << "Iveskite norima kieki (10, 150, 4200...)" << endl;
                    cin >> usdAmount;

                    cout << format("Jus nusipirkote {} USD uz {:.2f} EUR", usdAmount,
                                   usdAmount * USD_Pirkti) << endl;
                } else if (currency == 2) {
                    cout << "Iveskite norima kieki (10, 150, 4200...)" << endl;

                    double gbpAmount;
                    cin >> gbpAmount;

                    cout << format("Jus nusipirkote {} GBP uz {:.2f} EUR", gbpAmount,
                                   gbpAmount * GBP_Pirkti) << endl;
                } else if (currency == 3) {
                    cout << "Iveskite norima kieki (10, 150, 4200...)" << endl;

                    double inrAmount;
                    cin >> inrAmount;

                    cout << format("Jus nusipirkote {} INR uz {:.2f} EUR", inrAmount,
                                   inrAmount * INR_Pirkti) << endl;
                } else {
                    cout << "Blogas pasirinkimas\n"
                            << "Galimi pasirinkimai : 1, 2, 3\n";
                }
                cout << endl;
                break;
            case 3:
                cout << "\nPasirinkote valiutos pardavima (pasirinkta valiuta -> EUR).\n";
                break;
            case 4:
                cout << "\nViso gero!\n";
                break;
            default:
                cout << "Blogas pasirinkimas\n";
        }
    } while (input != 4);


    return 0;
}
