***== Quest 1 received. Modify the src/electro_snake.c program so it performs the sorting of the given matrix in a snake-like order vertically and horizontally, and outputs the sorted matrices in the same order, one after another, with an empty line in between. Do not change the recommended structure of the program. There should be NO spaces at the end of each line. After the last matrix is output, the '\n' sign is not required. In case of any erros output `n/a`. ==***

| Input | Output |
| ------ | ------ |
| 3 3<br/>1 2 3<br/>4 5 6<br/>7 8 9 | 1 6 7<br/>2 5 8<br/>3 4 9<br/><br/>1 2 3<br/>6 5 4<br/>7 8 9<br/> |
| 2 4<br/>1 2 3 4<br/>5 6 7 8 | 1 4 5 8<br/>2 3 6 7<br/><br/>1 2 3 4<br/>8 7 6 5<br/> |
| 0 0 | n/a |
| 3 3<br/>-1 -2 -3<br/>-4 -5 -6<br/>-7 -8 -9 | -9 -4 -3<br/>-8 -5 -2<br/>-7 -6 -1<br/><br/>-9 -8 -7<br/>-4 -5 -6<br/>-3 -2 -1<br/> |

***== Quest 2 received. Change the src/det.c program so it calculates and outputs the determinant of the given square matrix with float numbers. If it's impossible to calculate the determinant, output "n/a". Output numbers with an accuracy of 6 decimal places. ==***

| Input | Output |
| ------ | ------ |
| 3 3<br/>1 2 3<br/>4 5 6<br/>7 8 9 | 0.000000 |

***== Quest 3 received. Modify the src/invert.c program so it calculates and outputs the inverse matrix for the given square matrix with float numbers. For errors, display "n/a". There should be NO spaces at the end of each line. After the last row of the matrix is output, the '\n ' sign is not required. Output numbers should be separated by a space with an accuracy of 6 decimal places. ==***

| Input | Output |
| ------ | ------ |
| 3 3<br/>1 0.5 1<br/>4 1 2<br/>3 2 2 | -1.000000 0.500000 0.000000<br/>-1.000000 -0.500000 1.000000<br/>2.500000 -0.250000 -0.500000 |

***== Quest 4 received. Modify the src/sle.c program so it solves a system of linear equations using either Cramer's rule or Gaussian elimination, at your discretion. Implementing one method is enough. Equation coefficients should be entered as a matrix via stdin. You also need to create the output of the response to stdout. Do not forget about decomposition: functions should be easy to read and not too bulky. For errors, display "n/a". Numbers should be separated by a space with an accuracy of 6 decimal places. There should be no space at the end of the output. ==***

| Input | Output |
| ------ | ------ |
| 3 4<br/>1 1 1 2<br/>4 5 3 7<br/>2 7 7 9 | 1.000000 0.000000 1.000000 |
