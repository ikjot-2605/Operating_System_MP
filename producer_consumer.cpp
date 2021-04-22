#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<semaphore.h>
using namespace std;

struct p_c {
    bool producer; // true if it is a producer and false it is a consumer
    int at; // arrival time
    int bt; // burst time
    int id; // count of the producer and consumer, unique id
};

int s = 1; // Semaphore Variable
int empty = 6; //Empty Variable to keep the count of empty cells
int full = 0; // Full Variable to keep the count of occupied cells
int time_c = 0; //Time Variable to calculate completion time

//a function to order according to priority. Producer is given more priority if arrival time of consumer is equal to arrival time of producer
bool comparision(const p_c & x,
    const p_c & y) {
    if (x.at == y.at) {
        if (x.producer == true && y.producer == false) return true;
        else return false;
    } else return x.at < y.at;
}

//Signal Function
int signal(int s) {
    s++;
    return s;
}
//Wait Function
int wait(int s) {
    while (s <= 0);
    s--;
    return s;
}

// Producer Function
void producer(int time_b, int id) {
    s = wait(s);
    full = signal(full);
    empty = wait(empty);
    time_c += time_b; // calculating completion time
    cout << "Producer " << id << " has finished producing at t = " << time_c << endl;
    s = signal(s);
}

// Consumer Function
void consumer(int time_b, int id) {
    s = wait(s);
    full = wait(full);
    empty = signal(empty);
    time_c += time_b; //calculating completion time
    cout << "Consumer " << id << " has finished consuming at t = " << time_c << endl;
    s = signal(s);
}

void producerConsumer() {
    int p = 0, c = 0;
    cout << "Enter Number of Producers : ";
    cin >> p;
    cout << "Enter Number of consumers : ";
    cin >> c;
    int n = c + p;
    vector < p_c > pc(n); // an array of producers and consumers
    queue < p_c > pqueue; // a queue for producers
    queue < p_c > cqueue; // a queue for consumers

    // Take user input
    cout << "Enter the arrival time for all producers : ";
    for (int i = 0; i < p; i++) {
        cin >> pc[i].at;
        pc[i].id = i + 1;
        pc[i].producer = true;
    }
    cout << "Enter the arrival time for all consumers : ";
    for (int j = 0; j < c; j++) {
        cin >> pc[j + p].at;
        pc[j + p].id = j + 1;
        pc[j + p].producer = false;
    }
    cout << "Enter the burst time for all producers : ";
    for (int i = 0; i < p; i++) cin >> pc[i].bt;
    cout << "Enter the burst time for all consumers : ";
    for (int j = 0; j < c; j++) cin >> pc[j + p].bt;

    sort(pc.begin(), pc.end(), comparision);
    int left = n;
    for (int i = 0; i < n; i++) {
        if (pc[i].producer == true) {
            if (s == 1 && empty != 0) {
                pqueue.push(pc[i]);
                p_c x = pqueue.front();
                time_c = max(time_c, x.at);
                cout << "\nProducer " << x.id << " starts producing at t = " << time_c << endl;
                for (int j = i + 1; j < n; j++)
                    if (pc[j].at == x.at) {
                        if (pc[j].producer == true) cout << "   Producer " << pc[j].id << " needs to wait" << endl;
                        else cout << "   Consumer " << pc[j].id << " needs to wait" << endl;
                    }

                producer(x.bt, x.id);
                pqueue.pop();
            } else {
                cout << "Buffer is Full.Producer " << pc[i].id << " Needs to wait" << endl;
                pqueue.push(pc[i]);
            }
        } else {
            if (s == 1 && full != 0) {
                cqueue.push(pc[i]);
                p_c x = cqueue.front();
                time_c = max(time_c, x.at);
                cout << "\nConsumer " << x.id << " starts consuming at t = " << time_c << endl;
                for (int j = i + 1; j < n; j++)
                    if (pc[j].at >= x.at) {
                        if (pc[j].producer == true) cout << "   Producer " << pc[j].id << " needs to wait" << endl;
                        else cout << "   Consumer " << pc[j].id << " needs to wait" << endl;
                    }

                consumer(x.bt, x.id);
                cqueue.pop();
            } else {
                cout << "Buffer is Empty. Consumer " << pc[i].id << " Needs to wait" << endl << endl;
                cqueue.push(pc[i]);
            }
        }
    }

    vector < p_c > left1;
    while (pqueue.size() != 0) {
        cout << pqueue.front().id << endl;
        left1.push_back(pqueue.front());
        pqueue.pop();
    }
    while (cqueue.size() != 0) {
        left1.push_back(cqueue.front());
        cqueue.pop();
    }

    // This is to check and give prefernce to the left producer and consumers, which are kept waitng.
    sort(left1.begin(), left1.end(), comparision);
    n = left1.size();

    for (int i = 0; i < n; i++) {
        if (left1[i].producer == true) {
            if (s == 1 && empty != 0) {
                pqueue.push(left1[i]);
                p_c x = pqueue.front();
                time_c = max(time_c, x.at);
                cout << "\nProducer " << x.id << " starts producing at t = " << time_c << endl;
                for (int j = i + 1; j < n; j++) {
                    if (left1[j].at == x.at) {
                        if (left1[j].producer == true) {
                            cout << "   Producer " << left1[j].id << " needs to wait" << endl;
                        } else {
                            cout << "   Consumer " << left1[j].id << " needs to wait" << endl;
                        }
                    }

                }
                producer(x.bt, x.id);
                pqueue.pop();
            } else {
                cout << "Buffer is Full. Producer " << left1[i].id << " Needs to wait for Consumer" << endl << endl;
                pqueue.push(left1[i]);
            }

        } else {
            if (s == 1 && full != 0) {
                cqueue.push(left1[i]);
                p_c x = cqueue.front();
                time_c = max(time_c, x.at);
                cout << "\nConsumer" << x.id << " starts consuming at t = " << time_c << endl;
                for (int j = i+1; j < n; j++) {
                    if (left1[j].at >= x.at) {
                        if (left1[j].producer == true) {
                            cout << "   Producer " << left1[j].id << " is waiting" << endl;
                        } else {
                            cout << "   Consumer " << left1[j].id << " is waiting" << endl;
                        }
                    }

                }
                consumer(x.bt, x.id);
                cqueue.pop();
            } else {
                cout << "Buffer is Empty. Consumer " << left1[i].id << " Needs to wait for Producer" << endl;
                cqueue.push(left1[i]);
            }

        }
    }

}

int main(){
    
}