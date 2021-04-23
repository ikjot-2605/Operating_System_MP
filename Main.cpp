#include <stdio.h>
#include <bits/stdc++.h>
#include "disk_scheduling/Main.cpp"
#include "cpu_scheduling/Main.cpp"
#include "page_replacement/Main.cpp"
#include "memory_management/Main.cpp"
#include "process_synchronisation/Main.cpp"
using namespace std;

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define RESET "\x1b[0m"
#define CLEAR "\033[2J\033[1;1H"

int main () {
    while (true) {
        cout << CLEAR << endl << endl;
        cout << GREEN << "--------- MAIN MENU ----------" << endl;
        cout << GREEN << "Choose one of the following..." << endl;
        cout << YELLOW << "0. Exit the Program" << endl;
        cout << BLUE << "1. CPU Scheduling" << endl;
        cout << BLUE << "2. Disk Scheduling" << endl;
        cout << BLUE << "3. Memory Management" << endl;
        cout << BLUE << "4. Page Replacement" << endl;
        cout << BLUE << "5. Process Synchronisation" << endl;
        cout << YELLOW << "Enter your choice here: " << RESET;
        int choice; cin >> choice;
        if (choice == 0) {
            cout << "Exitted Program." << endl << endl;
            break;
        } else {
            cout << CLEAR;
            switch (choice) {
                case 1: cpu_main(); break;
                case 2: disk_main(); break;
                case 3: memory_main(); break;
                case 4: page_main(); break;
                case 5: sync_main(); break;
                default: cout << YELLOW << "Wrong Choice. Please try again." << endl; break;
            }
        }
    }
}