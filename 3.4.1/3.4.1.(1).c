#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main() {
    srand(time(NULL));  // Seed the random number generator
    int displayFlag = rand() % 5;  // Randomly choose when to display the flag (1 out of 5 times)

    if (displayFlag == 0) {
        printf("HD{Hech_qachon_yondashmang,_hatto_qiyomat_yuzida_ham}\\n");
    } else {
        printf("Bu safar bayroq yo'q, yana urinib ko'ring!\n\n");
    }

    fflush(stdout);  // Make sure output is printed immediately
    sleep(1);  // Pause for 1 second to simulate program running time

    return 0;
}

// watch -n 0.1 /home/phoenix/watchman

