# Main variables
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -O2
LDFLAGS = 
SRC_DIR = src
BUILD_DIR = build
INCLUDE_DIR = include
BIN_DIR = bin
TARGET = $(BIN_DIR)/tkeys

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC_FILES))

# Default target
all: $(TARGET)

$(TARGET): $(OBJ_FILES) $(BUILD_DIR)/tkeys.o | $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/tkeys.o: tkeys.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Utility commands
.PHONY: clean install uninstall

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

install: $(TARGET)
	@echo "Installing $(TARGET) to /usr/local/bin"
	install -m 0755 $(TARGET) /usr/local/bin

uninstall:
	@echo "Uninstalling $(TARGET) from /usr/local/bin"
	rm -f /usr/local/bin/$(notdir $(TARGET))

clear:
	rm -f $(BUILD_DIR)/*.o $(TARGET)

help:
	@echo "Available Makefile commands:"
	@echo "  make          - Builds the project"
	@echo "  make clean    - Removes temporary build files"
	@echo "  make install  - Installs the executable to /usr/local/bin"
	@echo "  make uninstall- Removes the installation"
	@echo "  make clear    - Deletes only object files and binaries"
	@echo "  make help     - Shows this help message"
