#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ===================== LỚP CHA =====================
class CanBo {
protected:
    string hoTen;
    int tuoi;
    string gioiTinh;
    string diaChi;

public:
    CanBo(string ht = "", int t = 0, string gt = "", string dc = "") {
        hoTen = ht;
        tuoi = t;
        gioiTinh = gt;
        diaChi = dc;
    }

    virtual void nhap() {
        cin.ignore();
        cout << "Ho ten: "; getline(cin, hoTen);
        cout << "Tuoi: "; cin >> tuoi;
        cin.ignore();
        cout << "Gioi tinh: "; getline(cin, gioiTinh);
        cout << "Dia chi: "; getline(cin, diaChi);
    }

    virtual void xuat() {
        cout << "Ho ten: " << hoTen << endl;
        cout << "Tuoi: " << tuoi << endl;
        cout << "Gioi tinh: " << gioiTinh << endl;
        cout << "Dia chi: " << diaChi << endl;
    }

    string getHoTen() {
        return hoTen;
    }

    virtual ~CanBo() {}
};

// ===================== CÔNG NHÂN =====================
class CongNhan : public CanBo {
private:
    int bac;

public:
    void nhap() override {
        CanBo::nhap();
        cout << "Bac (1-10): ";
        cin >> bac;
    }

    void xuat() override {
        CanBo::xuat();
        cout << "Bac: " << bac << endl;
        cout << "---------------------\n";
    }
};

// ===================== KỸ SƯ =====================
class KySu : public CanBo {
private:
    string nganh;

public:
    void nhap() override {
        CanBo::nhap();
        cin.ignore();
        cout << "Nganh dao tao: ";
        getline(cin, nganh);
    }

    void xuat() override {
        CanBo::xuat();
        cout << "Nganh: " << nganh << endl;
        cout << "---------------------\n";
    }
};

// ===================== NHÂN VIÊN =====================
class NhanVien : public CanBo {
private:
    string congViec;

public:
    void nhap() override {
        CanBo::nhap();
        cin.ignore();
        cout << "Cong viec: ";
        getline(cin, congViec);
    }

    void xuat() override {
        CanBo::xuat();
        cout << "Cong viec: " << congViec << endl;
        cout << "---------------------\n";
    }
};

// ===================== QUẢN LÝ CÁN BỘ =====================
class QLCB {
private:
    vector<CanBo*> ds;

public:
    // Thêm cán bộ
    void themCanBo() {
        int loai;
        cout << "\n1. Cong nhan\n2. Ky su\n3. Nhan vien\nChon: ";
        cin >> loai;

        CanBo* cb = nullptr;

        if (loai == 1) cb = new CongNhan();
        else if (loai == 2) cb = new KySu();
        else if (loai == 3) cb = new NhanVien();

        if (cb != nullptr) {
            cb->nhap();
            ds.push_back(cb);
        }
    }

    // Tìm kiếm theo họ tên
    void timKiem() {
        cin.ignore();
        string ten;
        cout << "Nhap ten can tim: ";
        getline(cin, ten);

        cout << "\nKet qua:\n";
        for (auto cb : ds) {
            if (cb->getHoTen().find(ten) != string::npos) {
                cb->xuat();
            }
        }
    }

    // Hiển thị danh sách
    void hienThi() {
        cout << "\nDanh sach can bo:\n";
        for (auto cb : ds) {
            cb->xuat();
        }
    }

    // Destructor giải phóng bộ nhớ
    ~QLCB() {
        for (auto cb : ds) {
            delete cb;
        }
    }
};

// ===================== MAIN =====================
int main() {
    QLCB ql;
    int chon;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Them can bo\n";
        cout << "2. Tim kiem theo ten\n";
        cout << "3. Hien thi danh sach\n";
        cout << "0. Thoat\n";
        cout << "Chon: ";
        cin >> chon;

        switch (chon) {
        case 1:
            ql.themCanBo();
            break;
        case 2:
            ql.timKiem();
            break;
        case 3:
            ql.hienThi();
            break;
        case 0:
            cout << "Thoat!\n";
            break;
        default:
            cout << "Lua chon khong hop le!\n";
        }

    } while (chon != 0);

    return 0;
}