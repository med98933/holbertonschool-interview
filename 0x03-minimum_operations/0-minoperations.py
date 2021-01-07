#!/usr/bin/python3
"""
  mini operations(n)
"""


def minOperations(n):
    """method that calculates the fewest number of operations    """
    c = 0
    op = 2
    while n >= 2:
        while not n % op:
            c += op
            n /= op
            n = int(n)
        op += 1
    return c
