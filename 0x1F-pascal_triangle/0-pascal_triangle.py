#!/usr/bin/python3
"""Module holds function to solve Pascal triangle """


def pascal_triangle(n):
    """ Returns a list of lists of integers representing
        the Pascal’s triangle of n
    """
    triangle = []
    if n <= 0:
        return triangle
    for i in range(1, (n + 1)):
        sub = []
        for j in range(i):
            sub.append(1)
        triangle.append(sub)
    for i in range(len(triangle)):
        for j in range(i):
            if j != 0:
                triangle[i][j] = triangle[i - 1][j] + triangle[i - 1][j - 1]
    return triangle
