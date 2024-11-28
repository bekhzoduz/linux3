#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

// Flag to check if the process is resumed (brought to the foreground)
volatile sig_atomic_t is_foreground = 0;

void print_menu() {
    printf("1. Print flag\n");
    printf("2. Exit\n");
    printf("3. Background\n");
    printf("INPUT>> ");
}

void display_flag() {
    printf("HD{Sizning_Linux_Bilish_Darajangiz_Katta_Tezlikda_Osayapti!}\n");
}

void handle_sigcont(int sig) {
    // This signal handler is triggered when the process is resumed (foregrounded)
    is_foreground = 1;
    printf("\nProcess moved to foreground. Main logic begins...\n");
}

int main() {
    // Set up the signal handler for SIGCONT (resume signal)
    signal(SIGCONT, handle_sigcont);

    // Initially in the background, the process does nothing (silent mode)
    printf("Process started in background... Waiting for SIGCONT to begin logic.\n");

    // The program will wait for the SIGCONT signal to move to the foreground
    while (1) {
        if (is_foreground) {
            // Once moved to the foreground, show the menu and perform the main logic
            int choice;
            while (1) {
                print_menu();
                scanf("%d", &choice);

                switch (choice) {
                    case 1:
                        display_flag();
                        break;
                    case 2:
                        printf("Exiting...\n");
                        exit(0);
                    case 3:
                        printf("Processni backgroundga o'tkazish...\n");
                        // Stop the process (pause execution until resumed)
                        kill(getpid(), SIGSTOP); // Stop the process, like sending it to background
                        break;
                    default:
                        printf("Xato tanlov! Iltimos, qayta urinib ko'ring.\n");
                }
            }
        }
        // If not in the foreground, just wait
        pause();  // Wait for signals
    }

    return 0;
}
