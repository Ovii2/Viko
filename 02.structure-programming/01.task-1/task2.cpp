#include <iostream>
#include <string>
#include <format>

using namespace std;

int main() {
    /*Sukurkite kintamuosius ir jiems priskirkite informaciją apie krepšinio/futbolo klubą
     *(pvz.: Kauno Žalgiris, Vilniaus Rytas, Madrido Real, Londono Arsenalas):
     *Pavadinimas, Įkūrimo metai, Savinininkas, Arena (gali būti stadionas), Vietų skaičius. Išveskite informaciją apie sporto klubą.*/

    string team = "Vilniaus Rytas";
    int established = 1997;
    string owner = "Darius Gudelis";
    string arena = "Arena Vilnius";
    int seatCount = 2500;

    cout << format("{} was established at {}. Is currently owned by {}. Home arena is {}. Fits around {} persons", team,
                   established, owner, arena, seatCount);

    return 0;
}
