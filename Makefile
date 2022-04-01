TARGET=calculator

CC=gcc
CFLAGS=-g -fprofile-arcs -ftest-coverage -Wall -Werror
LDFLAGS=-fprofile-arcs -ftest-coverage

LIBS=#-lpthread -lm

INCLUDE=-I./include
SRCDIR=./src

#OBJDIR=./obj
OBJS= \
	main.o \
	operation.o \

$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

#$(OBJDIR)/%.o: $(SRCDIR)/%.c
#	mkdir -p $(OBJDIR)
#	@[ -d $(OBJDIR) ]
#	$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $<

%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $<

all: clean $(TARGET)

clean:
	rm -rf $(TARGET) *.o *.gcno *.gcda *.gcov
