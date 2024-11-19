#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pwd.h>
#include <string.h>

int main() {
    // Get the current user ID
    uid_t uid = getuid();

    // Get the passwd struct for the current user
    struct passwd *pw = getpwuid(uid);

    if (pw == NULL) {
        perror("Failed to get user information");
        return 1;
    }

    // Check if the user is "pluto"
    if (strcmp(pw->pw_name, "pluto") == 0) {
        printf("User is pluto. Displaying the flag...\n");
        // Print the flag
        printf("Flag: HD{Koinot_juda_ham_kattaaaaa!}\n");
    } else {
        printf("Access denied. You must be user 'pluto' to see the flag.\n");
        return 1;
    }

    return 0;
}
