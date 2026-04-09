#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ================= EXCEPTION =================
class MauSoBangKhong : public exception {
public:
    const char* what() const noexcept override {
        return "Mau so khong duoc = 0!";
    }
};

// ================= CLASS =================
class PhanSo {
private:
    int tu, mau;

    // UCLN
    int gcd(int a, int b) const {
        return b == 0 ? a : gcd(b, a % b);
    }

    void toiGian() {
        int g = gcd(abs(tu), abs(mau));
        tu /= g;
        mau /= g;

        if (mau < 0) { // chuẩn hóa dấu
            tu = -tu;
            mau = -mau;
        }
    }

public:
    // constructor
    PhanSo(int t = 0, int m = 1) {
        if (m == 0) throw MauSoBangKhong();
        tu = t;
        mau = m;
        toiGian();
    }

    // ================= OPERATOR =================

    // +
    PhanSo operator+(const PhanSo& other) const {
        return PhanSo(tu * other.mau + other.tu * mau,
                      mau * other.mau);
    }

    // -
    PhanSo operator-(const PhanSo& other) const {
        return PhanSo(tu * other.mau - other.tu * mau,
                      mau * other.mau);
    }

    // *
    PhanSo operator*(const PhanSo& other) const {
        return PhanSo(tu * other.tu, mau * other.mau);
    }

    // /
    PhanSo operator/(const PhanSo& other) const {
        if (other.tu == 0) throw MauSoBangKhong();
        return PhanSo(tu * other.mau, mau * other.tu);
    }

    // ==
    bool operator==(const PhanSo& other) const {
        return tu == other.tu && mau == other.mau;
    }

    // <
    bool operator<(const PhanSo& other) const {
        return tu * other.mau < other.tu * mau;
    }

    // >
    bool operator>(const PhanSo& other) const {
        return tu * other.mau > other.tu * mau;
    }

    // ================= OUTPUT =================
    friend ostream& operator<<(ostream& os, const PhanSo& ps) {
        if (ps.mau == 1)
            os << ps.tu;
        else
            os << ps.tu << "/" << ps.mau;
        return os;
    }
};

// ================= MAIN =================
int main() {
    vector<PhanSo> ds;

    try {
        ds.push_back(PhanSo(1, 2));
        ds.push_back(PhanSo(3, 4));
        ds.push_back(PhanSo(2, 4)); // sẽ thành 1/2
        ds.push_back(PhanSo(5, 1)); // số nguyên

    } catch (exception& e) {
        cout << "Loi: " << e.what() << endl;
    }

    // ===== IN DANH SÁCH =====
    cout << "Danh sach phan so:\n";
    for (auto& ps : ds) {
        cout << ps << endl;
    }

    // ===== SẮP XẾP =====
    sort(ds.begin(), ds.end());

    cout << "\nSau khi sap xep:\n";
    for (auto& ps : ds) {
        cout << ps << endl;
    }

    // ===== PHÉP TOÁN =====
    PhanSo a(1, 2), b(3, 4);

    cout << "\nTinh toan:\n";
    cout << a << " + " << b << " = " << a + b << endl;
    cout << a << " - " << b << " = " << a - b << endl;
    cout << a << " * " << b << " = " << a * b << endl;
    cout << a << " / " << b << " = " << a / b << endl;

    // ===== SO SÁNH =====
    cout << "\nSo sanh:\n";
    cout << a << " == " << b << " ? " << (a == b) << endl;
    cout << a << " < " << b << " ? " << (a < b) << endl;

    return 0;
}