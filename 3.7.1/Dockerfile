FROM ubuntu:20.04

# Set non-interactive mode for apt-get
ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    gcc \
    make \
    sudo \
    vim \
    nano \
    curl \
    wget \
    git \
    build-essential \
    tar \
    unzip \
    runlevel \
    net-tools \
    python3 \
    python3-pip \
    bsdutils \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

# Copy the Python script into the container
COPY generate_fake_wtmp.py /generate_fake_wtmp.py

# Run the Python script to generate the fake wtmp file
RUN python3 /generate_fake_wtmp.py

# Set correct permissions for the wtmp file
RUN chmod 644 /var/log/wtmp

# Clean up the Python script
RUN rm /generate_fake_wtmp.py
CMD ["bash"]
