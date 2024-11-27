#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

int all_executable = 1;  // Flag to track if all files are executable

void check_permissions(const char *path) {
    struct stat fileStat;

    // Get the file status
    if (stat(path, &fileStat) < 0) {
        perror("Fayl statusini olishda xatolik");
        return;
    }

    // Check if the file is executable by everyone
    if (!((fileStat.st_mode & S_IXUSR) && // Owner has execute permission
          (fileStat.st_mode & S_IXGRP) && // Group has execute permission
          (fileStat.st_mode & S_IXOTH))) { // Others have execute permission
        // printf("File %s is not executable by everyone.\n", path);
        all_executable = 0;  // Set flag to 0 if any file is not executable
    }
}

void traverse_directory(const char *dir) {
    DIR *d;
    struct dirent *entry;

    if (!(d = opendir(dir))) {
        perror("Fayl yopilganda xatolik");
        return;
    }

    while ((entry = readdir(d)) != NULL) {
        // Skip the current and parent directory entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char path[1024];
        snprintf(path, sizeof(path), "%s/%s", dir, entry->d_name);

        // Check if the entry is a directory or a file
        if (entry->d_type == DT_DIR) {
            // Recursive call for directories
            traverse_directory(path);
        } else {
            // Check permissions for files
            check_permissions(path);
        }
    }

    closedir(d);
}

int main() {
    const char *path = "/var/ss";

    // Traverse the directory and check permissions
    traverse_directory(path);

    // Print the final result based on the executable flag
    if (all_executable) {
        printf("Barakalla!\nFlag: HD{koinot_sari_cheksizlikka_qadam}\n");
    } else {
        printf("Xatolik! Fayllar talab qilingan huquqlarga ega emas.\n");
    }

    return 0;
}
