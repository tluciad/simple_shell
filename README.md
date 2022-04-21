# simple_shell
Write a simple UNIX Command interpreter.
The first UNIX was developed in 1970 at Bell Telephone Laboratories

## Description
Simple_Shell is an exercise from Holberton School Colombia to C17. The objective is to make a utility that replicates the functioning of the shell.

## List of allowed functions and system calls:
- access (man 2 access)
- chdir (man 2 chdir)
- close (man 2 close)
- closedir (man 3 closedir)
- execve (man 2 execve)
- exit (man 3 exit)
- _exit (man 2 _exit)
- fflush (man 3 fflush)
- fork (man 2 fork)
- free (man 3 free)
- getcwd (man 3 getcwd)
- GETline (man 3 GETline)
- getpid (man 2 getpid)
- isatty (man 3 isatty)
- kill (man 2 kill)
- malloc (man 3 malloc)
- open (man 2 open)
- opendir (man 3 opendir)
- perror (man 3 perror)
- read (man 2 read)
- readdir (man 3 readdir)
- signal (man 2 signal)
- stat (__xstat) (man 2 stat)
- lstat (__lxstat) (man 2 lstat)
- fstat (__fxstat) (man 2 fstat)
- strtok (man 3 strtok)
- wait (man 2 wait)
- waitpid (man 2 waitpid)
- wait3 (man 2 wait3)
- wait4 (man 2 wait4)
- write (man 2 write)

## Compilation
Your shell will be compiled this way:

```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
## Invocation
After compile all .c located in this repository you can call the created shell using:
```
./hsh
```
## Non interactive mode
```
root@DESKTOP-QQAMHH6:/mnt/c/Users/TANIA DIAZ/.git/simple_shell# echo "ls" | ./hsh
Makefile  README.md  getPath.c  main_shell.c        my_shell.h     nobuiltin.c  strtok
OFunc.c   builtin.c  hsh        man_1_simple_shell  my_shellcmd.c  stringfun.c
```
## Interactive mode 
```
$ ls
Makefile  README.md  getPath.c  main_shell.c        my_shell.h     nobuiltin.c  strtok
OFunc.c   builtin.c  hsh        man_1_simple_shell  my_shellcmd.c  stringfun.c
$
```
## Flowchart
![Untitled Diagram(2)](https://user-images.githubusercontent.com/98775997/164135193-62dd3e0d-c257-45d5-952e-1c02f8be8d8f.jpg)

## Files
- my_shell.h
- builtin.c
- getpath.c
- main_shell.c
- man_1_simple_shell
- my_shellcmd.c
- nobuiltin.c
- Ofunc.c
- stringfunc.c
- README.md

## Structure in my_shell.h
```
/**
 * struct SLL - structure to manage the shell
 * @flags: arguments
 * @Command: parameter command
 * @num_flags: number of arguments
 */
typedef struct SLL
{
	char *Command;
	char **flags;
	int num_flags;
} sll_t;
```
## Exit 
