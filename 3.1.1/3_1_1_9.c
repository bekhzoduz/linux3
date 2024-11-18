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
    // Create the user "alie"
    printf("Creating the user 'alie'...\n");
    execute_command("sudo useradd alie");

    // Disable the user account by locking it
    printf("Disabling the user 'alie'...\n");
    execute_command("sudo passwd -l alie");

    // Verify if the user is disabled
    printf("Verifying if the user 'alie' is disabled:\n");
    execute_command("sudo passwd -S alie");

    return 0;
}
