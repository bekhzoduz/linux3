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
    echo "phoenix:phoenix" | chpasswd

# Create root password (Greek word as per the requirement)
RUN echo "root:Chronos" | chpasswd

# Create necessary directories
RUN mkdir -p /root/cron && mkdir -p /home/phoenix

# Add cron job for phoenix user
RUN echo "* * * * * echo 'HD{Cron_so'\''zi_\"Chronos\"dan_kelib_chiqadi,_bu_vaqt_degani}'" | crontab -u phoenix -


# Copy the check cron C programs (to be compiled)
COPY check1.c /root/check1.c
COPY check2.c /root/check2.c

# Compile the C programs
RUN gcc /root/check1.c -o /root/check1 && rm -f /root/check1.c
RUN gcc /root/check2.c -o /root/check2  && rm -f /root/check2.c

USER phoenix

WORKDIR /home/phoenix

# Start the cron service and keep the container running
CMD service cron start && bash
