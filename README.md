# McScript Interpreter

I wrote an interpreter for a language that I am calling "McScript". The syntax
mimics that of basic JavaScript. For now, the only thing this language can do is
print strings and integers to the standard output. It can also store variables in memory
for later use and do basic arithmetic. This is not intended as a commercial enterprise, but just for fun.

## How to Use
- Clone repository to local machine
- From the **src** directory type the following command `make main`
- Once the project has compiled, type the following command from the root of the project:
    `./main [source file]`
- There is a sample source file (test.fs) in the project root for demo purposes. All source
    files must have the ".fs" extension.
- *Note: This has only been tested on Linux (Ubuntu)*