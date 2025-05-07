#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

class GiaoDich {
protected:
    string maGD, ngayGD;
    float donGia;
    int soLuong;
public:
    virtual void nhap() {
        cout << "Nhap ma giao dich: "; cin >> maGD;
        cout << "Nhap ngay giao dich: "; cin >> ngayGD;
        cout << "Nhap don gia: "; cin >> donGia;
        cout << "Nhap so luong: "; cin >> soLuong;
    }
    virtual void xuat() const {
        cout << "Ma GD: " << maGD << ", Ngay GD: " << ngayGD
             << ", Don gia: " << donGia << ", So luong: " << soLuong;
    }
    virtual float thanhTien() const = 0;
    virtual ~GiaoDich() {}
};

class GDVang : public GiaoDich {
    string loaiVang;
public:
    void nhap() override {
        GiaoDich::nhap();
        cout << "Nhap loai vang: "; cin.ignore(); getline(cin, loaiVang);
    }
    void xuat() const override {
        cout << "[Giao dich vang] ";
        GiaoDich::xuat();
        cout << ", Loai vang: " << loaiVang
             << ", Thanh tien: " << thanhTien() << endl;
    }
    float thanhTien() const override {
        return soLuong * donGia;
    }
};

class GDTienTe : public GiaoDich {
    float tiGia;
    string loaiTien;
public:
    void nhap() override {
        GiaoDich::nhap();
        cout << "Nhap loai tien (VND/USD/EURO): "; cin >> loaiTien;
        cout << "Nhap ti gia: "; cin >> tiGia;
    }
    void xuat() const override {
        cout << "[Giao dich tien te] ";
        GiaoDich::xuat();
        cout << ", Loai tien: " << loaiTien << ", Ti gia: " << tiGia
             << ", Thanh tien: " << thanhTien() << endl;
    }
    float thanhTien() const override {
        if (loaiTien == "USD" || loaiTien == "EURO")
            return soLuong * donGia * tiGia;
        return soLuong * donGia;
    }
    string getLoaiTien() const { return loaiTien; }
};

int main() {
    vector<GiaoDich*> ds;
    int n;
    cout << "Nhap so giao dich vang: "; cin >> n;
    for (int i = 0; i < n; ++i) {
        GiaoDich* gd = new GDVang();
        gd->nhap();
        ds.push_back(gd);
    }

    cout << "Nhap so giao dich tien te: "; cin >> n;
    for (int i = 0; i < n; ++i) {
        GiaoDich* gd = new GDTienTe();
        gd->nhap();
        ds.push_back(gd);
    }

    float maxVang = -1, minEuro = numeric_limits<float>::max();
    GiaoDich* gdMaxVang = nullptr;
    GiaoDich* gdMinEuro = nullptr;

    cout << "\nDanh sach giao dich:\n";
    for (GiaoDich* gd : ds) {
        gd->xuat();

        if (GDVang* g = dynamic_cast<GDVang*>(gd)) {
            float tt = g->thanhTien();
            if (tt > maxVang) {
                maxVang = tt;
                gdMaxVang = g;
            }
        }

        if (GDTienTe* g = dynamic_cast<GDTienTe*>(gd)) {
            if (g->getLoaiTien() == "EURO") {
                float tt = g->thanhTien();
                if (tt < minEuro) {
                    minEuro = tt;
                    gdMinEuro = g;
                }
            }
        }
    }

    cout << "\nGiao dich vang co thanh tien cao nhat:\n";
    if (gdMaxVang) gdMaxVang->xuat();

    cout << "\nGiao dich EURO co thanh tien thap nhat:\n";
    if (gdMinEuro) gdMinEuro->xuat();

    cout << "\nDanh sach giao dich thanh tien > 1 ty:\n";
    for (GiaoDich* gd : ds) {
        if (gd->thanhTien() > 1e9) gd->xuat();
    }

    for (GiaoDich* gd : ds) delete gd;
    return 0;
}
