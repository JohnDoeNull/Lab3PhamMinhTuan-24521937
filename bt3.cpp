#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class PhanSo {
private:
    int tu, mau;

public:
    PhanSo(int tu, int mau) : tu(tu), mau(mau) {}

    float giaTri() {
        return static_cast<float>(tu) / mau;
    }

    bool operator<(const PhanSo& other) {
        return giaTri() < other.giaTri();
    }

    static PhanSo tong(PhanSo ps1, PhanSo ps2) {
        int tu = ps1.tu * ps2.mau + ps2.tu * ps1.mau;
        int mau = ps1.mau * ps2.mau;
        return PhanSo(tu, mau);
    }

    void xuat() {
        cout << tu << "/" << mau << " ";
    }
};

class cDSPhanSo {
private:
    vector<PhanSo> danhSach;

public:
    void themPhanSo(PhanSo ps) {
        danhSach.push_back(ps);
    }

    PhanSo tinhTong() {
        PhanSo tong(0, 1);
        for (auto& ps : danhSach) {
            tong = PhanSo::tong(tong, ps);
        }
        return tong;
    }

    void xuatDanhSach() {
        for (auto& ps : danhSach) {
            ps.xuat();
        }
        cout << endl;
    }
};

int main() {
    cDSPhanSo ds;
    ds.themPhanSo(PhanSo(1, 2));
    ds.themPhanSo(PhanSo(2, 3));
    cout << "Tổng các phân số: ";
    ds.xuatDanhSach();
    return 0;
}
