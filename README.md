# How-to-use:
* for C language files `#include "binary.h"`, for C++ language files `#include "binary.hpp"`, for Assembly language files `%INCLUDE "binary.asm"` 
* for C/C++ files do `ToBinary(number)` 'number' - it is any number greater than 0
* for Assembly language files move number into `rdi` register and do `call ToBinary` and you get output into `rax` register.
