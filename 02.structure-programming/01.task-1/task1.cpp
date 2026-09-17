#include <iostream>
#include <string>
#include <format>

using namespace std;

int main() {
    /*1. Sukurkite kintamuosius ir jiems priskirkite informaciją apie studentą:
     *Vardas, Pavardė, Amžius, Grupė, Kursas, Studijų programos pavadinimas. Išveskite informaciją apie studentą. */

    string name = "Vardenis";
    string lastName = "Pavardenis";
    int age = 19;
    int group = 1;
    int course = 1;
    string courseTitle = "software engineering";

    cout << format("Student {} {} is {} years old. "
                   "Is at group {} course {} studying {}", name, lastName, age, group, course, courseTitle);

    return 0;
}
