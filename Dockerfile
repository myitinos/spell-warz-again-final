FROM ubuntu:latest

RUN apt update && \
    apt install socat -y

WORKDIR /app

COPY ./flag.txt .
COPY ./spell-warz-again .

EXPOSE 12345/tcp
CMD socat tcp-listen:12345,reuseaddr,fork EXEC:./spell-warz-again
