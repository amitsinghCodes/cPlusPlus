#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

enum Level {
    LOW = 5,
    MEDIUM, // Now 6
    HIGH // Now 7
  };

enum Color { RED, GREEN, BLUE };

int main() {
    Point p1 = {1, 2};
    Point p2 = {3, 4};

    cout << "Point 1: (" << p1.x << ", " << p1.y << ")\n";
    cout << "Point 2: (" << p2.x << ", " << p2.y << ")\n";

    Color c = BLUE;
    cout << "Color: " << c << "\n";

    return 0;
}