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

    if (strcmp(pw->pw_name, "Ceres") == 0) {
        printf("Yaxshi, siz flagni ko'rishingiz mumkin:\n");
        // Print the flag
        printf("Flag: HD{Koinot_juda_ham_kattaaaaa!}\n");
    } else {
        printf("Kirish rad etildi. Siz user 'Ceres' bo'lishi kerak.\n");
        return 1;
    }

    return 0;
}
