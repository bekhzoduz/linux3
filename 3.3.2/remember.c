#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define ALLOC_SIZE 500 * 1024 * 1024 // 500 MB

int main() {

    // Jarayonni ko'proq CPU va xotira ishlatishga majbur qilish
    while (1) {
        void *memory = malloc(ALLOC_SIZE); // 500 MB xotira ajratish
        if (memory == NULL) {
            perror("Memory allocation failed");
            exit(1);
        }
        memset(memory, 0, ALLOC_SIZE); // Ajratilgan xotirani to'ldirish

        // CPUni majburan ishlatish uchun matematik hisoblash
        long long int i, j;
        for (i = 0; i < 1000000000; i++) {
            j = i * i;
        }
        sleep(1); // 1 soniya kutish
    }

    return 0;
}
