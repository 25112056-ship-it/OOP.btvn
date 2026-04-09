#include <iostream>
#include <string>
using namespace std;

// ===================== LỚP CHA =====================
class HangHoa {
protected:
    string ma_hang;
    string ten_hang;
    string nha_sx;
    double gia;

public:
    HangHoa(string ma = "", string ten = "", string nsx = "", double gia = 0) {
        this->ma_hang = ma;
        this->ten_hang = ten;
        this->nha_sx = nsx;
        this->gia = gia;
    }

    virtual void xuat() {
        cout << "Ma hang: " << ma_hang << endl;
        cout << "Ten hang: " << ten_hang << endl;
        cout << "Nha san xuat: " << nha_sx << endl;
        cout << "Gia: " << gia << endl;
    }

    virtual ~HangHoa() {}
};

// ===================== HÀNG ĐIỆN MÁY =====================
class HangDienMay : public HangHoa {
private:
    int tg_baohanh;
    int dien_ap;
    int cong_suat;

public:
    HangDienMay(string ma, string ten, string nsx, double gia,
                int tg, int da, int cs)
        : HangHoa(ma, ten, nsx, gia) {
        tg_baohanh = tg;
        dien_ap = da;
        cong_suat = cs;
    }

    void xuat() override {
        HangHoa::xuat();
        cout << "Thoi gian bao hanh: " << tg_baohanh << " thang\n";
        cout << "Dien ap: " << dien_ap << " V\n";
        cout << "Cong suat: " << cong_suat << " W\n";
        cout << "----------------------\n";
    }
};

// ===================== HÀNG SÀNH SỨ =====================
class HangSanhSu : public HangHoa {
private:
    string loai_nguyen_lieu;

public:
    HangSanhSu(string ma, string ten, string nsx, double gia,
               string loai)
        : HangHoa(ma, ten, nsx, gia) {
        loai_nguyen_lieu = loai;
    }

    void xuat() override {
        HangHoa::xuat();
        cout << "Loai nguyen lieu: " << loai_nguyen_lieu << endl;
        cout << "----------------------\n";
    }
};

// ===================== HÀNG THỰC PHẨM =====================
class HangThucPham : public HangHoa {
private:
    string ngay_sx;
    string ngay_hh;

public:
    HangThucPham(string ma, string ten, string nsx, double gia,
                 string nsxuat, string hsd)
        : HangHoa(ma, ten, nsx, gia) {
        ngay_sx = nsxuat;
        ngay_hh = hsd;
    }

    void xuat() override {
        HangHoa::xuat();
        cout << "Ngay san xuat: " << ngay_sx << endl;
        cout << "Han su dung: " << ngay_hh << endl;
        cout << "----------------------\n";
    }
};

// ===================== MAIN =====================
int main() {
    HangDienMay a("DM01", "Tivi", "Samsung", 10000, 24, 220, 150);
    HangSanhSu b("SS01", "Bat", "Bat Trang", 200, "Dat set");
    HangThucPham c("TP01", "Sua", "Vinamilk", 50, "01/01/2024", "01/06/2024");

    cout << "=== HANG DIEN MAY ===\n";
    a.xuat();

    cout << "=== HANG SANH SU ===\n";
    b.xuat();

    cout << "=== HANG THUC PHAM ===\n";
    c.xuat();

    return 0;
}