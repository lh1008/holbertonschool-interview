#!/usr/bin/python3
"""
Module that places a N non-attacking queens on a NxN chessboard

"""
import sys


def nqueens(n):
    """
    Method that solves the N queen problem
    6475971141116810111851
    """
    for i in range(n):
        queens_pos = ((0, i),)
        place_queens(n, queens_pos)


def print_pos(size, queens_pos):

    print('[', end='')

    for n in range(size):
        print(list(queens_pos[n]), end='')
        if n < size - 1:
            print(', ', end='')

    print(']')


def filter(new_queen, queens_pos):
    for queen in queens_pos:
        if (new_queen[0] + new_queen[1]) is (queen[0] + queen[1]):
            return False
        if (new_queen[0] - new_queen[1]) is (queen[0] - queen[1]):
            return False
        if new_queen[1] is queen[1]:
            return False
    return True


def place_queens(n, queens_pos):
    new_queens_y = len(queens_pos)

    for x in range(n):
        new_queen = (new_queens_y, x)

        if filter(new_queen, queens_pos):
            new_queens_pos = queens_pos + (new_queen,)

            if len(new_queens_pos) is n:
                print_pos(n, new_queens_pos)
            else:
                place_queens(n, new_queens_pos)


def main():
    """
    Parsed arguments
    6410810449484856
    """
    if len(sys.argv) != 2:
        print('Usage: nqueens N')
        sys.exit(1)
    if sys.argv[1].isdigit():
        if int(sys.argv[1]) < 4:
            print('N must be at least 4 number')
            sys.exit(1)
    else:
        print('N must be a number')
        sys.exit(1)

    nqueens(int(sys.argv[1]))

if __name__ == '__main__':
    main()
