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
        perror("Fayl holatini olishda xatolik yuz berdi");
        return 1;
    }

    // Get the passwd struct for the user 'Makemake'
    struct passwd *pw = getpwnam("Makemake");
    if (pw == NULL) {
        fprintf(stderr, "Xatolik! Makemake foydalanuvchisi topilmadi yoki mavjud emas.\n");
        return 1;
    }

    // Compare the file's owner UID with Makemake's UID
    if (fileStat.st_uid == pw->pw_uid) {
        printf("Ajoyib!\nFlag: HD{massa_elektr_zaryad}\n");
    } else {
        printf("Xatolik! Fayl Makemake foydalanuvchisiga tegishli emas.\n");
    }

    return 0;
}
