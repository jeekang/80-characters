# 80-characters
A simple line checker for code written in C.

Useful tool for checking code for proper style.

Marks all lines that are longer than 80 characters, and marks all characters in such line past 80. 

## How To Use
Download the .c file, compile using:  gcc 80characters.c -0 80characters.x.

Type in terminal ./80characters.x < [name of file to be checked here]

### Note
Program assumes 1000 characters max per line, and assumes every new line starts with a newline character.

