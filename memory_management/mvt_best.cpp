#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <bits/stdc++.h>
using namespace std;

// makes an allocation request to the memory stick
// checks is a partition is available
// if yes, it is allocated and that remaining space is split into a new partition
// if no, the request is rejected and a suitable bool value is returned
bool best_allocate_partition(struct process* p) {
    if (p->size > remaining_space) return false;
    struct partition* temp = new struct partition(); int index = -1;

    // best fit partition choice
    temp->size = memory_size + 1;
    for (int i=0; i<partitions.size(); i++)
        if (partitions[i]->pid == -1 && partitions[i]->size >= p->size && partitions[i]->size < temp->size) {
            temp = partitions[i]; index = i; }

    // allocates found partition or returns false
    if (index == -1) return false;
    if (temp->size > p->size) {
        struct partition* temp1 = new struct partition();
        temp1->size = partitions[index]->size - p->size;
        partitions[index]->size = p->size;
        temp1->pid = -1;
        partitions.insert(partitions.begin() + index + 1, temp1);
    }
    partitions[index]->pid = p->pid;
    return true;
}

// deletes partition based on process PID as input
bool best_delete_partition (int n) {
    for (int i=0; i<partitions.size(); i++) {
        if (partitions[i]->pid == n) {
            partitions[i]->pid = -1;
            remaining_space += partitions[i]->size;

            bool left_found = false;
            // merge consecutive free partitions
            if (i > 0 && partitions[i-1]->pid == -1) {
                partitions[i]->size += partitions[i-1]->size;
                partitions.erase(partitions.begin() + i-1);
                left_found = true;
            }
            if (left_found && i < partitions.size() && partitions[i]->pid == -1) {
                partitions[i-1]->size += partitions[i]->size;
                partitions.erase(partitions.begin() + i);
            } else if (i+1 < partitions.size() && partitions[i+1]->pid == -1) {
                partitions[i]->size += partitions[i+1]->size;
                partitions.erase(partitions.begin() + i+1);
            }
            return true;
        }
    } return false;
}

// Driver Code
int mvt_best_main () {
    // getting generic memory stick information
    cout << "Enter total size of memory : ";
    cin >> memory_size; cout << endl;
    remaining_space = memory_size;
    struct partition* full_partition = new struct partition();
    full_partition->size = memory_size; full_partition->pid = -1;
    partitions.push_back(full_partition);

    // user input loop
    while (true) {
        cout << "Make a choice\n{ 1: Insertion, 2: Deletion, 3: Stop Program } : ";
        int choice; cin >> choice;
        if (choice == 3) break; // exit to final output section
        int n; bool allocated_partition; struct process* temp;
        switch (choice) {
            case 1: // make a new allocation request
                temp = new struct process();
                cout << "Process ID : "; cin >> temp->pid;
                cout << "Process Size : "; cin >> temp->size;
                allocated_partition = best_allocate_partition(temp);
                if (allocated_partition) { // success
                    temp->allocation_status = true;
                    remaining_space -= temp->size;
                    cout << "The process was allocated." << endl;
                } else { // failure
                    temp->allocation_status = false;
                    cout << "The process cannot be allocated ";
                    if (temp->size > remaining_space) cout << "as only " << remaining_space << "kb is remaining." << endl;
                    else cout << "due to external fragmentation." << endl;
                }
                break;

            case 2: // unallocate an existing process
                cout << "Process ID to delete : ";
                cin >> n;
                if (best_delete_partition(n)) cout << "The process was unallocated." << endl;
                else cout << "The process ID is not valid." << endl;
                break;
        }
        cout << endl;
    }

    // final output to show memory status
    for (int i = 0 ; i < partitions.size(); i++) {
        cout << "Partition " << i+1;
        if (partitions[i]->pid != -1) cout << " has P" << partitions[i]->pid;
        else cout << " is empty";
        cout << " with size " << partitions[i]->size << endl;
    }
    cout << endl;
}