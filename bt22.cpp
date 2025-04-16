#include <iostream>
using namespace std;

class PhanSo {
private:
    int iTu, iMau;

    int gcd(int a, int b) {
        while (b != 0) {
            int t = b;
            b = a % b;
            a = t;
        }
        return a;
    }

public:
    void Nhap() {
        cout << "Nhap tu: ";
        cin >> iTu;
        cout << "Nhap mau: ";
        cin >> iMau;
    }

    void Xuat() {
        cout << iTu << "/" << iMau << endl;
    }

    void RutGon() {
        int ucln = gcd(iTu, iMau);
        iTu /= ucln;
        iMau /= ucln;
    }

    PhanSo Tong(const PhanSo& ps) {
        PhanSo result;
        result.iTu = iTu * ps.iMau + ps.iTu * iMau;
        result.iMau = iMau * ps.iMau;
        result.RutGon();
        return result;
    }

    PhanSo Hieu(const PhanSo& ps) {
        PhanSo result;
        result.iTu = iTu * ps.iMau - ps.iTu * iMau;
        result.iMau = iMau * ps.iMau;
        result.RutGon();
        return result;
    }

    PhanSo Tich(const PhanSo& ps) {
        PhanSo result;
        result.iTu = iTu * ps.iTu;
        result.iMau = iMau * ps.iMau;
        result.RutGon();
        return result;
    }

    PhanSo Thuong(const PhanSo& ps) {
        PhanSo result;
        result.iTu = iTu * ps.iMau;
        result.iMau = iMau * ps.iTu;
        result.RutGon();
        return result;
    }
};

int main() {
    PhanSo ps1, ps2;
    ps1.Nhap();
    ps2.Nhap();
    ps1.Xuat();
    ps2.Xuat();
    ps1.RutGon();
    ps1.Xuat();
    PhanSo ps3 = ps1.Tong(ps2);
    ps3.Xuat();
    return 0;
}
