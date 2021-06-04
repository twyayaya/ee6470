all : main.cpp
	riscv32-unknown-elf-g++ -std=c++14 main.cpp -o main -march=rv32ima -mabi=ilp32
	
sim: all
	~/docker-images/EE6470/hw6_test/bin/riscv-vp-acc --intercept-syscalls main
	
clean:
	rm -f main
