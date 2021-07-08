#!/usr/bin/python3
""" Module that rotates a 2D matrix """


def rotate_2d_matrix(matrix):
    """
    Method that rotates a 2D matrix 90 degrees clockwise
    Args:
        matrix (list[[list]]): a matrix
    """
    temp_matrix = []
    column = len(matrix)-1
    for column in range(len(matrix)):
        temp = []
        for row in range(len(matrix)-1,-1,-1):
            temp.append(matrix[row][column])
        temp_matrix.append(temp)
    for i in range(len(matrix)):
        for j in range(len(matrix)):
            matrix[i][j] = temp_matrix[i][j]
