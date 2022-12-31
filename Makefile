
wordscanner: wordscanner.cc
	g++ -std=c++14 -Wall -Werror -Wextra -pedantic -g -o wordscanner wordscanner.cc

clean:
	rm -f wordscanner *.o *.out


