PC_DEBUG_VERSION=y

#SVN_REVISION = $(shell svn info |grep Revision|awk '{print $$2}') 
REVISION = $(shell git rev-parse HEAD |awk '{print $$1}')
ifeq ($(PC_DEBUG_VERSION),y)
CC := gcc
LD := ld
CFLAGS  = -Wall -g -O0
CFLAGS  += -DPC_DEBUG_VERSION
#LDFLAGS += -lcurl
TARGET=x86_bin
else
CC = /opt/hisi-linux/x86-arm/arm-hisiv200-linux/target/bin/arm-hisiv200-linux-gcc
LD = /opt/hisi-linux/x86-arm/arm-hisiv200-linux/target/bin/arm-hisiv200-linux-ld
CFLAGS  = -Wall -g -O0
CFLAGS += -I./include/curl -I.
#CFLAGS += -L./lib -lcurl
LDFLAGS =
TARGET=arm_bin
endif



CFLAGS  += -DREVISION=$(REVISION)

SRC=$(wildcard *.c)
OBJS=$(patsubst %.c, %.o, $(SRC))

.PHONY: $(TARGET)

$(TARGET) : $(OBJS)
	echo $(REVISION)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)
	echo " -> Compiling ok."


clean:
	-@rm $(OBJS)
	-@rm $(TARGET)
	
