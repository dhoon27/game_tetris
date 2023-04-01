TARGET = tetris

TOP_DIR = $(shell pwd)
SRC_DIR = $(TOP_DIR)/src
INC_DIR = $(TOP_DIR)/inc
OUT_DIR = $(TOP_DIR)/output

# GCC_TOOL_PATH=$(shell which gcc)
CC = gcc
LD = gcc
CFLAGS = -Wall -Werror -c -I$(INC_DIR)
LFLAGS =

vpath %.c $(SRC_DIR)
vpath %.o $(OUT_DIR)

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(addprefix $(OUT_DIR)/,$(notdir $(SRCS:.c=.o)))

.PHONY: all prepare clear

all: prepare $(TARGET)

$(TARGET): $(OBJS)
	$(LD) $(LFLAGS) $^ -o $(OUT_DIR)/$@

$(OUT_DIR)/%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

prepare:
	mkdir -p $(OUT_DIR)

clean:
	rm -rf $(OUT_DIR)