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
COPY ./start-rising.sh /tmp/start-rising.sh
RUN chmod +x /tmp/start-rising.sh

# Compile the main C files with correct architecture
RUN gcc -m64 /home/phoenix/shell_PID_check.c -o /home/phoenix/shell_PID_check && rm -f /home/phoenix/shell_PID_check.c
RUN gcc -m64 /home/phoenix/ashes.c -o /home/phoenix/ashes && rm -f /home/phoenix/ashes.c
RUN gcc -m64 /home/phoenix/remember.c -o /usr/bin/remember && rm -f /home/phoenix/remember.c
RUN gcc -m64 /home/phoenix/rising_process.c -o /usr/bin/rising && rm -f /home/phoenix/rising_process.c

# Add background processes to run on login
RUN echo "# Start system processes" >> /etc/bash.bashrc && \
    echo "/usr/bin/system_monitor &" >> /etc/bash.bashrc && \
    echo "/usr/bin/network_service &" >> /etc/bash.bashrc && \
    echo "/usr/bin/backup_daemon &" >> /etc/bash.bashrc && \
    echo "/usr/bin/cache_cleaner &" >> /etc/bash.bashrc && \
    echo "/usr/bin/log_rotator &" >> /etc/bash.bashrc && \
    echo "/usr/bin/remember &" >> /etc/bash.bashrc && \
    echo "/usr/bin/red-hat &" >> /etc/bash.bashrc && \
    echo "/usr/bin/Haady &" >> /etc/bash.bashrc && \
    echo "/usr/bin/Cybernation &" >> /etc/bash.bashrc && \
    echo "/usr/bin/Nzrv &" >> /etc/bash.bashrc && \
    echo "/usr/bin/Something_not_useful &" >> /etc/bash.bashrc && \
    echo "/usr/bin/idk_what_to_do &" >> /etc/bash.bashrc && \
    echo "/usr/bin/rising &" >> /etc/bash.bashrc && \
    echo "kill -STOP $!" >> /etc/bash.bashrc && \
    echo "bg %13" >> /etc/bash.bashrc && \
    echo "trap 'kill $(jobs -p)' EXIT" >> /etc/bash.bashrc && \
    echo "export TERM=xterm" >> /etc/bash.bashrc

# Set the default user to phoenix for running processes
USER phoenix

# Set the working directory
WORKDIR /home/phoenix

# Start the rising_process in the background automatically when the container starts
CMD ["bash", "-l"]