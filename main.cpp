#include "stock.h"

int main() {
    stock s = stock("northrop", 1000000.0f, 100000.0f, 5000.0f, -1000.0f, 2000.0f, 
        1, 5000);
    
    cout << s.debugString();

    int input;
    cin >> input;
    while (input == 1) {
        s.simDay();
        cout << s.debugString();
        cin >> input;
    }
}