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
    // Give "cathy" access to run sudo without a password
    printf("Giving 'cathy' access to run sudo without a password...\n");
    execute_command("echo 'cathy ALL=(ALL) NOPASSWD: ALL' | sudo tee /etc/sudoers.d/cathy");

    // Verify if "cathy" can run sudo without a password
    printf("Verifying if 'cathy' can run sudo without a password:\n");
    execute_command("sudo -l -U cathy");

    return 0;
}
