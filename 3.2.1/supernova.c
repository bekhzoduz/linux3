#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

int main() {
    const char *directory_path = "/var/ss/super/";
    const char *file_prefix = "nova";
    int file_found = 0;

    // Open the directory
    DIR *dir = opendir(directory_path);
    if (dir == NULL) {
        perror("Fayl yopilganda xatolik");
        return 1;
    }

    struct dirent *entry;
    // Iterate over all the files in the directory
    while ((entry = readdir(dir)) != NULL) {
        // Check if the file name starts with "nova"
        if (strncmp(entry->d_name, file_prefix, strlen(file_prefix)) == 0) {
            printf("Juda yaxshi %s fayli topildi!\nFlag: HD{koinot_rostdan_ham_mavjudmi}\n", entry->d_name);
            file_found = 1;
            break; // Stop searching after the first match
        }
    }

    if (!file_found) {
        printf("'%s' fayli topilmadi\n", directory_path);
    }

    // Close the directory
    closedir(dir);

    return 0;
}
