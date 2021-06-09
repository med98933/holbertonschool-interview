#!/usr/bin/python3
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
        for i in range(s, l):
            aux = matrix[i][l]
            matrix[i][l] = matrix[s][i]
            aux2 = matrix[l][l + s - i]
            matrix[l][l + s - i] = aux
            aux = matrix[l + s - i][s]
            matrix[l + s - i][s] = aux2
            matrix[s][i] = aux
        s += 1
        l -= 1
