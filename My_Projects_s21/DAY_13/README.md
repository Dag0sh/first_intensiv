***== Quest 1 received. Create an src/cipher.c program. Add a console menu to the program and implement its first
item – specifying the path to the text file via stdin, to open, read, and output it to the console. If the file
is empty or does not exist or any other error, then output "n/a". If -1 is applied to the input, the program should exit. After executing each menu item, except -1, there should be a new line. Build the project using the Makefile. Stage name: cipher.
Executable file name: cipher. The executable file must be located in the root of the repository in the
build folder. It is forbidden to use d_namlen from the dirent.h library. ==***

| Input | Output | File|
| ------ | ------ | ------|
| 1<br>text.txt<br/>-1 | Aloha!<br/> | Aloha! |
| 1<br>abc.txt<br/>1<br/>abc.txt<br/>-1 | Hihi_haha<br/><br/>Hihi_haha<br/><br/> | Hihi_haha`\n` |
| 1<br>doesnt_exist.t_x_t<br/>1<br/>love.txt<br/>-1 | n/a<br/>i_love_sh21<br/> | i_love_sh21 |

***== Quest 2 received. Supplement the src/cipher.c program. Add menu item 2 – receiving an arbitrary line of text from the console and writing it to the end of the file uploaded in step 1. Output the contents of the file to the console. If the file
is empty or does not exist or any other error, then output "n/a". If -1 is applied to the input, the program should exit. After executing each menu item, except -1, there should be a new line. Build the project using the Makefile. Stage name: cipher. Executable file name: cipher. The executable file must be located in the root of the repository in the
build folder. It is forbidden to use d_namlen from the dirent.h library. ==***

| Input | Output| File |
| ------ | ------ | ----- |
| 1<br/>test.txt<br/>2<br/>Bek the great<br/>-1 | I_love<br/><br/>I_love<br/>Bek the great<br/> | I_love`\n` |
| 2<br/>Bek the great<br/>-1 | n/a<br/> |  |
| 1<br/>doesnt_exist.txt<br/>2<br/>Wow<br/>-1|n/a<br/>n/a<br/>| ~~doesnt_exist~~ |
| 1<br/>aboba.txt<br/>2<br/>hi<br/>-1|n/a<br/>hi<br/>| ~~empty~~ |

***== Quest 3 received. Supplement the src/cipher.c program. Add item 3 to the menu – encryption of all .c files using a Caesar cipher and clearing all .h files from the specified directory. The shift for a Caesar cipher is also set as a parameter via the console. Save all modified files and src/cipher.c in the repository, replacing the original ones. Build the project using the Makefile. Stage name: cipher. Executable file name: cipher. The executable file must be located in the root of the repository in the
build folder. It is forbidden to use d_namlen from the dirent.h library. ==***

***== Quest 4 received. Supplement the src/cipher.c program. Add item 4 to the menu – encryption of all .c files using the DES algorithm and clearing all .h files from the specified directory. Build the project using the Makefile. Stage name: cipher. Executable file name: cipher. The executable file must be located in the root of the repository in the
build folder. It is forbidden to use d_namlen from the dirent.h library. ==***

***== Quest 5 received. Create src/logger.c and src/logger.h files to implement the logger. Add log_init, logcat, and log_close functions to the files for creating a log file with the given name, writing the transmitted message in the created log file, and closing the log accordingly. Message format: an indication of the logging level (DEBUG, INFO, WARNING, ERROR), time, and the actual message. \
Supplement the src/cipher.c program by connecting it to the created logger which writes the main actions of the program in the file (File 'aaa.c' open; String wrote in the 'bbb.h' file, and so on). Build the project using the Makefile. Stage name: logging_cipher. Executable file name: logging_cipher. The executable file must be located in the root of the repository in the
build folder. It is forbidden to use d_namlen from the dirent.h library. ==***
