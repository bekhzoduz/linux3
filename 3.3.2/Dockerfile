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

# Copy the C source code for the rising process
COPY ./rising_process.c /home/phoenix/rising_process.c

# Copy the startup script
COPY ./start-rising.sh /usr/bin/start-rising.sh

# Compile the C file
RUN gcc -m64 /home/phoenix/rising_process.c -o /usr/bin/rising_process && rm -f /home/phoenix/rising_process.c

# Make the startup script executable
RUN chmod +x /usr/bin/start-rising.sh

# Switch to the phoenix user
USER phoenix

# Set the working directory
WORKDIR /home/phoenix

# Set the default command to the startup script
CMD ["/usr/bin/start-rising.sh"]
