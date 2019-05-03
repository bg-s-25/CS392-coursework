SRC_FILES = cs392_memcpy.c cs392_strlen.c
OBJ_FILES = cs392_memcpy.o cs392_strlen.o
HDRS      = cs392_string.h

libcs392string.so : $(OBJ_FILES)
	gcc -fPIC -shared -o libcs392string.so $(OBJ_FILES)

cs392_memcpy.o : cs392_memcpy.c $(HDRS)
	gcc -O0 -c -fPIC cs392_memcpy.c $(HDRS)

cs392_strlen.o : cs392_strlen.c $(HDRS)
	gcc -O0 -c -fPIC cs392_strlen.c $(HDRS)

clean:
	rm -f *.o libcs392string.so
