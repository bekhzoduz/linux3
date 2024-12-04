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
    util-linux \
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

RUN mkdir -p /etc/flash-drive

COPY ./usb /etc/flash-drive/

COPY ./newuser_check.c /home/katy/

RUN gcc /home/katy/newuser_check.c -o /home/katy/newuser_check

RUN rm -rf /home/katy/newuser_check.c && \
    chmod 750 /home/katy/newuser_check

RUN echo "HD{Qirollik_uchun_kalit}\n" > /root/.flag


RUN mkdir -p /tmp/files && \
    echo "Name,Age,City,Role\nAbdulaziz,19,Namangan,CEO\nAbdurauf,30,Toshkent,Manager" > /tmp/files/employees.csv && \
    echo "Product,Price,Quantity\nLaptop,999.99,50\nPhone,499.99,100" > /tmp/files/inventory.csv && \
    echo "Date,Transaction,Amount\n2023-01-01,Sale,1500\n2023-01-02,Purchase,750" > /tmp/files/transactions.csv && \
    echo "Student,Grade,Subject\nAlex,A,Math\nEmma,B,Science" > /tmp/files/grades.csv && \
    echo "Project Status Report\n\nProject: Alpha\nStatus: In Progress\nDeadline: Q4 2023" > /tmp/files/report1.doc && \
    echo "Meeting Minutes\n\nDate: 2023-09-15\nAttendees: Team A\nAgenda: Q4 Planning" > /tmp/files/minutes.doc && \
    echo "Technical Specification\n\nProduct: Beta v2.0\nRequirements: See attached" > /tmp/files/spec.doc && \
    echo "Proposal Document\n\nClient: XYZ Corp\nValue: $50,000\nTimeline: 6 months" > /tmp/files/proposal.doc && \
    echo "Weekly Update\n\nTeam: Development\nProgress: 75%\nBlockers: None" > /tmp/files/update.doc


COPY ./backup_check.c /root/

RUN gcc /root/backup_check.c -o /root/backup_check

RUN rm -rf /root/backup_check.c && \
    chmod 700 /root/backup_check

RUN chown brandon:brandon -R /home/brandon/

RUN chown katy:katy -R /home/katy/

USER brandon

WORKDIR /home/brandon/

CMD ["bash"]
