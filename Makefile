cc=g++
flags=-O3 -Wall -Wextra -fsanitize=address -fsanitize=undefined
src=./src/

walker.out: $(src)*.cpp $(src)*.hpp
	$(cc) $(src)*.cpp $(src)*.hpp $(flags) -lm -lraylib -o walker.out

clean: 
	rm walker.out
