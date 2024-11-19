# Base image
FROM ubuntu:latest

# Set environment variables
ENV DEBIAN_FRONTEND=noninteractive

# Update system and install necessary tools
RUN apt-get update && apt-get install -y \
    gcc \
    make \
    sudo \
    vim \
    nano \
    passwd


    # Barcha kodlarni /home/barbarian3 ichiga ko'chirish va kompilyatsiya qilish
RUN mkdir -p /home/Admin && \
    mkdir -p /root && \
    echo "root:hack123" | chpasswd && \
    useradd -m -d /home/Admin -s /bin/bash Admin && \
    echo "Admin:Admin" | chpasswd


# Create necessary users and groups
RUN useradd -m -s /bin/bash Mars && \
    useradd -m -s /bin/bash icegiants

# Create required directories and files
RUN mkdir -p /var/specialperms && \
    touch /var/specialperms/nebula /var/specialperms/binarystar && \
    chmod 644 /var/specialperms/nebula && \
    chmod 644 /var/specialperms/binarystar


 
# Copy the main C program
COPY check_specialperms.c /var/specialperms/check_specialperms.c

# Compile the C program
RUN gcc /var/specialperms/check_specialperms.c -o /var/specialperms/check_specialperms && \
    chmod +x /var/specialperms/check_specialperms && rm -rf /var/specialperms/*.c

# Create the flag file with SUID bit
# 2) Savol
RUN touch /HD{men_foydalanuvchiman} && \
    chmod 4604 /HD{men_foydalanuvchiman}

# Set default working directory
WORKDIR /home/Admin

# Default command to execute bash
CMD ["/bin/bash"]
