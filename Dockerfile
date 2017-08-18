FROM debian:stretch
# Install needed packages
RUN apt-get update && apt-get -y install cmake make build-essential

# clean unneded packages
RUN  rm -rf /var/lib/apt/lists/*

