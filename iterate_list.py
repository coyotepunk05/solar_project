def scan_readings():
    x_angles = range(0, 360, 10)  # 0, 10, 20, ..., 350
    y_angles = range(0, 100, 10)  # 0, 10, 20, ..., 90

    # Create an empty 2D array for z values
    z_values = [[0 for _ in y_angles] for _ in x_angles]

    for i, x in enumerate(x_angles):
        for j, y in enumerate(y_angles):
            # You would move motors to x and y here (if real setup)
            z = getReading()  # Your measurement
            z_values[i][j] = z  # Save to array

    return x_angles, y_angles, z_values


def find_max_spot(x_angles, y_angles, z_values):
    max_value = float('-inf')
    max_x = None
    max_y = None

    for i, x in enumerate(x_angles):
        for j, y in enumerate(y_angles):
            if z_values[i][j] > max_value:
                max_value = z_values[i][j]
                max_x = x
                max_y = y

    return max_x, max_y, max_value

