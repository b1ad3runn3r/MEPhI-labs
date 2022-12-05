CC = clang
CFLAGS = -gdwarf-4 -fno-omit-frame-pointer -Wall -Wextra -Wpedantic -Werror -Og -c
LDFLAGS = -lreadline
ANALYZE_FLAGS = --analyze -Xanalyzer -analyzer-output=html

SRCDIR = src
OBJDIR = build
REPORT_DIR = reports

TARGET = lab4_self lab4_readline

OBJ_READLINE = $(addprefix $(OBJDIR)/, common_readline.o main_readline.o)
OBJ_SELF = $(addprefix $(OBJDIR)/, common_self.o string.o main_self.o)
SRC = $(shell find $(SRCDIR) -name *.c) 

.PHONY: clean

all: clean $(TARGET)

lab4_self: $(OBJ_SELF)
	$(CC) $(OBJ_SELF) -o $(OBJDIR)/lab4_self

$(OBJ_SELF):
	$(CC) $(CFLAGS) $(SRCDIR)/lib/string/string.c -o $(OBJDIR)/common_self.o
	$(CC) $(CFLAGS) $(SRCDIR)/lib/common/common.c -o $(OBJDIR)/string.o
	$(CC) $(CFLAGS) $(SRCDIR)/main_self.c -o $(OBJDIR)/main_self.o

lab4_readline: $(OBJ_READLINE)
	$(CC) $(LDFLAGS) $(OBJ_READLINE) -o $(OBJDIR)/lab4_readline 

$(OBJ_READLINE):
	$(CC) $(CFLAGS) -DREADLINE $(SRCDIR)/lib/common/common.c -o $(OBJDIR)/common_readline.o
	$(CC) $(CFLAGS) -DREADLINE $(SRCDIR)/main_readline.c -o $(OBJDIR)/main_readline.o

analyze: $(SRC)
	$(CC) $(ANALYZE_FLAGS) $(SRC) 

clean:
	rm -rf $(OBJDIR)/*