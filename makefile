MTI_HOME=/opt/modelsim6.5/modeltech
CC=gcc -c -I$(MTI_HOME)/include
LD=ld -shared -E -o
test_pli.dll : test_pli.c test_pli.v
	$(CC) test_pli.c
	$(LD) test_pli.dll test_pli.o
	vlib work
	vlog -sv test_pli.v
	vsim -c -vopt test_pli -pli ./test_pli.dll -do sim.do
clean:
	rm -rf work
	rm -rf vsim.wlf
	rm -rf transcript
	rm -rf test_pli.o
	rm -rf test_pli.dll
