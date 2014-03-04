#makefile

all: compguess

compguess: compguess.o
	g++ compguess.o -o compguess

compguess.o: compguess.cc

clean:
	rm -f compguess.o compguess

install: compguess
	cp compguess ~/bin
