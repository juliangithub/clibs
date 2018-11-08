PC_DEBUG_VERSION=y

#SVN_REVISION = $(shell svn info |grep Revision|awk '{print $$2}') 
REVISION = $(shell git rev-parse HEAD)
#REVISION = abcdefg
ifeq ($(PC_DEBUG_VERSION),y)
CC := gcc
LD := ld
CFLAGS  = -Wall -g -O0
CFLAGS  += -DPC_DEBUG_VERSION
#LDFLAGS += -lcurl
TARGET=x86_bin
else
CC = arm-linux-gcc
LD = arm-linux-ld
CFLAGS  = -Wall -g -O0
CFLAGS += -I./include/curl
CFLAGS +=  -I.
#CFLAGS += -L./lib -lcurl
LDFLAGS =
TARGET=arm_bin
endif



CFLAGS  += -DREVISION="\"$(REVISION)"\"

SRC=$(wildcard *.c)
OBJS=$(patsubst %.c, %.o, $(SRC))

.PHONY: $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)
	@echo " $(TARGET)-> Compiling ok."
	@echo "reversion: $(REVISION) "


clean:
	-@rm $(OBJS)
	-@rm $(TARGET)
	
