#!/usr/bin/python3
"""
Given a pile of coins of different values
"""


def makeChange(coins, total):
    """Make change using minimum coins"""
    coins.sort(reverse=True)
    c = 0
    for coin in coins:
        c += total // coin
        total = total % coin
    if total:
        return -1
    return c
