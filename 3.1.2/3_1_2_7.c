#include <stdio.h>
#include <stdlib.h>

void execute_command(const char *command) {
    int result = system(command);
    if (result == -1) {
        perror("Command execution failed");
        exit(EXIT_FAILURE);
    }
}

int main() {
    // Create the user "john" (if not already created)
    printf("Creating the user 'john'...\n");
    execute_command("useradd -m john");

    // Set a password for the user "john"
    printf("Setting a password for 'john'...\n");
    execute_command("echo 'john:password' | chpasswd");

    // Grant permission to run /usr/bin/touch as root without password
    printf("Granting 'john' permission to run /usr/bin/touch as root...\n");
    FILE *sudoers_file = fopen("/etc/sudoers.d/john", "w");
    if (sudoers_file == NULL) {
        perror("Failed to open sudoers file for writing");
        exit(EXIT_FAILURE);
    }
    fprintf(sudoers_file, "john ALL=(ALL) NOPASSWD: /usr/bin/touch\n");
    fclose(sudoers_file);

    // Set correct permissions for the sudoers file
    execute_command("chmod 440 /etc/sudoers.d/john");

    // Verify that "john" can run /usr/bin/touch
    printf("Verifying if 'john' can execute /usr/bin/touch as root:\n");
    execute_command("sudo -l -U john");

    return 0;
}
