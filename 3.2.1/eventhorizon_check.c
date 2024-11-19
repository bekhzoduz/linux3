#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <pwd.h>
#include <string.h>

int main() {
    struct stat fileStat;
    const char *filepath = "/var/ss/eventhorizon";
    
    // Get the file's stat structure
    if (stat(filepath, &fileStat) != 0) {
        perror("Failed to get file status");
        return 1;
    }

    // Get the passwd struct for the user 'Makemake'
    struct passwd *pw = getpwnam("Makemake");
    if (pw == NULL) {
        fprintf(stderr, "Error: Makemake user not found or does not exist.\n");
        return 1;
    }

    // Compare the file's owner UID with Makemake's UID
    if (fileStat.st_uid == pw->pw_uid) {
        printf("HD{massa_elektr_zaryad}\n");
    } else {
        printf("The file is not owned by Makemake.\n");
    }

    return 0;
}
