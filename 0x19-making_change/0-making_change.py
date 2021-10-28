#!/usr/bin/python3
"""Module that holds function
makeChange for interview task
"""


def makeChange(coins, total):
    """Given a pile of coins of different values,
        determine the fewest number of coins needed
        to meet a given amount total

    Args:
        coins ([list]): Pile of Coins
        total ([int]): Total Value

    Returns:
        [int]: Number of coins to reach the total value
    """

    amount = 0
    totalcoins = 0
    if total <= 0:
        return 0
    while (amount < total):
        if not coins:
            return -1
        if max(coins) < total:
            amount += max(coins)
            totalcoins += 1
        else:
            coins.remove(max(coins))
    return totalcoins
