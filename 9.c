#include <stdio.h>
#include <string.h>

#define MAX 20  // Tối đa 20 sinh viên (có chỗ để thêm)

struct Student {
    int id;
    char name[50];
    int age;
    float gpa;
};

// Hàm in danh sách
void inDanhSach(struct Student ds[], int n) {
    printf("\n=== DANH SACH SINH VIEN (%d nguoi) ===\n", n);
    printf("ID   Ten         Tuoi   GPA\n");
    printf("--------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-4d %-10s  %-4d   %.2f\n", ds[i].id, ds[i].name, ds[i].age, ds[i].gpa);
    }
}

// Hàm thêm sinh viên mới
// Trả về 1 nếu thêm thành công, 0 nếu trùng ID hoặc đầy
int themSinhVien(struct Student ds[], int *n, int id, char ten[], int tuoi, float diem) {
    // Kiểm tra danh sách đầy chưa
    if (*n >= MAX) {
        printf("Loi: Lop da day, khong the them!\n");
        return 0;
    }
    
    // Kiểm tra trùng ID
    for (int i = 0; i < *n; i++) {
        if (ds[i].id == id) {
            printf("Loi: Da co sinh vien ID = %d (ten: %s). Khong the them trung!\n", id, ds[i].name);
            return 0;
        }
    }
    
    // Thêm vào cuối danh sách
    ds[*n].id = id;
    strcpy(ds[*n].name, ten);
    ds[*n].age = tuoi;
    ds[*n].gpa = diem;
    (*n)++;  // Tăng số lượng
    
    printf("Da them thanh cong sinh vien: %s (ID=%d)\n", ten, id);
    return 1;
}

// Hàm xóa sinh viên theo ID
// Trả về 1 nếu xóa thành công, 0 nếu không tìm thấy
int xoaSinhVien(struct Student ds[], int *n, int id) {
    int tim_thay = 0;
    int vitri = -1;
    
    // Tìm vị trí sinh viên có ID cần xóa
    for (int i = 0; i < *n; i++) {
        if (ds[i].id == id) {
            tim_thay = 1;
            vitri = i;
            break;
        }
    }
    
    if (tim_thay == 0) {
        printf("Loi: Khong tim thay sinh vien co ID = %d\n", id);
        return 0;
    }
    
    // Dịch chuyển các sinh viên phía sau lên
    for (int i = vitri; i < *n - 1; i++) {
        ds[i] = ds[i + 1];
    }
    
    (*n)--;  // Giảm số lượng
    printf("Da xoa thanh cong sinh vien ID = %d\n", id);
    return 1;
}

int main() {
    struct Student ds[MAX];
    int n = 0;  // Số sinh viên hiện tại
    
    // Giả lập đọc từ file classA.txt (dữ liệu cứng để chạy thử)
    // Bạn có thể thay bằng hàm đọc file thật sau này
    ds[0].id = 1; strcpy(ds[0].name, "An");    ds[0].age = 18; ds[0].gpa = 8.5;
    ds[1].id = 2; strcpy(ds[1].name, "Binh");  ds[1].age = 19; ds[1].gpa = 7.8;
    ds[2].id = 3; strcpy(ds[2].name, "Cuong"); ds[[2].age = 18; ds[2].gpa = 9.0;
    ds[3].id = 4; strcpy(ds[3].name, "Dung");  ds[3].age = 20; ds[3].gpa = 6.5;
    n = 4;  // Có 4 sinh viên ban đầu
    
    // In danh sách ban đầu
    inDanhSach(ds, n);
    
    // TEST THÊM SINH VIÊN
    printf("\n--- TEST THEM SINH VIEN ---\n");
    themSinhVien(ds, &n, 5, "Em", 18, 8.8);        // Thành công
    themSinhVien(ds, &n, 2, "Trung", 19, 9.0);     // Trùng ID → lỗi
    themSinhVien(ds, &n, 6, "Hoa", 19, 7.5);       // Thành công
    
    // TEST XÓA SINH VIÊN
    printf("\n--- TEST XOA SINH VIEN ---\n");
    xoaSinhVien(ds, &n, 3);   
    xoaSinhVien(ds, &n, 99); 
    inDanhSach(ds, n);
    
    return 0;
}