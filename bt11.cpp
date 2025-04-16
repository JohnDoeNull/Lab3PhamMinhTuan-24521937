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
};

int main() {
    PhanSo ps;
    ps.Nhap();
    ps.RutGon();
    ps.Xuat();
    return 0;
}
