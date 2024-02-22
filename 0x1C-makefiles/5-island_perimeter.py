#!/usr/bin/python3

"""Function calculates the perimeter of an island of square blocks"""


def island_perimeter(grid):
    """Returns the perimeter of the island described in grid
        grid is a list of list of integers
        0 represents a water zone
        1 represents a land zone
        One cell is a square with side length 1.

    Args:
        grid (list): list of lists representing a rectangular block.

    Returns:
        perimeter of the connected land.
    """

    x = len(grid[0])
    y = len(grid)
    perim = 0
    for i in range(y-2):
        for j in range(x-2):
            if grid[i+1][j+1] == 1:
                zeros = (4 - (grid[i][j+1] + grid[i+2][j+1]
                         + grid[i+1][j] + grid[i+1][j+2]))
                perim += zeros
    return perim
