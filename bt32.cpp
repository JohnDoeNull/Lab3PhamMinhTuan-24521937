#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Sach {
protected:
    string maSach, ngayNhap, nxb;
    float donGia;
    int soLuong;
public:
    virtual void nhap() {
        cout << "Nhap ma sach: "; cin >> maSach;
        cout << "Nhap ngay nhap: "; cin >> ngayNhap;
        cout << "Nhap don gia: "; cin >> donGia;
        cout << "Nhap so luong: "; cin >> soLuong;
        cout << "Nhap nha xuat ban: "; cin.ignore(); getline(cin, nxb);
    }
    virtual void xuat() const {
        cout << "Ma sach: " << maSach << ", Ngay nhap: " << ngayNhap
             << ", Don gia: " << donGia << ", So luong: " << soLuong
             << ", NXB: " << nxb;
    }
    virtual float thanhTien() const = 0;
    float getDonGia() const { return donGia; }
    string getNXB() const { return nxb; }
    virtual ~Sach() {}
};

class SachGiaoKhoa : public Sach {
    string tinhTrang;
public:
    void nhap() override {
        Sach::nhap();
        cout << "Nhap tinh trang (moi/cu): "; cin >> tinhTrang;
    }
    void xuat() const override {
        cout << "[Giao khoa] "; Sach::xuat();
        cout << ", Tinh trang: " << tinhTrang
             << ", Thanh tien: " << thanhTien() << endl;
    }
    float thanhTien() const override {
        return tinhTrang == "moi" ? soLuong * donGia : soLuong * donGia * 0.5;
    }
};

class SachThamKhao : public Sach {
    float thue;
public:
    void nhap() override {
        Sach::nhap();
        cout << "Nhap thue: "; cin >> thue;
    }
    void xuat() const override {
        cout << "[Tham khao] "; Sach::xuat();
        cout << ", Thue: " << thue << ", Thanh tien: " << thanhTien() << endl;
    }
    float thanhTien() const override {
        return soLuong * donGia + thue;
    }
};

int main() {
    vector<Sach*> dsSach;
    cout << "\nNhap 3 sach giao khoa:\n";
    for (int i = 0; i < 3; i++) {
        Sach* s = new SachGiaoKhoa();
        s->nhap();
        dsSach.push_back(s);
    }

    cout << "\nNhap 3 sach tham khao:\n";
    for (int i = 0; i < 3; i++) {
        Sach* s = new SachThamKhao();
        s->nhap();
        dsSach.push_back(s);
    }

    float tongGK = 0, tongTK = 0, tongDonGiaTK = 0;
    int demTK = 0;
    string nxbK;
    cout << "\nNhap NXB de loc sach giao khoa: ";
    cin.ignore(); getline(cin, nxbK);

    cout << "\nDanh sach cac sach:\n";
    for (Sach* s : dsSach) {
        s->xuat();
        if (dynamic_cast<SachGiaoKhoa*>(s)) {
            tongGK += s->thanhTien();
            if (s->getNXB() == nxbK)
                cout << "  --> Giao khoa cua NXB " << nxbK << endl;
        } else if (SachThamKhao* tk = dynamic_cast<SachThamKhao*>(s)) {
            tongTK += s->thanhTien();
            tongDonGiaTK += s->getDonGia();
            demTK++;
        }
    }

    cout << "\nTong tien sach giao khoa: " << tongGK;
    cout << "\nTong tien sach tham khao: " << tongTK;
    if (demTK)
        cout << "\nTrung binh don gia sach tham khao: " << (tongDonGiaTK / demTK) << endl;

    for (Sach* s : dsSach) delete s;
    return 0;
}
