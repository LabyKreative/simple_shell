# Team work project on Simple shell - C programming done by Adeyemi Owolabi and Joshua Monday.

The program provides an interface for users to get access to the kernel's services. The shell command interpreter. The shell is able to run some default commands and also have some built in functions for Man Page.

# Make this project yours:

Clone the repo.
```sh
$ git clone https://github.com/LabyKreative/simple_shell.git
```
Go to the directory "simple_shell".
```sh
$ cd simple_shell 
```
After cloning, it will be necessary to compile the program, so we added a Makefile (a file that compilates and executes the file at the same time.) you can use the Make File in the below manner:
```sh
$ make 
```
Run the code below to know how the Shell is compilated and executed: 
```sh
$ cat Makefile
```
Then you are ready to use our simple shell.

##  How it works:

The shell has two modes: **Interactive** in which the shell takes the commands from the standard input, executes them and gets ready to read another command-line.

As an example you can use the <b>ls</b> command for listing files in the current directory:

```sh
$ ls
_atoi.c AUTHORS built_ins.c _environ.c _error_handler.c main.h Makefile
$ 
```
Second mode is non-interactive. The command is passed by a pipe:
```
$ echo "/bin/ls" | ./hsh
_atoi.c AUTHORS built_ins.c _environ.c _error_handler.c main.h Makefile
```

# Manual
We added a man page in the repository, it can be run like this:
```
$ man ./man_1_page
```

# Authors
* Adeyemi Owolabi [Yahoo](labykreative@yahoo.com)
* Joshua Monday [Gmail](bumiche@gmail.com)
	ALX Students. LOS Cohort 11.

