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
    net-tools \
    python3 \
    python3-pip \
    bsdutils \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

# Create users
RUN useradd -m -d /home/phoenix -s /bin/bash phoenix && \
    echo "phoenix:phoenix" | chpasswd && \
    usermod -aG sudo phoenix && \
    useradd -m -d /home/chuck -s /bin/bash chuck && \
    echo "chuck:chuck" | chpasswd

#Create apache2 log directory
RUN mkdir -p /var/log/apache2
RUN touch /var/log/apache2/apache-custom.log
RUN touch /var/log/apache2/apache-custom.log1

# Copy the Python script into the container
COPY generate_fake_wtmp.py /generate_fake_wtmp.py

# Run the Python script to generate the fake wtmp file
RUN python3 /generate_fake_wtmp.py

# Set correct permissions for the wtmp file
RUN chmod 644 /var/log/wtmp

# Clean up the Python script
RUN rm /generate_fake_wtmp.py

USER phoenix
WORKDIR /home/phoenix
CMD ["bash"]
