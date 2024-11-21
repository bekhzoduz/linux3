#include <stdio.h>
#include <sys/stat.h>
#include <pwd.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BACKUP_FILE "/usr/bin/backup"
#define CRONTAB_ENTRY "0 2 * * * /usr/bin/backup\n"

// Function to check if the file exists and is owned by root
int check_backup_file() {
    struct stat fileStat;

    // Check if file exists
    if (stat(BACKUP_FILE, &fileStat) < 0) {
        printf("File %s does not exist.\n", BACKUP_FILE);
        return 0;
    }

    // Check if the owner is root (UID 0)
    struct passwd *pw = getpwuid(fileStat.st_uid);
    if (pw == NULL || fileStat.st_uid != 0) {
        printf("File %s is not owned by root.\n", BACKUP_FILE);
        return 0;
    }

    printf("File %s exists and is owned by root.\n", BACKUP_FILE);
    return 1;
}

// Function to check if crontab entry exists
int check_crontab() {
    FILE *fp = popen("crontab -l", "r");
    if (fp == NULL) {
        printf("Failed to read crontab.\n");
        return 0;
    }

    char line[256];
    int found = 0;

    // Search for the specific crontab entry
    while (fgets(line, sizeof(line), fp) != NULL) {
        if (strcmp(line, CRONTAB_ENTRY) == 0) {
            found = 1;
            break;
        }
    }
    pclose(fp);

    if (found) {
        printf("Crontab entry found: %s", CRONTAB_ENTRY);
    } else {
        printf("Required crontab entry not found.\n");
    }

    return found;
}

int main() {
    if (check_backup_file() && check_crontab()) {
        printf("HD{Endi_mashina_yaxshi_va_haqiqatan sizniki. Tabriklaymiz!}\n");
    } else {
        printf("Conditions not met. Please check the file and crontab configuration.\n");
    }
    return 0;
}
