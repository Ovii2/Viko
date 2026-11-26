#ifndef INC_01_BIKE_GEARS_BIKE_H
#define INC_01_BIKE_GEARS_BIKE_H

// Sukurkite klasę Dviratis su privačiu lauku pavara (int). Pradinė pavara yra 1, didžiausia – 7.
//
// perjungtiAukstyn() padidina pavarą vienetu, jei ji mažesnė nei 7.
// perjungtiZemyn() sumažina pavarą vienetu, jei ji didesnė nei 1.
// gautiPavara() grąžina dabartinę pavarą.
// Patikra. Sukūrę dviratį, pabandykite perjungti pavarą žemyn. Pavara turi likti 1.
// Tada du kartus perjunkite aukštyn ir išveskite dabartinę pavarą. Laukiamas rezultatas: 3.

class Bike {
    static const int MAX_GEAR = 7;
    static const int MIN_GEAR = 1;

private:
    int currentGear = MIN_GEAR;

public:
    void gearUp() {
        if (currentGear < MAX_GEAR) {
            currentGear++;
        }
    }

    void gearDown() {
        if (currentGear > MIN_GEAR) {
            currentGear--;
        }
    }

    int getGear() const {
        return currentGear;
    }
};


#endif //INC_01_BIKE_GEARS_BIKE_H
