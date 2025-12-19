#include <stdio.h>

#define SO_SV 10

struct Student {
    int id;
    int age;
    float gpa;
    char name[50];
};

// Hàm hoán đổi hai sinh viên
void swap(struct Student *a, struct Student *b) {
    struct Student temp = *a;
    *a = *b;
    *b = temp;
}

// Hàm sắp xếp theo GPA giảm dần (cao đến thấp)
void sortByGPADesc(struct Student students[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (students[j].gpa < students[j + 1].gpa) {
                swap(&students[j], &students[j + 1]);
            }
        }
    }
}

// Hàm in danh sách
void printList(struct Student students[], int n, char title[]) {
    printf("\n=== %s ===\n", title);
    printf("STT  Ten      Tuoi  GPA\n");
    printf("------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%2d   %-7s  %2d   %.2f\n",
               students[i].id,
               students[i].name,
               students[i].age,
               students[i].gpa);
    }
}

int main() {
    struct Student students[SO_SV];

    // Test case 1: GPA bằng nhau
    printf("TEST 1: GPA bang nhau\n");
    for (int i = 0; i < 5; i++) {
        students[i].id = i + 1;
        students[i].age = 18;
        students[i].gpa = 8.0;  // Tất cả đều 8.0
        sprintf(students[i].name, "SV%d", i + 1);
    }
    printList(students, 5, "Truoc sap xep (GPA bang nhau)");
    sortByGPADesc(students, 5);
    printList(students, 5, "Sau sap xep (van giu nguyen thu tu)");

    // Test case 2: GPA đã tăng dần sẵn
    printf("\nTEST 2: GPA da tang dan san\n");
    float gpa_tang[] = {5.5, 6.0, 7.0, 8.0, 9.0};
    for (int i = 0; i < 5; i++) {
        students[i].id = i + 1;
        students[i].age = 19;
        students[i].gpa = gpa_tang[i];
        sprintf(students[i].name, "SV%d", i + 1);
    }
    printList(students, 5, "Truoc sap xep (da tang dan)");
    sortByGPADesc(students, 5);
    printList(students, 5, "Sau sap xep (se dao nguoc thanh giam dan)");

    // Test case 3: GPA ngẫu nhiên (dữ liệu thực tế)
    printf("\nTEST 3: GPA ngau nhien (10 sinh vien)\n");
    struct Student data_ngau_nhien[SO_SV] = {
        {1, 18, 8.5, "An"},
        {2, 19, 7.2, "Binh"},
        {3, 18, 9.3, "Cuong"},
        {4, 20, 6.8, "Dung"},
        {5, 18, 8.5, "Em"},
        {6, 19, 7.9, "Phuong"},
        {7, 18, 9.0, "Giang"},
        {8, 20, 5.9, "Hoa"},
        {9, 19, 8.1, "Hung"},
        {10,18, 7.5, "Lan"}
    };
    // Sao chép dữ liệu
    for (int i = 0; i < SO_SV; i++) {
        students[i] = data_ngau_nhien[i];
    }
    printList(students, SO_SV, "Truoc sap xep (GPA ngau nhien)");
    sortByGPADesc(students, SO_SV);
    printList(students, SO_SV, "Sau sap xep (GPA giam dan)");

    // Bonus: Tính GPA trung bình sau khi sắp xếp
    float tong = 0;
    for (int i = 0; i < SO_SV; i++) {
        tong += students[i].gpa;
    }
    printf("\n=> GPA TRUNG BINH LOP: %.2f\n", tong / SO_SV);

    return 0;
}