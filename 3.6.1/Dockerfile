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

# Create user phoenix
RUN useradd -m -s /bin/bash phoenix && \
    echo "phoenix:phoenix123" | chpasswd

# Create root password (Greek word as per the requirement)
RUN echo "root:Chronos" | chpasswd

# Create necessary directories
RUN mkdir -p /root/cron && mkdir -p /home/phoenix

RUN echo "*/1 * * * * echo 'HD{Cron_so''zi_\"Chronos\"dan_kelib_chiqadi,_bu_vaqt_degani}' > /root/flag_cron.txt" >> /etc/crontab


# Create the binaries check1, check2, and play_with_fire.sh as C programs
COPY check1.c /root/cron/check1.c
COPY check2.c /root/cron/check2.c


# Compile the C files to create binaries
RUN gcc /root/cron/check1.c -o /root/cron/check1 && \
    gcc /root/cron/check2.c -o /root/cron/check2

# Make the shell script executable


# Start cron service"
CMD [ "bash" ]
