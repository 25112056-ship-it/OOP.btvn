#include <iostream>
using namespace std;

class NhanVien {
private:
    string tenNhanVien;
    double luongCoBan;
    double heSoLuong;

    static constexpr double LUONG_MAX = 50000; // hằng

public:

    // Constructor
    NhanVien(string ten, double luong, double heso) {
        tenNhanVien = ten;
        luongCoBan = luong;
        heSoLuong = heso;
    }

    // ===== Getter =====
    string getTen() {
        return tenNhanVien;
    }

    double getLuongCoBan() {
        return luongCoBan;
    }

    double getHeSoLuong() {
        return heSoLuong;
    }

    // ===== Setter =====
    void setTen(string ten) {
        tenNhanVien = ten;
    }

    void setLuongCoBan(double luong) {
        luongCoBan = luong;
    }

    void setHeSoLuong(double heso) {
        heSoLuong = heso;
    }

    // ===== tính lương =====
    double tinhLuong() {
        return luongCoBan * heSoLuong;
    }

    // ===== tăng lương =====
    bool tangLuong(double delta) {

        double luongMoi = (luongCoBan + delta) * heSoLuong;

        if (luongMoi > LUONG_MAX) {
            cout << "Luong vuot qua LUONG_MAX\n";
            return false;
        }

        luongCoBan += delta;
        return true;
    }

    // ===== in thông tin =====
    void inTTin() {
        cout << "Ten: " << tenNhanVien << endl;
        cout << "Luong co ban: " << luongCoBan << endl;
        cout << "He so: " << heSoLuong << endl;
        cout << "Luong: " << tinhLuong() << endl;
    }
};


int main() {

    NhanVien nv("Nguyen Van A", 1000, 2.5);

    nv.inTTin();

    cout << "Tang luong...\n";

    if (nv.tangLuong(500))
        cout << "Tang thanh cong\n";
    else
        cout << "Tang that bai\n";

    nv.inTTin();

    return 0;
}