#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    const char *path = "/var/ss/pulsar";
    FILE *file = fopen(path, "r");

    if (file == NULL) {
        perror("Failed to open file");
        return 1;
    }

    // Read the content of the file
    char content[256]; // Adjust size if necessary
    if (fgets(content, sizeof(content), file) != NULL) {
        // Check if the content contains the word "flag"
        if (strstr(content, "flag") != NULL) {
            printf("HD{Quyosh_sistemamizdagi_eng_katta_massa_quyoshga_tegishli}\n");
        } else {
            printf("The file does not contain the word 'flag'.\n");
        }
    } else {
        printf("Failed to read the content of the file.\n");
    }

    fclose(file);
    return 0;
}