#include <stdio.h>
#include <bits/stdc++.h>
#include "bankers.cpp"
#include "producer_consumer.cpp"
#include "reader_writer.cpp"
using namespace std;

int sync_main() {
    while (true) {
        cout << "Choose one of the following options..." << endl;
        cout << "0. Go back to main menu." << endl;
        cout << "1. Producer Consumenr Problem Demo" << endl;
        cout << "2. Reader Writer Problem Demo" << endl;
        cout << "3. Bankers Problem Demo" << endl;
        cout << "Enter your choice here: " << endl;
        int choice; cin >> choice;
        if (choice == 0) break;
        else {
            switch (choice) {
                case 1: producer_consumer_main(); break;
                case 2: reader_writer_main(); break;
                case 3: bankers_main(); break;
                default: cout << "Invalid Choice. Please try again"; break;
            }
        }
    }
}