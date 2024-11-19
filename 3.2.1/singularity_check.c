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

    // Check if the file is part of the group 'gasgiants'
    struct group *grp = getgrnam("gasgiants");
    if (grp == NULL) {
        fprintf(stderr, "Failed to get group information for 'gasgiants'\n");
        return 1;
    }

    // Check if the file belongs to 'gasgiants' group
    if (fileStat.st_gid != grp->gr_gid) {
        printf("The file is not owned by the 'gasgiants' group.\n");
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

    // Check if the file has the expected permissions
    if (isMember &&
        (fileStat.st_mode & S_IRGRP) &&           // Group read permission
        !(fileStat.st_mode & (S_IWGRP | S_IXGRP)) && // No group write or execute permission
        !(fileStat.st_mode & (S_IROTH | S_IWOTH | S_IXOTH))) { // No permissions for others
        printf("HD{qora_tuynuklar_cheksizdir}\n");
    } else {
        printf("The file does not have the expected permissions or you are not a member of the 'gasgiants' group.\n");
        printf("Group ID: %d, Expected Group ID: %d\n", fileStat.st_gid, grp->gr_gid);
        printf("File Permissions: %o\n", fileStat.st_mode & 0777);
    }

    return 0;
}
