all :
	gcc -Wall -Werror -Wextra -pedantic -g -o hsh *.c
	#valgrind --leak-check=yes --show-leak-kinds=all ./hsh
	#gdb ./hsh
	./hsh
