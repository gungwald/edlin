# Builds edlin
# https://cc65.github.io/doc/using-make.html

# TODO - Make cross-platform with BeanShell instead of GNU Make functions

# Requirements:
# 1. GNU Make must be used
# 2. The cc65 compiler must be properly setup
# 3. The AppleWin emulator is required for testing
# 4. Java is required to create disks with AppleCommander

SOURCES=editbuffer.c edlin.c error.c filename.c help.c string.c stringlist.c

PGM=edlin
DISK_VOL=$(PGM)
DISK=$(PGM).dsk
BASE_PRODOS_DISK=../storage/prodos-2.0.3-boot.dsk
AC=java -jar ../lib/AppleCommander-ac-1.4.0.jar

# Extra stuff
BASIC_AUX_TYPE=0x0801
READ_TIME_LOAD_ADDR=0x0260
SYS_LOAD_ADDR=0x2000
BIN_LOAD_ADDR=0x0803

ifndef CC65_TARGET
CC65_TARGET=apple2enh
endif

ifdef CC65_TARGET
CC      = cl65
CFLAGS  = -t $(CC65_TARGET) --create-dep $(<:.c=.d) -O
LDFLAGS = -t $(CC65_TARGET) -m $(PGM).map # -S $6000 to make both hi-res pages available
else
CC      = gcc
CFLAGS  = -MMD -MP -O
LDFLAGS = -Wl,-Map,$(PGM).map
endif

# This is needed because the removeFiles function can't be used after the
# double pipe on the AppleCommander line. It is necessary to include
# "cmd /c" because this might get run from Mingw or Cygwin where it is
# hard to determine the shell because GNU make may be compiled for Windows
# or Mingw/Cygwin.
ifeq ($(OS),Windows_NT)
	RM=cmd /c del
	AC:=$(subst /,\,$(AC))
else
	RM=rm
endif

# Define a variable/function that has a newline in it. This is
# needed in the $(foreach ) function.
define \n


endef

# Defines a function that can remove files on Windows and UN*X.
# Cmd has to be invoked specifically because the OS may be Windows
# but make could be run under Mingw or Cygwin.
define removeFiles
	$(if $(findstring Windows,$(OS)),
		$(foreach f,$(wildcard $(1)),cmd /c if exist $(f) del $(f)${\n}),
		rm $(1))
endef

# Only copies one file, no wildcards
define copyFile
	$(if $(findstring Windows,$(OS)),
		cmd /c copy $(subst /,\,$(1)) $(subst /,\,$(2)),
		cp $(1) $(2))
endef

########################################

.SUFFIXES:
.PHONY: all clean
all: $(DISK)

ifneq ($(MAKECMDGOALS),clean)
-include $(SOURCES:.c=.d)
endif

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

$(PGM): $(SOURCES:.c=.o)
	$(CC) $(LDFLAGS) -o $@ $^

$(DISK): $(PGM)
	$(call removeFiles,$(DISK))
	$(call copyFile,$(BASE_PRODOS_DISK),$(DISK))
	$(AC) -as $(DISK) $(PGM) BIN < $(PGM) || $(RM) $(DISK)

test: $(DISK)
	applewin -d1 $(DISK)
	#$(APPLEWIN) -s7 empty -d1 $(DISK)

clean:
	$(call removeFiles,$(SOURCES:.c=.o) $(SOURCES:.c=.d) $(PGM) $(PGM).map)

# $(call removeFiles,*.o $(PGM) $(DISK))
