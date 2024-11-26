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

    RUN groupadd -f Pluto && groupadd -f gasgiants && groupadd -f dwarfs && groupadd -f icegiants && groupadd -f terrestrials && groupadd -f hypotheticals && \
    useradd -m -d /home/Pluto -s /bin/bash -g Pluto Pluto && \
    useradd -m -d /home/Ceres -s /bin/bash -g Ceres Ceres && \
    useradd -m -d /home/Neptune -s /bin/bash -g Neptune Neptune && \
    useradd -m -d /home/Uranus -s /bin/bash -g Uranus Uranus && \
    useradd -m -d /home/Saturn -s /bin/bash -g Saturn Saturn && \
    useradd -m -d /home/Jupiter -s /bin/bash -g Jupiter Jupiter && \
    useradd -m -d /home/Haumea -s /bin/bash -g Haumea Haumea && \
    useradd -m -d /home/Mercury -s /bin/bash -g Mercury Mercury && \
    useradd -m -d /home/Eris -s /bin/bash -g Eris Eris && \
    useradd -m -d /home/Mars -s /bin/bash -g Mars Mars && \
    useradd -m -d /home/Earth -s /bin/bash -g Earth Earth && \
    useradd -m -d /home/Venus -s /bin/bash -g Venus Venus && \
    useradd -m -d /home/PlanetX -s /bin/bash -g PlanetX PlanetX && \
    echo "Pluto:solarsystem" | chpasswd && \
    echo "Neptune:solarsystem" | chpasswd && \
    echo "Uranus:solarsystem" | chpasswd && \
    echo "Saturn:solarsystem" | chpasswd && \
    echo "Jupiter:solarsystem" | chpasswd && \
    echo "Haumea:solarsystem" | chpasswd && \
    echo "Mercury:solarsystem" | chpasswd && \
    echo "Eris:solarsystem" | chpasswd && \
    echo "Mars:solarsystem" | chpasswd && \
    echo "Earth:solarsystem" | chpasswd && \
    echo "Venus:solarsystem" | chpasswd && \
    echo "PlanetX:solarsystem" | chpasswd && \
    mkdir -p /var/ss && \
    useradd -m -d /home/Makemake -s /bin/bash Makemake && \
    echo "Makemake:Makemake" | chpasswd && \
    useradd -m -d /home/Admin -s /bin/bash Admin && \
    echo "Admin:Admin" | chpasswd && \
    usermod -aG sudo Pluto && \
    usermod -aG sudo Makemake && \
    usermod -aG gasgiants Neptune && \
    usermod -aG gasgiants Uranus && \
    usermod -aG gasgiants Saturn && \
    usermod -aG gasgiants Jupiter && \
    usermod -aG icegiants Neptune && \
    usermod -aG icegiants Uranus && \
    usermod -aG dwarfs Pluto && \
    usermod -aG dwarfs Ceres && \
    usermod -aG dwarfs Makemake && \
    usermod -aG dwarfs Haumea && \
    usermod -aG dwarfs Eris && \
    usermod -aG terrestrials Mars && \
    usermod -aG terrestrials Earth && \
    usermod -aG terrestrials Venus && \
    usermod -aG terrestrials Mercury && \
    usermod -aG hypotheticals PlanetX

# Allow pluto to use sudo without password
RUN echo "Pluto ALL=(ALL) NOPASSWD:ALL" >> /etc/sudoers

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
    chown Pluton:Pluton /var/ss/pulsar && \
    chmod 600 /var/ss/pulsar && \
    chown Ceres:Ceres /var/ss/* && \
    chmod 700 /var/ss/asteroid && \
    chmod 755 /var/ss/meteor /var/ss/comet /var/ss/pulsar_check /var/ss/supernova /var/ss/blackhole /var/ss/neutronstar_check /var/ss/eventhorizon_check /var/ss/singularity_check

# Create and set permissions for /var/ss/eventhorizon and /var/ss/singularity
RUN touch /var/ss/eventhorizon /var/ss/singularity && \
    chown Pluton:Pluton /var/ss/eventhorizon /var/ss/singularity && \
    chmod 640 /var/ss/singularity && \
    chmod 640 /var/ss/eventhorizon

# Set the Pluto user to run the container
USER Admin
WORKDIR /home/Admin

# Default command to run the program
CMD ["/bin/bash"]
