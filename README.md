*This project was created as part of the 42 curriculum by flauweri.*

# Get Next Line

## Description
Get Next Line implements a function that reads a file descriptor line by line (ending with '\n'), returning one line per call, regardless of the operating system's internal buffering behavior.

The goal of this project is to deepen understanding of:
- **Static variables**
- **Parsing files**
- Memory allocation and management
- File descriptor handling
- Efficient buffer-based reading
- String manipulation

For example, given this file, get_next_line will return on the first call:
`*This project has been created as part of the 42 curriculum by flauweri.*`

On the second call, it will return a newline (`\n`), and on the third call, it will return:
`# Get Next Line`

## Instructions

### Usage
To use the function with your own main.c:

Include this in main.c:\
`#include "get_next_line.h"`\
`# include <fcntl.h>`

Compile with your main:\
`cc -Wall -Wextra -Werror main.c get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=(42)`

then:\
`./a.out "file_name"`

Compile with bonus:\
`cc -Wall -Wextra -Werror main_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c -D BUFFER_SIZE=(42)`

then:\
`./a.out "file_name_1" "file_name_2" "file_name_3" ...`

## Resources
Classic References

- man 2 read, man open, man close
- 42 official subject PDF

AI Usage
- what is a static variable ?
- what is the parsing of a file ?
- how does read work, what are its return ?

AI assistance was used for: structuring the README.