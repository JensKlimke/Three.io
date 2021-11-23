FROM ubuntu:20.04

# we need the timezone to be set for installing boost
ARG DEBIAN_FRONTEND=noninteractive
ENV TZ=Europe/Berlin
RUN apt-get update && apt-get install -y tzdata

# we need sudo and git
RUN apt-get update && apt-get install -y sudo
RUN apt-get update && apt-get install -y git

# install build toolchain
RUN apt-get update && apt-get install -y g++ build-essential cmake autoconf libtool
RUN apt-get update && apt-get install -y nodejs tar zstd
