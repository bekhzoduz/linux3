#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <string.h>

void print_menu() {
    printf("1. Print flag\n");
    printf("2. Exit\n");
    printf("3. Background\n");
    printf("INPUT>> ");
}

void display_flag() {
    printf("HD{Sizning_Linux_Bilish_Darajangiz_Katta_Tezlikda_Osayapti!}\n");
}

int main(int argc, char *argv[]) {
    int choice;

    // Check if choice was passed as parameter
    if (argc > 1) {
        choice = atoi(argv[1]);
    } else {
        // Get choice from user input
        print_menu();
        scanf("%d", &choice);
    }

    while (1) {
        switch (choice) {
            case 1:
                display_flag();
                break;
            case 2:
                printf("Exiting...\n");
                exit(0);
            case 3:
                printf("Processni backgroundga o'tkazish...\n");
                kill(getpid(), SIGSTOP); // Stop the process
                break;
                default:
                printf("Xato tanlov! Iltimos, qayta urinib ko'ring.\n");
        }

        // Get next choice from user
        print_menu();
        scanf("%d", &choice);
    }

    return 0;
}
