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
    // Create the user "bill" if it doesn't already exist
    printf("Creating the user 'bill'...\n");
    execute_command("sudo useradd bill");

    // Set the shell for "bill" to "/bin/dash"
    printf("Setting the shell for 'bill' to '/bin/dash'...\n");
    execute_command("sudo usermod -s /bin/dash bill");

    // Verify the shell for "bill"
    printf("Verifying the shell for 'bill':\n");
    execute_command("getent passwd bill");

    return 0;
}
