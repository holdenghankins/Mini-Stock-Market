#include "stock.h"

int main() {
    stock s = stock("northrop", 1000000.0f, 1000000.0f, 5000.0f, 0.0f, 0.0f, 
        1, 5000);
    
    cout << s.debugString() << "\n How far would you like to sim: ";
    int input;
    cin >> input;
    while (input > 0) {
        for (int i = 0; i < input; i++) {
            s.simDay();
        }
        cout << "\n" << s.debugString() << "\n";
        cout << "How far would you like to sim: ";
        cin >> input;
    }
}