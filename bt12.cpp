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

    // So sánh phân số
    bool operator>(const PhanSo &ps) const {
        return tu * ps.mau > mau * ps.tu;
    }
};

int main() {
    PhanSo ps1, ps2;
    ps1.Nhap();
    ps2.Nhap();
    
    ps1.RutGon();
    ps2.RutGon();

    cout << "Phan so 1: ";
    ps1.Xuat();
    cout << "Phan so 2: ";
    ps2.Xuat();

    if (ps1 > ps2) {
        cout << "Phan so 1 lon hon Phan so 2" << endl;
    } else {
        cout << "Phan so 2 lon hon Phan so 1" << endl;
    }

    return 0;
}
