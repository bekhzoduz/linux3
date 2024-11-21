FROM ubuntu:20.04

ENV DEBIAN_FRONTEND=noninteractive

# Install necessary packages
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
    e2fsprogs \
    mtools \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

# Create the user 'phoenix' and set up necessary directories
RUN useradd -m -d /home/phoenix -s /bin/bash phoenix && \
    echo "phoenix:phoenix" | chpasswd && \
    usermod -aG sudo phoenix && \
    mkdir -p /root && \
    echo "root:hack123" | chpasswd


# Copy the flag image into the mounted ext4 file system
COPY flag.img.1 /mnt/ext4/flash.img



# Switch to the phoenix user
USER phoenix

# Set the working directory
WORKDIR /home/phoenix

# Set the entrypoint to bash
CMD [ "/bin/bash" ]
