# UNIX Command Interpreter
This project is a UNIX command interpreter, also known as a shell, written in C programming language. The shell allows users to enter commands and execute them. The shell also supports various features such as input/output redirection, pipes, and background processes.

## Installation
To use this shell, you need to clone this repository to your local machine by running the following command in your terminal:

Copy code
```bash
git clone https://github.com/Souhib/UNIX-Command-Interpreter.git
```
Once you have cloned the repository, navigate to the directory using the cd command:

Copy code
```bash
cd UNIX-Command-Interpreter
```
Then, you can compile the shell using the following command:

Copy code
```bash
make
```

Usage
To start the shell, run the following command:

Copy code
```bash
./mysh
```
Once the shell is running, you can enter commands and execute them. The shell supports various features such as input/output redirection, pipes, and background processes.

To exit the shell, you can type exit or Ctrl-D.

## Examples
Here are some examples of how to use the shell:

```bash
$ ./mysh
$ ls
README.md  include  lib  src  Makefile
$ echo "Hello, world!"
Hello, world!
$ ls | wc -l
5
$ ls > file.txt
$ cat file.txt
README.md
include
lib
src
Makefile
```
