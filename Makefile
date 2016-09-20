obj-m += lian.o
KDIR?=/lib/modules/$(shell uname -r)/build
KDIRARM?=../../../../..
PWD:=$(shell pwd)

default:
	$(MAKE) -C $(KDIR) M=$(PWD) modules
.PHNOY:clear
clear:
	rm -rf *.o *.ko *.mod.* modules.* Modules.*

