CC = gcc
CFLAGS = -Wall -Wextra -I.
LDFLAGS =

SRCS = main.c student.c
OBJS = $(SRCS:.c=.o)
HEADER = student.h
EXECUTABLE = grade_card_program

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) $(EXECUTABLE) $(OBJS)
