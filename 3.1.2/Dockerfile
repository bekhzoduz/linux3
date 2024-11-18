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

# Create users with specific passwords and add them to sudo group
RUN useradd -m bill && echo "bill:bill" | chpasswd && usermod -aG sudo bill
RUN useradd -m cathy && echo "cathy:cathy" | chpasswd && usermod -aG sudo cathy
RUN useradd -m senji && echo "senji:senji" | chpasswd && usermod -aG sudo senji
RUN useradd -m john && echo "john:john" | chpasswd
RUN useradd -m jane && echo "jane:jane" | chpasswd

# Add John to the sudoers file to allow him to run /usr/bin/touch as root without a password
RUN echo "john ALL=(ALL) NOPASSWD: /usr/bin/touch" >> /etc/sudoers

# Add Cathy to sudoers to run sudo without a password
RUN echo "cathy ALL=(ALL) NOPASSWD: ALL" >> /etc/sudoers

# Ensure that only Bill, Cathy, and Senji are in the sudo group, making them the only sudo users
RUN deluser john sudo  # Remove John from sudo group if mistakenly added
RUN usermod -aG sudo bill
RUN usermod -aG sudo cathy
RUN usermod -aG sudo senji

# Copy the C source file to the container and compile it
COPY ./3_1_2_9.c /home/jane/3_1_2_9.c

# Compile the C file
RUN gcc /home/jane/3_1_2_9.c -o /home/jane/3.1.2.9 && rm -f /home/jane/3_1_2_9.c

# Run the compiled binary to create the necessary files during build
RUN /home/jane/3.1.2.9 && rm -f /home/jane/3.1.2.9

# Switch to 'cathy' user
USER cathy

# Set the working directory to '/home/cathy'
WORKDIR /home/cathy

# Set the default command to bash
CMD ["/bin/bash"]
