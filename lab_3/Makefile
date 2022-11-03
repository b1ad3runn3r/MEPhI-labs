CC = clang

RELEASE_CFLAGS =-g0 -O2 -fvisibility=hidden

DEBUG_CFLAGS = -gdwarf-4 -fno-omit-frame-pointer -Wall -Wextra -Wpedantic -Werror -O0

LDFLAGS = -lm

REPORT_DIR = reports
ANALYZE_FLAGS = --analyze -Xanalyzer -analyzer-output=html -o $(REPORT_DIR)

SRC = *.c lib/*.c

all:
	release

analyze:
	$(CC) $(ANALYZE_FLAGS) $(SRC)

debug:
	$(CC) $(DEBUG_CFLAGS) -c $(SRC)
	$(CC) $(LDFLAGS) *.o -o bin_debug

release:
	$(CC) $(RELEASE_CFLAGS) -c $(SRC)
	$(CC) $(LDFLAGS) *.o -o bin_release

clean:
	rm -rf $(REPORT_DIR)
	rm -rf bin*
	rm -rf *.o
