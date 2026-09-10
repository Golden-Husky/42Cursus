*This project has been created as part of the 42 curriculum by rsangjan.*

# Libft

## Description
Libft is the introductory project of the 42 curriculum. The goal is to build a personal C static library (`libft.a`) by re-implementing core standard C library (`libc`) routines, additional string and memory manipulation utilities, and singly linked list operations.

This static library serves as the core foundation for future C projects in the 42 syllabus, reinforcing key concepts such as pointer manipulation, memory allocation (`malloc`, `free`), file descriptors, and data structure maintenance.

### Detailed Description of the Library

The library contains 43 functions categorized into three primary modules:

#### 1. Standard Libc Functions

##### Memory Operations
| Function | Prototype | Description | Return Value |
| :--- | :--- | :--- | :--- |
| `ft_memset` | `void *ft_memset(void *b, int c, size_t len)` | Writes `len` bytes of value `c` (converted to an `unsigned char`) to the memory block `b`. | A pointer to `b`. |
| `ft_bzero` | `void ft_bzero(void *s, size_t n)` | Writes zero bytes (`'\0'`) to the string `s` for `n` bytes. | None. |
| `ft_memcpy` | `void *ft_memcpy(void *dst, const void *src, size_t n)` | Copies `n` bytes from `src` to `dst`. Memory areas must not overlap. | A pointer to `dst`. |
| `ft_memmove` | `void *ft_memmove(void *dst, const void *src, size_t len)` | Copies `len` bytes from `src` to `dst`. Handles overlapping memory areas safely. | A pointer to `dst`. |
| `ft_memchr` | `void *ft_memchr(const void *s, int c, size_t n)` | Scans the initial `n` bytes of memory area `s` for the first occurrence of `c`. | Pointer to the matching byte, or `NULL` if not found. |
| `ft_memcmp` | `int ft_memcmp(const void *s1, const void *s2, size_t n)` | Compares the first `n` bytes of memory blocks `s1` and `s2` byte by byte. | Difference between the first differing pair of bytes, or `0` if equal. |
| `ft_calloc` | `void *ft_calloc(size_t count, size_t size)` | Allocates memory for an array of `count` items of `size` bytes each and initializes all bytes to zero. Prevents integer overflow. | Pointer to allocated memory, or `NULL` on failure. |

##### String Operations
| Function | Prototype | Description | Return Value |
| :--- | :--- | :--- | :--- |
| `ft_strlen` | `size_t ft_strlen(const char *s)` | Computes the length of the null-terminated string `s`. | Number of characters preceding the terminating null character. |
| `ft_strlcpy` | `size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)` | Copies up to `dstsize - 1` characters from `src` to `dst`, null-terminating the result if `dstsize` is non-zero. | Total length of `src`. |
| `ft_strlcat` | `size_t ft_strlcat(char *dst, const char *src, size_t dstsize)` | Appends null-terminated string `src` to the end of `dst`, bounded by `dstsize`, guaranteeing null-termination. | Initial length of `dst` plus length of `src`, or `dstsize + strlen(src)` if `dstsize <= strlen(dst)`. |
| `ft_strchr` | `char *ft_strchr(const char *s, int c)` | Locates the first occurrence of `c` (converted to a `char`) in string `s`. | Pointer to the matched character, or `NULL` if not found. |
| `ft_strrchr` | `char *ft_strrchr(const char *s, int c)` | Locates the last occurrence of `c` in string `s`. | Pointer to the matched character, or `NULL` if not found. |
| `ft_strncmp` | `int ft_strncmp(const char *s1, const char *s2, size_t n)` | Compares at most `n` characters between strings `s1` and `s2`. | `< 0`, `0`, or `> 0` depending on whether `s1` is less than, matching, or greater than `s2`. |
| `ft_strnstr` | `char *ft_strnstr(const char *haystack, const char *needle, size_t len)` | Finds the first occurrence of `needle` within `haystack` searching up to `len` characters. | Pointer to the beginning of the match, `haystack` if `needle` is empty, or `NULL` if absent. |
| `ft_strdup` | `char *ft_strdup(const char *s1)` | Allocates sufficient memory via `malloc` and duplicates string `s1`. | Pointer to the new duplicate string, or `NULL` on failure. |

##### Character Checks & Number Parsing
| Function | Prototype | Description | Return Value |
| :--- | :--- | :--- | :--- |
| `ft_isalpha` | `int ft_isalpha(int c)` | Tests for an alphabetic character (`'a'`–`'z'`, `'A'`–`'Z'`). | Non-zero if true; `0` if false. |
| `ft_isdigit` | `int ft_isdigit(int c)` | Tests for a decimal digit character (`'0'`–`'9'`). | Non-zero if true; `0` if false. |
| `ft_isalnum` | `int ft_isalnum(int c)` | Tests for an alphanumeric character (`isalpha` or `isdigit`). | Non-zero if true; `0` if false. |
| `ft_isascii` | `int ft_isascii(int c)` | Tests if `c` belongs to the ASCII character set (`0` to `127`). | Non-zero if true; `0` if false. |
| `ft_isprint` | `int ft_isprint(int c)` | Tests for any printable character including space (`32` to `126`). | Non-zero if true; `0` if false. |
| `ft_toupper` | `int ft_toupper(int c)` | Converts lowercase letter (`'a'`–`'z'`) to uppercase (`'A'`–`'Z'`). | Converted character, or original character if no conversion. |
| `ft_tolower` | `int ft_tolower(int c)` | Converts uppercase letter (`'A'`–`'Z'`) to lowercase (`'a'`–`'z'`). | Converted character, or original character if no conversion. |
| `ft_atoi` | `int ft_atoi(const char *str)` | Converts the initial portion of `str` to an integer, handling leading whitespaces and signs. | The converted integer value. |

---

#### 2. Additional Functions

##### String Processing
| Function | Prototype | Description | Return Value |
| :--- | :--- | :--- | :--- |
| `ft_substr` | `char *ft_substr(char const *s, unsigned int start, size_t len)` | Allocates and returns a substring from `s`, starting at index `start` with maximum length `len`. | Substring, or `NULL` on failure. |
| `ft_strjoin` | `char *ft_strjoin(char const *s1, char const *s2)` | Allocates and returns a new string resulting from concatenating `s1` and `s2`. | New string, or `NULL` on failure. |
| `ft_strtrim` | `char *ft_strtrim(char const *s1, char const *set)` | Allocates and returns a copy of `s1` with all characters in `set` stripped from both ends. | Trimmed string, or `NULL` on failure. |
| `ft_split` | `char **ft_split(char const *s, char c)` | Allocates and returns an array of strings by splitting `s` using delimiter `c`. Cleans up allocated memory if allocation fails midway. | Null-terminated string array, or `NULL` on failure. |
| `ft_itoa` | `char *ft_itoa(int n)` | Allocates and returns a string representing integer `n`, correctly handling signs and `-2147483648`. | Converted numeric string, or `NULL` on failure. |
| `ft_strmapi` | `char *ft_strmapi(char const *s, char (*f)(unsigned int, char))` | Creates a new string by applying `f` to each character and index of string `s`. | Resulting string, or `NULL` on failure. |
| `ft_striteri` | `void ft_striteri(char *s, void (*f)(unsigned int, char*))` | Applies `f` to each character and index of string `s` in-place using addresses. | None. |

##### File Descriptor Output
| Function | Prototype | Description | Return Value |
| :--- | :--- | :--- | :--- |
| `ft_putchar_fd` | `void ft_putchar_fd(char c, int fd)` | Outputs character `c` to the specified file descriptor `fd`. | None. |
| `ft_putstr_fd` | `void ft_putstr_fd(char *s, int fd)` | Outputs string `s` to the specified file descriptor `fd`. | None. |
| `ft_putendl_fd` | `void ft_putendl_fd(char *s, int fd)` | Outputs string `s` followed by a newline (`'\n'`) to `fd`. | None. |
| `ft_putnbr_fd` | `void ft_putnbr_fd(int n, int fd)` | Outputs integer `n` to the specified file descriptor `fd`. | None. |

---

#### 3. Linked List Functions

These functions manipulate linked lists using the node definition declared in `libft.h`:

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
