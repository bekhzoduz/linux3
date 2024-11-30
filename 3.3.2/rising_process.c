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

    // Array of process names to kill
    const char *processes[] = {
        "/usr/bin/system_monitor",
        "/usr/bin/network_service", 
        "/usr/bin/backup_daemon",
        "/usr/bin/cache_cleaner",
        "/usr/bin/log_rotator",
        "/usr/bin/remember",
        "/usr/bin/red-hat",
        "/usr/bin/Haady",
        "/usr/bin/Cybernation", 
        "/usr/bin/Nzrv",
        "/usr/bin/Something_not_useful",
        "/usr/bin/idk_what_to_do"
    };

    // Get process list and kill matching processes
    FILE *fp;
    char cmd[256];
    char line[1024];
    
    // Loop through each process name
    for (int i = 0; i < sizeof(processes)/sizeof(processes[0]); i++) {
        // Build command to get PID of process
        snprintf(cmd, sizeof(cmd), "pidof %s", processes[i]);
        
        // Execute command and get output
        fp = popen(cmd, "r");
        if (fp != NULL) {
            if (fgets(line, sizeof(line), fp) != NULL) {
                // Convert PID string to integer
                pid_t pid = atoi(line);
                if (pid > 0) {
                    // Kill the process
                    kill(pid, SIGKILL);
                }
            }
            pclose(fp);
        }
    }
    // SIGCONT signalini qabul qilish uchun signal handlerni sozlash
    signal(SIGCONT, sigcont_handler);

    // Dastur boshlanganda, faqat "backgroundga o'ting" matnini chiqaramiz
    printf("Meni backgroundga olib o'ting va ortga qaytaring...\n");

    // Jarayonni backgroundga olib o'tish uchun signal kutish
    pause();  // wait until the process is moved to the background with SIGSTOP or other signal

    int choice = 0;

    // Menyuni chiqarish va foydalanuvchidan tanlov so'rash
    int done = 1;
    while (done) {
        print_menu();
        scanf("%d", &choice);

        // Tanlovni tekshirish
        switch (choice) {
            case 1:
                display_flag();
                done = 0;
                break;
            case 2:
                printf("Chiqish...\n");
                done = 0;
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
