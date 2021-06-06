#!/usr/bin/python3
"""  N queens"""
import sys


def valid_line(s, line):
    """
    checks if we can insert queen
    """
    for x in s:
        if x[1] == line[1]:
            return False
        if (x[0] + x[1]) == (line[0] + line[1]):
            return False
        if (x[0] - x[1]) == (line[0] - line[1]):
            return False
    return True


def solve_xs(r, n, s):
    """
    fills each lin
    """
    if (r == n):
        print(s)
    else:
        for col in range(n):
            line = [r, col]
            if valid_line(s, line):
                s.append(line)
                solve_xs(r + 1, n, s)
                s.remove(line)


def main(n):

    s = []
    solve_xs(0, n, s)


if __name__ == '__main__':

    if len(sys.argv) != 2:
        print('Usage: nxs N')
        sys.exit(1)
    try:
        i = int(sys.argv[1])
    except BaseException:
        print('N must be a number')
        sys.exit(1)
    i = int(sys.argv[1])
    if i < 4:
        print('N must be at least 4')
        sys.exit(1)
    main(i)
