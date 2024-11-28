# Use Ubuntu 20.04 as the base image
FROM ubuntu:20.04

# Set environment variable to avoid interactive prompts
ENV DEBIAN_FRONTEND=noninteractive

# Update package list and install necessary packages
RUN apt-get update && apt-get install -y \
    gcc \
    build-essential \
    sudo \
    curl \
    rsync \
    git \
    htop \
    net-tools \
    man-db \
    openssl \
    ca-certificates \
    wget \
    unzip \
    tar \
    libc6 \
    lsb-release \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

# Create phoenix user and give sudo privileges
RUN useradd -m phoenix && echo "phoenix:rebirth" | chpasswd && usermod -aG sudo phoenix
RUN echo "phoenix ALL=(ALL) NOPASSWD:ALL" >> /etc/sudoers && mkdir -p /var/rising

# Copy C source files into the container
COPY ./shell_PID_check.c /home/phoenix/shell_PID_check.c
COPY ./remember.c /home/phoenix/remember.c
COPY ./rising_process.c /home/phoenix/rising_process.c
COPY ./ashes.c /home/phoenix/ashes.c

# Create additional small C programs
RUN echo '#include <unistd.h>\nint main(){while(1)sleep(3600);}' > /tmp/system_monitor.c && \
    echo '#include <unistd.h>\nint main(){while(1)sleep(3600);}' > /tmp/network_service.c && \
    echo '#include <unistd.h>\nint main(){while(1)sleep(3600);}' > /tmp/backup_daemon.c && \
    echo '#include <unistd.h>\nint main(){while(1)sleep(3600);}' > /tmp/cache_cleaner.c && \
    echo '#include <unistd.h>\nint main(){while(1)sleep(3600);}' > /tmp/log_rotator.c && \
    gcc -o /usr/bin/system_monitor /tmp/system_monitor.c && \
    gcc -o /usr/bin/network_service /tmp/network_service.c && \
    gcc -o /usr/bin/backup_daemon /tmp/backup_daemon.c && \
    gcc -o /usr/bin/cache_cleaner /tmp/cache_cleaner.c && \
    gcc -o /usr/bin/log_rotator /tmp/log_rotator.c && \
    rm -f /tmp/*.c

# Compile the main C files with correct architecture
RUN gcc -m64 /home/phoenix/shell_PID_check.c -o /home/phoenix/shell_PID_check && rm -f /home/phoenix/shell_PID_check.c
RUN gcc -m64 /home/phoenix/ashes.c -o /home/phoenix/ashes && rm -f /home/phoenix/ashes.c
RUN gcc -m64 /home/phoenix/remember.c -o /usr/bin/remember && rm -f /home/phoenix/remember.c
RUN gcc -m64 /home/phoenix/rising_process.c -o /usr/bin/rising_process && rm -f /home/phoenix/rising_process.c

# Add background processes to run on login
RUN echo "# Start system processes" >> /etc/bash.bashrc && \
    echo "/usr/bin/remember &" >> /etc/bash.bashrc && \
    echo "/usr/bin/system_monitor &" >> /etc/bash.bashrc && \
    echo "/usr/bin/network_service &" >> /etc/bash.bashrc && \
    echo "/usr/bin/backup_daemon &" >> /etc/bash.bashrc && \
    echo "/usr/bin/cache_cleaner &" >> /etc/bash.bashrc && \
    echo "/usr/bin/log_rotator &" >> /etc/bash.bashrc && \
    echo "sleep infinity &" >> /etc/bash.bashrc && \
    echo "tail -f /dev/null &" >> /etc/bash.bashrc && \
    echo "while true; do : ; sleep 3600; done &" >> /etc/bash.bashrc && \
    echo "watch -n 3600 date &" >> /etc/bash.bashrc && \
    echo "ping -i 3600 localhost &" >> /etc/bash.bashrc && \
    echo "top -b -d 3600 &" >> /etc/bash.bashrc && \
    echo "vmstat 3600 &" >> /etc/bash.bashrc && \
    echo "iostat 3600 &" >> /etc/bash.bashrc && \
    echo "while true; do find /proc -maxdepth 1 >/dev/null 2>&1; sleep 3600; done &" >> /etc/bash.bashrc && \
    echo "while true; do df -h >/dev/null 2>&1; sleep 3600; done &" >> /etc/bash.bashrc && \
    echo "while true; do uptime >/dev/null 2>&1; sleep 3600; done &" >> /etc/bash.bashrc && \
    echo "while true; do w >/dev/null 2>&1; sleep 3600; done &" >> /etc/bash.bashrc && \
    echo "while true; do who >/dev/null 2>&1; sleep 3600; done &" >> /etc/bash.bashrc && \
    echo "while true; do last >/dev/null 2>&1; sleep 3600; done &" >> /etc/bash.bashrc && \
    echo "while true; do netstat -an >/dev/null 2>&1; sleep 3600; done &" >> /etc/bash.bashrc && \
    echo "while true; do lsof >/dev/null 2>&1; sleep 3600; done &" >> /etc/bash.bashrc && \
    echo "while true; do ss >/dev/null 2>&1; sleep 3600; done &" >> /etc/bash.bashrc && \
    echo "while true; do free >/dev/null 2>&1; sleep 3600; done &" >> /etc/bash.bashrc && \
    echo "while true; do mpstat >/dev/null 2>&1; sleep 3600; done &" >> /etc/bash.bashrc && \
    echo "while true; do pidstat >/dev/null 2>&1; sleep 3600; done &" >> /etc/bash.bashrc && \
    echo "while true; do sar >/dev/null 2>&1; sleep 3600; done &" >> /etc/bash.bashrc && \
    echo "while true; do dmesg >/dev/null 2>&1; sleep 3600; done &" >> /etc/bash.bashrc && \
    echo "while true; do journalctl >/dev/null 2>&1; sleep 3600; done &" >> /etc/bash.bashrc

# Set the default user to phoenix for running processes
USER phoenix

# Set the working directory
WORKDIR /home/phoenix

# Start the rising_process in the background automatically when the container starts
CMD ["bash"]
