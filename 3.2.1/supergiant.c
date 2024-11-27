#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>

int main() {
    const char *path = "/var/ss/supergiant";
    struct stat fileStat;

    // Check if the file exists
    if (stat(path, &fileStat) < 0) {
        perror("Failed to get file status");
        return 1;
    }

    // Get the owner and group information
    struct passwd *pw = getpwuid(fileStat.st_uid);
    struct group *grp = getgrgid(fileStat.st_gid);

    if (pw == NULL || grp == NULL) {
        printf("Failed to retrieve user or group information.\n");
        return 1;
    }

    // Check if the owner is 'jupiter'
    if (strcmp(pw->pw_name, "Jupiter") != 0) {
        printf("Xatolik! Fayl Jupiter foydalanuvchisiga tegishli emas.\n");
        return 1;
    }

    // Check if the group is 'dwarfs'
    if (strcmp(grp->gr_name, "dwarfs") != 0) {
        printf("Xatolik! Fayl 'dwarfs' guruhiga tegishli emas.\n");
        return 1;
    }

    // Check exact permissions: rwxr-xr--
    mode_t expected = S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH; // 754 in octal
    mode_t mask = S_IRWXU | S_IRWXG | S_IRWXO; // Check all permission bits
    
    if ((fileStat.st_mode & mask) == expected) {
        printf("Ajoyib!\nFlag: HD{yupiter_quyoshdan_8_barobar_katta}\n");
    } else {
        printf("Xatolik! Fayl huquqlari noto'g'ri o'rnatilgan.\n");
        printf("Fayl huquqlari: %o\n", fileStat.st_mode & 0777);
    }

    return 0;
}
