#include <iostream>
#include <vector>
#include <string>
using namespace std;

class NhanVien {
protected:
    string hoTen, ngaySinh;
public:
    virtual void nhap() {
        cout << "Nhap ho ten: "; cin.ignore(); getline(cin, hoTen);
        cout << "Nhap ngay sinh: "; getline(cin, ngaySinh);
    }
    virtual void xuat() const {
        cout << "Ho ten: " << hoTen << ", Ngay sinh: " << ngaySinh;
    }
    virtual float tinhLuong() const = 0;
    virtual ~NhanVien() {}
};

class NVSanXuat : public NhanVien {
    float luongCB;
    int soSP;
public:
    void nhap() override {
        NhanVien::nhap();
        cout << "Nhap luong co ban: "; cin >> luongCB;
        cout << "Nhap so san pham: "; cin >> soSP;
    }
    void xuat() const override {
        cout << "[Nhan vien san xuat] ";
        NhanVien::xuat();
        cout << ", Luong CB: " << luongCB << ", So SP: " << soSP
             << ", Luong: " << tinhLuong() << endl;
    }
    float tinhLuong() const override {
        return luongCB + soSP * 5000;
    }
};

class NVVanPhong : public NhanVien {
    int soNgay;
public:
    void nhap() override {
        NhanVien::nhap();
        cout << "Nhap so ngay lam viec: "; cin >> soNgay;
    }
    void xuat() const override {
        cout << "[Nhan vien van phong] ";
        NhanVien::xuat();
        cout << ", So ngay lam: " << soNgay
             << ", Luong: " << tinhLuong() << endl;
    }
    float tinhLuong() const override {
        return soNgay * 100000;
    }
};

int main() {
    vector<NhanVien*> ds;
    int n;

    cout << "Nhap so nhan vien san xuat: "; cin >> n;
    for (int i = 0; i < n; i++) {
        NhanVien* nv = new NVSanXuat();
        nv->nhap();
        ds.push_back(nv);
    }

    cout << "Nhap so nhan vien van phong: "; cin >> n;
    for (int i = 0; i < n; i++) {
        NhanVien* nv = new NVVanPhong();
        nv->nhap();
        ds.push_back(nv);
    }

    float tongLuong = 0;

    cout << "\nDanh sach nhan vien:\n";
    for (NhanVien* nv : ds) {
        nv->xuat();
        tongLuong += nv->tinhLuong();
    }

    cout << "\nTong luong cong ty phai tra: " << tongLuong << endl;

    for (NhanVien* nv : ds) delete nv;
    return 0;
}
