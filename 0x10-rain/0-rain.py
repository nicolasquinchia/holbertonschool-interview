#!/usr/bin/python3
""" Module containing the rain task,
    Calculate how many square units of water
    will be retained after it rains on a relief map
"""


def rain(walls):
    """ Calculate how much water will be retained after it rains

    Args:
        walls: list of non-negative integers

    Returns:
        Integer indicating total amount of rainwater retained
    """

    distance = len(walls)
    if distance == 0:
        return 0
    water_limit = 0
    for index in range(1, distance - 1):
        wall_left = walls[index]
        for x in range(index):
            wall_left = max(wall_left, walls[x])

        wall_right = walls[index]
        for x in range(index + 1, distance):
            wall_right = max(wall_right, walls[x])
        water_limit = water_limit + min(wall_left, wall_right) - walls[index]
    return water_limit
