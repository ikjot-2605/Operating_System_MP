#include <stdio.h>
#include <bits/stdc++.h>
#include "fcfs.cpp"
#include "hrrn.cpp"
#include "ljf.cpp"
#include "lrtf.cpp"
#include "rr.cpp"
#include "sjf.cpp"
#include "srtf.cpp"
#include "priority_non_p.cpp"
#include "priority_p.cpp"
using namespace std;

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define RESET "\x1b[0m"

int cpu_main() {
    int choice;
    while (true) {
        cout << endl << endl;
        cout << GREEN << "----------- CPU SCHEDULING -----------" << endl;
        cout << GREEN << "Choose one of the following options..." << endl;
        cout << YELLOW << "0. Go back to main menu." << endl;
        cout << BLUE << "1. First Come First Serve Demo" << endl;
        cout << BLUE << "2. Highest Response Ratio Next Demo" << endl;
        cout << BLUE << "3. Longest Job First Demo" << endl;
        cout << BLUE << "4. Longest Remaining Time First Demo" << endl;
        cout << BLUE << "5. Round Robin Demo" << endl;
        cout << BLUE << "6. Shortest Job First Demo" << endl;
        cout << BLUE << "7. Shortest Remaining Time First Demo" << endl;
        cout << BLUE << "8. Non Pre-emptive Priority Scheduling Demo" << endl;
        cout << BLUE << "9. Pre-emptive Priority Scheduling Demo" << endl;
        cout << YELLOW << "Enter your choice here: " << RESET;
        cin >> choice;
        if (choice == 0) break;
        else {
            cout << endl << endl;
            switch (choice) {
                case 1: cpu_fcfs_main(); break;
                case 2: hrrn_main(); break;
                case 3: ljf_main(); break;
                case 4: lrtf_main(); break;
                case 5: rr_main(); break;
                case 6: sjf_main(); break;
                case 7: srtf_main(); break;
                case 8: priority_non_p_main(); break;
                case 9: priority_p_main(); break;
                default: cout << YELLOW << "Invalid Choice. Please try again"; break;
            }
        }
    }
}
