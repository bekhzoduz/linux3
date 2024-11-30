#!/bin/bash

# Tekshiruv - jobs buyruq natijasi bo'sh bo'lsin
if [ "$(command jobs)" ]; then
   command jobs
else
    if [ "$ASHES_DONE" == "1" ]; then
        echo "\n\nPhoenix@Haady dan translatsiya xabari, (qayerdandir) $(date '+%A, %B %d, %H:%M:%S %Y'):\n\nXatosiz g'alaba qozondingiz! Flag:\nHD{Men_yo'qolgan_bo'lishim_mumkin, lekin_qaytaman, mana_siz_hali_ham_orzu_qilayotgan_flag}"
    fi
fi
