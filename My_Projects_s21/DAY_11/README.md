***== Quest 1 received. Create door structure in src/door_struct.h. 
The structure itself consists of an integer door id and an integer status 
(0 – closed, 1 – open). Correct the src/dmanager_module.c program so it 
sorts the initialized array of doors in ascending order by ids using any algorithm 
and displays it in the following format: "door id, door status". 
In addition to that, set the status "closed" for all doors. Changing the 
door initialization function is not allowed. Stick to the structured approach. 
The program should be built using a Makefile. Stage name: door_struct. The 
executable file should be located in the build folder at the root of the 
repository. It should be named Quest_1. The solution will be checked for memory 
leaks and for the style norm, instructions as usual-in `materials` ==***

0, 0<br/>
1, 0<br/>
2, 0<br/>
3, 0<br/>
4, 0<br/>
5, 0<br/>
6, 0<br/>
7, 0<br/>
8, 0<br/>
9, 0<br/>
10, 0<br/>
11, 0<br/>
12, 0<br/>
13, 0<br/>
14, 0<br/>

***== Quest 2 received. Develop an src/list.c program which contains implementations of functions for working
with a singly linked list of doors (`struct node* init(struct door* door)` - initialization of the singly linked list structure based on the passed `struct door`, `struct node* add_door(struct node* elem, struct door* door)` - inserting a new `struct door` element into a singly linked list after the passed `elem` node, `struct node* find_door(int door_id, struct node* root)` - search for a door in the list by its id, `struct node* remove_door(struct node* elem, struct node* root)` - deleting a list element, `void destroy(struct node* root)` - freeing the memory occupied by the list structure). Move the declarations of these functions and the structure of the singly linked list to the file src/list.h. Write module tests for checking 
the add_door and remove_door functions of the singly linked list in src/list_test.c. Method functions 
should return SUCCESS if the test is successful and FAIL if there is an error. 
The tests should be built using a Makefile. Stage name: list_test. 
The executable file should be located in the build folder at the root of 
the repository. It should be named Quest_2.
Please note: this quest will be tested by the `cppcheck` utility.==***

***== Quest 3 received. Develop an src/stack.c program which contains 
implementations of functions for working with a dynamic stack (init, push, 
pop, destroy). Put declarations of functions and structures of the dynamic 
stack that stores integers in src/stack.h. Write module tests for checking 
the push and pop functions of the stack in src/stack_test.c. Method functions 
should return SUCCESS if the test is successful and FAIL if there is an error. 
The tests should be built using a Makefile. Stage name: stack_test. 
The executable file should be located in the build folder at the root of 
the repository. It should be named Quest_3.
Please note: this quest will be tested by the `cppcheck` utility. ==***
