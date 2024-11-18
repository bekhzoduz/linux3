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
    // Create the user "senji"
    printf("Creating the user 'senji'...\n");
    execute_command("sudo useradd -m senji"); // -m creates a home directory

    // Set a password for the user (you can change "password" to your desired password)
    printf("Setting a password for 'senji'...\n");
    execute_command("echo 'senji:password' | sudo chpasswd");

    // Add "senji" to the "sudo" group to grant root privileges
    printf("Adding 'senji' to the 'sudo' group...\n");
    execute_command("sudo usermod -aG sudo senji");

    // Verify if "senji" has been added to the "sudo" group
    printf("Verifying if 'senji' is in the 'sudo' group:\n");
    execute_command("groups senji");

    return 0;
}
