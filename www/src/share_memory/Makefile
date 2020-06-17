TARGET1 := sim_catch
TARGET2 := temp_cgi

CROSS_COMPILE :=
CC = $(CROSS_COMPILE) gcc 
LD = $(CROSS_COMPILE) ld

OBJS1 := sim_catch.o task.o
OBJS2 := temp_cgi.o task.o cJSON.o

CFLAGS  += -Wall -I./inc

LDFLAGS +=

OUTPUT_DIR =/home/wanpihuan/work/mycode/Linux_shixun/cgi


all:$(TARGET1) $(TARGET2)
$(TARGET1):$(OBJS1)
	$(CC) $(LDFLAGS)  $^ -o $@
	# cp $@ $(OUTPUT_DIR)

$(TARGET2):$(OBJS2)
	$(CC) $(LDFLAGS)  $^ -o $@
	cp $@ $(OUTPUT_DIR)
%.o:%.c
	$(CC) $(CFLAGS) -c  $^ -o $@

clean:
	rm -f $(TARGET1) $(OBJS1) $(TARGET2) $(OBJS2)

