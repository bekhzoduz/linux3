# Use Ubuntu as the base image
FROM ubuntu:20.04

# Install necessary packages
RUN apt-get update && apt-get install -y \
    gcc \
    build-essential \
    sudo \
    curl \
    watch \
    && apt-get clean && rm -rf /var/lib/apt/lists/*

RUN useradd -m phoenix && echo "phoenix:rebirth" | chpasswd
# Add a binary (simulate /home/phoenix/watchman)
COPY ./watchman.c /home/phoenix/kuzatuvchi.c

# Compile the binary
RUN gcc /home/phoenix/kuzatuvchi.c -o /home/phoenix/kuzatuvchi && chmod +x /home/phoenix/kuzatuvchi && rm /home/phoenix/kuzatuvchi.c

# Set workdir and user
WORKDIR /home/phoenix
USER phoenix

# Start a shell
CMD ["/bin/bash"]
