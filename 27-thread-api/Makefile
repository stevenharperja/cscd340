
FLAGS = -Wall -pthread -g

all: main-race main-deadlock main-deadlock-global main-signal main-signal-cv

clean:
	rm -f main-race main-deadlock main-deadlock-global main-signal main-signal-cv

main-race: main-race.c mythreads.h
	gcc -o main-race main-race.c $(FLAGS)

main-race2: main-race2.c mythreads.h
	gcc -o main-race2 main-race.c $(FLAGS)

main-race3: main-race3.c mythreads.h
	gcc -o main-race3 main-race.c $(FLAGS)

main-race4: main-race4.c mythreads.h
	gcc -o main-race4 main-race.c $(FLAGS)

main-deadlock: main-deadlock.c mythreads.h
	gcc -o main-deadlock main-deadlock.c $(FLAGS)

main-deadlock-global: main-deadlock-global.c mythreads.h
	gcc -o main-deadlock-global main-deadlock-global.c $(FLAGS)

main-signal: main-signal.c mythreads.h
	gcc -o main-signal main-signal.c $(FLAGS)

main-signal-cv: main-signal-cv.c mythreads.h
	gcc -o main-signal-cv main-signal-cv.c $(FLAGS)

