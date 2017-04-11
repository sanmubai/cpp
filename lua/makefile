.SUFFIXES:.c .o

CC=gcc
SRCS=add.c
OBJS=$(SRCS:.c=.o)
EXEC=add

start:$(OBJS)
	$(CC) -o $(EXEC) $(OBJS)
	@echo '-------------ok------------'

.c.o:
	$(CC) -Wall -g -o $@ -c $<

add_c:
	$(CC) -o add add.c -I /usr/include/lua5.2/ -llua5.2

c_so:
	$(CC) -Wall -shared -fPIC -o c_so.so -I /usr/include/lua5.2 c_so.c


clean:
	rm -rf $(OBJS)