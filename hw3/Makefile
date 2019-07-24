cs392_shell : cs392_shell.o cs392_log.o cs392_exec.o cs392_signal.o
	gcc -o cs392_shell cs392_shell.o cs392_exec.o cs392_log.o cs392_signal.o
cs392_exec.o : cs392_exec.c
	gcc -o cs392_exec.o -c -g cs392_exec.c
cs392_log.o : cs392_log.c
	gcc -o cs392_log.o -c -g cs392_log.c
cs392_signal.o : cs392_signal.c
	gcc -o cs392_signal.o -c -g cs392_signal.c
cs392_shell.o : cs392_shell.c
	gcc -o cs392_shell.o -c -g cs392_shell.c

clean:
	rm -f *.o cs392_shell