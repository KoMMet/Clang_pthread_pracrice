H1=../include

exec :main.c main2.c
	gcc -std=c11 -pthread -I$(H1) main.c -o exec
	gcc -std=c11 -pthread -I$(H1) main2.c -o exec2

clean:
	rm -fr exec exec2
