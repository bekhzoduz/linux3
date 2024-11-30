#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <string.h>

// Signal handler to ignore interrupts and handle specific signals
void signal_handler(int signum) {
    // Ignore SIGINT (Ctrl+C), SIGQUIT, and SIGHUP (Terminal hangup)
    if (signum == SIGINT || signum == SIGQUIT || signum == SIGHUP) {
        // Simply ignore these signals, do nothing
        return;
    }

    // If the process is continued from background (SIGCONT)
    if (signum == SIGCONT) {
        char ashes_txt_path[] = "/home/phoenix/ashes.txt";
        if (access(ashes_txt_path, F_OK) != 0) {
            // File doesn't exist, print flag
            printf("HD{Endi_men_yana_bir_bor_qayta_tug'ildim}\n");
            printf("\nHahaha! Nima qilib qo'yganingni hayolinga ham keltirolmaysan... \nSen meni to'xtatolmaysan...\n");
        }else{
            printf("Meni o'chiring...\n");
        }
    }
}

// Function to generate the instructions file
void generate_instructions() {
    FILE *file = fopen("/home/phoenix/ashes.txt", "w");
    if (file != NULL) {
        fprintf(file, "Men mavjud bo'lganimcha davom eta olmayman, lekin davom etsangiz, men mavjud bo'la olmayman.\nMeni o'chiring....\n");
        fclose(file);
    } else {
        perror("ashes.txt yaratishda xatolik\n");
    }
}

int main() {
    // Set up signal handlers for common termination signals
    signal(SIGINT, signal_handler);  // Ctrl+C
    signal(SIGTERM, signal_handler); // kill
    signal(SIGQUIT, signal_handler); // Ctrl+\/
    signal(SIGHUP, signal_handler);  // Terminal hangup
    signal(SIGTSTP, SIG_DFL);        // Let Ctrl+Z work normally by using default handler

    // Step 1: First time the program runs, create ashes.txt
    while (1) {
        // Generate random numbers for CAPTCHA
        srand(time(NULL));
        int num1 = rand() % 10;
        int num2 = rand() % 10;
        printf("Boshlashdan oldin, siz robot emasligingizni isbotlang...\nQuyidagi amalning javobi nechchi? %d + %d\nJavobingiz: ", num1, num2);

        int user_answer;
        scanf("%d", &user_answer);

        if (user_answer == num1 + num2) {
            generate_instructions();
            printf("Yangi fayl yaratildi: /home/phoenix/ashes.txt\nSizning yurishingiz...\n");
            break; // Break out of the loop if CAPTCHA is solved
        } else {
            printf("Xato javob, qaytadan urinib ko'ring...\n");
            // Restart the loop instead of exiting
        }
    }

    // Step 2: After creating the file, enter an infinite loop
    while (1) {
        // This loop will not be interrupted by Ctrl+C or other termination signals
        sleep(1); // The program is running and doing nothing except ignoring signals
    }

    return 0;
}
