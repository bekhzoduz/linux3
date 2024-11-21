#!/bin/bash

# Jane foydalanuvchisini yaratish va home katalogini sozlash
if ! id "jane" &>/dev/null; then
    echo "User 'jane' does not exist. Creating..."
    sudo useradd -m jane
    sudo mkdir -p /home/jane
    sudo chown jane:jane /home/jane
fi

# Jane foydalanuvchisiga JANEFLAG o'zgaruvchisini qo'shish
echo 'export JANEFLAG="HD{Taqlid_qilish_bu_super!}"' | sudo tee -a /home/jane/.bashrc > /dev/null
sudo chown jane:jane /home/jane/.bashrc

# Jane foydalanuvchisiga o'tish va flagni tekshirish
echo "Switching to user 'jane' and verifying the JANEFLAG..."
sudo -u jane bash -c 'source ~/.bashrc; set | grep JANEFLAG'
