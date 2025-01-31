FROM debian:11
ADD ./binaries/proxysql /
MAINTAINER Peter Lyoo <peter.lyoo@sendbird.com>

RUN apt-get update && \
    apt-get install -y default-mysql-client wget lsb-release gnupg apt-transport-https ca-certificates jq

CMD ["proxysql", "-f", "--idle-threads", "-D", "/var/lib/proxysql"]