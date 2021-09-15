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
    t = [[1]]
    for j in range(1, n):
        prev = t[-1]
        t.append([1] + [prev[i]+prev[i+1] for i in range(len(prev)-1)] + [1])
    return t
