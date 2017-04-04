.SUFFIXES:.c .o

CC=gcc
SRCS=hello.c\
		add.c
OBJS=$(SRCS:.c=.o)
EXEC=hello

start:$(OBJS)
	$(CC) -o $(EXEC) $(OBJS)
	@echo '-------------ok------------'

.c.o:
	$(CC) -o $@ -c $<

clean:
	rm -rf $(OBJS)