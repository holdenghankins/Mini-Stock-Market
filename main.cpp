#include "market.h"

market makeMarket() {
    market m = market();
    
    sector* defense = new sector("Defense", "iProfiteering Aerospace & Defense ETF");
    defense->addStock(new stock("Southrup", 500.0f, 500.0f, 500.0f, 1.0f, 500));
    defense->addStock(new stock("Keydee", 500.0f, 500.0f, -500.0f, 1.5f, 500));
    defense->addStock(new stock("Lightheon", 500.0f, 500.0f, 500.0f, 1.0f, 500));
    defense->addStock(new stock("General Recursions", 500.0f, 500.0f, -1.0f, 1.0f, 500));
    defense->addStock(new stock("Orb", 500.0f, 500.0f, 500.0f, -100000.0f, 500));
    m.addSector(defense);

    return m;
}

int main() {
    market m = makeMarket();
    
    cout << m.toString() << "\n How far would you like to sim: ";
    int input;
    cin >> input;
    while (input > 0) {
        for (int i = 0; i < input; i++) {
            m.simDay();
        }
        cout << "\n" << m.toString() << "\n";
        cout << "How far would you like to sim: ";
        cin >> input;
    }
}


