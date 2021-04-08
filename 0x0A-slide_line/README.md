# 0x0A. 2048 (single line)

### Tasks

_**0. Slide line**_
Write a function that slides and merges an array of integers.

The goal of this task is to reproduce the [2048 game](https://intranet.hbtn.io/rltoken/zbaecdLFfcqthH0X60M62g)(NSFW !!) mechanics on a single horizontal line.

### Instructions and Compilation

The files were compiled on `Ubuntu 20.0.4 LTS` using `gcc version 8.4.0` compiler with flags `-Wall` `-Werror` `-Wextra` and `-pedantic`.

All functions are included in `slide_line.h`.

Open your terminal window and locate yourself in a directory where you will download the files you're going to use to check the program yourself:

Download the following files by typing the following commands:

`$ wget -O 0-main.c https://raw.githubusercontent.com/lh1008/holbertonschool-interview/main/0x0A-slide_line/0-main.c`

`$ wget -O 0-slide_line.c https://raw.githubusercontent.com/lh1008/holbertonschool-interview/main/0x0A-slide_line/0-slide_line.c`

`$ wget -O slide_line.h https://raw.githubusercontent.com/lh1008/holbertonschool-interview/main/0x0A-slide_line/slide_line.h`

Compile using the following command:

`$ gcc -Wall -Wextra -Werror -pedantic -o 0-slide_line 0-main.c 0-slide_line.c`

A `0-slide_line` executable will be returned by the compiler. Execute the file with the following commands and see what is the output of every example:

Input:
`$ ./0-slide_line L 2 2 0 0`
Output:
```
Line: 2, 2, 0, 0
Slide to the left
Line: 4, 0, 0, 0
```
Input:
`$ ./0-slide_line R 2 2 2 2 2`
Output:
```
Line: 2, 2, 2, 2, 2
Slide to the right
Line: 0, 0, 2, 4, 4
```

Input:
`$ ./0-slide_line L 2 2 0 0 0 0 0 2 0 0 0 2 0 4`
Output:
```
Line: 2, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 4
Slide to the left
Line: 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
```

The `'L'` for `left` and the `'R'` for `right` will slide the number to the right or to the left. 