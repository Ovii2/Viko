#include <iostream>
#include <string>
#include <iomanip>
#include <locale>
#include <format>

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

    int input;
    int currency;
    double eurAmount;

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
                    cout << "1 USD = " << USD_Bendras << " EUR" << endl;
                } else if (currency == 2) {
                    cout << "1 GBP = " << GBP_Bendras << " EUR" << endl;
                } else if (currency == 3) {
                    cout << "1 INR = " << INR_Bendras << " EUR" << endl;
                } else {
                    cout << "Blogas pasirinkimas" << endl
                            << "Galimi pasirinkimai : 1, 2, 3" << endl;
                }
                break;
            case 2:
                cout << "\nPasirinkote valiutos pirkima (EUR -> pasirinkta valiuta).\n";
                cout << "---Pasirinkite norima valiuta---\n"
                        << "1. EUR -> USD\n"
                        << "2. EUR -> GBP\n"
                        << "3. EUR -> INR\n";

                cin >> currency;

                if (currency == 1) {
                    cout << "Iveskite norima kieki (10, 150, 4200...)" << endl;
                    cin >> eurAmount;

                    cout << format("Jus nusipirkote {:.2Lf} USD uz {:.2Lf} EUR",
                                   eurAmount * USD_Pirkti, eurAmount) << endl;
                } else if (currency == 2) {
                    cout << "Iveskite norima kieki (10, 150, 4200...)" << endl;
                    cin >> eurAmount;

                    cout << format("Jus nusipirkote {:.2Lf} GBP uz {:.2Lf} EUR",
                                   eurAmount * GBP_Pirkti, eurAmount) << endl;
                } else if (currency == 3) {
                    cout << "Iveskite norima kieki (10, 150, 4200...)" << endl;
                    cin >> eurAmount;

                    cout << format("Jus nusipirkote {:.2Lf} INR uz {:.2Lf} EUR",
                                   eurAmount * INR_Pirkti, eurAmount) << endl;
                } else {
                    cout << "Blogas pasirinkimas" << endl
                            << "Galimi pasirinkimai : 1, 2, 3" << endl;
                }
                cout << endl;
                break;
            case 3:
                cout << "\nPasirinkote valiutos pardavima (pasirinkta valiuta -> EUR).\n";
                cout << "---Pasirinkite norima valiuta---\n"
                        << "1. USD -> EUR\n"
                        << "2. GBP -> EUR\n"
                        << "3. INR -> EUR\n";

                cin >> currency;

                if (currency == 1) {
                    cout << "Iveskite norima kieki (15, 400, 1024...)" << endl;
                    double usdAmount;
                    cin >> usdAmount;

                    cout << format("Jus pardavete {:.2Lf} USD uz {:.2Lf} EUR", usdAmount,
                                   usdAmount / USD_Parduoti) << endl;
                } else if (currency == 2) {
                    cout << "Iveskite norima kieki (15, 400, 1024...)" << endl;
                    double gbpAmount;
                    cin >> gbpAmount;

                    cout << format("Jus pardavete {:.2Lf} GBP uz {:.2Lf} EUR", gbpAmount,
                                   gbpAmount / GBP_Parduoti) << endl;
                } else if (currency == 3) {
                    cout << "Iveskite norima kieki (15, 400, 1024...)" << endl;
                    double inrAmount;
                    cin >> inrAmount;

                    cout << format("Jus pardavete {:.2Lf} INR uz {:.2Lf} EUR", inrAmount,
                                   inrAmount / INR_Parduoti) << endl;
                } else {
                    cout << "Blogas pasirinkimas" << endl
                            << "Galimi pasirinkimai : 1, 2, 3" << endl;
                }

                cout << endl;
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
