#!/usr/bin/python3
"""Rain"""


def rain(walls):
    """calculate how much water will be retained after it rains"""
    if not walls or len(walls) < 3:
        return 0
    n_walls = 0
    for x in range(1, len(walls) - 1):
        left_border = max(walls[:x])
        right_border = max(walls[x + 1:])
        min_border = min(left_border, right_border)
        if walls[x] < min_border:
            n_walls += min_border - walls[x]
    return n_walls
