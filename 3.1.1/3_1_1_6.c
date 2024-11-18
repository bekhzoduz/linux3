#include <stdio.h>
#include <stdlib.h>

void execute_command(const char *command) {
    int result = system(command);
    if (result == -1) {
        perror("Command failed");
        exit(EXIT_FAILURE);
    }
}

int main() {
    // Create the "agriculture" group
    printf("Creating the 'agriculture' group...\n");
    execute_command("sudo groupadd agriculture");

    // Create the users "jane" and "bill"
    printf("Creating the user 'jane'...\n");
    execute_command("sudo useradd jane");

    printf("Creating the user 'bill'...\n");
    execute_command("sudo useradd bill");

    // Add "jane" to the "agriculture" group
    printf("Adding 'jane' to the 'agriculture' group...\n");
    execute_command("sudo usermod -aG agriculture jane");

    // Add "bill" to the "agriculture" group
    printf("Adding 'bill' to the 'agriculture' group...\n");
    execute_command("sudo usermod -aG agriculture bill");

    // Verify the users are added to the group
    printf("Verifying that 'jane' and 'bill' are members of the 'agriculture' group:\n");
    execute_command("getent group agriculture");

    return 0;
}

