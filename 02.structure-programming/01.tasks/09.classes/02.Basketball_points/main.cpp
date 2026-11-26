#include <iostream>
#include "Player.h"
#include <format>

using namespace std;

int main() {
    Player player;
    player.addPoints(2);
    player.addPoints(3);
    player.removePoints(2);
    player.removePoints(5);

    cout << format("Dabartiniai taskai: {}", player.getPoints());

    return 0;
}
