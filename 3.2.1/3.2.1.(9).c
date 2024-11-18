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
        perror("Failed to open directory");
        return 1;
    }

    struct dirent *entry;
    // Iterate over all the files in the directory
    while ((entry = readdir(dir)) != NULL) {
        // Check if the file name starts with "nova"
        if (strncmp(entry->d_name, file_prefix, strlen(file_prefix)) == 0) {
            printf("File '%s' found! Flag: HD{koinot_rostdan_ham_mavjudmi}\n", entry->d_name);
            file_found = 1;
            break; // Stop searching after the first match
        }
    }

    if (!file_found) {
        printf("No file starting with 'nova' found in %s\n", directory_path);
    }

    // Close the directory
    closedir(dir);

    return 0;
}
