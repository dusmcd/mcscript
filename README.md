# McScript Interpreter

I wrote an interpreter for a language that I am calling "McScript". The syntax
mimics that of basic JavaScript.

## Current Features
- Prints integers and strings to the standard output
- Basic arithmetic functions (i.e., addition, subtraction, multiplication, and division)
- Store variables in memory for later use
- Function declarations and calls (everything that can be done in the global scope can be done inside a function)

## How to Use
- Clone repository to local machine
- From the **src** directory type the following command `make main`
- Once the project has compiled, type the following command from the root of the project:
    `./main [source file]`
- There is a sample source file (test.ms) in the project root for demo purposes. All source
    files must have the ".ms" extension.
- *Note: This has only been tested on Ubuntu 22.04*
