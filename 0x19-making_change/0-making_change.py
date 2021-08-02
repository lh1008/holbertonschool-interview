#!/usr/bin/python3
""" Module that determines the fewest number of coins """
import sys


def makeChange(coins, total):
    """
    Method that gets the coins
    needed to meet a given amount
    """
    nums = [float('inf') for x in range(total+1)]
    nums[0] = 0

    for coin in coins:
        for amount in range(len(nums)):
            if coin <= amount:
                nums[amount] = min(nums[amount], 1 + nums[amount - coin])

    return nums[total] if nums[total] != float('inf') else -1
