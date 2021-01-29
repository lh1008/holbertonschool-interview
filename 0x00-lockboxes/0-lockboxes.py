#!/usr/bin/python3
""" Module that checks locked boxes """


def canUnlockAll(boxes):
    """ Method that determines if all boxes can be opened """

    l = len(boxes)

    check = [0]
    list_ing = [i for i in range(l)]


    for it_1 in check:
        for it_2 in boxes[it_1]:
            if it_2 not in check and it_2 in list_ing:
                if it_2 >= l:
                    return False
                check.append(it_2)

    if len(check) == l:
        return True
    else:
        return False
