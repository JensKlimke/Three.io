FROM ubuntu:20.04

# we need the timezone to be set for installing boost
ARG DEBIAN_FRONTEND=noninteractive
ENV TZ=Europe/Berlin
RUN apt-get update && apt-get install -y tzdata

# install tools
RUN apt-get update && apt-get install -y g++ build-essential cmake  # c++ toolchain
RUN apt-get update && apt-get install -y git                        # install git (needed for googletest and cucumber)
RUN apt-get update && apt-get install -y nano                       # install nano for debugging

# install Googletest
WORKDIR /tmp
RUN git clone --depth 1 --branch release-1.6.0 https://github.com/google/googletest.git
RUN cd googletest && mkdir build && cd build && cmake .. && make
RUN cp -a googletest/include/gtest /usr/include
RUN cp -a googletest/build/*.a /usr/lib

# install Googlemock
RUN git clone --depth 1 --branch release-1.6.0 https://github.com/google/googlemock.git
RUN cp -r /tmp/googletest /tmp/googlemock/gtest
RUN cd googlemock && mkdir build && cd build && cmake .. && make
RUN cp -a googlemock/include/gmock /usr/include
RUN cp -a googlemock/build/*.a /usr/lib

# install prerequisites Cucumber
RUN apt-get update && apt-get install -y qt5-default          # can be remove probably (gtest used)
RUN apt-get update && apt-get install -y libboost1.67-all-dev # boost 1.67 (1.7x doesn't work with cucumber)
RUN apt-get update && apt-get install -y rubygems ruby-dev    # ruby for cucumber

# install cucumber from sources
RUN git clone --depth 1 --recursive --branch v0.5 https://github.com/cucumber/cucumber-cpp.git
RUN cd cucumber-cpp && git submodule init && git submodule update
RUN cd cucumber-cpp && gem install bundler && bundle install
RUN cd cucumber-cpp && cmake -E make_directory build \
     && cmake -E chdir build cmake -DCUKE_DISABLE_BOOST_TEST=ON -DCUKE_DISABLE_QT=ON .. \
     && cmake --build build && cmake --build build --target test

# copy sources
RUN mkdir /source
WORKDIR /source
COPY ./ ./

# build sources
RUN mkdir build && cd build && cmake -DBUILD_TESTING=ON .. && make && make test && make install
RUN cd test/application && mkdir build && cd build && cmake .. && make