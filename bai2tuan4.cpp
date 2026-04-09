#include <iostream>
using namespace std;

// ===================== LỚP POINT =====================
class Point {
private:
    int x, y;

public:
    // Constructor mặc định & có tham số
    Point(int x = 0, int y = 0) {
        this->x = x;
        this->y = y;
    }

    // Copy constructor
    Point(const Point& p) {
        x = p.x;
        y = p.y;
    }

    // Getter
    int getX() const { return x; }
    int getY() const { return y; }
};

// ===================== LỚP LINESEGMENT =====================
class LineSegment {
private:
    Point d1, d2;

public:
    // 1. Constructor mặc định
    LineSegment() {
        d1 = Point(8, 5);
        d2 = Point(1, 0);
    }

    // 2. Constructor với 2 Point (KHÔNG tạo thêm điểm mới)
    LineSegment(Point d1, Point d2) {
        this->d1 = d1;
        this->d2 = d2;
    }

    // 3. Constructor với 4 số nguyên
    LineSegment(int x1, int y1, int x2, int y2) {
        d1 = Point(x1, y1);
        d2 = Point(x2, y2);
    }

    // 4. Copy constructor (SAO CHÉP SÂU)
    LineSegment(const LineSegment& s) {
        d1 = Point(s.d1);
        d2 = Point(s.d2);
    }

    // Hàm hiển thị
    void display() const {
        cout << "d1: (" << d1.getX() << ", " << d1.getY() << ")\n";
        cout << "d2: (" << d2.getX() << ", " << d2.getY() << ")\n";
        cout << "------------------------\n";
    }
};

// ===================== HÀM MAIN =====================
int main() {
    // Constructor mặc định
    LineSegment a;

    // Constructor 4 số nguyên
    LineSegment b(1, 2, 3, 4);

    // Constructor với 2 Point
    Point p1(5, 6), p2(7, 8);
    LineSegment c(p1, p2);

    // Copy constructor
    LineSegment d(c);

    // Hiển thị kết quả
    cout << "Doan thang a:\n";
    a.display();

    cout << "Doan thang b:\n";
    b.display();

    cout << "Doan thang c:\n";
    c.display();

    cout << "Doan thang d (copy tu c):\n";
    d.display();

    return 0;
}