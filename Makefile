all: item.o ArrayList.o main.o
	@gcc item.o ArrayList.o main.o -o executavel

ArrayList.o:
	@gcc -c ArrayList.c 

item.o:
	@gcc -c item.c

main.o:
	@gcc -c main.c

clean:
	@rm -f *.o

run:
	@./executavel

zip:
	@zip -r executavel.zip Makefile main.c item.c item.h ArrayList.c ArrayList.h
