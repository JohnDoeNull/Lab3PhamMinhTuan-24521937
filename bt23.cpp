#include <iostream>
using namespace std;

class SoPhuc {
private:
    float iThuc, iAo;

public:
    void Nhap() {
        cout << "Nhap phan thuc: ";
        cin >> iThuc;
        cout << "Nhap phan ao: ";
        cin >> iAo;
    }

    void Xuat() {
        cout << iThuc << " + " << iAo << "i" << endl;
    }

    SoPhuc Tong(const SoPhuc& sp) {
        SoPhuc result;
        result.iThuc = iThuc + sp.iThuc;
        result.iAo = iAo + sp.iAo;
        return result;
    }

    SoPhuc Hieu(const SoPhuc& sp) {
        SoPhuc result;
        result.iThuc = iThuc - sp.iThuc;
        result.iAo = iAo - sp.iAo;
        return result;
    }

    SoPhuc Tich(const SoPhuc& sp) {
        SoPhuc result;
        result.iThuc = iThuc * sp.iThuc - iAo * sp.iAo;
        result.iAo = iThuc * sp.iAo + iAo * sp.iThuc;
        return result;
    }

    SoPhuc Thuong(const SoPhuc& sp) {
        SoPhuc result;
        float denom = sp.iThuc * sp.iThuc + sp.iAo * sp.iAo;
        result.iThuc = (iThuc * sp.iThuc + iAo * sp.iAo) / denom;
        result.iAo = (iAo * sp.iThuc - iThuc * sp.iAo) / denom;
        return result;
    }
};

int main() {
    SoPhuc sp1, sp2;
    sp1.Nhap();
    sp2.Nhap();
    sp1.Xuat();
    sp2.Xuat();
    SoPhuc sp3 = sp1.Tong(sp2);
    sp3.Xuat();
    return 0;
}
