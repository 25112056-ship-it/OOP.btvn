#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <fstream>

using namespace std;

// ================= EXCEPTION =================
class GiaKhongHopLe : public exception {
public:
    const char* what() const noexcept override {
        return "Gia phai >= 0!";
    }
};

class MaHangTrungLap : public exception {
public:
    const char* what() const noexcept override {
        return "Ma hang bi trung!";
    }
};

// ================= ABSTRACT CLASS =================
class HangHoa {
protected:
    string ma_hang;
    string ten_hang;
    double gia;

public:
    HangHoa(string ma, string ten, double g) {
        ma_hang = ma;
        ten_hang = ten;
        setGia(g);
    }

    virtual ~HangHoa() {}

    string getMa() const { return ma_hang; }
    string getTen() const { return ten_hang; }
    double getGia() const { return gia; }

    void setGia(double g) {
        if (g < 0) throw GiaKhongHopLe();
        gia = g;
    }

    virtual string loaiHang() = 0;
    virtual void inTTin() = 0;

    // so sánh theo mã (cho set)
    bool operator<(const HangHoa& other) const {
        return ma_hang < other.ma_hang;
    }
};

// ================= SUBCLASSES =================
class HangDienMay : public HangHoa {
private:
    int bao_hanh;

public:
    HangDienMay(string ma, string ten, double g, int bh)
        : HangHoa(ma, ten, g), bao_hanh(bh) {}

    string loaiHang() override {
        return "Dien may";
    }

    void inTTin() override {
        cout << "[Dien may] " << ma_hang << " - " << ten_hang
             << " - " << gia << " - BH: " << bao_hanh << " thang\n";
    }
};

class HangThucPham : public HangHoa {
private:
    string han_su_dung;

public:
    HangThucPham(string ma, string ten, double g, string hsd)
        : HangHoa(ma, ten, g), han_su_dung(hsd) {}

    string loaiHang() override {
        return "Thuc pham";
    }

    void inTTin() override {
        cout << "[Thuc pham] " << ma_hang << " - " << ten_hang
             << " - " << gia << " - HSD: " << han_su_dung << "\n";
    }
};

class HangSanSu : public HangHoa {
private:
    string nha_sx;

public:
    HangSanSu(string ma, string ten, double g, string nsx)
        : HangHoa(ma, ten, g), nha_sx(nsx) {}

    string loaiHang() override {
        return "Sanh su";
    }

    void inTTin() override {
        cout << "[Sanh su] " << ma_hang << " - " << ten_hang
             << " - " << gia << " - NSX: " << nha_sx << "\n";
    }
};

// ================= MANAGER =================
class QuanLyHangHoa {
private:
    vector<HangHoa*> ds;

public:
    ~QuanLyHangHoa() {
        for (auto p : ds) delete p;
    }

    void them(HangHoa* hh) {
        for (auto p : ds) {
            if (p->getMa() == hh->getMa()) {
                throw MaHangTrungLap();
            }
        }
        ds.push_back(hh);
    }

    void hienThi() {
        // sort theo giá
        sort(ds.begin(), ds.end(), [](HangHoa* a, HangHoa* b) {
            return a->getGia() < b->getGia();
        });

        for (auto p : ds) {
            p->inTTin();
        }
    }

    void luuFile(string filename) {
        ofstream f(filename);
        for (auto p : ds) {
            f << p->getMa() << " - " << p->getTen()
              << " - " << p->getGia() << endl;
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
    QuanLyHangHoa ql;

    try {
        ql.them(new HangDienMay("DM01", "Tivi", 10000, 24));
        ql.them(new HangThucPham("TP01", "Sua", 50, "10-12-2025"));
        ql.them(new HangSanSu("SS01", "Bat", 20, "Bat Trang"));

        // test trùng mã
        // ql.them(new HangDienMay("DM01", "Tu lanh", 20000, 12));

    } catch (exception& e) {
        cout << "Loi: " << e.what() << endl;
    }

    cout << "\n=== Danh sach hang hoa ===\n";
    ql.hienThi();

    ql.luuFile("hanghoa.txt");
    ql.docFile("hanghoa.txt");

    return 0;
}