CC = gcc # compiler selection

# GCC flags used:
# -g: debugger flag
# -Wall: Lists all warnings
# -Wextra: Lists extra warnings for extra specifc cases
# -Werror: Treat all warnings as error for forcing clean code
# -fsanitize=address: Catches memory leaks and buffer overflows. 
CFLAGS = -g -Wall -Wextra -fsanitize=address -Werror
TARGET = oogway_shell
SOURCES = oogway_shell.c utility.c

all: $(TARGET)

$(TARGET): $(SOURCES) oogway_shell.h
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES)

clean:
	rm -f $(TARGET)
