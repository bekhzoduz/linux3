#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fp;
    char line[256];
    int cron_found = 0;

    // Open /etc/crontab file
    fp = fopen("/etc/crontab", "r");
    if (fp == NULL) {
        perror("Failed to open /etc/crontab");
        return 1;
    }

    // Search for the specific cron job entry
    while (fgets(line, sizeof(line), fp) != NULL) {
        if (strstr(line, "37 13 * * 3") || strstr(line, "37 13 * * wed")) {
            printf("Flag:\nHD{Anacron_cronga_o‘xshaydi,_lekin_tizim_vaqti-vaqti_bilan_o‘chirilishini_faraz_qiladi}\n");
            cron_found = 1;
            break;
        }
    }

    if (!cron_found) {
        printf("Vazifa bajarilmadi.\n");
    }

    fclose(fp);
    return 0;
}
