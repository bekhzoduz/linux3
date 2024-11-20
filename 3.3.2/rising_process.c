#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h> // Required for kill() and SIGSTOP

void show_menu() {
    printf("1. print flag\n");
    printf("2. exit\n");
    printf("3. background\n");
    printf("Enter your choice: ");
}

int main() {
    char flag[] = "ThisIsTheFlag";
    int choice;

    while (1) {
        show_menu();
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting...\n");
            exit(1);
        }

        switch (choice) {
            case 1:
                printf("Flag: %s\n", flag);
                break;
            case 2:
                printf("Exiting...\n");
                exit(0);
            case 3:
                printf("Sending to background...\n");
                kill(getpid(), SIGSTOP); // Stop the process for backgrounding
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}
