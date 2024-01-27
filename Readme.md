# Pipex

This project is an implementation of the Unix `pipe` command in C.

## Structure

The project has the following structure:

- `includes/`: This directory contains all the header files.
- `utils/`: This directory contains all the source files.
- `main.c`: This is the main file of the project.

## Compilation

The project uses a Makefile for compilation. You can compile the project using the following command:

make

This will create an executable named pipex.

Usage
After compiling the project, you can run it with the following command:

Where:

file1 is the input file.
cmd1 is the first command to execute.
cmd2 is the second command to execute.
file2 is the output file.

The program will execute cmd1 with file1 as input and cmd2 with the output of cmd1 as input. The final output will be written to file2.

Cleaning Up
You can remove the compiled files with the following command:

This will remove all the .o files and the pipex executable.

Rebuilding
If you want to rebuild the project from scratch, you can use the following command:

This will clean up the compiled files and then recompile the project.

## Basic data flow in a pipe

![Pipeline](https://user-images.githubusercontent.com/78316076/153064847-6d3c0255-8c22-483a-bd4c-ef1facab7f80.svg)
