#include <stdio.h>
#include <stdlib.h>

int main() {
    // Path to the flag file
    const char *flag_file = "/root/flag.txt";
    const char *flag_content = "HD{Anacron_cronga_o‘xshaydi,_lekin_tizim_vaqti-vaqti_bilan_o‘chirilishini_faraz_qiladi}";

    // Create and write the flag to the file
    FILE *file = fopen(flag_file, "w");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }
    fprintf(file, "%s\n", flag_content);
    fclose(file);

    return EXIT_SUCCESS;
}

// mkdir -p /root/cron_task
// cd /root/cron_task
// crontab -e => 37 13 * * 3 /root/cron/check1

