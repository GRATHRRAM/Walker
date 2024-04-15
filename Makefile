cc=g++
flags=-O3 -Wall -Wextra -fsanitize=address -fsanitize=undefined

walker.out: *.cpp *.hpp
	$(cc) *.cpp *.hpp $(flags) -lm -lraylib -o walker.out

clean: 
	rm walker.out
