#!/usr/bin/python3
""" island_perimeter function """


def island_perimeter(grid):
    """  Function to find the perimeter of an island """

    def edges(matrix):
        """ detect number of edges  """
        c = 0
        for n in matrix:
            n = [0] + n + [0]
            for i in range(1, len(n)):
                c += n[i] != n[i-1]
        return c

    x = [[] for _ in range(len(grid[0]))]
    for n in grid:
        for i, item in enumerate(n):
            x[i].append(item)

    return edges(grid) + edges(x)
