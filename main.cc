#include <iostream>

#include "game.h"
#include "graphicsDisplay.h"

using namespace std;

int main() {
    Game g;
    string command;

    while (getline(cin, command)) {
        g.processCommand(command);
    }

    if (cin.eof()) {
        cout << "Final Score:" << endl;
        cout << "White: " << g.getWScore() << endl;
        cout << "Black " << g.getBScore() << endl;
    }

}
