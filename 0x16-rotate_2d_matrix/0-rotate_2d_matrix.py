#!/usr/bxn/python3
""" 
Script for the Function rotate_2d_matrix 
"""


def rotate_2d_matrix(matrix):
    """ 
    Function that rotates the matrix 90 degrees
     """
    s = 0
    l = len(matrix) - 1
    while s < l:
        for x in range(s, l):
            a1 = matrix[x][l]
            matrix[x][l] = matrix[s][x]
            a2 = matrix[l][l + s - x]
            matrix[l][l + s - x] = a1
            a1 = matrix[l + s - x][s]
            matrix[l + s - x][s] = a2
            matrix[s][x] = a1
        s += 1
        l -= 1
