#include <iostream>
#include <string>
#include <format>

using namespace std;

int main() {
    /*3. Sukurkite kintamuosius, saugančią informaciją apie automobilį: markė, modelis, pagaminimo metai, litražas ir spalva.
     *Išveskite šiuos duomenis suformatuotus vienoje eilutėje.
     *Pvz.: Automobilis OPEL ZAFIRA yra pagamintas 2010 metais. Jo motoras 2.0 llitrazo. Automobilis yra sidabrinės spalvos. */

    string make = "Opel";
    string model = "Vectra";
    int year = 1999;
    double engine = 2.0;
    string color = "pilkos";

    cout << format("Automobilis {} {} yra pagamintas {} metais. Jo motoras yra {}l litrazo. Automobilis yra {} spalvos.",
                   make, model, year, engine, color);

    return 0;
}
