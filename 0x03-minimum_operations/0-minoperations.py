#!/usr/bin/python3
""" Module that holds min Operations
"""


def minOperations(n):
    """ Method that calculates the fewest number of operations
    needed to result in exactly n H characters in the file
    Args:
        n ([int]): [number of letters to search]
    Returns:
        [n]: [number of operations]
    """
    char_cnt = 2
    op_cnt = 2
    clipp = 1
    if n <= 1:
        return 0
    while char_cnt < n:
        if n % char_cnt == 0:
            clipp = char_cnt
            op_cnt += 1
        char_cnt += clipp
        op_cnt += 1
    return op_cnt
