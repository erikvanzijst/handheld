
################################################################################
# Automatically-generated file. Do not edit!
################################################################################

MK_DIR = mkdir -p
ifdef SystemRoot
	SHELL = cmd.exe
	MK_DIR = mkdir
else
	ifeq ($(shell uname), Linux)
		MK_DIR = mkdir -p
	endif

	ifeq ($(shell uname | cut -d _ -f 1), CYGWIN)
		MK_DIR = mkdir -p
	endif

	ifeq ($(shell uname | cut -d _ -f 1), MINGW32)
		MK_DIR = mkdir -p
	endif

	ifeq ($(shell uname | cut -d _ -f 1), MINGW64)
		MK_DIR = mkdir -p
	endif

	ifeq ($(shell uname | cut -d _ -f 1), DARWIN)
		MK_DIR = mkdir -p
	endif
endif

# List the subdirectories for creating object files
SUB_DIRS +=  \
 \
src \
examples/src

# List the object files
OBJS +=  \
main.o \
src/pmic.o \
src/sleep.o \
src/osc.o \
src/tc.o \
examples/src/usart_basic_example.o \
driver_isr.o \
atmel_start.o \
src/clk.o \
src/usart_basic.o \
src/driver_init.o \
src/rtc.o \
src/protected_io.o \
src/screen.o \
src/font.o \
src/wallclock.o \
src/button.o

OBJS_AS_ARGS +=  \
"main.o" \
"src/pmic.o" \
"src/sleep.o" \
"src/osc.o" \
"src/tc.o" \
"examples/src/usart_basic_example.o" \
"driver_isr.o" \
"atmel_start.o" \
"src/clk.o" \
"src/usart_basic.o" \
"src/driver_init.o" \
"src/rtc.o" \
"src/protected_io.o" \
"src/screen.o" \
"src/font.o" \
"src/wallclock.o" \
"src/button.o"

# List the dependency files
DEPS := $(OBJS:%.o=%.d)

DEPS_AS_ARGS +=  \
"src/tc.d" \
"src/osc.d" \
"main.d" \
"examples/src/usart_basic_example.d" \
"src/rtc.d" \
"src/pmic.d" \
"src/sleep.d" \
"src/protected_io.d" \
"src/driver_init.d" \
"src/usart_basic.d" \
"driver_isr.d" \
"src/clk.d" \
"atmel_start.d" \
"src/screen.d" \
"src/font.d" \
"src/wallclock.d" \
"src/button.d"

MAKEFILE_DIR := $(dir $(realpath $(firstword $(MAKEFILE_LIST))))
OUTPUT_FILE_NAME :=handheld
QUOTE := "
OUTPUT_FILE_PATH +=$(OUTPUT_FILE_NAME).elf
OUTPUT_FILE_PATH_AS_ARGS +=$(OUTPUT_FILE_NAME).elf

vpath %.c ../
vpath %.s ../
vpath %.S ../

# All Target
all: $(SUB_DIRS) $(OUTPUT_FILE_PATH)

# Linker target




$(OUTPUT_FILE_PATH): $(OBJS)
	@echo Building target: $@
	@echo Invoking: AVR/GNU Linker
	$(QUOTE)avr-gcc$(QUOTE) -o $(OUTPUT_FILE_NAME).elf $(OBJS_AS_ARGS)  -Wl,--start-group -lm -Wl,--end-group \
-Wl,-Map="$(OUTPUT_FILE_NAME).map" -Wl,--gc-sections \
-mmcu=atxmega256c3 -B "$(MAKEFILE_DIR)../gcc/dev/atxmega256c3" \
-L"../gcc/dev/atxmega256c3/avrxmega6"  \
-l:libatxmega256c3.a 
	@echo Finished building target: $@

	"avr-objcopy" -O binary "$(OUTPUT_FILE_NAME).elf" "$(OUTPUT_FILE_NAME).bin"
	"avr-objcopy" -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures \
        "$(OUTPUT_FILE_NAME).elf" "$(OUTPUT_FILE_NAME).hex"
	"avr-objcopy" -j .eeprom --set-section-flags=.eeprom=alloc,load --change-section-lma \
        .eeprom=0 --no-change-warnings -O binary "$(OUTPUT_FILE_NAME).elf" \
        "$(OUTPUT_FILE_NAME).eep" || exit 0
	"avr-objdump" -h -S "$(OUTPUT_FILE_NAME).elf" > "$(OUTPUT_FILE_NAME).lss"
	"avr-size" "$(OUTPUT_FILE_NAME).elf"

# Compiler target(s)




%.o: %.c
	@echo Building file: $<
	@echo AVR/GNU C Compiler
	$(QUOTE)avr-gcc$(QUOTE) -x c -DF_CPU=32000000 -DDEBUG -Os -ffunction-sections -g3 -Wa,-mgcc-isr -c -std=gnu99 \
-mmcu=atxmega256c3 -B "$(MAKEFILE_DIR)../gcc/dev/atxmega256c3" \
    -D__xmega256C3__ \
-I"../config" -I"../examples/include" -I"../include" -I"../utils" -I"../utils/assembler" -I"../" -I"../include"  \
-MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"  -o "$@" "$<"

	@echo Finished building: $<

%.o: %.s
	@echo Building file: $<
	@echo AVR/GNU Assembler
	$(QUOTE)avr-gcc$(QUOTE) -x assembler-with-cpp -DF_CPU=32000000 -DDEBUG -Os -ffunction-sections -g3 -Wall -c -std=gnu99 \
-mmcu=atxmega256c3 -B "$(MAKEFILE_DIR)../gcc/dev/atxmega256c3" \
    -D__xmega256C3__ \
-I"../config" -I"../examples/include" -I"../include" -I"../utils" -I"../utils/assembler" -I"../" -I"../include"  \
-MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"  -o "$@" "$<"

	@echo Finished building: $<

%.o: %.S
	@echo Building file: $<
	@echo AVR/GNU Preprocessing Assembler
	$(QUOTE)avr-gcc$(QUOTE) -x assembler-with-cpp -DF_CPU=32000000 -DDEBUG -Os -ffunction-sections -g3 -Wall -c -std=gnu99 \
-mmcu=atxmega256c3 -B "$(MAKEFILE_DIR)../gcc/dev/atxmega256c3" \
    -D__xmega256C3__ \
-I"../config" -I"../examples/include" -I"../include" -I"../utils" -I"../utils/assembler" -I"../" -I"../include"  \
-MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"  -o "$@" "$<"

	@echo Finished building: $<

# Detect changes in the dependent files and recompile the respective object files.
ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(DEPS)),)
-include $(DEPS)
endif
endif

$(SUB_DIRS):
	$(MK_DIR) "$@"

flash:  $(SUB_DIRS) $(OUTPUT_FILE_PATH)
	@echo Writing flash over Atmel ICE in PDI mode...
	avrdude -c atmelice_pdi -p x256c3 -U flash:w:$(OUTPUT_FILE_NAME).hex

dfu: $(SUB_DIRS) $(OUTPUT_FILE_PATH) erase
	@echo Writing flash using DFU bootloader over USB...
	dfu-programmer atxmega256c3 flash --force $(OUTPUT_FILE_NAME).hex

clean:
	rm -f $(OBJS_AS_ARGS)
	rm -f $(OUTPUT_FILE_PATH)
	rm -f $(DEPS_AS_ARGS)
	rm -f $(OUTPUT_FILE_NAME).a $(OUTPUT_FILE_NAME).hex $(OUTPUT_FILE_NAME).bin \
        $(OUTPUT_FILE_NAME).lss $(OUTPUT_FILE_NAME).eep $(OUTPUT_FILE_NAME).map \
        $(OUTPUT_FILE_NAME).srec
