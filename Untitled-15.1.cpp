#include <iostream>
#include <cmath>
using namespace std;

// ===== Point =====
class Point {
public:
    double x, y;

    Point(double x = 0, double y = 0) {
        this->x = x;
        this->y = y;
    }
};

// ===== Rectangle =====
class Rectangle {
public:
    Point p1; // góc dưới trái
    Point p2; // góc trên phải

    Rectangle(Point a, Point b) {
        p1 = a;
        p2 = b;
    }
};

// ===== Circle =====
class Circle {
public:
    Point center;
    double radius;

    Circle(Point c, double r) {
        center = c;
        radius = r;
    }
};


// ===== kiểm tra khoảng cách =====
double distance(Point a, Point b) {
    return sqrt((a.x - b.x)*(a.x - b.x) +
                (a.y - b.y)*(a.y - b.y));
}


// ===== point_in_circle =====
bool point_in_circle(Circle c, Point p) {
    return distance(c.center, p) <= c.radius;
}


// ===== rect_in_circle =====
bool rect_in_circle(Circle c, Rectangle r) {

    Point a = r.p1;
    Point b = Point(r.p2.x, r.p1.y);
    Point d = Point(r.p1.x, r.p2.y);
    Point c2 = r.p2;

    return point_in_circle(c, a) &&
           point_in_circle(c, b) &&
           point_in_circle(c, c2) &&
           point_in_circle(c, d);
}


// ===== rect_circle_overlap =====
bool rect_circle_overlap(Circle c, Rectangle r) {

    Point a = r.p1;
    Point b = Point(r.p2.x, r.p1.y);
    Point d = Point(r.p1.x, r.p2.y);
    Point c2 = r.p2;

    return point_in_circle(c, a) ||
           point_in_circle(c, b) ||
           point_in_circle(c, c2) ||
           point_in_circle(c, d);
}


// ===== main =====
int main() {

    Circle circle(Point(150, 100), 75);

    Point p(160, 100);

    if (point_in_circle(circle, p))
        cout << "Point in circle\n";
    else
        cout << "Point outside\n";


    Rectangle rect(Point(140, 90), Point(170, 120));

    if (rect_in_circle(circle, rect))
        cout << "Rectangle in circle\n";
    else
        cout << "Rectangle not fully in circle\n";


    if (rect_circle_overlap(circle, rect))
        cout << "Rectangle overlap circle\n";
    else
        cout << "No overlap\n";

    return 0;
}