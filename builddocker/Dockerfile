# Using Debian Bullseye as the base image
FROM bjrowlett2/x86_64-elf-gcc

# Updating the package lists and installing the required packages
RUN apt-get update 
RUN apt-get upgrade -y
RUN apt-get install -y binutils-x86-64-linux-gnu
RUN apt-get install -y nasm
RUN apt-get install -y xorriso
RUN apt-get install -y grub-pc-bin
RUN apt-get install -y grub-common
RUN apt-get install -y make

# Creating a directory for the project
#RUN mkdir -p /root/env

# Setting the working directory
VOLUME /root/env
WORKDIR /root/env