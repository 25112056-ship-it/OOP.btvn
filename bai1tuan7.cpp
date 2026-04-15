#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
using namespace std;

// ================= BASE CLASS =================
class CanBo {
protected:
    string hoTen, gioiTinh, diaChi, loai;
    int tuoi;

public:
    CanBo() {}

    virtual void nhap() {
        cin.ignore();
        cout << "Ho ten: "; getline(cin, hoTen);
        cout << "Tuoi: "; cin >> tuoi;
        cin.ignore();
        cout << "Gioi tinh: "; getline(cin, gioiTinh);
        cout << "Dia chi: "; getline(cin, diaChi);
    }

    virtual void xuat() {
        cout << hoTen << " | " << tuoi << " | "
             << gioiTinh << " | " << diaChi;
    }

    string getHoTen() { return hoTen; }
    string getLoai() { return loai; }

    virtual string toJSON() = 0;

    virtual ~CanBo() {}
};

// ================= CONG NHAN =================
class CongNhan : public CanBo {
    int bac;

public:
    CongNhan() { loai = "CongNhan"; }

    void nhap() override {
        CanBo::nhap();
        cout << "Bac: "; cin >> bac;
    }

    void xuat() override {
        CanBo::xuat();
        cout << " | Bac: " << bac << endl;
    }

    string toJSON() override {
        return "{ \"loai\":\"CongNhan\", \"ten\":\"" + hoTen +
               "\", \"tuoi\":" + to_string(tuoi) +
               ", \"bac\":" + to_string(bac) + " }";
    }

    int getBac() { return bac; }
};

// ================= KY SU =================
class KySu : public CanBo {
    string nganh;

public:
    KySu() { loai = "KySu"; }

    void nhap() override {
        CanBo::nhap();
        cout << "Nganh: "; getline(cin, nganh);
    }

    void xuat() override {
        CanBo::xuat();
        cout << " | Nganh: " << nganh << endl;
    }

    string toJSON() override {
        return "{ \"loai\":\"KySu\", \"ten\":\"" + hoTen +
               "\", \"tuoi\":" + to_string(tuoi) +
               ", \"nganh\":\"" + nganh + "\" }";
    }
};

// ================= NHAN VIEN =================
class NhanVien : public CanBo {
    string congViec;

public:
    NhanVien() { loai = "NhanVien"; }

    void nhap() override {
        CanBo::nhap();
        cout << "Cong viec: "; getline(cin, congViec);
    }

    void xuat() override {
        CanBo::xuat();
        cout << " | CV: " << congViec << endl;
    }

    string toJSON() override {
        return "{ \"loai\":\"NhanVien\", \"ten\":\"" + hoTen +
               "\", \"tuoi\":" + to_string(tuoi) +
               ", \"cv\":\"" + congViec + "\" }";
    }
};

// ================= MANAGER =================
class QuanLyCanBo {
    map<string, CanBo*> ds;

public:
    // ===== ĐỌC CSV =====
    void docCSV(string file) {
        ifstream f(file);
        if (!f) {
            cout << "Khong tim thay file!\n";
            return;
        }

        string line;
        while (getline(f, line)) {
            stringstream ss(line);
            string ten, tuoi, gt, dc, loai, extra;

            getline(ss, ten, ',');
            getline(ss, tuoi, ',');
            getline(ss, gt, ',');
            getline(ss, dc, ',');
            getline(ss, loai, ',');
            getline(ss, extra, ',');

            CanBo* cb = nullptr;

            if (loai == "CongNhan") {
                cb = new CongNhan();
            } else if (loai == "KySu") {
                cb = new KySu();
            } else {
                cb = new NhanVien();
            }

            ds[ten] = cb; // đơn giản (có thể gán dữ liệu thêm)
        }

        f.close();
    }

    // ===== THÊM =====
    void them() {
        int chon;
        cout << "1. Cong nhan\n2. Ky su\n3. Nhan vien\nChon: ";
        cin >> chon;

        CanBo* cb;
        if (chon == 1) cb = new CongNhan();
        else if (chon == 2) cb = new KySu();
        else cb = new NhanVien();

        cb->nhap();
        ds[cb->getHoTen()] = cb;
    }

    // ===== XÓA =====
    void xoa(string ten) {
        ds.erase(ten);
    }

    // ===== TÌM =====
    void tim(string ten) {
        if (ds.count(ten)) ds[ten]->xuat();
        else cout << "Khong tim thay!\n";
    }

    // ===== TÌM THEO LOẠI =====
    void timLoai(string loai) {
        for (auto& p : ds) {
            if (p.second->getLoai() == loai)
                p.second->xuat();
        }
    }

    // ===== LƯU JSON =====
    void luuJSON(string file) {
        ofstream f(file);
        f << "[\n";
        for (auto& p : ds) {
            f << p.second->toJSON() << ",\n";
        }
        f << "]";
        f.close();
    }

    // ===== HIỂN THỊ =====
    void hienThi() {
        for (auto& p : ds)
            p.second->xuat();
    }

    ~QuanLyCanBo() {
        for (auto& p : ds)
            delete p.second;
    }
};

// ================= MAIN =================
int main() {
    QuanLyCanBo ql;
    int chon;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Doc CSV\n";
        cout << "2. Them\n";
        cout << "3. Xoa\n";
        cout << "4. Tim\n";
        cout << "5. Tim theo loai\n";
        cout << "6. Hien thi\n";
        cout << "7. Luu JSON\n";
        cout << "0. Thoat\n";
        cout << "Chon: ";
        cin >> chon;

        try {
            if (chon == 1) ql.docCSV("canbo.csv");
            else if (chon == 2) ql.them();
            else if (chon == 3) {
                string ten; cin.ignore();
                cout << "Nhap ten: "; getline(cin, ten);
                ql.xoa(ten);
            }
            else if (chon == 4) {
                string ten; cin.ignore();
                cout << "Nhap ten: "; getline(cin, ten);
                ql.tim(ten);
            }
            else if (chon == 5) {
                string loai; cin.ignore();
                cout << "Loai: "; getline(cin, loai);
                ql.timLoai(loai);
            }
            else if (chon == 6) ql.hienThi();
            else if (chon == 7) ql.luuJSON("canbo.json");
        }
        catch (...) {
            cout << "Loi xay ra!\n";
        }

    } while (chon != 0);

    return 0;
}