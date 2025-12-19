#include <stdio.h>

struct Student {
    int id;
    int age;
    float gpa;
    char name[50];
};
void saveToFile(struct Student students[], int n) {
    FILE *f = fopen("students.txt", "w");
    if (f == NULL) {
        printf("Khong mo duoc file de ghi!\n");
        return;
    }
    
    for (int i = 0; i < n; i++) {
        fprintf(f, "%d %s %d %.2f\n", 
                students[i].id, 
                students[i].name, 
                students[i].age, 
                students[i].gpa);
    }
    
    fclose(f);
    printf("Da luu danh sach vao file students.txt\n");
}

int main() {
    struct Student students[5];
    int n;
    
    printf("Nhap so luong sinh vien (1-5): ");
    scanf("%d", &n);
        for (int i = 0; i < n; i++) {
        printf("\nSinh vien thu %d:\n", i+1);
        
        printf("ID: ");
        scanf("%d", &students[i].id);
        
        printf("Ten: ");
        scanf("%s", students[i].name);g
        
        printf("Tuoi: ");
        scanf("%d", &students[i].age);
        
        printf("GPA: ");
        scanf("%f", &students[i].gpa);
    }
        printf("\n=== DANH SACH SINH VIEN ===\n");
    for (int i = 0; i < n; i++) {
        printf("SV %d: ID=%d, Ten=%s, Tuoi=%d, GPA=%.2f\n",
               i+1,
               students[i].id,
               students[i].name,
               students[i].age,
               students[i].gpa);
    }
    saveToFile(students, n);
    
    return 0;
}