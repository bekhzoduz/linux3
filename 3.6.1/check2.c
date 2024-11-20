#include <stdio.h>
#include <stdlib.h>

#define CRON_FILE "/var/spool/cron/crontabs/root"
#define CRON_JOB "The Playing With Fire cronjob is dangerous!"

int main() {
    FILE *file;
    char line[256];
    int cron_found = 0;

    // Open the crontab file (assuming it's the root crontab file)
    file = fopen(CRON_FILE, "r");
    if (file == NULL) {
        printf("Error opening cron file.\n");
        return 1;
    }

    // Read each line to check if the dangerous cron job is present
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, CRON_JOB) != NULL) {
            cron_found = 1;  // Cron job found
            break;
        }
    }
    fclose(file);

    if (cron_found) {
        // If the cron job is still found, print error message
        printf("Error: Cron job not removed.\n");
        return 1;
    } else {
        // If the cron job is removed, print the flag
        printf("Flag: HD{Prometheus_senning_o'zgarishlaringdan_xursand_bo'lar_edigan_edilar}\n");
    }

    return 0;
}
