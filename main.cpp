#include "market.h"

market makeMarket() {
    market m = market();

    // The following choices for template stocks are based off of the top results when I searched "stock" in google

    //                                 name, revenue, expendature, netAssets, hype, numLeft
    sector* defense = new sector("Defense", "iProfiteering Aerospace & Defense ETF");
    defense->addStock(new stock("Southrup", 30000000000.0f, 8000000000.0f, 150000000.0f, 1.1f, 50000000)); // Not far behind
    defense->addStock(new stock("Keydee", 45000000000.0f, 1000000000.0f, 100000000.0f, 1.25f, 90000000)); // Market golden boy
    defense->addStock(new stock("Lightheon", 10000000000.0f, 5000000000.0f, 0.0f, 0.95f, 100000000)); // Not flashy
    defense->addStock(new stock("General Recursions", 25000000000.0f, 50000000000.0f, -25000000000.0f, 1.1f, 50000000)); // Everything's great but the debt
    defense->addStock(new stock("Orb", 100000000.0f, 5000000.0f, -10.0f, 0.9f, 50000000)); // They have a stadium in Denver
    m.addSector(defense);

    sector * tech = new sector("Tech", "Invesco QQQQQ");
    tech->addStock(new stock("Grapefruit", 50000000000.0f, 1000000000.0f, 150000000.0f, 1.2f, 30000000)); // Ol' reliable
    tech->addStock(new stock("Nvy", 20000000000.0f, 15000000000.0f, -5000000000.0f, 2.0f, 50000000)); // These guys just print money!
    tech->addStock(new stock("Closed AL", 10000000000.0f, 20000000000.0f, -10000000000.0f, 3.0f, 10000000)); // They'll make a profit any day now
    tech->addStock(new stock("Elevencent", 11000000000.0f, 1000000000.0f, 0.0f, 1.0f, 80000000)); // 中文文本
    m.addSector(tech);

    sector * energy = new sector("Tech", "SiP Oil and Gas");
    energy->addStock(new stock("GE", 1.0f, 1.0f, 1.0f, 1.81f, 1000)); // WHERE'D THEY GO??
    energy->addStock(new stock("NPOC", 10000000.0f, 250000.0f, 30000000.0f, 0.8f, 500000)); // no comment
    energy->addStock(new stock("Enteron", 10000000000.0f, 10000000000.0f, -100000000000.0f, 1.2f, 10000000)); // Easiest bet in Mini Market!
    energy->addStock(new stock("Eggson", 5000000000.0f, 5000000000.0f, 0.0f, 1.2f, 5000000)); // There's one by my house :)
    m.addSector(energy);
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


