#include <iostream>
#include <string>

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
                int currency;
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
                cout << "\nPasirinkote valiutos pirkimas (EUR -> pasirinkta valiuta).\n";
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
