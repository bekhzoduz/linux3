FROM ubuntu:20.04

# Set non-interactive frontend for apt to avoid prompts during build
ENV DEBIAN_FRONTEND=noninteractive

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

# Create a new user 'phoenix' with sudo privileges
RUN useradd -m -d /home/phoenix -s /bin/bash phoenix && \
    echo "phoenix:rebirth" | chpasswd && \
    usermod -aG sudo phoenix && \
    mkdir -p /root && \
    echo "root:hack123" | chpasswd

# Create the "568c86b7-bayroq" package
WORKDIR /tmp
RUN mkdir -p 568c86b7-bayroq/DEBIAN && mkdir -p 568c86b7-bayroq/usr/bin

# Create the binary for 568c86b7-bayroq
RUN echo '#!/bin/bash' > 568c86b7-bayroq/usr/bin/568c86b7-bayroq \
    && echo 'echo "Yaxshi bajardingiz!\nFlag: HD{Bu_juda_muvofiq_qilib_bajarildi!}"' >> 568c86b7-bayroq/usr/bin/568c86b7-bayroq \
    && chmod +x 568c86b7-bayroq/usr/bin/568c86b7-bayroq


# Add control file for "568c86b7-bayroq"
RUN echo "Package: 568c86b7-bayroq" > 568c86b7-bayroq/DEBIAN/control \
    && echo "Version: 1.0" >> 568c86b7-bayroq/DEBIAN/control \
    && echo "Section: base" >> 568c86b7-bayroq/DEBIAN/control \
    && echo "Priority: optional" >> 568c86b7-bayroq/DEBIAN/control \
    && echo "Architecture: all" >> 568c86b7-bayroq/DEBIAN/control \
    && echo "Maintainer: Haady <haady@haad.ai>" >> 568c86b7-bayroq/DEBIAN/control \
    && echo "Description: Bayroqlarni olish uchun shunchaki dastur." >> 568c86b7-bayroq/DEBIAN/control

# Build and install "568c86b7-bayroq"
RUN dpkg-deb --build 568c86b7-bayroq && dpkg -i 568c86b7-bayroq.deb

# Create another package "OSpackage_1.0-1.deb"
RUN mkdir -p OSpackage/DEBIAN && mkdir -p OSpackage/usr/bin

# Add a dummy executable file to the new package
RUN echo '#!/bin/bash' > OSpackage/usr/bin/ospkgapp \
    && echo 'echo "HD{Kelajakdagi_barcha_pentestchilar_uchun_tanlangan_dastur}"' >> OSpackage/usr/bin/ospkgapp \
    && chmod +x OSpackage/usr/bin/ospkgapp

# Add a post-installation script to create the binary in /home/phoenix
RUN echo '#!/bin/bash' > OSpackage/DEBIAN/postinst \
    && echo 'echo "#!/bin/bash" > /home/phoenix/ospackage' >> OSpackage/DEBIAN/postinst \
    && echo 'echo "echo Flag: HD{Kelajakdagi_barcha_pentestchilar_uchun_tanlangan_dastur}" >> /home/phoenix/ospackage' >> OSpackage/DEBIAN/postinst \
    && echo 'chmod +x /home/phoenix/ospackage' >> OSpackage/DEBIAN/postinst \
    && chmod +x OSpackage/DEBIAN/postinst

# Add control file for the new package
RUN echo "Package: OSpackage" > OSpackage/DEBIAN/control \
    && echo "Version: 1.0-1" >> OSpackage/DEBIAN/control \
    && echo "Section: utilities" >> OSpackage/DEBIAN/control \
    && echo "Priority: optional" >> OSpackage/DEBIAN/control \
    && echo "Architecture: all" >> OSpackage/DEBIAN/control \
    && echo "Maintainer: OS Maintainer <os@example.com>" >> OSpackage/DEBIAN/control \
    && echo "Description: A utility package for demonstration purposes." >> OSpackage/DEBIAN/control

# Build the new package
RUN dpkg-deb --build OSpackage && \
    mv OSpackage.deb /home/phoenix/OSpackage_1.0-1.deb

    COPY ./packageone.c /home/phoenix
    RUN gcc /home/phoenix/packageone.c -o /home/phoenix/packageone && rm -f /home/phoenix/packageone.c

# Set the default user to phoenix and work directory
USER phoenix
WORKDIR /home/phoenix

# Provide a shell environment for manual testing
CMD ["/bin/bash"]
