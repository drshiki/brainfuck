brainfuck : main.o display_msg.o brainfuck.o
	gcc -o ../bin/brainfuck main.o display_msg.o brainfuck.o -std=c99 -Wall
main.o : main.c brainfuck.h
	gcc -c main.c -std=c99 -Wall
display_msg.o : display_msg.c brainfuck.h
	gcc -c display_msg.c -std=c99 -Wall
brainfuck.o : brainfuck.c brainfuck.h
	gcc -c brainfuck.c -std=c99 -Wall
install : ../bin/brainfuck
	cp ../bin/brainfuck /usr/local/bin
clean :
	rm ../bin/brainfuck *.o