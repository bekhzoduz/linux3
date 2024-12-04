#include <stdio.h>
#include <sys/stat.h>
#include <pwd.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BACKUP_FILE "/usr/bin/backup"
#define CRONTAB_ENTRY "0 2 * * * root /usr/bin/backup"

// Function to check if the file exists and is owned by root
int check_backup_file() {
    struct stat fileStat;

    // Check if file exists
    if (stat(BACKUP_FILE, &fileStat) < 0) {
        printf("%s fayli mavjud emas.\n", BACKUP_FILE);
        return 0;
    }

    // Check if the owner is root (UID 0) and group is root (GID 0)
    if (fileStat.st_uid != 0 || fileStat.st_gid != 0) {
        printf("%s fayli root:root ga tegishli emas.\n", BACKUP_FILE);
        return 0;
    }

    // Check if the file is executable
    if (!(fileStat.st_mode & S_IXUSR)) {
        printf("%s fayli bajarilishi mumkin emas.\n", BACKUP_FILE);
        return 0;
    }

    return 1;
}

// Function to check if crontab entry exists
int check_crontab() {
    FILE *fp;
    char buffer[256];
    int found = 0;

    // First try reading from the user crontab
    fp = popen("crontab -l 2>/dev/null", "r");
    if (fp != NULL) {
        while (fgets(buffer, sizeof(buffer), fp) != NULL) {
            // Trim whitespace and check if the crontab entry exists
            if (strstr(buffer, CRONTAB_ENTRY)) {
                found = 1;
                break;
            }
        }
        fclose(fp);
    }

    // If not found in user crontab, check /etc/crontab for system-wide crons
    if (!found) {
        fp = fopen("/etc/crontab", "r");
        if (fp != NULL) {
            while (fgets(buffer, sizeof(buffer), fp) != NULL) {
                // Trim whitespace and check if the crontab entry exists
                if (strstr(buffer, CRONTAB_ENTRY)) {
                    found = 1;
                    break;
                }
            }
            fclose(fp);
        }
    }

    if (found) {
        printf("Crontab entry topildi: %s\n", CRONTAB_ENTRY);
    } else {
        printf("Kerakli crontab yozuvi topilmadi.\n");
    }

    return found;
}

int main() {
    if (check_backup_file() && check_crontab()) {
        printf("HD{Endi_mashina_yaxshi_va_haqiqatan sizniki. Tabriklaymiz!}\n");
    } else {
        printf("Shartlar bajarilmadi. Fayl va crontab konfiguratsiyasini tekshiring.\n");
    }
    return 0;
}
