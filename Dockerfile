FROM debian:11
MAINTAINER Peter Lyoo <peter.lyoo@sendbird.com>

RUN apt-get update && \
    apt-get install -y default-mysql-client wget lsb-release gnupg apt-transport-https ca-certificates jq
RUN /bin/sh -c wget -nv -O - 'https://repo.proxysql.com/ProxySQL/proxysql-2.4.x/repo_pub_key' | gpg --dearmor > /etc/apt/trusted.gpg.d/proxysql-2.4.x-keyring.gpg # buildkit
RUN /bin/sh -c echo deb https://repo.proxysql.com/ProxySQL/proxysql-2.4.x/$(lsb_release -sc)/ ./ | tee /etc/apt/sources.list.d/proxysql.list && apt-get update && apt-get install proxysql=2.4.4 && rm -rf /var/lib/apt/lists/* # buildkit

ADD ./src/proxysql /usr/bin/proxysql

CMD ["proxysql", "-f", "--idle-threads", "-D", "/var/lib/proxysql"]