# C - Simple Shell
A simple UNIX command interpreter.

## Description
replicates the basic behavior of `/bin/sh`; copy-cat of the standard shell behavior.

The shell works in both **interactive** and **non-interactive** modes. It handles arguments, built-in
commands (exit - to exit shell, env - to print environment variables), special characters, errors,
and more. Can't forget to mention its Betty-Style checked!

## Compilation

This shell is compiled using the following command:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

## Usage

Interactive Mode:
$ ./hsh
($) /bin/ls
file1.c file2.c README.md
($) exit
$

Non-Interactive Mode:
$ echo "/bin/ls" | ./hsh
file1.c file2.c README.md

$ cat commands.txt
/bin/ls
/bin/pwd

$ cat commands.txt | ./hsh
file1.c file2.c README.md
/home/user/simple_shell

## Example (For an error):

$ ./hsh
($) wrongcommand
./hsh: 1: wrongcommand: not found
($)

## Requirements

- Allowed editors: vi, vim, emacs
- All files compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
- All files end with a new line
- README.md file, at the root of the folder of the project
- Code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
- Shell should not have any memory leaks
- No more than 5 functions per file
- All header files should be include guarded
- Use system calls only when you need to
