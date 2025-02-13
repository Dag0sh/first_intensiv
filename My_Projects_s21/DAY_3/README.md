***== Quest 1 received. Create an src/hello.c program that displays "Hello, AI!" on the screen using the formatted output functions from the standard library. Here and elsewhere, all programs must be written in C programming language C11 standard using the GCC compiler, flags -Wall, -Werror, -Wextra and the Google C++ Style Guide; only source files with code and data files (if necessary) should be pushed to git (to the src directory, develop branch). It is allowed to connect only the header file `<stdio.h>` ==***

***== Quest 2 received. Create an src/named_hello.c program that receives 
    an integer `name` via stdin and outputs "Hello, `name`!" to the screen. 
    Only source files with code and data files (if necessary) should be 
    pushed to git (to the src directory, develop branch). There is also
    restriction: only `<stdio.h>` can be used. ==***

| Input | Output |
| ------ | ------ |
| 123 | Hello, 123! |

***== Quest 3 received. Create an src/arithmetic.c program that receives two integers via stdin and outputs their sum, difference, product, and quotient, separated by a space in this particular order. Add a check for the input data so the program only receives integers. The answer must not end with a space. Add the option for processing division by zero. In case of any error, output "n/a". Only source files with code and data files (if necessary) should be pushed to git (to the src directory, develop branch). It is allowed to connect only the header file `<stdio.h>` ==***

| Input | Output |
| ------ | ------ |
| 8 2 | 10 6 16 4 |
| 1 0 | 1 1 0 n/a |
| 3 2 | 5 1 6 1 |

***== Quest 4 received. Create an src/max.c program that receives two integers and displays the highest of them on the screen. Add a check for the input data so the program only receives numbers — in case of an error, output n/a. Organize the search for the maximum value as a separate function. Only source files with code and data files (if necessary) should be pushed to git (to the src directory, develop branch, this will no longer be recalled in the future...) Only the `<stdio.h>` library can be included. ==***

| Input | Output |
| ------ | ------ |
| 3 2 | 3 |
| 12.3 10 | n/a |

***== Quest 5 received. Create an src/important_function.c program that receives one floating-point number `x` and displays the result of calculating the function on the screen (rounding to one digit after the decimal point). Add a check for the input data so the program only receives numbers. For errors, display "n/a". In this quest, in addition to `<stdio.h>` you can use the library `<math.h>` ==***

| Input | Output |
| ------ | ------ |
| 1 | -2070.4 |

***== Quest 6 received. Modify the src/float_compare.c program so it displays "OK!" at the end. Use comparison to a small value (about 1E-6). Declaring variables or constants is not considered an additional code change. ==***

***== Quest 7 received. Create an src/crack.c program that receives two floating-point numbers and outputs "GOTCHA" if the coordinates of the point are inside the circle, and "MISS" otherwise. Provide for entering only numbers — in case of an error, output n/a, can be used 
only `<stdio.h>`. ==***

| Input | Output |
| ------ | ------ |
| 1.5 1.5 | GOTCHA |
