#include <iostream>
#include <vector>
using namespace std;

class SieuNhan {
public:
    string ten;
    string vu_khi;
    string mau_sac;

    void nhap() {
        cout << "Nhap ten: ";
        cin >> ten;
        cout << "Nhap vu khi: ";
        cin >> vu_khi;
        cout << "Nhap mau sac: ";
        cin >> mau_sac;
    }

    void hienThi() {
        cout << ten << " - " << vu_khi << " - " << mau_sac << endl;
    }
};

int main() {
    vector<SieuNhan> ds;
    int n;

    cout << "Nhap so luong sieu nhan: ";
    cin >> n;

    // dùng while
    int i = 0;
    while (i < n) {
        SieuNhan sn;
        sn.nhap();
        ds.push_back(sn);
        i++;
    }

    cout << "\nDanh sach sieu nhan:\n";

    // dùng for
    for (int i = 0; i < ds.size(); i++) {
        ds[i].hienThi();
    }

    return 0;
}