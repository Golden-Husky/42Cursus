*This project has been created as part of the 42 curriculum by rsangjan.*

# Libft

## Description
Libft is the foundational project of the 42 curriculum. The objective is to build a personal C static library (`libft.a`) containing re-implementations of essential standard C library (`libc`) routines, additional string and memory manipulation utilities, and singly linked list management functions.

Developing `libft` establishes a rigorous understanding of memory layout, pointer arithmetic, dynamic memory allocation (`malloc`, `free`), file descriptors, and dynamic data structures in C. This static library serves as the core utility toolkit for subsequent projects throughout the 42 syllabus.

---

## Detailed Description of the Library

The library contains 43 functions organized into three functional modules:

### 1. Standard Libc Functions

#### Memory Operations
| Function Prototype | Description | Return Value |
| :--- | :--- | :--- |
| `void *ft_memset(void *b, int c, size_t len)` | Writes `len` bytes of value `c` (converted to an `unsigned char`) to the memory block `b`. | A pointer to the memory area `b`. |
| `void ft_bzero(void *s, size_t n)` | Writes zero bytes (`'\0'`) to the string `s` for `n` bytes. | None. |
| `void *ft_memcpy(void *dst, const void *src, size_t n)` | Copies `n` bytes from memory area `src` to memory area `dst`. Memory areas must not overlap. | A pointer to `dst`. |
| `void *ft_memmove(void *dst, const void *src, size_t len)` | Copies `len` bytes from `src` to `dst`. Safely handles overlapping memory buffers by checking relative pointer locations. | A pointer to `dst`. |
| `void *ft_memchr(const void *s, int c, size_t n)` | Scans the initial `n` bytes of the memory area pointed to by `s` for the first occurrence of `c`. | A pointer to the matching byte, or `NULL` if not found. |
| `int ft_memcmp(const void *s1, const void *s2, size_t n)` | Compares the first `n` bytes of memory areas `s1` and `s2` byte by byte (as `unsigned char`). | `< 0`, `0`, or `> 0` depending on whether `s1` is less than, matching, or greater than `s2`. |
| `void *ft_calloc(size_t count, size_t size)` | Allocates memory for an array of `count` elements of `size` bytes each using `malloc`, initializing all bytes to zero. Prevents integer overflow during size calculation. | A pointer to allocated memory, or `NULL` on allocation failure. |

#### String Operations
| Function Prototype | Description | Return Value |
| :--- | :--- | :--- |
| `size_t ft_strlen(const char *s)` | Computes the length of the string `s`, excluding the terminating null byte. | The number of characters preceding the terminating null character. |
| `size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)` | Copies up to `dstsize - 1` characters from `src` to `dst`, null-terminating the result if `dstsize` is not 0. | The total length of the string `src`. |
| `size_t ft_strlcat(char *dst, const char *src, size_t dstsize)` | Appends the null-terminated string `src` to the end of `dst`, using at most `dstsize - strlen(dst) - 1` bytes and guaranteeing null-termination. | Initial length of `dst` plus length of `src`, or `dstsize + strlen(src)` if `dstsize <= strlen(dst)`. |
| `char *ft_strchr(const char *s, int c)` | Locates the first occurrence of `c` (converted to a `char`) in the string `s`. The null terminator is considered part of the string. | A pointer to the matched character, or `NULL` if not found. |
| `char *ft_strrchr(const char *s, int c)` | Locates the last occurrence of `c` in the string `s`. | A pointer to the matched character, or `NULL` if not found. |
| `int ft_strncmp(const char *s1, const char *s2, size_t n)` | Compares not more than `n` characters of strings `s1` and `s2` using unsigned character values. | An integer less than, equal to, or greater than zero. |
| `char *ft_strnstr(const char *haystack, const char *needle, size_t len)` | Locates the first occurrence of null-terminated string `needle` within `haystack`, searching no more than `len` characters. | Pointer to the beginning of the located substring, `haystack` if `needle` is empty, or `NULL` if absent. |
| `char *ft_strdup(const char *s1)` | Allocates sufficient memory via `malloc` to copy `s1`, performs the copy, and returns a pointer to it. | Pointer to the duplicated string, or `NULL` on allocation failure. |

#### Character Checks & Number Parsing
| Function Prototype | Description | Return Value |
| :--- | :--- | :--- |
| `int ft_isalpha(int c)` | Tests for any character for which `isupper` or `islower` is true. | Non-zero if true; `0` if false. |
| `int ft_isdigit(int c)` | Tests for a decimal digit character (`'0'` through `'9'`). | Non-zero if true; `0` if false. |
| `int ft_isalnum(int c)` | Tests for any alphanumeric character (combination of `isalpha` and `isdigit`). | Non-zero if true; `0` if false. |
| `int ft_isascii(int c)` | Tests whether `c` fits into the ASCII character set (values `0` to `127`). | Non-zero if true; `0` if false. |
| `int ft_isprint(int c)` | Tests for any printable character, including space (ASCII `32` to `126`). | Non-zero if true; `0` if false. |
| `int ft_toupper(int c)` | Converts a lower-case letter (`'a'`–`'z'`) to the corresponding upper-case letter (`'A'`–`'Z'`). | The converted letter, or `c` unchanged if no conversion is possible. |
| `int ft_tolower(int c)` | Converts an upper-case letter (`'A'`–`'Z'`) to the corresponding lower-case letter (`'a'`–`'z'`). | The converted letter, or `c` unchanged if no conversion is possible. |
| `int ft_atoi(const char *str)` | Converts the initial portion of the string pointed to by `str` to an `int` representation, handling optional leading whitespace and signs. | The converted integer value. |

---

### 2. Additional Custom Functions

#### String Processing & Transformation
| Function Prototype | Description | Return Value |
| :--- | :--- | :--- |
| `char *ft_substr(char const *s, unsigned int start, size_t len)` | Allocates and returns a substring from string `s`. The substring begins at index `start` and is of maximum size `len`. | The substring, or `NULL` on allocation failure. |
| `char *ft_strjoin(char const *s1, char const *s2)` | Allocates and returns a new string, which is the result of the concatenation of `s1` and `s2`. | The new string, or `NULL` on allocation failure. |
| `char *ft_strtrim(char const *s1, char const *set)` | Allocates and returns a copy of `s1` with characters specified in `set` removed from the beginning and the end. | The trimmed string, or `NULL` on allocation failure. |
| `char **ft_split(char const *s, char c)` | Allocates and returns an array of strings obtained by splitting `s` using character `c` as delimiter. Array is null-terminated. Deallocates preceding memory blocks if an allocation failure occurs midway. | The array of new strings, or `NULL` on allocation failure. |
| `char *ft_itoa(int n)` | Allocates and returns a string representing the integer received as an argument, accounting for negative signs and minimum integer values (`-2147483648`). | The string representing the integer, or `NULL` on allocation failure. |
| `char *ft_strmapi(char const *s, char (*f)(unsigned int, char))` | Applies the function `f` to each character of string `s`, passing its index, to create a new string resulting from successive applications of `f`. | The string created from the transformations, or `NULL` on allocation failure. |
| `void ft_striteri(char *s, void (*f)(unsigned int, char*))` | Applies the function `f` on each character of string `s`, passing its index as first argument. Each character is passed by address to `f` to be modified in place. | None. |

#### File Descriptor Output
| Function Prototype | Description | Return Value |
| :--- | :--- | :--- |
| `void ft_putchar_fd(char c, int fd)` | Outputs the character `c` to the given file descriptor `fd` using the `write` system call. | None. |
| `void ft_putstr_fd(char *s, int fd)` | Outputs the string `s` to the given file descriptor `fd`. | None. |
| `void ft_putendl_fd(char *s, int fd)` | Outputs the string `s` followed by a newline (`'\n'`) to the given file descriptor `fd`. | None. |
| `void ft_putnbr_fd(int n, int fd)` | Outputs the integer `n` to the given file descriptor `fd`, handling recursion and the edge case of negative values. | None. |

---

### 3. Linked List Operations

The list manipulation component utilizes the following structure defined in `libft.h`:

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
