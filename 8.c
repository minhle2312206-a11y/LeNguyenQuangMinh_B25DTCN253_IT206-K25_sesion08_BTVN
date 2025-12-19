#include <stdio.h>
#include <string.h>

#define MAX_SV 10      // Mỗi lớp tối đa 10 sinh viên
#define MAX_FILE 30    // Độ dài tên file

struct Student {
    int id;
    int age;
    float gpa;
    char name[50];
};

// Hàm hoán đổi 2 sinh viên
void swap(struct Student *a, struct Student *b) {
    struct Student temp = *a;
    *a = *b;
    *b = temp;
}

// Hàm sắp xếp theo GPA giảm dần
void sortByGPADesc(struct Student students[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (students[j].gpa < students[j + 1].gpa) {
                swap(&students[j], &students[j + 1]);
            }
        }
    }
}

// Hàm lưu danh sách vào file
void saveClassToFile(struct Student students[], int n, char filename[]) {
    FILE *f = fopen(filename, "w");
    if (f == NULL) {
        printf("Loi: Khong tao duoc file %s\n", filename);
        return;
    }
    for (int i = 0; i < n; i++) {
        fprintf(f, "%d %s %d %.2f\n", students[i].id, students[i].name, students[i].age, students[i].gpa);
    }
    fclose(f);
    printf("Da luu lop vao file: %s (%d sinh vien)\n", filename, n);
}

// Hàm đọc danh sách từ file
int loadClassFromFile(struct Student students[], char filename[]) {
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        printf("Loi: Khong tim thay file %s\n", filename);
        return 0;
    }
    
    int n = 0;
    while (n < MAX_SV && fscanf(f, "%d %s %d %f", 
                                &students[n].id, 
                                students[n].name, 
                                &students[n].age, 
                                &students[n].gpa) == 4) {
        n++;
    }
    fclose(f);
    return n;
}

// Hàm in danh sách lớp
void printClass(struct Student students[], int n, char className[]) {
    printf("\n=== DANH SACH LOP %s ===\n", className);
    printf("STT  Ten        Tuoi  GPA\n");
    printf("-------------------------\n");
    float tong = 0;
    for (int i = 0; i < n; i++) {
        printf("%2d   %-9s  %2d   %.2f\n", students[i].id, students[i].name, students[i].age, students[i].gpa);
        tong += students[i].gpa;
    }
    printf("-------------------------\n");
    printf("GPA TRUNG BINH LOP: %.2f\n", tong / n);
}

int main() {
    struct Student temp[MAX_SV];

    // === TẠO DỮ LIỆU GIẢ LẬP CHO 3 LỚP ===

    // Lớp A
    struct Student classA[MAX_SV] = {
        {1, 18, 8.7, "An"},     {2, 19, 7.5, "Binh"},  {3, 18, 9.1, "Cuong"},
        {4, 18, 6.8, "Dung"},  {5, 19, 8.9, "Em"},    {6, 18, 7.2, "Hoa"},
        {7, 19, 9.4, "Giang"}, {8, 18, 6.5, "Hung"},  {9, 19, 8.3, "Lan"},
        {10,18, 7.9, "Minh"}
    };
    saveClassToFile(classA, 10, "classA.txt");

    // Lớp B
    struct Student classB[MAX_SV] = {
        {1, 18, 8.2, "Nam"},   {2, 19, 7.8, "Oanh"},  {3, 18, 8.8, "Phuc"},
        {4, 19, 6.9, "Quynh"}, {5, 18, 9.0, "Son"},   {6, 19, 7.4, "Tam"},
        {7, 18, 8.5, "Uyen"},  {8, 19, 6.7, "Vy"},    {9, 18, 8.1, "Xuan"},
        {10,19, 7.6, "Yen"}
    };
    saveClassToFile(classB, 10, "classB.txt");

    // Lớp C
    struct Student classC[MAX_SV] = {
        {1, 18, 9.2, "Khang"}, {2, 19, 8.4, "Linh"},  {3, 18, 7.9, "Mai"},
        {4, 18, 8.6, "Nhat"},  {5, 19, 7.1, "Phong"}, {6, 18, 9.5, "Quang"},
        {7, 19, 8.0, "Rang"},  {8, 18, 6.8, "Sang"},  {9, 19, 8.7, "Thu"},
        {10,18, 7.3, "Uoc"}
    };
    saveClassToFile(classC, 10, "classC.txt");

    printf("\nDa tao xong 3 file: classA.txt, classB.txt, classC.txt\n");

    // === NGƯỜI DÙNG NHẬP TÊN FILE ĐỂ XEM ===
    char filename[MAX_FILE];
    printf("\nNhap ten file de xem danh sach (vi du: classA.txt): ");
    scanf("%s", filename);

    struct Student students[MAX_SV];
    int n = loadClassFromFile(students, filename);

    if (n == 0) {
        printf("Khong doc duoc du lieu tu file.\n");
        return 1;
    }

    // Sắp xếp theo GPA giảm dần
    sortByGPADesc(students, n);

    // Lấy tên lớp từ tên file (bỏ .txt)
    char className[10];
    strncpy(className, filename, strlen(filename) - 4); // bỏ .txt
    className[strlen(filename) - 4] = '\0';

    // In kết quả
    printClass(students, n, className);

    return 0;
}