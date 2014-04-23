data.dat : a.out
	./a.out
a.out : PDE.c
	cc PDE.c -lm
