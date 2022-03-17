#!/usr/bin/python3
'''
Pascal triangle module
'''


def pascal_triangle(n):
    ''' Represent Pascal's '''
    pascal_list = []
    if n <= 0:
        return pascal_list
    for i in range(n):
        c = [1]
        if pascal_list:
            prev = pascal_list[-1]
            c.extend([sum(pair) for pair in zip(prev, prev[1:])])
            c.append(1)
        pascal_list.append(c)
    return (pascal_list)
