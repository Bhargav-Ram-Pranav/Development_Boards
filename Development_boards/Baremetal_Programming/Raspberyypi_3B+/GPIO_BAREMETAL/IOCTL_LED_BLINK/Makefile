obj-m=driver2.o 

all:
	make  ARCH=arm64 CROSS_COMPILE=/home/engineer/Downloads/buildroot-2022.02.9/output/host/bin/aarch64-linux- -C /home/engineer/Downloads/buildroot-2022.02.9/output/build/linux-custom M=$(shell pwd) modules


clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) clean
