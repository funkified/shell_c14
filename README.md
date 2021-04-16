# 0x16. C - Simple Shell

## Requirements
## General
* Allowed editors: vi, vim, emacs
* All your files will be compiled on Ubuntu 14.04 LTS
* Your C programs and functions will be compiled with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic
* All your files should end with a new line
* A README.md file, at the root of the folder of the project is mandatory
* Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
* Your shell should not have any memory leaks
* No more than 5 functions per file
* All your header files should be include guarded
* Use system calls only when you need to (why?)

## Output
* Unless specified otherwise, your program must have the exact same output as sh (/bin/sh) as well as the exact same error output.
* The only difference is when you print an error, the name of the program must be equivalent to your argv[0]

## List of allowed functions and system calls
* access (man 2 access)
* chdir (man 2 chdir)
* close (man 2 close)
* closedir (man 3 closedir)
* execve (man 2 execve)
* exit (man 3 exit)
* _exit (man 2 _exit)
* fflush (man 3 fflush)
* fork (man 2 fork)
* free (man 3 free)
* getcwd (man 3 getcwd)
* getline (man 3 getline)
* getpid (man 2 getpid)
* isatty (man 3 isatty)
* kill (man 2 kill)
* malloc (man 3 malloc)
* open (man 2 open)
* opendir (man 3 opendir)
* perror (man 3 perror)
* read (man 2 read)
* readdir (man 3 readdir)
* signal (man 2 signal)
* stat (__xstat) (man 2 stat)
* lstat (__lxstat) (man 2 lstat)
* fstat (__fxstat) (man 2 fstat)
* strtok (man 3 strtok)
* wait (man 2 wait)
* waitpid (man 2 waitpid)
* wait3 (man 2 wait3)
* wait4 (man 2 wait4)
* write (man 2 write)

## Files Created

| Name of File | Description |
| --- | --- |
|[shell.h](https://github.com/funkified/simple_shell/blob/master/header.h) | Holds libraries and prototypes |
|[main.c](https://github.com/funkified/simple_shell/blob/master/main.c) | main driving file|
|[env.c](https://github.com/funkified/simple_shell/blob/master/showenv.c) | function that shows the environmental variable |
|[helper_functions.c](https://github.com/funkified/simple_shell/blob/master/helper_funcs.c) | string manipulation along with free function |
|[static_path.c](https://github.com/funkified/simple_shell/blob/master/static_path.c)| determines if user input is a valid command by searching all directories in PATH |

## Available Commands


| Commands | Description |
--- | --- |
ls | lists all available files and directories in the current working directory
exit | exits the shell
env | prints the current environment
pwd | prints the present working directory
cd | changes the current directory of the process
^C | man the signal
\# | handles comments

---
```ls```:

```
$
$ ls
README.md  header.h  helper_funcs.c  hsh  main.c  our_cd.c  our_env.c  showenv.c  static_path.c
$
```
---
```ls -l ```:

```
$
$ ls -l
total 104
-rw-rw-r-- 1 vagrant vagrant   152 Apr 15 14:56 AUTHORS
-rw-rw-r-- 1 vagrant vagrant  5508 Apr 16 20:23 README.md
-rw-rw-r-- 1 vagrant vagrant   845 Apr 13 20:11 _printf.c
-rw-rw-r-- 1 vagrant vagrant  1188 Apr 13 22:40 _printfunc.c
-rw-rw-r-- 1 vagrant vagrant  1063 Apr 15 00:41 auxfunc.c
-rwxrwxr-x 1 vagrant vagrant   103 Apr 15 16:47 compile.sh
-rw-rw-r-- 1 vagrant vagrant  1038 Apr 15 00:45 env.c
-rw-rw-r-- 1 vagrant vagrant    93 Apr 15 14:47 global_var.h
-rw-rw-r-- 1 vagrant vagrant  1283 Apr 15 03:38 header.h
-rw-rw-r-- 1 vagrant vagrant  1948 Apr 10 20:57 holberton.h
-rwxrwxr-x 1 vagrant vagrant 13964 Apr 15 00:27 hsh
-rw-rw-r-- 1 vagrant vagrant  2305 Apr 15 18:08 main.c
-rwxrwxr-x 1 vagrant vagrant  4223 Apr 14 23:58 man_1_simple_shell
-rw-rw-r-- 1 vagrant vagrant   883 Apr 15 01:14 morefunc.c
-rwxrwxr-x 1 vagrant vagrant 13831 Apr 15 16:47 myShell
-rw-rw-r-- 1 vagrant vagrant   872 Apr 15 16:47 shell.h
-rw-rw-r-- 1 vagrant vagrant   947 Apr 15 00:45 show_env.c
drwxrwxr-x 2 vagrant vagrant  4096 Apr 16 20:02 test

$
```
---
```ls -l -a```:

```
$
$ls -l -a
total 112
drwxrwxr-x  4 vagrant vagrant  4096 Apr 16 19:57 .
drwxr-xr-x 23 vagrant vagrant  4096 Apr 15 04:01 ..
drwxrwxr-x  8 vagrant vagrant  4096 Apr 15 18:08 .git
-rw-rw-r--  1 vagrant vagrant   152 Apr 15 14:56 AUTHORS
-rw-rw-r--  1 vagrant vagrant  3048 Apr 16 19:57 README.md
-rw-rw-r--  1 vagrant vagrant   845 Apr 13 20:11 _printf.c
-rw-rw-r--  1 vagrant vagrant  1188 Apr 13 22:40 _printfunc.c
-rw-rw-r--  1 vagrant vagrant  1063 Apr 15 00:41 auxfunc.c
-rwxrwxr-x  1 vagrant vagrant   103 Apr 15 16:47 compile.sh
-rw-rw-r--  1 vagrant vagrant  1038 Apr 15 00:45 env.c
-rw-rw-r--  1 vagrant vagrant    93 Apr 15 14:47 global_var.h
-rw-rw-r--  1 vagrant vagrant  1283 Apr 15 03:38 header.h
-rw-rw-r--  1 vagrant vagrant  1948 Apr 10 20:57 holberton.h
-rwxrwxr-x  1 vagrant vagrant 13964 Apr 15 00:27 hsh
-rw-rw-r--  1 vagrant vagrant  2305 Apr 15 18:08 main.c
-rwxrwxr-x  1 vagrant vagrant  4223 Apr 14 23:58 man_1_simple_shell
-rw-rw-r--  1 vagrant vagrant   883 Apr 15 01:14 morefunc.c
-rwxrwxr-x  1 vagrant vagrant 13831 Apr 15 16:47 myShell
-rw-rw-r--  1 vagrant vagrant   872 Apr 15 16:47 shell.h
-rw-rw-r--  1 vagrant vagrant   947 Apr 15 00:45 show_env.c
drwxrwxr-x  3 vagrant vagrant  4096 Apr 15 16:13 test
$

$
```
---
```Ctrl + D```:

```
$
$ (User types in Ctrl + D here)
$ (Program has exited)```
---

```exit```:

```
$
$ (User types in exit here)
$ (Program has exited)
$
```

$
```
---
```env```:

```

$env
$
LC_PAPER=es_PR.UTF-8
XDG_SESSION_ID=3
LC_ADDRESS=es_PR.UTF-8
LC_MONETARY=es_PR.UTF-8
TERM=xterm-256color
SHELL=/bin/bash
SSH_CLIENT=10.0.2.2 33546 22
LC_NUMERIC=es_PR.UTF-8
SSH_TTY=/dev/pts/1
USER=vagrant
LC_TELEPHONE=es_PR.UTF-8
MAIL=/var/mail/vagrant
PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin
LC_IDENTIFICATION=es_PR.UTF-8
PWD=/home/vagrant/simple_shell
LANG=en_US.UTF-8
LC_MEASUREMENT=es_PR.UTF-8
SHLVL=1
HOME=/home/vagrant
LOGNAME=vagrant
XDG_DATA_DIRS=/usr/local/share:/usr/share:/var/lib/snapd/desktop
SSH_CONNECTION=10.0.2.2 33546 10.0.2.15 22
PROMPT_COMMAND= history -a; history -c; history -r;
XDG_RUNTIME_DIR=/run/user/1000
LC_TIME=es_PR.UTF-8
LC_NAME=es_PR.UTF-8
OLDPWD=/home/vagrant
_=./myShell
$
```
---

$
```
---
```pwd```:

```

$pwd
$
/home/vagrant/simple_shell
$
```
---


## Compilation
#### Your shell will be compiled this way:

* gcc -Wall -Werror -Wextra -pedantic *.c -o myShell
