#include <stdio.h>

int main() {
    // Check if zelda user exists by trying to open /etc/passwd
    FILE *fp = fopen("/etc/passwd", "r");
    if (!fp) {
        printf("/etc/passwd faylini ochishda xatolik!\n");
        return 1;
    }

    char line[256];
    int found = 0;
    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, "zelda:")) {
            found = 1;
            break;
        }
    }
    fclose(fp);

    if (found) {
        printf("Ajoyib!\nFlag: HD{foydalanuvchilarni_yaratish_bu_ajoyib!}\n");
    } else {
        printf("'zelda' nomli foydalanuvchi topilmadi!\n");
    }
    return 0;
}

