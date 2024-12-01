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

int is_watch_running() {
    // Check if parent process name contains "watch"
    char proc_path[256];
    snprintf(proc_path, sizeof(proc_path), "/proc/%d/comm", getppid());
    
    FILE *f = fopen(proc_path, "r");
    if (f) {
        char parent_name[256];
        if (fgets(parent_name, sizeof(parent_name), f)) {
            fclose(f);
            return strstr(parent_name, "watch") != NULL;
        }
        fclose(f);
    }
    return 0;
}

void show_flag_temporarily() {
    printf("\rMana! Men buni ko'rdim. Bir lahzalik yaltirash edi, lekin endi kelajak biroz... yorqinroq ko'rinmoqda.\n\nTik-tak! Sizning flagingiz:\nHD{Hech_qachon_yondashmang,_hatto_qiyomat_yuzida_ham}\n");
    fflush(stdout);
    sleep(2); // Flagni 2 soniya ko'rsatadi
    printf("\r%*s\r", 50, ""); // Flagni o'chiradi
    fflush(stdout);
}

int main() {
    printf("Is watch running: %d\n", is_watch_running());
    if (!is_watch_running()) {
        printf("Hech narsa o'zgarmayapti. Dunyo avvalgidek, lekin kelajak har kuni biroz qorong'iroq ko'rinmoqda.\nIltimos! Ketmang. Kimdir buni amalga oshirishi kerak, tushunayapsizmi? Kimdir dunyoni qutqarishi kerak.\nIltimos, kuzatishda davom eting.\n");
        return 0;
    }

    // Watch orqali ishga tushirilgan bo'lsa
    char state[64];
    time_t current_time = time(NULL);
    read_from_state(state, sizeof(state));

    if (state[0] == '\0') {
        // Dastur birinchi marta ishlamoqda
        write_to_state("start_time", "0");
    }

    time_t last_time = atol(state + strlen("start_time="));
    if (current_time - last_time >= 10) {
        show_flag_temporarily();
        write_to_state("start_time", "0"); // Vaqtni yangilash
    } else {
        printf("Hech narsa o'zgarmayapti. Dunyo avvalgidek, lekin kelajak har kuni biroz qorong'iroq ko'rinmoqda.\nIltimos! Ketmang. Kimdir buni amalga oshirishi kerak, tushunayapsizmi? Kimdir dunyoni qutqarishi kerak.\nIltimos, kuzatishda davom eting.\n");
    }

    return 0;
}
