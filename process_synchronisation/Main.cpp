#include <stdio.h>
#include <bits/stdc++.h>
#include "bankers.cpp"
#include "producer_consumer.cpp"
#include "dining_philosopher.cpp"
#include "reader_writer.cpp"
using namespace std;

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define RESET "\x1b[0m"

int sync_main() {
    while (true) {
        cout << endl << endl;
        cout << GREEN << "------- PROCESS SYNCHRONISATION ------" << endl;
        cout << GREEN << "Choose one of the following options..." << endl;
        cout << YELLOW << "0. Go back to main menu." << endl;
        cout << BLUE << "1. Producer Consumer Problem Demo" << endl;
        cout << BLUE << "2. Reader Writer Problem Demo" << endl;
        cout << BLUE << "3. Dining Philosophers Problem Demo" << endl;
        cout << BLUE << "4. Bankers Problem Demo" << endl;
        cout << YELLOW << "Enter your choice here: " << RESET;
        int choice; cin >> choice;
        if (choice == 0) break;
        else {
            cout << endl << endl;
            switch (choice) {
                case 1: producer_consumer_main(); break;
                case 2: reader_writer_main(); break;
                case 3: dining_main(); break;
                case 4: bankers_main(); break;
                default: cout << YELLOW << "Invalid Choice. Please try again"; break;
            }
        }
    }
}