#include <stdio.h>
#include <sys/stat.h>

int main() {
    struct stat fileStat;
    const char *filePath = "/var/ss/neutronstar";

    // Check if the file exists and retrieve its file status
    if (stat(filePath, &fileStat) < 0) {
        perror("Faylga kirishda xatolik yuz berdi");
        return 1;
    }

    // Check if the file is readable and writable by the owner, group, and others
    if ((fileStat.st_mode & S_IRUSR) && (fileStat.st_mode & S_IWUSR) && (fileStat.st_mode & S_IXUSR) && // Owner has all permissions
        (fileStat.st_mode & S_IRGRP) && (fileStat.st_mode & S_IWGRP) &&  // Group has read and write permission
        (fileStat.st_mode & S_IROTH)) {  // Others have read permission
        printf("Juda yaxshi!\nHD{Koinotdagi_eng_yoqtirgan_narsangiz_nima}\n");
    } else {
        printf("Xatolik! Fayl 766 darajadagi ruxsatlarga ega emas.\n");
    }

    return 0;
}

