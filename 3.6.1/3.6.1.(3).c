#include <stdio.h>

int main() {

     int result = system("crontab -r");

    if (result == 0) {
        printf("HD{Prometheus_senning_o'zgarishlaringdan_xursand_bo'lar_edigan_edilar}\n");
    }
    return 0;
}



//sudo nano /etc/cron.d/PlayingWithFire => # * * * * * root /bin/bash -c 'echo "This is a dangerous cron job!" >> /root/dangerous.log'
//sudo mkdir -p /root/cron
// sudo nano /root/cron/check2.c


