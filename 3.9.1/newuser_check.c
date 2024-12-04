#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <string.h>

int main() {
    // User to check
    const char *jesse_user = "jesse";

    // Get password entry for jesse
    struct passwd *jesse_pw = getpwnam(jesse_user);

    // Check if user exists
    if (jesse_pw == NULL) {
        printf("Jesse foydalanuvchisi mavjud emas!\n");
        return 1;
    }

    // Get jesse's groups
    int jesse_ngroups = 0;
    getgrouplist(jesse_user, jesse_pw->pw_gid, NULL, &jesse_ngroups);
    gid_t jesse_groups[jesse_ngroups];
    getgrouplist(jesse_user, jesse_pw->pw_gid, jesse_groups, &jesse_ngroups);

    // Check jesse's groups (should be jesse and sudo)
    int jesse_has_primary = 0;
    int jesse_has_sudo = 0;
    struct group *grp;

    for (int i = 0; i < jesse_ngroups; i++) {
        grp = getgrgid(jesse_groups[i]);
        if (grp) {
            if (strcmp(grp->gr_name, "jesse") == 0) jesse_has_primary = 1;
            if (strcmp(grp->gr_name, "sudo") == 0) jesse_has_sudo = 1;
        }
    }

    // Print results
    if (jesse_has_primary && jesse_has_sudo) {
        printf("Barakalla!\nFlag:\nHD{backdoor_foydalanuvchilarini_o'rnatish_yaxshi_va_yomon}\n");
    } else {
        if (!jesse_has_primary || !jesse_has_sudo) {
            printf("Jesse foydalanuvchisi kerakli ruxsatlar berilmagan!\n");
        }
    }

    return 0;
}
