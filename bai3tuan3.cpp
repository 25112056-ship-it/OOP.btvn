#include <iostream>
using namespace std;

class NhanVien {
private:
    string tenNhanVien;
    double luongCoBan;
    double heSoLuong;
    static constexpr double LUONG_MAX = 50000000; // 50 triệu

public:
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

    // ===== Tăng lương =====
    bool tangLuong(double delta) {
        double luongMoi = tinhLuong() + delta;

        if (luongMoi > LUONG_MAX) {
            cout << "Luong vuot qua LUONG_MAX!" << endl;
            return false;
        }

        // tăng bằng cách tăng hệ số
        heSoLuong = (luongMoi) / luongCoBan;
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

    cout << "\nTang luong...\n";
    nv.tangLuong(2000000);

    nv.inTTin();

    return 0;
}