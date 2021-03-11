#!/usr/bin/python3
""" Module that reads stdin line """

import fileinput
import sys


def main():
    """ Method that prints stdin line by line """
    output = []
    x = 0
    for line in sys.stdin:
        print(line.rstrip())
        words = line.split()
        output.append(words[-1])
        if len(output) == 10:
            print(output)


if __name__ == '__main__':
    main()
