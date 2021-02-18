#!/usr/bin/python3
"""
a method that determines if a given data set represents a valid UTF-8 encoding
"""


def validUTF8(data):
    """
    A function that:
    converts an integer to its binary representation
    """
    a = 0
    for i, num in enumerate(data):
        byte = num & 0xFF
        if a:
            if byte >> 6 != 2:
                return False
            a = a - 1
            continue
        while (1 << abs(7 - a)) & byte:
            a = a + 1
        if a == 1 or a > 4:
            return False
        a = max(a - 1, 0)
    return a == 0
