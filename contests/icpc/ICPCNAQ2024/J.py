def is_point_in_menger_sponge(level, x, y, z):
    size = 3 ** level
    
    # Check if the point is within the bounds of the Menger sponge
    if not (0 <= x < size and 0 <= y < size and 0 <= z < size):
        return 0

    # Iteratively check for presence in the sponge structure
    while level > 0:
        if (x % 3 == 1) and (y % 3 == 1) and (z % 3 == 1):
            return 0  # Inside a deleted cube
        x //= 3
        y //= 3
        z //= 3
        level -= 1

    return 1  # Point is in the sponge

# Read input
n, x1, y1, z1, x2, y2, z2 = map(int, input().split())

# Calculate the actual coordinates
x = x1 * (3**n) // x2
y = y1 * (3**n) // y2
z = z1 * (3**n) // z2

# Check if the point is in the Menger sponge
result = is_point_in_menger_sponge(n, x, y, z)

# Output the result
print(result)
