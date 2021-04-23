#!/usr/bin/python3
"""
    Holds funtion to unlock
    all boxes
"""


def canUnlockAll(boxes):
    """Method to know if all boxes can
    be unlocked
    Args:
        boxes ([list]): List of list with the boxes
        and the keys inside of each one
    Returns:
        [Bool]: True if all boxes are unlocked
        otherwise False
    """
    if not boxes or len(boxes) == 0:
        return True
    boxes_keys = [0]
    for box in boxes_keys:
        for keys_in_box in boxes[box]:
            if keys_in_box not in boxes_keys:
                if keys_in_box < len(boxes):
                    boxes_keys.append(keys_in_box)
    return len(boxes_keys) == len(boxes)
