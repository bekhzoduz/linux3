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
    // Create the group "industry"
    printf("Creating the group 'industry'...\n");
    execute_command("sudo groupadd industry");

    // Create the user "stan"
    printf("Creating the user 'stan'...\n");
    execute_command("sudo useradd stan");

    // Add "stan" to the "industry" group
    printf("Adding 'stan' to the 'industry' group...\n");
    execute_command("sudo usermod -aG industry stan");

    // Verify the group membership for "stan"
    printf("Verifying the group membership for 'stan':\n");
    execute_command("groups stan");

    return 0;
}
