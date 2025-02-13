***== Quest 1 received. Modify the src/sort.c program from the previous room to 
allocate the memory for the array dynamically (using the malloc or calloc function).
The length of the array `n` is specified in stdin prior to inputting the array.
In case of any error, output "n/a". There should be no line break character at 
the end of the output==***

| Input | Output |
| ------ | ------ |
| 10<br/>4 3 9 0 1 2 100 2 7 -1 | -1 0 1 2 2 3 4 7 9 100 |

***== Quest 2 received. Create an src/sort_no_leak.c program to fix the memory leak in the src/sort.c program. If there was no leak in the first place, then shrug the shoulders and copy src/sort.c to src/sort_no_leak.c. ==***

| Input | Output |
| ------ | ------ |
| 10<br/>4 3 9 0 1 2 100 2 7 -1 | -1 0 1 2 2 3 4 7 9 100 |

***== Quest 3 received. Add the src/matrix.c program that inputs 
and outputs integer matrices. Matrix memory allocation must be implemented in 
4 types: one static and 3 dynamic ones. For static memory allocation, the 
maximum size of the matrix does not exceed 100 x 100. To select the method 
of memory allocation in the program, you need to implement the menu with 
subparagraphs 1–4. The size of the matrix (first the number of rows, then the columns) is taken from two numbers in stdin 
right before its input. You also need to clean up all allocated memory. Refer to the 
materials folder for help. Pay attention to the output of the matrix:
there should be no extra spaces at the end of each line. There should not be a 
newline break character after the last line. In case of any error, output "n/a". ==***


| Input | Output |
| ------ | ------ |
| 2<br>2 2<br>4 3<br>9 0 | 4 3<br>9 0 |

***== Quest 4 received. Add the src/matrix_extended.c program, which expands 
the functionality of the src/matrix.c program. You need to calculate the maximum 
elements of the matrix in each of its rows and the minimum elements in each of 
its columns and output these values ​​at the end after the output of the 
matrix as two arrays (an array of maximum elements in each row and an 
array of minimum elements in each column). The first number is the number of the memory allocation method. Also note: no hyphenation 
characters after the last line(!)==***

| Input | Output |
| ------ | ------ |
| 2<br>3 3<br>4 3 1<br>9 0 55<br>-4 7 111 | 4 3 1<br>9 0 55<br>-4 7 111<br>4 55 111<br>-4 0 1 |

***== Quest 5 received. Modify the src/picture.c program so it recreates the picture from [the room wall](#level-2-room-3) in the terminal using arrays and matrices from the code. You are not allowed to change static arrays or matrices. ==***

***== Quest 6 received. Add an src/matrix_sort.c program that sorts the given 
matrix, putting rows with the minimum sum of elements first, followed by rows 
with the maximum sum of elements. Input data for the program are numbers N 
and M – matrix dimensions, and NxM of the numbers – matrix elements. The memory 
for the matrix must be allocated dynamically using one of the 3 methods. And it 
has to be cleared at the end of the program. In case of any error, output "n/a".==***

| Input | Output |
| ------ | ------ |
| 1<br>3 3<br>4 3 1<br>9 0 55<br>-4 7 -10 | -4 7 -10<br>4 3 1<br>9 0 55 |

***== Quest 7 received. Add an src/matrix_arithmetic.c program that performs one of 
the three operations: 1 – addition of two matrices, 2 – multiplication, or 
3 – transpose. The code of the respective operation must be input before 
inputting the dimensions and matrices. Matrices, as before, are integer-valued.
In case of any error, output "n/a". ==***

| Input | Output |
| ------ | ------ |
| 1<br/>2 2<br/>4 3<br/>9 0<br/>2 2<br/>1 1<br/>2 2 | 5 4<br/>11 2 |
| 2<br/>2 3<br/>4 3 1<br/>9 0 2<br/>3 1<br/>1<br/>2<br/>3 | 13<br/>15 |
| 3<br/>2 2<br/>4 3<br/>9 0 | 4 9<br/>3 0 |

***== Quest 8 received. Solve the task and save the result of the calculations in src/key10.txt. ==***