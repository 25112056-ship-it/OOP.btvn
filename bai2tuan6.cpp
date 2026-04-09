#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

// ================= EXCEPTION =================
class TuoiKhongHopLe : public exception {
public:
    const char* what() const noexcept override {
        return "Tuoi phai tu 18 den 65!";
    }
};

class BacKhongHopLe : public exception {
public:
    const char* what() const noexcept override {
        return "Bac cong nhan phai tu 1 den 10!";
    }
};

// ================= ABSTRACT CLASS =================
class CanBo {
protected:
    string hoTen;
    int tuoi;
    string gioiTinh;
    string diaChi;

public:
    CanBo(string ht, int t, string gt, string dc) {
        hoTen = ht;
        setTuoi(t);
        gioiTinh = gt;
        diaChi = dc;
    }

    virtual ~CanBo() {}

    void setTuoi(int t) {
        if (t < 18 || t > 65) throw TuoiKhongHopLe();
        tuoi = t;
    }

    string getTen() const { return hoTen; }
    int getTuoi() const { return tuoi; }

    virtual void moTa() = 0;

    // so sánh theo tên
    bool operator<(const CanBo& other) const {
        return hoTen < other.hoTen;
    }
};

// ================= SUBCLASSES =================
class CongNhan : public CanBo {
private:
    int bac;

public:
    CongNhan(string ht, int t, string gt, string dc, int b)
        : CanBo(ht, t, gt, dc) {
        setBac(b);
    }

    void setBac(int b) {
        if (b < 1 || b > 10) throw BacKhongHopLe();
        bac = b;
    }

    void moTa() override {
        cout << "[Cong nhan] " << hoTen << " - " << tuoi
             << " tuoi - Bac: " << bac << endl;
    }
};

class KySu : public CanBo {
private:
    string nganh;

public:
    KySu(string ht, int t, string gt, string dc, string n)
        : CanBo(ht, t, gt, dc), nganh(n) {}

    void moTa() override {
        cout << "[Ky su] " << hoTen << " - " << tuoi
             << " tuoi - Nganh: " << nganh << endl;
    }
};

class NhanVien : public CanBo {
private:
    string congViec;

public:
    NhanVien(string ht, int t, string gt, string dc, string cv)
        : CanBo(ht, t, gt, dc), congViec(cv) {}

    void moTa() override {
        cout << "[Nhan vien] " << hoTen << " - " << tuoi
             << " tuoi - CV: " << congViec << endl;
    }
};

// ================= MANAGER =================
class QLCB {
private:
    vector<CanBo*> ds;

public:
    ~QLCB() {
        for (auto p : ds) delete p;
    }

    void them(CanBo* cb) {
        ds.push_back(cb);
    }

    void hienThi() {
        // sort theo tên
        sort(ds.begin(), ds.end(), [](CanBo* a, CanBo* b) {
            return a->getTen() < b->getTen();
        });

        for (auto p : ds) {
            p->moTa();
        }
    }

    void timKiem(string ten) {
        cout << "\nKet qua tim kiem:\n";
        for (auto p : ds) {
            if (p->getTen().find(ten) != string::npos) {
                p->moTa();
            }
        }
    }

    void luuFile(string filename) {
        ofstream f(filename);
        for (auto p : ds) {
            f << p->getTen() << " - " << p->getTuoi() << endl;
        }
        f.close();
    }

    void docFile(string filename) {
        ifstream f(filename);
        string line;
        cout << "\n--- Noi dung file ---\n";
        while (getline(f, line)) {
            cout << line << endl;
        }
        f.close();
    }
};

// ================= MAIN =================
int main() {
    QLCB ql;

    try {
        ql.them(new CongNhan("Nguyen Van A", 30, "Nam", "HN", 5));
        ql.them(new KySu("Tran Van B", 40, "Nam", "HCM", "CNTT"));
        ql.them(new NhanVien("Le Thi C", 25, "Nu", "DN", "Ke toan"));

        // test lỗi
        // ql.them(new CongNhan("Test", 20, "Nam", "HN", 20));

    } catch (exception& e) {
        cout << "Loi: " << e.what() << endl;
    }

    cout << "\n=== Danh sach can bo ===\n";
    ql.hienThi();

    ql.timKiem("Nguyen");

    ql.luuFile("canbo.txt");
    ql.docFile("canbo.txt");

    return 0;
}