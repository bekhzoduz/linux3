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
    // Create the user "senji" (if not already created)
    printf("Creating the user 'senji'...\n");
    execute_command("sudo useradd -m senji");

    // Set a password for the user "senji"
    printf("Setting a password for 'senji'...\n");
    execute_command("echo 'senji:senji' | sudo chpasswd");

    // Add "senji" to the "sudo" group
    printf("Adding 'senji' to the 'sudo' group...\n");
    execute_command("sudo usermod -aG sudo senji");

    // Create the user "cathy" (if not already created)
    printf("Creating the user 'cathy'...\n");
    execute_command("sudo useradd -m cathy");

    // Set a password for the user "cathy"
    printf("Setting a password for 'cathy'...\n");
    execute_command("echo 'cathy:cathy' | sudo chpasswd");

    // Add "cathy" to the "sudo" group
    printf("Adding 'cathy' to the 'sudo' group...\n");
    execute_command("sudo usermod -aG sudo cathy");

    // Add "bill" to the "sudo" group (ensure bill exists)
    printf("Adding 'bill' to the 'sudo' group...\n");
    execute_command("sudo usermod -aG sudo bill");

    // Verify if "senji", "bill", and "cathy" are in the "sudo" group
    printf("Verifying if 'senji' is in the 'sudo' group:\n");
    execute_command("groups senji");

    printf("Verifying if 'bill' is in the 'sudo' group:\n");
    execute_command("groups bill");

    printf("Verifying if 'cathy' is in the 'sudo' group:\n");
    execute_command("groups cathy");

    return 0;
}
