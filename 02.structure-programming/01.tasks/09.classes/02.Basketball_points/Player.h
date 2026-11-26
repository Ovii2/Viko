#ifndef PLAYER_H
#define PLAYER_H
// Sukurkite klasę Krepsininkas su privačiu lauku taskai (int). Pradinis taškų skaičius yra 0.
//
// pridetiTaskus(int kiekis) prideda 1, 2 arba 3 taškus. Perdavus kitą reikšmę taškų skaičius nesikeičia.
// anuliuotiTaskus(int kiekis) atima taškus taisant klaidingą įrašą.
// Galima atimti tik teigiamą kiekį, ne didesnį už turimų taškų skaičių.
// gautiTaskus() grąžina dabartinį taškų skaičių.
// Patikra. Sukūrę krepšininką, pridėkite 2 ir 3 taškus atskirais kvietimais.
// Anuliuokite 2 taškus, tada pabandykite anuliuoti dar 5.
// Išveskite dabartinį taškų skaičių. Laukiamas rezultatas: 3 taškai.

class Player {
    static const int MIN_SHOT_POINTS = 1;
    static const int MAX_SHOT_POINTS = 3;
    static const int MIN_POINTS = 0;

private:
    int points = MIN_POINTS;

public:
    void addPoints(int amount) {
        if (amount > MAX_SHOT_POINTS || amount < MIN_SHOT_POINTS) {
            return;
        }
        points += amount;
    }

    void removePoints(int amount) {
        if (amount <= MIN_POINTS || amount > points) {
            return;
        }
        points -= amount;
    }

    int getPoints() const {
        return points;
    }
};

#endif //PLAYER_H
