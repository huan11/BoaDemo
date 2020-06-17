TARGET := cgi_ajax

CROSS_COMPILE :=
CC = $(CROSS_COMPILE) gcc 
LD = $(CROSS_COMPILE) ld

OBJS := cgi_ajax.o
OBJS += cJSON.o

CFLAGS  += -Wall -I./inc

LDFLAGS +=

OUTPUT_DIR =/home/wanpihuan/work/mycode/Linux_shixun/cgi


all:$(TARGET)
$(TARGET):$(OBJS)
	$(CC) $(LDFLAGS)  $^ -o $@
	cp $@ $(OUTPUT_DIR)

%.o:%.c
	$(CC) $(CFLAGS) -c  $^ -o $@

clean:
	rm -f $(TARGET) $(OBJS)

