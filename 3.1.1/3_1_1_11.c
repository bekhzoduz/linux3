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
    // Create the user "zelda" with specified home directory and shell
    printf("Creating the user 'zelda'...\n");
    execute_command("sudo useradd -m -d /zeldahome -s /bin/bash zelda");

    // Set a password for the user (you can change "password" to your desired password)
    printf("Setting a password for 'zelda'...\n");
    execute_command("echo 'zelda:password' | sudo chpasswd");

    // Run the check_zelda binary located in root's home directory
    printf("Running the check_zelda binary...\n");
    execute_command("sudo /root/check_zelda");

    return 0;
}
