# simple_shell
Write a simple UNIX Command interpreter.
A Unix shell is a command-line interpreter or shell that provides a command line user interface for Unix-like operating systems. The first UNIX was developed in 1970 at Bell Telephone Laboratories*

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
## env
Prints the current environment
```
$ env
SHELL=/bin/bash
WSL_DISTRO_NAME=Ubuntu
NAME=DESKTOP-QQAMHH6
PWD=/mnt/c/Users/TANIA DIAZ/.git/simple_shell
LOGNAME=root
MOTD_SHOWN=update-motd
HOME=/root
LANG=C.UTF-8
LS_COLORS=rs=0:di=01;34:ln=01;36:mh=00:pi=40;33:so=01;35:do=01;35:bd=40;33;01:cd=40;33;01:or=40;31;01:mi=00:su=37;41:sg=30;43:ca=30;41:tw=30;42:ow=34;42:st=37;44:ex=01;32:*.tar=01;31:*.tgz=01;31:*.arc=01;31:*.arj=01;31:*.taz=01;31:*.lha=01;31:*.lz4=01;31:*.lzh=01;31:*.lzma=01;31:*.tlz=01;31:*.txz=01;31:*.tzo=01;31:*.t7z=01;31:*.zip=01;31:*.z=01;31:*.dz=01;31:*.gz=01;31:*.lrz=01;31:*.lz=01;31:*.lzo=01;31:*.xz=01;31:*.zst=01;31:*.tzst=01;31:*.bz2=01;31:*.bz=01;31:*.tbz=01;31:*.tbz2=01;31:*.tz=01;31:*.deb=01;31:*.rpm=01;31:*.jar=01;31:*.war=01;31:*.ear=01;31:*.sar=01;31:*.rar=01;31:*.alz=01;31:*.ace=01;31:*.zoo=01;31:*.cpio=01;31:*.7z=01;31:*.rz=01;31:*.cab=01;31:*.wim=01;31:*.swm=01;31:*.dwm=01;31:*.esd=01;31:*.jpg=01;35:*.jpeg=01;35:*.mjpg=01;35:*.mjpeg=01;35:*.gif=01;35:*.bmp=01;35:*.pbm=01;35:*.pgm=01;35:*.ppm=01;35:*.tga=01;35:*.xbm=01;35:*.xpm=01;35:*.tif=01;35:*.tiff=01;35:*.png=01;35:*.svg=01;35:*.svgz=01;35:*.mng=01;35:*.pcx=01;35:*.mov=01;35:*.mpg=01;35:*.mpeg=01;35:*.m2v=01;35:*.mkv=01;35:*.webm=01;35:*.ogm=01;35:*.mp4=01;35:*.m4v=01;35:*.mp4v=01;35:*.vob=01;35:*.qt=01;35:*.nuv=01;35:*.wmv=01;35:*.asf=01;35:*.rm=01;35:*.rmvb=01;35:*.flc=01;35:*.avi=01;35:*.fli=01;35:*.flv=01;35:*.gl=01;35:*.dl=01;35:*.xcf=01;35:*.xwd=01;35:*.yuv=01;35:*.cgm=01;35:*.emf=01;35:*.ogv=01;35:*.ogx=01;35:*.aac=00;36:*.au=00;36:*.flac=00;36:*.m4a=00;36:*.mid=00;36:*.midi=00;36:*.mka=00;36:*.mp3=00;36:*.mpc=00;36:*.ogg=00;36:*.ra=00;36:*.wav=00;36:*.oga=00;36:*.opus=00;36:*.spx=00;36:*.xspf=00;36:
LESSCLOSE=/usr/bin/lesspipe %s %s
TERM=xterm-256color
LESSOPEN=| /usr/bin/lesspipe %s
USER=root
SHLVL=1
WSLENV=
XDG_DATA_DIRS=/usr/local/share:/usr/share:/var/lib/snapd/desktop
PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/mnt/c/WINDOWS/system32:/mnt/c/WINDOWS:/mnt/c/WINDOWS/System32/Wbem:/mnt/c/WINDOWS/System32/WindowsPowerShell/v1.0/:/mnt/c/WINDOWS/System32/OpenSSH/:/mnt/c/Program Files/Microsoft SQL Server/120/Tools/Binn/:/mnt/c/Program Files/PuTTY/:/mnt/c/Program Files (x86)/Windows Live/Shared:/mnt/c/Program Files/Git/cmd:/mnt/c/HashiCorp/Vagrant/bin:/mnt/c/TDM-GCC-64/bin:/mnt/c/Program Files/dotnet/:/mnt/c/Users/TANIA DIAZ/AppData/Local/Microsoft/WindowsApps:/mnt/c/Users/TANIA DIAZ/.dotnet/tools:/mnt/c/Users/TANIA DIAZ/AppData/Local/Programs/Microsoft VS Code/bin:/snap/bin
HOSTTYPE=x86_64
_=./hsh
```
## Exit 
Exits the shell, The STATUS argument is the integer used to exit the shell.
```
$ exit
root@DESKTOP-QQAMHH6:/mnt/c/Users/TANIA DIAZ/.git/simple_shell# 
```
*reference https://en.wikipedia.org/wiki/Unix_shell
