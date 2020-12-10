#!/usr/bin/python3
"""
task 0
"""


def canUnlockAll(boxes):
    """number of locked boxes"""
    for i in range(1, len(boxes) - 1):
        c = False
        for x in range(len(boxes)):
            c = (i in boxes[x] and i != x)
            if c:
                break
        if c is False:
            return c
    return True
