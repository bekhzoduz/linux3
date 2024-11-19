#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>

int main() {
    const char *path = "/var/ss/supergiant";
    struct stat fileStat;

    // Check if the file exists
    if (stat(path, &fileStat) < 0) {
        perror("Failed to get file status");
        return 1;
    }

    // Get the owner and group information
    struct passwd *pw = getpwuid(fileStat.st_uid);
    struct group *grp = getgrgid(fileStat.st_gid);

    // Check permissions
    if (pw != NULL && grp != NULL) {
        // Check if the owner is 'jupiter'
        if (strcmp(pw->pw_name, "jupiter") != 0) {
            printf("The file is not owned by 'jupiter'. Found owner: %s\n", pw->pw_name);
            return 1;
        }

        // Check if the group is 'dwarfs'
        if (strcmp(grp->gr_name, "dwarfs") != 0) {
            printf("The file is not part of the 'dwarfs' group. Found group: %s\n", grp->gr_name);
            return 1;
        }

        // Verify the permissions:
        // Check for Owner Permissions
        if (!(fileStat.st_mode & S_IRUSR)) {
            printf("Owner does not have read permission.\n");
        }
        if (!(fileStat.st_mode & S_IWUSR)) {
            printf("Owner does not have write permission.\n");
        }
        if (!(fileStat.st_mode & S_IXUSR)) {
            printf("Owner does not have execute permission.\n");
        }

        // Check for Group Permissions
        if (!(fileStat.st_mode & S_IRGRP)) {
            printf("Group does not have read permission.\n");
        }
        if (!(fileStat.st_mode & S_IXGRP)) {
            printf("Group does not have execute permission.\n");
        }
        if (fileStat.st_mode & S_IWGRP) {
            printf("Group has write permission (should not).\n");
        }

        // Check for Other Permissions
        if (!(fileStat.st_mode & S_IROTH)) {
            printf("Others do not have read permission.\n");
        }
        if (fileStat.st_mode & (S_IWOTH | S_IXOTH)) {
            printf("Others have write or execute permission (should not).\n");
        }

        // Final Permission Check
        if ((fileStat.st_mode & S_IRUSR) && 
            (fileStat.st_mode & S_IWUSR) && 
            (fileStat.st_mode & S_IXUSR) && 
            (fileStat.st_mode & S_IRGRP) && 
            (fileStat.st_mode & S_IXGRP) && 
            !(fileStat.st_mode & S_IWGRP) && 
            (fileStat.st_mode & S_IROTH) && 
            !(fileStat.st_mode & (S_IWOTH | S_IXOTH))) {
            printf("HD{yupiter_quyoshdan_8_barobar_katta}\n");
        } else {
            printf("The permissions are not set correctly.\n");
        }
    } else {
        printf("Failed to retrieve user or group information.\n");
        return 1;
    }

    return 0;
}
