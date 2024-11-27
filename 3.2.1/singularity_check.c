#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <grp.h>
#include <pwd.h>
#include <errno.h>

int main() {
    const char *path = "/var/ss/singularity";
    struct stat fileStat;

    // Get the file status
    if (stat(path, &fileStat) < 0) {
        perror("Failed to get file status");
        return 1;
    }

    // Check if the file is owned by root
    if (fileStat.st_uid != 0) {
        printf("Xatolik! Fayl root foydalanuvchisiga tegishli emas.\n");
        return 1;
    }

    // Check if the file is part of the 'gasgiants' group
    struct group *grp = getgrnam("gasgiants");
    if (grp == NULL) {
        fprintf(stderr, "Failed to get group information for 'gasgiants'\n");
        return 1;
    }

    if (fileStat.st_gid != grp->gr_gid) {
        printf("Xatolik! Fayl 'gasgiants' guruhi foydalanuvchisiga tegishli emas.\n");
        return 1;
    }

    // Check if permissions are exactly 720
    mode_t expected = S_IRWXU | S_IWGRP; // rwx for owner, w for group
    mode_t mask = S_IRWXU | S_IRWXG | S_IRWXO; // Check all permission bits
    
    if ((fileStat.st_mode & mask) == expected) {
        printf("Ajoyib!\nFlag: HD{qora_tuynuklar_cheksizdir}\n");
    } else {
        printf("Xatolik! Fayl talab qilingan huquqlarga ega emas.\n");
        printf("Fayl huquqlari: %o\n", fileStat.st_mode & 0720);
    }

    return 0;
}
