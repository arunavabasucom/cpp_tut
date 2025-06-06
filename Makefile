all:
	g++-14 -Iincludes ${file} -o a.out && ./a.out
