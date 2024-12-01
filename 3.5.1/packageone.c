#include <stdio.h>
#include <stdlib.h>

int main() {
    // Check if 568c86b7-bayroq package is installed using dpkg-query
    FILE *fp = popen("dpkg-query -l 568c86b7-bayroq", "r");
    if (fp == NULL) {
        printf("Error checking the package status.\n");
        return 1;
    }

    // If dpkg-query outputs nothing, package is not installed
    char buffer[1024];
    if (fgets(buffer, sizeof(buffer), fp) == NULL) {
        // Package is not found
        printf("Flag: HD{Siz_APTitude_sinovidan_muvoffaqiyatli_o'tdingiz}\n");
    } else {
        // Package is installed
        printf("Error, Nimanidur xato bajardingiz.\n");
    }

    fclose(fp);
    return 0;
}
