// A buffer region is an area created around a geographic feature at a specified distance.
// For example, a 1 km buffer around a water point represents all areas located within 1 km of that water source.
// Buffers can be created around points, lines, or polygons and are commonly used in GIS for proximity and spatial analysis.

// Write a program that creates buffers of different sizes around a specific point coordinate and returns the points in a given set that lie within each buffer.


#include <iostream>
#include <vector>
#include <cmath>
#include <string>

// Structure to represent 2D coordinates
struct Point {
    std::string label;
    double x;
    double y;
};

// Function to calculate Euclidean distance between two points
double calculateDistance(const Point& p1, const Point& p2) {
    return std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
}

int main() {
    // 1. Define the central point feature (e.g., Water Source at origin)
    Point centerPoint = {"Central Point (Water Source)", 0.0, 0.0};

    // 2. Define a set of candidate points to check
    std::vector<Point> candidatePoints = {
        {"Point A", 0.5, 0.5},
        {"Point B", 1.0, 2.0},
        {"Point C", 3.0, 4.0},
        {"Point D", -0.8, 0.2},
        {"Point E", 5.0, 5.0}
    };

    // 3. Define buffer radii to evaluate (e.g., 1 km, 3 km, 5 km)
    std::vector<double> bufferRadii = {1.0, 3.0, 5.0};

    std::cout << "Center Point: " << centerPoint.label 
              << " at (" << centerPoint.x << ", " << centerPoint.y << ")\n\n";

    // 4. Process each buffer size
    for (double radius : bufferRadii) {
        std::cout << "========================================\n";
        std::cout << "Points within " << radius << " unit buffer:\n";
        std::cout << "========================================\n";

        bool foundAny = false;
        for (const auto& pt : candidatePoints) {
            double distance = calculateDistance(centerPoint, pt);
            if (distance <= radius) {
                std::cout << " - " << pt.label << " (" << pt.x << ", " << pt.y 
                          << ") | Distance: " << distance << "\n";
                foundAny = true;
            }
        }

        if (!foundAny) {
            std::cout << " No points lie within this buffer.\n";
        }
        std::cout << "\n";
    }

    return 0;
}
