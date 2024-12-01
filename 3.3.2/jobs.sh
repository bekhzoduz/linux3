#!/bin/bash

if [ -f /tmp/jobs_output ]; then
    jobs_output=$(cat /tmp/jobs_output)
    if [ -z "$jobs_output" ]; then
        if [ -f /home/phoenix/.ashes_done ]; then
            ASHES_DONE=$(cat /home/phoenix/.ashes_done)
            if [ $ASHES_DONE == "ASHES_DONE=1" ]; then
                echo $'\n\nPhoenix@Haady dan translatsiya xabari, (qayerdandir) '$(date '+%A, %B %d, %H:%M:%S %Y')$':\n\nXatosiz g\'alaba qozondingiz! Flag:\nHD{Men_yo\'qolgan_bo\'lishim_mumkin, lekin_qaytaman, mana_siz_hali_ham_orzu_qilayotgan_flag}\n'
                rm -f /home/phoenix/.ashes_done
            fi
        fi
    else
        echo "$jobs_output"
    fi
    rm -f /tmp/jobs_output
fi
