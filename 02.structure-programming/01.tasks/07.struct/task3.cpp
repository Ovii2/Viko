#include <iostream>
#include <format>
#include <string>
#include <fstream>

using namespace std;

struct Player {
    string fullName;
    string team;
    int games;
    int points;
};

double calculateAverage(Player player) {
    return player.points / static_cast<double>(player.games);
}

void printBestPlayer(Player players[], int playerCount) {
    int best = 0;
    for (int i = 1; i < playerCount; ++i) {
        if (calculateAverage(players[i]) > calculateAverage(players[best])) {
            best = i;
        }
    }
    cout << format("\nGeriausias zaidejas: {}, {}, vidurkis {:.2f}\n",
                   players[best].fullName, players[best].team, calculateAverage(players[best]));
}

int main() {
    // 3.Sukurti programą, kuri:
    //
    // apibrėžia Zaidejas struktūrą su laukais: vardasPavarde (string), komanda (string), rungtynes (int), taskai (int);
    // iš failo zaidejai.txt nuskaito Eurolygos komandų žaidėjų duomenis;
    // apskaičiuoja kiekvieno žaidėjo pelnytų taškų vidurkį per rungtynes;
    // išveda žaidėjų vardus, pavardes, komandas ir taškų vidurkius;
    // išveda didžiausią taškų vidurkį turinčio žaidėjo vardą, pavardę ir komandą.

    ifstream fin("zaidejai.txt");

    if (!fin.is_open()) {
        cout << "Nepavyko atidaryti failo\n";
        return 1;
    }

    const int MAX_PLAYERS = 100;
    Player players[MAX_PLAYERS];
    int playerCount;

    fin >> playerCount;

    if (!fin || playerCount < 1 || playerCount > MAX_PLAYERS) {
        cout << "Neteisingas zaideju skaicius\n";
        return 1;
    }

    for (int i = 0; i < playerCount; ++i) {
        getline(fin >> ws, players[i].fullName, ';');
        getline(fin, players[i].team, ';');
        fin >> players[i].games;
        fin.ignore();
        fin >> players[i].points;

        if (!fin) {
            cout << format("Nepavyko nuskaityti {} zaidejo duomenu\n", i + 1);
            return 1;
        }
        if (players[i].games <= 0) {
            cout << format("Neteisingas {} zaidejo rungtyniu skaicius\n", i + 1);
            return 1;
        }

        double avg = calculateAverage(players[i]);
        cout << format("{}, {}, pelnytu tasku vidurkis {:.2f}\n", players[i].fullName, players[i].team, avg);
    }

    printBestPlayer(players, playerCount);
}