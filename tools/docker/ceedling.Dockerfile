FROM ubuntu:20.04

# Update apt repositories
RUN apt-get update -y \
    && apt-get upgrade -y
# Install packages
RUN dpkg --add-architecture i386
RUN apt-get update && DEBIAN_FRONTEND=noninteractive apt-get install -y \
        automake \
        autotools-dev \
        g++-multilib \
        gcc-multilib \
        gcovr \
        gdb \
        git \
        jq \
        make \
        lib32z-dev \
        libc6-dev-i386 \
        libevent-dev \
        libgpiod-dev \
        libz-dev \
        pkg-config \
        python3-pip \
        python-is-python3 \
        ruby \
        shellcheck \
        sudo \
        valgrind \
        vim \
        isc-dhcp-dev \
        libbind-dev \
        wget \
        ninja-build \
    && apt clean && rm -rf /var/lib/apt/lists/*

RUN apt-get update -y && apt-get install -y \
        gcc-multilib-arm-linux-gnueabihf \
        libc6-dbg:i386 \
        libglib2.0-dev:i386 \
        libxml2-utils \
        qemu-user \
    && apt clean && rm -rf /var/lib/apt/lists/*

RUN pip install \
    anybadge \
    cmake \
    cppcheck-codequality \
    flake8 \
    flake8-json \
    flake8-html \
    pygments \
    pylint-gitlab \
    meson

# Install cppcheck
WORKDIR /tmp
RUN git clone --branch 2.14.1 https://github.com/danmar/cppcheck \
    && cd ./cppcheck \
    && cmake -B build \
        -DUSE_MATCHCOMPILER=ON \
        -DCMAKE_BUILD_TYPE=Release \
        -DCMAKE_INSTALL_PREFIX=/usr/local \
    && cmake --build build --config Release -j "$(nproc)" \
    && cd build && make install \
    && cp /tmp/cppcheck/htmlreport/cppcheck-htmlreport /usr/local/bin/cppcheck-htmlreport \
    && cd /tmp && rm -rf ./cppcheck

# Install ceedling
RUN gem install ceedling -v 0.31.1

# Update the fake function framework plugin
RUN cd /var/lib/gems/2.7.0/gems/ceedling-0.31.1/plugins/ && \
    rm -rf fake_function_framework && \
    git clone --recurse https://github.com/ElectronVector/fake_function_framework.git && \
    cd -

#ENTRYPOINT ["/bin/bash", "-c", "/usr/bin/entrypoint.sh ${*}", "--"]
