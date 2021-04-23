#include <stdio.h>
#include <bits/stdc++.h>
#include "look.c"
#include "clook.c"
#include "scan.c"
#include "cscan.c"
#include "fcfs.c"
#include "sstf.c"
using namespace std;

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define RESET "\x1b[0m"

int disk_main() {
    while (true) {
        cout << endl << endl;
        cout << GREEN << "---------- DISK SCHEDULING -----------" << endl;
        cout << GREEN << "Choose one of the following options..." << endl;
        cout << YELLOW << "0. Go back to main menu." << endl;
        cout << BLUE << "1. LOOK Demo" << endl;
        cout << BLUE << "2. C-LOOK Demo" << endl;
        cout << BLUE << "3. SCAN Demo" << endl;
        cout << BLUE << "4. C-SCAN Demo" << endl;
        cout << BLUE << "5. FCFS Demo" << endl;
        cout << BLUE << "6. SSTF Demo" << endl;
        cout << YELLOW << "Enter your choice here: " << RESET;
        int choice; cin >> choice;
        if (choice == 0) break;
        else {
            cout << endl << endl;
            switch (choice) {
                case 1: look_main(); break;
                case 2: clook_main(); break;
                case 3: scan_main(); break;
                case 4: cscan_main(); break;
                case 5: fcfs_main(); break;
                case 6: sstf_main(); break;
                default: cout << YELLOW << "Invalid Choice. Please try again"; break;
            }
        }
    }
}