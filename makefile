all:
	gcc -o bats bats.c

clean:
	rm -f bats

run: all
	./bats