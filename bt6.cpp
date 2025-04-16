#include <iostream>
#include <vector>
using namespace std;

class cCandidate {
private:
    string ma, ten;
    float diemToan, diemVan, diemAnh;

public:
    cCandidate(string m, string t, float dt, float dv, float da)
        : ma(m), ten(t), diemToan(dt), diemVan(dv), diemAnh(da) {}

    float tongDiem() {
        return diemToan + diemVan + diemAnh;
    }

    void xuat() {
        cout << "Mã: " << ma << ", Tên: " << ten << ", Tổng điểm: " << tongDiem() << endl;
    }
};

class cListCandidate {
private:
    vector<cCandidate> danhSach;

public:
    void themThiSinh(cCandidate candidate) {
        danhSach.push_back(candidate);
    }

    void xuatThiSinh() {
        for (auto& thiSinh : danhSach) {
            thiSinh.xuat();
        }
    }

    cCandidate thiSinhTotNhat() {
        cCandidate max = danhSach[0];
        for (auto& thiSinh : danhSach) {
            if (thiSinh.tongDiem() > max.tongDiem()) {
                max = thiSinh;
            }
        }
        return max;
    }
};

int main() {
    cListCandidate list;
    list.themThiSinh(cCandidate("A1", "Nguyen A", 8, 7, 6));
    list.themThiSinh(cCandidate("A2", "Tran B", 9, 8, 7));
    cout << "Danh sách thí sinh:\n";
    list.xuatThiSinh();
    cout << "Thí sinh có tổng điểm cao nhất: ";
    cCandidate best = list.thiSinhTotNhat();
    best.xuat();
    return 0;
}
