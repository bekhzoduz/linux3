#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <grp.h>
#include <pwd.h>
#include <errno.h>

int main() {
    const char *path = "/var/ss/singularity";
    struct stat fileStat;

    // Get the file status
    if (stat(path, &fileStat) < 0) {
        perror("Failed to get file status");
        return 1;
    }

    // Check if the file is owned by root
    if (fileStat.st_uid != 0) { // 0 is root's UID
        printf("Xatolik! Fayl root foydalanuvchisiga tegishli emas.\n");
        return 1;
    }

    // Check if the file is part of the 'gasgiants' group
    struct group *grp = getgrnam("gasgiants");
    if (grp == NULL) {
        fprintf(stderr, "Failed to get group information for 'gasgiants'\n");
        return 1;
    }

    // Check if the file belongs to 'gasgiants' group
    if (fileStat.st_gid != grp->gr_gid) {
        printf("Xatolik! Fayl 'gasgiants' guruhi foydalanuvchisiga tegishli emas.\n");
        return 1;
    }

    // Check if the user is part of the 'gasgiants' group
    gid_t groups[32];
    int ngroups = 32; // Maximum number of groups
    if (getgroups(ngroups, groups) < 0) {
        perror("Failed to get groups for the user");
        return 1;
    }

    int isMember = 0;
    for (int i = 0; i < ngroups; i++) {
        if (groups[i] == grp->gr_gid) {
            isMember = 1;
            break;
        }
    }

    // Check if the file has the expected permissions:
    // - Owner (root) should have all permissions (rwx)
    // - Group (gasgiants) should have only write permission
    // - Others should have no permissions
    if (isMember &&
        (fileStat.st_mode & S_IRWXU) &&           // Owner has all permissions
        (fileStat.st_mode & S_IWGRP) &&           // Group has write permission
        !(fileStat.st_mode & (S_IRGRP | S_IXGRP)) && // No group read or execute permission
        !(fileStat.st_mode & (S_IROTH | S_IWOTH | S_IXOTH))) { // No permissions for others
        printf("Ajoyib!\nFlag: HD{qora_tuynuklar_cheksizdir}\n");
    } else {
        printf("Xatolik! Fayl talab qilingan huquqlarga ega emas yoki siz 'gasgiants' guruhi a'zolari bo'lmasiz.\n");
        printf("Guruhi ID: %d, Tasdiqlangan guruhi ID: %d\n", fileStat.st_gid, grp->gr_gid);
        printf("Fayl huquqlari: %o\n", fileStat.st_mode & 0740);
    }

    return 0;
}
