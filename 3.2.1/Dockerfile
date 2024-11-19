# Use a minimal base image with GCC installed
FROM ubuntu:20.04

ENV DEBIAN_FRONTEND=noninteractive

# Install necessary packages
RUN apt-get update && apt-get install -y \
    rsync \
    curl \
    libc6 \
    vim \
    git \
    nano \
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
    sudo && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

    RUN groupadd -f pluto && groupadd -f gasgiants && groupadd -f dwarfs && \
    useradd -m -d /home/pluto -s /bin/bash -g pluto pluto && \
    echo "pluto:solarsystem" | chpasswd && \
    mkdir -p /var/ss && \
    useradd -m -d /home/Makemake -s /bin/bash Makemake && \
    echo "Makemake:Makemake" | chpasswd && \
    usermod -aG gasgiants pluto && \
    usermod -aG sudo pluto && \
    usermod -aG sudo Makemake && \
    useradd -m jupiter && \
    useradd -m dwarf1 -g dwarfs && \
    useradd -m dwarf2 -g dwarfs

# Allow pluto to use sudo without password
RUN echo "pluto ALL=(ALL) NOPASSWD:ALL" >> /etc/sudoers

# Copy the C source files into the container
COPY asteroid.c /var/ss/
COPY meteor.c /var/ss/
COPY comet.c /var/ss/
COPY pulsar_check.c /var/ss/
COPY supernova.c /var/ss/
COPY blackhole.c /var/ss/
COPY neutronstar_check.c /var/ss/
COPY eventhorizon_check.c /var/ss/
COPY singularity_check.c /var/ss/
COPY supergiant.c /var/ss/
COPY final_check.c /var/ss/

# Compile the C programs
RUN gcc -o /var/ss/asteroid /var/ss/asteroid.c && \
    gcc -o /var/ss/meteor /var/ss/meteor.c && \
    gcc -o /var/ss/supernova /var/ss/supernova.c && \
    gcc -o /var/ss/comet /var/ss/comet.c && \
    gcc -o /var/ss/pulsar_check /var/ss/pulsar_check.c && \
    gcc -o /var/ss/blackhole /var/ss/blackhole.c && \
    gcc -o /var/ss/neutronstar_check /var/ss/neutronstar_check.c && \
    gcc -o /var/ss/eventhorizon_check /var/ss/eventhorizon_check.c && \
    gcc -o /var/ss/singularity_check /var/ss/singularity_check.c && \
    gcc -o /var/ss/supergiant /var/ss/supergiant.c && \
    gcc -o /var/ss/final_check /var/ss/final_check.c && \
    chmod +x /var/ss/asteroid /var/ss/meteor /var/ss/comet /var/ss/pulsar_check /var/ss/supernova /var/ss/blackhole /var/ss/neutronstar_check /var/ss/eventhorizon_check /var/ss/singularity_check /var/ss/supergiant /var/ss/final_check && \
    rm -rf /var/ss/*.c

# Create and set permissions for /var/ss/pulsar and other files
RUN echo "" > /var/ss/pulsar && \
    chown pluto:pluto /var/ss/pulsar && \
    chmod 600 /var/ss/pulsar && \
    chown pluto:pluto /var/ss/* && \
    chmod 755 /var/ss/asteroid /var/ss/meteor /var/ss/comet /var/ss/pulsar_check /var/ss/supernova /var/ss/blackhole /var/ss/neutronstar_check /var/ss/eventhorizon_check /var/ss/singularity_check

# Create and set permissions for /var/ss/eventhorizon and /var/ss/singularity
RUN touch /var/ss/eventhorizon /var/ss/singularity && \
    chown pluto:pluto /var/ss/eventhorizon /var/ss/singularity && \
    chmod 640 /var/ss/singularity && \
    chmod 640 /var/ss/eventhorizon

# Set the Pluto user to run the container
USER pluto
WORKDIR /home/pluto

# Default command to run the program
CMD ["/bin/bash"]
