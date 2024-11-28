#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

// Function to display the flag message

// Function to generate instruction file
void generate_instructions() {
    FILE *file = fopen("instructions.txt", "w");
    if (file != NULL) {
        fprintf(file, "HD{Endi_men_yana_bir_bor_qayta_tug'ildim}\n");
        fclose(file);
    } else {
        perror("Could not create instructions.txt");
    }
}

int main() {

    // Inform the user that the process has started
    printf("Flagni olish uchun instruction.txt fileni oching\n");
    // Generate the instruction file for the students
    generate_instructions();

    return 0;
}
