The USB DFU bootloader here ([atxmega256c3_104.hex](atxmega256c3_104.hex)) is
a precompiled binary provided by Atmel.

The file [AVR1916.zip](AVR1916.zip) (sourced from
[Atmel](https://microchipsupport.force.com/s/article/Pre-Programmed-USB-bootloader-for-Mega-Xmega-devices))
is Atmel's archive containing precompiled  bootloaders for the entire xmega
series.

Source code is included as well, but it seems that the IAR AVR Workbench
software/compiler is needed to compile the bootloader, as it is the only one 
able to produce a binary < 4K in size.

IAR AVR Workbench is expensive, but a free evaluation version is available,
provided the compiled object is < 4K [^1].

On xmega, the bootloader gets installed in the bootloader section of flash
storage which on the 256k chips starts at 0x40000.

The `BOOTRST` bootloader reset vector bit in fuse byte 2 must be set to force
the CPU to start executing the bootloader at address 0x40000 instead of the
main firmware at 0x00 at boot (the `make bootloader` target updates the fuse).

The firmware then checks to see if pin `PE5` is pulled low (button Y pressed
on our device). If not, it jumps straight to address 0x00 to start the main
program. Else it configures USB and enumerates itself as a DFU target:

```
$ lsusb
Bus 002 Device 001: ID 1d6b:0003 Linux Foundation 3.0 root hub
Bus 001 Device 080: ID 03eb:2fda Atmel Corp. DFU ATXMEGA256C3
```

[^1]: An alternative bootloader that compiles with avr-gcc with UART-only
    support (no USB) might be found [here](https://github.com/bandtank/Xmega_Bootloader).
