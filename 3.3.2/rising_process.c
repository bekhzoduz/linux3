#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <termios.h>
#include <signal.h>

// Menyuni chiqarish funktsiyasi
void print_menu() {
    printf("1. Flagni chiqarish\n");
    printf("2. Chiqish\n");
    printf("3. Backgroundga o'tish\n");
    printf("INPUT>> ");
}

// Flagni chiqarish funktsiyasi
void display_flag() {
    printf("HD{Sizning_Linux_Bilish_Darajangiz_Katta_Tezlikda_Osayapti!}\n");
}

int main() {
    // Dastur terminalga bog'langanligini tekshirish
    if (!isatty(fileno(stdin))) {
        // Agar dastur background rejimida bo'lsa, hech narsa qilmasin
        kill(getpid(), SIGSTOP);
        exit(0);
    }

    int choice = 0;

    // Menyuni chiqarish va foydalanuvchidan tanlov so'rash
    while (1) {
        print_menu();
        scanf("%d", &choice);

        // Tanlovni tekshirish
        switch (choice) {
            case 1:
                display_flag();
                break;
            case 2:
                printf("Chiqish...\n");
                exit(0);
            case 3:
                printf("Processni backgroundga o'tkazish...\n");
                kill(getpid(), SIGSTOP); // Processni to'xtatish
                break;
            default:
                printf("Xato tanlov! Iltimos, qayta urinib ko'ring.\n");
        }
    }

    return 0;
}
