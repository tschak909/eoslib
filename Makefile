TARGET_EXEC ?= eos

BUILD_DIR ?= ./build
SRC_DIRS ?= ./src

CC=zcc
AS=z88dk-z80asm

SRCS := $(shell find $(SRC_DIRS) -name *.cpp -or -name *.c -or -name *.s)
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

CFLAGS=+coleco -subtype=adam
LDFLAGS=-xeos

INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

$(TARGET_EXEC).lib: $(OBJS)
	$(AS) $(LDFLAGS) $(OBJS)

# c source
$(BUILD_DIR)/%.c.o: %.c
	$(MKDIR_P) $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

.PHONY: install check clean

install: src/eos.h eos.lib
	install src/eos.h /usr/local/share/z88dk/include/
	install eos.lib /usr/local/share/z88dk/lib/

check:
	$(MAKE) -C tests/console-output/

clean:
	$(RM) -r eos.lib $(BUILD_DIR)

-include $(DEPS)

MKDIR_P ?= mkdir -p
