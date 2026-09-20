*This project has been created as part of the 42 curriculum by rsangjan.*

# ft_printf

## Description

`ft_printf` is a reimplementation of the standard C `printf()` function. It builds the static library `libftprintf.a`, which provides:

```c
int	ft_printf(const char *format, ...);
```

The function reads a format string, prints output to standard output, and returns the total number of printed characters.

### Supported conversions

| Conversion | Output |
| --- | --- |
| `%c` | A single character |
| `%s` | A string |
| `%p` | A pointer address in lowercase hexadecimal |
| `%d`, `%i` | A signed decimal integer |
| `%u` | An unsigned decimal integer |
| `%x`, `%X` | A lowercase or uppercase hexadecimal integer |
| `%%` | A literal percent sign |

The mandatory version does not implement the original `printf()` buffer management or bonus flags.

## Project Structure

```text
ft_printf.c          Main format-string scanner
ft_printf_format.c   Conversion dispatch and variadic argument extraction
ft_printf_utils.c    Character, string, and pointer output helpers
ft_printf_numbers.c  Decimal and hexadecimal output helpers
ft_printf.h          Public interface and helper declarations
Makefile             Static-library build rules
```

## Algorithm and Data Structure

### Format scanning

`ft_printf` scans the format string one character at a time.

```text
ordinary character -> print it directly
% + specifier      -> dispatch to the matching helper
```

For example, `ft_printf("Age: %d", 42)` prints `Age: ` directly, then extracts `42` from the variadic arguments and prints it in decimal.

### Variadic arguments

The implementation uses `va_list`, `va_start`, `va_arg`, and `va_end` from `<stdarg.h>`.

```text
%c         -> int
%s         -> char *
%p         -> void *
%d, %i     -> int
%u, %x, %X -> unsigned int
```

The format dispatcher receives a pointer to the active `va_list`, so each `va_arg` call advances the same argument reader.

### Number conversion

Decimal and hexadecimal values use recursion. Each recursive call processes the more significant digits first, then the current call prints the final digit.

```text
507 / 10 -> 50, remainder 7
 50 / 10 ->  5, remainder 0
  5 / 10 ->  0, remainder 5

output: 5, then 0, then 7
```

Hexadecimal conversions follow the same method with base 16:

```text
0123456789abcdef
0123456789ABCDEF
```

No dynamic data structure is used. Output is written directly, while recursion uses the call stack to order number digits.

## Instructions

### Build

```bash
make
make clean
make fclean
make re
```

### Usage

Include the header:

```c
#include "ft_printf.h"
```

Build the library, then link it with a program:

```bash
cc -Wall -Wextra -Werror main.c -L. -lftprintf -o program
./program
```

Example:

```c
int	printed;

printed = ft_printf("Hello, %s! Score: %d%%\n", "42", 100);
```

## Resources

- [printf(3) Linux manual page](https://man7.org/linux/man-pages/man3/printf.3.html)
- [stdarg(3) Linux manual page](https://man7.org/linux/man-pages/man3/stdarg.3.html)
- [write(2) Linux manual page](https://man7.org/linux/man-pages/man2/write.2.html)
- [C reference: variadic functions](https://en.cppreference.com/w/c/variadic)

## AI Usage

AI was used as a learning and review tool for variadic functions, recursion, integer conversion, pointer output, static-library linking, Makefile rules, and Norminette-driven code organization.

The author developed and tested the implementation. AI was also used to review debugging output, identify a conditional-operator mistake in the format scanner, suggest edge cases, and structure this README. All suggestions were reviewed, understood, and adapted before use.
