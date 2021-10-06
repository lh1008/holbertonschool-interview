#!/usr/bin/python3
""" Module for a Prime Game """


def isWinner(x, nums):
    """
    Method to play the Prime round game
    """
    print(x)

    # itirate a list
    for i in nums:
        if i > 1:
            for j in range(2, i):
                if (i % j) == 0:
                    print(i, "is not a prime number")
                    print(j, "times", i//j, "is", i)
                    break
            else:
                print(i, "is a prime number")
        else:
            print(i)

# https://www.tutorialspoint.com/prime-or-not-in-python
