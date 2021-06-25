#!/usr/bin/python3
"""
Module that holds a funtion
that validates UTF-8 encoding
"""


def validUTF8(data):
    """Funtion that cheks if the
    data is encode in UTF-8
    Args:
        data ([list]): List of the data to validate
    Returns:
        [Bool]: True if is valid UTF-8 otherwise False
    """
    bytes = 0
    for decimal in data:
        bin_num = format(decimal, '#010b')[-8:]
        if bytes == 0:
            for bit in bin_num:
                if bit == '0':
                    break
                bytes += 1
            if bytes == 0:
                continue
            if bytes == 1 or bytes > 4:
                return False
        else:
            if not (bin_num[0] == '1' and bin_num[1] == '0'):
                return False
        bytes -= 1
    return bytes == 0
