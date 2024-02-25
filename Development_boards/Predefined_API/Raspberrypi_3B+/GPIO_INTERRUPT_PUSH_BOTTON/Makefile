obj-m += gpiointerrupt.o
 
 
 
all:
	make ARCH=arm64 CROSS_COMPILE=/home/engineer/Downloads/64_bit_buildroot/output/host/bin/aarch64-linux- -C /home/engineer/Downloads/64_bit_buildroot/output/build/linux-custom  M=$(shell pwd) modules
 
clean:
	make -C $(KDIR)  M=$(shell pwd) clean
