*This project has been created as part of the 42 curriculum by rsangjan .*

# Libft

## Description
Libft is the very first project in the 42 curriculum. The goal of this project is to create a custom C static library (`libft.a`) by re-implementing several standard C library functions (`libc`), along with additional utility functions and linked list manipulation functions. 

Developing this library provides a deep understanding of memory allocation, pointer manipulation, and foundational algorithms in C, serving as the essential building block for future 42 projects.

---

## Detailed Description of the Library
The library consists of three primary parts:

1. **Part 1 - Libc Functions:**
   - **Memory:** `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc`
   - **Strings:** `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_strdup`
   - **Character Checks & Conversion:** `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`, `ft_toupper`, `ft_tolower`, `ft_atoi`

2. **Part 2 - Additional Functions:**
   - Functions not present in the standard libc or present in a different form:
     - `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_itoa`, `ft_strmapi`, `ft_striteri`
   - File descriptor output:
     - `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`

3. **Bonus Part - Linked List Operations:**
   - Functions utilizing the `t_list` structure to manage singly linked lists:
     - `ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`, `ft_lstlast`, `ft_lstadd_back`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`

---

## Instructions

### Compilation
The library is compiled into `libft.a` using GNU Make and `cc` with the flags `-Wall -Wextra -Werror`.

- To compile the standard library:
  ```bash
  make
