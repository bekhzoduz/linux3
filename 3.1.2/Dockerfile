FROM ubuntu:20.04

ENV DEBIAN_FRONTEND=noninteractive

# Zarur paketlarni o'rnatish
RUN apt-get update && apt-get install -y \
    rsync \
    curl \
    libc6 \
    vim \
    git \
    htop \
    net-tools \
    tar \
    openssl \
    man-db \
    build-essential \
    software-properties-common \
    wget \
    unzip \
    lsb-release \
    ca-certificates \
    gcc \
    sudo \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

# Foydalanuvchilarni yaratish va sozlash
RUN useradd -m bill && echo "bill:bill" | chpasswd && usermod -aG sudo bill
RUN useradd -m cathy && echo "cathy:cathy" | chpasswd && usermod -aG sudo cathy
RUN useradd -m senji && echo "senji:senji" | chpasswd && usermod -aG sudo senji
RUN useradd -m john && echo "john:john" | chpasswd
RUN useradd -m jane && echo "jane:jane" | chpasswd

# John uchun sudo huquqlari cheklangan
RUN echo "john ALL=(ALL) NOPASSWD: /usr/bin/touch" >> /etc/sudoers

# Cathy uchun to'liq sudo huquqlari
RUN echo "cathy ALL=(ALL) NOPASSWD: ALL" >> /etc/sudoers

# John sudo guruhidan chiqarilgan bo'lsa, tekshirish
RUN id -nG john | grep -qw "sudo" && deluser john sudo || echo "john is not in sudo group"

# Sudo guruhiga faqat kerakli foydalanuvchilarni qo'shish
RUN usermod -aG sudo bill
RUN usermod -aG sudo cathy
RUN usermod -aG sudo senji

USER jane
# "jane" uchun muhit o'zgaruvchisini qo'shish
RUN export JANEFLAG="HD{Taqlid_qilish_bu_super!}" && \
    chown jane:jane /home/jane/.bashrc && \
    chmod 644 /home/jane/.bashrc


# Standart foydalanuvchi sifatida 'cathy'ni o'rnatish
USER cathy
WORKDIR /home/cathy

# Standart buyruq
CMD ["/bin/bash"]
