#include <stdio.h>
#include <string.h>

#define MAX 20  // Tối đa 20 sinh viên (để có chỗ thêm)

struct Student {
    int id;
    char name[50];
    int age;
    float gpa;
};

int n = 0;  // Số sinh viên hiện tại (toàn cục để dễ dùng)
struct Student ds[MAX];

// Hàm in danh sách sinh viên
void inDanhSach() {
    printf("\n=== DANH SACH SINH VIEN (%d nguoi) ===\n", n);
    if (n == 0) {
        printf("   (Chua co sinh vien nao)\n");
        return;
    }
    printf("ID   Ten         Tuoi   GPA\n");
    printf("--------------------------------\n");
    float tong = 0;
    for (int i = 0; i < n; i++) {
        printf("%-4d %-10s  %-4d   %.2f\n", ds[i].id, ds[i].name, ds[i].age, ds[i].gpa);
        tong += ds[i].gpa;
    }
    printf("--------------------------------\n");
    printf("GPA TRUNG BINH LOP: %.2f\n", tong / n);
}

// Hàm thêm sinh viên mới
void themSinhVien() {
    if (n >= MAX) {
        printf("Loi: Lop da day, khong the them!\n");
        return;
    }
    
    int id, tuoi;
    char ten[50];
    float diem;
    
    printf("Nhap ID: ");
    scanf("%d", &id);
    
    // Kiểm tra trùng ID
    for (int i = 0; i < n; i++) {
        if (ds[i].id == id) {
            printf("Loi: Da co sinh vien ID = %d! Khong the them trung.\n", id);
            return;
        }
    }
    
    printf("Nhap ten: ");
    scanf("%s", ten);
    printf("Nhap tuoi: ");
    scanf("%d", &tuoi);
    printf("Nhap GPA: ");
    scanf("%f", &diem);
    
    // Thêm vào mảng
    ds[n].id = id;
    strcpy(ds[n].name, ten);
    ds[n].age = tuoi;
    ds[n].gpa = diem;
    n++;
    
    printf("=> Da them thanh cong sinh vien %s (ID=%d)\n", ten, id);
}

// Hàm xóa sinh viên theo ID
void xoaSinhVien() {
    int id;
    printf("Nhap ID sinh vien can xoa: ");
    scanf("%d", &id);
    
    int vitri = -1;
    for (int i = 0; i < n; i++) {
        if (ds[i].id == id) {
            vitri = i;
            break;
        }
    }
    
    if (vitri == -1) {
        printf("Loi: Khong tim thay sinh vien co ID = %d\n", id);
        return;
    }
    
    // Dịch chuyển các sinh viên phía sau lên
    for (int i = vitri; i < n - 1; i++) {
        ds[i] = ds[i + 1];
    }
    n--;
    printf("=> Da xoa thanh cong sinh vien ID = %d\n", id);
}

// Hàm sắp xếp theo GPA giảm dần (Bubble Sort đơn giản)
void sapXepGPA() {
    if (n <= 1) {
        printf("Khong can sap xep (qua it sinh vien)\n");
        return;
    }
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (ds[j].gpa < ds[j + 1].gpa) {
                // Hoán đổi
                struct Student temp = ds[j];
                ds[j] = ds[j + 1];
                ds[j + 1] = temp;
            }
        }
    }
    printf("=> Da sap xep thanh cong theo GPA giam dan!\n");
}

// Hàm tạo 10 sinh viên giả lập
void taoDuLieuGiaLap() {
    struct Student gia_lap[10] = {
        {1, "An",     18, 8.7},
        {2, "Binh",   19, 7.5},
        {3, "Cuong",  18, 9.2},
        {4, "Dung",   20, 6.8},
        {5, "Em",     18, 8.9},
        {6, "Hoa",    19, 7.1},
        {7, "Giang",  18, 9.5},
        {8, "Hung",   20, 6.5},
        {9, "Lan",    19, 8.3},
        {10,"Minh",   18, 7.9}
    };
    
    for (int i = 0; i < 10; i++) {
        ds[i] = gia_lap[i];
    }
    n = 10;
    printf("=> Da tao thanh cong 10 sinh vien gia lap!\n");
}

// Hàm hiển thị menu
void hienThiMenu() {
    printf("\n");
    printf("===================================\n");
    printf("       QUAN LY SINH VIEN\n");
    printf("===================================\n");
    printf("1. Tao 10 sinh vien gia lap\n");
    printf("2. In danh sach sinh vien\n");
    printf("3. Them sinh vien moi\n");
    printf("4. Xoa sinh vien theo ID\n");
    printf("5. Sap xep theo GPA giam dan\n");
    printf("6. Thoat chuong trinh\n");
    printf("-----------------------------------\n");
    printf("Chon chuc nang (1-6): ");
}

int main() {
    int chon;
    
    do {
        hienThiMenu();
        scanf("%d", &chon);
        
        switch (chon) {
            case 1:
                taoDuLieuGiaLap();  // Tạo dữ liệu test
                inDanhSach();
                break;
            case 2:
                inDanhSach();       // In danh sách hiện tại
                break;
            case 3:
                themSinhVien();     // Thêm mới
                break;
            case 4:
                xoaSinhVien();      // Xóa theo ID
                break;
            case 5:
                sapXepGPA();        // Sắp xếp GPA
                inDanhSach();
                break;
            case 6:
                printf("==> Tam biet! Thoat chuong trinh.\n");
                break;
            default:
                printf("Loi: Chuc nang khong hop le! Chon lai tu 1-6.\n");
        }
    } while (chon != 6);
    
    return 0;
}