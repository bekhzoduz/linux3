#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <string.h>

int main() {
    // Users to check
    const char *katy_user = "katy";
    const char *jesse_user = "jesse";

    // Get password entries for both users
    struct passwd *katy_pw = getpwnam(katy_user);
    struct passwd *jesse_pw = getpwnam(jesse_user);

    // Check if users exist
    if (katy_pw == NULL || jesse_pw == NULL) {
        printf("One or both users do not exist.\n");
        return 1;
    }

    // Get katy's groups
    int katy_ngroups = 0;
    getgrouplist(katy_user, katy_pw->pw_gid, NULL, &katy_ngroups);
    gid_t katy_groups[katy_ngroups];
    getgrouplist(katy_user, katy_pw->pw_gid, katy_groups, &katy_ngroups);

    // Get jesse's groups
    int jesse_ngroups = 0;
    getgrouplist(jesse_user, jesse_pw->pw_gid, NULL, &jesse_ngroups);
    gid_t jesse_groups[jesse_ngroups];
    getgrouplist(jesse_user, jesse_pw->pw_gid, jesse_groups, &jesse_ngroups);

    // Check katy's groups (should be katy and sudo)
    int katy_has_primary = 0;
    int katy_has_sudo = 0;
    struct group *grp;

    for (int i = 0; i < katy_ngroups; i++) {
        grp = getgrgid(katy_groups[i]);
        if (grp) {
            if (strcmp(grp->gr_name, "katy") == 0) katy_has_primary = 1;
            if (strcmp(grp->gr_name, "sudo") == 0) katy_has_sudo = 1;
        }
    }

    // Check jesse's groups (should be jesse and sudo)
    int jesse_has_primary = 0;
    int jesse_has_sudo = 0;

    for (int i = 0; i < jesse_ngroups; i++) {
        grp = getgrgid(jesse_groups[i]);
        if (grp) {
            if (strcmp(grp->gr_name, "jesse") == 0) jesse_has_primary = 1;
            if (strcmp(grp->gr_name, "sudo") == 0) jesse_has_sudo = 1;
        }
    }

    // Print results
    if (katy_has_primary && katy_has_sudo && jesse_has_primary && jesse_has_sudo) {
        printf("Flag: HD{backdoor_foydalanuvchilarini_o'rnatish_yaxshi_va_yomon}\n");
    } else {
        if (!katy_has_primary || !katy_has_sudo) {
            printf("Katy is missing required groups (needs: katy, sudo)\n");
        }
        if (!jesse_has_primary || !jesse_has_sudo) {
            printf("Jesse is missing required groups (needs: jesse, sudo)\n");
        }
    }

    return 0;
}
