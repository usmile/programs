test: all
	gcc -I. slog.c test.c -o test
	gcc test.c -o test_so `pwd`/libslog.so
	gcc test.c -o test_static libslog.a
	@echo "Make complete!"

all: so static

so: 
	gcc -shared -fPIC slog.c -o libslog.so

static: slog.o
	ar rcs libslog.a slog.o

slog.o: slog.c
	gcc -Wall -O2 -I. -c slog.c

clean:
	@rm -rf test test_so test_static *.o
	@rm -rf *.a
	@rm -rf *.so
	@rm -rf *.log
	@rm -rf a.out
