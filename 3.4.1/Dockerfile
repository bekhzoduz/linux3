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

# Add a binary (simulate /home/phoenix/watchman)
COPY ./watchman.c /home/phoenix/watchman.c

# Compile the binary
RUN gcc /home/phoenix/watchman.c -o /home/phoenix/watchman && chmod +x /home/phoenix/watchman && rm /home/phoenix/watchman.c

# Set workdir and user
WORKDIR /home/phoenix
RUN useradd -m phoenix && echo "phoenix:rebirth" | chpasswd
USER phoenix

# Start a shell
CMD ["/bin/bash"]
