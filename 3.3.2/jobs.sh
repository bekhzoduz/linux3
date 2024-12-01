#!/bin/bash

# Tekshiruv - jobs buyruq natijasi bo'sh bo'lsin
if [ ! -z "$(command jobs)" ]; then
    echo "jobs bo'sh emas"
    jobs_output=$(command jobs)
    echo "$jobs_output"
else
    echo "jobs bo'sh"
    if [ "$ASHES_DONE" == "1" ]; then
        echo "ASHES_DONE 1"
        echo "\n\nPhoenix@Haady dan translatsiya xabari, (qayerdandir) $(date '+%A, %B %d, %H:%M:%S %Y'):\n\nXatosiz g'alaba qozondingiz! Flag:\nHD{Men_yo'qolgan_bo'lishim_mumkin, lekin_qaytaman, mana_siz_hali_ham_orzu_qilayotgan_flag}"
    else
        echo "ASHES_DONE 0"
    fi
fi
