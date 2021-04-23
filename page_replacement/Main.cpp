#include <stdio.h>
#include <bits/stdc++.h>
#include "fifo.c"
#include "lru.c"
#include "mru.c"
#include "paging.cpp"
#include "optimal.cpp"
using namespace std;

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define RESET "\x1b[0m"

int page_main() {
    while (true) {
        cout << endl << endl;
        cout << GREEN << "---------- PAGE REPLACEMENT ----------" << endl;
        cout << GREEN << "Choose one of the following options..." << endl;
        cout << YELLOW << "0. Go back to main menu." << endl;
        cout << BLUE << "1. First In First Out Demo" << endl;
        cout << BLUE << "2. Least Recently Used Demo" << endl;
        cout << BLUE << "3. Most Recently Used Demo" << endl;
        cout << BLUE << "4. Optimal Page Replacement Demo" << endl;
        cout << BLUE << "5. Paging with FIFO Demo" << endl;
        cout << YELLOW << "Enter your choice here: " << RESET;
        int choice; cin >> choice;
        if (choice == 0) break;
        else {
            cout << endl << endl;
            switch (choice) {
                case 1: fifo_main(); break;
                case 2: lru_main(); break;
                case 3: mru_main(); break;
                case 4: optimal_main(); break;
                case 5: paging_main(); break;
                default: cout << YELLOW << "Invalid Choice. Please try again"; break;
            }
        }
    }
    return 0;
}
