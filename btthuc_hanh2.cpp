#include <iostream>
using namespace std;

class SieuNhan {
public:
    string ten;
    string vu_khi;
    string mau_sac;

    SieuNhan(string t, string vk, string ms) {
        ten = t;
        vu_khi = vk;
        mau_sac = ms;
    }

    void hienThi() {
        cout << "Ten: " << ten << endl;
        cout << "Vu khi: " << vu_khi << endl;
        cout << "Mau sac: " << mau_sac << endl;
        cout << "-------------------\n";
    }
};

int main() {
    SieuNhan A("A", "Kiem", "Do");
    SieuNhan B("B", "Khien", "Xanh");

    A.hienThi();
    B.hienThi();

    return 0;
}