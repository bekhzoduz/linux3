#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *file;
    int file_exists = 0;

    // Check if PlayingWithFire file exists in /etc/cron.monthly
    file = fopen("/etc/cron.monthly/PlayingWithFire", "r");
    if (file != NULL) {
        file_exists = 1;
        fclose(file);
    }

    if (file_exists) {
        printf("Vazifa bajarilmadi.\n");
        return 1;
    } else {
        printf("Flag:\nHD{Prometheus_senning_o'zgarishlaringdan_xursand_bo'lar_edigan_edilar}\n");
    }

    return 0;
}
