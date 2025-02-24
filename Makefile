compile: main.c 
	 gcc main.c -o main

run: main
	 . main

clean: main
	 rm main