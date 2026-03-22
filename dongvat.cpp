#include <iostream>
using namespace std;

// ===== Lớp Dog =====
class Dog {
private:
    string ten;
    string mau;
    string giong;
    string camxuc;

public:
    Dog(string t, string m, string g, string c) {
        ten = t;
        mau = m;
        giong = g;
        camxuc = c;
    }

    void sua() {
        cout << ten << " dang sua" << endl;
    }

    void vayDuoi() {
        cout << ten << " dang vay duoi" << endl;
    }

    void an() {
        cout << ten << " dang an" << endl;
    }

    void chay() {
        cout << ten << " dang chay" << endl;
    }
};


// ===== Lớp Car =====
class Car {
private:
    string hang;
    string kichthuoc;
    string mau;
    double gia;

public:
    Car(string h, string k, string m, double g) {
        hang = h;
        kichthuoc = k;
        mau = m;
        gia = g;
    }

    void tangToc() {
        cout << "Xe dang tang toc" << endl;
    }

    void giamToc() {
        cout << "Xe dang giam toc" << endl;
    }

    void dung() {
        cout << "Xe da dung" << endl;
    }
};


// ===== Lớp Account =====
class Account {
private:
    string tenTK;
    string soTK;
    string nganHang;
    double soDu;

public:
    Account(string t, string s, string n, double d) {
        tenTK = t;
        soTK = s;
        nganHang = n;
        soDu = d;
    }

    void rut(double tien) {
        if (tien <= soDu) {
            soDu -= tien;
            cout << "Rut thanh cong. So du: " << soDu << endl;
        } else {
            cout << "Khong du tien" << endl;
        }
    }

    void gui(double tien) {
        soDu += tien;
        cout << "Gui thanh cong. So du: " << soDu << endl;
    }

    void kiemTra() {
        cout << "So du hien tai: " << soDu << endl;
    }
};


// ===== Main =====
int main() {

    // Dog
    Dog dog1("Milu", "Vang", "Poodle", "Vui");
    dog1.sua();
    dog1.an();

    cout << "------" << endl;

    // Car
    Car car1("Toyota", "Lon", "Den", 500000000);
    car1.tangToc();
    car1.dung();

    cout << "------" << endl;

    // Account
    Account acc1("Nguyen Van A", "123456", "ACB", 1000);
    acc1.kiemTra();
    acc1.gui(500);
    acc1.rut(300);

    return 0;
}