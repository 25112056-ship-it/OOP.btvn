#include <iostream>
using namespace std;

class NhanVien {
private:
    string tenNhanVien;
    double luongCoBan;
    double heSoLuong;

public:
    static constexpr double LUONG_MAX = 50000000; // hằng số

    // ===== Constructor =====
    NhanVien(string ten = "", double lcb = 0, double hsl = 0) {
        tenNhanVien = ten;
        luongCoBan = lcb;
        heSoLuong = hsl;
    }

    // ===== Getter =====
    string getTen() { return tenNhanVien; }
    double getLuongCoBan() { return luongCoBan; }
    double getHeSoLuong() { return heSoLuong; }

    // ===== Setter =====
    void setTen(string ten) { tenNhanVien = ten; }
    void setLuongCoBan(double lcb) { luongCoBan = lcb; }
    void setHeSoLuong(double hsl) { heSoLuong = hsl; }

    // ===== Tính lương =====
    double tinhLuong() {
        return luongCoBan * heSoLuong;
    }

    // ===== Tăng lương (tăng hệ số) =====
    bool tangLuong(double delta) {
        double heSoMoi = heSoLuong + delta;
        double luongMoi = luongCoBan * heSoMoi;

        if (luongMoi > LUONG_MAX) {
            cout << "Luong vuot qua LUONG_MAX!" << endl;
            return false;
        }

        heSoLuong = heSoMoi;
        return true;
    }

    // ===== In thông tin =====
    void inTTin() {
        cout << "Ten: " << tenNhanVien << endl;
        cout << "Luong co ban: " << luongCoBan << endl;
        cout << "He so luong: " << heSoLuong << endl;
        cout << "Luong: " << tinhLuong() << endl;
    }
};

// ===== MAIN =====
int main() {
    NhanVien nv("Nguyen Van A", 5000000, 2.0);

    nv.inTTin();

    cout << "\nTang he so luong...\n";
    if (nv.tangLuong(0.5)) {
        cout << "Tang luong thanh cong!\n";
    } else {
        cout << "Tang luong that bai!\n";
    }

    nv.inTTin();

    return 0;
}