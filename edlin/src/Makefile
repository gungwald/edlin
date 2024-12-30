# Builds edlin

# Requirements:
# 1. GNU Make must be used
# 2. The cc65 compiler must be properly setup
# 3. The AppleWin emulator is required for testing

PGM=edlin
DISK_VOL=$(PGM)
DISK=$(PGM).dsk
BASE_PRODOS_DISK=../storage/prodos-2.0.3-boot.dsk
AC=java -jar ../lib/AppleCommander-ac-1.4.0.jar

CC=cl65
AS=ca65
OBJS=$(PGM).o
HDRS=
CFLAGS=-O -t $(CC65_TARGET) -DTRACE
LDFLAGS=-t $(CC65_TARGET) # -S $6000 to make both hi-res pages available

# Extra stuff
BASIC_AUX_TYPE=0x0801
READ_TIME_LOAD_ADDR=0x0260
SYS_LOAD_ADDR=0x2000
BIN_LOAD_ADDR=0x0803

ifndef CC65_TARGET
	CC65_TARGET:=apple2enh
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

all: $(DISK)

$(DISK): $(PGM)
	$(call removeFiles,$(DISK))
	$(call copyFile,$(BASE_PRODOS_DISK),$(DISK))
	$(AC) -as $(DISK) $(PGM) BIN < $(PGM) || $(RM) $(DISK)

$(PGM): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

test: $(DISK)
	applewin -d1 $(DISK)
	#$(APPLEWIN) -s7 empty -d1 $(DISK)

clean:
	$(call removeFiles,*.o $(PGM) $(DISK))

