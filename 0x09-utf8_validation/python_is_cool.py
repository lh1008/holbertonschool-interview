#!/usr/bin/python3
""" Module to determine whether a given data is valid UTF-8 """


def validUTF8(data):
    """
    Method that determines given a set of data
    represents a valid UTF-8 encoding and returns
    True: if data is a valid UTF-8 enconding
    False: if not
    """

    for item in data:
        if item < 256:
            # print(chr(item).encode('utf-8'))
            print(chr(item))
        elif item > 255:
            return False
