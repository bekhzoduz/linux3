FROM ubuntu:20.04

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
    cron \
&& apt-get clean \
&& rm -rf /var/lib/apt/lists/*


USER root

RUN useradd -m brandon && \
    echo "brandon:moneytree" | sudo chpasswd && \
    usermod -aG sudo brandon && \
    useradd -m katy && \
    echo "katy:hellowworld" | sudo chpasswd && \
    usermod -aG sudo katy && \
    mkdir -p /home/brandon/

COPY ./3.9.1.1.sh /home/brandon/generate_files.sh

RUN bash /home/brandon/generate_files.sh 

RUN rm -rf /home/brandon/generate_files.sh 
    
COPY ./3.9.1.2.sh /home/brandon/generate_files.sh

RUN bash /home/brandon/generate_files.sh 

RUN rm -rf /home/brandon/generate_files.sh

COPY ./newuser_check.c /home/katy/

RUN gcc /home/katy/newuser_check.c -o /home/katy/newuser_check

RUN rm -rf /home/katy/newuser_check.c && \
    chmod 750 /home/katy/newuser_check

RUN echo "HD{Qirollik_uchun_kalit}" > /root/.hidden_file.txt

COPY ./backup_check.c /root/

RUN gcc /root/backup_check.c -o /root/backup_check

RUN rm -rf /root/backup_check.c && \
    chmod 700 /root/backup_check

RUN chown brandon:brandon -R /home/brandon/

RUN chown katy:katy -R /home/katy/

USER brandon

WORKDIR /home/brandon/

CMD ["bash"]
