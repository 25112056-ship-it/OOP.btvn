#include <iostream>
#include <cmath>
using namespace std;

class Point {
public:
    int x, y;

    Point(int x = 0, int y = 0) {
        this->x = x;
        this->y = y;
    }

    void nhap() {
        cin >> x >> y;
    }

    void xuat() {
        cout << "(" << x << ", " << y << ")" << endl;
    }

    // khoảng cách tới O
    double distanceToO() {
        return sqrt(x*x + y*y);
    }

    // khoảng cách tới điểm khác
    double distanceTo(Point p) {
        return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
    }

    // đối xứng qua O
    Point doiXung() {
        return Point(-x, -y);
    }
};

int main() {
    Point A(3,4);
    cout << "Diem A: "; A.xuat();

    Point B;
    cout << "Nhap diem B: ";
    B.nhap();

    Point C = B.doiXung();
    cout << "Diem C doi xung B qua O: ";
    C.xuat();

    cout << "Khoang cach B -> O: " << B.distanceToO() << endl;
    cout << "Khoang cach A -> B: " << A.distanceTo(B) << endl;

    return 0;
}