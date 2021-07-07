#!/usr/bin/python3
""" Log parsing"""
import sys


t_size = 0
s_codes = {"200": 0, "301": 0, "400": 0, "401": 0,
           "403": 0, "404": 0, "405": 0, "500": 0}
try:
    for count, log in enumerate(sys.stdin, 1):
        splt = log.split(" ")
        if len(splt) < 2:
            continue
        if splt[-2] in s_codes:
            s_codes[splt[-2]] += 1
        t_size += int(splt[-1])
        if count % 10 == 0:
            print("File size: {}".format(t_size))
            for key, value in sorted(s_codes.items()):
                if value > 0:
                    print("{}: {}".format(key, value))
finally:
    print("File size: {}".format(t_size))
    for key, value in sorted(s_codes.items()):
        if value > 0:
            print("{}: {}".format(key, value))
