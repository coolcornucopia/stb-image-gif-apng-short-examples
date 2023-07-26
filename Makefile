SRC_DIR = src
OBJ_DIR = build

SRC_FILES = $(SRC_DIR)/helpers.c

APP1 = stb_image_png_example
APP2 = stb_image_gif_example

CC ?= gcc
CFLAGS += -Wall

release: CFLAGS += -Os

# Note: -g is required for debugging step by step with gdb
debug: CFLAGS += -DDEBUG -g
#debug: CFLAGS += -DLOG_LONG_INFO

LIBS = $(shell pkg-config --cflags --libs sdl2) -lm

all: prepare $(APP1) $(APP2)
debug: all
release: all

prepare:
	@mkdir -p $(OBJ_DIR)

$(APP1):
	$(CC) -o $(OBJ_DIR)/$@ $(SRC_DIR)/$@.c $(SRC_FILES) $(CFLAGS) $(LIBS)

$(APP2):
	$(CC) -o $(OBJ_DIR)/$@ $(SRC_DIR)/$@.c $(SRC_FILES) $(CFLAGS) $(LIBS)

clean:
	rm -rf $(OBJ_DIR)

