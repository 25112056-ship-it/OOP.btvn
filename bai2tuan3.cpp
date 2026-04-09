#include <iostream>
#include <cmath>
using namespace std;

// ===== POINT =====
class Point {
public:
    double x, y;

    Point(double x = 0, double y = 0) {
        this->x = x;
        this->y = y;
    }
};

// ===== CIRCLE =====
class Circle {
public:
    Point center;
    double radius;

    Circle(Point c, double r) {
        center = c;
        radius = r;
    }
};

// ===== RECTANGLE =====
class Rectangle {
public:
    double x, y; // góc dưới bên trái
    double width, height;

    Rectangle(double x, double y, double w, double h) {
        this->x = x;
        this->y = y;
        width = w;
        height = h;
    }
};

// ===== HÀM TÍNH KHOẢNG CÁCH =====
double distance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

// ===== 1. POINT IN CIRCLE =====
bool point_in_circle(Circle c, Point p) {
    return distance(c.center, p) <= c.radius;
}

// ===== 2. RECT IN CIRCLE =====
bool rect_in_circle(Circle c, Rectangle r) {
    // 4 góc của hình chữ nhật
    Point p1(r.x, r.y);
    Point p2(r.x + r.width, r.y);
    Point p3(r.x, r.y + r.height);
    Point p4(r.x + r.width, r.y + r.height);

    return point_in_circle(c, p1) &&
           point_in_circle(c, p2) &&
           point_in_circle(c, p3) &&
           point_in_circle(c, p4);
}

// ===== 3. RECT CIRCLE OVERLAP =====
bool rect_circle_overlap(Circle c, Rectangle r) {
    // chỉ cần 1 góc nằm trong là true
    Point p1(r.x, r.y);
    Point p2(r.x + r.width, r.y);
    Point p3(r.x, r.y + r.height);
    Point p4(r.x + r.width, r.y + r.height);

    return point_in_circle(c, p1) ||
           point_in_circle(c, p2) ||
           point_in_circle(c, p3) ||
           point_in_circle(c, p4);
}

// ===== MAIN =====
int main() {
    Circle c(Point(150, 100), 75);

    Point p(160, 110);
    Rectangle r(140, 90, 20, 20);

    cout << "Point in circle: " << point_in_circle(c, p) << endl;
    cout << "Rect in circle: " << rect_in_circle(c, r) << endl;
    cout << "Rect overlap: " << rect_circle_overlap(c, r) << endl;

    return 0;
}