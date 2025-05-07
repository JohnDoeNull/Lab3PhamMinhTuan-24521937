#include <iostream>
#include <vector>
#include <string>
using namespace std;

class ChuyenXe {
protected:
    string maSoChuyen, hoTenTaiXe, soXe;
    float doanhThu;
public:
    virtual void nhap() {
        cout << "Nhap ma so chuyen: "; cin >> maSoChuyen;
        cin.ignore();
        cout << "Nhap ho ten tai xe: "; getline(cin, hoTenTaiXe);
        cout << "Nhap so xe: "; cin >> soXe;
        cout << "Nhap doanh thu: "; cin >> doanhThu;
    }
    virtual void xuat() const {
        cout << "Ma chuyen: " << maSoChuyen << ", Tai xe: " << hoTenTaiXe
             << ", So xe: " << soXe << ", Doanh thu: " << doanhThu << endl;
    }
    float getDoanhThu() const { return doanhThu; }
    virtual ~ChuyenXe() {}
};

class ChuyenXeNoiThanh : public ChuyenXe {
    int soTuyen, soKm;
public:
    void nhap() override {
        ChuyenXe::nhap();
        cout << "Nhap so tuyen: "; cin >> soTuyen;
        cout << "Nhap so km: "; cin >> soKm;
    }
    void xuat() const override {
        cout << "[Noi thanh] ";
        ChuyenXe::xuat();
        cout << "So tuyen: " << soTuyen << ", So km: " << soKm << endl;
    }
};

class ChuyenXeNgoaiThanh : public ChuyenXe {
    string noiDen;
    int soNgay;
public:
    void nhap() override {
        ChuyenXe::nhap();
        cin.ignore();
        cout << "Nhap noi den: "; getline(cin, noiDen);
        cout << "Nhap so ngay di: "; cin >> soNgay;
    }
    void xuat() const override {
        cout << "[Ngoai thanh] ";
        ChuyenXe::xuat();
        cout << "Noi den: " << noiDen << ", So ngay: " << soNgay << endl;
    }
};

int main() {
    vector<ChuyenXe*> ds;

    cout << "\nNhap 2 chuyen xe noi thanh:\n";
    for (int i = 0; i < 2; ++i) {
        ChuyenXe* p = new ChuyenXeNoiThanh();
        p->nhap();
        ds.push_back(p);
    }

    cout << "\nNhap 2 chuyen xe ngoai thanh:\n";
    for (int i = 0; i < 2; ++i) {
        ChuyenXe* p = new ChuyenXeNgoaiThanh();
        p->nhap();
        ds.push_back(p);
    }

    float tong = 0, tongNoi = 0, tongNgoai = 0;

    cout << "\nDanh sach cac chuyen xe:\n";
    for (ChuyenXe* p : ds) {
        p->xuat();
        tong += p->getDoanhThu();
        if (dynamic_cast<ChuyenXeNoiThanh*>(p)) tongNoi += p->getDoanhThu();
        else if (dynamic_cast<ChuyenXeNgoaiThanh*>(p)) tongNgoai += p->getDoanhThu();
    }

    cout << "\nTong doanh thu tat ca: " << tong << endl;
    cout << "Tong doanh thu noi thanh: " << tongNoi << endl;
    cout << "Tong doanh thu ngoai thanh: " << tongNgoai << endl;

    for (ChuyenXe* p : ds) delete p;
    return 0;
}
