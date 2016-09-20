ifneq ($(KERNELRELEASE),)
	MODNAME:=yue
	FILENAME:=lx
	obj-m += $(MODNAME).o
	${MODNAME}-objs+=${FILENAME}.o
else
	KERNELDIR?=/lib/modules/$(shell uname -r)/build
	PWD:=$(shell pwd)
default:
	$(MAKE) -C ${KERNELDIR} M=${PWD} modules
endif

.PHNOY:clear
clear:
	rm -rf *.o *.ko *.mod.* modules.* Modules.*


