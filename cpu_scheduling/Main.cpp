#include <stdio.h>
#include <bits/stdc++.h>
#include "fcfs.cpp"
#include "hrrn.cpp"
#include "ljf.cpp"
#include "lrtf.cpp"
#include "rr.cpp"
#include "sjf.cpp"
#include "srtf.cpp"
using namespace std;

int cpu_main() {
    int choice;
    while (true) {
        cout << "Choose one of the following options..." << endl;
        cout << "0. Go back to main menu." << endl;
        cout << "1. First Come First Serve Demo" << endl;
        cout << "2. Highest Response Ratio Next Demo" << endl;
        cout << "3. Longest Job First Demo" << endl;
        cout << "4. Longest Remaining Time First Demo" << endl;
        cout << "5. Round Robin Demo" << endl;
        cout << "6. Shortest Job First Demo" << endl;
        cout << "7. Shortest Remaining Time First Demo" << endl;
        cout << "Enter your choice here: " << endl;
        if (choice == 0) break;
        else {
            switch (choice) {
                case 1: cpu_fcfs_main(); break;
                case 2: hrrn_main(); break;
                case 3: ljf_main(); break;
                case 4: lrtf_main(); break;
                case 5: rr_main(); break;
                case 6: sjf_main(); break;
                case 7: srtf_main(); break;
                default: cout << "Invalid Choice. Please try again"; break;
            }
        }
    }
}
