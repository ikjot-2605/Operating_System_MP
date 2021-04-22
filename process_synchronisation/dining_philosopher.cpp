#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <bits/stdc++.h>

using namespace std;

// when true, it indicates that a philosopher is currently looking for chopsticks
bool selection_mutex = false;

// arrays to store question info
bool *chopstick_mutex, *finish_status, *eating_status;
int number_of_finsihed_philosophers = 0, cur_time = 0, *arrival_time, *burst_time;

int n; // stores number of philosophers and chopsticks (equal for this qs)

// checks if the ith philosopher has to wait
bool has_to_wait (int i) {
    return selection_mutex || chopstick_mutex[i] || chopstick_mutex[(i+1)%n];
}

// returns if the ith philosopher can start eating
bool can_start_eating (int i) {
    if (selection_mutex) return false;
    else {
        selection_mutex = true;
        if (chopstick_mutex[i] || chopstick_mutex[(i+1)%n]) {
            selection_mutex = false;
            return false;
        } else {
            chopstick_mutex[i] = true;
            chopstick_mutex[(i+1)%n] = true;
            selection_mutex = false;
            return true;
        }
    }
}

// releases the chopsticks
void release_chopsticks (int i) {
    selection_mutex = true;
    chopstick_mutex[i] = false;
    chopstick_mutex[(i+1)%n] = false;
    selection_mutex = false;
}

// driver code
int dining_main () {
    cout << "Enter number of Philosophers - "; cin >> n;
    chopstick_mutex = new bool [n];
    eating_status = new bool [n];
    finish_status = new bool [n];
    arrival_time = new int [n];
    burst_time = new int [n];

    // get information about the philosophers
    cout << endl << "Enter information about the Philosophers." << endl;
    for (int i=0; i<n; i++) {
        cout << "Philosopher " << i+1 << " Info" << endl;
        cout << "Arrival Time - "; cin >> arrival_time[i];
        cout << "Burst Time   - "; cin >> burst_time[i];
        cout << endl;
    }
    cout << "---" << endl;

    // time loop simulator
    while (number_of_finsihed_philosophers < n) {
        cout << "Logs for time T = " << cur_time << endl;

        for (int i=0; i<n; i++) {
            if (!finish_status[i]) {
                if (arrival_time[i] > cur_time) cout << "Philosopher " << i+1 << " is thinking." << endl;
                else {
                    if (burst_time[i] <= 0) {
                        release_chopsticks(i);
                        finish_status[i] = true; number_of_finsihed_philosophers++;
                        cout << "Philosopher " << i+1 << " has finished eating." << endl;
                    } else if (eating_status[i]) {
                        burst_time[i]--;
                        cout << "Philosopher " << i+1 << " is eating." << endl;
                    } else if (has_to_wait(i)) cout << "Philosopher " << i+1 << " has to wait." << endl;
                    else if (can_start_eating(i)) {
                        eating_status[i] = true;
                        burst_time[i]--;
                        cout << "Philosopher " << i+1 << " has started eating." << endl;
                    } else cout << "Philosopher " << i+1 << " has to wait." << endl;
                }
            } else cout << "Philosopher " << i+1 << " has finished eating." << endl;
        }

        sleep(1); cur_time++;
        cout << endl;
    }
}