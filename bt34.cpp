#include <iostream>
#include <vector>
#include <string>
using namespace std;

class GiaoDichBDS {
protected:
    string maGD, ngayGD;
    float donGia, dienTich;
public:
    virtual void nhap() {
        cout << "Nhap ma GD: "; cin >> maGD;
        cout << "Nhap ngay GD (dd/mm/yyyy): "; cin >> ngayGD;
        cout << "Nhap don gia: "; cin >> donGia;
        cout << "Nhap dien tich: "; cin >> dienTich;
    }
    virtual void xuat() const {
        cout << "Ma GD: " << maGD << ", Ngay GD: " << ngayGD
             << ", Don gia: " << donGia << ", Dien tich: " << dienTich;
    }
    virtual float thanhTien() const = 0;
    string getNgayGD() const { return ngayGD; }
    virtual ~GiaoDichBDS() {}
};

class GDDat : public GiaoDichBDS {
    string loaiDat;
public:
    void nhap() override {
        GiaoDichBDS::nhap();
        cout << "Nhap loai dat (A/B/C): "; cin >> loaiDat;
    }
    void xuat() const override {
        cout << "[Giao dich Dat] ";
        GiaoDichBDS::xuat();
        cout << ", Loai dat: " << loaiDat
             << ", Thanh tien: " << thanhTien() << endl;
    }
    float thanhTien() const override {
        if (loaiDat == "A") return dienTich * donGia * 1.5;
        return dienTich * donGia;
    }
};

class GDNhaPho : public GiaoDichBDS {
    string loaiNha, diaChi;
public:
    void nhap() override {
        GiaoDichBDS::nhap();
        cout << "Nhap loai nha (cao cap/thuong): "; cin.ignore(); getline(cin, loaiNha);
        cout << "Nhap dia chi: "; getline(cin, diaChi);
    }
    void xuat() const override {
        cout << "[Giao dich Nha pho] ";
        GiaoDichBDS::xuat();
        cout << ", Loai nha: " << loaiNha << ", Dia chi: " << diaChi
             << ", Thanh tien: " << thanhTien() << endl;
    }
    float thanhTien() const override {
        if (loaiNha == "thuong") return dienTich * donGia * 0.9;
        return dienTich * donGia;
    }
};

class GDCCH : public GiaoDichBDS {
    string maCan;
    int viTriTang;
public:
    void nhap() override {
        GiaoDichBDS::nhap();
        cout << "Nhap ma can ho: "; cin >> maCan;
        cout << "Nhap vi tri tang: "; cin >> viTriTang;
    }
    void xuat() const override {
        cout << "[Giao dich Can ho] ";
        GiaoDichBDS::xuat();
        cout << ", Ma can: " << maCan << ", Tang: " << viTriTang
             << ", Thanh tien: " << thanhTien() << endl;
    }
    float thanhTien() const override {
        if (viTriTang == 1) return dienTich * donGia * 2;
        if (viTriTang >= 15) return dienTich * donGia * 1.2;
        return dienTich * donGia;
    }
};

int main() {
    vector<GiaoDichBDS*> ds;
    int n;
    cout << "Nhap so giao dich Dat: "; cin >> n;
    for (int i = 0; i < n; i++) {
        GiaoDichBDS* gd = new GDDat();
        gd->nhap();
        ds.push_back(gd);
    }

    cout << "Nhap so giao dich Nha pho: "; cin >> n;
    for (int i = 0; i < n; i++) {
        GiaoDichBDS* gd = new GDNhaPho();
        gd->nhap();
        ds.push_back(gd);
    }

    cout << "Nhap so giao dich Can ho: "; cin >> n;
    for (int i = 0; i < n; i++) {
        GiaoDichBDS* gd = new GDCCH();
        gd->nhap();
        ds.push_back(gd);
    }

    int demDat = 0, demNha = 0, demCH = 0;
    float tongCH = 0, maxTienNha = -1;
    GiaoDichBDS* gdNhaMax = nullptr;

    cout << "\nDanh sach giao dich:\n";
    for (GiaoDichBDS* gd : ds) {
        gd->xuat();

        if (dynamic_cast<GDDat*>(gd)) demDat++;
        else if (dynamic_cast<GDNhaPho*>(gd)) {
            demNha++;
            float tt = gd->thanhTien();
            if (tt > maxTienNha) {
                maxTienNha = tt;
                gdNhaMax = gd;
            }
        }
        else if (dynamic_cast<GDCCH*>(gd)) {
            demCH++;
            tongCH += gd->thanhTien();
        }
    }

    cout << "\nSo giao dich Dat: " << demDat;
    cout << "\nSo giao dich Nha pho: " << demNha;
    cout << "\nSo giao dich Can ho: " << demCH;

    if (demCH)
        cout << "\nTrung binh thanh tien giao dich Can ho: " << (tongCH / demCH);

    cout << "\nGiao dich Nha pho co thanh tien cao nhat:\n";
    if (gdNhaMax) gdNhaMax->xuat();

    cout << "\nGiao dich thuc hien trong thang 12/2024:\n";
    for (GiaoDichBDS* gd : ds) {
        string date = gd->getNgayGD();
        if (date.substr(3, 2) == "12" && date.substr(6, 4) == "2024") {
            gd->xuat();
        }
    }

    for (GiaoDichBDS* gd : ds) delete gd;
    return 0;
}
