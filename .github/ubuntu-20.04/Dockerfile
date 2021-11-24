FROM ubuntu:20.04

# we need the timezone to be set for installing boost
ARG DEBIAN_FRONTEND=noninteractive
ENV TZ=Europe/Berlin
RUN apt-get update && apt-get install -y tzdata

# we need sudo, git, node etc. to simulate the git actions container
RUN apt-get update && apt-get install -y sudo
RUN apt-get update && apt-get install -y git
RUN apt-get update && apt-get install -y nodejs tar zstd

# install build toolchain
RUN apt-get update && apt-get install -y g++ build-essential cmake autoconf libtool
RUN apt-get update && apt-get install -y python python3-pip
