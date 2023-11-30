#include <iostream>
#include "game.h"
#include "board.h"

using namespace std;

int main() {
    Board b;
    Game g(b);
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
