# C++ Modules

## Overview
This repository contains exercises focusing on namespaces, classes, member functions, standard I/O streams, initialization lists, static and const keywords, and other basic C++ concepts. All code should comply with the C++98 standard.

## Compiling
- Compile your code with the following flags:
  ```bash
  c++ -Wall -Wextra -Werror
## Formatting and Naming Conventions
- Write class names in **UpperCamelCase** format. Files containing class code will be named according to the class name. For instance:
  - For a class named `BrickWall`, the files should be:
    - `BrickWall.hpp` or `BrickWall.h`
    - `BrickWall.cpp` or `BrickWall.tpp`
- Unless specified otherwise, every output message must end with a new-line character and be displayed to the standard output.

## Allowed/Forbidden
- You are allowed to use almost everything from the standard library. It’s advisable to utilize C++-style functions instead of C-style functions.
- You cannot use any external libraries. This includes C++11 (and later) and Boost libraries.
- The following functions are forbidden:
  - `*printf()`
  - `*alloc()` and `free()`
