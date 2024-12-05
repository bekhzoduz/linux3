FROM ubuntu:20.04

# Set non-interactive mode for apt-get
ENV DEBIAN_FRONTEND=noninteractive

# Install necessary packages
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
    systemd \
    apache2 \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

# Ensure systemd directories exist
RUN mkdir -p /run/systemd && \
    mkdir -p /var/log/journal && \
    chmod 2755 /var/log/journal


# Create users
RUN useradd -m -d /home/phoenix -s /bin/bash phoenix && \
    echo "phoenix:phoenix" | chpasswd && \
    usermod -aG sudo phoenix && \
    useradd -m -d /home/chuck -s /bin/bash chuck && \
    echo "chuck:chuck" | chpasswd && \
    echo 'root:root' | chpasswd

USER root

# Add incorrect directive to Apache configuration to generate an error
RUN echo 'IncorrectDirective' >> /etc/apache2/apache2.conf


# Create Apache log directory
RUN mkdir -p /var/log/apache2
RUN touch /var/log/apache2/apache-custom.log
RUN touch /var/log/apache2/apache-custom.log1

COPY start-apache-service.sh /start-apache-service.sh
RUN chmod +x /start-apache-service.sh && \
    echo "/start-apache-service.sh" >> /home/phoenix/.bashrc


# Copy the Python script into the container
COPY generate_fake_wtmp.py /generate_fake_wtmp.py

# Run the Python script to generate the fake wtmp file
RUN python3 /generate_fake_wtmp.py

# Set correct permissions for the wtmp file
RUN chmod 644 /var/log/wtmp

# Clean up the Python script
RUN rm /generate_fake_wtmp.py

# Fix permissions for systemd and logs
RUN chown -R root:root /var/log/apache2 && chmod -R 644 /var/log/apache2/*

# Set non-root user and working directory
USER phoenix
WORKDIR /home/phoenix

# Start systemd in the background and then launch bash
CMD ["/lib/systemd/systemd"]