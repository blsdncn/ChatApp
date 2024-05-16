CC = gcc

CFLAGS = -Wall -g -I$(UTIL_DIR)

# Directories
SOURCE_DIR = src
CLIENT_DIR = $(SOURCE_DIR)/SocketClient
SERVER_DIR = $(SOURCE_DIR)/SocketServer
UTIL_DIR = $(SOURCE_DIR)/SocketUtil

# Source Files
CLIENT_SRC = $(CLIENT_DIR)/main.c
SERVER_SRC = $(SERVER_DIR)/main.c
UTIL_SRC = $(UTIL_DIR)/socketutil.c

# Header Files
UTIL_HDR = $(UTIL_DIR)/socketutil.h

# Object Files
CLIENT_OBJ = $(CLIENT_DIR)/main.o
SERVER_OBJ = $(SERVER_DIR)/main.o
UTIL_OBJ = $(UTIL_DIR)/socketutil.o

CLIENT_TARGET = socketClient
SERVER_TARGET = socketServer

all: $(CLIENT_TARGET) $(SERVER_TARGET)

# Client Executable
$(CLIENT_TARGET): $(UTIL_OBJ) $(CLIENT_OBJ)
	$(CC) $(UTIL_OBJ) $(CLIENT_OBJ) -o $@

# Server Executable
$(SERVER_TARGET): $(UTIL_OBJ) $(SERVER_OBJ)
	$(CC) $(UTIL_OBJ) $(SERVER_OBJ) -o $@

# Compile .c files into .o files
$(CLIENT_OBJ): $(CLIENT_SRC) $(UTIL_HDR)
	$(CC) $(CFLAGS) -c $< -o $@

$(SERVER_OBJ): $(SERVER_SRC) $(UTIL_HDR)
	$(CC) $(CFLAGS) -c $< -o $@

$(UTIL_OBJ): $(UTIL_SRC) $(UTIL_HDR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target to remove compiled files
clean:
	rm -f $(CLIENT_OBJ) $(SERVER_OBJ) $(UTIL_OBJ) $(CLIENT_TARGET) $(SERVER_TARGET)

# Phoney Targets
.PHONEY: all clean