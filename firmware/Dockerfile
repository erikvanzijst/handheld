FROM ubuntu:20.04
MAINTAINER Erik van Zijst <erik.van.zijst@gmail.com>
LABEL Description="Embedded ARM GNU C compiler and OpenOCD"

RUN apt-get update -y
RUN apt-get install -y \
    python3 \
    build-essential \
    gcc-arm-none-eabi \
    git \
    openocd
RUN apt-get install -y gcc-avr avr-libc uisp avrdude flex byacc bison
