#include <stdio.h>
#include <sys/stat.h>

int main() {
    struct stat fileStat;
    const char *filePath = "/var/ss/neutronstar";

    // Check if the file exists and retrieve its file status
    if (stat(filePath, &fileStat) < 0) {
        perror("Error accessing the file");
        return 1;
    }

    // Check if the file is readable and writable by the owner, group, and others
    if ((fileStat.st_mode & S_IRUSR) && (fileStat.st_mode & S_IWUSR) &&  // Owner has read and write permission
        (fileStat.st_mode & S_IRGRP) && (fileStat.st_mode & S_IWGRP) &&  // Group has read and write permission
        (fileStat.st_mode & S_IROTH) && (fileStat.st_mode & S_IWOTH)) {  // Others have read and write permission
        printf("HD{Koinotdagi_eng_yoqtirgan_narsangiz_nima}\n");
    } else {
        printf("The file does not have the required permissions (666).\n");
    }

    return 0;
}

