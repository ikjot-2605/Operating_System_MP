#include <stdio.h>
#include <bits/stdc++.h>
#include "look.c"
#include "clook.c"
#include "scan.c"
#include "cscan.c"
#include "fcfs.c"
#include "sstf.c"
using namespace std;

int disk_main() {
    while (true) {
        cout << endl << endl;
        cout << "Choose one of the following options..." << endl;
        cout << "0. Go back to main menu." << endl;
        cout << "1. LOOK Demo" << endl;
        cout << "2. C-LOOK Demo" << endl;
        cout << "3. SCAN Demo" << endl;
        cout << "4. C-SCAN Demo" << endl;
        cout << "5. FCFS Demo" << endl;
        cout << "6. SSTF Demo" << endl;
        cout << "Enter your choice here: " << endl;
        int choice; cin >> choice;
        if (choice == 0) break;
        else {
            switch (choice) {
                case 1: look_main(); break;
                case 2: clook_main(); break;
                case 3: scan_main(); break;
                case 4: cscan_main(); break;
                case 5: fcfs_main(); break;
                case 6: sstf_main(); break;
                default: cout << "Invalid Choice. Please try again"; break;
            }
        }
    }
}