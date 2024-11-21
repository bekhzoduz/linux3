#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <string.h>

int main() {
    // Target user to check (jesse)
    const char *target_user = "jesse";
    const char *check_user = "katy";  // Reference user (katy)

    // Get the password entries for target and reference users
    struct passwd *target_pw = getpwnam(target_user);
    struct passwd *check_pw = getpwnam(check_user);

    // Check if users exist
    if (target_pw == NULL || check_pw == NULL) {
        printf("One or both users do not exist.\n");
        return 1;  // Exit with error if either user does not exist
    }

    // Get the groups the target user belongs to
    int ngroups = 0;
    getgrouplist(target_user, target_pw->pw_gid, NULL, &ngroups); // Get number of groups
    gid_t target_groups[ngroups];
    getgrouplist(target_user, target_pw->pw_gid, target_groups, &ngroups); // Get the actual groups

    // Get the groups the reference user (katy) belongs to
    int check_ngroups = 0;
    getgrouplist(check_user, check_pw->pw_gid, NULL, &check_ngroups); // Get number of groups
    gid_t check_groups[check_ngroups];
    getgrouplist(check_user, check_pw->pw_gid, check_groups, &check_ngroups); // Get the actual groups

    // Check if both users share all groups
    int matched_groups = 1;
    for (int i = 0; i < check_ngroups; i++) {
        int found = 0;
        for (int j = 0; j < ngroups; j++) {
            if (check_groups[i] == target_groups[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            matched_groups = 0;
            break;
        }
    }

    // Print the result
    if (matched_groups) {
        printf("Flag: HD{backdoor_foydalanuvchilarini_o'rnatish_yaxshi_va_yomon}\n");
    } else {
        printf("User '%s' does not belong to the same groups as katy. Access denied.\n", target_user);
    }

    return 0;
}

