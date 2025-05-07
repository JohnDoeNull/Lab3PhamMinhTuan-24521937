#include <iostream>
#include <vector>
#include <string>
using namespace std;

class SinhVien {
protected:
    string maSV, hoTen, diaChi;
    int tongTinChi;
    float diemTB;
public:
    virtual void nhap() {
        cout << "Nhap ma SV: "; cin >> maSV;
        cin.ignore();
        cout << "Nhap ho ten: "; getline(cin, hoTen);
        cout << "Nhap dia chi: "; getline(cin, diaChi);
        cout << "Nhap tong so tin chi: "; cin >> tongTinChi;
        cout << "Nhap diem trung binh: "; cin >> diemTB;
    }
    virtual void xuat() const {
        cout << "Ma SV: " << maSV << ", Ho ten: " << hoTen
             << ", Dia chi: " << diaChi << ", Tin chi: " << tongTinChi
             << ", DTB: " << diemTB;
    }
    float getDTB() const { return diemTB; }
    virtual bool totNghiep() const = 0;
    virtual ~SinhVien() {}
};

class SVCD : public SinhVien {
    float diemTN;
public:
    void nhap() override {
        SinhVien::nhap();
        cout << "Nhap diem thi tot nghiep: "; cin >> diemTN;
    }
    void xuat() const override {
        cout << "[Cao dang] ";
        SinhVien::xuat();
        cout << ", Diem TN: " << diemTN;
        cout << ", Tot nghiep: " << (totNghiep() ? "Co" : "Khong") << endl;
    }
    bool totNghiep() const override {
        return tongTinChi >= 110 && diemTB >= 5 && diemTN >= 5;
    }
};

class SVDH : public SinhVien {
    string tenLV;
    float diemLV;
public:
    void nhap() override {
        SinhVien::nhap();
        cin.ignore();
        cout << "Nhap ten luan van: "; getline(cin, tenLV);
        cout << "Nhap diem luan van: "; cin >> diemLV;
    }
    void xuat() const override {
        cout << "[Dai hoc] ";
        SinhVien::xuat();
        cout << ", LV: " << tenLV << ", Diem LV: " << diemLV;
        cout << ", Tot nghiep: " << (totNghiep() ? "Co" : "Khong") << endl;
    }
    bool totNghiep() const override {
        return tongTinChi >= 145 && diemTB >= 5 && diemLV >= 5;
    }
};

int main() {
    vector<SinhVien*> ds;
    int n;

    cout << "Nhap so sinh vien cao dang: "; cin >> n;
    for (int i = 0; i < n; ++i) {
        SinhVien* sv = new SVCD();
        sv->nhap();
        ds.push_back(sv);
    }

    cout << "Nhap so sinh vien dai hoc: "; cin >> n;
    for (int i = 0; i < n; ++i) {
        SinhVien* sv = new SVDH();
        sv->nhap();
        ds.push_back(sv);
    }

    float maxDTB = -1;
    SinhVien* svMax = nullptr;

    cout << "\nDanh sach sinh vien:\n";
    for (SinhVien* sv : ds) {
        sv->xuat();
        if (dynamic_cast<SVDH*>(sv) && sv->getDTB() > maxDTB) {
            maxDTB = sv->getDTB();
            svMax = sv;
        }
    }

    cout << "\nDanh sach sinh vien du dieu kien tot nghiep:\n";
    for (SinhVien* sv : ds) {
        if (sv->totNghiep()) sv->xuat();
    }

    cout << "\nDanh sach sinh vien KHONG du dieu kien tot nghiep:\n";
    for (SinhVien* sv : ds) {
        if (!sv->totNghiep()) sv->xuat();
    }

    if (svMax) {
        cout << "\nSinh vien dai hoc co DTB cao nhat:\n";
        svMax->xuat();
    }

    for (SinhVien* sv : ds) delete sv;
    return 0;
}
