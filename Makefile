all:
	g++-14 -include includes/io_setup.h ${file} -o a.out && ./a.out
