TARGET := cgi_test

CROSS_COMPILE :=
CC = $(CROSS_COMPILE) gcc
LD = $(CROSS_COMPILE) ld

OBJS := cgi_test.o
OBJS += my_time.o

CFLAGS  += -Wall -I./inc

LDFLAGS +=

all:$(TARGET)
$(TARGET):$(OBJS)
	$(CC) $(LDFLAGS)  $^ -o $@

%.o:%.c
	$(CC) $(LDFLAGS) -c  $^ -o $@

clean:
	rm -f $(TARGET) $(OBJS)
