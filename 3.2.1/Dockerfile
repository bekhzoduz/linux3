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

RUN echo "root:SagittariusA" | chpasswd

# Create groups
RUN groupadd -f gasgiants && \
    groupadd -f dwarfs && \
    groupadd -f icegiants && \
    groupadd -f terrestrials && \
    groupadd -f hypotheticals && \
    useradd -m -d /home/Pluto -s /bin/bash Pluto && \
    useradd -m -d /home/Ceres -s /bin/bash Ceres && \
    useradd -m -d /home/Neptune -s /bin/bash Neptune && \
    useradd -m -d /home/Uranus -s /bin/bash Uranus && \
    useradd -m -d /home/Saturn -s /bin/bash Saturn && \
    useradd -m -d /home/Jupiter -s /bin/bash Jupiter && \
    useradd -m -d /home/Haumea -s /bin/bash Haumea && \
    useradd -m -d /home/Mercury -s /bin/bash Mercury && \
    useradd -m -d /home/Eris -s /bin/bash Eris && \
    useradd -m -d /home/Mars -s /bin/bash Mars && \
    useradd -m -d /home/Earth -s /bin/bash Earth && \
    useradd -m -d /home/Venus -s /bin/bash Venus && \
    useradd -m -d /home/PlanetX -s /bin/bash PlanetX && \
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
    echo "Ceres:solarsystem" | chpasswd && \
    mkdir -p /var/ss && \
    mkdir -p /var/ss/super && \
    mkdir -p /var/ss/blackhole && \
    useradd -m -d /home/Makemake -s /bin/bash Makemake && \
    echo "Makemake:Makemake" | chpasswd && \
    useradd -m -d /home/Admin -s /bin/bash Admin && \
    echo "Admin:Admin" | chpasswd && \
    usermod -g sudo Pluto && \
    usermod -g sudo Makemake && \
    usermod -g gasgiants Neptune && \
    usermod -g gasgiants Uranus && \
    usermod -g gasgiants Saturn && \
    usermod -g gasgiants Jupiter && \
    usermod -g icegiants Neptune && \
    usermod -g icegiants Uranus && \
    usermod -g dwarfs Pluto && \
    usermod -g dwarfs Ceres && \
    usermod -g dwarfs Makemake && \
    usermod -g dwarfs Haumea && \
    usermod -g dwarfs Eris && \
    usermod -g terrestrials Mars && \
    usermod -g terrestrials Earth && \
    usermod -g terrestrials Venus && \
    usermod -g terrestrials Mercury && \
    usermod -g hypotheticals PlanetX

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
    gcc -o /var/ss/blackhole/SagittariusA /var/ss/blackhole.c && \
    gcc -o /var/ss/neutronstar_check /var/ss/neutronstar_check.c && \
    gcc -o /var/ss/eventhorizon_check /var/ss/eventhorizon_check.c && \
    gcc -o /var/ss/singularity_check /var/ss/singularity_check.c && \
    gcc -o /var/ss/supergiant /var/ss/supergiant.c && \
    gcc -o /var/ss/final_check /var/ss/final_check.c && \
    chmod +x /var/ss/asteroid /var/ss/meteor /var/ss/comet /var/ss/pulsar_check /var/ss/supernova /var/ss/blackhole /var/ss/neutronstar_check /var/ss/eventhorizon_check /var/ss/singularity_check /var/ss/supergiant /var/ss/final_check && \
    rm -rf /var/ss/*.c

# Create and set permissions for /var/ss/pulsar and other files
RUN echo "" > /var/ss/pulsar && \
    chown Pluto:Pluto /var/ss/pulsar && \
    chmod 600 /var/ss/pulsar && \
    chown Ceres:Ceres /var/ss/* && \
    chmod 700 /var/ss/asteroid && \
    chmod 770 /var/ss/meteor && \
    chmod 770 /var/ss/pulsar && \
    chown root:icegiants /var/ss/pulsar && \
    chown root:terrestrials /var/ss/meteor && \
    chmod 700 /var/ss/comet && \
    chown Saturn:Saturn /var/ss/comet && \
    chown root:hypotheticals /var/ss/super && \
    chmod 775 /var/ss/super && \
    chown Earth:Earth /var/ss/blackhole && \
    chmod 700 /var/ss/blackhole && \
    touch /var/ss/neutronstar /var/ss/eventhorizon && \
    chown root:root /var/ss/neutronstar_check /var/ss/neutronstar /var/ss/eventhorizon && \
    chmod 777 /var/ss/neutronstar_check && \
    chmod 700 /var/ss/neutronstar /var/ss/eventhorizon && \
    chmod 755 /var/ss/pulsar_check /var/ss/supernova /var/ss/eventhorizon_check /var/ss/singularity_check

# Create and set permissions for /var/ss/eventhorizon and /var/ss/singularity
RUN touch /var/ss/singularity && \
    chown Pluto:Pluto /var/ss/eventhorizon /var/ss/singularity && \
    chmod 640 /var/ss/singularity && \
    chmod 640 /var/ss/eventhorizon

# Set the Pluto user to run the container
USER Admin
WORKDIR /home/Admin

# Default command to run the program
CMD ["/bin/bash"]
