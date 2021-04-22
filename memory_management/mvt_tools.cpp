// structure to store process information
struct process {
    int pid, size;
    bool allocation_status;
};

// structure to store partition information
struct partition {
    int size, pid;
};

// memory stick variables
int memory_size, remaining_space;
vector <struct partition *> partitions;