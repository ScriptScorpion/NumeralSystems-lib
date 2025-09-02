### How-to-use:
  
# Binary-lib:
  * for C language files `#include "binary.h"`, for C++ language files `#include "binary.hpp"`, for Assembly language files `%INCLUDE "binary.asm"`.
  * for C/C++ files do `unsigned int p = ToBinary(number)` 'number' - it is any number greater than 0.
  * for Assembly language files move number into `rdi` register and do `call ToBinary` and you get output into `rax` register.
# Hex-lib:
  * for C language files `#include "hex.h"`, for C++ language files `#include "hex.hpp"`.
  * for C language files do `char *p = ToHex(number)` 'number' - it is any number greater than 0, don't forget to do `free(p)` before exiting from program.
  * for C++ language files do `std::string p = ToHex(number)` 'number' - it is any number greater than 0.
