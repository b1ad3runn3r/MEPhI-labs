CC = clang

RELEASE_CFLAGS =-g0 -O2 -fvisibility=hidden

DEBUG_CFLAGS = -gdwarf-4 -fno-omit-frame-pointer -Wall -Wextra -Wpedantic -Werror -O0

LDFLAGS = -lreadline

SRC_SELF = main.c lib/*.c
OBJ_SELF = main.o string.o

SRC_READLINE = main_readline.c
OBJ_READLINE = main_readline.o

#TODO: add default targets

readline_debug:
	$(CC) $(DEBUG_CFLAGS) -c $(SRC_READLINE)
	$(CC) $(LDFLAGS) $(OBJ_READLINE) -o readline_debug

readline_release:
	$(CC) $(RELEASE_CFLAGS) -c $(SRC_READLINE)
	$(CC) $(LDFLAGS) $(OBJ_READLINE) -o readline_release

self_debug:
	$(CC) $(DEBUG_CFLAGS) -c $(SRC_SELF)
	$(CC) $(OBJ_SELF) -o self_debug

self_release:
	$(CC) $(RELEASE_CFLAGS) -c $(SRC_SELF)
	$(CC) $(OBJ_SELF) -o self_release

clean:
	rm -rf readline*
	rm -rf self*
	rm -rf *.o
