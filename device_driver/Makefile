obj-m := mychr_dev.o

KERNELDIR := /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

All: test_dd test_app

test_dd: mychr_dev.c
	make -C $(KERNELDIR) SUBDIRS=$(PWD) modules

test_app: mychr_app.c
	gcc mychr_app.c -o mychr_app

clean:
	make -C $(KERNELDIR) M=$(PWD) clean
	