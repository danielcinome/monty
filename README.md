# C - Stacks, Queues - LIFO, FIFO

### The Monty language

Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

**Monty byte code files**

Files containing Monty byte codes usually have the  `.m`  extension. Most of the industry uses this standard but it is not required by the specification of the language.
### Data structures
```
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

```

```
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
```
**The monty program**

-   Usage:  `monty file`
    -   where  `file`  is the path to the file containing Monty byte code
-   If the user does not give any file or more than one argument to your program, print the error message  `USAGE: monty file`, followed by a new line, and exit with the status  `EXIT_FAILURE`
-   If, for any reason, its not possible to open the file, print the error message  `Error: Can't open file <file>`, followed by a new line, and exit with the status  `EXIT_FAILURE`
    -   where  `<file>`  is the name of the file
-   If the file contains an invalid instruction, print the error message  `L<line_number>: unknown instruction <opcode>`, followed by a new line, and exit with the status  `EXIT_FAILURE`
    -   where  is the line number where the instruction appears.
    -   Line numbers always start at 1
-   The monty program runs the bytecodes line by line and stop if either:
    -   it executed properly every line of the file
    -   it finds an error in the file
    -   an error occured
-   If you cant malloc anymore, print the error message  `Error: malloc failed`, followed by a new line, and exit with status  `EXIT_FAILURE`.
-   You have to use  `malloc`  and  `free`  and are not allowed to use any other function from  `man malloc`  (realloc, calloc, )
### Compilation & Output

-   Your code will be compiled this way:

```
$ gcc -Wall -Werror -Wextra -pedantic *.c -o monty
```
**The opcode**
-  `pop` removes the top element of the stack.
-  `pint` prints the value at the top of the stack, followed by a new line.
-  `swap` swaps the top two elements of the stack.
-  `add` adds the top two elements of the stack.
-  `nop` doesnt do anything.
-  `sub` subtracts the top element of the stack from the second top element of the stack.
- `div` divides the second top element of the stack by the top element of the stack.
-  `mul` multiplies the second top element of the stack with the top element of the stack.
-  `mod` computes the rest of the division of the second top element of the stack by the top element of the stack.
-  `pchar` prints the char at the top of the stack, followed by a new line.
-  `pstr` prints the string starting at the top of the stack, followed by a new line.
-  `rotl` rotates the stack to the top.
-  `rotr` rotates the stack to the bottom.
-  `stack` sets the format of the data to a stack (LIFO). This is the default behavior of the program.
-  `queue` sets the format of the data to a queue (FIFO).

**Example**

![N|Solid](https://i.ibb.co/b3CGshH/Captura.png)

**Output**

![N|Solid](https://i.ibb.co/yn90W5b/Captura.png)

## Author
- Daniel Chinome - [Github](https://github.com/danielcinome) / [Twitter](https://twitter.com/DanielChinome)
- Oscar Riaño -  [Github](https://github.com/OscarDRT/) / [Twitter](https://twitter.com/Oscar__RT)

