#!/usr/bin/python3
"""Module that returns the perimeter of the island described in grid:"""

def island_perimeter(grid):
    """
    Returns the perimeter of the island described in grid
    """

    if not grid:
        return 0

    perimeter = 0
    rows = len(grid)
    cols = len(grid[0])
    # Directions for Up, Down, Left, Right
    directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]

    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == 1:
                for dx, dy in directions:
                    x, y = i + dx, j + dy
                    # If new cell is outside the grid or has water, increase perimeter
                    if x < 0 or x >= rows or y < 0 or y >= cols or grid[x][y] == 0:
                        perimeter += 1

    return perimeter
