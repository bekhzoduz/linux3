#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

// Komanda bajarish uchun funksiya
void execute_command(const char *command) {
    int result = system(command);
    if (result == -1) {
        perror("Command execution failed");
        exit(EXIT_FAILURE);
    } else if (WEXITSTATUS(result) != 0) {
        fprintf(stderr, "Command '%s' failed with exit code %d\n", command, WEXITSTATUS(result));
        exit(EXIT_FAILURE);
    }
}

int main() {
    // Foydalanuvchi "jane" mavjudligini tekshirish
    printf("Checking if the user 'jane' exists...\n");
    if (system("id -u jane > /dev/null 2>&1") == 0) {
        printf("User 'jane' already exists.\n");
    } else {
        printf("Creating the user 'jane'...\n");
        execute_command("sudo useradd -m jane");
        execute_command("echo 'jane:jane' | sudo chpasswd");
    }

    // "jane" uchun home katalogini tekshirish
    printf("Checking if the home directory '/home/jane' exists...\n");
    if (system("[ -d /home/jane ]") != 0) {
        printf("Home directory '/home/jane' does not exist. Creating...\n");
        execute_command("sudo mkdir -p /home/jane");
        execute_command("sudo chown jane:jane /home/jane");
    }

    // ".bashrc" mavjudligini tekshirish
    printf("Checking if '.bashrc' exists for 'jane'...\n");
    if (system("sudo test -f /home/jane/.bashrc") != 0) {
        printf("Creating the '.bashrc' file for 'jane'...\n");
        FILE *file = fopen("/home/jane/.bashrc", "w");
        if (file) {
            fprintf(file, "export JANEFLAG=\"HD{Taqlid_qilish_bu_super!}\"\n");
            fclose(file);
            execute_command("sudo chown jane:jane /home/jane/.bashrc");
        } else {
            fprintf(stderr, "Failed to create /home/jane/.bashrc: %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }
    } else {
        // ".bashrc" ga flagni qo'shish
        printf("Appending the JANEFLAG to '.bashrc' for 'jane'...\n");
        execute_command("echo 'export JANEFLAG=\"HD{Taqlid_qilish_bu_super!}\"' | sudo tee -a /home/jane/.bashrc > /dev/null");
        execute_command("sudo chown jane:jane /home/jane/.bashrc");
    }

    // "jane" foydalanuvchisiga o'tish va flagni tekshirish
    printf("Switching to user 'jane' and verifying the JANEFLAG...\n");
    execute_command("sudo -i -u jane bash -c 'source ~/.bashrc; set | grep JANEFLAG'");

    printf("\nJANEFLAG successfully set and verified.\n");
    return 0;
}
