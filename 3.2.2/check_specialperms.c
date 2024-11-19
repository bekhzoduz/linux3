#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>

int main() {
    const char *nebula_path = "/var/specialperms/nebula";
    const char *binarystar_path = "/var/specialperms/binarystar";
    struct stat nebula_stat, binarystar_stat;

    // Get file stats
    if (stat(nebula_path, &nebula_stat) < 0 || stat(binarystar_path, &binarystar_stat) < 0) {
        perror("Failed to get file status");
        return 1;
    }

    // Check owner of nebula
    struct passwd *nebula_pw = getpwuid(nebula_stat.st_uid);
    if (nebula_pw == NULL || strcmp(nebula_pw->pw_name, "Mars") != 0) {
        printf("The file 'nebula' is not owned by 'Mars'.\n");
        return 1;
    }

    // Check if SUID bit is set on nebula
    if (!(nebula_stat.st_mode & S_ISUID)) {
        printf("The SUID bit is not set on 'nebula'.\n");
        return 1;
    }

    // Check group of binarystar
    struct group *binarystar_grp = getgrgid(binarystar_stat.st_gid);
    if (binarystar_grp == NULL || strcmp(binarystar_grp->gr_name, "icegiants") != 0) {
        printf("The group of 'binarystar' is not 'icegiants'.\n");
        return 1;
    }

    // Check if SGID bit is set on binarystar
    if (!(binarystar_stat.st_mode & S_ISGID)) {
        printf("The SGID bit is not set on 'binarystar'.\n");
        return 1;
    }

    // If all checks pass, print the flag
    printf("HD{yulduzlararo_chang_buluti}\n");

    return 0;
}
