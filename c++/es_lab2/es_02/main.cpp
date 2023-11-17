#include <iostream>
#include <cmath>

//Point type (struct has default public interface)
struct Point {
    //Coordinates
    double x, y;
};

//Overload of the << operator in order to print the point without printing explicitly its coordinates
std::ostream &operator<<(std::ostream &stream, const Point &p) {
    stream << "(" << p.x << "; " << p.y << ")";

    return stream;
}

//Overload of the >> operator in order to get the point without getting explicitly its coordinates
std::istream &operator>>(std::istream &stream, Point &p) {
    stream >> p.x >> p.y;

    return stream;
}

//Circle type (struct has default public interface)
struct Circle {
    //Center coordinates
    Point center;
    //Radius value
    double rad;

    /*
    Method that check if a point p is inside the circle
    const Point &p means:
        1) const -> the method does not change the value of p;
        2) & -> the point is not passed by value (is not copied) but passed by reference.

    The method is declared as const because it does not change the attributes
    */
    bool isPointInside(const Point &p) const {
        //Computing the euclidean distance (with pitagora's theoreme) between the point and
        //the center of the circle
        double dist = std::sqrt(std::pow(center.x - p.x, 2) + std::pow(center.y - p.y, 2));

        //If the distance is less or equals than the radius than the point is inside the circle
        return dist <= rad;
    }
};

//Overload of the << operator in order to print the circle without printing explicitly its attributes
std::ostream &operator<<(std::ostream &stream, const Circle &c) {
    stream << "{Center point: " <<  c.center << " | Radius: " << c.rad << "}";

    return stream;
}

//Overload of the >> operator in order to get the circle without getting explicitly its attributes
std::istream &operator>>(std::istream &stream, Circle &c) {
    stream >> c.center >> c.rad;

    return stream;
}

int main() {
    Point p;
    Circle c;

    //Getting the point data from the user
    std::cout << "Enter the point coordinates:\n";
    std::cin >> p;

    //Getting the circle data from the user
    std::cout << "Enter the circle (center coordinates and radius):\n";
    std::cin >> c;

    //Checking the value of the radius
    if(c.rad < 0) {
        //Printing the error
        std::cout << "\nError: The value of the radius must be positive!\n";
    } else {
        //Checking if the point is inside the circle and printing the results
        if(c.isPointInside(p)) {
            std::cout << "The point " << p << " is inside the circle " << c << "\n";
        } else {
            std::cout << "The point " << p << " is NOT inside the circle " << c << "\n";
        }
    }

    return EXIT_SUCCESS;
}