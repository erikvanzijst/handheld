# Firmware for XMega256C3

## Requirements

On OSX, install the AVR compiler toolchain and a DFU programmer:

```
$ xcode-select --install
$ brew tap osx-cross/avr
$ brew install avr-gcc
$ brew install dfu-programmer
```

For Linux:

```
```

## Programming

Compile the project:

```
$ cd gcc
gcc $ make
...
Finished building target: handheld.elf
"avr-objcopy" -O binary "handheld.elf" "handheld.bin"
"avr-objcopy" -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures \
        "handheld.elf" "handheld.hex"
"avr-objcopy" -j .eeprom --set-section-flags=.eeprom=alloc,load --change-section-lma \
        .eeprom=0 --no-change-warnings -O binary "handheld.elf" \
        "handheld.eep" || exit 0
"avr-objdump" -h -S "handheld.elf" > "handheld.lss"
"avr-size" "handheld.elf"
   text	   data	    bss	    dec	    hex	filename
    812	      0	      0	    812	    32c	handheld.elf
$
```

Connect an Atmel ICE programmer with PDI cable and flash:

```
gcc $ make flash
Writing flash over Atmel ICE in PDI mode...
avrdude -c atmelice_pdi -p x256c3 -U flash:w:handheld.hex

avrdude: AVR device initialized and ready to accept instructions

Reading | ################################################## | 100% 0.00s

avrdude: Device signature = 0x1e9846 (probably x256a1)
avrdude: NOTE: Programmer supports page erase for Xmega devices.
         Each page will be erased before programming it, but no chip erase is performed.
         To disable page erases, specify the -D option; for a chip-erase, use the -e option.
avrdude: reading input file "handheld.hex"
avrdude: input file handheld.hex auto detected as Intel Hex
avrdude: writing flash (812 bytes):

Writing | ################################################## | 100% 0.04s

avrdude: 812 bytes of flash written
avrdude: verifying flash memory against handheld.hex:
avrdude: load data flash data from input file handheld.hex:
avrdude: input file handheld.hex auto detected as Intel Hex
avrdude: input file handheld.hex contains 812 bytes
avrdude: reading on-chip flash data:

Reading | ################################################## | 100% 0.02s

avrdude: verifying ...
avrdude: 812 bytes of flash verified

avrdude done.  Thank you.
$
```
