all: mesh.o
	gcc mesh.o
run:
	./a.out
mesh.o: mesh.c
	gcc -c mesh.c
clean:
	rm -f ./a.out mesh.o
