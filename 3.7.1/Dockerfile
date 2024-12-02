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
    systemctl \
    apache2 \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

# Create users
RUN useradd -m -d /home/phoenix -s /bin/bash phoenix && \
    echo "phoenix:phoenix" | chpasswd && \
    usermod -aG sudo phoenix && \
    useradd -m -d /home/chuck -s /bin/bash chuck && \
    echo "chuck:chuck" | chpasswd

# Add incorrect directive to Apache configuration to generate an error
RUN echo 'IncorrectDirective' >> /etc/apache2/apache2.conf
RUN sudo mkdir -p /var/log/journal
RUN sudo chown root:systemd-journal /var/log/journal && \
    sudo chmod 2755 /var/log/journal
    

# Create Apache log directory
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

# Set non-root user and working directory
USER phoenix
WORKDIR /home/phoenix

CMD ["bash"]