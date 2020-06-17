TARGET := test_form

CROSS_COMPILE :=
CC = $(CROSS_COMPILE) gcc 
LD = $(CROSS_COMPILE) ld

OBJS := form2.o cgic.o

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

