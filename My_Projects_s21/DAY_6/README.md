***== Quest 1 received. Create an src/sort.c program that expects an stdin array with the length of 10 integers for input and outputs the same array sorted in ascending order. Arrange the functions of reading, sorting and output of the array separately. You can use any sorting algorithm. Using stdlib.h is not allowed. Passing an array to a function only by pointer. For errors, display "n/a". ==***

| Input | Output |
| ------ | ------ |
| 4 3 9 0 1 2 100 2 7 -1 | -1 0 1 2 2 3 4 7 9 100 |

***== Quest 2 received. Create an src/fast_sort.c program that sorts an array of 10 integer elements in ascending order using two different sorting algorithms with theoretical estimates of computational complexity no higher than nlog(n) (e.g. quicksort and heapsort). In the first line of stdout, output the array sorted by the first algorithm; in the second line–by the second algorithm. You are not allowed to use stdlib.h or third-party libraries. Follow the principles of structured programming. Passing an array to a function only by pointer. For errors, display "n/a". ==***

| Input | Output |
| ------ | ------ |
| 4 3 9 0 1 2 100 2 7 -1 | -1 0 1 2 2 3 4 7 9 100<br/>-1 0 1 2 2 3 4 7 9 100 |

***== Quest 3 received. Modify the src/key9part1.c program so it can receive the array's length and an array of integers. The program should output in stdout the sum of the even elements of the array and the newly formed array from the elements of the old one, by which the previously calculated sum is divided evenly. Decreasing the decomposition is not allowed–you can add functions if needed, but you cannot delete them. Using stdlib.h is not allowed. Passing an array to a function only by pointer. The maximum size of the input array is 10. In case of an error or the absence of even elements, display "n/a". ==***

Note: zero is considered an odd number.

| Input | Output |
| ------ | ------ |
| 10<br/>4 3 9 0 1 2 0 2 7 -1 | 8<br/>4 1 2 2 -1 |

***== Quest 4 received. Create an src/cycle_shift.c program that receives a number `n`, an array `A` with `n` integers, and a number `c` by which all elements of the array must rotate to the left. If the value of `c` is negative, the shift in the array must occur to the right. A modified array is expected as output. Stick to the recommended decomposition, like in the previous quests. Using stdlib.h is not allowed. Passing an array to a function only by pointer. The maximum size of the input array is 10. For errors, display "n/a". ==***

| Input | Output |
| ------ | ------ |
| 10<br/>4 3 9 0 1 2 0 2 7 -1<br/>2 | 9 0 1 2 0 2 7 -1 4 3 |

***== Quest 5 received. Modify the src/key9part2.c program so it returns the result of addition and subtraction of two very large numbers that were passed to the program as input in the form of arrays. Maximum number length: 100 elements of type int. The integers you enter are decimal digits. If the subtrahend is higher than the minuend, "n/a" must be displayed instead of the difference. Stick to the decomposition, like in the previous quests. Using stdlib.h is not allowed. Passing an array to a function only by pointer. For errors, display "n/a". ==***

| Input | Output |
| ------ | ------ |
| 1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 6 1<br/>2 9 | 1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 9 0<br/>1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 3 2 |
| 0 1 0<br/>0 0 1 | 1 1<br/>9 |