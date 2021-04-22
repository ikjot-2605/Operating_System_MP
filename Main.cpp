#include <stdio.h>
#include <bits/stdc++.h>
#include "disk_scheduling/Main.cpp"
#include "cpu_scheduling/Main.cpp"
#include "page_replacement/Main.cpp"
#include "memory_management/Main.cpp"
#include "process_synchronisation/Main.cpp"
using namespace std;

int main () {
    while (true) {
        cout << endl << endl;
        cout << "Choose one of the following..." << endl;
        cout << "0. Exit the Program" << endl;
        cout << "1. CPU Scheduling" << endl;
        cout << "2. Disk Scheduling" << endl;
        cout << "3. Memory Management" << endl;
        cout << "4. Page Replacement" << endl;
        cout << "5. Process Synchronisation" << endl;
        cout << "Enter your choice here: ";
        int choice; cin >> choice;
        if (choice == 0) {
            cout << "Exitted Program." << endl << endl;
            break;
        } else {
            switch (choice) {
                case 1: cpu_main(); break;
                case 2: disk_main(); break;
                case 3: memory_main(); break;
                case 4: page_main(); break;
                case 5: sync_main(); break;
                default: cout << "Wrong Choice. Please try again." << endl; break;
            }
        }
    }
}