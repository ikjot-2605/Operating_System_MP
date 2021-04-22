#include <stdio.h>
#include <bits/stdc++.h>
#include "fifo.c"
#include "lru.c"
#include "mru.c"
using namespace std;

int page_main() {
    while (true) {
        cout << "Choose one of the following options..." << endl;
        cout << "0. Go back to main menu." << endl;
        cout << "1. First In First Out Demo" << endl;
        cout << "2. Least Recently Used Demo" << endl;
        cout << "3. Most Recently Used Demo" << endl;
        cout << "Enter your choice here: " << endl;
        int choice; cin >> choice;
        if (choice == 0) break;
        else {
            switch (choice) {
                case 1: fifo_main(); break;
                case 2: lru_main(); break;
                case 3: mru_main(); break;
                default: cout << "Invalid Choice. Please try again"; break;
            }
        }
    }
    return 0;
}
