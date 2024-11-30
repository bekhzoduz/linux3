#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <termios.h>
#include <signal.h>
#include <stdbool.h>

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

// SIGCONT signaliga javob berish uchun signal handler
void sigcont_handler(int sig) {
    // Bu yerda faqat jarayonni davom ettirishni kutishimiz kerak
}

int main() {
    // Dastur terminalga bog'langanligini tekshirish
    if (!isatty(fileno(stdin))) {
        // Agar dastur background rejimida bo'lsa, hech narsa qilmasin
        kill(getpid(), SIGSTOP);
        exit(0);
    }

    // SIGCONT signalini qabul qilish uchun signal handlerni sozlash
    signal(SIGCONT, sigcont_handler);

    // Dastur boshlanganda, faqat "backgroundga o'ting" matnini chiqaramiz
    printf("Meni backgroundga olib o'ting va ortga qaytaring...\n");

    // Jarayonni backgroundga olib o'tish uchun signal kutish
    pause();  // wait until the process is moved to the background with SIGSTOP or other signal

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
                break;
        }
    }

    return 0;
}
