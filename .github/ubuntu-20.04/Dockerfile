FROM ubuntu:20.04

# we need the timezone to be set for installing boost
ARG DEBIAN_FRONTEND=noninteractive
ENV TZ=Europe/Berlin
RUN apt-get update && apt-get install -y tzdata

# install toolchain
RUN apt-get update && apt-get install -y git
RUN apt-get update && apt-get install -y g++ build-essential cmake