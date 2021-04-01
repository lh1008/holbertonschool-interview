# 0x09. UTF-8 Validation

### Tasks

_**0. UTF-8 Validation**_
Write a method that determines if a given data set represents a valid UTF-8 encoding.

### Instructions and Build

All the files were interpreted and compiled using Ubuntu 20.04 LTS using `python3`.

Download `0-main.py` and `0-validate_utf8.py` files in your machine. Locate yourselves where the files are located with your terminal.

Change your files permissions.

`$ chmod u+x 0-main.py 0-validate_utf8.py`

Execute the program:

`$ ./0-main.py`

You should have this return:

```
True
True
False
```

Open the `0-main.py` file and check what is being sent to `0-validate_utf8.py` -> `def validUTF8(data)` method (function).

First two list of encoded lists are in the range of `0` to `255`. The last string has `256`, being one number ahead of `255`. The basic Latin-1 Unicode goes up to `255`. If there is a number above of `255` the program returns `False` or `True` if the list of Unicode numbers are below or equal to `255`.