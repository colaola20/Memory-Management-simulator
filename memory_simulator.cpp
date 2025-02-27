# include <iostream>
using namespace std;

void userMemoryAllocation() {
    unsigned int seed = time(0);
    int ran_num;
    int process_size;
    double num_of_pages;
    int process_id = 0;
    int starting_memory_addr = 2000;
    int unused_space;
    // each process is assigned a random size (1 to 30) pages. There is 100 pages in total.
    // Process size = random number * 80
    int available_space = 100;
    printf("Process ID      Starting Memory Address     Size of the Process MB      Unused Space MB\n");
    do {
        // creates random number between 1 to 30
        ran_num = rand_r(&seed) % 30 + 1;
        //calculates process's size
        process_size = ran_num * 80;
        // calculates number of pages used by a processes
        num_of_pages = ceil(double(process_size) / double(160));
        //calculates unused space left after
        unused_space = 160 * num_of_pages - process_size;

        //printf("Process size is: %d where random number is: %d\n",process_size, ran_num);
        //printf("Number of pages needed: %f\n", num_of_pages);

        // check if there is space available for the next process
        if (available_space > num_of_pages) {
        printf("%d                %d                          %d                          %d\n", process_id, starting_memory_addr, process_size, unused_space);
        }
        //updates available space in the memory
        available_space = available_space - int(num_of_pages);
        //keep track of process's id
        process_id ++;
        // ypdates starting memory address
        starting_memory_addr = starting_memory_addr + process_size;
    }
    while (available_space > 0);
}


int main() {
    int process_num[100];
    userMemoryAllocation();
    return 0;
}