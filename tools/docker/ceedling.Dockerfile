FROM ubuntu:20.04

# Update apt repositories
RUN apt-get update -y \
    && apt-get upgrade -y \
    && DEBIAN_FRONTEND=noninteractive apt-get install -y \
        gcc-multilib \
        gcovr \
        git \
        ruby \
    && apt clean \
    && rm -rf /var/lib/apt/lists/*

# Install ceedling
RUN gem install ceedling -v 0.31.1

# Update the fake function framework plugin
RUN cd /var/lib/gems/2.7.0/gems/ceedling-0.31.1/plugins/ && \
    rm -rf fake_function_framework && \
    git clone --recurse https://github.com/ElectronVector/fake_function_framework.git && \
    cd -

#ENTRYPOINT ["/bin/bash", "-c", "/usr/bin/entrypoint.sh ${*}", "--"]
