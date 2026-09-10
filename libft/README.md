*This project has been created as part of the 42 curriculum by rsangjan.*

# Libft

## Description
Libft is the foundational project of the 42 curriculum. The goal is to build a personal C static library (`libft.a`) by re-implementing core standard C library (`libc`) routines, additional string and memory manipulation utilities, and singly linked list operations.

This static library serves as the core foundation for subsequent projects throughout the 42 syllabus, reinforcing key concepts such as pointer manipulation, dynamic memory allocation (`malloc`, `free`), file descriptors, and data structure maintenance.

### Detailed description of the library

The library contains 43 functions organized into three functional categories:

#### 1. Standard Libc Functions
- **Memory Operations:**
  - `ft_memset`: Fills a byte string with a byte value.
  - `ft_bzero`: Writes zero-valued bytes to a string.
  - `ft_memcpy`: Copies memory area without overlap handling.
  - `ft_memmove`: Copies memory area safely handling overlapping regions.
  - `ft_memchr`: Scans memory for a matching character.
  - `ft_memcmp`: Compares byte strings.
  - `ft_calloc`: Allocates memory and sets all bytes to zero with overflow protection.

- **String Operations:**
  - `ft_strlen`: Finds the length of a string.
  - `ft_strlcpy`: Size-bounded string copying with guaranteed null-termination.
  - `ft_strlcat`: Size-bounded string concatenation with guaranteed null-termination.
  - `ft_strchr`: Locates the first occurrence of a character in a string.
  - `ft_strrchr`: Locates the last occurrence of a character in a string.
  - `ft_strncmp`: Compares two strings up to `n` characters.
  - `ft_strnstr`: Locates a substring in a string bounded by length.
  - `ft_strdup`: Allocates and duplicates a string.

- **Character Checks & Number Parsing:**
  - `ft_isalpha`: Checks for an alphabetic character.
  - `ft_isdigit`: Checks for a digit (`0` through `9`).
  - `ft_isalnum`: Checks for an alphanumeric character.
  - `ft_isascii`: Checks whether a character fits into the ASCII character set.
  - `ft_isprint`: Checks for any printable character including space.
  - `ft_toupper`: Converts a lowercase letter to uppercase.
  - `ft_tolower`: Converts an uppercase letter to lowercase.
  - `ft_atoi`: Converts the initial portion of a string to an integer representation.

#### 2. Additional Custom Functions
- **String Processing:**
  - `ft_substr`: Allocates and returns a substring from a string.
  - `ft_strjoin`: Allocates and returns a new string resulting from concatenating two strings.
  - `ft_strtrim`: Trims characters specified in a set from the beginning and end of a string.
  - `ft_split`: Splits a string using a delimiter character into an array of strings.
  - `ft_itoa`: Converts an integer into a string representation.
  - `ft_strmapi`: Applies a function to each character of a string to create a new mapped string.
  - `ft_striteri`: Applies a function to each character of a string in-place.

- **File Descriptor Output:**
  - `ft_putchar_fd`: Outputs a character to a given file descriptor.
  - `ft_putstr_fd`: Outputs a string to a given file descriptor.
  - `ft_putendl_fd`: Outputs a string followed by a newline to a given file descriptor.
  - `ft_putnbr_fd`: Outputs an integer to a given file descriptor.

#### 3. Linked List Functions
- `ft_lstnew`: Allocates and initializes a new list element node.
- `ft_lstadd_front`: Adds a new element at the beginning of a list.
- `ft_lstsize`: Counts the number of elements in a list.
- `ft_lstlast`: Returns the last element of a list.
- `ft_lstadd_back`: Adds a new element at the end of a list.
- `ft_lstdelone`: Frees the memory of a node's content and the node itself.
- `ft_lstclear`: Deletes and frees an entire list and sets its pointer to `NULL`.
- `ft_lstiter`: Iterates over a list and applies a function to the content of each node.
- `ft_lstmap`: Iterates over a list and applies a function to create a new resulting list.

---

## Instructions


### Compilation

All files are compiled using `cc` with the flags `-Wall -Wextra -Werror`.

```bash
make        # Compiles mandatory functions into libft.a
make clean  # Removes object files (.o)
make fclean # Removes object files and libft.a
make re     # Recompiles everything from scratch
```

### Usage

#### Include the Header
Include the header file in your C source files:

```c
#include "libft.h"
```

## Resources

### References & Guides
* [Understanding memmove & Memory Overlap](https://www.youtube.com/watch?v=1eb0d9yCm2M) - Visual explanation of memory overlapping and how `memmove` differs from `memcpy`.
* [42 Cursus Guide - ft_split](https://42-cursus.gitbook.io/guide/0-rank-00/libft/additional-functions/ft_split#commented-solution) - Guide for `ft_split` logic and memory allocation.
* [libftTester](https://github.com/Tripouille/libftTester) - Automated test for Libft.
* Linux Programmer's Manual (man pages for standard libc functions).

### AI usage
- **How AI was used:** AI was used for prompt-based code review, conceptual explanations, edge-case analysis, and README structure formatting.
- **For which tasks:** AI helped analyze potential edge cases (such as NULL pointers, memory overlapping in memory functions, and delimiter handling in string manipulation) and provided explanations for standard library specifications.
- **Which parts:** 
  - *Makefile:* Reviewed rules and pattern substitutions (`$(SRCS:.c=.o)`) to ensure clean compilation without relinking.
  - *Logic analysis:* Evaluated boundary cases in `ft_split` (allocation failure cleanup) and `ft_strtrim` (edge delimiter handling).
  - *Documentation:* Assisted in structuring and verifying compliance of this `README.md` with Chapter V guidelines.
