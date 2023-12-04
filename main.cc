#include <iostream>

#include "game.h"
#include "GraphicsDisplay.h"

using namespace std;

int main() {
    Game g;
    string command;

    GraphicsDisplay gDisplay(500, 500, 8); // Initialize a graphics display

    while (getline(cin, command)) {
        g.processCommand(command);
    }

    if (cin.eof()) {
        cout << "Final Score:" << endl;
        cout << "White: " << g.getWScore() << endl;
        cout << "Black " << g.getBScore() << endl;
    }

}
