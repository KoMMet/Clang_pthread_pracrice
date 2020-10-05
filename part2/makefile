H1=../include

exec exec2:main.c 2main.c
	gcc -std=c11 -pthread -I$(H1) main.c -o exec
	gcc -std=c11 -pthread -I$(H1) 2main.c -o exec2

clean:
	rm -fr exec exec2
