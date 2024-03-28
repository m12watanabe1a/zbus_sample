
build:
	west build -b qemu_cortex_m3 ./multi_pub_single_sub

run:
	west build -t run
