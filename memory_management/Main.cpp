#include <stdio.h>
#include <bits/stdc++.h>
#include "mft_best.c"
#include "mft_first.c"
#include "mft_worst.c"
#include "mvt_tools.cpp"
#include "mvt_best.cpp"
#include "mvt_first.cpp"
#include "mvt_worst.cpp"
using namespace std;

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define RESET "\x1b[0m"

int memory_main() {
    while (true) {
        cout << endl << endl;
        cout << GREEN << "---------- MEMORY MANAGEMENT ---------" << endl;
        cout << GREEN << "Choose one of the following options..." << endl;
        cout << YELLOW << "0. Go back to main menu." << endl;
        cout << BLUE << "1. MFT Best Fit Demo" << endl;
        cout << BLUE << "2. MFT First Fit Demo" << endl;
        cout << BLUE << "3. MFT Worst Fit Demo" << endl;
        cout << BLUE << "4. MVT Best Fit Demo" << endl;
        cout << BLUE << "5. MVT First Fit Demo" << endl;
        cout << BLUE << "6. MVT Worst Fit Demo" << endl;
        cout << YELLOW << "Enter your choice here: " << RESET;
        int choice; cin >> choice;
        if (choice == 0) break;
        else {
            cout << endl << endl;
            switch (choice) {
                case 1: mft_best_main(); break;
                case 2: mft_first_main(); break;
                case 3: mft_worst_main(); break;
                case 4: mvt_best_main(); break;
                case 5: mvt_first_main(); break;
                case 6: mvt_worst_main(); break;
                default: cout << YELLOW << "Invalid Choice. Please try again"; break;
            }
        }
    }
}