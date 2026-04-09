#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

// ================= EXCEPTION =================
class TuoiKhongHopLe : public exception {
public:
    const char* what() const noexcept override {
        return "Tuoi phai tu 18-65!";
    }
};

class BacKhongHopLe : public exception {
public:
    const char* what() const noexcept override {
        return "Bac phai tu 1-10!";
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
    CanBo(string ht, int t, string gt, string dc)
        : hoTen(ht), gioiTinh(gt), diaChi(dc) {
        setTuoi(t);
    }

    virtual ~CanBo() {}

    void setTuoi(int t) {
        if (t < 18 || t > 65) throw TuoiKhongHopLe();
        tuoi = t;
    }

    string getTen() const { return hoTen; }

    // abstract
    virtual string moTa() const = 0;

    // giống __str__
    virtual string toString() const {
        return hoTen + " - " + to_string(tuoi) + " - " + gioiTinh + " - " + diaChi;
    }

    // giống __repr__
    virtual string repr() const {
        return toString();
    }

    // giống __eq__
    bool operator==(const CanBo& other) const {
        return hoTen == other.hoTen && tuoi == other.tuoi;
    }

    // giống __lt__ (sort theo tên)
    bool operator<(const CanBo& other) const {
        return hoTen < other.hoTen;
    }

    // in giống print(obj)
    friend ostream& operator<<(ostream& os, const CanBo& cb) {
        os << cb.moTa();
        return os;
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

    string moTa() const override {
        return "[CongNhan] " + toString() + " - Bac: " + to_string(bac);
    }
};

class KySu : public CanBo {
private:
    string nganh;

public:
    KySu(string ht, int t, string gt, string dc, string n)
        : CanBo(ht, t, gt, dc), nganh(n) {}

    string moTa() const override {
        return "[KySu] " + toString() + " - Nganh: " + nganh;
    }
};

class NhanVien : public CanBo {
private:
    string congViec;

public:
    NhanVien(string ht, int t, string gt, string dc, string cv)
        : CanBo(ht, t, gt, dc), congViec(cv) {}

    string moTa() const override {
        return "[NhanVien] " + toString() + " - CV: " + congViec;
    }
};

// ================= MAIN =================
int main() {
    vector<CanBo*> ds;

    try {
        ds.push_back(new CongNhan("Nguyen A", 30, "Nam", "HN", 5));
        ds.push_back(new KySu("Tran B", 28, "Nu", "HCM", "CNTT"));
        ds.push_back(new NhanVien("Le C", 35, "Nam", "DN", "Ke toan"));

    } catch (exception& e) {
        cout << "Loi: " << e.what() << endl;
    }

    // ===== ĐA HÌNH + SORT =====
    sort(ds.begin(), ds.end(), [](CanBo* a, CanBo* b) {
        return *a < *b;
    });

    cout << "=== Danh sach ===\n";
    for (auto cb : ds) {
        cout << *cb << endl;  // giống print(cb)
    }

    // ===== TÌM KIẾM =====
    string ten;
    cout << "\nNhap ten can tim: ";
    getline(cin, ten);

    cout << "Ket qua:\n";
    for (auto cb : ds) {
        if (cb->toString().find(ten) != string::npos) {
            cout << *cb << endl;
        }
    }

    // ===== LƯU FILE =====
    ofstream f("canbo.txt");
    for (auto cb : ds) {
        f << cb->repr() << endl;
    }
    f.close();

    cout << "\nDa luu file canbo.txt\n";

    // cleanup
    for (auto cb : ds) delete cb;

    return 0;
}