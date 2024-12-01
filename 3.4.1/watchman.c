#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define STATE_FILE "/dev/shm/state_file" // Vaqtinchalik fayl yo'li

void write_to_state(const char *key, const char *value) {
    FILE *file = fopen(STATE_FILE, "w");
    if (file) {
        fprintf(file, "%s=%s\n", key, value);
        fclose(file);
    }
}

void read_from_state(char *buffer, size_t size) {
    FILE *file = fopen(STATE_FILE, "r");
    if (file) {
        fgets(buffer, size, file);
        fclose(file);
    } else {
        buffer[0] = '\0'; // Agar fayl yo'q bo'lsa, bo'sh qaytariladi
    }
}

void show_flag_temporarily() {
    printf("\rMana! Men buni ko'rdim. Bir lahzalik yaltirash edi, lekin endi kelajak biroz... yorqinroq ko'rinmoqda.\n\nTik-tak! Sizning flagingiz:\nHD{Hech_qachon_yondashmang,_hatto_qiyomat_yuzida_ham}\n");
}

int main() {
    // Dastur har doim ishlaydi, shuning uchun "watch"ni tekshirish shart emas
    char state[64];
    time_t current_time = time(NULL);
    read_from_state(state, sizeof(state));

    if (state[0] == '\0') {
        // Dastur birinchi marta ishlamoqda
        char time_str[32];
        snprintf(time_str, sizeof(time_str), "%ld", current_time);
        write_to_state("start_time", time_str);
        printf("Hech narsa o'zgarmayapti. Dunyo avvalgidek, lekin kelajak har kuni biroz qorong'iroq ko'rinmoqda.\nIltimos! Ketmang. Kimdir buni amalga oshirishi kerak, tushunayapsizmi? Kimdir dunyoni qutqarishi kerak.\nIltimos, kuzatishda davom eting.\n");
        return 0;
    }

    time_t last_time = atol(state + strlen("start_time="));
    if (current_time - last_time >= 60) {  // 60 soniya kutish
        show_flag_temporarily();
        char time_str[32];
        snprintf(time_str, sizeof(time_str), "%ld", current_time);
        write_to_state("start_time", time_str); // Vaqtni yangilash
    } else {
        printf("Hech narsa o'zgarmayapti. Dunyo avvalgidek, lekin kelajak har kuni biroz qorong'iroq ko'rinmoqda.\nIltimos! Ketmang. Kimdir buni amalga oshirishi kerak, tushunayapsizmi? Kimdir dunyoni qutqarishi kerak.\nIltimos, kuzatishda davom eting.\n");
    }

    return 0;
}