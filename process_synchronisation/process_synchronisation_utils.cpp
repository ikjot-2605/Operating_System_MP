int time_c = 0; //Time Variable to calculate completion time

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