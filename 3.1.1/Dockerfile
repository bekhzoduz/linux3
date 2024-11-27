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

# Barcha kodlarni /home/barbarian3 ichiga ko'chirish va kompilyatsiya qilish
RUN mkdir -p /home/barbarian3 && \
    mkdir -p /root && \
    echo "root:hack123" | chpasswd && \
    useradd -m -d /home/Admin -s /bin/bash Admin && \
    echo "Admin:Admin" | chpasswd

COPY ./ /home/barbarian3/

WORKDIR /home/barbarian3

# Barcha .c fayllarni bir marta kompilyatsiya qilish va bajarish
RUN for file in 3_1_1_6.c 3_1_1_7.c 3_1_1_8.c 3_1_1_9.c 3_1_1_10.c; do \
    gcc $file -o ${file%.c}; \
    ./${file%.c}; \
    done

# Keraksiz fayllarni o'chirish
RUN rm -rf /home/barbarian3/*

# check_zelda.c uchun alohida kompilyatsiya
COPY ./check_zelda.c /root
RUN gcc /root/check_zelda.c -o /root/check_zelda && rm -f /root/check_zelda.c

# Foydalanuvchilarni sozlash
RUN usermod -c "Jane Carson" jane && \
    useradd -m -d /home/barbarian3 -s /bin/bash barbarian3 && \
    echo "barbarian3:barbarian03" | chpasswd && \
    usermod -aG sudo barbarian3 && \
    echo "Senji ALL=(ALL) NOPASSWD:ALL" >> /etc/sudoers && \
    deluser barbarian3 sudo && \
    usermod -aG sudo senji

# Admin foydalanuvchi sifatida ishga tushirish
USER Admin
WORKDIR /home/Admin

CMD ["bash"]
