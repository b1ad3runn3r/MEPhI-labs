AFL_DIR=AFLplusplus

CC = $(AFL_DIR)/afl-clang-fast
FUZZER = $(AFL_DIR)/afl-fuzz

ADDRESS_FLAGS = -fsanitize=address
CFLAGS = -g -fno-omit-frame-pointer $(ADDRESS_FLAGS) -c
LDFLAGS = -lreadline

SRCDIR = ../src
OBJDIR = build

TARGET = lab4_self lab4_readline

OBJ_READLINE = $(addprefix $(OBJDIR)/, common_readline.o main_readline.o)
OBJ_SELF = $(addprefix $(OBJDIR)/, common_self.o string.o main_self.o)

.PHONY: clean

all: clean $(TARGET)

lab4_self: $(OBJ_SELF)
	$(CC) $(OBJ_SELF) $(ADDRESS_FLAGS) -o $(OBJDIR)/lab4_self

$(OBJ_SELF):
	$(CC) $(CFLAGS) $(SRCDIR)/lib/common/common.c -o $(OBJDIR)/string.o
	$(CC) $(CFLAGS) $(SRCDIR)/lib/string/string.c -o $(OBJDIR)/common_self.o
	$(CC) $(CFLAGS) $(SRCDIR)/main_self.c -o $(OBJDIR)/main_self.o

lab4_readline: $(OBJ_READLINE)
	$(CC) $(LDFLAGS) $(ADDRESS_FLAGS) $(OBJ_READLINE) -o $(OBJDIR)/lab4_readline 

$(OBJ_READLINE):
	$(CC) $(CFLAGS) -DREADLINE $(SRCDIR)/lib/common/common.c -o $(OBJDIR)/common_readline.o
	$(CC) $(CFLAGS) -DREADLINE $(SRCDIR)/main_readline.c -o $(OBJDIR)/main_readline.o

clean:
	rm -rf $(OBJDIR)/*