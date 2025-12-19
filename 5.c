#include <stdio.h>

struct Student {
    int id;
    int age;
    float gpa;
    char name[50];
};

// Hàm lưu vào file (giữ nguyên)
void saveToFile(struct Student students[], int n) {
    FILE *f = fopen("students.txt", "w");
    if (f == NULL) {
        printf("Khong mo duoc file de ghi!\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        fprintf(f, "%d %s %d %.2f\n", students[i].id, students[i].name, students[i].age, students[i].gpa);
    }
    fclose(f);
}

// Hàm đọc từ file (giữ nguyên)
int loadFromFile(struct Student students[]) {
    FILE *f = fopen("students.txt", "r");
    if (f == NULL) return 0;
    
    int n = 0;
    while (n < 5 && fscanf(f, "%d %s %d %f", &students[n].id, students[n].name, &students[n].age, &students[n].gpa) == 4) {
        n++;
    }
    fclose(f);
    return n;
}

/**
 * Tim kiem sinh vien theo ID
 * 
 * @param students: Mang chua danh sach sinh vien
 * @param n: So luong sinh vien hien co trong mang
 * @param id: ID can tim
 * 
 * @return: Chi so (index) cua sinh vien trong mang neu tim thay,
 *          hoac -1 neu khong tim thay hoac ID khong hop le (am)
 */
int findStudentById(struct Student students[], int n, int id) {
    // Truong hop ID am -> khong hop le
    if (id < 0) {
        return -1;
    }
    
    for (int i = 0; i < n; i++) {
        if (students[i].id == id) {
            return i;  // Tim thay, tra ve chi so
        }
    }
    return -1;  // Khong tim thay
}

// Ham test cac truong hop
void testFindStudent(struct Student students[], int n) {
    printf("\n=== TEST TIM KIEM SINH VIEN THEO ID ===\n");
    
    // Test 1: ID ton tai (vi du ID = 1)
    int index = findStudentById(students, n, 1);
    if (index != -1) {
        printf("Tim thay ID=1: %s, Tuoi=%d, GPA=%.2f\n", 
               students[index].name, students[index].age, students[index].gpa);
    } else {
        printf("Khong tim thay ID=1\n");
    }
    
    // Test 2: ID khong ton tai (vi du ID = 999)
    index = findStudentById(students, n, 999);
    if (index != -1) {
        printf("Tim thay ID=999 (khong nen xay ra)\n");
    } else {
        printf("Khong tim thay ID=999 (dung)\n");
    }
    
    // Test 3: ID am
    index = findStudentById(students, n, -5);
    if (index != -1) {
        printf("Tim thay ID=-5 (khong nen xay ra)\n");
    } else {
        printf("Khong tim thay ID=-5 (dung, ID am khong hop le)\n");
    }
}

int main() {
    struct Student students[5];
    int n = loadFromFile(students);
    
    if (n == 0) {
        printf("Khong co du lieu trong file students.txt. Hay chay chuong trinh nhap du lieu truoc.\n");
        return 0;
    }
    
    printf("Da doc %d sinh vien tu file.\n", n);
    
    // In danh sach (de kiem tra)
    printf("\nDanh sach doc tu file:\n");
    for (int i = 0; i < n; i++) {
        printf("%d %s %d %.2f\n", students[i].id, students[i].name, students[i].age, students[i].gpa);
    }
    
    // Chay test tim kiem
    testFindStudent(students, n);
    
    return 0;
}