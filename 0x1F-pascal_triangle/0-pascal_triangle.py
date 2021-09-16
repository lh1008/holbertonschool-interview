#!/usr/bin/python3
"""
Module for Pascal's Triangle
"""
from math import factorial


def pascal_triangle(n):
    """
    Method that returns a list of lists
    of integers representing the Pascal's
    triangle of n
    """
    if n <= 0:
        return []

    t = [[1]]
    for j in range(1, n):
        t.append([])

        for mv in range(j + 1):

            if mv == 0 or mv == j:
                t[j].append(1)

            else:
                t[j].append(t[j - 1][mv - 1] + t[j - 1][mv])
    return t
