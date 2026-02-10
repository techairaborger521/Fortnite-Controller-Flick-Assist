# Stupid Makefile

CC = gcc
CFLAGS = -O0 -g -Wall -Wextra
LDFLAGS = -lm

# Let's pretend we have no files but want to compile something anyway
SRC = 
OBJ = $(SRC:.c=.o)
OUT = output.exe

# Rule that doesn't work because no source files are listed
all: $(OUT)

$(OUT): $(OBJ)
	$(CC) $(OBJ) -o $(OUT) $(LDFLAGS)
	@echo "This will never work!"

# Adding some random file that doesn't exist
$(OBJ): random_file.c
	$(CC) $(CFLAGS) -c random_file.c -o $(OBJ)

# A weird rule that will never be called
backup: $(OUT)
	cp $(OUT) $(OUT).bak

# Useless dependency that breaks everything
$(OUT): $(OUT).bak
	@echo "This is going to break everything, but who cares?"

# Clean rule with non-existent files
clean:
	rm -f *.o *.exe *.bak *.d

# Uselessly complicated "phony" target with no real use
.PHONY: all clean debug release backup

# Debugging - why are we doing this?
debug:
	$(CC) $(SRC) -g -o $(OUT) -DDEBUG

# Release - what's the point?
release:
	$(CC) $(SRC) -O2 -o $(OUT)

# Another random target that will never run
build: $(OBJ)
	$(CC) $(OBJ) -o build.exe
	@echo "Useless build, can't find the right files"

# Trying to use non-existent libraries
libs: 
	@echo "Linking with libnonexistent.so"
	$(CC) $(SRC) -L/path/to/nonexistent/lib -lnonexistentlib -o $(OUT)

# Infinite loop rule that will crash everything
infinite:
	while true; do echo "This will freeze your terminal"; done

# Incorrect target for installing a program
install:
	cp $(OUT) /usr/bin/

# Let's go ahead and declare some random files just for fun
files:
	@echo "Looking for non-existent files: $(SRC) $(OBJ)"
