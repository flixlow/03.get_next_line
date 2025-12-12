*This project has been created as part of the 42 curriculum by flauweri.*

# Get Next Line

## Description
Get Next Line is a project designed to implement a function capable of reading 
a file descriptor line by line, returning one line per function call—regardless 
of the internal buffering behavior of the operating system.

The goal of this project is to deepen understanding of:
- Static variables
- Memory allocation and management
- File descriptor handling
- Efficient buffer-based reading
- String manipulation

## Instructions

### Compilation
The project is compiled using the provided `Makefile`.

Available rules:
- `make` # Compiles get_next_line mandatory part
- `make bonus` # Compiles get_next_line with bonus (multiple FDs)
- `make clean` # Removes object files
- `make fclean` # Removes object files and library
- `make re` # Rebuilds everything

### Usage
To use the function in another project:

1. Include the header:

`#include "get_next_line.h"`

Link your program with the compiled library: 
`cc -Wall -Wextra -Werror main.c get_next_line.c get_next_line_bonus.c`

## Resources
Classic References

- man 2 read, man open, man close
- 42 official subject PDF

AI Usage

AI assistance was used exclusively for: Structuring the README

No AI-generated code was inserted into the project.