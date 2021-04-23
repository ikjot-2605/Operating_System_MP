#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#define MAX_CUSTOMERS 25
using namespace std;

void *customer(void *num);
void *barber(void *);
void randwait(int secs);

//Define the semaphores.
// waitingRoom Limits the # of customers allowed  to enter the waiting room at one time.
sem_t waitingRoom;
// barberChair ensures mutually exclusive access to the barber chair.
sem_t barberChair;
// barberPillow is used to allow the barber to sleep until a customer arrives.
sem_t barberPillow;
// seatBelt is used to make the customer to wait until the barber is done cutting his/her hair.
sem_t seatBelt;
// Flag to stop the barber thread when all customers have been serviced.
int allDone = 0;

int sleeping_barber_main () {
    time_c = 0;
    pthread_t btid;
    pthread_t tid[MAX_CUSTOMERS];
    int i, x, numCustomers, numChairs;
    int Number[MAX_CUSTOMERS];
    int AT[MAX_CUSTOMERS];
    cout << "Enter the number of customers and chairs: ";
    cin >> x; numCustomers = x;
    cin >> x; numChairs = x;

    for (i = 0; i < numCustomers; i++) {
        cout << "Enter Arrival Time for Customer " << i << ": ";
        cin >> AT[i];
        Number[i] = i;
    }

    // Initialize the semaphores with initial values...
    sem_init(&waitingRoom, 0, numChairs);
    sem_init(&barberChair, 0, 1);
    sem_init(&barberPillow, 0, 0);
    sem_init(&seatBelt, 0, 0);

    // Create the barber.
    pthread_create(&btid, NULL, barber, NULL);

    // Create the customers.
    for (i = 0; i < numCustomers; i++)
        if (AT[i] <= time_c) {
            pthread_create(&tid[i], NULL, customer, (void *)&Number[i]);
            cout << "Customer " << i << " has arrived at the parlour waiting room at t = " << time_c << endl;
        } else i--;
    cout << endl;

    for (int i=0; i<numCustomers; i++) pthread_join(tid[i], NULL);

    // When all of the customers are finished, kill the barber thread.
    allDone = 1;
    sem_post(&barberPillow); // Wake the barber so he will exit.
    pthread_join(btid, NULL);
}

void *customer(void *number) {
    int num = *(int *)number; // Leave for the shop and take some random amount of  time to arrive.
    sem_wait(&waitingRoom);
    sem_wait(&barberChair); // The chair is free so give up your spot in the  waiting room.
    sem_post(&waitingRoom); // Wake up the barber...
    cout << "Barber was called by Customer " << num << endl;
    sem_post(&barberPillow); // Wait for the barber to finish cutting your hair.
    sem_wait(&seatBelt);     // Give up the chair.
    sem_post(&barberChair);
    cout << "Customer " << num << " has left the barber shop at t = " << time_c << endl;
}

void *barber(void *junk) {
    // While there are still customers to be serviced... Our barber is omnicient and can tell if there are  customers still on the way to his shop.

    while (!allDone) { // Sleep until someone arrives and wakes you..
        cout << "The Barber is now sleeping." << endl;
        sem_wait(&barberPillow); // Skip this stuff at the end...
        if (!allDone) { // Take a random amount of time to cut the customer's hair.
            cout << "The barber is now cutting hair..." << endl << endl;
            randwait(2); time_c += 2;
            sem_post(&seatBelt);
        }
        else cout << endl << "All customers for the day have been serviced." << endl;
    }
}

void randwait(int secs) {
    sleep(secs);
}