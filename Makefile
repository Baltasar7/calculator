##
## Attention:
##      This makefile is not support header file update. (TODO)
##      When updated header file, Must execute make clean.
##

TARGET:=calculator

CC:=gcc
CFLAGS:=-g -fprofile-arcs -ftest-coverage -Wall -Werror
LDFLAGS:=-fprofile-arcs -ftest-coverage

INCLUDE:=-I./include
SRCDIR:=./src
SRCS:=$(wildcard $(SRCDIR)/*.c)

OBJDIR:=./obj
OBJS:=$(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS))

vpath %.c src
vpath %.h include


.PHONY: all
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<


.PHONY: clean
clean:
	rm -rf $(TARGET) $(OBJDIR)
