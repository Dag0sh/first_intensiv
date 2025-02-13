***== Quest 1 received. Make corrections in the src/maxmin.c program so it compiles itself and works correctly (finds max and min out of 3 integer numbers and displays them on the screen). Do not change the structure of the program. In case of incorrect input, you must output n/a. ==***

| Input | Output |
| ------ | ------ |
| 1 2 3 | 3 1 |

***== Quest 2 received. Make corrections in the src/squaring.c program so it compiles itself and works correctly (receives an array of integers via stdin, squares them and outputs the result to stdout). In case of incorrect input, you must output n/a. Decreasing the decomposition is not allowed–you can add functions if needed, but you cannot delete them. ==***

| Input | Output |
| ------ | ------ |
| 3<br/>1 2 3 | 1 4 9 |

***== Quest 3 received. Add implementations of the necessary functions into 
the src/stat.c program so it compiles itself and works correctly (receives 
an array of integers via stdin, displays it, calculates and displays on the new line a set 
of statistical metrics – maxima and minima, the expected value, and variance, assuming that we are dealing with a discrete uniform distribution). 
In case of incorrect input, you must output n/a. Decreasing the decomposition 
is not allowed – you can add functions if needed, but you cannot delete them. 
Stick to the recommended program structure. Output floating-point numbers with an accuracy of 6 decimal places. ==***

| Input | Output |
| ------ | ------ |
| 4<br/>1 2 3 4 | 1 2 3 4<br>4 1 2.500000 1.250000 |

***== Quest 4 received. Implement the src/search.c program in accordance with the comment. The program has to receive an array of integers via stdin and find the first occurrence of number that meets the following requirements in that array: even number, equal to or above the expected value, follows the three-sigma rule, does not equal 0. The number it finds must be output to stdout. If such number does not exist, the program must output 0. The maximum number of numbers entered is 30. In case of incorrect input, you must output n/a. During the development, stick to the ideas of decomposition from previous quests; you are welcome to reuse the functions that have already been developed. The functions must be simple and compact and take up no more than 20–30 lines of code. ==***

| Input | Output |
| ------ | ------ |
| 4<br/>1 2 3 4 | 4 |
