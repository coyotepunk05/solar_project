#include <vector>
#include <limits>

using namespace std;

// Function to simulate reading
float getReading() {
    // Replace with your actual sensor reading code
    return random(0, 1000) / 10.0;  // Example: random float between 0.0 and 100.0
}

// Scan readings over X and Y angles
void scan_readings(vector<int>& x_angles, vector<int>& y_angles, vector<vector<float>>& z_values) {
    // Fill x_angles (0 to 350 step 10)
    for (int x = 0; x < 360; x += 10) {
        x_angles.push_back(x);
    }
    
    // Fill y_angles (0 to 90 step 10)
    for (int y = 0; y <= 90; y += 10) {
        y_angles.push_back(y);
    }

    // Resize z_values 2D array
    z_values.resize(x_angles.size(), vector<float>(y_angles.size(), 0.0));

    // Take readings
    for (size_t i = 0; i < x_angles.size(); ++i) {
        for (size_t j = 0; j < y_angles.size(); ++j) {
            // Move motors to (x, y) here if needed

            float z = getReading();  // Get sensor reading
            z_values[i][j] = z;       // Save to array
        }
    }
}

// Find maximum spot in Z array
void find_max_spot(const vector<int>& x_angles, const vector<int>& y_angles, const vector<vector<float>>& z_values,
                   int& max_x, int& max_y, float& max_value) {
    max_value = -numeric_limits<float>::infinity();
    max_x = 0;
    max_y = 0;

    for (size_t i = 0; i < x_angles.size(); ++i) {
        for (size_t j = 0; j < y_angles.size(); ++j) {
            if (z_values[i][j] > max_value) {
                max_value = z_values[i][j];
                max_x = x_angles[i];
                max_y = y_angles[j];
            }
        }
    }
}
