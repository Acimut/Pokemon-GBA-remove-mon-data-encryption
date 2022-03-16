#-------------------------------------------------------------------------------

ifeq ($(strip $(DEVKITARM)),)
$(error Please set DEVKITARM in your environment. export DEVKITARM=/path/to/devkitARM)
endif

include $(DEVKITARM)/base_tools

#-------------------------------------------------------------------------------

include config.mk

export BUILD := build
export SRC := src
export BIN_LINKED := $(BUILD)/$(SRC)
export BINARY := $(BUILD)/linked.o
export RESOURCES := graphics

export ARMIPS ?= armips.exe
export GFX ?= gbagfx.exe
export PREPROC ?= preproc.exe
export LD := $(PREFIX)ld

export ASFLAGS := -mthumb
	
export INCLUDES := -I $(SRC) -I . -I include -D$(ROM_CODE)
export WARNINGFLAGS :=	-Wall -Wno-discarded-array-qualifiers \
	-Wno-int-conversion
export CFLAGS := -g -O2 $(WARNINGFLAGS) -mthumb -std=gnu11 $(INCLUDES) -mcpu=arm7tdmi \
	-march=armv4t -mno-thumb-interwork -fno-inline -fno-builtin -mlong-calls -DROM_$(ROM_CODE) \
	-fdiagnostics-color
export DEPFLAGS = -MT $@ -MMD -MP -MF "$(@:%.o=%.d)"
export LDFLAGS := -T linker.ld -r $(ROM_CODE).ld

#-------------------------------------------------------------------------------
	
rwildcard=$(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))


# Sources
C_SRC := $(call rwildcard,$(SRC),*.c)
S_SRC := $(call rwildcard,$(SRC),*.s)

# Binaries
C_OBJ := $(C_SRC:%.c=$(BUILD)/%.o)
S_OBJ := $(S_SRC:%.s=$(BUILD)/%.o)

ALL_OBJ := $(C_OBJ) $(S_OBJ)

#-------------------------------------------------------------------------------

.PHONY: all rom clean graphics

all: clean rom

# rom: main$(ROM_CODE).asm $(BINARY)
rom: main$(ROM_CODE).asm $(ALL_OBJ)
	@echo "\nLinking ELF binary $@"
	@$(LD) $(LDFLAGS) -o $(BIN_LINKED)/CreateBoxMon_lnk.o $(BIN_LINKED)/CreateBoxMon.o
	@echo "\nCreating ROM"
	$(ARMIPS) main$(ROM_CODE).asm -sym offsets_$(ROM_CODE).txt

clean:
	rm -rf $(BINARY)
	rm -rf $(BUILD)/$(SRC)

$(BINARY): $(ALL_OBJ)
	@echo "\nLinking ELF binary $@"
	@$(LD) $(LDFLAGS) -o $@ $^

$(BUILD)/%.o: %.c
	@echo "\nCompiling $<"
	@mkdir -p $(@D)
	@$(CC) $(DEPFLAGS) $(CFLAGS) -E -c $< -o $(BUILD)/$*.i
	@$(PREPROC) $(BUILD)/$*.i charmap.txt | $(CC) $(CFLAGS) -x c -o $@ -c -

$(BUILD)/%.o: %.s
	@echo -e "Assembling $<"
	@mkdir -p $(@D)
	$(PREPROC) "$<" charmap.txt | @$(AS) $(ASFLAGS) -o $@

firered:              	; @$(MAKE) ROM_CODE=BPRE
rojofuego:           	; @$(MAKE) ROM_CODE=BPRS
emerald:              	; @$(MAKE) ROM_CODE=BPEE
esmeralda:              ; @$(MAKE) ROM_CODE=BPES
