# ft_printf
## Description

ft_printf is a custom implementation of the standard C printf function.
It allows formatted output to the standard output (stdout) and supports a subset of standard conversion specifiers.
This project demonstrates mastery of variadic functions, flags, width, precision, and string manipulation in C.

## Features

### Handles format specifiers:

%c — character

%s — string

%p — pointer address

%d / %i — signed integers

%u — unsigned integers

%x / %X — hexadecimal

%% — literal percent sign

### Supports flags:

- (left-justify)

0 (zero-padding)

+ (force sign)

space (prepend space for positive numbers)

### (alternate form for hex/octal)

Handles width and precision

Built using variadic functions (stdarg.h) and modular C design.
