#!/usr/bin/python3
""" Module that places a N non-attacking queens on a NxN chessboard """
import sys

def main():
    """ Method that solves the N queen problem """
    if len(sys.argv) == 2:
        if sys.argv[1].isdigit():
            print(sys.argv[1])
            if int(sys.argv[1]) < 4:
                print('N must be at least 4 number')
        else:
            print('N must be a number')

        for eachArg in sys.argv:
            print('Argument {}'.format(eachArg))
    else:
        print('Usage: nqueens N\n')
        sys.exit(1)

if __name__ == '__main__':
    main()
