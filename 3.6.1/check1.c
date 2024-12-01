#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fp;
    char line[256];
    int cron_found = 0;

    // Execute 'crontab -l' to list user cron jobs
    fp = popen("crontab -l", "r");
    if (fp == NULL) {
        perror("Failed to run crontab -l");
        return 1;
    }

    // Search for the specific cron job entry
    while (fgets(line, sizeof(line), fp) != NULL) {
        if (strstr(line, "37 13 * * 3")) {
            printf("Flag:\nHD{Anacron_cronga_o‘xshaydi,_lekin_tizim_vaqti-vaqti_bilan_o‘chirilishini_faraz_qiladi}\n");
            cron_found = 1;
            break;
        }
    }

    if (!cron_found) {
        printf("Kerakli cron job topilmadis.\n");
    }

    fclose(fp);
    return 0;
}
