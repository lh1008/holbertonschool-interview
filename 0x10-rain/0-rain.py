#!/usr/bin/python3
""" Module for rain method that retains rain """


def rain(walls):
    """
    Method to calculate how many square units of
    water will be retained after it rains.
    """

    if (walls == 0):
        return 0

    res = 0
    n = len(walls)

    for i in range(1, n-1):
        left = walls[i]

        for j in range(i):
            left = max(left, walls[j])

        right = walls[i]

        for j in range(i+1, n):
            right = max(right, walls[j])

        res = res + (min(left, right) - walls[i])

    return res
