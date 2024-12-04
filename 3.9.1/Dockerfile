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
    nano \
&& apt-get clean \
&& rm -rf /var/lib/apt/lists/*


USER root

RUN useradd -m -s /bin/bash brandon && \
    echo "brandon:moneytree" | sudo chpasswd && \
    usermod -aG sudo brandon && \
    useradd -m -s /bin/bash katy && \
    echo "katy:jurisdiction" | sudo chpasswd && \
    usermod -aG sudo katy


RUN echo "HD{Linux_ko'nikmalarimizni_sinab_ko'rish_vaqti_keldi}\n" > /home/brandon/flag.txt && \
    echo "Lorem ipsum dolor sit amet, consectetur adipiscing elit." > /docs.txt && \
    echo "From your friend, Katy.\n\nNo reply!" > /email.doc && \
    echo "HRni seshanba kuni 09:00 da uchrashuvi bor" > /home/important.doc && \
    echo "DATE,USER,MESSAGE\n2005-07-17,brandon,Salom Dunyo!\n2005-08-21,katy,Eng zo'r tizim!" > /home/info.csv && \
    echo "Qayerga bormang, baribir o‘sha yerda o‘zingiz bo‘lasiz" > /home/stuff.txt

RUN echo "MACHINE|USERNAME|PASSWORD\nlocalhost|katy|jurisdiction" > /katy-stuff.csv && \
    echo "HD{tez_orada_bu_quti_sizniki_bo'ladi}\n" > /home/katy/flag.txt

COPY ./usb /dev/usb
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
