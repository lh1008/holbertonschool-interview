# 0x0E. Linear search in skip list

### Task

_**0. Linear search in a skip list**_
Write a function that searches for a value in a sorted skip list of integers.

#### Files

- `0-main.c`
- `search.h`
- `0-linear_skip.c`

From [0x0E. Linear search in skip list](https://github.com/holbertonschool/0x0E.Linear_search-in_skip_list) repository.

- `create_skiplist.c`
- `free_skiplist.c`
- `print_skiplist.c`

### Instructions and Compilation

The files were compiled on `Ubuntu 20.0.4 LTS` using `gcc version 8.4.0` compiler with flags `-Wall` `-Werror` `-Wextra` and `-pedantic`.

All functions are included in `search.h`.

Open your terminal window and locate yourself in a directory where you will download the files you're going to use to check the program yourself:

Download the following files by typing the following commands:

`$ wget -O 0-main.c `

`$ wget -O search.h`

`$ wget -O 0-linear_skip.c`

`$ wget -O create_skiplist.c https://raw.githubusercontent.com/holbertonschool/0x0E.Linear_search-in_skip_list/main/create_skiplist.c`

`$ wget -O free_skiplist.c https://raw.githubusercontent.com/holbertonschool/0x0E.Linear_search-in_skip_list/main/free_skiplist.c`

`$ wget -O print_skiplist.c https://raw.githubusercontent.com/holbertonschool/0x0E.Linear_search-in_skip_list/main/print_skiplist.c`

Compile using the following command:

`$ gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-linear_skip.c skiplist/*.c -lm -o 0-linear_skip`

Execute the program:

`$ ./0-linear_skip`