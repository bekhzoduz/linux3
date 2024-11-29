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

# Create additional small C programs
RUN echo '#include <unistd.h>\nint main(){while(1)sleep(3600);}' > /tmp/system_monitor.c && \
    echo '#include <unistd.h>\nint main(){while(1)sleep(3600);}' > /tmp/network_service.c && \
    echo '#include <unistd.h>\nint main(){while(1)sleep(3600);}' > /tmp/backup_daemon.c && \
    echo '#include <unistd.h>\nint main(){while(1)sleep(3600);}' > /tmp/cache_cleaner.c && \
    echo '#include <unistd.h>\nint main(){while(1)sleep(3600);}' > /tmp/log_rotator.c && \
    echo '#include <unistd.h>\nint main(){while(1)sleep(3600);}' > /tmp/red-hat.c && \
    echo '#include <unistd.h>\nint main(){while(1)sleep(3600);}' > /tmp/Haady.c && \
    echo '#include <unistd.h>\nint main(){while(1)sleep(3600);}' > /tmp/Cybernation.c && \
    echo '#include <unistd.h>\nint main(){while(1)sleep(3600);}' > /tmp/Nzrv.c && \
    echo '#include <unistd.h>\nint main(){while(1)sleep(3600);}' > /tmp/Something_not_useful.c && \
    echo '#include <unistd.h>\nint main(){while(1)sleep(3600);}' > /tmp/idk_what_to_do.c && \
    gcc -o /usr/bin/system_monitor /tmp/system_monitor.c && \
    gcc -o /usr/bin/network_service /tmp/network_service.c && \
    gcc -o /usr/bin/backup_daemon /tmp/backup_daemon.c && \
    gcc -o /usr/bin/cache_cleaner /tmp/cache_cleaner.c && \
    gcc -o /usr/bin/log_rotator /tmp/log_rotator.c && \
    gcc -o /usr/bin/red-hat /tmp/red-hat.c && \
    gcc -o /usr/bin/Haady /tmp/Haady.c && \
    gcc -o /usr/bin/Cybernation /tmp/Cybernation.c && \
    gcc -o /usr/bin/Nzrv /tmp/Nzrv.c && \
    gcc -o /usr/bin/Something_not_useful /tmp/Something_not_useful.c && \
    gcc -o /usr/bin/idk_what_to_do /tmp/idk_what_to_do.c && \
    rm -f /tmp/*.c

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
    echo "/tmp/start-rising.sh" >> /etc/bash.bashrc


# Set the default user to phoenix for running processes
USER phoenix

# Set the working directory
WORKDIR /home/phoenix

# Start the rising_process in the background automatically when the container starts
CMD ["bash"]
