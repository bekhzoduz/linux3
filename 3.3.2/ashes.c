#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

// Signal handler to ignore interrupts
void signal_handler(int signum) {
    // Allow SIGSTOP for background operation, ignore others
    if (signum == SIGTSTP) {
        kill(getpid(), SIGSTOP);
    }
    // Check if process is being continued from background (SIGCONT)
    if (signum == SIGCONT) {
        // Check if ashes.txt exists
        char ashes_txt_path[] = "/home/phoenix/ashes.txt";
        if (access(ashes_txt_path, F_OK) != 0) {
            // File doesn't exist, print flag
            printf("HD{Endi_men_yana_bir_bor_qayta_tug'ildim}\n");
        }
    }
}

// Function to generate instruction file
void generate_instructions() {
    FILE *file = fopen("/home/phoenix/ashes.txt", "w");
    if (file != NULL) {
        fprintf(file, "Men mavjud bo'lganimcha davom eta olmayman, lekin davom etsangiz, men mavjud bo'la olmayman.\nMeni o'chiring....\n");
        fclose(file);
    } else {
        perror("ashes.txt yaratishda xatolik");
    }
}

int main() {
    // Set up signal handlers for common termination signals
    signal(SIGINT, signal_handler);  // Ctrl+C
    signal(SIGTERM, signal_handler); // kill
    signal(SIGQUIT, signal_handler); // Ctrl+
    signal(SIGHUP, signal_handler);  // Terminal hangup
    signal(SIGTSTP, signal_handler); // Ctrl+Z

    while(1) {
        // Generate random numbers for captcha
        srand(time(NULL));
        int num1 = rand() % 100;
        int num2 = rand() % 100;
        printf("Boshlashdan oldin, siz robot emasligingizni isbotlang...\nQuyidagi amalning javobi nechchi? %d + %d\nJavobingiz:", num1, num2);

        int user_answer;
        scanf("%d", &user_answer);

        if (user_answer == num1 + num2) {
            generate_instructions();
            printf("Yangi fayl yaratildi: /home/phoenix/ashes.txt\nSizning yurishingiz...");
            break;
        }else{
            printf("Xato javob, qaytadan urinib ko'ring...\n");
            return 0;
        }
    }
    return 0;
}
