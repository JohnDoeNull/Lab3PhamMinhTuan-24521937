#include <iostream>
using namespace std;

class PhanSo {
private:
    int tu, mau;

    // Hàm tìm ước chung lớn nhất
    int gcd(int a, int b) {
        while (b != 0) {
            int t = b;
            b = a % b;
            a = t;
        }
        return a;
    }

public:
    // Nhập phân số
    void Nhap() {
        cout << "Nhap tu: ";
        cin >> tu;
        cout << "Nhap mau: ";
        cin >> mau;
    }

    // Xuất phân số
    void Xuat() {
        cout << tu << "/" << mau << endl;
    }

    // Rút gọn phân số
    void RutGon() {
        int ucln = gcd(tu, mau);
        tu /= ucln;
        mau /= ucln;
    }

    // Tính tổng phân số
    PhanSo Tong(const PhanSo& ps) {
        PhanSo result;
        result.tu = tu * ps.mau + ps.tu * mau;
        result.mau = mau * ps.mau;
        result.RutGon();
        return result;
    }

    // Tính hiệu phân số
    PhanSo Hieu(const PhanSo& ps) {
        PhanSo result;
        result.tu = tu * ps.mau - ps.tu * mau;
        result.mau = mau * ps.mau;
        result.RutGon();
        return result;
    }

    // Tính tích phân số
    PhanSo Tich(const PhanSo& ps) {
        PhanSo result;
        result.tu = tu * ps.tu;
        result.mau = mau * ps.mau;
        result.RutGon();
        return result;
    }

    // Tính thương phân số
    PhanSo Thuong(const PhanSo& ps) {
        PhanSo result;
        result.tu = tu * ps.mau;
        result.mau = mau * ps.tu;
        result.RutGon();
        return result;
    }
};

int main() {
    PhanSo ps1, ps2;
    ps1.Nhap();
    ps2.Nhap();
    
    ps1.RutGon();
    ps2.RutGon();

    cout << "Tổng hai phân số: ";
    PhanSo psTong = ps1.Tong(ps2);
    psTong.Xuat();

    cout << "Hiệu hai phân số: ";
    PhanSo psHieu = ps1.Hieu(ps2);
    psHieu.Xuat();

    cout << "Tích hai phân số: ";
    PhanSo psTich = ps1.Tich(ps2);
    psTich.Xuat();

    cout << "Thương hai phân số: ";
    PhanSo psThuong = ps1.Thuong(ps2);
    psThuong.Xuat();

    return 0;
}
