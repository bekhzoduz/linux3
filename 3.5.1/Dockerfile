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

# Create the "01002-flag" package
WORKDIR /tmp
RUN mkdir -p 01002-flag/DEBIAN && mkdir -p 01002-flag/usr/bin

# Create the binary for 01002-flag
RUN echo '#!/bin/bash' > 01002-flag/usr/bin/01002-flag \
    && echo 'echo "HD{Bu_juda_muvofiq_qilib_bajarildi!}"' >> 01002-flag/usr/bin/01002-flag \
    && chmod +x 01002-flag/usr/bin/01002-flag


# Add control file for "01002-flag"
RUN echo "Package: 01002-flag" > 01002-flag/DEBIAN/control \
    && echo "Version: 1.0" >> 01002-flag/DEBIAN/control \
    && echo "Section: base" >> 01002-flag/DEBIAN/control \
    && echo "Priority: optional" >> 01002-flag/DEBIAN/control \
    && echo "Architecture: all" >> 01002-flag/DEBIAN/control \
    && echo "Maintainer: Test <test@example.com>" >> 01002-flag/DEBIAN/control \
    && echo "Description: A dummy application for retrieving flags." >> 01002-flag/DEBIAN/control

# Build and install "01002-flag"
RUN dpkg-deb --build 01002-flag && dpkg -i 01002-flag.deb

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
