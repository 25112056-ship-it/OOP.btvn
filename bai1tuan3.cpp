#include <iostream>
using namespace std;

// ===== CLASS CON CHO =====
class Dog {
private:
    string ten;
    string mauSac;
    string giong;
    string camXuc;

public:
    void nhap() {
        cout << "Nhap ten cho: ";
        getline(cin, ten);
        cout << "Nhap mau sac: ";
        getline(cin, mauSac);
        cout << "Nhap giong: ";
        getline(cin, giong);
        cout << "Nhap cam xuc: ";
        getline(cin, camXuc);
    }

    void sua() {
        cout << ten << " dang sua!" << endl;
    }

    void vayDuoi() {
        cout << ten << " dang vay duoi!" << endl;
    }

    void an() {
        cout << ten << " dang an!" << endl;
    }

    void chay() {
        cout << ten << " dang chay!" << endl;
    }
};

// ===== CLASS O TO =====
class Car {
private:
    string hang;
    string mau;
    double gia;

public:
    void nhap() {
        cout << "Nhap hang xe: ";
        getline(cin, hang);
        cout << "Nhap mau xe: ";
        getline(cin, mau);
        cout << "Nhap gia: ";
        cin >> gia;
        cin.ignore();
    }

    void tangToc() {
        cout << "Xe dang tang toc!" << endl;
    }

    void giamToc() {
        cout << "Xe dang giam toc!" << endl;
    }

    void dam() {
        cout << "Xe da dam!" << endl;
    }
};

// ===== CLASS TAI KHOAN =====
class TaiKhoan {
private:
    string tenTK;
    string soTK;
    string nganHang;
    double soDu;

public:
    void nhap() {
        cout << "Nhap ten tai khoan: ";
        getline(cin, tenTK);
        cout << "Nhap so tai khoan: ";
        getline(cin, soTK);
        cout << "Nhap ngan hang: ";
        getline(cin, nganHang);
        cout << "Nhap so du: ";
        cin >> soDu;
        cin.ignore();
    }

    void rut(double tien) {
        if (tien <= soDu) {
            soDu -= tien;
            cout << "Rut thanh cong! So du con: " << soDu << endl;
        } else {
            cout << "Khong du tien!" << endl;
        }
    }

    void gui(double tien) {
        soDu += tien;
        cout << "Gui thanh cong! So du moi: " << soDu << endl;
    }

    void kiemTra() {
        cout << "So du hien tai: " << soDu << endl;
    }
};

// ===== MAIN =====
int main() {
    // Con cho
    Dog dog;
    dog.nhap();
    dog.sua();
    dog.chay();

    cout << "-----------------\n";

    // O to
    Car car;
    car.nhap();
    car.tangToc();

    cout << "-----------------\n";

    // Tai khoan
    TaiKhoan tk;
    tk.nhap();
    tk.gui(500);
    tk.rut(200);
    tk.kiemTra();

    return 0;
}