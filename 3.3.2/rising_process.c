#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

void print_menu() {
    printf("1. Print flag\n");
    printf("2. Exit\n");
    printf("3. Background\n");
    printf("INPUT>> ");
}

void display_flag() {
    printf("HD{Sizning_Linux_Bilish_Darajangiz_Katta_Tezlikda_Osayapti!}\n");
}

int main() {
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
                kill(getpid(), SIGSTOP); // Stop the process
                break;
            default:
                printf("Xato tanlov! Iltimos, qayta urinib ko'ring.\n");
        }
    }

    return 0;
}
