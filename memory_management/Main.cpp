#include <stdio.h>
#include <bits/stdc++.h>
#include "mft_best.cpp"
#include "mft_first.cpp"
#include "mft_worst.cpp"
#include "mvt_tools.cpp"
#include "mvt_best.cpp"
#include "mvt_first.cpp"
#include "mvt_worst.cpp"
using namespace std;

int memory_main() {
    while (true) {
        cout << endl << endl;
        cout << "Choose one of the following options..." << endl;
        cout << "0. Go back to main menu." << endl;
        cout << "1. MFT Best Fit Demo" << endl;
        cout << "2. MFT First Fit Demo" << endl;
        cout << "3. MFT Worst Fit Demo" << endl;
        cout << "4. MVT Best Fit Demo" << endl;
        cout << "5. MVT First Fit Demo" << endl;
        cout << "6. MVT Worst Fit Demo" << endl;
        cout << "Enter your choice here: " << endl;
        int choice; cin >> choice;
        if (choice == 0) break;
        else {
            switch (choice) {
                case 1: mft_best_main(); break;
                case 2: mft_first_main(); break;
                case 3: mft_worst_main(); break;
                case 4: mvt_best_main(); break;
                case 5: mvt_first_main(); break;
                case 6: mvt_worst_main(); break;
                default: cout << "Invalid Choice. Please try again"; break;
            }
        }
    }
}