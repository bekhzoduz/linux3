FROM ubuntu:20.04

# Set non-interactive mode for apt-get
ENV DEBIAN_FRONTEND=noninteractive

# Install necessary packages
RUN apt-get update && apt-get install -y \
    cron \
    rsync \
    curl \
    libc6 \
    vim \
    git \
    bsdutils \
    htop \
    net-tools \
    tar \
    openssl \
    man-db \
    build-essential \
    software-properties-common \
    wget \
    unzip \
    nano \
    lsb-release \
    ca-certificates \
    gcc \
    sudo \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

# Create user phoenix
RUN useradd -m -s /bin/bash phoenix && \
    echo "phoenix:phoenix" | chpasswd

# Create root password (Greek word as per the requirement)
RUN echo "root:Chronos" | chpasswd

# Create necessary directories
RUN mkdir -p /root/cron && mkdir -p /home/phoenix

USER root

# Remove and recreate wtmp file with correct permissions and ownership
RUN rm -f /var/log/wtmp && \
    touch /var/log/wtmp && \
    chmod 664 /var/log/wtmp && \
    chown root:utmp /var/log/wtmp

# Create fake user login
RUN touch /tmp/wtmp.txt && \
    echo '[1] [0000] [haady pts/1 192.168.1.100 2024-12-01 12:00]' >> /tmp/wtmp.txt && \
    echo '[2] [0000] [alice pts/2 10.0.0.55 2024-12-01 13:15]' >> /tmp/wtmp.txt && \
    echo '[3] [0000] [bob pts/0 172.16.0.100 2024-12-01 14:30]' >> /tmp/wtmp.txt && \
    echo '[4] [0000] [carol pts/3 192.168.0.25 2024-12-01 15:45]' >> /tmp/wtmp.txt && \
    echo '[5] [0000] [dave pts/1 10.10.0.15 2024-12-01 16:20]' >> /tmp/wtmp.txt && \
    echo '[6] [0000] [eve pts/2 172.20.0.50 2024-12-01 17:00]' >> /tmp/wtmp.txt && \
    echo '[7] [0000] [frank pts/4 192.168.2.75 2024-12-01 18:30]' >> /tmp/wtmp.txt && \
    echo '[8] [0000] [grace pts/0 10.0.1.100 2024-12-01 19:45]' >> /tmp/wtmp.txt && \
    echo '[9] [0000] [henry pts/3 172.16.1.200 2024-12-01 20:15]' >> /tmp/wtmp.txt && \
    echo '[10] [0000] [chuck pts/1 192.168.3.150 2024-12-01 21:30]' >> /tmp/wtmp.txt && \
    utmpdump -r /tmp/wtmp.txt > /var/log/wtmp && \
    rm -f /tmp/wtmp.txt


# Add cron job for phoenix user
RUN echo "* * * * * echo 'HD{Cron_so\'zi_\"Chronos\"dan_kelib_chiqadi,_bu_vaqt_degani}'" | crontab -u phoenix - && \
    echo '#!/bin/bash\necho "The Playing With Fire cronjob is dangerous!"' > /etc/cron.monthly/PlayingWithFire && \
    chmod +x /etc/cron.monthly/PlayingWithFire


# Copy the check cron C programs (to be compiled)
COPY check1.c /root/check1.c
COPY check2.c /root/check2.c

# Compile the C programs
RUN gcc /root/check1.c -o /root/cron/check1 && rm -f /root/check1.c
RUN gcc /root/check2.c -o /root/cron/check2  && rm -f /root/check2.c

USER phoenix

WORKDIR /home/phoenix

CMD ["bash"]
