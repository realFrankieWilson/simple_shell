SIMPLE SHELL PROJECT

Table Of Contents
> What is the shell?
> About this project
> Essential  functionalities of the simple shell
> File description
> List of allowed functionns and system calls
for this project
> Usage
> Example of usage
> Bugs
> Team

What is the shell?
The shell is a program that takes command from the keyboard
via the terminal, and gives them to the operating system to perform.

About this project

This project is a simple version of the linux shell made for Holberton School
taking part in the low-level-programming and algorithm linux and  unix system
programming projects.
It is created using the C programming Language and it can perform many func-
tionalities that a real shell does

Essential functionalities of the simple shell

Displays a prompt "$" and waits for user input.
Runs all commands of type "executable program"(ls and /bin/ls).
Runs the following build-in commands: exit, env, setenv and unsetenv.
Handles the PATH global variable
Handles commans withb arguments
Handles the EOF(End Of File) condition.
Handles the ctrl + C signal -> it doesn't exit the shell

List of allowed functions and system calls  for this project

access (man 2 access)
chdir (man 2 chdir)
close (man 2 close)
closedir (man 3 closedir)
execve (man 2 execve)
exit (man 3 exit)
_exit (man 2 _exit)
fflush (man 3 fflush)
fork (man 2 fork)
free (man 3 free)
getcwd (man 3 getcwd)
getline (man 3 getline)
getpid (man 2 getpid)
isatty (man 3 isatty)
kill (man 2 kill)
malloc (man 3 malloc)
open (man 2 open)
opendir (man 3 opendir)
perror (man 3 perror)
read (man 2 read)
readdir (man 3 readdir)
signal (man 2 signal)
stat (__xstat) (man 2 stat)
lstat (__lxstat) (man 2 lstat)
fstat (__fxstat) (man 2 fstat)
strtok (man 3 strtok)
wait (man 2 wait)
waitpid (man 2 waitpid)
wait3 (man 2 wait3)
wait4 (man 2 wait4)
write (man 2 write) 

USAGE

You can try our shell by following these steps:
step 1: Clone our repository using this command (you need to have
git installed on your maachine first);
https://github.com/realFrankieWilson/simple_shell

step 2: Change directory to simple_shell

step 3: Compile the c files in this way:
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh

step 4: Run the shell
./hsh

Exiting the shell

When you want to exit the shell, you can simple press Ctrl + D

##TEAM
> Frank Ugwu
> Lilian Onyeabo

We hope you find this project really useful and have fun while at it.
